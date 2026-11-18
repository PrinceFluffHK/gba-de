#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Gorilla Tactics and Juggernaut boost physical damage by 50%", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS; }
    PARAMETRIZE { ability = ABILITY_JUGGERNAUT; }

    GIVEN {
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5), results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Gorilla Tactics and Juggernaut stack with Choice Band", s16 damage)
{
    enum Ability ability;
    enum Item item;
    PARAMETRIZE { ability = ABILITY_ZEN_MODE;         item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS;  item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS;  item = ITEM_CHOICE_BAND; }
    PARAMETRIZE { ability = ABILITY_JUGGERNAUT;       item = ITEM_NONE; }
    PARAMETRIZE { ability = ABILITY_JUGGERNAUT;       item = ITEM_CHOICE_BAND; }

    GIVEN {
        ASSUME(GetItemHoldEffect(ITEM_CHOICE_BAND) == HOLD_EFFECT_CHOICE_BAND);
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); Item(item); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5),  results[1].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.25), results[2].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(1.5),  results[3].damage);
        EXPECT_MUL_EQ(results[0].damage, Q_4_12(2.25), results[4].damage);
    }
}

SINGLE_BATTLE_TEST("Gorilla Tactics and Juggernaut do not boost damage while Dynamaxed", s16 damage)
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_ZEN_MODE; }
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS; }
    PARAMETRIZE { ability = ABILITY_JUGGERNAUT; }

    GIVEN {
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, player);
        HP_BAR(opponent, captureDamage: &results[i].damage);
    } FINALLY {
        EXPECT_EQ(results[0].damage, results[1].damage);
        EXPECT_EQ(results[0].damage, results[2].damage);
    }
}

SINGLE_BATTLE_TEST("Gorilla Tactics and Juggernaut lock moves outside Dynamax")
{
    enum Ability ability;
    enum BattlerId battler = GetBattlerAtPosition(B_POSITION_PLAYER_LEFT);
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS; }
    PARAMETRIZE { ability = ABILITY_JUGGERNAUT; }

    GIVEN {
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); Moves(MOVE_SCRATCH, MOVE_GROWL); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } THEN {
        EXPECT_EQ(gBattleStruct->choicedMove[battler], MOVE_SCRATCH);
        EXPECT_EQ(CheckMoveLimitations(battler, 0, MOVE_LIMITATION_CHOICE_ITEM) & (1 << 1), 1 << 1);
    }
}

SINGLE_BATTLE_TEST("Gorilla Tactics and Juggernaut do not lock moves while Dynamaxed")
{
    enum Ability ability;
    PARAMETRIZE { ability = ABILITY_GORILLA_TACTICS; }
    PARAMETRIZE { ability = ABILITY_JUGGERNAUT; }

    GIVEN {
        PLAYER(SPECIES_DARMANITAN_GALAR) { Ability(ability); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH, gimmick: GIMMICK_DYNAMAX); }
        TURN { MOVE(player, MOVE_FLAME_CHARGE); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_STRIKE, player);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_MAX_FLARE, player);
    }
}

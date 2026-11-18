#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Hardy Thorns damages attackers that make contact")
{
    const u32 maxHP = 800;

    GIVEN {
        ASSUME(MoveMakesContact(MOVE_SCRATCH));
        PLAYER(SPECIES_WOBBUFFET) { MaxHP(maxHP); HP(maxHP); }
        OPPONENT(SPECIES_CACNEA) { Ability(ABILITY_HARDY_THORNS); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ABILITY_POPUP(opponent, ABILITY_HARDY_THORNS);
    } THEN {
        EXPECT_EQ(player->hp, maxHP - maxHP / (B_ROUGH_SKIN_DMG >= GEN_4 ? 8 : 16));
    }
}

SINGLE_BATTLE_TEST("Hardy Thorns prevents damage from sandstorm")
{
    GIVEN {
        ASSUME(GetMoveEffect(MOVE_SANDSTORM) == EFFECT_WEATHER);
        ASSUME(GetMoveWeatherType(MOVE_SANDSTORM) == BATTLE_WEATHER_SANDSTORM);
        PLAYER(SPECIES_CACNEA) { Ability(ABILITY_HARDY_THORNS); HP(160); MaxHP(160); }
        OPPONENT(SPECIES_WOBBUFFET);
    } WHEN {
        TURN { MOVE(opponent, MOVE_SANDSTORM); }
        TURN {}
    } SCENE {
        NONE_OF { HP_BAR(player); }
    } THEN {
        EXPECT_EQ(player->hp, 160);
    }
}

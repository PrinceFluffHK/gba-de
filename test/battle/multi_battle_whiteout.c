#include "global.h"
#include "test/battle.h"

MULTI_BATTLE_TEST("Player does whiteout in a multibattle even if the Partner still has Pokemon (Multi; Full Team; Gen4+)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_4);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 3);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 4);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 5);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), TRUE);
    }
}

TWO_VS_ONE_BATTLE_TEST("Player does whiteout in a multibattle even if the Partner still has Pokemon (2v1; Full Team; Gen4+)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_4);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 3);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 4);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 5);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), TRUE);
    }
}

MULTI_BATTLE_TEST("Player does not whiteout in a multibattle if the Partner still has Pokemon (Multi; Half Team; Gen4+)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_4);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            MOVE(opponentRight, MOVE_SPITFIRE, target:playerRight);
            SEND_OUT(playerRight, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentRight);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), FALSE);
    }
}

TWO_VS_ONE_BATTLE_TEST("Player does not whiteout in a multibattle if the Partner still has Pokemon (2v1; Half Team; Gen4+)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_4);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            MOVE(opponentRight, MOVE_SPITFIRE, target:playerRight);
            SEND_OUT(playerRight, 1);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentRight);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), FALSE);
    }
}

MULTI_BATTLE_TEST("Player does whiteout in a multibattle if the Partner still has Pokemon (Multi; Full Team; Gen3)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_3);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
        OPPONENT_B(SPECIES_DRAGONAIR);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 3);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 4);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 5);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), TRUE);
    }
}

TWO_VS_ONE_BATTLE_TEST("Player does whiteout in a multibattle if the Partner still has Pokemon (2v1; Full Team; Gen3)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_3);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_A(SPECIES_DRAGONAIR);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
        OPPONENT_A(SPECIES_DRAGONITE);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 3);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 4);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 5);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), TRUE);
    }
}

MULTI_BATTLE_TEST("Player does whiteout in a multibattle if the Partner still has Pokemon (Multi; Half Team; Gen3)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_3);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_B(SPECIES_DRAGONAIR);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), TRUE);
    }
}

TWO_VS_ONE_BATTLE_TEST("Player does whiteout in a multibattle if the Partner still has Pokemon (2v1; Full Team; Gen3)")
{
    GIVEN {
        WITH_CONFIG(B_MULTI_BATTLE_WHITEOUT, GEN_3);
        ASSUME(GetMoveEffect(MOVE_SPITFIRE) == EFFECT_FIXED_HP_DAMAGE);
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PLAYER(SPECIES_WYNAUT) { HP(1); }
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        PARTNER(SPECIES_WOBBUFFET);
        OPPONENT_A(SPECIES_DRAGONITE) { Moves(MOVE_SPITFIRE); }
        OPPONENT_A(SPECIES_DRAGONAIR);
    } WHEN {
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 1);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
            SEND_OUT(playerLeft, 2);
        }
        TURN {
            MOVE(opponentLeft, MOVE_SPITFIRE, target:playerLeft);
        }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SPITFIRE, opponentLeft);
    } THEN {
        EXPECT_EQ(NoAliveMonsForPlayer(), TRUE);
    }
}

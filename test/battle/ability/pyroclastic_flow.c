#include "global.h"
#include "test/battle.h"

SINGLE_BATTLE_TEST("Pyroclastic Flow burns an attacker that damages its holder")
{
    GIVEN {
        PLAYER(SPECIES_WOBBUFFET);
        OPPONENT(SPECIES_MAGCARGO) { Ability(ABILITY_PYROCLASTIC_FLOW); }
    } WHEN {
        TURN { MOVE(player, MOVE_SCRATCH); }
    } SCENE {
        ANIMATION(ANIM_TYPE_MOVE, MOVE_SCRATCH, player);
        ABILITY_POPUP(opponent, ABILITY_PYROCLASTIC_FLOW);
        ANIMATION(ANIM_TYPE_STATUS, B_ANIM_STATUS_BRN, player);
        STATUS_ICON(player, burn: TRUE);
    }
}

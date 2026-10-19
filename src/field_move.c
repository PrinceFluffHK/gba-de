#include "global.h"
#include "event_data.h"
#include "field_move.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "party_menu.h"
#include "strings.h"
#include "constants/field_move.h"
#include "constants/moves.h"
#include "constants/party_menu.h"

static bool32 IsAlwaysFalse(void)
{
    return FALSE;
}

static bool32 IsAlwaysTrue(void)
{
    return TRUE;
}

static bool32 CanUseCut(void) { return FlagGet(IS_FRLG ? FLAG_BADGE02_GET : FLAG_BADGE01_GET); }
static bool32 CanUseFieldFlash(void) { return FlagGet(IS_FRLG ? FLAG_BADGE01_GET : FLAG_BADGE02_GET); }
static bool32 CanUseRockSmash(void) { return FlagGet(IS_FRLG ? FLAG_BADGE01_GET : FLAG_BADGE03_GET); }
static bool32 CanUseStrength(void) { return FlagGet(FLAG_BADGE04_GET); }
static bool32 CanUseSurf(void) { return FlagGet(FLAG_BADGE05_GET); }
static bool32 CanUseFieldFly(void) { return FlagGet(IS_FRLG ? FLAG_BADGE03_GET : FLAG_BADGE06_GET); }
static bool32 CanUseDive(void) { return FlagGet(FLAG_BADGE07_GET); }
static bool32 CanUseWaterfall(void) { return FlagGet(IS_FRLG ? FLAG_BADGE07_GET : FLAG_BADGE08_GET); }

const struct FieldMoveInfo gFieldMoveInfo[FIELD_MOVES_COUNT] =
{
    [FIELD_MOVE_CUT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Cut,
        .isUnlockedFunc = CanUseCut,
        .moveID = MOVE_CUT,
        .partyMsgID = PARTY_MSG_NOTHING_TO_CUT,
    },

    [FIELD_MOVE_FLASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Flash,
        .isUnlockedFunc = CanUseFieldFlash,
        .moveID = MOVE_FLASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_ROCK_SMASH] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockSmash,
        .isUnlockedFunc = CanUseRockSmash,
        .moveID = MOVE_ROCK_SMASH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_STRENGTH] =
    {
        .fieldMoveFunc = SetUpFieldMove_Strength,
        .isUnlockedFunc = CanUseStrength,
        .moveID = MOVE_STRENGTH,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SURF] =
    {
        .fieldMoveFunc = SetUpFieldMove_Surf,
        .isUnlockedFunc = CanUseSurf,
        .moveID = MOVE_SURF,
        .partyMsgID = PARTY_MSG_CANT_SURF_HERE,
    },

    [FIELD_MOVE_FLY] =
    {
        .fieldMoveFunc = SetUpFieldMove_Fly,
        .isUnlockedFunc = CanUseFieldFly,
        .moveID = MOVE_FLY,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIVE] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dive,
        .isUnlockedFunc = CanUseDive,
        .moveID = MOVE_DIVE,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_WATERFALL] =
    {
        .fieldMoveFunc = SetUpFieldMove_Waterfall,
        .isUnlockedFunc = CanUseWaterfall,
        .moveID = MOVE_WATERFALL,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_TELEPORT] =
    {
        .fieldMoveFunc = SetUpFieldMove_Teleport,
        .isUnlockedFunc = IsAlwaysTrue,
        .moveID = MOVE_TELEPORT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_DIG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Dig,
        .isUnlockedFunc = IsAlwaysTrue,
        .moveID = MOVE_DIG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_SECRET_POWER] =
    {
        .fieldMoveFunc = SetUpFieldMove_SecretPower,
        .isUnlockedFunc = IsAlwaysTrue,
        .moveID = MOVE_SECRET_POWER,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },

    [FIELD_MOVE_MILK_DRINK] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsAlwaysTrue,
        .moveID = MOVE_MILK_DRINK,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SOFT_BOILED] =
    {
        .fieldMoveFunc = SetUpFieldMove_SoftBoiled,
        .isUnlockedFunc = IsAlwaysTrue,
        .moveID = MOVE_SOFT_BOILED,
        .partyMsgID = PARTY_MSG_NOT_ENOUGH_HP,
    },

    [FIELD_MOVE_SWEET_SCENT] =
    {
        .fieldMoveFunc = SetUpFieldMove_SweetScent,
        .isUnlockedFunc = IsAlwaysTrue,
        .moveID = MOVE_SWEET_SCENT,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
    },
    [FIELD_MOVE_ROCK_CLIMB] =
    {
        .fieldMoveFunc = SetUpFieldMove_RockClimb,
#if OW_ROCK_CLIMB_FIELD_MOVE
    .isUnlockedFunc = IsAlwaysTrue,
#else
    .isUnlockedFunc = IsAlwaysFalse,
#endif
        .moveID = MOVE_ROCK_CLIMB,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .hideIfLocked = TRUE,
    },
    [FIELD_MOVE_DEFOG] =
    {
        .fieldMoveFunc = SetUpFieldMove_Defog,
#if OW_DEFOG_FIELD_MOVE
    .isUnlockedFunc = IsAlwaysTrue,
#else
    .isUnlockedFunc = IsAlwaysFalse,
#endif
        .moveID = MOVE_DEFOG,
        .partyMsgID = PARTY_MSG_CANT_USE_HERE,
        .hideIfLocked = TRUE,
    },
};

bool32 FieldMove_IsVisible(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].fieldMoveFunc != NULL
        && (!gFieldMoveInfo[fieldMove].hideIfLocked || IsFieldMoveUnlocked(fieldMove));
}

const u8 *FieldMove_GetLockedMessage(enum FieldMove fieldMove)
{
    return gFieldMoveInfo[fieldMove].hideIfLocked ? gText_EmptyString2 : gText_CantUseUntilNewBadge;
}

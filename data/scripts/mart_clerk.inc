gText_HowMayIServeYou::
	.string "Welcome!\p"
	.string "How may I serve you?$"

gText_PleaseComeAgain::
	.string "Please come again!$"

gText_PlayerWhatCanIDoForYou::
	.string "{PLAYER}{KUN}, welcome!\p"
	.string "What can I do for you?$"

Pokemart_DefaultItemList::
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	pokemartlistend

@ Each list is selected by the number of badges the player has earned.
.align 2
Pokemart_DefaultItemListsByBadgeCount::
	.4byte Pokemart_StandardItems_0Badges
	.4byte Pokemart_StandardItems_1Badge
	.4byte Pokemart_StandardItems_2Badges
	.4byte Pokemart_StandardItems_3Badges
	.4byte Pokemart_StandardItems_4Badges
	.4byte Pokemart_StandardItems_5Badges
	.4byte Pokemart_StandardItems_6Badges
	.4byte Pokemart_StandardItems_7Badges
	.4byte Pokemart_StandardItems_8Badges

.align 2
Pokemart_StandardItems_0Badges:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_POTION
    .2byte ITEM_ANTIDOTE
    .2byte ITEM_PARALYZE_HEAL
    .2byte ITEM_AWAKENING
	.2byte ITEM_NONE
Pokemart_StandardItems_1Badge:
    .2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE
Pokemart_StandardItems_2Badges:
    .2byte ITEM_POKE_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE
Pokemart_StandardItems_3Badges:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE
Pokemart_StandardItems_4Badges:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_REVIVE
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE
Pokemart_StandardItems_5Badges:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_REVIVE
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE
Pokemart_StandardItems_6Badges:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE
Pokemart_StandardItems_7Badges:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE
Pokemart_StandardItems_8Badges:
    .2byte ITEM_POKE_BALL
    .2byte ITEM_GREAT_BALL
    .2byte ITEM_ULTRA_BALL
	.2byte ITEM_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
    .2byte ITEM_SERIOUS_MINT
    .2byte ITEM_ABILITY_CAPSULE
    .2byte ITEM_ABILITY_PATCH
    .2byte ITEM_FRESH_START_MOCHI
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_NONE

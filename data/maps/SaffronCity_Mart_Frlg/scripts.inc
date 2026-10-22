SaffronCity_Mart_Frlg_MapScripts::
	.byte 0

SaffronCity_Mart_EventScript_Lass::
	msgbox SaffronCity_Mart_Text_ReviveIsCostly, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Youngster::
	msgbox SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper, MSGBOX_NPC
	end

SaffronCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartstandard
	msgbox gText_PleaseComeAgain
	release
	end

SaffronCity_Mart_EventScript_Clerk_2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart SaffronCity_Mart_Pokemart_Secondary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
SaffronCity_Mart_Pokemart_Secondary:
	.2byte ITEM_DYNAMAX_BAND
	pokemartlistend

SaffronCity_Mart_Text_MaxRepelMoreEffectiveThanSuper::
	.string "MAX REPEL keeps weaker POKéMON\n"
	.string "from appearing.\p"
	.string "MAX REPEL stays effective longer\n"
	.string "than SUPER REPEL.$"

SaffronCity_Mart_Text_ReviveIsCostly::
	.string "REVIVE is costly, but it revives\n"
	.string "fainted POKéMON!$"


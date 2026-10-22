CinnabarIsland_Mart_Frlg_MapScripts::
	.byte 0

CinnabarIsland_Mart_EventScript_Woman::
	msgbox CinnabarIsland_Mart_Text_DontTheyHaveXAttack, MSGBOX_NPC
	end

CinnabarIsland_Mart_EventScript_Scientist::
	msgbox CinnabarIsland_Mart_Text_ExtraItemsNeverHurt, MSGBOX_NPC
	end

CinnabarIsland_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartstandard
	msgbox gText_PleaseComeAgain
	release
	end

CinnabarIsland_Mart_EventScript_Clerk_2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart CinnabarIsland_Mart_Pokemart_Secondary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
CinnabarIsland_Mart_Pokemart_Secondary:
	.2byte ITEM_DYNAMAX_BAND
	pokemartlistend

CinnabarIsland_Mart_Text_DontTheyHaveXAttack::
	.string "Don't they have X ATTACK?\p"
	.string "I like it because it raises the\n"
	.string "ATTACK stat in battle.$"

CinnabarIsland_Mart_Text_ExtraItemsNeverHurt::
	.string "It never hurts to have extra items.\n"
	.string "You never know what might happen.$"


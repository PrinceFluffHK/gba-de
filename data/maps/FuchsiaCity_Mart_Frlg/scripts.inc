FuchsiaCity_Mart_Frlg_MapScripts::
	.byte 0

FuchsiaCity_Mart_EventScript_CooltrainerF::
	msgbox FuchsiaCity_Mart_Text_DidYouTryXSpeed, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Gentleman::
	msgbox FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants, MSGBOX_NPC
	end

FuchsiaCity_Mart_EventScript_Clerk::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemartstandard
	msgbox gText_PleaseComeAgain
	release
	end

FuchsiaCity_Mart_EventScript_Clerk_2::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart FuchsiaCity_Mart_Pokemart_Secondary
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
FuchsiaCity_Mart_Pokemart_Secondary:
	.2byte ITEM_DYNAMAX_BAND
	pokemartlistend

FuchsiaCity_Mart_Text_DontTheyHaveSafariZonePennants::
	.string "Don't they have any pennants\n"
	.string "promoting the SAFARI ZONE?\p"
	.string "How about some paper lanterns?\n"
	.string "Aren't there even any calendars?$"

FuchsiaCity_Mart_Text_DidYouTryXSpeed::
	.string "Did you try X SPEED?\n"
	.string "It speeds up a POKéMON in battle.$"


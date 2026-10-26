TwoIsland_Frlg_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, TwoIsland_OnTransition
	.byte 0

TwoIsland_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_TWO_ISLAND
	setflag FLAG_VISITED_TWO_ISLAND
	call TwoIsland_EventScript_SetShopState
	end

TwoIsland_EventScript_SetShopState::
	goto_if_set FLAG_IS_CHAMPION, TwoIsland_EventScript_SetShopStateAfterHoennLink
	goto_if_set FLAG_SYS_GAME_CLEAR, TwoIsland_EventScript_SetShopStateAfterChampion
	goto_if_set FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopStateAfterLostelleRescue
	goto TwoIsland_EventScript_SetShopStateDefault
	end

TwoIsland_EventScript_SetShopStateAfterHoennLink::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_SetShopExpanded2
	goto TwoIsland_EventScript_SetShopExpanded3
	end

TwoIsland_EventScript_SetShopStateAfterChampion::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_RESCUED_LOSTELLE, TwoIsland_EventScript_SetShopInitial
	goto_if_unset FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_SetShopExpanded1
	goto TwoIsland_EventScript_SetShopExpanded2
	end

TwoIsland_EventScript_SetShopStateAfterLostelleRescue::
	goto_if_unset FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_SetShopInitial
	goto TwoIsland_EventScript_SetShopExpanded1
	end

TwoIsland_EventScript_SetShopStateDefault::
	goto TwoIsland_EventScript_SetShopInitial
	end

TwoIsland_EventScript_SetShopInitial::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 1
	return

TwoIsland_EventScript_SetShopExpanded1::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 2
	clearflag FLAG_HIDE_TWO_ISLAND_WOMAN
	return

TwoIsland_EventScript_SetShopExpanded2::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 3
	clearflag FLAG_HIDE_TWO_ISLAND_BEAUTY
	return

TwoIsland_EventScript_SetShopExpanded3::
	setvar VAR_MAP_SCENE_TWO_ISLAND, 4
	clearflag FLAG_HIDE_TWO_ISLAND_SUPER_NERD
	return

TwoIsland_EventScript_Clerk::
	lock
	faceplayer
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ClerkShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ClerkShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ClerkShopExpanded1
	goto TwoIsland_EventScript_ClerkShopInitial
	end

TwoIsland_EventScript_ClerkShopExpanded3::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_3, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_3
	message TwoIsland_Text_BringingItemsFromDistantLands
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded3
	end

TwoIsland_EventScript_ClerkShopExpanded2::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_2, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_2
	message TwoIsland_Text_HopeYouGiveItYourBest
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded2
	end

TwoIsland_EventScript_ClerkShopExpanded1::
	goto_if_set FLAG_TWO_ISLAND_SHOP_EXPANDED_1, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_EXPANDED_1
	message TwoIsland_Text_AddedMerchandiseForLostelle
	waitmessage
	goto TwoIsland_EventScript_ShopExpanded1
	end

TwoIsland_EventScript_ClerkShopInitial::
	goto_if_set FLAG_TWO_ISLAND_SHOP_INTRODUCED, TwoIsland_EventScript_ClerkShopSkipIntro
	setflag FLAG_TWO_ISLAND_SHOP_INTRODUCED
	message TwoIsland_Text_WelcomeToShopMerchandiseLimited
	waitmessage
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ClerkShopSkipIntro::
	message gText_HowMayIServeYou
	waitmessage
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 4, TwoIsland_EventScript_ShopExpanded3
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 3, TwoIsland_EventScript_ShopExpanded2
	goto_if_eq VAR_MAP_SCENE_TWO_ISLAND, 2, TwoIsland_EventScript_ShopExpanded1
	goto TwoIsland_EventScript_ShopInitial
	end

TwoIsland_EventScript_ShopInitial::
@	pokemart TwoIsland_Items_ShopInitial
	msgbox TwoIsland_Text_NeedMegaRing
	release
	end

	.align 2
TwoIsland_Items_ShopInitial::
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_FRESH_WATER
	pokemartlistend

TwoIsland_EventScript_ShopExpanded1::
	pokemart TwoIsland_Items_ShopExpanded1
	msgbox gText_PleaseComeAgain
	release
	end

@ After saving Lostelle
	.align 2
TwoIsland_Items_ShopExpanded1::
	.2byte ITEM_VENUSAURITE
    .2byte ITEM_CHARIZARDITE_X
    .2byte ITEM_CHARIZARDITE_Y
    .2byte ITEM_BLASTOISINITE
    .2byte ITEM_BEEDRILLITE
    .2byte ITEM_PIDGEOTITE
    .2byte ITEM_ALAKAZITE
    .2byte ITEM_SLOWBRONITE
    .2byte ITEM_GENGARITE
    .2byte ITEM_KANGASKHANITE
    .2byte ITEM_PINSIRITE
    .2byte ITEM_GYARADOSITE
    .2byte ITEM_AERODACTYLITE
    .2byte ITEM_MEWTWONITE_X
    .2byte ITEM_MEWTWONITE_Y
	pokemartlistend

TwoIsland_EventScript_ShopExpanded2::
	pokemart TwoIsland_Items_ShopExpanded2
	msgbox gText_PleaseComeAgain
	release
	end
	
@ After entering Hall of Fame
	.align 2
TwoIsland_Items_ShopExpanded2::
	.2byte ITEM_VENUSAURITE
    .2byte ITEM_CHARIZARDITE_X
    .2byte ITEM_CHARIZARDITE_Y
    .2byte ITEM_BLASTOISINITE
    .2byte ITEM_BEEDRILLITE
    .2byte ITEM_PIDGEOTITE
    .2byte ITEM_ALAKAZITE
    .2byte ITEM_SLOWBRONITE
    .2byte ITEM_GENGARITE
    .2byte ITEM_KANGASKHANITE
    .2byte ITEM_PINSIRITE
    .2byte ITEM_GYARADOSITE
    .2byte ITEM_AERODACTYLITE
    .2byte ITEM_MEWTWONITE_X
    .2byte ITEM_MEWTWONITE_Y
    .2byte ITEM_AMPHAROSITE
    .2byte ITEM_STEELIXITE
    .2byte ITEM_SCIZORITE
    .2byte ITEM_HERACRONITE
    .2byte ITEM_HOUNDOOMINITE
    .2byte ITEM_TYRANITARITE
    .2byte ITEM_SCEPTILITE
    .2byte ITEM_BLAZIKENITE
    .2byte ITEM_SWAMPERTITE
    .2byte ITEM_GARDEVOIRITE
    .2byte ITEM_SABLENITE
    .2byte ITEM_MAWILITE
    .2byte ITEM_AGGRONITE
    .2byte ITEM_MEDICHAMITE
    .2byte ITEM_MANECTITE
    .2byte ITEM_SHARPEDONITE
    .2byte ITEM_CAMERUPTITE
    .2byte ITEM_ALTARIANITE
    .2byte ITEM_BANETTITE
    .2byte ITEM_ABSOLITE
    .2byte ITEM_GLALITITE
    .2byte ITEM_SALAMENCITE
    .2byte ITEM_METAGROSSITE
    .2byte ITEM_LATIASITE
    .2byte ITEM_LATIOSITE
    .2byte ITEM_LOPUNNITE
    .2byte ITEM_GARCHOMPITE
    .2byte ITEM_LUCARIONITE
    .2byte ITEM_ABOMASITE
    .2byte ITEM_GALLADITE
    .2byte ITEM_AUDINITE
    .2byte ITEM_DIANCITE
    .2byte ITEM_CLEFABLITE
    .2byte ITEM_VICTREEBELITE
    .2byte ITEM_STARMINITE
    .2byte ITEM_DRAGONINITE
    .2byte ITEM_MEGANIUMITE
    .2byte ITEM_FERALIGITE
    .2byte ITEM_SKARMORITE
    .2byte ITEM_FROSLASSITE
    .2byte ITEM_EMBOARITE
    .2byte ITEM_EXCADRITE
    .2byte ITEM_SCOLIPITE
    .2byte ITEM_SCRAFTINITE
    .2byte ITEM_EELEKTROSSITE
    .2byte ITEM_CHANDELURITE
    .2byte ITEM_CHESNAUGHTITE
    .2byte ITEM_DELPHOXITE
    .2byte ITEM_GRENINJITE
    .2byte ITEM_PYROARITE
    .2byte ITEM_FLOETTITE
    .2byte ITEM_MALAMARITE
    .2byte ITEM_BARBARACITE
    .2byte ITEM_DRAGALGITE
    .2byte ITEM_HAWLUCHANITE
    .2byte ITEM_ZYGARDITE
    .2byte ITEM_DRAMPANITE
    .2byte ITEM_FALINKSITE
    .2byte ITEM_HEATRANITE
    .2byte ITEM_DARKRANITE
    .2byte ITEM_ZERAORITE
    .2byte ITEM_RAICHUNITE_X
    .2byte ITEM_RAICHUNITE_Y
    .2byte ITEM_CHIMECHITE
    .2byte ITEM_ABSOLITE_Z
    .2byte ITEM_STARAPTITE
    .2byte ITEM_GARCHOMPITE_Z
    .2byte ITEM_LUCARIONITE_Z
    .2byte ITEM_GOLURKITE
    .2byte ITEM_MEOWSTICITE
    .2byte ITEM_CRABOMINITE
    .2byte ITEM_GOLISOPITE
    .2byte ITEM_MAGEARNITE
    .2byte ITEM_SCOVILLAINITE
    .2byte ITEM_BAXCALIBRITE
    .2byte ITEM_TATSUGIRINITE
    .2byte ITEM_GLIMMORANITE
	pokemartlistend

TwoIsland_EventScript_ShopExpanded3::
	pokemart TwoIsland_Items_ShopExpanded3
	msgbox gText_PleaseComeAgain
	release
	end

@ After completing Ruby/Sapphire quest
	.align 2
TwoIsland_Items_ShopExpanded3::
	.2byte ITEM_VENUSAURITE
    .2byte ITEM_CHARIZARDITE_X
    .2byte ITEM_CHARIZARDITE_Y
    .2byte ITEM_BLASTOISINITE
    .2byte ITEM_BEEDRILLITE
    .2byte ITEM_PIDGEOTITE
    .2byte ITEM_ALAKAZITE
    .2byte ITEM_SLOWBRONITE
    .2byte ITEM_GENGARITE
    .2byte ITEM_KANGASKHANITE
    .2byte ITEM_PINSIRITE
    .2byte ITEM_GYARADOSITE
    .2byte ITEM_AERODACTYLITE
    .2byte ITEM_MEWTWONITE_X
    .2byte ITEM_MEWTWONITE_Y
    .2byte ITEM_AMPHAROSITE
    .2byte ITEM_STEELIXITE
    .2byte ITEM_SCIZORITE
    .2byte ITEM_HERACRONITE
    .2byte ITEM_HOUNDOOMINITE
    .2byte ITEM_TYRANITARITE
    .2byte ITEM_SCEPTILITE
    .2byte ITEM_BLAZIKENITE
    .2byte ITEM_SWAMPERTITE
    .2byte ITEM_GARDEVOIRITE
    .2byte ITEM_SABLENITE
    .2byte ITEM_MAWILITE
    .2byte ITEM_AGGRONITE
    .2byte ITEM_MEDICHAMITE
    .2byte ITEM_MANECTITE
    .2byte ITEM_SHARPEDONITE
    .2byte ITEM_CAMERUPTITE
    .2byte ITEM_ALTARIANITE
    .2byte ITEM_BANETTITE
    .2byte ITEM_ABSOLITE
    .2byte ITEM_GLALITITE
    .2byte ITEM_SALAMENCITE
    .2byte ITEM_METAGROSSITE
    .2byte ITEM_LATIASITE
    .2byte ITEM_LATIOSITE
    .2byte ITEM_LOPUNNITE
    .2byte ITEM_GARCHOMPITE
    .2byte ITEM_LUCARIONITE
    .2byte ITEM_ABOMASITE
    .2byte ITEM_GALLADITE
    .2byte ITEM_AUDINITE
    .2byte ITEM_DIANCITE
    .2byte ITEM_CLEFABLITE
    .2byte ITEM_VICTREEBELITE
    .2byte ITEM_STARMINITE
    .2byte ITEM_DRAGONINITE
    .2byte ITEM_MEGANIUMITE
    .2byte ITEM_FERALIGITE
    .2byte ITEM_SKARMORITE
    .2byte ITEM_FROSLASSITE
    .2byte ITEM_EMBOARITE
    .2byte ITEM_EXCADRITE
    .2byte ITEM_SCOLIPITE
    .2byte ITEM_SCRAFTINITE
    .2byte ITEM_EELEKTROSSITE
    .2byte ITEM_CHANDELURITE
    .2byte ITEM_CHESNAUGHTITE
    .2byte ITEM_DELPHOXITE
    .2byte ITEM_GRENINJITE
    .2byte ITEM_PYROARITE
    .2byte ITEM_FLOETTITE
    .2byte ITEM_MALAMARITE
    .2byte ITEM_BARBARACITE
    .2byte ITEM_DRAGALGITE
    .2byte ITEM_HAWLUCHANITE
    .2byte ITEM_ZYGARDITE
    .2byte ITEM_DRAMPANITE
    .2byte ITEM_FALINKSITE
    .2byte ITEM_HEATRANITE
    .2byte ITEM_DARKRANITE
    .2byte ITEM_ZERAORITE
    .2byte ITEM_RAICHUNITE_X
    .2byte ITEM_RAICHUNITE_Y
    .2byte ITEM_CHIMECHITE
    .2byte ITEM_ABSOLITE_Z
    .2byte ITEM_STARAPTITE
    .2byte ITEM_GARCHOMPITE_Z
    .2byte ITEM_LUCARIONITE_Z
    .2byte ITEM_GOLURKITE
    .2byte ITEM_MEOWSTICITE
    .2byte ITEM_CRABOMINITE
    .2byte ITEM_GOLISOPITE
    .2byte ITEM_MAGEARNITE
    .2byte ITEM_SCOVILLAINITE
    .2byte ITEM_BAXCALIBRITE
    .2byte ITEM_TATSUGIRINITE
    .2byte ITEM_GLIMMORANITE
    .2byte ITEM_RED_ORB
    .2byte ITEM_BLUE_ORB
	pokemartlistend

TwoIsland_EventScript_Sailor::
	msgbox TwoIsland_Text_FellowMovedFromCeladonCity, MSGBOX_NPC
	end

TwoIsland_EventScript_Woman::
	msgbox TwoIsland_Text_ShopkeepersBrotherWorksGameCorner, MSGBOX_NPC
	end

TwoIsland_EventScript_Beauty::
	lock
	faceplayer
	famechecker FAMECHECKER_BRUNO, 4
	msgbox TwoIsland_Text_BrunoCameToIslandWhileBack
	release
	end

TwoIsland_EventScript_SuperNerd::
	msgbox TwoIsland_Text_BuyRareItemsHere, MSGBOX_NPC
	end

TwoIsland_EventScript_Boy::
	msgbox TwoIsland_Text_OldWomanLivesOutOnCape, MSGBOX_NPC
	end

TwoIsland_EventScript_LittleBoy::
	msgbox TwoIsland_Text_HaveYouTriedJumpingGame, MSGBOX_NPC
	end

TwoIsland_EventScript_IslandSign::
	msgbox TwoIsland_Text_IslandSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_JoyfulGameCornerSign::
	msgbox TwoIsland_Text_JoyfulGameCornerSign, MSGBOX_SIGN
	end

TwoIsland_EventScript_FastCurrentSign::
	msgbox TwoIsland_Text_DangerFastCurrent, MSGBOX_SIGN
	end

TwoIsland_Text_IslandSign::
	.string "TWO ISLAND\n"
	.string "Boon Island for Two$"

TwoIsland_Text_JoyfulGameCornerSign::
	.string "Skip & Chomp!\n"
	.string "Joyful GAME CORNER$"

TwoIsland_Text_DangerFastCurrent::
	.string "DANGER! FAST CURRENT!\n"
	.string "Fishing and surfing prohibited!$"

TwoIsland_Text_WelcomeToShopMerchandiseLimited::
	.string "Oh!\n"
	.string "Hello, welcome to my shop!\p"
	.string "We've only opened up recently.\p"
	.string "Our merchandise is limited, but I\n"
	.string "hope we can serve your needs.$"

TwoIsland_Text_AddedMerchandiseForLostelle::
	.string "I can't tell you how grateful I am\n"
	.string "for your rescue of LOSTELLE.\p"
	.string "Thanks to your feat, the people of\n"
	.string "THREE ISLAND have changed their\l"
	.string "attitudes about KANTO people.\p"
	.string "And, I'm from KANTO, you see.\p"
	.string "The people of THREE ISLAND\n"
	.string "helped me add to my merchandise.$"

TwoIsland_Text_HopeYouGiveItYourBest::
	.string "Hi! I'm giving it my best here.\n"
	.string "I hope you do too, {PLAYER}.$"

TwoIsland_Text_BringingItemsFromDistantLands::
	.string "Oh, hello, {PLAYER}!\n"
	.string "Welcome!\p"
	.string "I've started bringing in items from\n"
	.string "distant lands.\p"
	.string "I've got some rare items in, too.\n"
	.string "Please have a look!$"

TwoIsland_Text_FellowMovedFromCeladonCity::
	.string "That fellow there, he moved here\n"
	.string "from CELADON CITY.\p"
	.string "He started up a shop with his\n"
	.string "younger brother.\p"
	.string "You have to wonder if he knew what\n"
	.string "he was getting into.$"

TwoIsland_Text_ShopkeepersBrotherWorksGameCorner::
	.string "The shopkeeper's brother took\n"
	.string "a job at the GAME CORNER.\p"
	.string "He's trying to pull together money\n"
	.string "so they can buy more merchandise.$"

TwoIsland_Text_BrunoCameToIslandWhileBack::
	.string "Listen, listen.\n"
	.string "Did you know?\p"
	.string "A famous TRAINER came to the\n"
	.string "ISLAND a little while back.\p"
	.string "He's one of the ELITE FOUR.\n"
	.string "His name is BRUNO.\p"
	.string "He went away disappointed when he\n"
	.string "found out that they were all sold\l"
	.string "out of Rage Candybars.$"

TwoIsland_Text_BuyRareItemsHere::
	.string "The discerning TRAINER knows to\n"
	.string "buy rare items here!$"

TwoIsland_Text_OldWomanLivesOutOnCape::
	.string "There's an old woman who lives in\n"
	.string "a cottage out on the cape.\p"
	.string "She gives the eye to POKéMON.\n"
	.string "It's a bit unnerving.$"

TwoIsland_Text_HaveYouTriedJumpingGame::
	.string "Boing! Boing!\n"
	.string "Have you tried the jumping game?\p"
	.string "The POKéMON you can enter…\n"
	.string "Boing!\p"
	.string "Some go boing!\p"
	.string "And some go boooooooing!\p"
	.string "Did you know that?\n"
	.string "Boing!$"

TwoIsland_Text_NeedMegaRing::
	.string "Welcome!\p"
	.string "Sorry, but do you have a MEGA RING?\p"
	.string "We don't sell MEGA STONES to\n"
	.string "trainers who don't have one.$"


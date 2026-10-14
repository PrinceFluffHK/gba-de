LilycoveCity_DepartmentStore_3F_MapScripts::
	.byte 0

LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeft::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeftExpanded
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_EvoItemsBasic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_DepartmentStore_3F_EventScript_ClerkLeftExpanded::
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_EvoItemsExpanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_EvoItemsBasic:
	.2byte ITEM_EVERSTONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_OVAL_STONE
	pokemartlistend
	
	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_EvoItemsExpanded:
	.2byte ITEM_EVERSTONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_WATER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_ICE_STONE
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_DAWN_STONE
	.2byte ITEM_DUSK_STONE
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_OVAL_STONE
	.2byte ITEM_LINKING_CORD
	.2byte ITEM_REAPER_CLOTH
	.2byte ITEM_DRAGON_SCALE
	.2byte ITEM_DEEP_SEA_TOOTH
	.2byte ITEM_DEEP_SEA_SCALE
	.2byte ITEM_PROTECTOR
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	goto_if_set FLAG_RECEIVED_HM_WATERFALL, LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight_Expanded
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_MegaStones_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_MegaStones_Basic:
	.2byte ITEM_RAICHUNITE_X
	.2byte ITEM_RAICHUNITE_Y
	.2byte ITEM_ALAKAZITE
	.2byte ITEM_STARMINITE
	.2byte ITEM_PINSIRITE
	.2byte ITEM_GYARADOSITE
	.2byte ITEM_HERACRONITE
	.2byte ITEM_SKARMORITE
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
	.2byte ITEM_ABSOLITE_Z
	.2byte ITEM_GLALITITE
	.2byte ITEM_SALAMENCITE
	.2byte ITEM_METAGROSSITE
	.2byte ITEM_LATIASITE
	.2byte ITEM_LATIOSITE
	.2byte ITEM_FROSLASSITE
	.2byte ITEM_GALLADITE
	pokemartlistend

LilycoveCity_DepartmentStore_3F_EventScript_ClerkRight_Expanded::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_DepartmentStore_3F_Pokemart_MegaStones_Expanded
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LilycoveCity_DepartmentStore_3F_Pokemart_MegaStones_Expanded:
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

LilycoveCity_DepartmentStore_3F_EventScript_TriathleteM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_PokefanM::
	msgbox LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_EventScript_Woman::
	msgbox LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon, MSGBOX_NPC
	end

LilycoveCity_DepartmentStore_3F_Text_ItemsBestForTougheningPokemon:
	.string "For quickly toughening up POKéMON,\n"
	.string "items are the best.\p"
	.string "PROTEIN boosts ATTACK,\n"
	.string "and CALCIUM raises SP. ATK.$"

LilycoveCity_DepartmentStore_3F_Text_WantMoreEndurance:
	.string "I want my POKéMON to have more\n"
	.string "endurance.\p"
	.string "I'm trying to decide whether to raise\n"
	.string "DEFENSE with IRON, or SP. DEF with ZINC.$"

LilycoveCity_DepartmentStore_3F_Text_GaveCarbosToSpeedUpMon:
	.string "I gave a CARBOS to my POKéMON,\n"
	.string "and its SPEED went up.$"


/* GnollHack 4.0 encounter.c */
/* Copyright (c) Janne Gustafsson, 2019.                           */
/* GnollHack may be freely redistributed.  See license for details. */

#include "hack.h"
#include <ctype.h>
#include <math.h>

/* NAMELISTS HERE */
#define MAX_NAMELIST_NAMES 16
#define NAMELIST_GOBLIN_KING 1
#define NAMELIST_LICH 2
#define NAMELIST_ARCH_LICH 3
#define NAMELIST_LICH_KING 4

static const char namelists[][MAX_NAMELIST_NAMES][BUFSIZ] = {
	{"", "", "", "",},
	{"Urok", "Golluk", "Grimsh", "Urum",},
	{"Deimos", "Kangaxx", "Lyran", "Karlat", "Vongoethe",},
	{"Acererak ", "Vecna", "Zhengyi", "Jymahna", "Rhangaun", "Priamon Rakesk", "Shangalar the Black", "Kartak Spellseer",},
	{"Ner'zhul", "Arthas Menethil", "Bolvar Fordragon",},
	{ 0 }
};



#define NORANDOMIZEDITEM { 0, 0, 0, 0, 0, 0 }
#define NORANDOMIZEDALTERNATIVES { { NORANDOMIZEDITEM, NORANDOMIZEDITEM, NORANDOMIZEDITEM, NORANDOMIZEDITEM, NORANDOMIZEDITEM } }
#define NOMONSTERITEMS { NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES }
#define NOMONSTERALTERNATIVE { 0, 0, 0, 0, 0, 0, NOMONSTERITEMS }
#define NORANDOMIZEDMONSTER { { NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  }
#define NOMONSTERS { NORANDOMIZEDMONSTER, NORANDOMIZEDMONSTER, NORANDOMIZEDMONSTER, NORANDOMIZEDMONSTER, NORANDOMIZEDMONSTER }
#define NOENCOUNTER { NOMONSTERS, 0, 0 }


/* Note: The number of encounter definitions is limited to 256 in context.encounter_appeared. This should be plenty and if more is needed, change the number there -- JG */
struct encounterdef encounter_definitions[] =
{
	NOENCOUNTER,
	{
		{
			/* Monster 1 */
			{ { { PM_GIANT_SPIDER, 1, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_CAVE_SPIDER, 0, 3, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_WINTER_WOLF, 1, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_WINTER_WOLF_CUB, 2, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_WARG, 1, 1,0,  0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_WOLF, 2, 4, 0,  0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_QUEEN_BEE, 0, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_KILLER_BEE, 6, 3, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GIANT_RAT, 1, 2, 0, 0, 50, NOMONSTERITEMS },
			{ PM_RABID_RAT, 1, 2, 0, 0, 50, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_SEWER_RAT, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_SOLDIER_ANT, 2, 5, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_FIRE_ANT, 3, 5, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_JACKAL, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_HYENA, 2, 8, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_MANES, 2, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_LEMURE, 2, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GARTER_SNAKE, 2, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_ROTHE, 2, 4, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GRID_BUG, 2, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_COUATL, 2, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_HILL_GIANT, 2, 4, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_STONE_GIANT, 2, 4, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_FIRE_GIANT, 2, 4, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_FROST_GIANT, 2, 4, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_TITAN, 0, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			{ { { PM_STORM_GIANT, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_APE, 2, 3, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_GIANT_ANT, 5, 10, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ELVENKING, 0, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_ELF_LORD, 0, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_WOODLAND_ELF, 2, 1, 0, 0, 35, NOMONSTERITEMS },
				{ PM_GREY_ELF, 2, 1, 0, 0, 30, NOMONSTERITEMS },
				{ PM_GREEN_ELF, 2, 1, 0, 0, 35, NOMONSTERITEMS },
				NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_CAPTAIN, 0, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_LIEUTENANT, 0, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_SERGEANT, 0, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 4 */
			{ { { PM_SOLDIER, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_GIANT_BAT, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GIANT_BAT, 0, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_BAT, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ORC_ZOMBIE, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_DWARF_ZOMBIE, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_ELF_ZOMBIE, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_GHOUL, 2, 3, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_GNOLL_ZOMBIE, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_HUMAN_ZOMBIE, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_SKELETON_WARRIOR, 0, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_SKELETON, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_SKELETON_KING, 0, 1, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_SKELETON_LORD, 0, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_SKELETON_WARRIOR, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	{
		{
			/* Monster 1 */
			{ { { PM_ARCH_LICH, 1, 0, NAMELIST_ARCH_LICH, EM_NAME_KNOWN, 100, {
				{ { { STAFF_OF_THE_MAGI, 0, 0, 3, 0, 50 }, { STAFF_OF_FROST, 0, 0, 3, 0, 25 }, { QUARTERSTAFF, 0, 0, 0, 0, 25 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
				{ { { CLOAK_OF_MAGIC_RESISTANCE, 0, 0, 3, 0, 50 }, { CLOAK_OF_PROTECTION, 0, 0, 3, 0, 25 }, { LEATHER_CLOAK, 0, 0, 0, 0, 25 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
				{ { { BRACERS_OF_DEFENSE, 0, 0, 3, 0, 50 }, { BRACERS_OF_SPELL_CASTING, 0, 0, 3, 0, 25 }, { LEATHER_BRACERS, 0, 0, 0, 0, 25 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
				{ { { ROBE_OF_THE_ARCHMAGI, 0, 0, 3, 0, 50 }, { ROBE_OF_EYES, 0, 0, 3, 0, 25 }, { ROBE, 0, 0, 0, 0, 25 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
					  NORANDOMIZEDALTERNATIVES }
				},
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		ED_HELL_ONLY
	},

	{
		{
			/* Monster 1 */
			{ { { PM_LICH, 1, 0, NAMELIST_LICH, EM_NAME_KNOWN, 40, NOMONSTERITEMS },
				{ PM_DEMILICH, 1, 0, NAMELIST_LICH, EM_NAME_KNOWN, 40, NOMONSTERITEMS },
				NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		20,
		ED_IGNORE_MONSTER_APPEARANCE_FLAGS
	},

	{
		{
			/* Monster 1 */
			{ { { PM_OGRE_LORD, 1, 1, 0, 0, 100,
					{ { { { CLUB, 0, 0, 2, 0, 50 }, { BATTLE_AXE, 0, 1, 2, 0, 50 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
					  NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES } },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_OGRE, 2, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER, 
			NORANDOMIZEDMONSTER, 
			NORANDOMIZEDMONSTER 
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ORC_CAPTAIN, 1, 1, 0, 0, 100,
					{ { { { TWO_HANDED_SWORD, 0, 0, 2, 0, 50 }, { BATTLE_AXE, 0, 0, 2, 0, 50 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
					  NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES } },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_HILL_ORC, 3, 4, 0, 0, 40, NOMONSTERITEMS }, { PM_MORDOR_ORC, 3, 4, 0, 0, 30, NOMONSTERITEMS }, { PM_URUK_HAI, 3, 4, 0, 0, 30, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			{ { { PM_ORC_SHAMAN, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		30,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GOBLIN_KING, 0, 1, NAMELIST_GOBLIN_KING, EM_NAME_KNOWN, 100,
					{ { { { CLUB, 0, 1, 2, 0, 30 }, { BATTLE_AXE, 0, 1, 2, 0, 30 }, { ORCISH_SHORT_SWORD, 0, 1, 2, 0, 40 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
					  NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES } },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_HOBGOBLIN, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_GOBLIN, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		30,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_KOBOLD_LORD, 0, 1, 0, 0, 100,
					{ { { { DAGGER, 0, 0, 2, 0, 50 }, { SHORT_SWORD, 0, 0, 2, 0, 50 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
					  NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES } },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_LARGE_KOBOLD, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_KOBOLD, 2, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 4 */
			{ { { PM_KOBOLD_SHAMAN, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER
		},
		15,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GNOLL_KING, 1, 0, 0, 0, 100,
					{ { { { FLAIL, 0, 1, 3, 0, 50 }, { DOUBLE_HEADED_FLAIL, 0, 1, 2, 0, 50 }, NORANDOMIZEDITEM, NORANDOMIZEDITEM, NORANDOMIZEDITEM } },
					  NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES, NORANDOMIZEDALTERNATIVES } },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_GNOLL_LORD, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_GNOLL, 3, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 4 */
			{ { { PM_GNOLL_WARDEN, 1, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 5 */
			{ { { PM_HYENA, 4, 0, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  }
		},
		30,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GNOLL_LORD, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_GNOLL, 2, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_GNOLL_WARDEN, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 4 */
			{ { { PM_HYENA, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER
		},
		30,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GNOME_KING, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_GNOME_LORD, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_GNOME, 2, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 4 */
			{ { { PM_GNOMISH_WIZARD, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_FLIND_LORD, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_FLIND, 1, 3, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_SHOOSUVA, 0, 3, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_BLACK_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_BLACK_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_BLACK_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_BLACK_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_GRAY_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_GRAY_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GRAY_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_GRAY_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_RED_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_RED_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_RED_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_RED_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_BLUE_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_BLUE_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_BLUE_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_BLUE_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_WHITE_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_WHITE_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_WHITE_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_WHITE_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_ORANGE_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_ORANGE_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ORANGE_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_ORANGE_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_GREEN_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_GREEN_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_GREEN_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_GREEN_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_ANCIENT_YELLOW_DRAGON, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_YELLOW_DRAGON, 2, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_YELLOW_DRAGON, 1, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_YELLOW_DRAGON_HATCHLING, 2, 4, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_OWLBEAR_PATRIARCH, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 2 */
			{ { { PM_OWLBEAR_MATRIARCH, 0, 1, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 3 */
			{ { { PM_OWLBEAR_SHAMAN, 0, 2, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			/* Monster 4 */
			{ { { PM_OWLBEAR, 2, 3, 0, 0, 100, NOMONSTERITEMS }, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},

	{
		{
			/* Monster 1 */
			{ { { PM_UMBER_HULK, 2, 2, 0, 0, 100, NOMONSTERITEMS },
			NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE, NOMONSTERALTERNATIVE }  },
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER,
			NORANDOMIZEDMONSTER
		},
		10,
		0
	},


	NOENCOUNTER,
};


static struct encounter zeroencounter = { 0 };
#define MAX_ENCOUNTERS 2048
static struct encounter encounter_list[MAX_ENCOUNTERS];




void encounter_init();

STATIC_DCL void FDECL(write_encounter_monsterdata, (int, int, int*, int*, double));
STATIC_DCL void FDECL(calculate_encounter_difficulty, (int, int));



void
encounter_init()
{
	for (int j = 0; j < MAX_ENCOUNTERS; j++)
	{
		encounter_list[j] = zeroencounter;
		for (int i = 0; i < MAX_ENCOUNTER_MONSTERS; i++)
		{
			encounter_list[j].encounter_monsters[i].permonstid = NON_PM;
		}
	}

	int encounternum = 0;
	int encountermonsternum = 0;

	/* Write 'spanned' encounter data */
	for (int i = 1; encounter_definitions[i].probability > 0; i++)
	{
		encountermonsternum = 0;
		write_encounter_monsterdata(i, 0, &encountermonsternum, &encounternum, encounter_definitions[i].probability / 100);
		encounternum++;
	}

	/* Calculate encounter difficulties */
	for (int attk_mon_num = 1; attk_mon_num <= MAX_ENCOUNTER_ATTACKING_MONSTERS; attk_mon_num++)
	{
		for (int i = 0; i < MAX_ENCOUNTERS; i++)
		{
			if (encounter_list[i].probability == 0)
				break;

			calculate_encounter_difficulty(i, attk_mon_num);
		}
	}

    return;
}

STATIC_OVL
void 
write_encounter_monsterdata(encounter_definition_index, monster_type_index, active_encounter_monster_index_ptr, active_encounter_index_ptr, encprob)
int encounter_definition_index;
int monster_type_index;
int* active_encounter_monster_index_ptr;
int* active_encounter_index_ptr;
double encprob;
{
	if (monster_type_index >= MAX_ENCOUNTER_MONSTER_TYPES)
		return;

	if (!active_encounter_index_ptr || !active_encounter_monster_index_ptr)
		return;

	encounter_list[*active_encounter_index_ptr].eflags = encounter_definitions[encounter_definition_index].eflags;
	encounter_list[*active_encounter_index_ptr].encounterdefid = encounter_definition_index;

	int orig_encounter_index = 0;
	int orig_monster_index = 0;
	struct encounter base_encounter = { 0 };

	orig_encounter_index = *active_encounter_index_ptr;
	base_encounter = encounter_list[*(active_encounter_index_ptr)];
	orig_monster_index = *active_encounter_monster_index_ptr;

	for(int rnd_monster_index = 0; rnd_monster_index < MAX_RANDOM_MONSTER_ALTERNATIVES; rnd_monster_index++)
	{
		int numrnd = encounter_definitions[encounter_definition_index].encounter_monster_types[monster_type_index].random_encounter_monsters[rnd_monster_index].generatednumber_random;
		int numconst = encounter_definitions[encounter_definition_index].encounter_monster_types[monster_type_index].random_encounter_monsters[rnd_monster_index].generatednumber_constant;
		int pmid = encounter_definitions[encounter_definition_index].encounter_monster_types[monster_type_index].random_encounter_monsters[rnd_monster_index].permonstid;

		double monster_type_probability = encounter_definitions[encounter_definition_index].encounter_monster_types[monster_type_index].random_encounter_monsters[rnd_monster_index].probability / 100;
		*active_encounter_monster_index_ptr = orig_monster_index;

		if (numrnd == 0 && numconst == 0)
		{
			if(encounter_list[*active_encounter_index_ptr].probability == 0)
				encounter_list[*active_encounter_index_ptr].probability = encprob * 100;

			break;
		}

		for (int i = 0; i <= numrnd; i++)
		{
			double monster_number_probability = 1 / (1 + (double)numrnd);

			/* Make sure that first time everything is written in the same encounter */
			if(i > 0)
			{
				/* Move to a new encounter slot */
				(*active_encounter_index_ptr) = (*active_encounter_index_ptr) + 1;

				/* Write eflags and encounter definition index just in case */
				encounter_list[*active_encounter_index_ptr].eflags = encounter_definitions[encounter_definition_index].eflags;
				encounter_list[*active_encounter_index_ptr].encounterdefid = encounter_definition_index;

				/* Check whether there is space to write new encounters, if not, exit */
				if (*active_encounter_index_ptr >= MAX_ENCOUNTERS)
					return;

				/* Copy the data from the original encounter as a basis for the new encounter */
				if(monster_type_index > 0)
					encounter_list[*active_encounter_index_ptr] = base_encounter;

				/* Set the encounter monster pointer to the original value */
				(*active_encounter_monster_index_ptr) = orig_monster_index;
			}
			/* Now, both randomized monster has been selected (rnd_monster_index)
			 * as well as the number of those monsters (i)
			 */
			int num = numconst + i;

			/* Write num monsters to the current encounter */
			for (int j = 1; j <= num; j++)
			{
				if (*active_encounter_monster_index_ptr >= MAX_ENCOUNTER_MONSTERS)
					break;

				encounter_list[*(active_encounter_index_ptr)].encounter_monsters[*active_encounter_monster_index_ptr].permonstid = pmid;
				encounter_list[*(active_encounter_index_ptr)].encounter_monsters[*active_encounter_monster_index_ptr].mflags = 
					encounter_definitions[encounter_definition_index].encounter_monster_types[monster_type_index].random_encounter_monsters[rnd_monster_index].mflags;
				encounter_list[*(active_encounter_index_ptr)].encounter_monsters[*active_encounter_monster_index_ptr].namelistid =
+					encounter_definitions[encounter_definition_index].encounter_monster_types[monster_type_index].random_encounter_monsters[rnd_monster_index].namelistid;
				for(int k = 0; k < MAX_MONSTER_ITEMS; k++)
				{
					encounter_list[*(active_encounter_index_ptr)].encounter_monsters[*active_encounter_monster_index_ptr].monster_items[k] = 
						encounter_definitions[encounter_definition_index].encounter_monster_types[monster_type_index].random_encounter_monsters[rnd_monster_index].monster_items[k];
				}

				/* Move to next free monster slot */
				(*active_encounter_monster_index_ptr) = (*active_encounter_monster_index_ptr) + 1;
			}

			/* Move to the next monster */
			if (monster_type_index < MAX_ENCOUNTER_MONSTER_TYPES - 1)
			{
				write_encounter_monsterdata(encounter_definition_index, monster_type_index + 1, active_encounter_monster_index_ptr, active_encounter_index_ptr,
					encprob * monster_type_probability * monster_number_probability);
			}
			else
			{
				encounter_list[*active_encounter_index_ptr].probability = encprob * monster_type_probability * monster_number_probability * 100;
			}
		}
	}
}



STATIC_OVL
void
calculate_encounter_difficulty(encounter_index, max_attk_monsters)
int encounter_index;
int max_attk_monsters;
{

	long maxdifficulty = 0;
	long mindifficulty = 0;
	long pointdifficulty = 0;
	//double totaldifficulty = 0;
	//double totalsquareddifficulty = 0;
	double totalcubeddifficulty = 0;
	double totalthreehalvespowerdifficulty = 0;
	double totalpowdifficulty = 0;
	double power = 1.0/3.0;
	int monster_cnt = 0;
	for (int i = 0; i < MAX_ENCOUNTER_MONSTERS; i++)
	{
		int pmid = encounter_list[encounter_index].encounter_monsters[i].permonstid;
		if (pmid == NON_PM)
			break;
		monster_cnt++;
	}
	double applicable_max = min((double)monster_cnt, 8.0);
	double applicable_attk_mon = min((double)max_attk_monsters, applicable_max);

	if (applicable_attk_mon >= applicable_max)
		power = 2.0 / 3.0;
	else if (applicable_attk_mon <= 1.0 || applicable_max <= 1.0)
		power = 1.0 / 3.0;
	else
		power = (1.0 + (((double)applicable_attk_mon - 1.0) / (applicable_max - 1.0)) * (2.0 - 1.0)) / 3.0;

	if (power <= 0)
		power = 1.0 / 3.0;

	for (int i = 0; i < MAX_ENCOUNTER_MONSTERS; i++)
	{
		int pmid = encounter_list[encounter_index].encounter_monsters[i].permonstid;
		if (pmid == NON_PM)
			break;
		double monster_difficulty = (double)max(1, mons[pmid].difficulty); // Treat level 0 monsters as level 1
		//totaldifficulty += (double)monster_difficulty;
		//totalsquareddifficulty += (double)monster_difficulty * (double)monster_difficulty;
		totalcubeddifficulty += pow(monster_difficulty, 3.0);
		totalthreehalvespowerdifficulty += pow(monster_difficulty, 1.5);
		totalpowdifficulty += pow(monster_difficulty, 1.0 / power);
	}

	maxdifficulty = (long)round(pow(totalthreehalvespowerdifficulty, 1.0 / 1.5));
	mindifficulty = (long)round(pow(totalcubeddifficulty, 1.0 / 3.0));
	if (maxdifficulty < mindifficulty)
		maxdifficulty = mindifficulty;
	pointdifficulty = (long)round(pow(totalpowdifficulty, power));
	if (pointdifficulty < mindifficulty)
		pointdifficulty = mindifficulty;
	if (pointdifficulty > maxdifficulty)
		pointdifficulty = maxdifficulty;

	encounter_list[encounter_index].difficulty_max = (int)maxdifficulty;
	encounter_list[encounter_index].difficulty_min = (int)mindifficulty;

	/* Calculate Tommi's point estimate */
	/* This currently assumes that encounter definitions list monsters in descending order of difficulty,
	 * or at least in the order they are assumed to be killed in combet;
	 * otherwise, they need to be sorted into descending order 
	 */
	//int max_attacking_monsters = max_attk_monsters;
	//double combatvalue = 0;
	//double difficulty_point_estimate = 0;

#if 0
	for (int i = 0; i < MAX_ENCOUNTER_MONSTERS; i++)
	{
		int pmid = encounter_list[encounter_index].encounter_monsters[i].permonstid;
		if (pmid == NON_PM)
			break;

		int current_monster_difficulty = max(1, mons[pmid].difficulty);

		double ehp = (double)current_monster_difficulty;
		double dptu = 0;
		for (int j = i; j < MAX_ENCOUNTER_MONSTERS && j <= i + max_attacking_monsters ; j++)
		{
			int dpmid = encounter_list[encounter_index].encounter_monsters[j].permonstid;
			if (dpmid == NON_PM)
				break;
			int dptu_monster_difficulty = max(1, mons[dpmid].difficulty);
			dptu += (double)dptu_monster_difficulty;
		}
		combatvalue += dptu * ehp;
	}
#endif

#if 0
	double sum = 0;
	long totaldifficulty_of_removed_monsters = 0;

	for (int i = 0; i < MAX_ENCOUNTER_MONSTERS; i++)
	{
		int pmid = encounter_list[encounter_index].encounter_monsters[i].permonstid;
		if (pmid == NON_PM)
			break;

		int current_monster_difficulty = max(1, mons[pmid].difficulty);

		sum += ((double)totaldifficulty - (double)totaldifficulty_of_removed_monsters) * ((double)current_monster_difficulty / (double)totaldifficulty);

		/* Move to next and mark this as 'removed' */
		totaldifficulty_of_removed_monsters += (long)current_monster_difficulty;
	}

	combatvalue = sum * (double)totaldifficulty;
#endif
#if 0
	if (max_attk_monsters >= 8)
		difficulty_point_estimate = maxdifficulty;
	else if (max_attk_monsters <= 1)
		difficulty_point_estimate = mindifficulty;
	else
		difficulty_point_estimate = mindifficulty + (((double)max_attk_monsters - 1.0) / 7.0) * (maxdifficulty - mindifficulty); // round(sqrt(combatvalue));
#endif

	encounter_list[encounter_index].difficulty_point_estimate[max_attk_monsters] = (int)pointdifficulty;
}


void
randomize_encounter(x, y)
int x, y;
{
	double totalrollprob = 0;
	int selected_encounter = 0;
	double totalselectedprob = 0;
	int acceptable_encounter_count = 0;
	int maxmlev = 0, minmlev = 0;

	int max_attk_monsters = 2;
	if (Is_bigroom(&u.uz))
		max_attk_monsters = 6;
	else if (In_mines(&u.uz))
		max_attk_monsters = 3;

	for (int i = 1; i <= 1; i++)
	{
		totalselectedprob = 0;

		get_generated_monster_minmax_levels(i, &minmlev, &maxmlev, 0);

		for (int j = 0; j < MAX_ENCOUNTERS && encounter_list[j].probability > 0; j++)
		{
			encounter_list[j].insearch = FALSE;

			if ((encounter_list[j].eflags & ED_ONLY_ONCE) && context.encounter_appeared[encounter_list[j].encounterdefid] == TRUE)
				continue;

			if ((encounter_list[j].eflags & ED_NOHELL) && Inhell)
				continue;

			if ((encounter_list[j].eflags & ED_HELL_ONLY) && !Inhell)
				continue;

			if ((encounter_list[j].eflags & ED_NOMINES) && In_mines(&u.uz))
				continue;

			if ((encounter_list[j].eflags & ED_MINES_ONLY) && !In_mines(&u.uz))
				continue;


			if (
				(encounter_list[j].difficulty_point_estimate[max_attk_monsters] >= minmlev && encounter_list[j].difficulty_point_estimate[max_attk_monsters] <= maxmlev)
				)
			{
				encounter_list[j].insearch = TRUE;
				totalselectedprob += encounter_list[j].probability;
				acceptable_encounter_count++;
			}

		}
		if (totalselectedprob > 0)
			break;
	}

	int roll_int = rn2(32000); /* totalprob should be 1000, but just in case it is accidently less or more */
	double roll = (double)roll_int / 32000.0 * totalselectedprob;

	if (totalselectedprob > 0)
	{
		for (int i = 1; i < MAX_ENCOUNTERS; i++)
		{
			if(encounter_list[i].insearch)
				totalrollprob += encounter_list[i].probability;

			if (totalrollprob >= roll)
			{
				selected_encounter = i;
				break;
			}
		}
	}

	if (selected_encounter > 0)
	{
		context.encounter_appeared[encounter_list[selected_encounter].encounterdefid] = TRUE;
		create_encounter(selected_encounter, x, y);
	}
	else
	{
		makemon((struct permonst*)0, x, y, NO_MM_FLAGS);
	}

	return;
}


void
create_encounter(selected_encounter, x, y)
int selected_encounter, x, y;
{
	int max_attk_monsters = 2;
	if (Is_bigroom(&u.uz))
		max_attk_monsters = 6;
	else if (In_mines(&u.uz))
		max_attk_monsters = 3;

	/* Calculate experience first */
	long encounter_experience = 1 + encounter_list[selected_encounter].difficulty_point_estimate[max_attk_monsters] * encounter_list[selected_encounter].difficulty_point_estimate[max_attk_monsters];
	long total_monster_experience = 0;
	long total_monster_difficulty = 0;

	boolean upper = Is_rogue_level(&u.uz);
	boolean elemlevel = In_endgame(&u.uz) && !Is_astralevel(&u.uz);

	for (int i = 0; i < MAX_ENCOUNTER_MONSTERS; i++)
	{
		int pmid = encounter_list[selected_encounter].encounter_monsters[i].permonstid;
		if (pmid == NON_PM)
			break;

		if (mvitals[pmid].mvflags & G_GONE)
			continue;
		if (upper && !isupper((uchar)def_monsyms[(int)mons[pmid].mlet].sym))
			continue;
		if (elemlevel && wrong_elem_type(&mons[pmid]))
			continue;
		if(!(encounter_list[selected_encounter].eflags & ED_IGNORE_MONSTER_APPEARANCE_FLAGS)
			&& !(encounter_list[selected_encounter].encounter_monsters[i].mflags & EM_IGNORE_APPEARANCE_FLAGS)
			)
		{
			if (Inhell && mons[pmid].geno & G_NOHELL)
				continue;
			if (!Inhell && mons[pmid].geno & G_HELL)
				continue;
			if (In_mines(&u.uz) && (mons[pmid].geno & G_NOMINES))
				continue;
		}
		total_monster_experience += 1 + mons[pmid].difficulty * mons[pmid].difficulty;
		total_monster_difficulty += mons[pmid].difficulty;
	}

	long xpdiff = encounter_experience - total_monster_experience;
	if (xpdiff < 0)
		xpdiff = 0;

	int nx = x, ny = y;
	for (int i = 0; i < MAX_ENCOUNTER_MONSTERS; i++)
	{
		int pmid = encounter_list[selected_encounter].encounter_monsters[i].permonstid;
		if (pmid == NON_PM)
			break;

		if (mvitals[pmid].mvflags & G_GONE)
			continue;
		if (upper && !isupper((uchar)def_monsyms[(int)mons[pmid].mlet].sym))
			continue;
		if (elemlevel && wrong_elem_type(&mons[pmid]))
			continue;
		if (!(encounter_list[selected_encounter].eflags & ED_IGNORE_MONSTER_APPEARANCE_FLAGS)
			&& !(encounter_list[selected_encounter].encounter_monsters[i].mflags & EM_IGNORE_APPEARANCE_FLAGS)
			)
		{
			if (Inhell && mons[pmid].geno & G_NOHELL)
				continue;
			if (!Inhell && mons[pmid].geno & G_HELL)
				continue;
			if (In_mines(&u.uz) && (mons[pmid].geno & G_NOMINES))
				continue;
		}

		int extraflags = 0;
		if (encounter_list[selected_encounter].encounter_monsters[i].mflags & EM_MAXIMUM_HIT_POINTS)
			extraflags |= MM_MAX_HP;
		if (encounter_list[selected_encounter].encounter_monsters[i].mflags & EM_FORCE_MALE)
			extraflags |= MM_MALE;
		if (encounter_list[selected_encounter].encounter_monsters[i].mflags & EM_FORCE_FEMALE)
			extraflags |= MM_FEMALE;

		struct monst* mon = (struct monst*)0;
		mon = makemon(&mons[pmid], nx, ny, MM_NOGRP | MM_ADJACENTOK | extraflags);

		if(mon)
		{
			if (nx == 0 && ny == 0)
			{
				nx = mon->mx;
				ny = mon->my;
			}

			int monster_difficulty = mons[pmid].difficulty;
			long monster_experience = 1 + monster_difficulty * monster_difficulty;
			
			if(xpdiff > 0 && total_monster_difficulty > 0)
				mon->extra_encounter_xp = (xpdiff * monster_difficulty) / total_monster_difficulty;

			/* Force peaceful if need be */
			if (encounter_list[selected_encounter].encounter_monsters[i].mflags & EM_FORCE_PEACEFUL)
				mon->mpeaceful = 1;

			/* Name monster */
			if (encounter_list[selected_encounter].encounter_monsters[i].namelistid > 0 &&
				!(mon->data->geno & G_UNIQ 
					|| mon->isshk
				))
			{
				int nlid = encounter_list[selected_encounter].encounter_monsters[i].namelistid;
				int listnamecnt = 0;
				for (int j = 0; j < MAX_NAMELIST_NAMES; j++)
				{
					if (!namelists[nlid][j] || namelists[nlid][j] == '\0' || strcmp(namelists[nlid][j], "\0") == 0 || strcmp(namelists[nlid][j], "") == 0)
						break;

					char* bp;
					char testbuf[BUFSIZ] = "";
					Sprintf(testbuf, "|%s|", namelists[nlid][j]);
					if ((bp = strstri(context.used_names, testbuf)) != 0)
						continue;

					listnamecnt++;
				}

				if(listnamecnt > 0)
				{
					int roll = listnamecnt == 1 ? 0 : rn2(listnamecnt);
					int selectedindex = -1;
					char buf[BUFSZ] = "";
					char* bp;
					char testbuf[BUFSIZ] = "";
					int k = 0;
					boolean allused = FALSE;

					for(int k = 0; k <= roll; k++)
					{
						do
						{
							selectedindex++;
							if (selectedindex >= MAX_NAMELIST_NAMES)
							{
								allused = TRUE; 
								break;
							}
							Sprintf(testbuf, "|%s|", namelists[nlid][selectedindex]);
						} while ((bp = strstri(context.used_names, testbuf)) != 0);

						if (allused)
							break;
					} 

					if(!allused && selectedindex >= 0 && selectedindex < MAX_NAMELIST_NAMES)
					{
						strcpy(buf, namelists[nlid][selectedindex]);
						if (!(
							!namelists[nlid][selectedindex]
							|| namelists[nlid][selectedindex] == '\0'
							|| strcmp(namelists[nlid][selectedindex], "\0") == 0
							|| strcmp(namelists[nlid][selectedindex], "") == 0))
						{
							(void)christen_monst(mon, buf);
							if(encounter_list[selected_encounter].encounter_monsters[i].mflags & EM_NAME_KNOWN)
								mon->u_know_mname = 1; /* They are famous enough! */
							Sprintf(eos(context.used_names), "%s|", buf);
						}
					}
				}

			}

			/* Add items */
			for (int j = 0; j < MAX_MONSTER_ITEMS; j++)
			{
				int roll = rn2(100);
				int selected_item = -1;
				int totalprob = 0;
				for (int k = 0; k < MAX_MONSTER_RANDOM_ITEM_ALTERNATIVES; k++)
				{
					totalprob += encounter_list[selected_encounter].encounter_monsters[i].monster_items[j].random_monster_items[k].probability;
					if (totalprob >= roll)
					{
						selected_item = k;
						break;
					}
				}

				if (totalprob == 0)
					break;

				if (selected_item > -1)
				{
					int otyp = (int)encounter_list[selected_encounter].encounter_monsters[i].monster_items[j].random_monster_items[selected_item].otyp;
					short oartifact = encounter_list[selected_encounter].encounter_monsters[i].monster_items[j].random_monster_items[selected_item].oartifact;
					long flags = encounter_list[selected_encounter].encounter_monsters[i].monster_items[j].random_monster_items[selected_item].iflags;
					if (otyp > STRANGE_OBJECT)
					{
						struct obj* otmp = mksobj(otyp, !!(flags & MI_INITIALIZE), !!(flags & MI_ALLOW_ARTIFACTS), FALSE);

						if (otmp)
						{
							/* Make it into the artifact */
							if (oartifact > 0)
								otmp = oname(otmp, artiname(oartifact));

							if (flags & MI_BLESSED)
								bless(otmp);
							else if (flags & MI_CURSED)
								curse(otmp);
							else if (flags & MI_UNCURSED)
								otmp->blessed = otmp->cursed = 0;

							if (flags & MI_ERODEPROOF)
								otmp->oerodeproof = TRUE;

							if (!(flags & MI_IGNORE_SPE))
							{
								int enchantment = encounter_list[selected_encounter].encounter_monsters[i].monster_items[j].random_monster_items[selected_item].spe_constant;

								if (encounter_list[selected_encounter].encounter_monsters[i].monster_items[j].random_monster_items[selected_item].spe_random > 0)
									enchantment += rn2(1 + encounter_list[selected_encounter].encounter_monsters[i].monster_items[j].random_monster_items[selected_item].spe_random);

								otmp->enchantment = enchantment;
							}

							(void)mpickobj(mon, otmp);
						}
					}
				}
			}
		}
	}
}


/* Save encounter list */
int
wiz_save_encounters(VOID_ARGS) /* Save a csv file for encounters */
{
	if (wizard)
	{
		pline("Starting writing encounters.csv...");
		const char* fq_save = "encounters.csv";
		int fd;

		(void)remove(fq_save);

#ifdef MAC
		fd = macopen(fq_save, O_WRONLY | O_TEXT | O_CREAT | O_TRUNC, TEXT_TYPE);
#else
		fd = open(fq_save, O_WRONLY | O_TEXT | O_CREAT | O_TRUNC, FCMASK);
#endif

		char buf[BUFSIZ] = "";

		Sprintf(buf, "#,DifMin");
		(void)write(fd, buf, strlen(buf));
		for (int j = 1; j <= MAX_ENCOUNTER_ATTACKING_MONSTERS; j++)
		{
			Sprintf(buf, ",DifP%d", j);
			(void)write(fd, buf, strlen(buf));

		}
		Sprintf(buf, ",DifMax,Probability");
		(void)write(fd, buf, strlen(buf));


		for (int j = 0; j < 16; j++)
		{
			Sprintf(buf, ",%d,Monster", j + 1);
			(void)write(fd, buf, strlen(buf));

		}
		Sprintf(buf, "\n");
		(void)write(fd, buf, strlen(buf));



		for (int i = 0; i < MAX_ENCOUNTERS; i++)
		{
			if (encounter_list[i].probability == 0)
				break;

			Sprintf(buf, "%d,%d", i, encounter_list[i].difficulty_min);
			(void)write(fd, buf, strlen(buf));

			for (int j = 1; j <= MAX_ENCOUNTER_ATTACKING_MONSTERS; j++)
			{
				Sprintf(buf, ",%d", encounter_list[i].difficulty_point_estimate[j]);
				(void)write(fd, buf, strlen(buf));
			}

			Sprintf(buf, ",%d,%f",
				encounter_list[i].difficulty_max,
				encounter_list[i].probability
			);
			(void)write(fd, buf, strlen(buf));



			for (int j = 0; j < MAX_ENCOUNTER_MONSTERS; j++)
			{
				if (encounter_list[i].encounter_monsters[j].permonstid == NON_PM)
					break;
				Sprintf(buf, ",%d,%s",
					j+1,
					mons[encounter_list[i].encounter_monsters[j].permonstid].mname
				);
				(void)write(fd, buf, strlen(buf));
			}
			Sprintf(buf, "\n");
			(void)write(fd, buf, strlen(buf));
		}
		(void)close(fd);

		pline("Done!");
	}
	else
		pline("Command unavailable.");

	return 0;
}


/*encounter.c*/

/* GnollHack 4.0 soundset.c */
/* Copyright (c) Janne Gustafsson, 2020.                            */
/* GnollHack may be freely redistributed.  See license for details. */

#include "hack.h"
#include "lev.h" /* for checking save modes */
#include "artifact.h"
#include "artilist.h"

NEARDATA struct soundsource_t* sound_base = 0;
STATIC_DCL void FDECL(set_hearing_array, (int, int, double, int));


NEARDATA struct player_soundset_definition player_soundsets[MAX_PLAYER_SOUNDSETS] =
{
	{
		"",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE}
	},
	{
		"Generic",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_PUSH_EFFORT, 1.0f}, {GHSOUND_GOBLIN_DEATH, 1.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_HUMAN_BAREHANDED, OBJECT_SOUNDSET_HUMAN_BAREFOOTED}
    },
	{
		"",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE}
    }
};


NEARDATA struct monster_soundset_definition monster_soundsets[MAX_MONSTER_SOUNDSETS] =
{
	{
		"",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE, OBJECT_SOUNDSET_NONE}
    },
	{
		"Generic",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_MONSTER_DEATH_GENERIC, 1.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_HUMAN_BAREHANDED, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_HUMAN_BAREFOOTED}
    },
	{
		"Goblin",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_GOBLIN_DEATH, 1.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_HUMAN_BAREHANDED, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_HUMAN_BAREFOOTED}
    },
	{
		"Dragon",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_HUMAN_BAREFOOTED}
    },
	{
		"Dracolich",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_HUMAN_BAREFOOTED}    },
    {
        "Bee",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_HUMAN_BAREFOOTED}
    },
    {
        "Horse",
        {{GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_NONE, 0.0f}, {GHSOUND_MONSTER_DEATH_GENERIC, 1.0f}},
        SOUNDSOURCE_AMBIENT_GENERAL,
        {OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_GENERAL, OBJECT_SOUNDSET_HORSE_BAREFOOTED}
    },
};


NEARDATA struct object_soundset_definition object_soundsets[MAX_OBJECT_SOUNDSETS] =
{
    {
        "",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_NONE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "general",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_BOW_FIRE, 1.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_PLAYER_FOOTSTEPS_NORMAL, 1.0f},
            {GHSOUND_GENERIC_FLY, 1.0f},
            {GHSOUND_GENERIC_LEVITATE, 1.0f},
            {GHSOUND_NONE, 1.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,        
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_GENERIC
    },
    {
        "candle",
        {
            {GHSOUND_FIRE, 0.3f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_LIT,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "quarterstaff",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "bow",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_BOW_FIRE, 1.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "crossbow",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_CROSSBOW_FIRE, 1.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "arrow",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 1.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "sword",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_SWORD_SWING, 1.0f},
            {GHSOUND_SWORD_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_SWORD_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "axe",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_AXE_SWING, 1.0f},
            {GHSOUND_AXE_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_SWORD_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "dagger",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DAGGER_SWING, 1.0f},
            {GHSOUND_DAGGER_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_DAGGER_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "bone dagger",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "human barehanded",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_HUMAN_BAREHANDED_SWING, 1.0f},
            {GHSOUND_HUMAN_BAREHANDED_HIT, 1.0f},
            {GHSOUND_NONE, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "human barefooted",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_HUMAN_KICK_SWING, 1.0f},
            {GHSOUND_HUMAN_KICK_HIT, 1.0f},
            {GHSOUND_NONE, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_PLAYER_FOOTSTEPS_NORMAL, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "horse barefooted",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_HUMAN_KICK_SWING, 1.0f},
            {GHSOUND_HUMAN_KICK_HIT, 1.0f},
            {GHSOUND_NONE, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_HORSE_FOOTSTEPS, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "cotton slippers",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_HUMAN_KICK_SWING, 1.0f},
            {GHSOUND_HUMAN_KICK_HIT, 0.5f},
            {GHSOUND_NONE, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_FOOTSTEPS_COTTON_SLIPPERS, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "chest",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_CHEST_UNLOCK, 1.0f},
            {GHSOUND_CHEST_LOCK, 1.0f},
            {GHSOUND_CHEST_BREAK_LOCK, 1.0f},
            {GHSOUND_CHEST_LID_SLAM, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "coins",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_PICKUP_COINS, 1.0f},
            {GHSOUND_DROP_COINS, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    },
    {
        "boulder",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_STAFF_SWING, 1.0f},
            {GHSOUND_STAFF_HIT, 1.0f},
            {GHSOUND_GENERIC_ITEM_THROW, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_ARROW_HIT, 1.0f},

            {GHSOUND_GENERIC_ITEM_PICK_UP, 1.0f},
            {GHSOUND_GENERIC_ITEM_DROP, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},

            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DISCARD_GENERIC, 1.0f},
            {GHSOUND_SPARKS_FLY_GENERIC, 1.0f},
            {GHSOUND_PUSH_BOULDER, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL,
        {
            OCCUPATION_SOUNDSET_NONE,
            OCCUPATION_SOUNDSET_GENERIC_EATING,
            OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK,
            OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP,
            OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF,
            OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK,
            OCCUPATION_SOUNDSET_GENERIC_STUDYING,
            OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND,
            OCCUPATION_SOUNDSET_GENERIC_SWINGING,
            OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR,
            OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE
        },
        OBJECT_RAY_SOUNDSET_NONE
    }
};

NEARDATA struct occupation_soundset_definition occupation_soundset_definitions[MAX_OCCUPATION_SOUNDSETS] =
{
    {
        "",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_EATING",
        {
            {GHSOUND_EAT_GENERIC_AMBIENT, 1.0f},
            {GHSOUND_EAT_GENERIC_START, 1.0f},
            {GHSOUND_EAT_GENERIC_FINISH, 1.0f},
            {GHSOUND_EAT_GENERIC_INTERRUPTED, 1.0f},
            {GHSOUND_EAT_GENERIC_RESUME, 1.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_OPENING_TIN",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_DIGGING_ROCK",
        {
            {GHSOUND_DIGGING_GENERIC_AMBIENT, 1.0f},
            {GHSOUND_DIGGING_GENERIC_START, 1.0f},
            {GHSOUND_DIGGING_GENERIC_FINISH, 1.0f},
            {GHSOUND_DIGGING_GENERIC_INTERRUPTED, 1.0f},
            {GHSOUND_DIGGING_GENERIC_RESUME, 1.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_SETTING_TRAP",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_WIPING_OFF",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_TAKING_OFF",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_PICKING_LOCK",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_FORCING_LOCK",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_STUDYING",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_DIGGING_GROUND",
        {
            {GHSOUND_DIGGING_GROUND_GENERIC_AMBIENT, 1.0f},
            {GHSOUND_DIGGING_GROUND_GENERIC_START, 1.0f},
            {GHSOUND_DIGGING_GROUND_GENERIC_FINISH, 1.0f},
            {GHSOUND_DIGGING_GROUND_GENERIC_INTERRUPTED, 1.0f},
            {GHSOUND_DIGGING_GROUND_GENERIC_RESUME, 1.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_SWINGING",
        {
            {GHSOUND_DIGGING_GENERIC_AMBIENT, 1.0f},
            {GHSOUND_DIGGING_GENERIC_START, 1.0f},
            {GHSOUND_DIGGING_GENERIC_FINISH, 1.0f},
            {GHSOUND_DIGGING_GENERIC_INTERRUPTED, 1.0f},
            {GHSOUND_DIGGING_GENERIC_RESUME, 1.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_HITTING_DOOR",
        {
            {GHSOUND_DIGGING_GENERIC_AMBIENT, 1.0f},
            {GHSOUND_DIGGING_GENERIC_START, 1.0f},
            {GHSOUND_DIGGING_GENERIC_FINISH, 1.0f},
            {GHSOUND_DIGGING_GENERIC_INTERRUPTED, 1.0f},
            {GHSOUND_DIGGING_GENERIC_RESUME, 1.0f}
        }
    },
    {
        "OCCUPATION_SOUNDSET_GENERIC_CUTTING_TREE",
        {
            {GHSOUND_DIGGING_GENERIC_AMBIENT, 1.0f},
            {GHSOUND_DIGGING_GENERIC_START, 1.0f},
            {GHSOUND_DIGGING_GENERIC_FINISH, 1.0f},
            {GHSOUND_DIGGING_GENERIC_INTERRUPTED, 1.0f},
            {GHSOUND_DIGGING_GENERIC_RESUME, 1.0f}
        }
    },
};

NEARDATA struct location_soundset_definition location_soundsets[MAX_LOCATION_SOUNDSETS] =
{
    {
        "",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL
    },
    {
        "general",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL
    },
    {
        "fountain",
        {
            {GHSOUND_FOUNTAIN, 0.75f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL
    },
    {
        "altar",
        {
            {GHSOUND_FIRE, 0.5f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_LIT
    },
    {
        "door",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_DOOR_WHAM, 1.0f},
            {GHSOUND_DOOR_BREAK, 1.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL
    },
};


NEARDATA struct region_soundset_definition region_soundsets[MAX_REGION_SOUNDSETS] =
{
    {
        "",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_GENERAL
    },
    {
        "poison gas",
        {
            {GHSOUND_POISON_GAS_INSIDE, 1.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        },
        SOUNDSOURCE_AMBIENT_INSIDE_REGION
    }
};


NEARDATA struct effect_sound_definition ui_sounds[MAX_UI_SOUND_TYPES] =
{
    {
        "illegal",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "button-down",
        {GHSOUND_UI_BUTTON_DOWN, 1.0f}
    },
    {
        "menu-select",
        {GHSOUND_UI_MENU_SELECT, 1.0f}
    },
    {
        "",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "",
        {GHSOUND_NONE, 0.0f}
    }
};


NEARDATA struct effect_sound_definition sfx_sounds[MAX_SFX_SOUND_TYPES] =
{
    {
        "",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "read",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "quaff",
        {GHSOUND_SFX_QUAFF, 1.0f}
    },
    {
        "door open",
        {GHSOUND_DOOR_OPEN, 1.0f}
    },
    {
        "door close",
        {GHSOUND_DOOR_CLOSE, 1.0f}
    },
    {
        "door unlock",
        {GHSOUND_DOOR_UNLOCK, 1.0f}
    },
    {
        "door lock",
        {GHSOUND_DOOR_LOCK, 1.0f}
    },
    {
        "door resists",
        {GHSOUND_DOOR_RESISTS, 1.0f}
    },
    {
        "door try locked",
        {GHSOUND_DOOR_TRY_LOCKED, 1.0f}
    },
    {
        "",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "shield effect",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "talk effect",
        {GHSOUND_NONE, 0.0f}
    },
    {
        "push boulder",
        {GHSOUND_PUSH_BOULDER, 1.0f}
    },
    {
        "paralyzed",
        {GHSOUND_CAUSE_PARALYSIS, 1.0f}
    },
    {
        "sleeping",
        {GHSOUND_CAUSE_SLEEPING, 1.0f}
    },
};


struct ray_soundset_definition ray_soundsets[MAX_RAY_SOUNDSETS] =
{
    {
        "ray of magic missiles",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of fire",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of frost",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of sleep",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of disintegration",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of electricity",
        {
            {GHSOUND_RAY_ELEC_AMBIENT, 1.0f},
            {GHSOUND_RAY_ELEC_CREATE, 100.0f},
            {GHSOUND_RAY_ELEC_DESTROY, 10.0f},
            {GHSOUND_RAY_ELEC_BOUNCE, 100.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of poison gas",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of acid",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of death",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "ray of petrification",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of magic missiles",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of fire",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of frost",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of sleep",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of disintegration",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of electricity",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of poison gas",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of acid",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of death",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "explosion of petrification",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "no object ray soundset",
        {
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
    {
        "generic object ray soundset",
        {
            {GHSOUND_RAY_ELEC_AMBIENT, 1.0f},
            {GHSOUND_RAY_ELEC_CREATE, 100.0f},
            {GHSOUND_RAY_ELEC_DESTROY, 10.0f},
            {GHSOUND_RAY_ELEC_BOUNCE, 100.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f},
            {GHSOUND_NONE, 0.0f}
        }
    },
};



void
update_game_music()
{
    struct ghsound_music_info musicinfo = { 0 };
    musicinfo.volume = 1.0f;
    musicinfo.ghsound = GHSOUND_NONE;

    if (context.game_started == FALSE)
    {
        musicinfo.ghsound = GHSOUND_MUSIC_INTRO;
    }
    else if (program_state.gameover == 1)
    {
        musicinfo.ghsound = GHSOUND_MUSIC_GAMEOVER;
    }
    else
    {
        struct mkroom* room_ptr = which_room(u.ux, u.uy);
        if (!room_ptr)
            musicinfo.ghsound = get_level_music(&u.uz);
        else
            musicinfo.ghsound = get_room_music(room_ptr);
    }

    /* play_ghsound_music will check if the music is currently playing and then do nothing if this is the case */
    /* GHSOUND_NONE will stop music */
    play_ghsound_music(musicinfo);
}

void
stop_music()
{
    struct ghsound_music_info musicinfo = { 0 };
    musicinfo.ghsound = GHSOUND_NONE;
    musicinfo.volume = 0.0f;
    musicinfo.stop_music = TRUE;

    play_ghsound_music(musicinfo);
}

void
play_level_ambient_sounds()
{
    struct ghsound_level_ambient_info lainfo = { 0 };
    lainfo.volume = 1.0f;
    lainfo.ghsound = GHSOUND_NONE;

    if (context.game_started == FALSE || program_state.gameover == 1)
    {
        lainfo.ghsound = GHSOUND_NONE;
    }
    else
    {
        struct mkroom* room_ptr = which_room(u.ux, u.uy);
        if (!room_ptr)
            lainfo.ghsound = get_level_ambient_sounds(&u.uz);
        else
            lainfo.ghsound = get_room_ambient_sounds(room_ptr);
    }

    /* play_ghsound_level_ambient will check if the ambient sound is currently playing and then do nothing if this is the case */
    /* GHSOUND_NONE will stop ambient sounds */
    play_ghsound_level_ambient(lainfo);
}

enum floor_surface_types
get_floor_surface_type(x, y)
int x, y;
{
    if (!isok(x, y))
        return FLOOR_SURFACE_NONE;

    struct rm* lev = &levl[x][y];

    enum floor_surface_types floorid = FLOOR_SURFACE_NONE;
    int ftyp = IS_FLOOR(lev->typ) ? lev->typ : lev->floortyp;
    int fsubtyp = IS_FLOOR(lev->typ) ? lev->subtyp : lev->floorsubtyp;

    enum obj_material_types floor_material = get_location_type_material(ftyp, fsubtyp);
    floorid = material_definitions[floor_material].floor_surface_mapping;

    return floorid;
}

void
play_movement_sound(mtmp, climbingid)
struct monst* mtmp;
enum climbing_types climbingid;
{
	if (!mtmp)
		return;
	boolean isyou = (mtmp == &youmonst);
    boolean isfemale = isyou ? (Upolyd ? u.mfemale : flags.female) : mtmp->female;

    struct ghsound_immediate_info immediateinfo = { 0 };

    /* Parameters */
	enum floor_surface_types floorid = get_floor_surface_type(isyou ? u.ux : mtmp->mx, isyou ? u.uy : mtmp->my); /* Set the appropriate floor here */
    enum floor_treading_types treadingid = FLOOR_TREADING_TYPE_NORMAL;
    enum location_passing_types passingid = LOCATION_PASSING_TYPE_NORMAL;

	enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f, base_volume = isyou || mtmp == u.usteed ? 1.0f : 0.25f;
    float weight = max(0.0f, min(10000.0f, (float)mtmp->data->cwt));

    enum monster_soundset_types mss = isfemale ? mtmp->data->female_soundset : mtmp->data->soundset;
    enum object_soundset_types oss = monster_soundsets[mss].attack_soundsets[BAREFOOTED_ATTACK_NUMBER];
    enum object_sound_types sound_type = OBJECT_SOUND_TYPE_WALK;

    if (isyou)
	{ 
        if (!isok(u.ux, u.uy))
            return;

        if (Wwalking && floorid == FLOOR_SURFACE_LIQUID)
            passingid = LOCATION_PASSING_TYPE_WATERWALKING;
        else if (!Swimming && floorid == FLOOR_SURFACE_LIQUID)
            passingid = LOCATION_PASSING_TYPE_SUBMERGED;
        else if (Passes_walls && IS_ROCK(levl[u.ux][u.uy].typ))
            passingid = LOCATION_PASSING_TYPE_THROUGH_SOLID_WALLS;

        treadingid = Stealth ? FLOOR_TREADING_TYPE_STEALTH : FLOOR_TREADING_TYPE_NORMAL;

        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;

        if (is_flyer(mtmp->data) || Flying)
        {
            sound_type = OBJECT_SOUND_TYPE_FLY;
            struct obj* otmp = what_gives(FLYING);
            if (otmp)
            {
                enum object_soundset_types oss2 = objects[otmp->otyp].oc_soundset;
                soundid = object_soundsets[oss2].sounds[sound_type].ghsound;
                volume = object_soundsets[oss2].sounds[sound_type].volume;
            }
            else
            {
                soundid = object_soundsets[oss].sounds[sound_type].ghsound;
                volume = object_soundsets[oss].sounds[sound_type].volume;
            }
        }
        else if (is_floater(mtmp->data) || Levitation)
        {
            sound_type = OBJECT_SOUND_TYPE_LEVITATION;
            struct obj* otmp = what_gives(LEVITATION);
            if (otmp)
            {
                enum object_soundset_types oss2 = objects[otmp->otyp].oc_soundset;
                soundid = object_soundsets[oss2].sounds[sound_type].ghsound;
                volume = object_soundsets[oss2].sounds[sound_type].volume;
            }
            else
            {
                soundid = object_soundsets[oss].sounds[sound_type].ghsound;
                volume = object_soundsets[oss].sounds[sound_type].volume;
            }
        }
        else if ((is_swimmer(mtmp->data) || amphibious(mtmp->data) || Swimming) && floorid == FLOOR_SURFACE_LIQUID)
        {
            sound_type = OBJECT_SOUND_TYPE_SWIM;
            struct obj* otmp = what_gives(SWIMMING);
            if (otmp)
            {
                enum object_soundset_types oss2 = objects[otmp->otyp].oc_soundset;
                soundid = object_soundsets[oss2].sounds[sound_type].ghsound;
                volume = object_soundsets[oss2].sounds[sound_type].volume;
            }
            else
            {
                soundid = object_soundsets[oss].sounds[sound_type].ghsound;
                volume = object_soundsets[oss].sounds[sound_type].volume;
            }
        }
        else if (uarmf)
        {
            enum object_soundset_types oss_boots = objects[uarmf->otyp].oc_soundset;
            soundid = object_soundsets[oss_boots].sounds[sound_type].ghsound;
            volume = object_soundsets[oss_boots].sounds[sound_type].volume;
        }
	}
	else
	{
        if (!isok(mtmp->mx, mtmp->my))
            return;

        if (mtmp->mprops[WATER_WALKING] != 0 && floorid == FLOOR_SURFACE_LIQUID)
            passingid = LOCATION_PASSING_TYPE_WATERWALKING;
        else if (mtmp->mprops[SWIMMING] == 0 && floorid == FLOOR_SURFACE_LIQUID)
            passingid = LOCATION_PASSING_TYPE_SUBMERGED;
        else if (mtmp->mprops[PASSES_WALLS] != 0 && IS_ROCK(levl[mtmp->mx][mtmp->my].typ))
            passingid = LOCATION_PASSING_TYPE_THROUGH_SOLID_WALLS;

        treadingid = mtmp->mprops[STEALTH] != 0 ? FLOOR_TREADING_TYPE_STEALTH : FLOOR_TREADING_TYPE_NORMAL;

        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;

        if (is_flyer(mtmp->data) || mtmp->mprops[FLYING] != 0)
        {
            sound_type = OBJECT_SOUND_TYPE_FLY;
            struct obj* otmp = what_gives_monster(mtmp, FLYING);
            if (otmp)
            {
                enum object_soundset_types oss2 = objects[otmp->otyp].oc_soundset;
                soundid = object_soundsets[oss2].sounds[sound_type].ghsound;
                volume = object_soundsets[oss2].sounds[sound_type].volume;
            }
            else
            {
                soundid = object_soundsets[oss].sounds[sound_type].ghsound;
                volume = object_soundsets[oss].sounds[sound_type].volume;
            }
        }
        else if (is_flyer(mtmp->data) || mtmp->mprops[LEVITATION] != 0)
        {
            sound_type = OBJECT_SOUND_TYPE_LEVITATION;
            struct obj* otmp = what_gives_monster(mtmp, LEVITATION);
            if (otmp)
            {
                enum object_soundset_types oss2 = objects[otmp->otyp].oc_soundset;
                soundid = object_soundsets[oss2].sounds[sound_type].ghsound;
                volume = object_soundsets[oss2].sounds[sound_type].volume;
            }
            else
            {
                soundid = object_soundsets[oss].sounds[sound_type].ghsound;
                volume = object_soundsets[oss].sounds[sound_type].volume;
            }
        }
        else if ((is_swimmer(mtmp->data) || amphibious(mtmp->data) || mtmp->mprops[SWIMMING] != 0) && floorid == FLOOR_SURFACE_LIQUID)
        {
            sound_type = OBJECT_SOUND_TYPE_SWIM;
            struct obj* otmp = what_gives_monster(mtmp, SWIMMING);
            if (otmp)
            {
                enum object_soundset_types oss2 = objects[otmp->otyp].oc_soundset;
                soundid = object_soundsets[oss2].sounds[sound_type].ghsound;
                volume = object_soundsets[oss2].sounds[sound_type].volume;
            }
            else
            {
                soundid = object_soundsets[oss].sounds[sound_type].ghsound;
                volume = object_soundsets[oss].sounds[sound_type].volume;
            }
        }
        else if (mtmp->worn_item_flags & W_ARMF)
        {
            struct obj* omtp_boots = which_armor(mtmp, W_ARMF);
            if (omtp_boots)
            {
                enum object_soundset_types oss_boots = objects[omtp_boots->otyp].oc_soundset;
                soundid = object_soundsets[oss_boots].sounds[sound_type].ghsound;
                volume = object_soundsets[oss_boots].sounds[sound_type].volume;
            }
        }
        
        float hearing = hearing_array[mtmp->mx][mtmp->my];
        if (hearing == 0.0f)
            return;
        else
            volume *= hearing_array[mtmp->mx][mtmp->my];
	}

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = base_volume * volume;
    immediateinfo.parameter_names[0] = "FloorSurface";
    immediateinfo.parameter_values[0] = (float)floorid;
    immediateinfo.parameter_names[1] = "Weight";
    immediateinfo.parameter_values[1] = weight;
    immediateinfo.parameter_names[2] = "TreadingType";
    immediateinfo.parameter_values[2] = (float)treadingid;
    immediateinfo.parameter_names[3] = "ClimbingType";
    immediateinfo.parameter_values[3] = (float)climbingid;
    immediateinfo.parameter_names[4] = "PassingType";
    immediateinfo.parameter_values[4] = (float)passingid;
    immediateinfo.parameter_names[5] = (char*)0;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if(soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);
}

void
play_simple_object_sound(obj, sound_type)
struct obj* obj;
enum object_sound_types sound_type;
{
    /* Do not use for hit sounds */

    if (!obj)
        return;

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;
    struct ghsound_immediate_info immediateinfo = { 0 };

    if (obj->oartifact && artilist[obj->oartifact].soundset > OBJECT_SOUNDSET_NONE)
    {
        enum object_soundset_types oss = artilist[obj->oartifact].soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }
    else
    {
        enum object_soundset_types oss = objects[obj->otyp].oc_soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }

    xchar x = 0, y = 0;
    get_obj_location(obj, &x, &y, 0);

    if (isok(x, y))
    {
        float hearing = hearing_array[x][y];
        if (hearing == 0.0f)
            return;
        else
            volume *= hearing_array[x][y];
    }
    else
        return;

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);

}

void
play_object_floor_sound(obj, sound_type)
struct obj* obj;
enum object_sound_types sound_type;
{
    if (!obj || !isok(obj->ox, obj->oy))
        return;

    struct ghsound_immediate_info immediateinfo = { 0 };
    enum floor_surface_types floorid = get_floor_surface_type(obj->ox, obj->oy);
    float weight = (float)obj->owt;
    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;

    if (obj->oartifact && artilist[obj->oartifact].soundset > OBJECT_SOUNDSET_NONE)
    {
        enum object_soundset_types oss = artilist[obj->oartifact].soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }
    else
    {
        enum object_soundset_types oss = objects[obj->otyp].oc_soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }

    float hearing = hearing_array[obj->ox][obj->oy];
    if (hearing == 0.0f)
        return;
    else
        volume *= hearing_array[obj->ox][obj->oy];

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.parameter_names[0] = "FloorSurface";
    immediateinfo.parameter_values[0] = (float)floorid;
    immediateinfo.parameter_names[1] = "Weight";
    immediateinfo.parameter_values[1] = weight;
    immediateinfo.parameter_names[2] = (char*)0;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);
}

void
play_object_container_in_sound(obj, container)
struct obj* obj;
struct obj* container;
{
    if (!obj || !container)
        return;

    enum object_sound_types sound_type = OBJECT_SOUND_TYPE_DROP;
    struct ghsound_immediate_info immediateinfo = { 0 };

    enum obj_material_types container_material = objects[container->otyp].oc_material;
    enum floor_surface_types floorid = material_definitions[container_material].floor_surface_mapping;
    float weight = (float)obj->owt;
    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;

    if (obj->oartifact && artilist[obj->oartifact].soundset > OBJECT_SOUNDSET_NONE)
    {
        enum object_soundset_types oss = artilist[obj->oartifact].soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }
    else
    {
        enum object_soundset_types oss = objects[obj->otyp].oc_soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.parameter_names[0] = "FloorSurface";
    immediateinfo.parameter_values[0] = (float)floorid;
    immediateinfo.parameter_names[1] = "Weight";
    immediateinfo.parameter_values[1] = weight;
    immediateinfo.parameter_names[2] = (char*)0;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);
}

void
play_simple_location_sound(x, y, sound_type)
xchar x, y;
enum location_sound_types sound_type;
{
    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;
    struct ghsound_immediate_info immediateinfo = { 0 };

    if (!isok(x, y))
        return;

    enum location_soundset_types lss = location_type_definitions[levl[x][y].typ].soundset;
    soundid = location_soundsets[lss].sounds[sound_type].ghsound;
    volume = location_soundsets[lss].sounds[sound_type].volume;

    /* Move one square towards the player, since the square itself may be rock etc. */
    xchar hear_x = x + sgn(u.ux - x);
    xchar hear_y = y + sgn(u.uy - y);
    
    if (!isok(hear_x, hear_y))
        hear_x = x, hear_y = y;

    float hearing = hearing_array[hear_x][hear_y];
    if (hearing == 0.0f)
        return;
    else
        volume *= hearing_array[hear_x][hear_y];

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);

}

void
play_simple_player_sound(sound_type)
enum player_sound_types sound_type;
{
    /* Do not use for hit sounds */

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;
    struct ghsound_immediate_info immediateinfo = { 0 };

    enum player_soundset_types pss = get_player_soundset();
    soundid = player_soundsets[pss].sounds[sound_type].ghsound;
    volume = player_soundsets[pss].sounds[sound_type].volume;

    xchar x = u.ux, y = u.uy;

    if (isok(x, y))
    {
        float hearing = hearing_array[x][y];
        if (hearing == 0.0f)
            return;
        else
            volume *= hearing_array[x][y];
    }
    else
        return;

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);

}

void
play_simple_monster_sound(mon, sound_type)
struct monst* mon;
enum monster_sound_types sound_type;
{
    /* Do not use for hit sounds */

    if (!mon)
        return;

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;
    struct ghsound_immediate_info immediateinfo = { 0 };

    enum monster_soundset_types mss = mon->female ? mon->data->female_soundset : mon->data->soundset;
    soundid = monster_soundsets[mss].sounds[sound_type].ghsound;
    volume = monster_soundsets[mss].sounds[sound_type].volume;

    xchar x = mon->mx, y = mon->my;

    if (isok(x, y))
    {
        float hearing = hearing_array[x][y];
        if (hearing == 0.0f)
            return;
        else
            volume *= hearing_array[x][y];
    }
    else
        return;

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);

}

void
play_monster_simple_weapon_sound(magr, attack_number, weapon, sound_type)
struct monst* magr;
int attack_number;
struct obj* weapon;
enum object_sound_types sound_type;
{
    /* Do not use for hit sounds */

    if (!magr)
        return;

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;
    boolean you_attack = (magr == &youmonst);
    struct ghsound_immediate_info immediateinfo = { 0 };

    if (weapon)
    {
        if (weapon->oartifact && artilist[weapon->oartifact].soundset > OBJECT_SOUNDSET_NONE)
        {
            enum object_soundset_types oss = artilist[weapon->oartifact].soundset;
            soundid = object_soundsets[oss].sounds[sound_type].ghsound;
            volume = object_soundsets[oss].sounds[sound_type].volume;
        }
        else
        {
            enum object_soundset_types oss = objects[weapon->otyp].oc_soundset;
            soundid = object_soundsets[oss].sounds[sound_type].ghsound;
            volume = object_soundsets[oss].sounds[sound_type].volume;
        }
    }
    else
    {
        if (you_attack)
        {
            enum player_soundset_types pss = get_player_soundset();
            enum object_soundset_types oss = player_soundsets[pss].attack_soundsets[PLAYER_ATTACK_SOUNDSET_BAREHANDED];
            soundid = object_soundsets[oss].sounds[sound_type].ghsound;
            volume = object_soundsets[oss].sounds[sound_type].volume;
        }
        else
        {
            enum monster_soundset_types mss = magr->female ? magr->data->female_soundset : magr->data->soundset;
            enum object_soundset_types oss = monster_soundsets[mss].attack_soundsets[attack_number];
            soundid = object_soundsets[oss].sounds[sound_type].ghsound;
            volume = object_soundsets[oss].sounds[sound_type].volume;
            if (isok(magr->mx, magr->my))
            {
                float hearing = hearing_array[magr->mx][magr->my];
                if (hearing == 0.0f)
                    return;
                else
                    volume *= hearing_array[magr->mx][magr->my];
            }
        }
    }

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if(soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);

}

void
get_hit_location(surface_type, surface_source_ptr, defx_ptr, defy_ptr)
enum hit_surface_source_types surface_type;
anything* surface_source_ptr;
xchar *defx_ptr, *defy_ptr;
{
    if (!surface_source_ptr || !defx_ptr || !defy_ptr)
        return;

    boolean you_defend = FALSE;
    anything surface_source = *surface_source_ptr;

    struct monst* mdef = 0;
    struct obj* obj = 0;
    coord cc = { 0 };

    *defx_ptr = 0;
    *defy_ptr = 0;

    if (surface_type == HIT_SURFACE_SOURCE_MONSTER)
    {
        mdef = surface_source.a_monst;
        if (!mdef)
            return;

        you_defend = (mdef == &youmonst);

        if (you_defend)
        {
            *defx_ptr = u.ux;
            *defy_ptr = u.uy;
        }
        else
        {
            *defx_ptr = mdef->mx;
            *defy_ptr = mdef->my;
        }
    }
    else if (surface_type == HIT_SURFACE_SOURCE_OBJECT)
    {
        obj = surface_source.a_obj;
        if (!obj)
            return;
        get_obj_location(obj, defx_ptr, defy_ptr, 0);
    }
    else if (surface_type == HIT_SURFACE_SOURCE_LOCATION)
    {
        cc.x = surface_source.a_coord.x;
        cc.y = surface_source.a_coord.y;
        if (!isok(cc.x, cc.y))
            return;

        /* Move one square closer to the player */
        xchar hear_x = cc.x + sgn(u.ux - cc.x);
        xchar hear_y = cc.y + sgn(u.uy - cc.y);

        if(isok(hear_x, hear_y))
        { 
            *defx_ptr = hear_x;
            *defy_ptr = hear_y;
        }
        else
        {
            *defx_ptr = cc.x;
            *defy_ptr = cc.y;
        }
    }
    else if (surface_type == HIT_SURFACE_SOURCE_TRAP)
    {
        struct trap* t = surface_source.a_trap;
        if (!t)
            return;
        *defx_ptr = t->tx;
        *defy_ptr = t->ty;
    }

}



enum hit_surface_types
get_hit_surface_type(surface_type, surface_source_ptr)
enum hit_surface_source_types surface_type;
anything* surface_source_ptr;
{
    enum hit_surface_types surfaceid = HIT_SURFACE_NONE;
    enum obj_mat_types surface_material = MAT_NONE;
    if (!surface_source_ptr)
        return surfaceid;

    anything surface_source = *surface_source_ptr;

    if (surface_type == HIT_SURFACE_SOURCE_MONSTER)
    {
        struct monst* mdef = surface_source.a_monst;
        if (!mdef)
            return surfaceid;

        boolean you_defend = (mdef == &youmonst);

        surface_material = mdef->data->natural_armor_material_type;
        if (you_defend)
        {
            /* Maybe change if you are wearing armor */
        }
        else if (mdef)
        {
            /* Maybe change if monster is wearing armor */
        }
    }
    else if (surface_type == HIT_SURFACE_SOURCE_OBJECT)
    {
        struct obj* obj = surface_source.a_obj;
        if (!obj)
            return surfaceid;
        surface_material = objects[obj->otyp].oc_material;
    }
    else if (surface_type == HIT_SURFACE_SOURCE_LOCATION)
    {
        coord cc = { 0 };
        cc.x = surface_source.a_coord.x;
        cc.y = surface_source.a_coord.y;
        if (!isok(cc.x, cc.y))
            return surfaceid;
        surface_material = location_type_definitions[levl[cc.x][cc.y].typ].material;
    }
    else if (surface_type == HIT_SURFACE_SOURCE_TRAP)
    {
        struct trap* t = surface_source.a_trap;
        if (!t)
            return surfaceid;
        surface_material = trap_type_definitions[t->ttyp].material;
    }

    surfaceid = material_definitions[surface_material].hit_surface_mapping;

    return surfaceid;
}

void
play_monster_weapon_hit_sound(magr, surface_type, surface_source_ptr, attack_number, weapon, damage, thrown)
struct monst* magr;
enum hit_surface_source_types surface_type;
anything* surface_source_ptr;
int attack_number; /* attack_number == NATTK indicates kicking */
struct obj* weapon;
double damage;
enum hmon_atkmode_types thrown;
{
    if (!magr || !surface_source_ptr)
        return;

    boolean you_attack = (magr == &youmonst);
    boolean isfemale = you_attack ? (Upolyd ? u.mfemale : flags.female) : magr->female;

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;
    enum object_sound_types sound_type = (thrown == HMON_MELEE ? OBJECT_SOUND_TYPE_HIT_MELEE : OBJECT_SOUND_TYPE_HIT_THROW);
    struct ghsound_immediate_info immediateinfo = { 0 };

    xchar defx = 0, defy = 0;
    get_hit_location(surface_type, surface_source_ptr, &defx, &defy);
    if (!isok(defx, defy))
        return;

    if (weapon)
    {
        if (weapon->oartifact && artilist[weapon->oartifact].soundset > OBJECT_SOUNDSET_NONE)
        {
            enum object_soundset_types oss = artilist[weapon->oartifact].soundset;
            soundid = object_soundsets[oss].sounds[sound_type].ghsound;
            volume = object_soundsets[oss].sounds[sound_type].volume;
        }
        else
        {
            enum object_soundset_types oss = objects[weapon->otyp].oc_soundset;
            soundid = object_soundsets[oss].sounds[sound_type].ghsound;
            volume = object_soundsets[oss].sounds[sound_type].volume;
        }
    }
    else
    {
        enum monster_soundset_types mss = isfemale ? magr->data->female_soundset : magr->data->soundset;
        enum object_soundset_types oss = monster_soundsets[mss].attack_soundsets[attack_number];
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
        /* Hit sound is based on the defender's location */
        if (isok(defx, defy))
        {
            float hearing = hearing_array[defx][defy];
            if (hearing == 0.0f)
                return;
            else
                volume *= hearing_array[defx][defy];
        }
    }

    enum hit_surface_types surfaceid = get_hit_surface_type(surface_type, surface_source_ptr);

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.parameter_names[0] = "HitSurface";
    immediateinfo.parameter_values[0] = (float)surfaceid;
    immediateinfo.parameter_names[1] = "Damage";
    immediateinfo.parameter_values[1] = (float)damage;
    immediateinfo.parameter_names[2] = (char*)0;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);

}


void
play_object_hit_sound(obj, surface_type, surface_source_ptr, damage, thrown)
struct obj* obj;
enum hit_surface_source_types surface_type;
anything* surface_source_ptr;
double damage;
enum hmon_atkmode_types thrown;
{
    if (!surface_source_ptr || !obj)
        return;

    struct monst* mdef = 0;
    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;
    enum object_sound_types sound_type = (thrown == HMON_MELEE ? OBJECT_SOUND_TYPE_HIT_MELEE : OBJECT_SOUND_TYPE_HIT_THROW);
    struct ghsound_immediate_info immediateinfo = { 0 };

    xchar defx = 0, defy = 0;
    get_hit_location(surface_type, surface_source_ptr, &defx, &defy);
    if (!isok(defx, defy))
        return;

    if (obj->oartifact && artilist[obj->oartifact].soundset > OBJECT_SOUNDSET_NONE)
    {
        enum object_soundset_types oss = artilist[obj->oartifact].soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }
    else
    {
        enum object_soundset_types oss = objects[obj->otyp].oc_soundset;
        soundid = object_soundsets[oss].sounds[sound_type].ghsound;
        volume = object_soundsets[oss].sounds[sound_type].volume;
    }

    xchar x = defx, y = defy;
    if (isok(x, y))
    {
        float hearing = hearing_array[x][y];
        if (hearing == 0.0f)
            return;
        else
            volume *= hearing_array[x][y];
    }
    else
        return;


    enum hit_surface_types surfaceid = get_hit_surface_type(surface_type, surface_source_ptr);

    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.parameter_names[0] = "HitSurface";
    immediateinfo.parameter_values[0] = (float)surfaceid;
    immediateinfo.parameter_names[1] = "Damage";
    immediateinfo.parameter_values[1] = (float)damage;
    immediateinfo.parameter_names[2] = (char*)0;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);

}

void
play_sfx_sound(sfx_sound_id)
enum effect_sounds_types sfx_sound_id;
{

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;

    soundid = sfx_sounds[sfx_sound_id].sound.ghsound;
    volume = min(1.0f, sfx_sounds[sfx_sound_id].sound.volume);

    struct ghsound_immediate_info immediateinfo = { 0 };
    immediateinfo.ghsound = soundid;
    immediateinfo.volume = volume;
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);
}

void
play_ui_sound(ui_sound_id)
enum ui_sounds_types ui_sound_id;
{

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;

    soundid = ui_sounds[ui_sound_id].sound.ghsound;
    volume = ui_sounds[ui_sound_id].sound.volume;

    struct ghsound_immediate_info immediateinfo = { 0 };
    immediateinfo.ghsound = soundid;
    immediateinfo.volume = min(1.0f, volume);
    immediateinfo.sound_type = IMMEDIATE_SOUND_UI;

    if (soundid > GHSOUND_NONE && volume > 0.0f)
        play_immediate_ghsound(immediateinfo);
}


void
play_sfx_sound_at_location(sfx_sound_id, x, y)
enum sfx_sounds_types sfx_sound_id;
int x, y;
{
    if (!isok(x, y) || hearing_array[x][y] == 0.0f)
        return;

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;

    soundid = sfx_sounds[sfx_sound_id].sound.ghsound;
    volume = sfx_sounds[sfx_sound_id].sound.volume;

    struct ghsound_immediate_info immediateinfo = { 0 };
    immediateinfo.ghsound = soundid;
    immediateinfo.volume = min(1.0f, volume * hearing_array[x][y]);
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (immediateinfo.ghsound > GHSOUND_NONE && immediateinfo.volume > 0.0f)
        play_immediate_ghsound(immediateinfo);
}

void
play_immediate_ray_sound_at_location(ray_soundset_id, ray_sound_type, x, y)
enum ray_soundset_types ray_soundset_id; 
enum ray_sounds_types ray_sound_type;
int x, y;
{
    if (!isok(x, y) || hearing_array[x][y] == 0.0f)
        return;
    enum ray_soundset_types typ = ray_soundset_id;
    if (ray_soundsets[typ].sounds[ray_sound_type].ghsound == GHSOUND_NONE)
        return;

    enum ghsound_types soundid = GHSOUND_NONE;
    float volume = 1.0f;

    soundid = ray_soundsets[typ].sounds[ray_sound_type].ghsound;
    volume = ray_soundsets[typ].sounds[ray_sound_type].volume;

    struct ghsound_immediate_info immediateinfo = { 0 };
    immediateinfo.ghsound = soundid;
    immediateinfo.volume = min(1.0f, volume * hearing_array[x][y]);
    immediateinfo.sound_type = IMMEDIATE_SOUND_SFX;

    if (immediateinfo.ghsound > GHSOUND_NONE && immediateinfo.volume > 0.0f)
        play_immediate_ghsound(immediateinfo);
}

void
start_ambient_ray_sound_at_location(ray_type, x, y)
int ray_type; /* 0...NRAYS normal ray, NRAYS...2NRAYS-1 explosion effect */
int x, y;
{
    int typ = ray_type;
    if (ray_soundsets[typ].sounds[RAY_SOUND_TYPE_AMBIENT].ghsound == GHSOUND_NONE)
        return;

    float hearing_volume = 0.0f;
    if (isok(x, y))
        hearing_volume = hearing_array[x][y];

    struct ghsound_effect_ambient_info info = { 0 };
    info.ghsound = ray_soundsets[typ].sounds[RAY_SOUND_TYPE_AMBIENT].ghsound;
    info.volume = min(1.0f, ray_soundsets[typ].sounds[RAY_SOUND_TYPE_AMBIENT].volume * hearing_volume);

    play_ghsound_effect_ambient(info);
}

void
update_ambient_ray_sound_to_location(ray_type, x, y)
int ray_type; /* 0...NRAYS normal ray, NRAYS...2NRAYS-1 explosion effect */
int x, y;
{
    int typ = ray_type;
    if (ray_soundsets[typ].sounds[RAY_SOUND_TYPE_AMBIENT].ghsound == GHSOUND_NONE)
        return;

    float hearing_volume = 0.0f;
    if (isok(x, y))
        hearing_volume = hearing_array[x][y];

    struct effect_ambient_volume_info vinfo = { 0 };
    vinfo.volume = min(1.0f, ray_soundsets[typ].sounds[RAY_SOUND_TYPE_AMBIENT].volume * hearing_volume);

    set_effect_ambient_volume(vinfo);
}

void
stop_ambient_ray_sound(ray_type)
int ray_type; /* 0...NRAYS normal ray, NRAYS...2NRAYS-1 explosion effect */
{
    int typ = ray_type;

    if (ray_soundsets[typ].sounds[RAY_SOUND_TYPE_AMBIENT].ghsound == GHSOUND_NONE)
        return;

    struct effect_ambient_volume_info vinfo = { 0 };
    vinfo.volume = 0.0f;

    set_effect_ambient_volume(vinfo);
}


void
start_occupation_ambient_sound(object_soundset_id, occupation_type)
enum object_soundset_types object_soundset_id;
enum occupation_types occupation_type;
{
    if (occupation_soundset_definitions[object_soundsets[object_soundset_id].occupation_soundsets[occupation_type]].sounds[OCCUPATION_SOUND_TYPE_AMBIENT].ghsound == GHSOUND_NONE)
        return;

    struct ghsound_occupation_ambient_info info = { 0 };
    info.ghsound = occupation_soundset_definitions[object_soundsets[object_soundset_id].occupation_soundsets[occupation_type]].sounds[OCCUPATION_SOUND_TYPE_AMBIENT].ghsound;
    info.volume = min(1.0f, occupation_soundset_definitions[object_soundsets[object_soundset_id].occupation_soundsets[occupation_type]].sounds[OCCUPATION_SOUND_TYPE_AMBIENT].volume);

    play_ghsound_occupation_ambient(info);
}

void
stop_occupation_ambient_sound(object_soundset_id, occupation_type)
enum object_soundset_types object_soundset_id;
enum occupation_types occupation_type;
{
    if (occupation_soundset_definitions[object_soundsets[object_soundset_id].occupation_soundsets[occupation_type]].sounds[OCCUPATION_SOUND_TYPE_AMBIENT].ghsound == GHSOUND_NONE)
        return;

    struct ghsound_occupation_ambient_info info = { 0 };
    info.volume = 0.0f;

    play_ghsound_occupation_ambient(info);

}

void
play_occupation_immediate_sound(object_soundset_id, occupation_type, sound_type)
enum object_soundset_types object_soundset_id;
enum occupation_types occupation_type;
enum occupation_sound_types sound_type;
{

    if (occupation_soundset_definitions[object_soundsets[object_soundset_id].occupation_soundsets[occupation_type]].sounds[sound_type].ghsound == GHSOUND_NONE)
        return;

    struct ghsound_immediate_info info = { 0 };
    info.ghsound = occupation_soundset_definitions[object_soundsets[object_soundset_id].occupation_soundsets[occupation_type]].sounds[sound_type].ghsound;
    info.volume = min(1.0f, occupation_soundset_definitions[object_soundsets[object_soundset_id].occupation_soundsets[occupation_type]].sounds[sound_type].volume);

    play_immediate_ghsound(info);
}

enum player_soundset_types
get_player_soundset()
{
	return PLAYER_SOUNDSET_GENERAL;
}

void
dosetsoundvolume()
{
	adjust_ghsound_general_volumes();
}

void
update_hearing_array(mode)
int mode; /* 0 = normal, 1 = clear */
{
	/* Clear array*/
	memset(hearing_array, 0, sizeof(hearing_array));

	/* Can't hear anything */
	if (Deaf || mode == 1)
		return;

	int hear_distance = get_max_hearing_distance();

	/* Fill the array */
	hearing_array[u.ux][u.uy] = 1.0f;

	for (int r = 1; r <= hear_distance; r++)
	{
		int x_min = u.ux - r;
		int x_max = u.ux + r;
		int x_min_adjusted = max(1, x_min);
		int x_max_adjusted = min(COLNO - 1, x_max);

		int y_min = u.uy - r;
		int y_max = u.uy + r;
		int y_min_adjusted = max(0, y_min);
		int y_max_adjusted = min(COLNO - 1, y_max);

		boolean horizontal_min_done = FALSE;
		boolean horizontal_max_done = FALSE;

		/* 1. Horizontal lines, left to right */
		for (int i = 0; i <= 1; i++)
		{
			if (i == 0)
			{
				if(y_min_adjusted != y_min)
					continue;

				horizontal_min_done = TRUE;
			}
			else if (i == 1)
			{
				if(y_max_adjusted != y_max)
					continue;

				horizontal_max_done = TRUE;
			}

			int y = (i == 0 ? y_min_adjusted : y_max_adjusted);

			
			for (int x = x_min_adjusted; x <= x_max_adjusted; x++)
			{
				float prev_hearing = 0.0f;
				int prev_y = (i == 0) ? y + 1 : y - 1;

				if (r == 1)
				{
					prev_hearing = 1.0f;
				}
				else if (prev_y > y_max_adjusted || prev_y < y_min_adjusted)
				{
					//Nothing
				}
				else
				{
					float maximum = 0.0f;

					/* Take maximum from above or below from the previous round */
					for (int prev_x = max(x_min_adjusted + 1, x - 1); prev_x <= min(x_max_adjusted - 1, x + 1); prev_x++)
					{
						maximum = max(maximum, hearing_array[prev_x][prev_y]);
					}
	
					/* Take also previous from the same line */
					if(x > x_min_adjusted)
						maximum = max(maximum, hearing_array[x - 1][y]);

					prev_hearing = maximum;
				}

				if (prev_hearing == 0.0f)
				{
					continue;
					/* Current hearing is 0, too */
				}
				else
				{
					set_hearing_array(x, y, prev_hearing, r);
				}
			}
		}

		/* Vertical lines, top to bottom */
		for (int i = 0; i <= 1; i++)
		{
			if (i == 0 && x_min_adjusted != x_min)
				continue;
			if (i == 1 && x_max_adjusted != x_max)
				continue;

			int x = (i == 0 ? x_min_adjusted : x_max_adjusted);
			int upper_y_limit = y_max_adjusted - (horizontal_max_done ? 1 : 0);

			for (int y = y_min_adjusted + (horizontal_min_done ? 1 : 0); y <= upper_y_limit; y++)
			{
				float prev_hearing = 0.0f;
				int prev_x = (i == 0) ? x + 1 : x - 1;

				if (r == 1)
				{
					prev_hearing = 1.0f;
				}
				else if (prev_x > x_max_adjusted || prev_x < x_min_adjusted)
				{
					//Nothing
				}
				else
				{
					float maximum = 0.0f;
					for (int prev_y = max(y_min_adjusted + 1, y - 1); prev_y <= min(y_max_adjusted - 1, y + 1); prev_y++)
					{
						maximum = max(maximum, hearing_array[prev_x][prev_y]);
					}

					/* Take also previous from the same line */
					if (y > y_min_adjusted)
						maximum = max(maximum, hearing_array[x][y - 1]);

					prev_hearing = maximum;
				}

				if (prev_hearing == 0.0f)
				{
					continue;
					/* Current hearing is 0, too */
				}
				else
				{
					set_hearing_array(x, y, prev_hearing, r);
				}
			}
		}

		/* Vertical lines, bottom to top */
		for (int i = 0; i <= 1; i++)
		{
			if (i == 0 && x_max_adjusted != x_max)
				continue;
			if (i == 1 && x_min_adjusted != x_min)
				continue;

			int x = (i == 0 ? x_max_adjusted : x_min_adjusted);

			for (int y = y_max_adjusted - 1 ; y >= y_min_adjusted; y--)
			{
				if(hearing_array[x][y + 1] > 0.0f)
					set_hearing_array(x, y, hearing_array[x][y + 1], r);
			}
		}

		/* Horizontal lines, right to left */
		for (int i = 0; i <= 1; i++)
		{
			if (i == 0 && y_max_adjusted != y_max)
				continue;
			if (i == 1 && y_min_adjusted != y_min)
				continue;

			int y = (i == 0 ? y_max_adjusted : y_min_adjusted);

			for (int x = x_max_adjusted - 1; x >= x_min_adjusted; x--)
			{
				if (hearing_array[x + 1][y] > 0.0f)
					set_hearing_array(x, y, hearing_array[x + 1][y], r);
			}
		}
	}

}

STATIC_OVL
void set_hearing_array(x, y, prev_hearing, radius)
int x, y;
double prev_hearing;
int radius;
{
    float multiplier = 1.0f;
    if (radius <= 0)
    {
        hearing_array[x][y] = 1.0f;
        return;
    }
    else if (radius == 1)
    {
        multiplier = 0.75f; /* Specially adjusted value */
    }
    else if (radius >= 2)
    {
        float prev_factor = 1.0f / ((float)(radius - 1) * (float)(radius - 1));
        float curr_factor = 1.0f / ((float)radius * (float)radius);
        multiplier = curr_factor / prev_factor;
    }

	struct monst* mtmp;
	if (IS_ROCK(levl[x][y].typ) && !IS_TREE(levl[x][y].typ))
	{
		/* Nothing */
	}
	else if ((mtmp = m_at(x, y)) && is_lightblocker_mappear(mtmp))
	{
		/* Nothing */
	}
	else if (IS_DOOR(levl[x][y].typ) && (levl[x][y].doormask != 0 && (levl[x][y].doormask & (D_NODOOR | D_ISOPEN | D_BROKEN)) == 0))
	{
		float new_hearing = (float)max(0.0f, min(1.0f, multiplier * ((float)prev_hearing) / (10.0f)));
		if(new_hearing > hearing_array[x][y])
			hearing_array[x][y] = new_hearing;
	}
	else
	{
		float new_hearing = (float)max(0.0f, min(1.0f, multiplier * (float)prev_hearing));
		if (new_hearing > hearing_array[x][y])
			hearing_array[x][y] = new_hearing;
	}

}

void
update_ambient_sounds()
{
    for (struct soundsource_t* curr = sound_base; curr; curr = curr->next)
    {
        if (!isok(curr->x, curr->y))
            continue;

        boolean lit = FALSE;
        boolean insidereg = FALSE;

        /* Update sound source location */
        if (curr->type == SOUNDSOURCE_OBJECT)
        {
            if (get_obj_location(curr->id.a_obj, &curr->x, &curr->y, 0))
                ;

            if (curr->id.a_obj)
                lit = curr->id.a_obj->lamplit;
        }
        else if (curr->type == SOUNDSOURCE_MONSTER)
        {
            if (get_mon_location(curr->id.a_monst, &curr->x, &curr->y, 0))
                ;

            if (curr->id.a_monst)
                lit = curr->id.a_monst->data->lightrange;
        }
        else if (curr->type == SOUNDSOURCE_LOCATION)
        {
            curr->x = curr->id.a_coord.x;
            curr->y = curr->id.a_coord.y;

            if (isok(curr->id.a_coord.x, curr->id.a_coord.y))
                lit = levl[curr->id.a_coord.x][curr->id.a_coord.y].lamplit;
        }
        else if (curr->type == SOUNDSOURCE_REGION)
        {
            if (get_region_location(curr->id.a_nhregion, &curr->x, &curr->y, 0))
                ;

            if (curr->id.a_nhregion)
            {
                lit = curr->id.a_nhregion->lamplit;
                insidereg = hero_inside(curr->id.a_nhregion);
            }
        }

        /* Update sound source heard volume */
        float old_heard_volume = curr->heard_volume;
        float hearing_volume = hearing_array[curr->x][curr->y];
        float total_volume = 0.0f;
        if (hearing_volume > 0.0f)
        {
            float source_volume = curr->source_volume;
            total_volume = source_volume * hearing_volume;
            if (curr->subtype == SOUNDSOURCE_AMBIENT_LIT && !lit)
                total_volume = 0.0f;
            else if (curr->subtype == SOUNDSOURCE_AMBIENT_INSIDE_REGION && !insidereg)
                total_volume = 0.0f;
        }

        if(total_volume < 0.001f)
            total_volume = 0.0f; /* turn off if too quiet */

        curr->heard_volume = total_volume;
        if(curr->heard_volume != old_heard_volume)
            set_ambient_ghsound_volume(curr);
    }
}

void
update_hearing_array_and_ambient_sounds()
{
	update_hearing_array(0);
	update_ambient_sounds();
}

void
clear_hearing_array_and_ambient_sounds()
{
    update_hearing_array(1);
    update_ambient_sounds();
}

int get_max_hearing_distance()
{
	return (u.uswallow ? 1 : Underwater ? 2 : MAX_HEARING_DISTANCE);
}

void
update_hearing_array_and_ambient_sounds_if_point_within_hearing_range(px, py)
int px, py;
{
	int max_hear_dist = get_max_hearing_distance();
	if (abs(u.ux - px) <= max_hear_dist && abs(u.uy - py) <= max_hear_dist)
		update_hearing_array_and_ambient_sounds();
}

void
unblock_vision_and_hearing_at_point(x, y)
int x, y;
{
	unblock_point(x, y);
	update_hearing_array_and_ambient_sounds_if_point_within_hearing_range(x, y);
}

void
block_vision_and_hearing_at_point(x, y)
int x, y;
{
	block_point(x, y);
	update_hearing_array_and_ambient_sounds_if_point_within_hearing_range(x, y);
}




/*
 * Ambient sound sources.
 *
 * This implementation minimizes memory at the expense of extra
 * recalculations.
 *
 * Sound sources are "things" that have a physical position and volume.
 * They have a type, which gives us information about them.  Currently
 * they are only attached to objects, monsters, and locations.  Note:  the
 * polymorphed-player handling assumes that both youmonst.m_id and
 * youmonst.mx will always remain 0.
 *
 * Sound sources, like timers, either follow game play (RANGE_GLOBAL) or
 * stay on a level (RANGE_LEVEL).  Sound sources are unique by their
 * (type, id) pair.  For sound sources attached to objects, this id
 * is a pointer to the object.
 *
 * The structure of the save/restore mechanism is amazingly similar to
 * the timer save/restore.  This is because they both have the same
 * principals of having pointers into objects that must be recalculated
 * across saves and restores.
 */

 /* flags */
#define SSF_SHOW 0x1        /* display the sound source */
#define SSF_NEEDS_FIXUP 0x2 /* need oid fixup */
#define SSF_SILENCE_SOURCE 0x4 /* emits silence rather than sound */

STATIC_DCL void FDECL(write_soundsource, (int, sound_source*));
STATIC_DCL int FDECL(maybe_write_soundsource, (int, int, BOOLEAN_P));


/* Create a new sound source.  */
void
new_sound_source(x, y, ghsound, volume, type, subtype, id)
xchar x, y;
enum ghsound_types ghsound;
double volume;
enum soundsource_types type;
enum soundsource_ambient_subtypes subtype;
anything* id;
{
    sound_source* ss;
    double absvolume = volume > 0.0 ? volume : -volume;
    if (absvolume > 1.0 || absvolume < 0.0) 
    {
        impossible("new_sound_source:  illegal volume %d", volume);
        return;
    }

    ss = (sound_source*)alloc(sizeof(sound_source));

    ss->next = sound_base;
    ss->x = x;
    ss->y = y;
    ss->ghsound = ghsound;
    ss->source_volume = ((float)absvolume);
    ss->heard_volume = ss->source_volume * hearing_array[x][y];
    ss->type = type;
    ss->subtype = subtype;
    ss->id = *id;
    ss->flags = volume < 0 ? SSF_SILENCE_SOURCE : 0;
    sound_base = ss;

    add_ambient_ghsound(ss);

    hearing_full_recalc = 1; /* make the source show up */
}

/*
 * Delete a sound source. This assumes only one sound source is attached
 * to an object at a time.
 */
void
del_sound_source(type, id)
int type;
anything* id;
{
    sound_source* curr, * prev;
    anything tmp_id;

    tmp_id = zeroany;
    /* need to be prepared for dealing a with sound source which
       has only been partially restored during a level change
       (in particular: chameleon vs prot. from shape changers) */
    switch (type)
    {
    case SOUNDSOURCE_OBJECT:
        tmp_id.a_uint = id->a_obj->o_id;
        break;
    case SOUNDSOURCE_MONSTER:
        tmp_id.a_uint = id->a_monst->m_id;
        break;
    case SOUNDSOURCE_LOCATION:
        tmp_id = zeroany;
        tmp_id.a_coord.x = id->a_coord.x;
        tmp_id.a_coord.y = id->a_coord.y;
        break;
    case SOUNDSOURCE_REGION:
        tmp_id.a_uint = get_rid(id->a_nhregion);
        break;
    default:
        tmp_id.a_uint = 0;
        break;
    }

    for (prev = 0, curr = sound_base; curr; prev = curr, curr = curr->next)
    {
        if (curr->type != type)
            continue;

        if ((type == SOUNDSOURCE_LOCATION && curr->id.a_coord.x == tmp_id.a_coord.x && curr->id.a_coord.y == tmp_id.a_coord.y)
            || (type != SOUNDSOURCE_LOCATION && curr->id.a_obj == ((curr->flags & SSF_NEEDS_FIXUP) ? tmp_id.a_obj : id->a_obj))
            )
        {
            if (prev)
                prev->next = curr->next;
            else
                sound_base = curr->next;

            if (delete_ambient_ghsound != 0)
                delete_ambient_ghsound(curr);

            free((genericptr_t)curr);
            hearing_full_recalc = 1;
            return;
        }
    }
    impossible("del_sound_source: not found type=%d, id=%s", type,
        fmt_ptr((genericptr_t)id->a_obj));
}


/* Save all sound sources of the given volume. */
void
save_sound_sources(fd, mode, volume)
int fd, mode, volume;
{
    int count, actual, is_global;
    sound_source** prev, * curr;

    if (perform_bwrite(mode))
    {
        count = maybe_write_soundsource(fd, volume, FALSE);
        bwrite(fd, (genericptr_t)&count, sizeof count);
        actual = maybe_write_soundsource(fd, volume, TRUE);
        if (actual != count)
        {
            panic("counted %d sound sources, wrote %d! [volume=%d]", count,
                actual, volume);
            return;
        }
    }

    if (release_data(mode)) 
    {
        for (prev = &sound_base; (curr = *prev) != 0;) 
        {
            if (!curr->id.a_monst)
            {
                impossible("save_sound_sources: no id! [volume=%d]", volume);
                is_global = 0;
            }
            else
                switch (curr->type) 
                {
                case SOUNDSOURCE_OBJECT:
                    is_global = !obj_is_local(curr->id.a_obj);
                    break;
                case SOUNDSOURCE_MONSTER:
                    is_global = !mon_is_local_mx(curr->id.a_monst);
                    break;
                case SOUNDSOURCE_LOCATION:
                    is_global = 0; /* always local by definition */
                    break;
                case SOUNDSOURCE_REGION:
                    is_global = 0; /* always local by definition */
                    break;
                default:
                    is_global = 0;
                    impossible("save_sound_sources: bad type (%d) [volume=%d]",
                        curr->type, volume);
                    break;
                }
            /* if global and not doing local, or vice versa, remove it */
            if (is_global ^ (volume == RANGE_LEVEL)) 
            {
                *prev = curr->next;
                if(delete_ambient_ghsound != 0)
                    delete_ambient_ghsound(curr);
                free((genericptr_t)curr);
            }
            else
            {
                prev = &(*prev)->next;
            }
        }
    }
}

/*
 * Pull in the structures from disk, but don't recalculate the object
 * pointers.
 */
void
restore_sound_sources(fd)
int fd;
{
    int count;
    sound_source* ss;

    /* restore elements */
    mread(fd, (genericptr_t)&count, sizeof count);

    while (count-- > 0) {
        ss = (sound_source*)alloc(sizeof(sound_source));
        mread(fd, (genericptr_t)ss, sizeof(sound_source));
        ss->next = sound_base;
        sound_base = ss;
        add_ambient_ghsound(ss);
    }
}

/* to support '#stats' wizard-mode command */
void
sound_stats(hdrfmt, hdrbuf, count, size)
const char* hdrfmt;
char* hdrbuf;
long* count;
size_t* size;
{
    sound_source* ss;

    Sprintf(hdrbuf, hdrfmt, sizeof(sound_source));
    *count = *size = 0L;
    for (ss = sound_base; ss; ss = ss->next) {
        ++* count;
        *size += sizeof * ss;
    }
}

/* Relink all sounds that are so marked. */
void
relink_sound_sources(ghostly)
boolean ghostly;
{
    char which;
    unsigned nid;
    sound_source* ss;

    for (ss = sound_base; ss; ss = ss->next)
    {
        if (ss->flags & SSF_NEEDS_FIXUP)
        {
            if (ss->type == SOUNDSOURCE_OBJECT || ss->type == SOUNDSOURCE_MONSTER || ss->type == SOUNDSOURCE_LOCATION || ss->type == SOUNDSOURCE_REGION)
            {
                if (ghostly && ss->type != SOUNDSOURCE_LOCATION && ss->type != SOUNDSOURCE_REGION)
                {
                    if (!lookup_id_mapping(ss->id.a_uint, &nid))
                        impossible("relink_sound_sources: no id mapping");
                }
                else
                    nid = ss->id.a_uint;

                if (ss->type == SOUNDSOURCE_OBJECT)
                {
                    which = 'o';
                    ss->id.a_obj = find_oid(nid);
                }
                else if (ss->type == SOUNDSOURCE_MONSTER)
                {
                    which = 'm';
                    ss->id.a_monst = find_mid(nid, FM_EVERYWHERE);
                }
                else if (ss->type == SOUNDSOURCE_LOCATION)
                {
                    which = 'l';
                    ss->id = zeroany;
                    ss->id.a_coord.x = ss->x;
                    ss->id.a_coord.y = ss->y;
                }
                else if (ss->type == SOUNDSOURCE_REGION)
                {
                    which = 'r';
                    ss->id.a_nhregion = find_rid(nid);
                }

                if (!ss->id.a_monst)
                    impossible("relink_sound_sources: cant find %c_id %d", which, nid);
            }
            else
                impossible("relink_sound_sources: bad type (%d)", ss->type);

            ss->flags &= ~SSF_NEEDS_FIXUP;
        }
    }
}

/*
 * Part of the sound source save routine.  Count up the number of sound
 * sources that would be written.  If write_it is true, actually write
 * the sound source out.
 */
STATIC_OVL int
maybe_write_soundsource(fd, volume, write_it)
int fd, volume;
boolean write_it;
{
    int count = 0, is_global;
    sound_source* ss;

    for (ss = sound_base; ss; ss = ss->next)
    {
        if (!ss->id.a_monst)
        {
            impossible("maybe_write_soundsource: no id! [volume=%d]", volume);
            continue;
        }

        switch (ss->type)
        {
        case SOUNDSOURCE_OBJECT:
            is_global = !obj_is_local(ss->id.a_obj);
            break;
        case SOUNDSOURCE_MONSTER:
            is_global = !mon_is_local_mx(ss->id.a_monst);
            break;
        case SOUNDSOURCE_LOCATION:
            is_global = 0; /* always local */
            break;
        case SOUNDSOURCE_REGION:
            is_global = 0; /* always local */
            break;
        default:
            is_global = 0;
            impossible("maybe_write_soundsource: bad type (%d) [volume=%d]", ss->type, volume);
            break;
        }

        /* if global and not doing local, or vice versa, count it */
        if (is_global ^ (volume == RANGE_LEVEL))
        {
            count++;
            if (write_it)
                write_soundsource(fd, ss);
        }
    }

    return count;
}

void
sound_sources_sanity_check()
{
    sound_source* ss;
    struct monst* mtmp;
    struct obj* otmp;
    struct nhregion* reg;
    unsigned int auint = 0;

    for (ss = sound_base; ss; ss = ss->next)
    {
        if (!ss->id.a_monst)
        {
            panic("insane sound source: no id!");
            return;
        }
        if (ss->type == SOUNDSOURCE_OBJECT)
        {
            otmp = (struct obj*)ss->id.a_obj;
            if (otmp)
                auint = otmp->o_id;

            if (find_oid(auint) != otmp)
            {
                panic("insane sound source: can't find obj #%u!", auint);
                return;
            }
        }
        else if (ss->type == SOUNDSOURCE_MONSTER)
        {
            mtmp = (struct monst*)ss->id.a_monst;
            if (mtmp)
                auint = mtmp->m_id;

            if (find_mid(auint, FM_EVERYWHERE) != mtmp)
            {
                panic("insane sound source: can't find mon #%u!", auint);
                return;
            }
        }
        else if (ss->type == SOUNDSOURCE_LOCATION)
        {
            coord c = ss->id.a_coord;
            if (!isok(c.x, c.y))
            {
                panic("insane sound source: invalid location coordinates (%d, %d)!", c.x, c.y);
                return;
            }
        }
        else if (ss->type == SOUNDSOURCE_REGION)
        {
            reg = (struct nhregion*)ss->id.a_nhregion;
            if (reg)
                auint = get_rid(reg);

            if (find_rid(auint) != reg)
            {
                panic("insane sound source: can't find nhregion #%u!", auint);
                return;
            }
        }
        else
        {
            panic("insane sound source: bad ss type %d", ss->type);
            return;
        }
    }
}

/* Write a sound source structure to disk. */
STATIC_OVL void
write_soundsource(fd, ss)
int fd;
sound_source* ss;
{
    anything arg_save;
    struct obj* otmp;
    struct monst* mtmp;
    struct nhregion* reg;

    if (ss->type == SOUNDSOURCE_OBJECT || ss->type == SOUNDSOURCE_MONSTER || ss->type == SOUNDSOURCE_LOCATION || ss->type == SOUNDSOURCE_REGION)
    {
        if (ss->flags & SSF_NEEDS_FIXUP)
        {
            bwrite(fd, (genericptr_t)ss, sizeof(sound_source));
        }
        else
        {
            /* replace object pointer with id for write, then put back */
            arg_save = ss->id;
            if (ss->type == SOUNDSOURCE_OBJECT)
            {
                otmp = ss->id.a_obj;
                ss->id = zeroany;
                ss->id.a_uint = otmp->o_id;
                if (find_oid((unsigned)ss->id.a_uint) != otmp)
                    impossible("write_soundsource: can't find obj #%u!",
                        ss->id.a_uint);
            }
            else if (ss->type == SOUNDSOURCE_MONSTER)
            {
                mtmp = (struct monst*)ss->id.a_monst;
                ss->id = zeroany;
                ss->id.a_uint = mtmp->m_id;
                if (find_mid((unsigned)ss->id.a_uint, FM_EVERYWHERE) != mtmp)
                    impossible("write_soundsource: can't find mon #%u!",
                        ss->id.a_uint);
            }
            else if (ss->type == SOUNDSOURCE_LOCATION)
            {
                /* No need to do anything, coord can be written to disk as is */
            }
            else if (ss->type == SOUNDSOURCE_REGION)
            { 
                reg = (struct nhregion*)ss->id.a_nhregion;
                ss->id = zeroany;
                ss->id.a_uint = get_rid(reg);
                if (find_rid((unsigned)ss->id.a_uint) != reg)
                    impossible("write_soundsource: can't find nhregion #%u!",
                        ss->id.a_uint);
            }

            ss->flags |= SSF_NEEDS_FIXUP;
            bwrite(fd, (genericptr_t)ss, sizeof(sound_source));
            ss->id = arg_save;
            ss->flags &= ~SSF_NEEDS_FIXUP;
        }
    }
    else
    {
        impossible("write_soundsource: bad type (%d)", ss->type);
    }
}

/* Change sound source's ID from src to dest. */
void
obj_move_sound_source(src, dest)
struct obj* src, * dest;
{
    sound_source* ss;

    for (ss = sound_base; ss; ss = ss->next)
    {
        if (ss->type == SOUNDSOURCE_OBJECT && ss->id.a_obj == src)
            ss->id.a_obj = dest;
    }

    src->makingsound = 0;
    dest->makingsound = 1;
}

/* return true if there exist any sound sources */
boolean
any_sound_source()
{
    return (boolean)(sound_base != (sound_source*)0);
}

/*
 * Snuff an object sound source if at (x,y).  This currently works
 * only for burning sound sources.
 */
void
snuff_sound_source(x, y)
int x, y;
{
    sound_source* ss;
    struct obj* obj;

    for (ss = sound_base; ss; ss = ss->next)
        /*
         * Is this position check valid??? Can I assume that the positions
         * will always be correct because the objects would have been
         * updated with the last vision update?  [Is that recent enough???]
         */
        if (ss->type == SOUNDSOURCE_OBJECT && ss->x == x && ss->y == y) {
            obj = ss->id.a_obj;
            if (1) //obj_is_burning(obj)) 
            {
                del_sound_source(SOUNDSOURCE_OBJECT, obj_to_any(obj));
                end_sound(obj, FALSE);
                /*
                 * The current ss element has just been removed (and
                 * ss->next is now invalid).  Return assuming that there
                 * is only one sound source attached to each object.
                 */
                return;
            }
        }
        else if (ss->type == SOUNDSOURCE_LOCATION && ss->x == x && ss->y == y)
        {
            if (levl[x][y].makingsound)
            {
                levl[x][y].makingsound = 0;
                del_sound_source(SOUNDSOURCE_LOCATION, xy_to_any(x, y));
                newsym(x, y);
                return;
            }
        }

}


/* copy the sound source(s) attached to src, and attach it/them to dest */
void
obj_split_sound_source(src, dest)
struct obj* src, * dest;
{
    sound_source* ss, * new_ss;

    for (ss = sound_base; ss; ss = ss->next)
        if (ss->type == SOUNDSOURCE_OBJECT && ss->id.a_obj == src) 
        {
            /*
             * Insert the new source at beginning of list.  This will
             * never interfere us walking down the list - we are already
             * past the insertion point.
             */
            new_ss = (sound_source*)alloc(sizeof(sound_source));
            *new_ss = *ss;
            new_ss->id.a_obj = dest;
            new_ss->next = sound_base;
            sound_base = new_ss;
            //dest->lamplit = 1; /* now an active sound source */
        }
}

/* sound source `src' has been folded into sound source `dest';
   used for merging lit candles and adding candle(s) to lit candelabrum */
void
obj_merge_sound_sources(src, dest)
struct obj* src, * dest;
{
    sound_source* ss;

    /* src == dest implies adding to candelabrum */
    if (src != dest)
        del_sound_source(SOUNDSOURCE_OBJECT, obj_to_any(src));
    //end_burn(src, TRUE); /* extinguish candles */


    for (ss = sound_base; ss; ss = ss->next)
        if (ss->type == SOUNDSOURCE_OBJECT && ss->id.a_obj == dest) 
        {
            //ss->volume = candle_sound_range(dest);
            hearing_full_recalc = 1; /* in case volume changed */
            break;
        }
}

/* sound source `obj' is being made brighter or dimmer */
void
obj_adjust_sound_volume(obj, new_volume)
struct obj* obj;
double new_volume;
{
    sound_source* ss;

    for (ss = sound_base; ss; ss = ss->next)
        if (ss->type == SOUNDSOURCE_OBJECT && ss->id.a_obj == obj) {
            if ((float)new_volume != ss->source_volume)
                hearing_full_recalc = 1;
            ss->source_volume = (float)new_volume;
            return;
        }
    impossible("obj_adjust_sound_volume: can't find %s", xname(obj));
}


/*
 * Start a burn timeout on the given object. If not "already lit" then
 * create a light source for the vision system.  There had better not
 * be a burn already running on the object.
 *
 */
void
begin_sound(obj, already_making_noise)
struct obj* obj;
boolean already_making_noise;
{
    long turns = 0;
    boolean do_timer = TRUE;

    obj->makingsound = 1;
    do_timer = FALSE;
    turns = 0;

    if (do_timer) 
    {
        if (start_timer(turns, TIMER_OBJECT, MAKE_SOUND_OBJECT, obj_to_any(obj))) 
        {
            obj->makingsound = 1;
            obj->age -= turns; /* Needs own timer, otherwise possible conflict with light sources */
            if (carried(obj) && !already_making_noise)
                update_inventory();
        }
        else 
        {
            obj->makingsound = 0;
        }
    }
    else 
    {
        if (carried(obj) && !already_making_noise)
            update_inventory();
    }

    if (obj->makingsound && !already_making_noise) 
    {
        xchar x, y;
        enum object_soundset_types objsoundset = objects[obj->otyp].oc_soundset;
        enum ghsound_types ghsound = object_soundsets[objsoundset].sounds[OBJECT_SOUND_TYPE_AMBIENT].ghsound;
        float volume = object_soundsets[objsoundset].sounds[OBJECT_SOUND_TYPE_AMBIENT].volume;
        enum soundsource_ambient_subtypes subtype = object_soundsets[objsoundset].ambient_subtype;

        if (get_obj_location(obj, &x, &y, CONTAINED_TOO | BURIED_TOO))
            new_sound_source(x, y, ghsound, (double)volume, SOUNDSOURCE_OBJECT, subtype, obj_to_any(obj));
        else
            impossible("begin_sound: can't get obj position");
    }
}

/*
 * Stop a burn timeout on the given object if timer attached.  Darken
 * light source.
 */
void
end_sound(obj, timer_attached)
struct obj* obj;
boolean timer_attached;
{
    if (!obj->makingsound) 
    {
        impossible("end_sound: obj %s not making sound", xname(obj));
        return;
    }

    if (1) //obj->otyp == MAGIC_LAMP || obj->otyp == MAGIC_CANDLE || artifact_light(obj) || obj_shines_magical_light(obj))
        timer_attached = FALSE;

    if (!timer_attached) {
        /* [DS] Cleanup explicitly, since timer cleanup won't happen */
        del_sound_source(SOUNDSOURCE_OBJECT, obj_to_any(obj));
        obj->makingsound = 0;
        if (obj->where == OBJ_INVENT)
            update_inventory();
    }
    else if (!stop_timer(MAKE_SOUND_OBJECT, obj_to_any(obj)))
        impossible("end_sound: obj %s not timed!", xname(obj));
}

boolean
obj_has_sound_source(obj)
struct obj* obj;
{
    return (obj->makingsound == TRUE);
}

enum ghsound_types
obj_ambient_sound(obj)
struct obj* obj;
{
    if (!obj || objects[obj->otyp].oc_soundset == OBJECT_SOUNDSET_NONE)
        return GHSOUND_NONE;

    return object_soundsets[objects[obj->otyp].oc_soundset].sounds[OBJECT_SOUND_TYPE_AMBIENT].ghsound;
}

double
obj_ambient_sound_volume(obj)
struct obj* obj;
{
    if (!obj || objects[obj->otyp].oc_soundset == OBJECT_SOUNDSET_NONE)
        return 0.0;

    return (double)object_soundsets[objects[obj->otyp].oc_soundset].sounds[OBJECT_SOUND_TYPE_AMBIENT].volume;
}

enum ghsound_types
get_location_ambient_sound_type(x, y, volume_ptr, subtype_ptr)
xchar x, y;
double* volume_ptr;
enum soundsource_ambient_subtypes *subtype_ptr;
{
    if (!isok(x, y))
        return GHSOUND_NONE;

    struct rm* lev = &levl[x][y];

    enum location_soundset_types lsoundset = location_type_definitions[lev->typ].soundset;

    if (lsoundset == LOCATION_SOUNDSET_NONE)
        return GHSOUND_NONE;

    if (volume_ptr)
        *volume_ptr = (double)location_soundsets[lsoundset].sounds[LOCATION_SOUND_TYPE_AMBIENT].volume;

    if (subtype_ptr)
        *subtype_ptr = location_soundsets[lsoundset].ambient_subtype;

    return location_soundsets[lsoundset].sounds[LOCATION_SOUND_TYPE_AMBIENT].ghsound;
}

enum ghsound_types
get_dungeon_music(dnum)
int dnum;
{
    enum ghsound_types res = GHSOUND_NONE;

    if (Inhell)
        res = GHSOUND_GEHENNOM_MUSIC_NORMAL;
    else if (dnum == mines_dnum)
        res = GHSOUND_GNOMISH_MINES_MUSIC_NORMAL;
    else if (dnum == sokoban_dnum)
        res = GHSOUND_SOKOBAN_MUSIC_NORMAL;
    else if (dnum == quest_dnum)
        res = GHSOUND_DUNGEON_NORMAL_MUSIC_NORMAL;
    else if (dnum == tower_dnum)
        res = GHSOUND_DUNGEON_NORMAL_MUSIC_NORMAL;
    else if (dnum == modron_dnum)
        res = GHSOUND_DUNGEON_NORMAL_MUSIC_NORMAL;
    else if (dnum == bovine_dnum)
        res = GHSOUND_DUNGEON_NORMAL_MUSIC_NORMAL;
    else
        res = GHSOUND_DUNGEON_NORMAL_MUSIC_NORMAL;

    return res;
}

enum ghsound_types
get_level_music(dlvl)
struct d_level* dlvl;
{
    enum ghsound_types res = GHSOUND_NONE;
    if (!dlvl)
        return res;

    int dnum = dlvl->dnum;


    if (Is_valley(dlvl))
        return GHSOUND_GEHENNOM_MUSIC_VALLEY;
    else if (Is_sanctum(dlvl))
        return GHSOUND_GEHENNOM_MUSIC_SANCTUM;
    else if (Is_stronghold(dlvl))
        return GHSOUND_DUNGEON_NORMAL_MUSIC_CASTLE;
    else if (Is_medusa_level(dlvl))
        return GHSOUND_DUNGEON_NORMAL_MUSIC_MEDUSA;
    else if (Is_asmo_level(dlvl))
        return GHSOUND_GEHENNOM_MUSIC_NORMAL;
    if (Is_minetown_level(dlvl))
        return GHSOUND_GNOMISH_MINES_MUSIC_TOWN;
    else
        return get_dungeon_music(dnum);

    return res;
}

enum ghsound_types
get_room_music(room)
struct mkroom* room;
{
    enum roomtype_types rtype = room->orig_rtype;
    enum ghsound_types res = get_level_music(&u.uz);;

    if (rtype >= SHOPBASE)
    {
        if (room->resident && room->resident->isshk && room->resident->mextra && ESHK(room->resident))
        {
            if(is_peaceful(room->resident))
            {
                switch (rtype)
                {
                case SHOPBASE:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case ARMORSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case SCROLLSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case POTIONSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case WEAPONSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case FOODSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case RINGSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case WANDSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case TOOLSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case BOOKSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case REAGENTSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case FODDERSHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                case CANDLESHOP:
                    res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL;
                    break;
                default:
                    break;
                }
            }
            else
            {
                res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_SHOPKEEPER_ANGRY;
            }
        }
        else
        {
            res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_SHOPKEEPER_DEAD;
        }
    }
    else
    {
        switch (rtype)
        {
        case OROOM:
            break;
        case COURT:
            break;
        case SWAMP:
            break;
        case VAULT:
            break;
        case BEEHIVE:
            break;
        case DRAGONLAIR:
            break;
        case LIBRARY:
            break;
        case GARDEN:
            break;
        case MORGUE:
            break;
        case BARRACKS:
            break;
        case ZOO:
            break;
        case DELPHI:
            res = GHSOUND_DUNGEON_NORMAL_MUSIC_ORACLE;
            break;
        case TEMPLE:
            res = GHSOUND_DUNGEON_NORMAL_MUSIC_TEMPLE;
            break;
        case LEPREHALL:
            break;
        case COCKNEST:
            break;
        case ANTHOLE:
            break;
        case DESERTEDSHOP:
            res = GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_DESERTED;
            break;
        default:
            break;
        }
    }

    return res;
}


enum ghsound_types
get_level_ambient_sounds(dlvl)
struct d_level* dlvl;
{
    enum ghsound_types res = GHSOUND_NONE;
    if (!dlvl)
        return res;

    int dnum = dlvl->dnum;


    if (Is_valley(dlvl))
        return GHSOUND_GEHENNOM_VALLEY_AMBIENT;
    else
        return GHSOUND_NONE;

    return res;
}

enum ghsound_types
get_room_ambient_sounds(room)
struct mkroom* room;
{
    enum roomtype_types rtype = room->orig_rtype;
    enum ghsound_types res = get_level_ambient_sounds(&u.uz);

    switch (rtype)
    {
    case OROOM:
        break;
    case COURT:
        break;
    case SWAMP:
        break;
    case VAULT:
        break;
    case BEEHIVE:
        break;
    case DRAGONLAIR:
        break;
    case LIBRARY:
        break;
    case GARDEN:
        res = GHSOUND_GARDEN;
        break;
    case MORGUE:
        res = GHSOUND_MORGUE;
        break;
    case BARRACKS:
        break;
    case ZOO:
        break;
    case DELPHI:
        break;
    case TEMPLE:
        break;
    case LEPREHALL:
        break;
    case COCKNEST:
        break;
    case ANTHOLE:
        break;
    case DESERTEDSHOP:
        res = GHSOUND_MORGUE;
        break;
    case ARMORSHOP:
        break;
    case SHOPBASE:
        break;
    case SCROLLSHOP:
        break;
    case POTIONSHOP:
        break;
    case WEAPONSHOP:
        break;
    case FOODSHOP:
        break;
    case RINGSHOP:
        break;
    case WANDSHOP:
        break;
    case TOOLSHOP:
        break;
    case BOOKSHOP:
        break;
    case REAGENTSHOP:
        break;
    case FODDERSHOP:
        break;
    case CANDLESHOP:
        break;
    default:
        break;
    }

    return res;
}



/* soundset.c */
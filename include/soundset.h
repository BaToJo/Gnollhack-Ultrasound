/*
 * soundset.h
 * Copyright (c) Janne Gustafsson, 2020
 */
#include "action.h" 

#ifndef SOUNDSET_H
#define SOUNDSET_H

#define BACKGROUND_MUSIC_VOLUME 0.04f
#define SIMPLE_STEALTH_VOLUME 0.08f
#define MAX_HEARING_DISTANCE 10


/*
* GHSOUNDS
*/
/* All GnollHack Sounds */
enum ghsound_types {
	GHSOUND_NONE = 0,
	GHSOUND_MUSIC_SPLASH,
	GHSOUND_MUSIC_PLAYER_SELECTION,
	GHSOUND_MUSIC_INTRO,
	GHSOUND_DUNGEON_NORMAL_MUSIC_NORMAL,
	GHSOUND_DUNGEON_NORMAL_MUSIC_ORACLE,
	GHSOUND_DUNGEON_NORMAL_MUSIC_TEMPLE,
	GHSOUND_DUNGEON_NORMAL_MUSIC_MEDUSA,
	GHSOUND_DUNGEON_NORMAL_MUSIC_CASTLE,
	GHSOUND_GNOMISH_MINES_MUSIC_NORMAL,
	GHSOUND_GNOMISH_MINES_MUSIC_TOWN,
	GHSOUND_SOKOBAN_MUSIC_NORMAL,
	GHSOUND_GEHENNOM_MUSIC_NORMAL,
	GHSOUND_GEHENNOM_MUSIC_VALLEY,
	GHSOUND_GEHENNOM_MUSIC_SANCTUM,
	GHSOUND_PLAYER_FOOTSTEPS_NORMAL,
	GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_NORMAL,
	GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_SHOPKEEPER_ANGRY,
	GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_SHOPKEEPER_DEAD,
	GHSOUND_DUNGEON_NORMAL_MUSIC_SHOP_DESERTED,
	GHSOUND_FOUNTAIN,
	GHSOUND_BEE,
	GHSOUND_FIRE,
	GHSOUND_STAFF_SWING,
	GHSOUND_STAFF_HIT,
	GHSOUND_GEHENNOM_VALLEY_AMBIENT,
	GHSOUND_MORGUE,
	GHSOUND_GARDEN,
	GHSOUND_UI_BUTTON_DOWN,
	GHSOUND_UI_MENU_SELECT,
	GHSOUND_SFX_QUAFF,
	GHSOUND_POISON_GAS_INSIDE,
	GHSOUND_RAY_ELEC_AMBIENT,
	GHSOUND_RAY_ELEC_CREATE,
	GHSOUND_RAY_ELEC_DESTROY,
	GHSOUND_RAY_ELEC_BOUNCE,
	GHSOUND_BOW_FIRE,
	GHSOUND_ARROW_HIT,
	GHSOUND_SWORD_SWING,
	GHSOUND_SWORD_HIT,
	GHSOUND_AXE_SWING,
	GHSOUND_AXE_HIT,
	GHSOUND_GOBLIN_DEATH,
	GHSOUND_DAGGER_SWING,
	GHSOUND_DAGGER_HIT,
	GHSOUND_HUMAN_BAREHANDED_SWING,
	GHSOUND_HUMAN_BAREHANDED_HIT,
	GHSOUND_HUMAN_KICK_SWING,
	GHSOUND_HUMAN_KICK_HIT,
	GHSOUND_DOOR_WHAM,
	GHSOUND_DOOR_BREAK,
	GHSOUND_DOOR_OPEN,
	GHSOUND_DOOR_CLOSE,
	GHSOUND_DOOR_UNLOCK,
	GHSOUND_DOOR_LOCK,
	GHSOUND_DOOR_RESISTS,
	GHSOUND_DOOR_TRY_LOCKED,
	GHSOUND_CHEST_UNLOCK,
	GHSOUND_CHEST_LOCK,
	GHSOUND_CROSSBOW_FIRE,
	GHSOUND_PICKUP_COINS,
	GHSOUND_DROP_COINS,
	GHSOUND_HORSE_FOOTSTEPS,
	GHSOUND_PUSH_BOULDER,
	GHSOUND_PUSH_EFFORT,
	GHSOUND_CAUSE_PARALYSIS,
	GHSOUND_CAUSE_SLEEPING,
	GHSOUND_MONSTER_DEATH_GENERIC,
	GHSOUND_CHEST_BREAK_LOCK,
	GHSOUND_CHEST_LID_SLAM,
	GHSOUND_GENERIC_ITEM_PICK_UP,
	GHSOUND_GENERIC_ITEM_DROP,
	GHSOUND_GENERIC_ITEM_THROW,
	GHSOUND_FOOTSTEPS_COTTON_SLIPPERS,
	GHSOUND_SWORD_DROP,
	GHSOUND_DAGGER_DROP,
	GHSOUND_GENERIC_FLY,
	GHSOUND_GENERIC_LEVITATE,
	MAX_GHSOUNDS
};


/* 
 * SOUND SOURCES ETC.
 */
/* Mobile ambient sound sources */
enum soundsource_types {
	SOUNDSOURCE_OBJECT = 0,
	SOUNDSOURCE_MONSTER,
	SOUNDSOURCE_LOCATION,
	SOUNDSOURCE_REGION,
	MAX_SOUNDSOURCE_TYPES
};

enum soundsource_ambient_subtypes {
	SOUNDSOURCE_AMBIENT_GENERAL = 0,
	SOUNDSOURCE_AMBIENT_LIT,
	SOUNDSOURCE_AMBIENT_INSIDE_REGION,
	MAX_SOUNDSOURCE_AMBIENT_SUBTYPES
};


/* UI sound types */
enum ui_sound_types {
	UI_SOUND_ILLEGAL = 0,
	UI_SOUND_BUTTON_DOWN,
	UI_SOUND_MENU_SELECT,
	UI_SOUND_TICK_BOX,
	UI_SOUND_UNTICK_BOX,
	UI_SOUND_OPEN_WINDOW,
	MAX_UI_SOUND_TYPES
};

/* General effect sound types */
enum sfx_sound_types {
	SFX_ILLEGAL = 0,
	SFX_READ,
	SFX_QUAFF,
	SFX_OPEN_DOOR,
	SFX_CLOSE_DOOR,
	SFX_UNLOCK_DOOR,
	SFX_LOCK_DOOR,
	SFX_DOOR_RESISTS,
	SFX_DOOR_TRY_LOCKED,
	SFX_KICK_SWING,
	SFX_KICK_THUMP,
	SFX_MUFFLED_SHATTER,
	SFX_CHIME_OF_CASH_REGISTER,
	SFX_SHIELD_EFFECT,
	SFX_TALK_EFFECT,
	SFX_PUSH_BOULDER,
	SFX_CAUSE_PARALYSIS,
	SFX_CAUSE_SLEEPING,
//	SFX_CAUSE_STUN,
//	SFX_CAUSE_BLINDNESS,
//	SFX_CAUSE_TERMINAL_ILLNESS,
//	SFX_CAUSE_FOOD_POISONING,
//	SFX_CAUSE_MUMMY_ROT,
//	SFX_CAUSE_PETRIFICATION,
	MAX_SFX_SOUND_TYPES
};


/* 
 * SOUND WINDOWPROC FUNCTION DEFINITIONS 
 */
#define MAX_SOUND_PARAMETERS 8
enum immediate_sound_types {
	IMMEDIATE_SOUND_SFX = 0,
	IMMEDIATE_SOUND_UI = 1
};

/* Used play_ghsound function input structs */
struct ghsound_immediate_info {
	enum ghsound_types ghsound;
	char* parameter_names[MAX_SOUND_PARAMETERS];
	float parameter_values[MAX_SOUND_PARAMETERS];
	float volume;
	enum immediate_sound_types sound_type;
};

struct ghsound_music_info {
	enum ghsound_types ghsound;
	float volume;
	boolean stop_music;
};

struct ghsound_level_ambient_info {
	enum ghsound_types ghsound;
	float volume;
};

struct ghsound_effect_ambient_info {
	enum ghsound_types ghsound;
	float volume;
};

struct effect_ambient_volume_info {
	float volume;
};


/* Unused play_ghsound function input structs */
struct function_info_A {
	enum ghsound_types ghsound;
	float volume;
};


struct function_info_C {
	enum ghsound_types ghsound;
	enum obj_material_types strike_surface;
	float volume;
};


/* 
 * SOUNDSET DEFINITIONS 
 */
/* General sound information */
struct ghsound_info {
	enum ghsound_types ghsound;
	float volume;
};

/* OBJECT SOUNDSETS */
enum object_sound_types {
	OBJECT_SOUND_TYPE_AMBIENT = 0,		/* Ambient sound that is typically either continuously played or played when the object is lit */

	/* Combat */
	OBJECT_SOUND_TYPE_SWING_MELEE,		/* Played at the start of the attack animation */
	OBJECT_SOUND_TYPE_HIT_MELEE,		/* Played at the end of the melee attack animation and at the end of throw if the attack hits target */
	OBJECT_SOUND_TYPE_THROW,			/* Played when the object is thrown */
	OBJECT_SOUND_TYPE_FIRE,				/* Played when a launcher is fired */
	OBJECT_SOUND_TYPE_HIT_THROW,		/* Played at the end of the throw/fire attack animation and at the end of throw if the attack hits target */

	/* Spell */
	OBJECT_SOUND_TYPE_MISSILE_EFFECT_AMBIENT,
	OBJECT_SOUND_TYPE_CREATE_MISSILE_EFFECT,
	OBJECT_SOUND_TYPE_DESTROY_MISSILE_EFFECT,
	OBJECT_SOUND_TYPE_MISSILE_EFFECT_HIT_MONSTER,
	OBJECT_SOUND_TYPE_MISSILE_EFFECT_HIT_OBJECT,
	OBJECT_SOUND_TYPE_MISSILE_EFFECT_HIT_LOCATION,

	/* Handling */
	OBJECT_SOUND_TYPE_PICK_UP,
	OBJECT_SOUND_TYPE_DROP,
	OBJECT_SOUND_TYPE_OPEN_CONTAINER,
	OBJECT_SOUND_TYPE_CLOSE_CONTAINER,
	OBJECT_SOUND_TYPE_UNLOCK_CONTAINER,
	OBJECT_SOUND_TYPE_LOCK_CONTAINER,
	OBJECT_SOUND_TYPE_BREAK_LOCK_CONTAINER,
	OBJECT_SOUND_TYPE_LID_SLAM_CONTAINER,
	OBJECT_SOUND_TYPE_WEAR,
	OBJECT_SOUND_TYPE_TAKEOFF,
	OBJECT_SOUND_TYPE_WIELD,
	OBJECT_SOUND_TYPE_UNWIELD,
	OBJECT_SOUND_TYPE_QUIVER,
	OBJECT_SOUND_TYPE_UNQUIVER,
	OBJECT_SOUND_TYPE_APPLY,
	OBJECT_SOUND_TYPE_INVOKE,
	OBJECT_SOUND_TYPE_QUAFF,
	OBJECT_SOUND_TYPE_READ,

	/* General */
	OBJECT_SOUND_TYPE_BREAK,			/* Sound upon breaking the item */
	OBJECT_SOUND_TYPE_PUSH,

	/* Movement */
	OBJECT_SOUND_TYPE_WALK,				/* Walk sound if used as boots */
	OBJECT_SOUND_TYPE_FLY,				/* Fly if attached to back */
	OBJECT_SOUND_TYPE_LEVITATION,		/* Levitate when worn / used */
	OBJECT_SOUND_TYPE_SWIM,				/* Swim when worn */
	MAX_OBJECT_SOUND_TYPES
};


struct object_soundset_definition {
	char* soundset_name;
	struct ghsound_info sounds[MAX_OBJECT_SOUND_TYPES];
	enum soundsource_ambient_subtypes ambient_subtype;
};

enum object_soundset_types {
	OBJECT_SOUNDSET_NONE = 0,
	OBJECT_SOUNDSET_GENERAL,
	OBJECT_SOUNDSET_CANDLE,
	OBJECT_SOUNDSET_QUARTERSTAFF,
	OBJECT_SOUNDSET_BOW,
	OBJECT_SOUNDSET_CROSSBOW,
	OBJECT_SOUNDSET_ARROW,
	OBJECT_SOUNDSET_SWORD,
	OBJECT_SOUNDSET_AXE,
	OBJECT_SOUNDSET_DAGGER,
	OBJECT_SOUNDSET_BONE_DAGGER,
	OBJECT_SOUNDSET_HUMAN_BAREHANDED,
	OBJECT_SOUNDSET_HUMAN_BAREFOOTED,
	OBJECT_SOUNDSET_HORSE_BAREFOOTED,
	OBJECT_SOUNDSET_COTTON_SLIPPERS,
	OBJECT_SOUNDSET_CHEST,
	OBJECT_SOUNDSET_COIN,
	OBJECT_SOUNDSET_BOULDER,
	MAX_OBJECT_SOUNDSETS
};

extern struct object_soundset_definition object_soundsets[MAX_OBJECT_SOUNDSETS];


/* PLAYER SOUNDSETS */
enum player_sound_types {
	PLAYER_SOUND_TYPE_AMBIENT = 0,
	PLAYER_SOUND_TYPE_COUGH,
	PLAYER_SOUND_TYPE_OUCH,
	PLAYER_SOUND_TYPE_SEARCH,
	PLAYER_SOUND_TYPE_SEARCH_FOUND_SOMETHING,
	PLAYER_SOUND_TYPE_WAIT,
	PLAYER_SOUND_TYPE_PUSH_EFFORT,
	PLAYER_SOUND_TYPE_DEATH,
	MAX_PLAYER_SOUND_TYPES
};

enum player_attack_soundset_types {
	PLAYER_ATTACK_SOUNDSET_BAREHANDED = 0,
	PLAYER_ATTACK_SOUNDSET_BAREFOOTED,
	MAX_PLAYER_ATTACK_SOUNDSETS
};

struct player_soundset_definition {
	char* soundset_name;

	/* General */
	struct ghsound_info sounds[MAX_PLAYER_SOUND_TYPES];
	enum soundsource_ambient_subtypes ambient_subtype;

	/* Bare-handed and kick soundsets */
	enum object_soundset_types attack_soundsets[MAX_PLAYER_ATTACK_SOUNDSETS];
};

enum player_soundset_types {
	PLAYER_SOUNDSET_NONE = 0,
	PLAYER_SOUNDSET_GENERAL,
	PLAYER_SOUNDSET_FEMALE_ELVEN_WIZARD,
	MAX_PLAYER_SOUNDSETS
};

extern struct player_soundset_definition player_soundsets[MAX_PLAYER_SOUNDSETS];


/* MONSTER SOUNDSETS */
enum monster_sound_types {
	MONSTER_SOUND_TYPE_AMBIENT = 0,
	MONSTER_SOUND_TYPE_COUGH,
	MONSTER_SOUND_TYPE_PUSH_EFFORT,
	MONSTER_SOUND_TYPE_DEATH,
	MAX_MONSTER_SOUND_TYPES
};

struct monster_soundset_definition {
	char* soundset_name;

	/* General */
	struct ghsound_info sounds[MAX_MONSTER_SOUND_TYPES];
	enum soundsource_ambient_subtypes ambient_subtype;

	/* Attacks */
	enum object_soundset_types attack_soundsets[NATTK + 1]; /* attack # NATTK is used for hit sounds in kick command and for walking sound */

#define BAREHANDED_ATTACK_NUMBER 0
#define BAREFOOTED_ATTACK_NUMBER NATTK
};

enum monster_soundset_types {
	MONSTER_SOUNDSET_NONE = 0,
	MONSTER_SOUNDSET_GENERAL,
	MONSTER_SOUNDSET_GOBLIN,
	MONSTER_SOUNDSET_DRAGON,
	MONSTER_SOUNDSET_DRACOLICH,
	MONSTER_SOUNDSET_BEE,
	MONSTER_SOUNDSET_HORSE,
	MAX_MONSTER_SOUNDSETS
};

extern struct monster_soundset_definition monster_soundsets[MAX_MONSTER_SOUNDSETS];


/* LOCATION SOUNDSETS */
enum location_sound_types {
	LOCATION_SOUND_TYPE_AMBIENT = 0,	/* Ambient sound that is typically either continuously played or played when the location is lit */
	LOCATION_SOUND_TYPE_WHAM,			/* Sound upon kicking the location */
	LOCATION_SOUND_TYPE_BREAK,			/* Sound upon breaking the location */
	MAX_LOCATION_SOUND_TYPES
};

struct location_soundset_definition {
	char* soundset_name;
	struct ghsound_info sounds[MAX_LOCATION_SOUND_TYPES];
	enum soundsource_ambient_subtypes ambient_subtype;
};

enum location_soundset_types {
	LOCATION_SOUNDSET_NONE = 0,
	LOCATION_SOUNDSET_GENERAL,
	LOCATION_SOUNDSET_FOUNTAIN,
	LOCATION_SOUNDSET_ALTAR,
	LOCATION_SOUNDSET_DOOR,
	MAX_LOCATION_SOUNDSETS
};

extern struct location_soundset_definition location_soundsets[MAX_LOCATION_SOUNDSETS];


/* REGION SOUNDSETS */
enum region_sound_types {
	REGION_SOUND_TYPE_AMBIENT = 0,				/* Player inside or outside of the region, based on the square with best hearing value: Ambient sound that is typically either continuously played or played when the region is lit */
	REGION_SOUND_TYPE_CREATE,					/* Sound upon creation of the region */
	REGION_SOUND_TYPE_DESTROY,					/* Sound upon destruction of the region */
	MAX_REGION_SOUND_TYPES
};

struct region_soundset_definition {
	char* soundset_name;
	struct ghsound_info sounds[MAX_REGION_SOUND_TYPES];
	enum soundsource_ambient_subtypes ambient_subtype;
};

enum region_soundset_types {
	REGION_SOUNDSET_NONE = 0,
	REGION_SOUNDSET_POISON_GAS,
	MAX_REGION_SOUNDSETS
};

extern struct region_soundset_definition region_soundsets[MAX_REGION_SOUNDSETS];

/* EFFECT SOUNDS */
struct effect_sound_definition {
	char* sound_name;
	struct ghsound_info sound;
};

extern struct effect_sound_definition ui_sounds[MAX_UI_SOUND_TYPES];
extern struct effect_sound_definition sfx_sounds[MAX_SFX_SOUND_TYPES];


/* RAY SOUNDSETS */
enum ray_sound_types {
	RAY_SOUND_TYPE_AMBIENT = 0,				/* Ambient sound while the ray is travelling */
	RAY_SOUND_TYPE_CREATE,					/* Sound upon creation of the ray */
	RAY_SOUND_TYPE_DESTROY,					/* Sound upon dissipation of the ray */
	RAY_SOUND_TYPE_BOUNCE,					/* Sound upon the ray bouncing */
	RAY_SOUND_TYPE_WHIZZES_BY_YOU,			/* Sound upon the ray wheezing by you */
	RAY_SOUND_TYPE_HIT_MONSTER,				/* Sound upon the ray hitting a monster */
	RAY_SOUND_TYPE_HIT_OBJECT,				/* Sound upon the ray hitting an object */
	RAY_SOUND_TYPE_HIT_LOCATION,			/* Sound upon the ray hitting a location, e.g. digging a wall */
	MAX_RAY_SOUND_TYPES
}; 

struct ray_soundset_definition {
	char* soundset_name;
	struct ghsound_info sounds[MAX_RAY_SOUND_TYPES];
};

extern struct ray_soundset_definition ray_soundsets[2 * NRAYS]; /* 0...NRAYS-1 normal ray, NRAYS...2NRAYS-1 explosion */


/* Other definitions */
enum hit_surface_source_types {
	HIT_SURFACE_SOURCE_NONE = 0,
	HIT_SURFACE_SOURCE_MONSTER,
	HIT_SURFACE_SOURCE_OBJECT,
	HIT_SURFACE_SOURCE_LOCATION,
	HIT_SURFACE_SOURCE_TRAP
};

enum hit_surface_types {
	HIT_SURFACE_NONE = 0,
	HIT_SURFACE_FLESH,
	HIT_SURFACE_ORGANIC, /* Jellies */
	HIT_SURFACE_BONE,  /* Also chitin etc. */
	HIT_SURFACE_LEATHER,
	HIT_SURFACE_METAL,
	HIT_SURFACE_WOOD,
	HIT_SURFACE_STONE,
	HIT_SURFACE_GLASS,
	HIT_SURFACE_LIQUID,
	HIT_SURFACE_IMMATERIAL,
	MAX_HIT_SURFACE_TYPES
};


/* Movement paramters (+weight) */
enum floor_surface_types {
	FLOOR_SURFACE_NONE = 0,
	FLOOR_SURFACE_STONE,
	FLOOR_SURFACE_WOOD,
	FLOOR_SURFACE_GROUND,
	FLOOR_SURFACE_GRASS,
	FLOOR_SURFACE_METAL,
	FLOOR_SURFACE_CARPET,
	FLOOR_SURFACE_LIQUID,
	MAX_FLOOR_SURFACE_TYPES
};

enum floor_treading_types {
	FLOOR_TREADING_TYPE_NORMAL = 0,
	FLOOR_TREADING_TYPE_STEALTH,
	FLOOR_TREADING_TYPE_RUN,
	MAX_FLOOR_TREADING_TYPES
};

enum climbing_types {
	CLIMBING_TYPE_NONE = 0,
	CLIMBING_TYPE_STAIRS_UP,
	CLIMBING_TYPE_STAIRS_DOWN,
	CLIMBING_TYPE_LADDER_UP,
	CLIMBING_TYPE_LADDER_DOWN,
	MAX_CLIMBING_TYPES
};

enum location_passing_types {
	LOCATION_PASSING_TYPE_NORMAL = 0,
	LOCATION_PASSING_TYPE_WATERWALKING,			/* Has waterwalking on water or lava, so does not strictly splash the water or lava */
	LOCATION_PASSING_TYPE_THROUGH_SOLID_WALLS,  /* Like a ghost, xorn or earth elemental; sound inside solid wall, maybe normal while not inside? */
	LOCATION_PASSING_TYPE_SUBMERGED,			/* Maybe an amulet of magical breathing and no swimming */
	MAX_LOCATION_PASSING_TYPES
};

#endif /* SOUNDSET_H */
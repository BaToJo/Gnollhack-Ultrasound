/*
 * animation.h
 * Copyright 2020 by Janne Gustafsson
 */
#include "action.h"

#ifndef ANIMATION_H
#define ANIMATION_H

/* Game cursor types */
enum game_cursor_types
{
    CURSOR_STYLE_GENERIC_CURSOR = 0,
    CURSOR_STYLE_LOOK_CURSOR,
    CURSOR_STYLE_TRAVEL_CURSOR,
    CURSOR_STYLE_NAME_CURSOR,
    CURSOR_STYLE_TELEPORT_CURSOR,
    CURSOR_STYLE_JUMP_CURSOR,
    CURSOR_STYLE_POLEARM_CURSOR,
    CURSOR_STYLE_GRAPPLE_CURSOR,
    CURSOR_STYLE_SPELL_CURSOR,
    CURSOR_STYLE_PAY_CURSOR,
    MAX_CURSORS
};

struct game_cursor_definition {
    char* game_cursor_name;
    enum replacement_types replacement;
    enum animation_types animation;
    enum enlargement_types enlargement;
};


extern NEARDATA struct game_cursor_definition game_cursors[];


/* Autodraw */
enum autodraw_types
{
    AUTODRAW_NONE = 0,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_ALL,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_LEFT_RIGHT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_DOWN,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_DOWN_LEFT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_DOWN_RIGHT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_LEFT_RIGHT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_DOWN_LEFT_RIGHT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_DOWN_RIGHT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_DOWN_LEFT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_RIGHT,
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_LEFT
};

#define NUM_AUTODRAWS AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_LEFT

enum autodraw_drawing_types
{
    AUTODRAW_DRAW_GENERAL = 0,
    AUTODRAW_DRAW_REPLACE_WALL_ENDS
};


struct autodraw_definition {
    char* autodraw_name;
    enum autodraw_drawing_types draw_type;
    char draw_directions;
    int source_glyph;
    int source_glyph2;
    int source_glyph3;
    /* and other useful stuff if need be */
};

#define AUTODRAW_DIR_LEFT 0x01
#define AUTODRAW_DIR_RIGHT 0x02
#define AUTODRAW_DIR_UP 0x04
#define AUTODRAW_DIR_DOWN 0x08

extern NEARDATA struct autodraw_definition autodraws[];


/* Enlargement sets */
#define MAX_FRAMES_PER_ENLARGEMENT 5
#define MAX_TILES_PER_ENLARGEMENT MAX_FRAMES_PER_ENLARGEMENT

struct enlargement_definition {
    char* enlargement_name;
    char number_of_tiles;
    char number_of_frames;
    int glyph_offset;
    char width_in_tiles;
    char height_in_tiles;
    char main_tile_x_coordinate; /* Always 0 or 1 on the last row */
    char frame2tile[MAX_FRAMES_PER_ENLARGEMENT];
    /* Enlargement frame position: number from 0 to 4, X = -1 indicates main tile
            0 1 2    
            3 X 4
    */
    char frame_flags[MAX_FRAMES_PER_ENLARGEMENT];
    enum autodraw_types frame_autodraw[MAX_FRAMES_PER_ENLARGEMENT];
};

#define ENLFLAGS_H_FLIP 0x01


enum enlargement_types
{
    NO_ENLARGEMENT = 0,
    DRACOLICH_ENLARGEMENT,
    DRACOLICH_STATUE_ENLARGEMENT,
    TREE_ENLARGEMENT,
    DUNGEON_NORMAL_UPSTAIRS_ENLARGEMENT,
    DUNGEON_NORMAL_BRANCH_UPSTAIRS_ENLARGEMENT,
    DUNGEON_NORMAL_SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT /* Keep this last */
};

#define NUM_ENLARGEMENTS DUNGEON_NORMAL_SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT

#define DRACOLICH_ENLARGEMENT_OFF (0)
#define DRACOLICH_ENLARGEMENT_FRAMES 5

#define DRACOLICH_STATUE_ENLARGEMENT_OFF (DRACOLICH_ENLARGEMENT_FRAMES + DRACOLICH_ENLARGEMENT_OFF)
#define DRACOLICH_STATUE_ENLARGEMENT_FRAMES 5

#define TREE_ENLARGEMENT_OFF (DRACOLICH_STATUE_ENLARGEMENT_FRAMES + DRACOLICH_STATUE_ENLARGEMENT_OFF)
#define TREE_ENLARGEMENT_FRAMES 5

#define UPSTAIRS_ENLARGEMENT_OFF (TREE_ENLARGEMENT_FRAMES + TREE_ENLARGEMENT_OFF)
#define UPSTAIRS_ENLARGEMENT_FRAMES 1

#define BRANCH_UPSTAIRS_ENLARGEMENT_OFF (UPSTAIRS_ENLARGEMENT_FRAMES + UPSTAIRS_ENLARGEMENT_OFF)
#define BRANCH_UPSTAIRS_ENLARGEMENT_FRAMES 1

#define SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_OFF (BRANCH_UPSTAIRS_ENLARGEMENT_FRAMES + BRANCH_UPSTAIRS_ENLARGEMENT_OFF)
#define SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_FRAMES 1

#define MAX_ENLARGEMENT_FRAMES (SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_FRAMES + SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_OFF)

extern NEARDATA struct enlargement_definition enlargements[];


/* Animation tiles */
#define MAX_FRAMES_PER_ANIMATION 32
#define MAX_TILES_PER_ANIMATION MAX_FRAMES_PER_ANIMATION

enum animation_play_types
{
    ANIMATION_PLAY_TYPE_ALWAYS = 0,
    ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY
};

enum main_tile_use_types
{
    ANIMATION_MAIN_TILE_USE_FIRST = 0,
    ANIMATION_MAIN_TILE_USE_LAST,
    ANIMATION_MAIN_TILE_IGNORE
};

struct animation_definition {
    char* animation_name;
    char number_of_tiles;
    char number_of_frames;
    int glyph_offset;
    int intervals_between_frames;
    enum animation_play_types play_type;
    enum main_tile_use_types main_tile_use_style; /* 0 = play as first tile and frame, 1 = play as last tile and frame, 2 = ignore */
    enum autodraw_types  main_tile_autodraw;
    char frame2tile[MAX_FRAMES_PER_ANIMATION];
    short tile_enlargement[MAX_TILES_PER_ANIMATION];
    enum autodraw_types frame_autodraw[MAX_FRAMES_PER_ANIMATION];
};

enum animation_types
{
    NO_ANIMATION = 0,
    HANDCRAFTED_CANDLE_LIT_ANIMATION,
    PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION,
    BRASS_LANTERN_LIT_ANIMATION,
    LAWFUL_ALTAR_ANIMATION,
    NEUTRAL_ALTAR_ANIMATION,
    CHAOTIC_ALTAR_ANIMATION,
    LOOK_CURSOR_ANIMATION,
    KOBOLD_ANIMATION,
    LARGE_KOBOLD_ANIMATION,
    KOBOLD_LORD_ANIMATION,
    PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION,
    TWISTED_CANDLE_LIT_ANIMATION /* Keep this last */
};

#define NUM_ANIMATIONS TWISTED_CANDLE_LIT_ANIMATION

#define HANDCRAFTED_CANDLE_ANIMATION_OFF (0)
#define HANDCRAFTED_CANDLE_ANIMATION_FRAMES 1
#define PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_OFF (HANDCRAFTED_CANDLE_ANIMATION_FRAMES + HANDCRAFTED_CANDLE_ANIMATION_OFF)
#define PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_FRAMES 1
#define BRASS_LANTERN_LIT_ANIMATION_OFF (PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_FRAMES + PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_OFF)
#define BRASS_LANTERN_LIT_ANIMATION_FRAMES 1
#define LAWFUL_ALTAR_ANIMATION_OFF (BRASS_LANTERN_LIT_ANIMATION_FRAMES + BRASS_LANTERN_LIT_ANIMATION_OFF)
#define LAWFUL_ALTAR_ANIMATION_FRAMES 1
#define NEUTRAL_ALTAR_ANIMATION_OFF (LAWFUL_ALTAR_ANIMATION_FRAMES + LAWFUL_ALTAR_ANIMATION_OFF)
#define NEUTRAL_ALTAR_ANIMATION_FRAMES 1
#define CHAOTIC_ALTAR_ANIMATION_OFF (NEUTRAL_ALTAR_ANIMATION_FRAMES + NEUTRAL_ALTAR_ANIMATION_OFF)
#define CHAOTIC_ALTAR_ANIMATION_FRAMES 1
#define LOOK_CURSOR_ANIMATION_OFF (CHAOTIC_ALTAR_ANIMATION_FRAMES + CHAOTIC_ALTAR_ANIMATION_OFF)
#define LOOK_CURSOR_ANIMATION_FRAMES 3
#define KOBOLD_ANIMATION_OFF (LOOK_CURSOR_ANIMATION_FRAMES + LOOK_CURSOR_ANIMATION_OFF)
#define KOBOLD_ANIMATION_FRAMES 1
#define LARGE_KOBOLD_ANIMATION_OFF (KOBOLD_ANIMATION_FRAMES + KOBOLD_ANIMATION_OFF)
#define LARGE_KOBOLD_ANIMATION_FRAMES 1
#define KOBOLD_LORD_ANIMATION_OFF (LARGE_KOBOLD_ANIMATION_FRAMES + LARGE_KOBOLD_ANIMATION_OFF)
#define KOBOLD_LORD_ANIMATION_FRAMES 1
#define PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_OFF (KOBOLD_LORD_ANIMATION_FRAMES + KOBOLD_LORD_ANIMATION_OFF)
#define PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_FRAMES 4
#define TWISTED_CANDLE_ANIMATION_OFF (PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_FRAMES + PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_OFF)
#define TWISTED_CANDLE_ANIMATION_FRAMES 1

#define MAX_ANIMATION_FRAMES (TWISTED_CANDLE_ANIMATION_FRAMES + TWISTED_CANDLE_ANIMATION_OFF)

extern NEARDATA struct animation_definition animations[];


/* Replacements */
#define MAX_TILES_PER_REPLACEMENT 32

enum replacement_action_types
{
    REPLACEMENT_ACTION_NO_ACTION = 0,
    REPLACEMENT_ACTION_BOTTOM_TILE,
    REPLACEMENT_ACTION_OBJECT_LIT,
    REPLACEMENT_ACTION_LOCATION_LIT,
    REPLACEMENT_ACTION_COIN_QUANTITY,
    REPLACEMENT_ACTION_CHEST,
    REPLACEMENT_ACTION_LOCATION_HORIZONTAL,
    REPLACEMENT_ACTION_AUTODRAW
};


struct replacement_definition {
    char* replacement_name;
    char number_of_tiles;
    int glyph_offset;
    unsigned long replacement_events;
    enum replacement_action_types replacement_action; /* hard-coded - defines which tile to use and when */
    enum autodraw_types general_autodraw; /* For zero-tile replacements */
    char* tile_names[MAX_TILES_PER_REPLACEMENT];
    short tile_animation[MAX_TILES_PER_REPLACEMENT];
    short tile_enlargement[MAX_TILES_PER_REPLACEMENT];
    enum autodraw_types tile_autodraw[MAX_TILES_PER_REPLACEMENT];
};

#define REPLACEMENT_EVENT_NO_EVENT              0x00000000UL
#define REPLACEMENT_EVENT_UPDATE_FROM_BELOW     0x00000001UL
#define REPLACEMENT_EVENT_UPDATE_FROM_TOP       0x00000002UL
#define REPLACEMENT_EVENT_UPDATE_FROM_LEFT      0x00000004UL
#define REPLACEMENT_EVENT_UPDATE_FROM_RIGHT     0x00000008UL


enum replacement_types
{
    NO_REPLACEMENT = 0,
    DUNGEON_NORMAL_STONE_REPLACEMENT,
    DUNGEON_NORMAL_VWALL_REPLACEMENT,
    DUNGEON_NORMAL_CRWALL_REPLACEMENT,
    DUNGEON_NORMAL_TRWALL_REPLACEMENT,
    DUNGEON_NORMAL_TLWALL_REPLACEMENT,
    DUNGEON_NORMAL_TUWALL_REPLACEMENT,
    DUNGEON_NORMAL_TDWALL_REPLACEMENT,
    DUNGEON_NORMAL_HWALL_REPLACEMENT,
    DUNGEON_NORMAL_TLCORN_REPLACEMENT,
    DUNGEON_NORMAL_TRCORN_REPLACEMENT,
    DUNGEON_NORMAL_BLCORN_REPLACEMENT,
    DUNGEON_NORMAL_BRCORN_REPLACEMENT,
    COIN_REPLACEMENT,
    HANDCRAFTED_CANDLE_LIT_REPLACEMENT,
    TWISTED_CANDLE_LIT_REPLACEMENT,
    LAWFUL_ALTAR_REPLACEMENT,
    NEUTRAL_ALTAR_REPLACEMENT,
    CHAOTIC_ALTAR_REPLACEMENT,
    CHEST_REPLACEMENT,
    IRON_BAR_REPLACEMENT,
    BRASS_LANTERN_LIT_REPLACEMENT /* Keep this last */
};

#define NUM_REPLACEMENTS BRASS_LANTERN_LIT_REPLACEMENT

#define DUNGEON_NORMAL_STONE_REPLACEMENT_OFF (0)
#define DUNGEON_NORMAL_STONE_REPLACEMENT_TILES 1
//VWALL NO TILES
//CRWALL NO TILES
//TRWALL NO TILES
//TLWALL NO TILES
//TUWALL NO TILES
//TDWALL NO TILES
//HWALL NO TILES
#define COIN_REPLACEMENT_OFF (DUNGEON_NORMAL_STONE_REPLACEMENT_TILES + DUNGEON_NORMAL_STONE_REPLACEMENT_OFF)
#define COIN_REPLACEMENT_TILES 2
#define HANDCRAFTED_CANDLE_LIT_REPLACEMENT_OFF (COIN_REPLACEMENT_TILES + COIN_REPLACEMENT_OFF)
#define HANDCRAFTED_CANDLE_LIT_REPLACEMENT_TILES 1
#define TWISTED_CANDLE_LIT_REPLACEMENT_OFF (HANDCRAFTED_CANDLE_LIT_REPLACEMENT_TILES + HANDCRAFTED_CANDLE_LIT_REPLACEMENT_OFF)
#define TWISTED_CANDLE_LIT_REPLACEMENT_TILES 1
#define LAWFUL_ALTAR_REPLACEMENT_OFF (TWISTED_CANDLE_LIT_REPLACEMENT_TILES + TWISTED_CANDLE_LIT_REPLACEMENT_OFF)
#define LAWFUL_ALTAR_REPLACEMENT_TILES 1
#define NEUTRAL_ALTAR_REPLACEMENT_OFF (LAWFUL_ALTAR_REPLACEMENT_TILES + LAWFUL_ALTAR_REPLACEMENT_OFF)
#define NEUTRAL_ALTAR_REPLACEMENT_TILES 1
#define CHAOTIC_ALTAR_REPLACEMENT_OFF (NEUTRAL_ALTAR_REPLACEMENT_TILES + NEUTRAL_ALTAR_REPLACEMENT_OFF)
#define CHAOTIC_ALTAR_REPLACEMENT_TILES 1
#define CHEST_REPLACEMENT_OFF (CHAOTIC_ALTAR_REPLACEMENT_TILES + CHAOTIC_ALTAR_REPLACEMENT_OFF)
#define CHEST_REPLACEMENT_TILES 2
#define IRON_BAR_REPLACEMENT_OFF (CHEST_REPLACEMENT_TILES + CHEST_REPLACEMENT_OFF)
#define IRON_BAR_REPLACEMENT_TILES 1
#define BRASS_LANTERN_LIT_OFF (IRON_BAR_REPLACEMENT_TILES + IRON_BAR_REPLACEMENT_OFF)
#define BRASS_LANTERN_LIT_TILES 1
#define MAX_REPLACEMENT_TILES (BRASS_LANTERN_LIT_TILES + BRASS_LANTERN_LIT_OFF)

extern NEARDATA struct replacement_definition replacements[];





#endif /* ANIMATION_H */
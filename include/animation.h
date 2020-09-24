/*
 * animation.h
 * Copyright 2020 by Janne Gustafsson
 */
#include "general.h"
#include "action.h"

#ifndef ANIMATION_H
#define ANIMATION_H



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
    AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_LEFT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_ALL,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_LEFT_RIGHT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_DOWN,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_DOWN_LEFT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_DOWN_RIGHT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_LEFT_RIGHT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_DOWN_LEFT_RIGHT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_DOWN_RIGHT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_DOWN_LEFT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_RIGHT,
    AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_LEFT
};

#define NUM_AUTODRAWS AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_LEFT

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
    char number_of_tile_animations;
    int intervals_between_frames;
    enum animation_play_types play_type;
    enum main_tile_use_types main_tile_use_style; /* 0 = play as first tile and frame, 1 = play as last tile and frame, 2 = ignore */
    enum autodraw_types  main_tile_autodraw;
    char frame2tile[MAX_FRAMES_PER_ANIMATION];
    char sound_play_frame;
    char action_execution_frame;
    short tile_enlargement; /* Animations always use the same single enlargement */
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
    ALTAR_OF_MOLOCH_ANIMATION,
    HIGH_ALTAR_ANIMATION,
    LOOK_CURSOR_ANIMATION,
    KOBOLD_ANIMATION,
    LARGE_KOBOLD_ANIMATION,
    KOBOLD_LORD_ANIMATION,
    PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION,
    DRACOLICH_ATTACK_ANIMATION,
    MAGIC_FOUNTAIN_ANIMATION,
    FOUNTAIN_OF_HEALING_ANIMATION,
    FOUNTAIN_OF_MANA_ANIMATION,
    FOUNTAIN_OF_POWER_ANIMATION,
    FOUNTAIN_OF_POISON_ANIMATION,
    FOUNTAIN_OF_WATER_ANIMATION,
    HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION,
    HUMAN_KNIGHT_FEMALE_KICK_ANIMATION,
    HUMAN_KNIGHT_FEMALE_CAST_ANIMATION,
    ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION,
    ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION,
    ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION,
    DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION,
    DWARF_KNIGHT_FEMALE_KICK_ANIMATION,
    ORC_ROGUE_FEMALE_ATTACK_ANIMATION,
    ORC_ROGUE_FEMALE_KICK_ANIMATION,
    HUMAN_TOURIST_MALE_ATTACK_ANIMATION,
    HUMAN_TOURIST_MALE_KICK_ANIMATION,
    ELF_RANGER_MALE_FIRE_ANIMATION,
    ELF_RANGER_MALE_KICK_ANIMATION,
    GNOLL_HEALER_MALE_ATTACK_ANIMATION,
    GNOLL_HEALER_MALE_KICK_ANIMATION,
    DUST_VORTEX_SWALLOW_ANIMATION,
    FIERY_EXPLOSION_ANIMATION,
    GENERIC_SPELL_EFFECT_ANIMATION,
    TWISTED_CANDLE_LIT_ANIMATION,
    VIBRATING_SQUARE_ANIMATION /* Keep this last */
};

#define NUM_ANIMATIONS VIBRATING_SQUARE_ANIMATION

#define HANDCRAFTED_CANDLE_ANIMATION_OFF (0)
#define HANDCRAFTED_CANDLE_ANIMATION_FRAMES 1
#define HANDCRAFTED_CANDLE_ANIMATION_TILES 1
#define PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_OFF (HANDCRAFTED_CANDLE_ANIMATION_FRAMES + HANDCRAFTED_CANDLE_ANIMATION_OFF)
#define PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_FRAMES 1
#define PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_TILES 1
#define BRASS_LANTERN_LIT_ANIMATION_OFF (PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_FRAMES + PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_OFF)
#define BRASS_LANTERN_LIT_ANIMATION_FRAMES 1
#define BRASS_LANTERN_LIT_ANIMATION_TILES 1
#define LAWFUL_ALTAR_ANIMATION_OFF (BRASS_LANTERN_LIT_ANIMATION_FRAMES + BRASS_LANTERN_LIT_ANIMATION_OFF)
#define LAWFUL_ALTAR_ANIMATION_FRAMES 1
#define LAWFUL_ALTAR_ANIMATION_TILES 1
#define NEUTRAL_ALTAR_ANIMATION_OFF (LAWFUL_ALTAR_ANIMATION_FRAMES + LAWFUL_ALTAR_ANIMATION_OFF)
#define NEUTRAL_ALTAR_ANIMATION_FRAMES 1
#define NEUTRAL_ALTAR_ANIMATION_TILES 1
#define CHAOTIC_ALTAR_ANIMATION_OFF (NEUTRAL_ALTAR_ANIMATION_FRAMES + NEUTRAL_ALTAR_ANIMATION_OFF)
#define CHAOTIC_ALTAR_ANIMATION_FRAMES 1
#define CHAOTIC_ALTAR_ANIMATION_TILES 1
#define ALTAR_OF_MOLOCH_ANIMATION_OFF (CHAOTIC_ALTAR_ANIMATION_FRAMES + CHAOTIC_ALTAR_ANIMATION_OFF)
#define ALTAR_OF_MOLOCH_ANIMATION_FRAMES 1
#define ALTAR_OF_MOLOCH_ANIMATION_TILES 1
#define HIGH_ALTAR_ANIMATION_OFF (ALTAR_OF_MOLOCH_ANIMATION_FRAMES + ALTAR_OF_MOLOCH_ANIMATION_OFF)
#define HIGH_ALTAR_ANIMATION_FRAMES 1
#define HIGH_ALTAR_ANIMATION_TILES 1
#define LOOK_CURSOR_ANIMATION_OFF (HIGH_ALTAR_ANIMATION_FRAMES + HIGH_ALTAR_ANIMATION_OFF)
#define LOOK_CURSOR_ANIMATION_FRAMES 3
#define LOOK_CURSOR_ANIMATION_TILES 2
#define KOBOLD_ANIMATION_OFF (LOOK_CURSOR_ANIMATION_FRAMES + LOOK_CURSOR_ANIMATION_OFF)
#define KOBOLD_ANIMATION_FRAMES 1
#define KOBOLD_ANIMATION_TILES 1
#define LARGE_KOBOLD_ANIMATION_OFF (KOBOLD_ANIMATION_FRAMES + KOBOLD_ANIMATION_OFF)
#define LARGE_KOBOLD_ANIMATION_FRAMES 1
#define LARGE_KOBOLD_ANIMATION_TILES 1
#define KOBOLD_LORD_ANIMATION_OFF (LARGE_KOBOLD_ANIMATION_FRAMES + LARGE_KOBOLD_ANIMATION_OFF)
#define KOBOLD_LORD_ANIMATION_FRAMES 1
#define KOBOLD_LORD_ANIMATION_TILES 1
#define PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_OFF (KOBOLD_LORD_ANIMATION_FRAMES + KOBOLD_LORD_ANIMATION_OFF)
#define PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_FRAMES 4
#define PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_TILES 4
#define DRACOLICH_ATTACK_ANIMATION_OFF (PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_FRAMES + PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_OFF)
#define DRACOLICH_ATTACK_ANIMATION_FRAMES 4
#define DRACOLICH_ATTACK_ANIMATION_TILES 4
#define MAGIC_FOUNTAIN_ANIMATION_OFF (DRACOLICH_ATTACK_ANIMATION_FRAMES + DRACOLICH_ATTACK_ANIMATION_OFF)
#define MAGIC_FOUNTAIN_ANIMATION_FRAMES 1
#define MAGIC_FOUNTAIN_ANIMATION_TILES 1
#define FOUNTAIN_OF_HEALING_ANIMATION_OFF (MAGIC_FOUNTAIN_ANIMATION_FRAMES + MAGIC_FOUNTAIN_ANIMATION_OFF)
#define FOUNTAIN_OF_HEALING_ANIMATION_FRAMES 1
#define FOUNTAIN_OF_HEALING_ANIMATION_TILES 1
#define FOUNTAIN_OF_MANA_ANIMATION_OFF (FOUNTAIN_OF_HEALING_ANIMATION_FRAMES + FOUNTAIN_OF_HEALING_ANIMATION_OFF)
#define FOUNTAIN_OF_MANA_ANIMATION_FRAMES 1
#define FOUNTAIN_OF_MANA_ANIMATION_TILES 1
#define FOUNTAIN_OF_POWER_ANIMATION_OFF (FOUNTAIN_OF_MANA_ANIMATION_FRAMES + FOUNTAIN_OF_MANA_ANIMATION_OFF)
#define FOUNTAIN_OF_POWER_ANIMATION_FRAMES 1
#define FOUNTAIN_OF_POWER_ANIMATION_TILES 1
#define FOUNTAIN_OF_POISON_ANIMATION_OFF (FOUNTAIN_OF_POWER_ANIMATION_FRAMES + FOUNTAIN_OF_POWER_ANIMATION_OFF)
#define FOUNTAIN_OF_POISON_ANIMATION_FRAMES 1
#define FOUNTAIN_OF_POISON_ANIMATION_TILES 1
#define FOUNTAIN_OF_WATER_ANIMATION_OFF (FOUNTAIN_OF_POISON_ANIMATION_FRAMES + FOUNTAIN_OF_POISON_ANIMATION_OFF)
#define FOUNTAIN_OF_WATER_ANIMATION_FRAMES 1
#define FOUNTAIN_OF_WATER_ANIMATION_TILES 1
#define HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_OFF (FOUNTAIN_OF_WATER_ANIMATION_FRAMES + FOUNTAIN_OF_WATER_ANIMATION_OFF)
#define HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES 9
#define HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_TILES 9
#define HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_OFF (HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES + HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_OFF)
#define HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES 11
#define HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_TILES 11
#define HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_OFF (HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES + HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_OFF)
#define HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_FRAMES 13
#define HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_TILES 13
#define ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_OFF (HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_FRAMES + HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_OFF)
#define ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_FRAMES 16
#define ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_TILES 16
#define ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_OFF (ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_FRAMES + ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_OFF)
#define ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_FRAMES 9
#define ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_TILES 9
#define ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_OFF (ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_FRAMES + ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_OFF)
#define ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_FRAMES 12
#define ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_TILES 12
#define DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_OFF (ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_FRAMES + ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_OFF)
#define DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES 10
#define DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_TILES 10
#define DWARF_KNIGHT_FEMALE_KICK_ANIMATION_OFF (DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES + DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_OFF)
#define DWARF_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES 9
#define DWARF_KNIGHT_FEMALE_KICK_ANIMATION_TILES 9
#define ORC_ROGUE_FEMALE_ATTACK_ANIMATION_OFF (DWARF_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES + DWARF_KNIGHT_FEMALE_KICK_ANIMATION_OFF)
#define ORC_ROGUE_FEMALE_ATTACK_ANIMATION_FRAMES 9
#define ORC_ROGUE_FEMALE_ATTACK_ANIMATION_TILES 9
#define ORC_ROGUE_FEMALE_KICK_ANIMATION_OFF (ORC_ROGUE_FEMALE_ATTACK_ANIMATION_FRAMES + ORC_ROGUE_FEMALE_ATTACK_ANIMATION_OFF)
#define ORC_ROGUE_FEMALE_KICK_ANIMATION_FRAMES 9
#define ORC_ROGUE_FEMALE_KICK_ANIMATION_TILES 9
#define HUMAN_TOURIST_MALE_ATTACK_ANIMATION_OFF (ORC_ROGUE_FEMALE_KICK_ANIMATION_FRAMES + ORC_ROGUE_FEMALE_KICK_ANIMATION_OFF)
#define HUMAN_TOURIST_MALE_ATTACK_ANIMATION_FRAMES 11
#define HUMAN_TOURIST_MALE_ATTACK_ANIMATION_TILES 11
#define HUMAN_TOURIST_MALE_KICK_ANIMATION_OFF (HUMAN_TOURIST_MALE_ATTACK_ANIMATION_FRAMES + HUMAN_TOURIST_MALE_ATTACK_ANIMATION_OFF)
#define HUMAN_TOURIST_MALE_KICK_ANIMATION_FRAMES 9
#define HUMAN_TOURIST_MALE_KICK_ANIMATION_TILES 9
#define ELF_RANGER_MALE_FIRE_ANIMATION_OFF (HUMAN_TOURIST_MALE_KICK_ANIMATION_FRAMES + HUMAN_TOURIST_MALE_KICK_ANIMATION_OFF)
#define ELF_RANGER_MALE_FIRE_ANIMATION_FRAMES 22
#define ELF_RANGER_MALE_FIRE_ANIMATION_TILES 22
#define ELF_RANGER_MALE_KICK_ANIMATION_OFF (ELF_RANGER_MALE_FIRE_ANIMATION_FRAMES + ELF_RANGER_MALE_FIRE_ANIMATION_OFF)
#define ELF_RANGER_MALE_KICK_ANIMATION_FRAMES 10
#define ELF_RANGER_MALE_KICK_ANIMATION_TILES 10
#define GNOLL_HEALER_MALE_ATTACK_ANIMATION_OFF (ELF_RANGER_MALE_KICK_ANIMATION_FRAMES + ELF_RANGER_MALE_KICK_ANIMATION_OFF)
#define GNOLL_HEALER_MALE_ATTACK_ANIMATION_FRAMES 9
#define GNOLL_HEALER_MALE_ATTACK_ANIMATION_TILES 9
#define GNOLL_HEALER_MALE_KICK_ANIMATION_OFF (GNOLL_HEALER_MALE_ATTACK_ANIMATION_FRAMES + GNOLL_HEALER_MALE_ATTACK_ANIMATION_OFF)
#define GNOLL_HEALER_MALE_KICK_ANIMATION_FRAMES 9
#define GNOLL_HEALER_MALE_KICK_ANIMATION_TILES 9
#define DUST_VORTEX_SWALLOW_ANIMATION_OFF (GNOLL_HEALER_MALE_KICK_ANIMATION_FRAMES + GNOLL_HEALER_MALE_KICK_ANIMATION_OFF)
#define DUST_VORTEX_SWALLOW_ANIMATION_FRAMES 3
#define DUST_VORTEX_SWALLOW_ANIMATION_TILES 3 
#define FIERY_EXPLOSION_ANIMATION_OFF (DUST_VORTEX_SWALLOW_ANIMATION_FRAMES * MAX_SWALLOW_CHARS + DUST_VORTEX_SWALLOW_ANIMATION_OFF)
#define FIERY_EXPLOSION_ANIMATION_FRAMES 3
#define FIERY_EXPLOSION_ANIMATION_TILES 3 
#define GENERIC_SPELL_EFFECT_ANIMATION_OFF (FIERY_EXPLOSION_ANIMATION_FRAMES * MAX_EXPLOSION_CHARS + FIERY_EXPLOSION_ANIMATION_OFF)
#define GENERIC_SPELL_EFFECT_ANIMATION_FRAMES 3
#define GENERIC_SPELL_EFFECT_ANIMATION_TILES 2
#define TWISTED_CANDLE_ANIMATION_OFF (GENERIC_SPELL_EFFECT_ANIMATION_FRAMES + GENERIC_SPELL_EFFECT_ANIMATION_OFF)
#define TWISTED_CANDLE_ANIMATION_FRAMES 1
#define TWISTED_CANDLE_ANIMATION_TILES 1
#define VIBRATING_SQUARE_ANIMATION_OFF (TWISTED_CANDLE_ANIMATION_FRAMES + TWISTED_CANDLE_ANIMATION_OFF)
#define VIBRATING_SQUARE_ANIMATION_FRAMES 1
#define VIBRATING_SQUARE_ANIMATION_TILES 1

#define TOTAL_ANIMATION_FRAMES (VIBRATING_SQUARE_ANIMATION_FRAMES + VIBRATING_SQUARE_ANIMATION_OFF)

extern NEARDATA struct animation_definition animations[];


/* Enlargement sets */
#define NUM_POSITIONS_IN_ENLARGEMENT 5

struct enlargement_definition {
    char* enlargement_name;
    char number_of_animation_tiles;
    char number_of_animation_frames;
    char number_of_enlargement_tiles;
    int glyph_offset;
    char width_in_tiles;
    char height_in_tiles;
    char main_tile_x_coordinate; /* Always 0 or 1 on the last row */
    char position2tile[NUM_POSITIONS_IN_ENLARGEMENT];
    /* Enlargement position is index in the array: number from 0 to 4, X = -1 indicates main tile
            0 1 2
            3 X 4
       Value of -1 indicates the tile does not ex�st, a nonnegative value indicates tile number used for the position
    */
    char position_flags[NUM_POSITIONS_IN_ENLARGEMENT];
    enum autodraw_types position_autodraw[NUM_POSITIONS_IN_ENLARGEMENT];
};

#define ENLFLAGS_H_FLIP 0x01


enum enlargement_types
{
    NO_ENLARGEMENT = 0,
    DRACOLICH_ENLARGEMENT,
    DRACOLICH_STATUE_ENLARGEMENT,
    BALROG_ENLARGEMENT,
    BALROG_STATUE_ENLARGEMENT,
    BALROG_PASSIVE_DEFENSE_ENLARGEMENT,
    TREE_ENLARGEMENT,
    DUNGEON_NORMAL_UPSTAIRS_ENLARGEMENT,
    DUNGEON_NORMAL_BRANCH_UPSTAIRS_ENLARGEMENT,
    DUNGEON_NORMAL_SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT,
    HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT,
    HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT,
    HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT,
    ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT,
    ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT,
    ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT,
    DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT,
    DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT,
    ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT,
    ORC_ROGUE_FEMALE_KICK_ENLARGEMENT,
    HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT,
    HUMAN_TOURIST_MALE_KICK_ENLARGEMENT,
    ELF_RANGER_MALE_FIRE_ENLARGEMENT,
    ELF_RANGER_MALE_KICK_ENLARGEMENT,
    GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT,
    GNOLL_HEALER_MALE_KICK_ENLARGEMENT,
    PONY_ENLARGEMENT,
    PONY_STATUE_ENLARGEMENT,
    HORSE_ENLARGEMENT,
    HORSE_STATUE_ENLARGEMENT,
    WARHORSE_ENLARGEMENT,
    WARHORSE_STATUE_ENLARGEMENT,
    DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT,
    DRACOLICH_ATTACK_ENLARGEMENT /* Keep this last */
};

#define NUM_ENLARGEMENTS DRACOLICH_ATTACK_ENLARGEMENT

#define DRACOLICH_ENLARGEMENT_OFF (0)
#define DRACOLICH_ENLARGEMENT_TILES 5

#define DRACOLICH_STATUE_ENLARGEMENT_OFF (DRACOLICH_ENLARGEMENT_TILES + DRACOLICH_ENLARGEMENT_OFF)
#define DRACOLICH_STATUE_ENLARGEMENT_TILES 5

#define BALROG_ENLARGEMENT_OFF (DRACOLICH_STATUE_ENLARGEMENT_TILES + DRACOLICH_STATUE_ENLARGEMENT_OFF)
#define BALROG_ENLARGEMENT_TILES 5

#define BALROG_STATUE_ENLARGEMENT_OFF (BALROG_ENLARGEMENT_TILES + BALROG_ENLARGEMENT_OFF)
#define BALROG_STATUE_ENLARGEMENT_TILES 5

#define BALROG_PASSIVE_DEFENSE_ENLARGEMENT_OFF (BALROG_STATUE_ENLARGEMENT_TILES + BALROG_STATUE_ENLARGEMENT_OFF)
#define BALROG_PASSIVE_DEFENSE_ENLARGEMENT_TILES 5

#define TREE_ENLARGEMENT_OFF (BALROG_PASSIVE_DEFENSE_ENLARGEMENT_TILES + BALROG_PASSIVE_DEFENSE_ENLARGEMENT_OFF)
#define TREE_ENLARGEMENT_TILES 5

#define UPSTAIRS_ENLARGEMENT_OFF (TREE_ENLARGEMENT_TILES + TREE_ENLARGEMENT_OFF)
#define UPSTAIRS_ENLARGEMENT_TILES 1

#define BRANCH_UPSTAIRS_ENLARGEMENT_OFF (UPSTAIRS_ENLARGEMENT_TILES + UPSTAIRS_ENLARGEMENT_OFF)
#define BRANCH_UPSTAIRS_ENLARGEMENT_TILES 1

#define SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_OFF (BRANCH_UPSTAIRS_ENLARGEMENT_TILES + BRANCH_UPSTAIRS_ENLARGEMENT_OFF)
#define SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_TILES 1

#define HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_OFF (SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_TILES + SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_OFF)
#define HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_TILES 2

#define HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT_OFF (HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_TILES * HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES + HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_OFF)
#define HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT_TILES 2

#define HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT_OFF (HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT_TILES * HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES + HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT_OFF)
#define HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT_TILES 1

#define ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT_OFF (HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT_TILES * HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_FRAMES + HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT_OFF)
#define ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT_TILES 2

#define ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT_OFF (ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT_TILES * ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_FRAMES + ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT_OFF)
#define ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT_TILES 2

#define ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT_OFF (ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT_TILES * ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_FRAMES + ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT_OFF)
#define ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT_TILES 2

#define DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_OFF (ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT_TILES * ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_FRAMES + ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT_OFF)
#define DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_TILES 2

#define DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT_OFF (DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_TILES * DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES + DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_OFF)
#define DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT_TILES 2

#define ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT_OFF (DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT_TILES * DWARF_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES + DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT_OFF)
#define ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT_TILES 2

#define ORC_ROGUE_FEMALE_KICK_ENLARGEMENT_OFF (ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT_TILES * ORC_ROGUE_FEMALE_ATTACK_ANIMATION_FRAMES + ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT_OFF)
#define ORC_ROGUE_FEMALE_KICK_ENLARGEMENT_TILES 2

#define HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT_OFF (ORC_ROGUE_FEMALE_KICK_ENLARGEMENT_TILES * ORC_ROGUE_FEMALE_KICK_ANIMATION_FRAMES + ORC_ROGUE_FEMALE_KICK_ENLARGEMENT_OFF)
#define HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT_TILES 2

#define HUMAN_TOURIST_MALE_KICK_ENLARGEMENT_OFF (HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT_TILES * HUMAN_TOURIST_MALE_ATTACK_ANIMATION_FRAMES + HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT_OFF)
#define HUMAN_TOURIST_MALE_KICK_ENLARGEMENT_TILES 2

#define ELF_RANGER_MALE_FIRE_ENLARGEMENT_OFF (HUMAN_TOURIST_MALE_KICK_ENLARGEMENT_TILES * HUMAN_TOURIST_MALE_KICK_ANIMATION_FRAMES + HUMAN_TOURIST_MALE_KICK_ENLARGEMENT_OFF)
#define ELF_RANGER_MALE_FIRE_ENLARGEMENT_TILES 2

#define ELF_RANGER_MALE_KICK_ENLARGEMENT_OFF (ELF_RANGER_MALE_FIRE_ENLARGEMENT_TILES * ELF_RANGER_MALE_FIRE_ANIMATION_FRAMES + ELF_RANGER_MALE_FIRE_ENLARGEMENT_OFF)
#define ELF_RANGER_MALE_KICK_ENLARGEMENT_TILES 2

#define GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT_OFF (ELF_RANGER_MALE_KICK_ENLARGEMENT_TILES * ELF_RANGER_MALE_KICK_ANIMATION_FRAMES + ELF_RANGER_MALE_KICK_ENLARGEMENT_OFF)
#define GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT_TILES 2

#define GNOLL_HEALER_MALE_KICK_ENLARGEMENT_OFF (GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT_TILES * GNOLL_HEALER_MALE_ATTACK_ANIMATION_FRAMES + GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT_OFF)
#define GNOLL_HEALER_MALE_KICK_ENLARGEMENT_TILES 2

#define PONY_ENLARGEMENT_OFF (GNOLL_HEALER_MALE_KICK_ENLARGEMENT_TILES * GNOLL_HEALER_MALE_KICK_ANIMATION_FRAMES + GNOLL_HEALER_MALE_KICK_ENLARGEMENT_OFF)
#define PONY_ENLARGEMENT_TILES 1

#define PONY_STATUE_ENLARGEMENT_OFF (PONY_ENLARGEMENT_TILES + PONY_ENLARGEMENT_OFF)
#define PONY_STATUE_ENLARGEMENT_TILES 1

#define HORSE_ENLARGEMENT_OFF (PONY_STATUE_ENLARGEMENT_TILES + PONY_STATUE_ENLARGEMENT_OFF)
#define HORSE_ENLARGEMENT_TILES 1

#define HORSE_STATUE_ENLARGEMENT_OFF (HORSE_ENLARGEMENT_TILES + HORSE_ENLARGEMENT_OFF)
#define HORSE_STATUE_ENLARGEMENT_TILES 1

#define WARHORSE_ENLARGEMENT_OFF (HORSE_STATUE_ENLARGEMENT_TILES + HORSE_STATUE_ENLARGEMENT_OFF)
#define WARHORSE_ENLARGEMENT_TILES 1

#define WARHORSE_STATUE_ENLARGEMENT_OFF (WARHORSE_ENLARGEMENT_TILES + WARHORSE_ENLARGEMENT_OFF)
#define WARHORSE_STATUE_ENLARGEMENT_TILES 1

#define DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT_OFF (WARHORSE_STATUE_ENLARGEMENT_TILES + WARHORSE_STATUE_ENLARGEMENT_OFF)
#define DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT_TILES 1

#define DRACOLICH_ATTACK_ENLARGEMENT_OFF (DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT_TILES + DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT_OFF)
#define DRACOLICH_ATTACK_ENLARGEMENT_TILES 5


#define TOTAL_ENLARGEMENT_TILES (DRACOLICH_ATTACK_ENLARGEMENT_TILES * DRACOLICH_ATTACK_ANIMATION_FRAMES + DRACOLICH_ATTACK_ENLARGEMENT_OFF)

extern NEARDATA struct enlargement_definition enlargements[];


/* Replacements */
#define MAX_TILES_PER_REPLACEMENT 32

enum replacement_action_types
{
    REPLACEMENT_ACTION_NO_ACTION = 0,
    REPLACEMENT_ACTION_BOTTOM_TILE,
    REPLACEMENT_ACTION_SHORE_TILE,
    REPLACEMENT_ACTION_SHORE_ADJUSTED_TILE,
    REPLACEMENT_ACTION_FLOOR_ADJUSTED_TILE,
    REPLACEMENT_ACTION_SHORE_AND_FLOOR_ADJUSTED_TILE,
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
    ALTAR_OF_MOLOCH_REPLACEMENT,
    HIGH_ALTAR_REPLACEMENT,
    CHEST_REPLACEMENT,
    DUNGEON_NORMAL_IRON_BAR_REPLACEMENT,
    DUNGEON_NORMAL_WATER_REPLACEMENT,
    DUNGEON_NORMAL_ICE_REPLACEMENT,
    DUNGEON_NORMAL_LAVA_REPLACEMENT,
    DUNGEON_NORMAL_ROOM_REPLACEMENT,
    DUNGEON_NORMAL_GRASS_REPLACEMENT,
    DUNGEON_NORMAL_GRASS_SWAMPY_REPLACEMENT,
    DUNGEON_NORMAL_GROUND_REPLACEMENT,
    DUNGEON_NORMAL_STAIRS_UP_REPLACEMENT,
    DUNGEON_NORMAL_STAIRS_DOWN_REPLACEMENT,
    DUNGEON_NORMAL_TRAPDOOR_REPLACEMENT,
    DUNGEON_NORMAL_HOLE_REPLACEMENT,
    DUNGEON_NORMAL_PIT_REPLACEMENT,
    DUNGEON_NORMAL_SPIKED_PIT_REPLACEMENT,
    GNOMISH_MINES_STONE_REPLACEMENT,
    GNOMISH_MINES_VWALL_REPLACEMENT,
    GNOMISH_MINES_CRWALL_REPLACEMENT,
    GNOMISH_MINES_TRWALL_REPLACEMENT,
    GNOMISH_MINES_TLWALL_REPLACEMENT,
    GNOMISH_MINES_TUWALL_REPLACEMENT,
    GNOMISH_MINES_TDWALL_REPLACEMENT,
    GNOMISH_MINES_HWALL_REPLACEMENT,
    GNOMISH_MINES_TLCORN_REPLACEMENT,
    GNOMISH_MINES_TRCORN_REPLACEMENT,
    GNOMISH_MINES_BLCORN_REPLACEMENT,
    GNOMISH_MINES_BRCORN_REPLACEMENT,
    GNOMISH_MINES_IRON_BAR_REPLACEMENT,
    GEHENNOM_STONE_REPLACEMENT,
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
#define ALTAR_OF_MOLOCH_REPLACEMENT_OFF (CHAOTIC_ALTAR_REPLACEMENT_TILES + CHAOTIC_ALTAR_REPLACEMENT_OFF)
#define ALTAR_OF_MOLOCH_REPLACEMENT_TILES 1
#define HIGH_ALTAR_REPLACEMENT_OFF (ALTAR_OF_MOLOCH_REPLACEMENT_TILES + ALTAR_OF_MOLOCH_REPLACEMENT_OFF)
#define HIGH_ALTAR_REPLACEMENT_TILES 1
#define CHEST_REPLACEMENT_OFF (HIGH_ALTAR_REPLACEMENT_TILES + HIGH_ALTAR_REPLACEMENT_OFF)
#define CHEST_REPLACEMENT_TILES 2
#define DUNGEON_NORMAL_IRON_BAR_REPLACEMENT_OFF (CHEST_REPLACEMENT_TILES + CHEST_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_IRON_BAR_REPLACEMENT_TILES 1
#define DUNGEON_NORMAL_WATER_REPLACEMENT_OFF (DUNGEON_NORMAL_IRON_BAR_REPLACEMENT_TILES + DUNGEON_NORMAL_IRON_BAR_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_WATER_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4)
#define DUNGEON_NORMAL_ICE_REPLACEMENT_OFF (DUNGEON_NORMAL_WATER_REPLACEMENT_TILES + DUNGEON_NORMAL_WATER_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_ICE_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4)
#define DUNGEON_NORMAL_LAVA_REPLACEMENT_OFF (DUNGEON_NORMAL_ICE_REPLACEMENT_TILES + DUNGEON_NORMAL_ICE_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_LAVA_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4)
#define DUNGEON_NORMAL_ROOM_REPLACEMENT_OFF (DUNGEON_NORMAL_LAVA_REPLACEMENT_TILES + DUNGEON_NORMAL_LAVA_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_ROOM_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4)
#define DUNGEON_NORMAL_GRASS_REPLACEMENT_OFF (DUNGEON_NORMAL_ROOM_REPLACEMENT_TILES + DUNGEON_NORMAL_ROOM_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_GRASS_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4)
#define DUNGEON_NORMAL_GRASS_SWAMPY_REPLACEMENT_OFF (DUNGEON_NORMAL_GRASS_REPLACEMENT_TILES + DUNGEON_NORMAL_GRASS_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_GRASS_SWAMPY_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4)
#define DUNGEON_NORMAL_GROUND_REPLACEMENT_OFF (DUNGEON_NORMAL_GRASS_SWAMPY_REPLACEMENT_TILES + DUNGEON_NORMAL_GRASS_SWAMPY_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_GROUND_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4)
#define DUNGEON_NORMAL_STAIRS_UP_REPLACEMENT_OFF (DUNGEON_NORMAL_GROUND_REPLACEMENT_TILES + DUNGEON_NORMAL_GROUND_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_STAIRS_UP_REPLACEMENT_TILES (1)
#define DUNGEON_NORMAL_STAIRS_DOWN_REPLACEMENT_OFF (DUNGEON_NORMAL_STAIRS_UP_REPLACEMENT_TILES + DUNGEON_NORMAL_STAIRS_UP_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_STAIRS_DOWN_REPLACEMENT_TILES ((MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES) * 2)
#define DUNGEON_NORMAL_TRAPDOOR_REPLACEMENT_OFF (DUNGEON_NORMAL_STAIRS_DOWN_REPLACEMENT_TILES + DUNGEON_NORMAL_STAIRS_DOWN_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_TRAPDOOR_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES)
#define DUNGEON_NORMAL_HOLE_REPLACEMENT_OFF (DUNGEON_NORMAL_TRAPDOOR_REPLACEMENT_TILES + DUNGEON_NORMAL_TRAPDOOR_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_HOLE_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES)
#define DUNGEON_NORMAL_PIT_REPLACEMENT_OFF (DUNGEON_NORMAL_HOLE_REPLACEMENT_TILES + DUNGEON_NORMAL_HOLE_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_PIT_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES)
#define DUNGEON_NORMAL_SPIKED_PIT_REPLACEMENT_OFF (DUNGEON_NORMAL_PIT_REPLACEMENT_TILES + DUNGEON_NORMAL_PIT_REPLACEMENT_OFF)
#define DUNGEON_NORMAL_SPIKED_PIT_REPLACEMENT_TILES (MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES)
#define GNOMISH_MINES_STONE_REPLACEMENT_OFF (DUNGEON_NORMAL_SPIKED_PIT_REPLACEMENT_TILES + DUNGEON_NORMAL_SPIKED_PIT_REPLACEMENT_OFF)
#define GNOMISH_MINES_STONE_REPLACEMENT_TILES 1
//VWALL NO TILES
//CRWALL NO TILES
//TRWALL NO TILES
//TLWALL NO TILES
//TUWALL NO TILES
//TDWALL NO TILES
//HWALL NO TILES
#define GNOMISH_MINES_IRON_BAR_REPLACEMENT_OFF (GNOMISH_MINES_STONE_REPLACEMENT_TILES + GNOMISH_MINES_STONE_REPLACEMENT_OFF)
#define GNOMISH_MINES_IRON_BAR_REPLACEMENT_TILES 1
#define GEHENNOM_STONE_REPLACEMENT_OFF (GNOMISH_MINES_IRON_BAR_REPLACEMENT_TILES + GNOMISH_MINES_IRON_BAR_REPLACEMENT_OFF)
#define GEHENNOM_STONE_REPLACEMENT_TILES 1
#define BRASS_LANTERN_LIT_OFF (GEHENNOM_STONE_REPLACEMENT_TILES + GEHENNOM_STONE_REPLACEMENT_OFF)
#define BRASS_LANTERN_LIT_TILES 1
#define TOTAL_REPLACEMENT_TILES (BRASS_LANTERN_LIT_TILES + BRASS_LANTERN_LIT_OFF)

extern NEARDATA struct replacement_definition replacements[];


/* Special effects */
enum special_effect_types
{
    SPECIAL_EFFECT_TELEPORT_OUT = 0,
    SPECIAL_EFFECT_TELEPORT_IN,
    SPECIAL_EFFECT_GENERIC_SPELL,
    MAX_SPECIAL_EFFECTS
};

struct special_effect_definition {
    const char* name;
    int display_time; /* in milliseconds, 0 indicates delay_output */
    enum replacement_types replacement;
    enum animation_types animation;
    enum enlargement_types enlargement;
};

extern NEARDATA struct special_effect_definition special_effects[MAX_SPECIAL_EFFECTS];


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
    CURSOR_STYLE_INVISIBLE,
    MAX_CURSORS
};

struct game_cursor_definition {
    const char* name;
    enum replacement_types replacement;
    enum animation_types animation;
    enum enlargement_types enlargement;
};


extern NEARDATA struct game_cursor_definition game_cursors[MAX_CURSORS];

#define MAX_PLAYED_SPECIAL_EFFECTS 4

#endif /* ANIMATION_H */
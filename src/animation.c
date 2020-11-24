/*
 * Copyright (c) Janne Gustafsson, 2020
 */
#include "hack.h"

NEARDATA struct animation_definition animations[MAX_ANIMATIONS] =
{
    { "", 0,
      0, 0, 
      0,
      0,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      0,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "handcrafted-candle-lit-animation", HANDCRAFTED_CANDLE_ANIMATION_TILES,
      HANDCRAFTED_CANDLE_ANIMATION_FRAMES, HANDCRAFTED_CANDLE_ANIMATION_OFF, 
      1, 
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      0, 0,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elf_wizard_female_cast-animation", PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_TILES,
      PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_FRAMES, PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "brass-lantern-lit-animation", BRASS_LANTERN_LIT_ANIMATION_TILES,
      BRASS_LANTERN_LIT_ANIMATION_FRAMES, BRASS_LANTERN_LIT_ANIMATION_OFF, 3,
      1,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "lawful-altar-animation", LAWFUL_ALTAR_ANIMATION_TILES,
      LAWFUL_ALTAR_ANIMATION_FRAMES, LAWFUL_ALTAR_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "neutral-altar-animation", NEUTRAL_ALTAR_ANIMATION_TILES,
      NEUTRAL_ALTAR_ANIMATION_FRAMES, NEUTRAL_ALTAR_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "chaotic-altar-animation", CHAOTIC_ALTAR_ANIMATION_TILES,
      CHAOTIC_ALTAR_ANIMATION_FRAMES, CHAOTIC_ALTAR_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "altar-of-moloch-animation", ALTAR_OF_MOLOCH_ANIMATION_TILES,
      ALTAR_OF_MOLOCH_ANIMATION_FRAMES, ALTAR_OF_MOLOCH_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "high-altar-animation", HIGH_ALTAR_ANIMATION_TILES,
      HIGH_ALTAR_ANIMATION_FRAMES, HIGH_ALTAR_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "look-cursor-animation", LOOK_CURSOR_ANIMATION_TILES,
      LOOK_CURSOR_ANIMATION_FRAMES, LOOK_CURSOR_ANIMATION_OFF, 
      1,
      7,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, -1, 1, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "kobold-animation", KOBOLD_ANIMATION_TILES,
      KOBOLD_ANIMATION_FRAMES, KOBOLD_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "large-kobold-animation", LARGE_KOBOLD_ANIMATION_TILES,
      LARGE_KOBOLD_ANIMATION_FRAMES, LARGE_KOBOLD_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "kobold-lord-animation", KOBOLD_LORD_ANIMATION_TILES,
      KOBOLD_LORD_ANIMATION_FRAMES, KOBOLD_LORD_ANIMATION_OFF,
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elf-wizard-female-kick-animation", PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_TILES,
      PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_FRAMES, PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION_OFF, 
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dracolich-attack-animation", DRACOLICH_ATTACK_ANIMATION_TILES,
      DRACOLICH_ATTACK_ANIMATION_FRAMES, DRACOLICH_ATTACK_ANIMATION_OFF, 
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      DRACOLICH_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "magic-fountain-animation", MAGIC_FOUNTAIN_ANIMATION_TILES,
        MAGIC_FOUNTAIN_ANIMATION_FRAMES, MAGIC_FOUNTAIN_ANIMATION_OFF, 
        1,
        2,
        ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        NO_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fountain-of-healing-animation", FOUNTAIN_OF_HEALING_ANIMATION_TILES,
        FOUNTAIN_OF_HEALING_ANIMATION_FRAMES, FOUNTAIN_OF_HEALING_ANIMATION_OFF, 
        1,
        2,
        ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        NO_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fountain-of-mana-animation", FOUNTAIN_OF_MANA_ANIMATION_TILES,
        FOUNTAIN_OF_MANA_ANIMATION_FRAMES, FOUNTAIN_OF_MANA_ANIMATION_OFF, 
        1,
        2,
        ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        NO_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fountain-of-power-animation", FOUNTAIN_OF_POWER_ANIMATION_TILES,
        FOUNTAIN_OF_POWER_ANIMATION_FRAMES, FOUNTAIN_OF_POWER_ANIMATION_OFF, 
        1,
        2,
        ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        NO_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fountain-of-poison-animation", FOUNTAIN_OF_MANA_ANIMATION_TILES,
        FOUNTAIN_OF_MANA_ANIMATION_FRAMES, FOUNTAIN_OF_MANA_ANIMATION_OFF, 
        1,
        2,
        ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        NO_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fountain-of-water-animation", FOUNTAIN_OF_WATER_ANIMATION_TILES,
        FOUNTAIN_OF_WATER_ANIMATION_FRAMES, FOUNTAIN_OF_WATER_ANIMATION_OFF, 
        1,
        2,
        ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        NO_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-knight-female-attack-animation", HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_TILES,
      HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES, HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_OFF, 
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      4, 7,
      HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-knight-female-kick-animation", HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_TILES,
        HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES, HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_OFF, 
        1,
        1,
        ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        2, 7,
        HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-knight-female-cast-animation", HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_TILES,
        HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_FRAMES, HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_OFF,
        1,
        2,
        ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-knight-male-attack-animation", HUMAN_KNIGHT_MALE_ATTACK_ANIMATION_TILES,
      HUMAN_KNIGHT_MALE_ATTACK_ANIMATION_FRAMES, HUMAN_KNIGHT_MALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      4, 7,
      HUMAN_KNIGHT_MALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elf-priest-male-chaotic-cast-animation", ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_TILES,
        ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_FRAMES, ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_OFF,
        1,
        2,
        ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elf-priest-male-chaotic-attack-animation", ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_TILES,
        ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_FRAMES, ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_OFF,
        1,
        1,
        ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elf-priest-male-chaotic-kick-animation", ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_TILES,
        ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_FRAMES, ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_OFF,
        1,
        1,
        ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        4, 7,
        ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dwarf-knight-female-attack-animation", DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_TILES,
      DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES, DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      6, 9,
      DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dwarf-knight-female-kick-animation", DWARF_KNIGHT_FEMALE_KICK_ANIMATION_TILES,
        DWARF_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES, DWARF_KNIGHT_FEMALE_KICK_ANIMATION_OFF,
        1,
        1,
        ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        3, 6,
        DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "orc-barbarian-male-attack-animation", ORC_BARBARIAN_MALE_ATTACK_ANIMATION_TILES,
      ORC_BARBARIAN_MALE_ATTACK_ANIMATION_FRAMES, ORC_BARBARIAN_MALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      6, 8,
      ORC_BARBARIAN_MALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "orc-barbarian-male-kick-animation", ORC_BARBARIAN_MALE_KICK_ANIMATION_TILES,
      ORC_BARBARIAN_MALE_KICK_ANIMATION_FRAMES, ORC_BARBARIAN_MALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      3, 6,
      ORC_BARBARIAN_MALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "orc-rogue-female-attack-animation", ORC_ROGUE_FEMALE_ATTACK_ANIMATION_TILES,
      ORC_ROGUE_FEMALE_ATTACK_ANIMATION_FRAMES, ORC_ROGUE_FEMALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      6, 8,
      ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "orc-rogue-female-kick-animation", ORC_ROGUE_FEMALE_KICK_ANIMATION_TILES,
      ORC_ROGUE_FEMALE_KICK_ANIMATION_FRAMES, ORC_ROGUE_FEMALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      3, 6,
      ORC_ROGUE_FEMALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-tourist-male-attack-animation", HUMAN_TOURIST_MALE_ATTACK_ANIMATION_TILES,
      HUMAN_TOURIST_MALE_ATTACK_ANIMATION_FRAMES, HUMAN_TOURIST_MALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      6, 9,
      HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-tourist-male-kick-animation", HUMAN_TOURIST_MALE_KICK_ANIMATION_TILES,
      HUMAN_TOURIST_MALE_KICK_ANIMATION_FRAMES, HUMAN_TOURIST_MALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      3, 7,
      HUMAN_TOURIST_MALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-valkyrie-female-attack-animation", HUMAN_VALKYRIE_FEMALE_ATTACK_ANIMATION_TILES,
      HUMAN_VALKYRIE_FEMALE_ATTACK_ANIMATION_FRAMES, HUMAN_VALKYRIE_FEMALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      4, 7,
      HUMAN_VALKYRIE_FEMALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-valkyrie-female-kick-animation", HUMAN_VALKYRIE_FEMALE_KICK_ANIMATION_TILES,
      HUMAN_VALKYRIE_FEMALE_KICK_ANIMATION_FRAMES, HUMAN_VALKYRIE_FEMALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      4, 7,
      HUMAN_VALKYRIE_FEMALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elf-ranger-male-fire-animation", ELF_RANGER_MALE_FIRE_ANIMATION_TILES,
      ELF_RANGER_MALE_FIRE_ANIMATION_FRAMES, ELF_RANGER_MALE_FIRE_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      9, 10,
      ELF_RANGER_MALE_FIRE_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elf-ranger-male-kick-animation", ELF_RANGER_MALE_KICK_ANIMATION_TILES,
      ELF_RANGER_MALE_KICK_ANIMATION_FRAMES, ELF_RANGER_MALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      3, 7,
      ELF_RANGER_MALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnoll-healer-male-attack-animation", GNOLL_HEALER_MALE_ATTACK_ANIMATION_TILES,
      GNOLL_HEALER_MALE_ATTACK_ANIMATION_FRAMES, GNOLL_HEALER_MALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      3, 6,
     GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnoll-healer-male-kick-animation", GNOLL_HEALER_MALE_KICK_ANIMATION_TILES,
      GNOLL_HEALER_MALE_KICK_ANIMATION_FRAMES, GNOLL_HEALER_MALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      2, 5,
      GNOLL_HEALER_MALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-monk-male-attack-animation", HUMAN_MONK_MALE_ATTACK_ANIMATION_TILES,
      HUMAN_MONK_MALE_ATTACK_ANIMATION_FRAMES, HUMAN_MONK_MALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      3, 6,
      HUMAN_MONK_MALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-monk-male-kick-animation", HUMAN_MONK_MALE_KICK_ANIMATION_TILES,
      HUMAN_MONK_MALE_KICK_ANIMATION_FRAMES, HUMAN_MONK_MALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      2, 5,
      HUMAN_MONK_MALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-samurai-male-attack-animation", HUMAN_SAMURAI_MALE_ATTACK_ANIMATION_TILES,
      HUMAN_SAMURAI_MALE_ATTACK_ANIMATION_FRAMES, HUMAN_SAMURAI_MALE_ATTACK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      4, 7,
      HUMAN_SAMURAI_MALE_ATTACK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "human-samurai-male-kick-animation", HUMAN_SAMURAI_MALE_KICK_ANIMATION_TILES,
      HUMAN_SAMURAI_MALE_KICK_ANIMATION_FRAMES, HUMAN_SAMURAI_MALE_KICK_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      4, 7,
      HUMAN_SAMURAI_MALE_KICK_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "ochre-jelly-swallow-animation", OCHRE_JELLY_SWALLOW_ANIMATION_TILES,
      OCHRE_JELLY_SWALLOW_ANIMATION_FRAMES, OCHRE_JELLY_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      6,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dust-vortex-swallow-animation", DUST_VORTEX_SWALLOW_ANIMATION_TILES,
      DUST_VORTEX_SWALLOW_ANIMATION_FRAMES, DUST_VORTEX_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fog-cloud-swallow-animation", FOG_CLOUD_SWALLOW_ANIMATION_TILES,
      FOG_CLOUD_SWALLOW_ANIMATION_FRAMES, FOG_CLOUD_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "ice-vortex-swallow-animation", ICE_VORTEX_SWALLOW_ANIMATION_TILES,
      ICE_VORTEX_SWALLOW_ANIMATION_FRAMES, ICE_VORTEX_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "steam-vortex-swallow-animation", STEAM_VORTEX_SWALLOW_ANIMATION_TILES,
      STEAM_VORTEX_SWALLOW_ANIMATION_FRAMES, STEAM_VORTEX_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fire-vortex-swallow-animation", FIRE_VORTEX_SWALLOW_ANIMATION_TILES,
      FIRE_VORTEX_SWALLOW_ANIMATION_FRAMES, FIRE_VORTEX_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "energy-vortex-swallow-animation", ENERGY_VORTEX_SWALLOW_ANIMATION_TILES,
      ENERGY_VORTEX_SWALLOW_ANIMATION_FRAMES, ENERGY_VORTEX_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "air-elemental-swallow-animation", AIR_ELEMENTAL_SWALLOW_ANIMATION_TILES,
      AIR_ELEMENTAL_SWALLOW_ANIMATION_FRAMES, AIR_ELEMENTAL_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "elder-air-elemental-swallow-animation", ELDER_AIR_ELEMENTAL_SWALLOW_ANIMATION_TILES,
      ELDER_AIR_ELEMENTAL_SWALLOW_ANIMATION_FRAMES, ELDER_AIR_ELEMENTAL_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "juiblex-swallow-animation", JUIBLEX_SWALLOW_ANIMATION_TILES,
      JUIBLEX_SWALLOW_ANIMATION_FRAMES, JUIBLEX_SWALLOW_ANIMATION_OFF,
      MAX_SWALLOW_CHARS,
      6,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fiery-explosion-animation", FIERY_EXPLOSION_ANIMATION_TILES,
      FIERY_EXPLOSION_ANIMATION_FRAMES, FIERY_EXPLOSION_ANIMATION_OFF,
      MAX_EXPLOSION_CHARS,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_LAST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "magic-explosion-animation", MAGIC_EXPLOSION_ANIMATION_TILES,
      MAGIC_EXPLOSION_ANIMATION_FRAMES, MAGIC_EXPLOSION_ANIMATION_OFF,
      MAX_EXPLOSION_CHARS,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_LAST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "frosty-explosion-animation", FROSTY_EXPLOSION_ANIMATION_TILES,
      FROSTY_EXPLOSION_ANIMATION_FRAMES, FROSTY_EXPLOSION_ANIMATION_OFF,
      MAX_EXPLOSION_CHARS,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_LAST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "noxious-explosion-animation", NOXIOUS_EXPLOSION_ANIMATION_TILES,
      NOXIOUS_EXPLOSION_ANIMATION_FRAMES, NOXIOUS_EXPLOSION_ANIMATION_OFF,
      MAX_EXPLOSION_CHARS,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_LAST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "fire-ray-animation", FIRE_RAY_ANIMATION_TILES,
      FIRE_RAY_ANIMATION_FRAMES, FIRE_RAY_ANIMATION_OFF,
      MAX_ZAP_CHARS,
      1,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_LAST,
      AUTODRAW_NONE,
      { 0, 1, 3, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "generic-spell-effect-animation", GENERIC_SPELL_EFFECT_ANIMATION_TILES,
      GENERIC_SPELL_EFFECT_ANIMATION_FRAMES, GENERIC_SPELL_EFFECT_ANIMATION_OFF,
      1,
      1,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 0, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "teleport-in-animation", TELEPORT_IN_ANIMATION_TILES,
      TELEPORT_IN_ANIMATION_FRAMES, TELEPORT_IN_ANIMATION_OFF,
      1,
      2,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      1, 4,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "teleport-out-animation", TELEPORT_OUT_ANIMATION_TILES,
      TELEPORT_OUT_ANIMATION_FRAMES, TELEPORT_OUT_ANIMATION_OFF,
      1,
      2,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      1, 4,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "summon-demon-animation", SUMMON_DEMON_ANIMATION_TILES,
      SUMMON_DEMON_ANIMATION_FRAMES, SUMMON_DEMON_ANIMATION_OFF,
      1,
      2,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      0, 14,
      SUMMON_DEMON_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "summon-celestial-animation", SUMMON_CELESTIAL_ANIMATION_TILES,
      SUMMON_CELESTIAL_ANIMATION_FRAMES, SUMMON_CELESTIAL_ANIMATION_OFF,
      1,
      4,
      ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      0, 17,
      SUMMON_CELESTIAL_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "twisted-candle-lit-animation", TWISTED_CANDLE_ANIMATION_TILES,
      TWISTED_CANDLE_ANIMATION_FRAMES, TWISTED_CANDLE_ANIMATION_OFF, 
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_NONE,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "old-fashioned-candle-lit-animation", OLD_FASHIONED_CANDLE_ANIMATION_TILES,
     OLD_FASHIONED_CANDLE_ANIMATION_FRAMES, OLD_FASHIONED_CANDLE_ANIMATION_OFF,
     1,
     3,
     ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
     AUTODRAW_NONE,
     { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
     -1, -1,
     NO_ENLARGEMENT,
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "oriental-brass-lamp-lit-animation", ORIENTAL_BRASS_LAMP_ANIMATION_TILES,
     ORIENTAL_BRASS_LAMP_ANIMATION_FRAMES, ORIENTAL_BRASS_LAMP_ANIMATION_OFF,
     1,
     3,
     ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
     AUTODRAW_NONE,
     { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
     -1, -1,
     NO_ENLARGEMENT,
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "antiquated-brass-lamp-lit-animation", ANTIQUATED_BRASS_LAMP_ANIMATION_TILES,
     ANTIQUATED_BRASS_LAMP_ANIMATION_FRAMES, ANTIQUATED_BRASS_LAMP_ANIMATION_OFF,
     1,
     3,
     ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
     AUTODRAW_NONE,
     { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
     -1, -1,
     NO_ENLARGEMENT,
     { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "vibrating-square-animation", VIBRATING_SQUARE_ANIMATION_TILES,
        VIBRATING_SQUARE_ANIMATION_FRAMES, VIBRATING_SQUARE_ANIMATION_OFF,
        1,
        2,
        ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
        AUTODRAW_NONE,
        { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
        -1, -1,
        NO_ENLARGEMENT,
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "candelabrum-lit-animation", CANDELABRUM_LIT_ANIMATION_TILES,
      CANDELABRUM_LIT_ANIMATION_FRAMES, CANDELABRUM_LIT_ANIMATION_OFF,
      1,
      3,
      ANIMATION_PLAY_TYPE_ALWAYS, ANIMATION_MAIN_TILE_USE_FIRST,
      AUTODRAW_CANDELABRUM,
      { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29, 30, 31 },
      -1, -1,
      NO_ENLARGEMENT,
      { AUTODRAW_CANDELABRUM_ANIMATION_TILE_1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
};

NEARDATA struct enlargement_definition enlargements[MAX_ENLARGEMENTS] =
{
    { "", 0, 0,
      0, 0,
      0, 0, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },

    { "dracolich-enlargement", 0, 0,
      DRACOLICH_ENLARGEMENT_TILES, DRACOLICH_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "dracolich-statue-enlargement", 0, 0,
      DRACOLICH_STATUE_ENLARGEMENT_TILES, DRACOLICH_STATUE_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "balrog-enlargement", 0, 0,
      BALROG_ENLARGEMENT_TILES, BALROG_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "balrog-statue-enlargement", 0, 0,
      BALROG_STATUE_ENLARGEMENT_TILES, BALROG_STATUE_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "balrog-passive-defense-enlargement", 0, 0,
      BALROG_PASSIVE_DEFENSE_ENLARGEMENT_TILES, BALROG_PASSIVE_DEFENSE_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "tarrasque-enlargement", 0, 0,
      TARRASQUE_ENLARGEMENT_TILES, TARRASQUE_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "tarrasque-statue-enlargement", 0, 0,
      TARRASQUE_STATUE_ENLARGEMENT_TILES, TARRASQUE_STATUE_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "marilith-enlargement", 0, 0,
      MARILITH_ENLARGEMENT_TILES, MARILITH_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "marilith-statue-enlargement", 0, 0,
      MARILITH_STATUE_ENLARGEMENT_TILES, MARILITH_STATUE_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "tree-enlargement", 0, 0,
      TREE_ENLARGEMENT_TILES, TREE_ENLARGEMENT_OFF,
      3, 2, 0,
      { 0, 1, 2, 3, 4 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-upstairs-enlargement", 0, 0,
      UPSTAIRS_ENLARGEMENT_TILES, UPSTAIRS_ENLARGEMENT_OFF,
      1, 2, 0,
      { -1, 0, -1, -1, -1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-branch-upstairs-enlargement", 0, 0,
      BRANCH_UPSTAIRS_ENLARGEMENT_TILES, BRANCH_UPSTAIRS_ENLARGEMENT_OFF,
      1, 2, 0,
      { -1, 0, -1, -1, -1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-special-branch-upstairs-enlargement", 0, 0,
      SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_TILES, SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_OFF,
      1, 2, 0,
      { -1, 0, -1, -1, -1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "human-knight-female-attack-enlargement", 
      HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_TILES, HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES,
      HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_TILES, HUMAN_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "human-knight-female-kick-enlargement", 
      HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_TILES, HUMAN_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES,
      HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT_TILES, HUMAN_KNIGHT_FEMALE_KICK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "human-knight-female-cast-enlargement",
      HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_TILES, HUMAN_KNIGHT_FEMALE_CAST_ANIMATION_FRAMES,
      HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT_TILES, HUMAN_KNIGHT_FEMALE_CAST_ENLARGEMENT_OFF,
      1, 2, 0,
      { -1, 0, -1, -1, -1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "human-knight-male-attack-enlargement", 
      HUMAN_KNIGHT_MALE_ATTACK_ANIMATION_TILES, HUMAN_KNIGHT_MALE_ATTACK_ANIMATION_FRAMES,
      HUMAN_KNIGHT_MALE_ATTACK_ENLARGEMENT_TILES, HUMAN_KNIGHT_MALE_ATTACK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "elf-priest-male-chaotic-cast-enlargement",
      ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_TILES, ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION_FRAMES,
      ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT_TILES, ELF_PRIEST_MALE_CHAOTIC_CAST_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "elf-priest-male-chaotic-attack-enlargement",
      ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_TILES, ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION_FRAMES,
      ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT_TILES, ELF_PRIEST_MALE_CHAOTIC_ATTACK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "elf-priest-male-chaotic-kick-enlargement",
      ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_TILES, ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION_FRAMES,
      ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT_TILES, ELF_PRIEST_MALE_CHAOTIC_KICK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "dwarf-knight-female-attack-enlargement",
      DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_TILES, DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION_FRAMES,
      DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_TILES, DWARF_KNIGHT_FEMALE_ATTACK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "dwarf-knight-female-kick-enlargement",
      DWARF_KNIGHT_FEMALE_KICK_ANIMATION_TILES, DWARF_KNIGHT_FEMALE_KICK_ANIMATION_FRAMES,
      DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT_TILES, DWARF_KNIGHT_FEMALE_KICK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "orc-barbarian-male-attack-enlargement",
      ORC_BARBARIAN_MALE_ATTACK_ANIMATION_TILES, ORC_BARBARIAN_MALE_ATTACK_ANIMATION_FRAMES,
      ORC_BARBARIAN_MALE_ATTACK_ENLARGEMENT_TILES, ORC_BARBARIAN_MALE_ATTACK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "orc-barbarian-male-kick-enlargement",
      ORC_BARBARIAN_MALE_KICK_ANIMATION_TILES, ORC_BARBARIAN_MALE_KICK_ANIMATION_FRAMES,
      ORC_BARBARIAN_MALE_KICK_ENLARGEMENT_TILES, ORC_BARBARIAN_MALE_KICK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "orc-rogue-female-attack-enlargement",
      ORC_ROGUE_FEMALE_ATTACK_ANIMATION_TILES, ORC_ROGUE_FEMALE_ATTACK_ANIMATION_FRAMES,
      ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT_TILES, ORC_ROGUE_FEMALE_ATTACK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "orc-rogue-female-kick-enlargement",
      ORC_ROGUE_FEMALE_KICK_ANIMATION_TILES, ORC_ROGUE_FEMALE_KICK_ANIMATION_FRAMES,
      ORC_ROGUE_FEMALE_KICK_ENLARGEMENT_TILES, ORC_ROGUE_FEMALE_KICK_ENLARGEMENT_OFF,
      3, 1, 0,
      { -1, -1, -1, 0, 1 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
      { "human-tourist-male-attack-enlargement",
        HUMAN_TOURIST_MALE_ATTACK_ANIMATION_TILES, HUMAN_TOURIST_MALE_ATTACK_ANIMATION_FRAMES,
        HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT_TILES, HUMAN_TOURIST_MALE_ATTACK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "human-tourist-male-kick-enlargement",
        HUMAN_TOURIST_MALE_KICK_ANIMATION_TILES, HUMAN_TOURIST_MALE_KICK_ANIMATION_FRAMES,
        HUMAN_TOURIST_MALE_KICK_ENLARGEMENT_TILES, HUMAN_TOURIST_MALE_KICK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "human-valkyrie-female-attack-enlargement",
        HUMAN_VALKYRIE_FEMALE_ATTACK_ANIMATION_TILES, HUMAN_VALKYRIE_FEMALE_ATTACK_ANIMATION_FRAMES,
        HUMAN_VALKYRIE_FEMALE_ATTACK_ENLARGEMENT_TILES, HUMAN_VALKYRIE_FEMALE_ATTACK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "human-valkyrie-female-kick-enlargement",
        HUMAN_VALKYRIE_FEMALE_KICK_ANIMATION_TILES, HUMAN_VALKYRIE_FEMALE_KICK_ANIMATION_FRAMES,
        HUMAN_VALKYRIE_FEMALE_KICK_ENLARGEMENT_TILES, HUMAN_VALKYRIE_FEMALE_KICK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "elf-ranger-male-fire-enlargement",
        ELF_RANGER_MALE_FIRE_ANIMATION_TILES, ELF_RANGER_MALE_FIRE_ANIMATION_FRAMES,
        ELF_RANGER_MALE_FIRE_ENLARGEMENT_TILES, ELF_RANGER_MALE_FIRE_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "elf-ranger-male-kick-enlargement",
        ELF_RANGER_MALE_KICK_ANIMATION_TILES, ELF_RANGER_MALE_KICK_ANIMATION_FRAMES,
        ELF_RANGER_MALE_KICK_ENLARGEMENT_TILES, ELF_RANGER_MALE_KICK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "gnoll-healer-male-attack-enlargement",
        GNOLL_HEALER_MALE_ATTACK_ANIMATION_TILES, GNOLL_HEALER_MALE_ATTACK_ANIMATION_FRAMES,
        GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT_TILES, GNOLL_HEALER_MALE_ATTACK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "gnoll-healer-male-kick-enlargement",
        GNOLL_HEALER_MALE_KICK_ANIMATION_TILES, GNOLL_HEALER_MALE_KICK_ANIMATION_FRAMES,
        GNOLL_HEALER_MALE_KICK_ENLARGEMENT_TILES, GNOLL_HEALER_MALE_KICK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "human-monk-male-attack-enlargement",
        HUMAN_MONK_MALE_ATTACK_ANIMATION_TILES, HUMAN_MONK_MALE_ATTACK_ANIMATION_FRAMES,
        HUMAN_MONK_MALE_ATTACK_ENLARGEMENT_TILES, HUMAN_MONK_MALE_ATTACK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "human-monk-male-kick-enlargement",
        HUMAN_MONK_MALE_KICK_ANIMATION_TILES, HUMAN_MONK_MALE_KICK_ANIMATION_FRAMES,
        HUMAN_MONK_MALE_KICK_ENLARGEMENT_TILES, HUMAN_MONK_MALE_KICK_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "human-samurai-male-attack-enlargement",
        HUMAN_SAMURAI_MALE_ATTACK_ANIMATION_TILES, HUMAN_SAMURAI_MALE_ATTACK_ANIMATION_FRAMES,
        HUMAN_SAMURAI_MALE_ATTACK_ENLARGEMENT_TILES, HUMAN_SAMURAI_MALE_ATTACK_ENLARGEMENT_OFF,
        3, 2, 0,
        { 0, 1, 2, 3, 4 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "human-samurai-male-kick-enlargement",
        HUMAN_SAMURAI_MALE_KICK_ANIMATION_TILES, HUMAN_SAMURAI_MALE_KICK_ANIMATION_FRAMES,
        HUMAN_SAMURAI_MALE_KICK_ENLARGEMENT_TILES, HUMAN_SAMURAI_MALE_KICK_ENLARGEMENT_OFF,
        3, 2, 0,
        { 0, 1, 2, 3, 4 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "pony-enlargement", 0, 0,
      PONY_ENLARGEMENT_TILES, PONY_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "pony-statue-enlargement", 0, 0,
      PONY_STATUE_ENLARGEMENT_TILES, PONY_STATUE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "horse-enlargement", 0, 0,
      HORSE_ENLARGEMENT_TILES, HORSE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "horse-statue-enlargement", 0, 0,
      HORSE_STATUE_ENLARGEMENT_TILES, HORSE_STATUE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "warhorse-enlargement", 0, 0,
      WARHORSE_ENLARGEMENT_TILES, WARHORSE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "warhorse-statue-enlargement", 0, 0,
      WARHORSE_STATUE_ENLARGEMENT_TILES, WARHORSE_STATUE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "pegasus-enlargement", 0, 0,
      PEGASUS_ENLARGEMENT_TILES, PEGASUS_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "pegasus-statue-enlargement", 0, 0,
      PEGASUS_STATUE_ENLARGEMENT_TILES, PEGASUS_STATUE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "white-unicorn-enlargement", 0, 0,
      WHITE_UNICORN_ENLARGEMENT_TILES, WHITE_UNICORN_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "white-unicorn-statue-enlargement", 0, 0,
      WHITE_UNICORN_STATUE_ENLARGEMENT_TILES, WHITE_UNICORN_STATUE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "gray-unicorn-enlargement", 0, 0,
      GRAY_UNICORN_ENLARGEMENT_TILES, GRAY_UNICORN_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "gray-unicorn-statue-enlargement", 0, 0,
      GRAY_UNICORN_STATUE_ENLARGEMENT_TILES, GRAY_UNICORN_STATUE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "black-unicorn-enlargement", 0, 0,
      BLACK_UNICORN_ENLARGEMENT_TILES, BLACK_UNICORN_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
    { "black-unicorn-statue-enlargement", 0, 0,
      BLACK_UNICORN_STATUE_ENLARGEMENT_TILES, BLACK_UNICORN_STATUE_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
    },
      { "ram-enlargement", 0, 0,
      RAM_ENLARGEMENT_TILES, RAM_ENLARGEMENT_OFF,
      2, 1, 0,
      { -1, -1, -1, -1, 0 },
      { 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0 }
      },
      { "ram-statue-enlargement", 0, 0,
        RAM_STATUE_ENLARGEMENT_TILES, RAM_STATUE_ENLARGEMENT_OFF,
        2, 1, 0,
        { -1, -1, -1, -1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "horse-enlargement", 0, 0,
        LARGE_RAM_ENLARGEMENT_TILES, LARGE_RAM_ENLARGEMENT_OFF,
        2, 1, 0,
        { -1, -1, -1, -1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "large-ram-statue-enlargement", 0, 0,
        LARGE_RAM_STATUE_ENLARGEMENT_TILES, LARGE_RAM_STATUE_ENLARGEMENT_OFF,
        2, 1, 0,
        { -1, -1, -1, -1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "warram-enlargement", 0, 0,
        WARRAM_ENLARGEMENT_TILES, WARRAM_ENLARGEMENT_OFF,
        2, 1, 0,
        { -1, -1, -1, -1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "warram-statue-enlargement", 0, 0,
        WARRAM_STATUE_ENLARGEMENT_TILES, WARRAM_STATUE_ENLARGEMENT_OFF,
        2, 1, 0,
        { -1, -1, -1, -1, 0 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "dungeon-normal-smaller-upstairs-enlargement", 0, 0,
        DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT_TILES, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT_OFF,
        1, 2, 0,
        { -1, 0, -1, -1, -1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "dungeon-undead-upstairs-enlargement", 0, 0,
        DUNGEON_UNDEAD_UPSTAIRS_ENLARGEMENT_TILES, DUNGEON_UNDEAD_UPSTAIRS_ENLARGEMENT_OFF,
        1, 2, 0,
        { -1, 0, -1, -1, -1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "dungeon-undead-branch-upstairs-enlargement", 0, 0,
        DUNGEON_UNDEAD_BRANCH_UPSTAIRS_ENLARGEMENT_TILES, DUNGEON_UNDEAD_BRANCH_UPSTAIRS_ENLARGEMENT_OFF,
        1, 2, 0,
        { -1, 0, -1, -1, -1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "dungeon-undead-special-branch-upstairs-enlargement", 0, 0,
        DUNGEON_UNDEAD_SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_TILES, DUNGEON_UNDEAD_SPECIAL_BRANCH_UPSTAIRS_ENLARGEMENT_OFF,
        1, 2, 0,
        { -1, 0, -1, -1, -1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "dracolich-attack-enlargement",
        DRACOLICH_ATTACK_ANIMATION_TILES, DRACOLICH_ATTACK_ANIMATION_FRAMES,
        DRACOLICH_ATTACK_ENLARGEMENT_TILES, DRACOLICH_ATTACK_ENLARGEMENT_OFF,
        3, 2, 0,
        { 0, 1, 2, 3, 4 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "summon-demon-enlargement",
        SUMMON_DEMON_ANIMATION_TILES, SUMMON_DEMON_ANIMATION_FRAMES,
        SUMMON_DEMON_ENLARGEMENT_TILES, SUMMON_DEMON_ENLARGEMENT_OFF,
        3, 1, 0,
        { -1, -1, -1, 0, 1 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "summon-celestial-enlargement",
        SUMMON_CELESTIAL_ANIMATION_TILES, SUMMON_CELESTIAL_ANIMATION_FRAMES,
        SUMMON_CELESTIAL_ENLARGEMENT_TILES, SUMMON_CELESTIAL_ENLARGEMENT_OFF,
        3, 2, 0,
        { 0, 1, 2, 3, 4 },
        { 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0 }
      },
      { "bookshelf-enlargement", 0, 0,
        BOOKSHELF_ENLARGEMENT_TILES, BOOKSHELF_ENLARGEMENT_OFF,
        1, 2, 0,
        { -1, 0, -1, -1, -1 },
        { 0, 0, 0, 0, 0 },
        { 0, AUTODRAW_BOOKSHELF, 0, 0, 0 }
      },
      { "weapon-rack-enlargement", 0, 0,
        WEAPON_RACK_ENLARGEMENT_TILES, WEAPON_RACK_ENLARGEMENT_OFF,
        1, 2, 0,
        { -1, 0, -1, -1, -1 },
        { 0, 0, 0, 0, 0 },
        { 0, AUTODRAW_WEAPON_RACK, 0, 0, 0 }
      },
};

NEARDATA struct replacement_definition replacements[MAX_REPLACEMENTS] =
{
    { "",
      0, 0,
      0UL,
      REPLACEMENT_ACTION_NO_ACTION,
      AUTODRAW_NONE,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-stone-replacement",
      DUNGEON_NORMAL_STONE_REPLACEMENT_TILES, DUNGEON_NORMAL_STONE_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW,
      REPLACEMENT_ACTION_BOTTOM_TILE,
      AUTODRAW_NONE,
      { "bottom-end", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-vwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_DOWN,
      { "bottom-end", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-crwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_ALL,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-trwall-replacement",
        0, 0,
        REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
        REPLACEMENT_ACTION_AUTODRAW,
        AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_DOWN_RIGHT,
        { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-tlwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_LEFT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_DOWN_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-tuwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-tdwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_DOWN_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-hwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-tlcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_DOWN_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-trcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_BELOW,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_DOWN_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-blcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-brcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_NORMAL_REPLACE_WALL_ENDS_UP_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "coin-replacement",
      COIN_REPLACEMENT_TILES, COIN_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_COIN_QUANTITY,
      AUTODRAW_NONE,
      { "few", "many", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "handcrafted-candle-replacement",
      HANDCRAFTED_CANDLE_LIT_REPLACEMENT_TILES, HANDCRAFTED_CANDLE_LIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_OBJECT_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { HANDCRAFTED_CANDLE_LIT_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "twisted-candle-replacement",
      TWISTED_CANDLE_LIT_REPLACEMENT_TILES, TWISTED_CANDLE_LIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_OBJECT_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { TWISTED_CANDLE_LIT_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "old-fashioned-candle-replacement",
      OLD_FASHIONED_CANDLE_LIT_REPLACEMENT_TILES, OLD_FASHIONED_CANDLE_LIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_OBJECT_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { OLD_FASHIONED_CANDLE_LIT_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "oriental-brass-lamp-replacement",
      ORIENTAL_BRASS_LAMP_LIT_REPLACEMENT_TILES, ORIENTAL_BRASS_LAMP_LIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_OBJECT_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      {ORIENTAL_BRASS_LAMP_LIT_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "antiquated-brass-lamp-replacement",
      ANTIQUATED_BRASS_LAMP_LIT_REPLACEMENT_TILES, ANTIQUATED_BRASS_LAMP_LIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_OBJECT_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      {ANTIQUATED_BRASS_LAMP_LIT_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "lawful-altar-replacement",
      LAWFUL_ALTAR_REPLACEMENT_TILES, LAWFUL_ALTAR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { LAWFUL_ALTAR_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "neutral-altar-replacement",
      NEUTRAL_ALTAR_REPLACEMENT_TILES, NEUTRAL_ALTAR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { NEUTRAL_ALTAR_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "chaotic-altar-replacement",
      CHAOTIC_ALTAR_REPLACEMENT_TILES, CHAOTIC_ALTAR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { CHAOTIC_ALTAR_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "altar-of-moloch-replacement",
      ALTAR_OF_MOLOCH_REPLACEMENT_TILES, ALTAR_OF_MOLOCH_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { ALTAR_OF_MOLOCH_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "high-altar-replacement",
      HIGH_ALTAR_REPLACEMENT_TILES, HIGH_ALTAR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { HIGH_ALTAR_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "chest-replacement",
      CHEST_REPLACEMENT_TILES, CHEST_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_CHEST,
      AUTODRAW_NONE,
      { "locked", "broken", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "golden-chest-replacement",
      GOLDEN_CHEST_REPLACEMENT_TILES, GOLDEN_CHEST_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_CHEST,
      AUTODRAW_NONE,
      { "locked", "broken", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-iron-bar-replacement",
      DUNGEON_NORMAL_IRON_BAR_REPLACEMENT_TILES, DUNGEON_NORMAL_IRON_BAR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_HORIZONTAL,
      AUTODRAW_NONE,
      { "horizontal", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-water-replacement",
      DUNGEON_NORMAL_WATER_REPLACEMENT_TILES, DUNGEON_NORMAL_WATER_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-parquet", "shore-marble", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground-swampy", "shore-corridor", "shore-water", "shore-ice", "shore-lava", "shore-drawbridge-down", "shore-water" /*"shore-air"*/, "shore-water" /*"shore-cloud"*/, "shore-water" /*"shore-water2"*/, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-ice-replacement",
      DUNGEON_NORMAL_ICE_REPLACEMENT_TILES, DUNGEON_NORMAL_ICE_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-parquet", "shore-marble", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground-swampy", "shore-corridor", "shore-water", "shore-ice", "shore-lava", "shore-drawbridge-down", "shore-ice" /*"shore-air"*/, "shore-ice" /*"shore-cloud"*/, "shore-ice" /*"shore-water2"*/, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-lava-replacement",
      DUNGEON_NORMAL_LAVA_REPLACEMENT_TILES, DUNGEON_NORMAL_LAVA_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-parquet", "shore-marble", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground-swampy", "shore-corridor", "shore-water", "shore-ice", "shore-lava", "shore-drawbridge-down", "shore-lava" /*"shore-air"*/, "shore-lava" /*"shore-cloud"*/, "shore-lava" /*"shore-water2"*/, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-room-replacement",
      DUNGEON_NORMAL_ROOM_REPLACEMENT_TILES, DUNGEON_NORMAL_ROOM_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-parquet", "shore-marble", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground-swampy", "shore-corridor", "shore-water", "shore-ice", "shore-lava", "shore-drawbridge-down", "shore-room" /*"shore-air"*/, "shore-room" /*"shore-cloud"*/, "shore-room" /*"shore-water2"*/, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-grass-replacement",
      DUNGEON_NORMAL_GRASS_REPLACEMENT_TILES, DUNGEON_NORMAL_GRASS_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-parquet", "shore-marble", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground-swampy", "shore-corridor", "shore-water", "shore-ice", "shore-lava", "shore-drawbridge-down", "shore-grass" /*"shore-air"*/, "shore-grass" /*"shore-cloud"*/, "shore-grass" /*"shore-water2"*/, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-grass-swampy-replacement",
      DUNGEON_NORMAL_GRASS_SWAMPY_REPLACEMENT_TILES, DUNGEON_NORMAL_GRASS_SWAMPY_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-parquet", "shore-marble", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground-swampy", "shore-corridor", "shore-water", "shore-ice", "shore-lava", "shore-drawbridge-down", "shore-grass-swampy" /*"shore-air"*/, "shore-grass-swampy" /*"shore-cloud"*/, "shore-grass-swampy" /*"shore-water2"*/, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-ground-replacement",
      DUNGEON_NORMAL_GROUND_REPLACEMENT_TILES, DUNGEON_NORMAL_GROUND_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-parquet", "shore-marble", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground-swampy", "shore-corridor", "shore-water", "shore-ice", "shore-lava", "shore-drawbridge-down", "shore-ground" /*"shore-air"*/, "shore-ground" /*"shore-cloud"*/, "shore-ground" /*"shore-water2"*/, "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-air-replacement",
      DUNGEON_NORMAL_AIR_REPLACEMENT_TILES, DUNGEON_NORMAL_AIR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-room", "shore-room", "shore-room", "shore-grass", "shore-grass-swampy", "shore-ground", "shore-ground", "shore-room", "shore-air", "shore-air", "shore-air", "shore-air", "shore-air", "shore-cloud", "shore-water2", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-cloud-replacement",
      DUNGEON_NORMAL_CLOUD_REPLACEMENT_TILES, DUNGEON_NORMAL_CLOUD_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-cloud", "shore-air", "shore-cloud", "shore-cloud", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-water2-replacement",
      DUNGEON_NORMAL_WATER2_REPLACEMENT_TILES, DUNGEON_NORMAL_WATER2_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_TILE,
      AUTODRAW_NONE,
      { "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-water2", "shore-air", "shore-water2", "shore-water2", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, RTF_SKIP, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-stairs-up-replacement",
      DUNGEON_NORMAL_STAIRS_UP_REPLACEMENT_TILES, DUNGEON_NORMAL_STAIRS_UP_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_ADJUSTED_TILE,
      AUTODRAW_NONE,
      { "smaller", "", "", "", "", "", "", "s", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, DUNGEON_NORMAL_SMALLER_UPSTAIRS_ENLARGEMENT, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-stairs-down-replacement",
      DUNGEON_NORMAL_STAIRS_DOWN_REPLACEMENT_TILES, DUNGEON_NORMAL_STAIRS_DOWN_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_SHORE_AND_FLOOR_ADJUSTED_TILE,
      AUTODRAW_NONE,
      { "room", "parquet", "marble", "grass", "grass-swampy", "ground", "ground-swampy", "corridor", "smaller-room", "smaller-parquet", "smaller-marble", "smaller-grass", "smaller-grass-swampy", "smaller-ground", "smaller-ground-swampy", "smaller-corridor", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-trapdoor-replacement",
      DUNGEON_NORMAL_TRAPDOOR_REPLACEMENT_TILES, DUNGEON_NORMAL_TRAPDOOR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_FLOOR_ADJUSTED_TILE,
      AUTODRAW_NONE,
      { "floor-room", "floor-parquet", "floor-marble", "floor-grass", "floor-grass-swampy", "floor-ground", "floor-ground-swampy", "floor-corridor", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-hole-replacement",
      DUNGEON_NORMAL_HOLE_REPLACEMENT_TILES, DUNGEON_NORMAL_HOLE_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_FLOOR_ADJUSTED_TILE,
      AUTODRAW_NONE,
      { "floor-room", "floor-parquet", "floor-marble", "floor-grass", "floor-grass-swampy", "floor-ground", "floor-ground-swampy", "floor-corridor", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-pit-replacement",
      DUNGEON_NORMAL_PIT_REPLACEMENT_TILES, DUNGEON_NORMAL_PIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_FLOOR_ADJUSTED_TILE,
      AUTODRAW_NONE,
      { "floor-room", "floor-parquet", "floor-marble", "floor-grass", "floor-grass-swampy", "floor-ground", "floor-ground-swampy", "floor-corridor", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-spiked-pit-replacement",
      DUNGEON_NORMAL_SPIKED_PIT_REPLACEMENT_TILES, DUNGEON_NORMAL_SPIKED_PIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_FLOOR_ADJUSTED_TILE,
      AUTODRAW_NONE,
      { "floor-room", "floor-parquet", "floor-marble", "floor-grass", "floor-grass-swampy", "floor-ground", "floor-ground-swampy", "floor-corridor", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-normal-lever-replacement",
      DUNGEON_NORMAL_LEVER_REPLACEMENT_TILES, DUNGEON_NORMAL_LEVER_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_LEVER_STATE,
      AUTODRAW_NONE,
      { "activated", "", "", "", "", "", "", "s", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-stone-replacement",
      GNOMISH_MINES_STONE_REPLACEMENT_TILES, GNOMISH_MINES_STONE_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW,
      REPLACEMENT_ACTION_BOTTOM_TILE,
      AUTODRAW_NONE,
      { "bottom-end", "bottom-end-variation-1", "bottom-end-variation-2", "bottom-end-variation-3", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-vwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_DOWN,
      { "bottom-end", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-crwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_ALL,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-trwall-replacement",
        0, 0,
        REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
        REPLACEMENT_ACTION_AUTODRAW,
        AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_DOWN_RIGHT,
        { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-tlwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_LEFT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_DOWN_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-tuwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-tdwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_DOWN_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-hwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-tlcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_DOWN_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-trcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_BELOW,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_DOWN_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-blcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-brcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_GNOMISH_MINES_REPLACE_WALL_ENDS_UP_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gnomish-mines-iron-bar-replacement",
      GNOMISH_MINES_IRON_BAR_REPLACEMENT_TILES, GNOMISH_MINES_IRON_BAR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_HORIZONTAL,
      AUTODRAW_NONE,
      { "horizontal", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "gehennom-stone-replacement",
      GEHENNOM_STONE_REPLACEMENT_TILES, GEHENNOM_STONE_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW,
      REPLACEMENT_ACTION_BOTTOM_TILE,
      AUTODRAW_NONE,
      { "bottom-end", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-stone-replacement",
      DUNGEON_UNDEAD_STONE_REPLACEMENT_TILES, DUNGEON_UNDEAD_STONE_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW,
      REPLACEMENT_ACTION_BOTTOM_TILE,
      AUTODRAW_NONE,
      { "bottom-end", "bottom-end-variation-1", "bottom-end-variation-2", "bottom-end-variation-3", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-vwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_UP_DOWN,
      { "bottom-end", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-crwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_ALL,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-trwall-replacement",
        0, 0,
        REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
        REPLACEMENT_ACTION_AUTODRAW,
        AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_UP_DOWN_RIGHT,
        { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-tlwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_LEFT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_UP_DOWN_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-tuwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_UP_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-tdwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_DOWN_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-hwall-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_LEFT_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-tlcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_BELOW | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_DOWN_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-trcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_BELOW,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_DOWN_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-blcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_TOP | REPLACEMENT_EVENT_UPDATE_FROM_RIGHT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_UP_RIGHT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-brcorn-replacement",
      0, 0,
      REPLACEMENT_EVENT_UPDATE_FROM_LEFT | REPLACEMENT_EVENT_UPDATE_FROM_TOP,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_DUNGEON_UNDEAD_REPLACE_WALL_ENDS_UP_LEFT,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "dungeon-undead-iron-bar-replacement",
      DUNGEON_UNDEAD_IRON_BAR_REPLACEMENT_TILES, DUNGEON_UNDEAD_IRON_BAR_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_LOCATION_HORIZONTAL,
      AUTODRAW_NONE,
      { "horizontal", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "brass-lantern-replacement",
      BRASS_LANTERN_LIT_REPLACEMENT_TILES, BRASS_LANTERN_LIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_OBJECT_LIT,
      AUTODRAW_NONE,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { BRASS_LANTERN_LIT_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "bookshelf-enlargement-replacement",
      0, 0,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_AUTODRAW,
      AUTODRAW_BOOKSHELF,
      { "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
    { "candelabrum-replacement",
      CANDELABRUM_LIT_REPLACEMENT_TILES, CANDELABRUM_LIT_REPLACEMENT_OFF,
      REPLACEMENT_EVENT_NO_EVENT,
      REPLACEMENT_ACTION_AUTODRAW_AND_OBJECT_LIT,
      AUTODRAW_CANDELABRUM,
      { "lit", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "" },
      { CANDELABRUM_LIT_ANIMATION, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { AUTODRAW_CANDELABRUM, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
      { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 }
    },
};


NEARDATA struct autodraw_definition autodraws[MAX_AUTODRAWS] =
{
    {"", 0, 0, 0, 0, 0},
    {
        "dungeon-normal-wall-autodraw-all",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-up-down",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-up-down-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-up-down-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-up-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-down-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-down-down-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-down-down-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-down-up-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_UP,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },
    {
        "dungeon-normal-wall-autodraw-down-up-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + GLYPH_CMAP_OFF,
        S_hwall + GLYPH_CMAP_OFF
    },

    {
        "gnomish-mines-wall-autodraw-all",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-up-down",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-up-down-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-up-down-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-up-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-down-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-down-down-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-down-down-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-down-up-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_UP,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "gnomish-mines-wall-autodraw-down-up-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_GNOMISH_MINES * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_GNOMISH_MINES * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    }, 

    {
        "dungeon-undead-wall-autodraw-all",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-up-down",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-up-down-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-up-down-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-up-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-down-left-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-down-down-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_DOWN,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-down-down-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_DOWN | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-down-up-right",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_RIGHT | AUTODRAW_DIR_UP,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "dungeon-undead-wall-autodraw-down-up-left",
        AUTODRAW_DRAW_REPLACE_WALL_ENDS,
        AUTODRAW_DIR_UP | AUTODRAW_DIR_LEFT,
        0 + CRWALL_VARIATION_OFFSET + CMAP_UNDEAD_STYLE * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF,
        S_vwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF,
        S_hwall + CMAP_UNDEAD_STYLE * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF
    },
    {
        "bookshelf-autodraw",
        AUTODRAW_DRAW_BOOKSHELF_CONTENTS,
        0,
        BOOKSHELF_GRAPHICS + GLYPH_UI_TILE_OFF,
        0,
        0
    },
    {
        "weapon-rack-autodraw",
        AUTODRAW_DRAW_WEAPON_RACK_CONTENTS,
        0,
        0,
        0,
        0
    },
    {
        "candelabrum-autodraw",
        AUTODRAW_DRAW_CANDELABRUM_CANDLES,
        0,
        CANDELABRUM_GRAPHICS + GLYPH_UI_TILE_OFF,
        0,
        0
    },
    {
        "candelabrum-animation-1-autodraw",
        AUTODRAW_DRAW_CANDELABRUM_CANDLES,
        1,
        CANDELABRUM_GRAPHICS + GLYPH_UI_TILE_OFF,
        0,
        0
    },

};


/* Special Effects */
NEARDATA struct special_effect_definition special_effects[MAX_SPECIAL_EFFECTS] =
{
    {"teleport-out",        0, 0, 2,      LAYER_GENERAL_EFFECT, NO_REPLACEMENT, TELEPORT_OUT_ANIMATION, NO_ENLARGEMENT},
    {"teleport-in",         0, 0, 2,      LAYER_GENERAL_EFFECT, NO_REPLACEMENT, TELEPORT_IN_ANIMATION, NO_ENLARGEMENT },
    {"generic-spell",       0, 0, 6,      LAYER_MONSTER_EFFECT, NO_REPLACEMENT, GENERIC_SPELL_EFFECT_ANIMATION, NO_ENLARGEMENT },
    {"summon-demon",        0, 0, 2,      LAYER_BACKGROUND_EFFECT, NO_REPLACEMENT, SUMMON_DEMON_ANIMATION, NO_ENLARGEMENT },
    {"summon-celestial",    0, 0, 2,      LAYER_GENERAL_EFFECT, NO_REPLACEMENT, SUMMON_CELESTIAL_ANIMATION, NO_ENLARGEMENT },
    {"summon-nature",       0, 0, 2,      LAYER_BACKGROUND_EFFECT, NO_REPLACEMENT, SUMMON_DEMON_ANIMATION, NO_ENLARGEMENT },
    {"summon-monster",      0, 0, 2,      LAYER_BACKGROUND_EFFECT, NO_REPLACEMENT, SUMMON_DEMON_ANIMATION, NO_ENLARGEMENT },
    {"summon-nasty",        0, 0, 2,      LAYER_BACKGROUND_EFFECT, NO_REPLACEMENT, SUMMON_DEMON_ANIMATION, NO_ENLARGEMENT },
    {"summon-undead",       0, 0, 2,      LAYER_BACKGROUND_EFFECT, NO_REPLACEMENT, SUMMON_DEMON_ANIMATION, NO_ENLARGEMENT },
    {"animate-dead",        0, 0, 2,      LAYER_GENERAL_EFFECT, NO_REPLACEMENT, SUMMON_DEMON_ANIMATION, NO_ENLARGEMENT },
    {"summon-in-smoke",     0, 0, 2,      LAYER_GENERAL_EFFECT, NO_REPLACEMENT, SUMMON_DEMON_ANIMATION, NO_ENLARGEMENT },
};


/* Game Cursors */
NEARDATA struct game_cursor_definition game_cursors[MAX_CURSORS] =
{
    {"generic", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"look", NO_REPLACEMENT, LOOK_CURSOR_ANIMATION, NO_ENLARGEMENT },
    {"travel", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"name", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"teleport", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"jump", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"polearm", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"grapple", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"spell", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"pay", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"invisible", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
};

/* Hit tile */
NEARDATA struct hit_tile_definition hit_tile_definitions[MAX_HIT_TILES] =
{
    {"hit", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"poisoned", NO_REPLACEMENT, LOOK_CURSOR_ANIMATION, NO_ENLARGEMENT },
    {"disintegrated", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"crushed", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"splashed-acid", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"on-fire", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"frozen", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"electrocuted", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"death", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"sleep", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"petrified", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"critical", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"flashed-light", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"paralyzed", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"slimed", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"sick", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"famine", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"heal", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"were", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"drain-level", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
    {"slow", NO_REPLACEMENT, NO_ANIMATION, NO_ENLARGEMENT},
};

STATIC_DCL int FDECL(get_shore_tile_index, (struct rm* , struct rm*));
STATIC_DCL int FDECL(get_solid_floor_tile_index, (struct rm*));
STATIC_DCL int FDECL(get_shore_and_floor_adjusted_tile_index, (struct rm*, struct rm*, struct rm*, struct rm*));


void
init_animations()
{
    /* force linkage */
    return;
}

int
get_player_action_glyph_offset(action)
enum action_tile_types action;
{
    /* relies on aligned ordering of glyph offsets and action_tile_types */
    int res = GLYPH_PLAYER_OFF + action * NUM_PLAYER_CHARACTERS;
    return res;
}

int
get_monster_action_glyph_offset(action, genderidx)
enum action_tile_types action;
int genderidx;
{
    /* relies on aligned ordering of glyph offsets and action_tile_types */
    int res = (genderidx == 0 ? GLYPH_MON_OFF : GLYPH_FEMALE_MON_OFF) + action * NUM_MONSTERS;
    return res;
}

short
get_player_replacement(action, roleidx, raceidx, genderidx, alignmentidx, levelidx)
enum action_tile_types action;
int roleidx, raceidx, genderidx, alignmentidx, levelidx;
{
    /* Write here the code that returns the right replacement for the combination that has a replacement */
    switch (action)
    {
    case ACTION_TILE_NO_ACTION:
        break;
    case ACTION_TILE_ATTACK:
        break;
    case ACTION_TILE_THROW:
        break;
    case ACTION_TILE_FIRE:
        break;
    case ACTION_TILE_CAST_NODIR:
        break;
    case ACTION_TILE_CAST_DIR:
        break;
    case ACTION_TILE_SPECIAL_ATTACK:
        break;
    case ACTION_TILE_KICK:
        break;
    case ACTION_TILE_PASSIVE_DEFENSE:
        break;
    case ACTION_TILE_DEFEND:
        break;
    case ACTION_TILE_RECEIVE_DAMAGE:
        break;
    case ACTION_TILE_ITEM_USE:
        break;
    case ACTION_TILE_DOOR_USE:
        break;
    case ACTION_TILE_DEATH:
        break;
    case MAX_ACTION_TILES:
        break;
    default:
        break;
    }
    return 0;
}

short
get_player_animation(action, roleidx, raceidx, genderidx, alignmentidx, levelidx)
enum action_tile_types action;
int roleidx, raceidx, genderidx, alignmentidx, levelidx;
{
    /* Write here the code that returns the right animation for the combination that has an animation */
    switch (action)
    {
    case ACTION_TILE_NO_ACTION:
        break;
    case ACTION_TILE_ATTACK:
        if (roleidx == ROLE_KNIGHT && raceidx == RACE_HUMAN && genderidx == GENDER_FEMALE)
            return HUMAN_KNIGHT_FEMALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_KNIGHT && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_KNIGHT_MALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_KNIGHT && raceidx == RACE_DWARF && genderidx == GENDER_FEMALE)
            return DWARF_KNIGHT_FEMALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_MONK && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_MONK_MALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_SAMURAI && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_SAMURAI_MALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_ROGUE && raceidx == RACE_ORC && genderidx == GENDER_FEMALE)
            return ORC_ROGUE_FEMALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_BARBARIAN && raceidx == RACE_ORC && genderidx == GENDER_MALE)
            return ORC_BARBARIAN_MALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_TOURIST && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_TOURIST_MALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_VALKYRIE && raceidx == RACE_HUMAN && genderidx == GENDER_FEMALE)
            return HUMAN_VALKYRIE_FEMALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_HEALER && raceidx == RACE_GNOLL && genderidx == GENDER_MALE)
            return GNOLL_HEALER_MALE_ATTACK_ANIMATION;
        if (roleidx == ROLE_PRIEST && raceidx == RACE_ELF && genderidx == GENDER_MALE && alignmentidx == A_CHAOTIC + 1)
            return ELF_PRIEST_MALE_CHAOTIC_ATTACK_ANIMATION;
        break;
    case ACTION_TILE_THROW:
        break;
    case ACTION_TILE_FIRE:
        if (roleidx == ROLE_RANGER && raceidx == RACE_ELF && genderidx == GENDER_MALE)
            return ELF_RANGER_MALE_FIRE_ANIMATION;
        break;
    case ACTION_TILE_CAST_NODIR:
        if (roleidx == ROLE_WIZARD && raceidx == RACE_ELF && genderidx == GENDER_FEMALE)
            return PLAYER_ELF_FEMALE_WIZARD_CAST_ANIMATION;
        if (roleidx == ROLE_KNIGHT && raceidx == RACE_HUMAN && genderidx == GENDER_FEMALE)
            return HUMAN_KNIGHT_FEMALE_CAST_ANIMATION;
        break;
    case ACTION_TILE_CAST_DIR:
        if (roleidx == ROLE_PRIEST && raceidx == RACE_ELF && genderidx == GENDER_MALE && alignmentidx == A_CHAOTIC + 1)
            return ELF_PRIEST_MALE_CHAOTIC_CAST_ANIMATION;
        if (roleidx == ROLE_KNIGHT && raceidx == RACE_HUMAN && genderidx == GENDER_FEMALE)
            return HUMAN_KNIGHT_FEMALE_CAST_ANIMATION;
        break;
    case ACTION_TILE_SPECIAL_ATTACK:
        break;
    case ACTION_TILE_KICK:
        if (roleidx == ROLE_WIZARD && raceidx == RACE_ELF && genderidx == GENDER_FEMALE)
            return PLAYER_ELF_FEMALE_WIZARD_KICK_ANIMATION;
        if (roleidx == ROLE_KNIGHT && raceidx == RACE_HUMAN && genderidx == GENDER_FEMALE)
            return HUMAN_KNIGHT_FEMALE_KICK_ANIMATION;
        if (roleidx == ROLE_KNIGHT && raceidx == RACE_DWARF && genderidx == GENDER_FEMALE)
            return DWARF_KNIGHT_FEMALE_KICK_ANIMATION;
        if (roleidx == ROLE_MONK && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_MONK_MALE_KICK_ANIMATION;
        if (roleidx == ROLE_SAMURAI && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_SAMURAI_MALE_KICK_ANIMATION;
        if (roleidx == ROLE_PRIEST && raceidx == RACE_ELF && genderidx == GENDER_MALE && alignmentidx == A_CHAOTIC + 1)
            return ELF_PRIEST_MALE_CHAOTIC_KICK_ANIMATION;
        if (roleidx == ROLE_ROGUE && raceidx == RACE_ORC && genderidx == GENDER_FEMALE)
            return ORC_ROGUE_FEMALE_KICK_ANIMATION;
        if (roleidx == ROLE_BARBARIAN && raceidx == RACE_ORC && genderidx == GENDER_MALE)
            return ORC_BARBARIAN_MALE_KICK_ANIMATION;
        if (roleidx == ROLE_TOURIST && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_TOURIST_MALE_KICK_ANIMATION;
        if (roleidx == ROLE_VALKYRIE && raceidx == RACE_HUMAN && genderidx == GENDER_FEMALE)
            return HUMAN_VALKYRIE_FEMALE_KICK_ANIMATION;
        if (roleidx == ROLE_HEALER && raceidx == RACE_GNOLL && genderidx == GENDER_MALE)
            return GNOLL_HEALER_MALE_KICK_ANIMATION;
        if (roleidx == ROLE_RANGER && raceidx == RACE_ELF && genderidx == GENDER_MALE)
            return ELF_RANGER_MALE_KICK_ANIMATION;
        break;
    case ACTION_TILE_PASSIVE_DEFENSE:
        break;
    case ACTION_TILE_DEFEND:
        break;
    case ACTION_TILE_RECEIVE_DAMAGE:
        break;
    case ACTION_TILE_ITEM_USE:
        if (roleidx == ROLE_TOURIST && raceidx == RACE_HUMAN && genderidx == GENDER_MALE)
            return HUMAN_TOURIST_MALE_ATTACK_ANIMATION;
        break;
    case ACTION_TILE_DOOR_USE:
        break;
    case ACTION_TILE_DEATH:
        break;
    case MAX_ACTION_TILES:
        break;
    default:
        break;
    }
    return 0;
}

struct replacement_info
data_to_replacement_info(signed_glyph, layer, otmp)
int signed_glyph, layer;
struct obj* otmp;
{
    struct replacement_info info = { 0 };
    info.signed_glyph = signed_glyph;
    info.layer = layer;
    info.object = otmp;

    return info;
}

short
maybe_get_replaced_tile(ntile, x, y, info, autodraw_ptr)
int x, y;
short ntile;
struct replacement_info info;
enum autodraw_types* autodraw_ptr;
{
#ifdef USE_TILES
    struct obj* otmp = info.object;
    short replacement_idx = tile2replacement[ntile];
    if (replacement_idx > 0)
    {
        int action_id = replacements[replacement_idx].replacement_action;

        switch (replacements[replacement_idx].replacement_action)
        {
        case REPLACEMENT_ACTION_BOTTOM_TILE:
        {
            int below_y = y + 1;
            if (!isok(x, below_y) 
                || levl[x][below_y].hero_memory_layers.glyph == cmap_to_glyph(S_unexplored) 
                || (IS_DOORJOIN(levl[x][below_y].typ) && !IS_TREE(levl[x][below_y].typ)) 
                || levl[x][below_y].typ == DOOR 
                || levl[x][below_y].typ == UNEXPLORED 
                || (!cansee(x, y) && levl[x][below_y].hero_memory_layers.glyph == cmap_to_glyph(S_stone))
                || (levl[x][y].seenv & (SV3 | SV4 | SV5 | SV6 | SV7)) == 0)
            {
                /* No action */
            }
            else
            {
                if(autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                /* Return the tile based on stone's subtyp (i.e., take the right variation) */
                int repl_idx = min(replacements[replacement_idx].number_of_tiles - 1, levl[x][y].subtyp);

                if (x == u.ux && y == u.uy - 1)
                    x = x;

                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[0];
                return glyph2tile[repl_idx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }

            break;
        }
        case REPLACEMENT_ACTION_SHORE_TILE:
        {
            int above_y = y - 1;
            int below_y = y + 1;
            int floortype = IS_FLOOR(levl[x][y].typ) || IS_POOL(levl[x][y].typ) || levl[x][y].typ == LAVAPOOL || levl[x][y].typ == ICE ? levl[x][y].typ : levl[x][y].floortyp;
            boolean is_water_or_air_level = (Is_airlevel(&u.uz) || Is_waterlevel(&u.uz));

            if (!(is_water_or_air_level && info.layer == LAYER_FLOOR) && (Underwater || !isok(x, above_y)
                || (levl[x][y].typ == levl[x][above_y].typ && get_location_category(levl[x][y].typ, levl[x][y].subtyp) == get_location_category(levl[x][above_y].typ, levl[x][above_y].subtyp))
                || (level.flags.hero_memory && levl[x][above_y].hero_memory_layers.glyph == cmap_to_glyph(S_unexplored))
                || levl[x][above_y].typ == UNEXPLORED || (IS_SOLID_FLOOR(floortype) && (IS_DOORJOIN(levl[x][above_y].typ)))))
            {
                /* No action */
            }
            else
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                int tileidx = -1;
                /* Kludge for water and air levels */
                if (is_water_or_air_level && info.layer == LAYER_FLOOR)
                {
                    struct layer_info this_l = layers_at(x, y);
                    struct layer_info above_l = layers_at(x, above_y);
                    int this_g = this_l.layer_glyphs[info.layer];
                    int above_g = above_l.layer_glyphs[info.layer];
                    int this_cmap = generic_glyph_to_cmap(this_g);
                    int above_cmap = generic_glyph_to_cmap(above_g);
                    if (this_cmap == above_cmap)
                        return ntile;

                    if (above_cmap == S_water)
                        tileidx = MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 6;
                    else if (above_cmap == S_cloud)
                        tileidx = MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 5;
                    else if (above_cmap == S_air)
                        tileidx = MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4;
                    else
                        tileidx = get_shore_tile_index(&levl[x][y], &levl[x][above_y]);
                }
                else
                    tileidx = get_shore_tile_index(&levl[x][y], &levl[x][above_y]);

                if (tileidx < 0 || tileidx >= MAX_TILES_PER_REPLACEMENT || (replacements[replacement_idx].tile_flags[tileidx] & RTF_SKIP))
                    return ntile;

                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[tileidx];
                return glyph2tile[tileidx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }

            break;
        }
        case REPLACEMENT_ACTION_SHORE_ADJUSTED_TILE:
        {
            int above_y = y - 1;
            if (Underwater || !isok(x, above_y) || levl[x][above_y].hero_memory_layers.glyph == cmap_to_glyph(S_unexplored)
                || levl[x][above_y].typ == UNEXPLORED)
            {
                /* No action */
            }
            else if (levl[x][above_y].typ == DRAWBRIDGE_DOWN || levl[x][above_y].typ == LAVAPOOL || levl[x][above_y].typ == LAVAPOOL || levl[x][above_y].typ == POOL || levl[x][above_y].typ == MOAT || levl[x][above_y].typ == WATER || levl[x][above_y].typ == DRAWBRIDGE_UP)
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                int tileidx = 0;
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[tileidx];

                return glyph2tile[tileidx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }

            break;
        }        
        case REPLACEMENT_ACTION_FLOOR_ADJUSTED_TILE:
        {
            if (Underwater || levl[x][y].hero_memory_layers.glyph == cmap_to_glyph(S_unexplored)
                || !IS_SOLID_FLOOR(levl[x][y].floortyp))
            {
                /* No action */
            }
            else
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;
                int tileidx = get_solid_floor_tile_index(&levl[x][y]);
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[tileidx];
                return glyph2tile[tileidx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        case REPLACEMENT_ACTION_SHORE_AND_FLOOR_ADJUSTED_TILE:
        {
            int above_y = y - 1;
            int left_x = x - 1;
            int right_x = x + 1;
            if (Underwater || levl[x][y].hero_memory_layers.glyph == cmap_to_glyph(S_unexplored)
                || !IS_SOLID_FLOOR(levl[x][y].floortyp))
            {
                /* No action */
            }
            else
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;
                int tileidx = get_shore_and_floor_adjusted_tile_index(&levl[x][y], isok(x, above_y) ? &levl[x][above_y] : 0, isok(left_x, y) ? &levl[left_x][y] : 0, isok(right_x, y) ? &levl[right_x][y] : 0);
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[tileidx];
                return glyph2tile[tileidx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        case REPLACEMENT_ACTION_OBJECT_LIT:
        {
            if (!otmp)
                return ntile;

            if (is_obj_activated(otmp))
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                /* Return the first tile with index 0 */
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[0];
                return glyph2tile[0 + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        case REPLACEMENT_ACTION_LOCATION_LIT:
        {
            if (isok(x, y) && get_location_light_range(x, y) != 0 && levl[x][y].lamplit == TRUE)
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                /* Return the first tile with index 0 */
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[0];
                return glyph2tile[0 + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        case REPLACEMENT_ACTION_LOCATION_HORIZONTAL:
        {
            if (isok(x, y) && levl[x][y].horizontal == TRUE)
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                /* Return the first tile with index 0 */
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[0];
                return glyph2tile[0 + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        case REPLACEMENT_ACTION_LEVER_STATE:
        {
            struct trap* ttmp = 0;
            unsigned long leverstate = 0UL;
            if (isok(x, y) && (ttmp = t_at(x, y)) != 0 && ttmp->ttyp == LEVER && (leverstate = ttmp->tflags & TRAPFLAGS_STATE_MASK) > 0)
            {
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].general_autodraw;

                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                int glyph_idx = max(0, min((int)replacements[replacement_idx].number_of_tiles, (int)leverstate) - 1);
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[glyph_idx];

                return glyph2tile[glyph_idx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }        
        case REPLACEMENT_ACTION_COIN_QUANTITY:
        {
            if (!otmp)
                return ntile;

            if (autodraw_ptr)
                *autodraw_ptr = replacements[replacement_idx].general_autodraw;

            if (replacements[replacement_idx].number_of_tiles < 1)
                return ntile;

            if (otmp->quan > 1)
            {
                int glyph_idx = (otmp->quan <= 6 ? 0 : 1);
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[glyph_idx];
                return glyph2tile[glyph_idx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        case REPLACEMENT_ACTION_CHEST:
        {
            if (!otmp)
                return ntile;

            if (autodraw_ptr)
                *autodraw_ptr = replacements[replacement_idx].general_autodraw;

            if (replacements[replacement_idx].number_of_tiles < 1)
                return ntile;

            if (otmp->olocked)
            {
                int glyph_idx = 0;
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[glyph_idx];
                return glyph2tile[glyph_idx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            else if (otmp->obroken)
            {
                int glyph_idx = 1;
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[glyph_idx];
                return glyph2tile[glyph_idx + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        case REPLACEMENT_ACTION_AUTODRAW:
        {
            if (autodraw_ptr)
                *autodraw_ptr = replacements[replacement_idx].general_autodraw;
            break;
        }
        case REPLACEMENT_ACTION_AUTODRAW_AND_OBJECT_LIT:
        {
            if (!otmp)
                return ntile;

            if (autodraw_ptr)
                *autodraw_ptr = replacements[replacement_idx].general_autodraw;

            if (is_obj_activated(otmp))
            {
                if (replacements[replacement_idx].number_of_tiles < 1)
                    return ntile;

                /* Return the first tile with index 0 */
                if (autodraw_ptr)
                    *autodraw_ptr = replacements[replacement_idx].tile_autodraw[0];
                return glyph2tile[0 + replacements[replacement_idx].glyph_offset + GLYPH_REPLACEMENT_OFF];
            }
            break;
        }
        default:
            break;
        }
    }
#endif
    return ntile;
}

STATIC_OVL int
get_shore_tile_index(mainlev, lev)
struct rm* mainlev, *lev;
{
    int mainlev_is_pool_ice_or_lava = (mainlev && (IS_POOL(mainlev->typ) || mainlev->typ == ICE || mainlev->typ == LAVAPOOL));
    if (lev->typ == WATER)
    {
        if (mainlev->typ == WATER)
            return -1;
        else
            return MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 6;
    }
    else if (lev->typ == CLOUD)
    {
        if (mainlev->typ == CLOUD)
            return -1;
        else
            return MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 5;
    }
    else if (lev->typ == AIR)
    {
        if (mainlev->typ == AIR)
            return -1;
        else
            return MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 4;
    }
    else if (lev->typ == DRAWBRIDGE_DOWN)
    {
        return MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 3;
    }
    else if (lev->typ == LAVAPOOL || (lev->typ == DRAWBRIDGE_UP && lev->flags & DB_LAVA))
    {
        if(mainlev->typ == LAVAPOOL)
            return -1;
        else
            return MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 2;
    }
    else if (lev->typ == ICE || (lev->typ == DRAWBRIDGE_UP && lev->flags & DB_ICE))
    {
        if (mainlev->typ == ICE)
            return -1;
        else
            return MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 1;
    }
    else if ((IS_POOL(lev->typ) && lev->typ != DRAWBRIDGE_UP) || (lev->typ == DRAWBRIDGE_UP && (lev->flags & DB_UNDER) == DB_MOAT))
    {
        if (IS_POOL(mainlev->typ))
            return -1;
        else
            return MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES + 0;
    }
    else if (lev->typ == CORR)
    {
        if ((!mainlev_is_pool_ice_or_lava && mainlev->typ == lev->typ && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->typ, lev->subtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->typ && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->typ, lev->subtyp))
            )
            return -1;
        else
            return get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES;
    }
    else if (!IS_FLOOR(lev->typ) && lev->floortyp == CORR)
    {
        if ((!mainlev_is_pool_ice_or_lava && IS_FURNITURE(lev->typ) && mainlev->typ == lev->floortyp && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->floortyp && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            )
            return -1;
        else
            return get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES;
    }
    else if (lev->typ == GROUND || (lev->typ == DRAWBRIDGE_UP && lev->flags & DB_GROUND))
    {
        if ((!mainlev_is_pool_ice_or_lava &&  mainlev->typ == lev->typ && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->typ, lev->subtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->typ && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->typ, lev->subtyp))
            )
            return -1;
        else
            return get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES;
    }
    else if (!IS_FLOOR(lev->typ) && lev->floortyp == GROUND)
    {
        if ((!mainlev_is_pool_ice_or_lava && IS_FURNITURE(lev->typ) && mainlev->typ == lev->floortyp && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->floortyp && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            )
            return -1;
        else
            return get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES;
    }
    else if (lev->typ == GRASS)
    {
        if ((!mainlev_is_pool_ice_or_lava && mainlev->typ == lev->typ && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->typ, lev->subtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->typ && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->typ, lev->subtyp))
            )
            return -1;
        else
            return get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES;
    }
    else if (!IS_FLOOR(lev->typ) && lev->floortyp == GRASS)
    {
        if ((!mainlev_is_pool_ice_or_lava && IS_FURNITURE(lev->typ) && mainlev->typ == lev->floortyp && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->floortyp && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            )
            return -1;
        else
            return get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES;
    }
    else if (lev->typ == ROOM)
    {
        if ((!mainlev_is_pool_ice_or_lava && mainlev->typ == lev->typ && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->typ, lev->subtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->typ && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->typ, lev->subtyp))
            )
            return -1;
        else
            return get_location_category(lev->typ, lev->subtyp);
    }
    else if (!IS_FLOOR(lev->typ) && lev->floortyp == ROOM)
    {
        if ((!mainlev_is_pool_ice_or_lava && IS_FURNITURE(lev->typ) && mainlev->typ == lev->floortyp && get_location_category(mainlev->typ, mainlev->subtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            || (!mainlev_is_pool_ice_or_lava && IS_FURNITURE(mainlev->typ) && mainlev->floortyp == lev->floortyp && get_location_category(mainlev->floortyp, mainlev->floorsubtyp) == get_location_category(lev->floortyp, lev->floorsubtyp))
            )
            return -1;
        else
            return get_location_category(lev->floortyp, lev->floorsubtyp);
    }

    return 0;
}


STATIC_OVL int
get_solid_floor_tile_index(lev)
struct rm* lev;
{
    if (lev->typ == CORR)
    {
        return get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES;
    }
    else if (lev->floortyp == CORR)
    {
        return get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES;
    }
    else if (lev->typ == GROUND)
    {
        return get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES;
    }
    else if (lev->floortyp == GROUND)
    {
        return get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES;
    }
    else if (lev->typ == GRASS)
    {
        return get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES;
    }
    else if (lev->floortyp == GRASS)
    {
        return get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES;
    }
    else if (lev->typ == ROOM)
    {
        return get_location_category(lev->typ, lev->subtyp);
    }
    else if (lev->floortyp == ROOM)
    {
        return get_location_category(lev->floortyp, lev->floorsubtyp);
    }

    return 0;
}

STATIC_OVL int
get_shore_and_floor_adjusted_tile_index(lev, above_lev, left_lev, right_lev)
struct rm *lev, *above_lev, *left_lev, *right_lev;
{
    int typ = 0;


    if (lev->typ == CORR)
    {
        typ = get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES;
    }
    else if (lev->floortyp == CORR)
    {
        typ = get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES;
    }
    else if (lev->typ == GROUND)
    {
        typ = get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES;
    }
    else if (lev->floortyp == GROUND)
    {
        typ = get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES;
    }
    else if (lev->typ == GRASS)
    {
        typ = get_location_category(lev->typ, lev->subtyp) + MAX_FLOOR_CATEGORIES;
    }
    else if (lev->floortyp == GRASS)
    {
        typ = get_location_category(lev->floortyp, lev->floorsubtyp) + MAX_FLOOR_CATEGORIES;
    }
    else if (lev->typ == ROOM)
    {
        typ = get_location_category(lev->typ, lev->subtyp);
    }
    else if (lev->floortyp == ROOM)
    {
        typ = get_location_category(lev->floortyp, lev->floorsubtyp);
    }

    if ((above_lev && (IS_POOL(above_lev->typ) || above_lev->typ == LAVAPOOL || above_lev->typ == ICE))
        || (left_lev && (IS_POOL(left_lev->typ) || left_lev->typ == LAVAPOOL || left_lev->typ == ICE))
        || (right_lev && (IS_POOL(right_lev->typ) || right_lev->typ == LAVAPOOL || right_lev->typ == ICE))
        )
    {
        /* Pick smaller version */
        typ += MAX_FLOOR_CATEGORIES + MAX_GRASS_CATEGORIES + MAX_GROUND_CATEGORIES + MAX_CORRIDOR_CATEGORIES;
    }

    return typ;
}

short
maybe_get_animated_tile(ntile, tile_animation_idx, play_type, interval_counter, frame_idx_ptr, main_tile_idx_ptr, mapAnimated, autodraw_ptr)
short ntile;
int tile_animation_idx;
enum animation_play_types play_type;
unsigned long interval_counter;
int *frame_idx_ptr, *main_tile_idx_ptr;
boolean* mapAnimated;
enum autodraw_types* autodraw_ptr;
{
#ifdef USE_TILES
    if (frame_idx_ptr)
        *frame_idx_ptr = -1;
    if (main_tile_idx_ptr)
        *main_tile_idx_ptr = -1;

    short animation_idx = tile2animation[ntile];
    if (animation_idx > 0)
    {
        if (autodraw_ptr)
            *autodraw_ptr = animations[animation_idx].main_tile_autodraw;
        if (animations[animation_idx].number_of_frames < 1)
            return ntile;
        if (animations[animation_idx].play_type != play_type)
            return ntile;

        if (mapAnimated)
            *mapAnimated = TRUE;

        char main_tile_frame_position = -1; /* ignore */
        if (animations[animation_idx].main_tile_use_style == ANIMATION_MAIN_TILE_USE_FIRST)
        {
            main_tile_frame_position = 0;
        }
        else if (animations[animation_idx].main_tile_use_style == ANIMATION_MAIN_TILE_USE_LAST)
        {
            main_tile_frame_position = animations[animation_idx].number_of_frames;
        }
        if (main_tile_idx_ptr)
            *main_tile_idx_ptr = main_tile_frame_position;
        char additional_tile_num = (main_tile_frame_position > -1 ? 1 : 0);
        char animation_tile_offset = (main_tile_frame_position == 0 ? 1 : 0);
        unsigned long numframes = (unsigned long)(animations[animation_idx].number_of_frames + additional_tile_num); /* add original tile as the first tile and frame */
        char current_animation_frame = (char)((interval_counter / (unsigned long)animations[animation_idx].intervals_between_frames) % numframes);
        if (frame_idx_ptr)
            *frame_idx_ptr = current_animation_frame;
        
        /* Separately played animations are played only once, and once the numframes is exceeded, the animation stops */
        if (play_type == ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY 
            && (interval_counter / (unsigned long)animations[animation_idx].intervals_between_frames) >= numframes)
            return ntile;

        if (current_animation_frame != main_tile_frame_position) /* 0 is the original picture */
        {
            char animation_frame_index = current_animation_frame - animation_tile_offset;
            if (animation_frame_index >= animations[animation_idx].number_of_frames)
            {
                return ntile; /* original tile is the last if number_of_frames is exceeded by numframes */
            }

            if (autodraw_ptr)
                *autodraw_ptr = animations[animation_idx].frame_autodraw[animation_frame_index];

            int tile_anim_idx = (tile_animation_idx < 0 || tile_animation_idx >= animations[animation_idx].number_of_tile_animations ? 0 : tile_animation_idx);
            int animation_glyph = (int)animation_frame_index + tile_anim_idx * animations[animation_idx].number_of_frames + animations[animation_idx].glyph_offset + GLYPH_ANIMATION_OFF;
            short res = glyph2tile[animation_glyph]; /* animated version selected */
            return res;
        }
    }
#endif
    return ntile;
}


int
get_tile_animation_index_from_glyph(glyph)
int glyph;
{
    int absglyph = abs(glyph);
    if (glyph_is_swallow(absglyph))
    {
        int glyph_idx = absglyph - GLYPH_SWALLOW_OFF;
        int char_idx = glyph_idx % MAX_SWALLOW_CHARS;
        return char_idx;
    }
    else if (glyph_is_explosion(absglyph))
    {
        int glyph_idx = absglyph - GLYPH_EXPLODE_OFF;
        int char_idx = glyph_idx % MAX_EXPLOSION_CHARS;
        return char_idx;
    }
    else if (glyph_is_zap(absglyph))
    {
        int glyph_idx = absglyph - GLYPH_ZAP_OFF;
        int char_idx = glyph_idx % MAX_ZAP_CHARS;
        return char_idx;
    }
    else
        return 0;

}

short
get_player_enlargement(action, roleidx, raceidx, genderidx, alignmentidx, levelidx)
enum action_tile_types action;
int roleidx, raceidx, genderidx, alignmentidx, levelidx;
{
    /* Write here the code that returns the right enlargement for the combination that has an enlargement */
    switch (action)
    {
    case ACTION_TILE_NO_ACTION:
        break;
    case ACTION_TILE_ATTACK:
        break;
    case ACTION_TILE_THROW:
        break;
    case ACTION_TILE_FIRE:
        break;
    case ACTION_TILE_CAST_NODIR:
        break;
    case ACTION_TILE_CAST_DIR:
        break;
    case ACTION_TILE_SPECIAL_ATTACK:
        break;
    case ACTION_TILE_KICK:
        break;
    case ACTION_TILE_PASSIVE_DEFENSE:
        break;
    case ACTION_TILE_DEFEND:
        break;
    case ACTION_TILE_RECEIVE_DAMAGE:
        break;
    case ACTION_TILE_ITEM_USE:
        break;
    case ACTION_TILE_DOOR_USE:
        break;
    case ACTION_TILE_DEATH:
        break;
    case MAX_ACTION_TILES:
        break;
    default:
        break;
    }
    return 0;
}


short
get_animation_base_tile(animidx)
short animidx;
{
    for (int i = LOW_PM; i < NUM_MONSTERS; i++)
    {
        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
        {
            if (mons[i].animation.actions[action] == animidx)
                return glyph2tile[i + get_monster_action_glyph_offset(action, 0)];
        }
        if (mons[i].animation.statue == animidx)
            return glyph2tile[i + GLYPH_STATUE_OFF];
        if (mons[i].animation.corpse == animidx)
            return glyph2tile[i + GLYPH_BODY_OFF];

        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
        {
            if (mons[i].female_animation.actions[action] == animidx)
                return glyph2tile[i + get_monster_action_glyph_offset(action, 1)];
        }
        if (mons[i].female_animation.corpse == animidx)
            return glyph2tile[i + GLYPH_FEMALE_BODY_OFF];
        if (mons[i].female_animation.statue == animidx)
            return glyph2tile[i + GLYPH_FEMALE_STATUE_OFF];
    }

    for (int i = STRANGE_OBJECT; i < NUM_OBJECTS; i++)
    {
        if(obj_descr[objects[i].oc_descr_idx].stand_animation == animidx)
            return glyph2tile[i + GLYPH_OBJ_OFF];
    }

    for (int cmap_idx = 0; cmap_idx < MAX_CMAP_TYPES; cmap_idx++)
    {
        for (int i = 0; i < MAX_CMAPPED_CHARS; i++)
        {
            if (defsyms[i].stand_animation[cmap_idx] == animidx)
                return glyph2tile[i + GLYPH_CMAP_OFF];
            if (defsyms[i].broken_animation[cmap_idx] == animidx)
                return glyph2tile[i + GLYPH_BROKEN_CMAP_OFF];
        }

        for (int i = 0; i < MAX_VARIATIONS; i++)
        {
            if (defsym_variations[i].stand_animation[cmap_idx] == animidx)
                return glyph2tile[i + GLYPH_CMAP_VARIATION_OFF];
            if (defsym_variations[i].broken_animation[cmap_idx] == animidx)
                return glyph2tile[i + GLYPH_BROKEN_CMAP_VARIATION_OFF];
        }
    }

    for (int roleidx = 0; roleidx < NUM_ROLES; roleidx++)
    {
        for (int raceidx = 0; raceidx < NUM_RACES; raceidx++)
        {
            for (int genderidx = 0; genderidx <= 1; genderidx++)
            {
                for (int alignment = -1; alignment <= 1; alignment++)
                {
                    for (int level = 0; level < NUM_PLAYER_GLYPH_LEVELS; level++)
                    {
                        int player_glyph_index = player_to_glyph_index(roleidx, raceidx, genderidx, alignment, level);
                        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
                        {
                            if (get_player_animation(action, roleidx, raceidx, genderidx, alignment, level) == animidx)
                                return glyph2tile[player_glyph_index + get_player_action_glyph_offset(action)];
                        }
                    }
                }
            }
        }
    }

    /* Explosion */
    for (int i = 0; i < MAX_EXPLOSIONS; i++)
    {
        if (explosion_type_definitions[i].animation == animidx)
            return glyph2tile[i * MAX_EXPLOSION_CHARS + GLYPH_EXPLODE_OFF];
    }

    /* Zap */
    for (int i = 0; i < MAX_ZAP_TYPES; i++)
    {
        if (zap_type_definitions[i].animation == animidx)
            return glyph2tile[i * MAX_ZAP_CHARS + GLYPH_ZAP_OFF];
    }

    /* Swallow */
    for (int i = 0; i < NUM_MONSTERS; i++)
    {
        if (mons[i].animation.swallow == animidx || mons[i].female_animation.swallow == animidx)
            return glyph2tile[i * MAX_SWALLOW_CHARS + GLYPH_SWALLOW_OFF];
    }

    /* Special Effects */
    for (enum special_effect_types i = SPECIAL_EFFECT_TELEPORT_OUT; i < MAX_SPECIAL_EFFECTS; i++)
    {
        if (special_effects[i].animation == animidx)
            return glyph2tile[i + GLYPH_SPECIAL_EFFECT_OFF];
    }

    /* Cursors */
    for (enum game_cursor_types i = CURSOR_STYLE_GENERIC_CURSOR; i < MAX_CURSORS; i++)
    {
        if (game_cursors[i].animation == animidx)
            return glyph2tile[i + GLYPH_CURSOR_OFF];
    }

    /* Hit tiles */
    for (enum hit_tile_types i = HIT_TILE; i < MAX_HIT_TILES; i++)
    {
        if (hit_tile_definitions[i].animation == animidx)
            return glyph2tile[i + GLYPH_HIT_TILE_OFF];
    }

    /* UI Tiles */
    for (enum game_ui_tile_types i = DEATH_TILE; i < MAX_UI_TILES; i++)
    {
        if (ui_tile_component_array[i].animation == animidx)
            return glyph2tile[i + GLYPH_UI_TILE_OFF];
    }

    /* Replacement */
    for (int i = 1; i < MAX_REPLACEMENTS; i++)
    {
        for (int j = 0; j < replacements[i].number_of_tiles; j++)
        {
            if (replacements[i].tile_animation[j] == animidx)
                return glyph2tile[j + replacements[i].glyph_offset + GLYPH_REPLACEMENT_OFF];
        }
    }

    return -1;
}


short
get_enlargement_base_tile(enlidx, enl_anim_tile_idx)
short enlidx, enl_anim_tile_idx;
{
    for (int i = LOW_PM; i < NUM_MONSTERS; i++)
    {
        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
        {
            if (mons[i].enlargement.actions[action] == enlidx)
                return glyph2tile[i + get_monster_action_glyph_offset(action, 0)];
        }
        if (mons[i].enlargement.statue == enlidx)
            return glyph2tile[i + GLYPH_STATUE_OFF];
        if (mons[i].enlargement.corpse == enlidx)
            return glyph2tile[i + GLYPH_BODY_OFF];

        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
        {
            if (mons[i].female_enlargement.actions[action] == enlidx)
                return glyph2tile[i + get_monster_action_glyph_offset(action, 1)];
        }
        if (mons[i].female_enlargement.statue == enlidx)
            return glyph2tile[i + GLYPH_FEMALE_STATUE_OFF];
        if (mons[i].female_enlargement.corpse == enlidx)
            return glyph2tile[i + GLYPH_FEMALE_BODY_OFF];
    }

    for (int i = STRANGE_OBJECT; i < NUM_OBJECTS; i++)
    {
        if (obj_descr[objects[i].oc_descr_idx].enlargement == enlidx)
            return glyph2tile[i + GLYPH_OBJ_OFF];
    }

    for (int cmap_idx = 0; cmap_idx < MAX_CMAP_TYPES; cmap_idx++)
    {

        for (int i = 0; i < MAX_CMAPPED_CHARS; i++)
        {
            if (defsyms[i].enlargement[cmap_idx] == enlidx)
                return glyph2tile[i + cmap_idx * NUM_CMAP_TYPE_CHARS + GLYPH_CMAP_OFF];
            if (defsyms[i].broken_enlargement[cmap_idx] == enlidx)
                return glyph2tile[i + cmap_idx * NUM_CMAP_TYPE_CHARS + GLYPH_BROKEN_CMAP_OFF];
        }

        for (int i = 0; i < MAX_VARIATIONS; i++)
        {
            if (defsym_variations[i].enlargement[cmap_idx] == enlidx)
                return glyph2tile[i + cmap_idx * MAX_VARIATIONS + GLYPH_CMAP_VARIATION_OFF];
            if (defsym_variations[i].broken_enlargement[cmap_idx] == enlidx)
                return glyph2tile[i + cmap_idx * MAX_VARIATIONS + GLYPH_BROKEN_CMAP_VARIATION_OFF];
        }
    }

    for (int roleidx = 0; roleidx < NUM_ROLES; roleidx++)
    {
        for (int raceidx = 0; raceidx < NUM_RACES; raceidx++)
        {
            for (int genderidx = 0; genderidx <= 1; genderidx++)
            {
                for (int alignment = -1; alignment <= 1; alignment++)
                {
                    for (int level = 0; level < NUM_PLAYER_GLYPH_LEVELS; level++)
                    {
                        int player_glyph_index = player_to_glyph_index(roleidx, raceidx, genderidx, alignment, level);
                        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
                        {
                            if (get_player_enlargement(action, roleidx, raceidx, genderidx, alignment, level) == enlidx)
                                return glyph2tile[player_glyph_index + get_player_action_glyph_offset(action)];
                        }
                    }
                }
            }
        }
    }

    for (enum special_effect_types i = SPECIAL_EFFECT_TELEPORT_OUT; i < MAX_SPECIAL_EFFECTS; i++)
    {
        if (special_effects[i].enlargement == enlidx)
            return glyph2tile[i + GLYPH_SPECIAL_EFFECT_OFF];
    }

    for (enum game_cursor_types i = CURSOR_STYLE_GENERIC_CURSOR; i < MAX_CURSORS; i++)
    {
        if (game_cursors[i].enlargement == enlidx)
            return glyph2tile[i + GLYPH_CURSOR_OFF];
    }

    for (enum hit_tile_types i = HIT_TILE; i < MAX_HIT_TILES; i++)
    {
        if (hit_tile_definitions[i].enlargement == enlidx)
            return glyph2tile[i + GLYPH_HIT_TILE_OFF];
    }

    for (enum game_ui_tile_types i = DEATH_TILE; i < MAX_UI_TILES; i++)
    {
        if (ui_tile_component_array[i].enlargement == enlidx)
            return glyph2tile[i + GLYPH_UI_TILE_OFF];
    }


    /* Replacement */
    for (int i = 1; i < MAX_REPLACEMENTS; i++)
    {
        for (int j = 0; j < replacements[i].number_of_tiles; j++)
        {
            if (replacements[i].tile_enlargement[j] == enlidx)
                return glyph2tile[j + replacements[i].glyph_offset + GLYPH_REPLACEMENT_OFF];
        }
    }

    /* Animation */
    for (int i = 1; i < MAX_ANIMATIONS; i++)
    {
        for (int j = 0; j < animations[i].number_of_tiles; j++)
        {
            if (animations[i].tile_enlargement == enlidx && (enl_anim_tile_idx < 0 || enl_anim_tile_idx == j))
                return glyph2tile[get_animation_frame_with_tile(i, j) + animations[i].glyph_offset + GLYPH_ANIMATION_OFF];
        }
    }


    return -1;
}

int
get_animation_frame_with_tile(animidx, tileidx)
int animidx, tileidx;
{
    for (int i = 0; i < TOTAL_ANIMATION_FRAMES; i++)
    {
        if (animations[animidx].frame2tile[i] == tileidx)
            return i;
    }

    return 0;
}

short
get_replacement_base_tile(replacement_idx)
short replacement_idx;
{
    for (int i = LOW_PM; i < NUM_MONSTERS; i++)
    {
        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
        {
            if (mons[i].replacement.actions[action] == replacement_idx)
                return glyph2tile[i + get_monster_action_glyph_offset(action, 0)];
        }
        if (mons[i].replacement.statue == replacement_idx)
            return glyph2tile[i + GLYPH_STATUE_OFF];
        if (mons[i].replacement.corpse == replacement_idx)
            return glyph2tile[i + GLYPH_BODY_OFF];

        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
        {
            if (mons[i].female_replacement.actions[action] == replacement_idx)
                return glyph2tile[i + get_monster_action_glyph_offset(action, 1)];
        }
        if (mons[i].female_replacement.corpse == replacement_idx)
            return glyph2tile[i + GLYPH_FEMALE_BODY_OFF];
        if (mons[i].female_replacement.statue == replacement_idx)
            return glyph2tile[i + GLYPH_FEMALE_STATUE_OFF];
    }

    for (int i = STRANGE_OBJECT; i < NUM_OBJECTS; i++)
    {
        if (obj_descr[objects[i].oc_descr_idx].replacement == replacement_idx)
            return glyph2tile[i + GLYPH_OBJ_OFF];
    }

    for (int cmap_idx = 0; cmap_idx < MAX_CMAP_TYPES; cmap_idx++)
    {
        for (int i = 0; i < MAX_CMAPPED_CHARS; i++)
        {
            if (defsyms[i].replacement[cmap_idx] == replacement_idx)
                return glyph2tile[i + GLYPH_CMAP_OFF];
            if (defsyms[i].broken_replacement[cmap_idx] == replacement_idx)
                return glyph2tile[i + GLYPH_BROKEN_CMAP_OFF];
        }

        for (int i = 0; i < MAX_VARIATIONS; i++)
        {
            if (defsym_variations[i].replacement[cmap_idx] == replacement_idx)
                return glyph2tile[i + GLYPH_CMAP_VARIATION_OFF];
            if (defsym_variations[i].broken_replacement[cmap_idx] == replacement_idx)
                return glyph2tile[i + GLYPH_BROKEN_CMAP_VARIATION_OFF];
        }
    }

    for (int roleidx = 0; roleidx < NUM_ROLES; roleidx++)
    {
        for (int raceidx = 0; raceidx < NUM_RACES; raceidx++)
        {
            for (int genderidx = 0; genderidx <= 1; genderidx++)
            {
                for (int alignment = -1; alignment <= 1; alignment++)
                {
                    for (int level = 0; level < NUM_PLAYER_GLYPH_LEVELS; level++)
                    {
                        int player_glyph_index = player_to_glyph_index(roleidx, raceidx, genderidx, alignment, level);
                        for (enum action_tile_types action = ACTION_TILE_NO_ACTION; action < MAX_ACTION_TILES; action++)
                        {
                            if (get_player_replacement(action, roleidx, raceidx, genderidx, alignment, level) == replacement_idx)
                                return glyph2tile[player_glyph_index + get_player_action_glyph_offset(action)];
                        }
                    }
                }
            }
        }
    }

    for (enum special_effect_types i = SPECIAL_EFFECT_TELEPORT_OUT; i < MAX_SPECIAL_EFFECTS; i++)
    {
        if (special_effects[i].replacement == replacement_idx)
            return glyph2tile[i + GLYPH_SPECIAL_EFFECT_OFF];
    }

    for (enum game_cursor_types i = CURSOR_STYLE_GENERIC_CURSOR; i < MAX_CURSORS; i++)
    {
        if (game_cursors[i].replacement == replacement_idx)
            return glyph2tile[i + GLYPH_CURSOR_OFF];
    }

    for (enum hit_tile_types i = HIT_TILE; i < MAX_HIT_TILES; i++)
    {
        if (hit_tile_definitions[i].replacement == replacement_idx)
            return glyph2tile[i + GLYPH_HIT_TILE_OFF];
    }

    for (enum game_ui_tile_types i = DEATH_TILE; i < MAX_UI_TILES; i++)
    {
        if (ui_tile_component_array[i].replacement == replacement_idx)
            return glyph2tile[i + GLYPH_UI_TILE_OFF];
    }

    return -1;
}


void
play_special_effect_at(sp_effect, spef_number, x, y, force_visibility)
enum special_effect_types sp_effect;
int spef_number, x, y;
boolean force_visibility;
{
    if (iflags.using_gui_tiles && isok(x, y) && spef_number >= 0 && spef_number < MAX_PLAYED_SPECIAL_EFFECTS && (force_visibility || cansee(x, y)))
    {
        enum layer_types layer = special_effects[sp_effect].layer;
        context.spef_action_animation_layer[spef_number] = layer;
        context.spef_action_animation_x[spef_number] = x;
        context.spef_action_animation_y[spef_number] = y;
        context.spef_milliseconds_to_wait_until_action[spef_number] = 0;
        context.spef_milliseconds_to_wait_until_end[spef_number] = 0;
        context.force_allow_keyboard_commands = TRUE;
        show_glyph_on_layer(x, y, sp_effect + GLYPH_SPECIAL_EFFECT_OFF, layer);

        enum animation_types anim = special_effects[sp_effect].animation;
        if (anim > 0 && animations[anim].play_type == ANIMATION_PLAY_TYPE_PLAYED_SEPARATELY)
        {
            context.special_effect_animation_counter[spef_number] = 0;
            context.special_effect_animation_counter_on[spef_number] = TRUE;
            force_redraw_at(x, y);
            flush_screen(0);

            int framenum = animations[anim].number_of_frames + (animations[anim].main_tile_use_style != ANIMATION_MAIN_TILE_IGNORE ? 1 : 0);
            if (animations[anim].sound_play_frame <= -1)
            {
                context.spef_milliseconds_to_wait_until_action[spef_number] = (flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * animations[anim].intervals_between_frames * framenum;
            }
            else
            {
                if(animations[anim].sound_play_frame > 0)
                    delay_output_milliseconds((flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * animations[anim].intervals_between_frames * animations[anim].sound_play_frame);
  
                if (animations[anim].action_execution_frame > animations[anim].sound_play_frame)
                {
                    context.spef_milliseconds_to_wait_until_action[spef_number] = (flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * animations[anim].intervals_between_frames * (animations[anim].action_execution_frame - animations[anim].sound_play_frame);
                    if (animations[anim].action_execution_frame < framenum)
                        context.spef_milliseconds_to_wait_until_end[spef_number] = (flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * animations[anim].intervals_between_frames * (framenum - animations[anim].action_execution_frame);
                }
                else
                {
                    context.spef_milliseconds_to_wait_until_action[spef_number] = (flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * animations[anim].intervals_between_frames * (framenum - animations[anim].sound_play_frame);
                    context.spef_milliseconds_to_wait_until_end[spef_number] = 0UL;
                }
            }
        }
        else
        {
            force_redraw_at(x, y);
            flush_screen(0);
            if(special_effects[sp_effect].frames_to_sound > 0)
                delay_output_milliseconds((flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * special_effects[sp_effect].frames_to_sound);
            context.spef_milliseconds_to_wait_until_action[spef_number] = (flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * special_effects[sp_effect].frames_from_sound_to_action;
            context.spef_milliseconds_to_wait_until_end[spef_number] = (flags.animation_frame_interval_in_milliseconds > 0 ? flags.animation_frame_interval_in_milliseconds : ANIMATION_FRAME_INTERVAL) * special_effects[sp_effect].frames_from_action_to_end;
        }

    }
}

void
special_effect_wait_until_action(spef_number)
int spef_number;
{
    if (context.spef_milliseconds_to_wait_until_action[spef_number] > 0UL)
    {
        delay_output_milliseconds(context.spef_milliseconds_to_wait_until_action[spef_number]);
        context.spef_milliseconds_to_wait_until_action[spef_number] = 0UL;
    }
}

void
special_effect_wait_until_end(spef_number)
int spef_number;
{
    if (context.spef_milliseconds_to_wait_until_end[spef_number] > 0)
    {
        delay_output_milliseconds(context.spef_milliseconds_to_wait_until_end[spef_number]);
        context.spef_milliseconds_to_wait_until_end[spef_number] = 0UL;
    }

    context.special_effect_animation_counter_on[spef_number] = FALSE;
    context.special_effect_animation_counter[spef_number] = 0UL;
    context.spef_milliseconds_to_wait_until_action[spef_number] = 0UL;

    if (isok(context.spef_action_animation_x[spef_number], context.spef_action_animation_y[spef_number]))
    {
        show_glyph_on_layer(context.spef_action_animation_x[spef_number], context.spef_action_animation_y[spef_number], NO_GLYPH, context.spef_action_animation_layer[spef_number]);
        force_redraw_at(context.spef_action_animation_x[spef_number], context.spef_action_animation_y[spef_number]);
        flush_screen(0);
    }
    context.force_allow_keyboard_commands = FALSE;
}


/* animation.c */



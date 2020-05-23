/*
 * Layers. Copyright (c) Janne Gustafsson, 2020
 *
 */

#ifndef LAYER_H
#define LAYER_H

struct layer_info {
    int glyph; /* For ascii compatibility */
    int bkglyph; /* For ascii compatibility */

    int floor_glyph;
    int dungeon_feature_glyph;
    int object_glyph;
    int monster_glyph;
    int monster_effect_glyph;
    int environment_glyph;
    int general_effect_glyph;

    unsigned long layer_flags;

    /* Monster info for display */
    int current_hp;
    int max_hp;
    int current_mana;
    int max_mana;
    unsigned long condition_flags;

};

#define LFLAGS_M_PET                0x00000001UL
#define LFLAGS_M_DETECTED           0x00000002UL
#define LFLAGS_M_RIDDEN             0x00000004UL
#define LFLAGS_M_SADDLED            0x00000008UL

#define LFLAGS_O_THROWN             0x00000010UL
#define LFLAGS_O_FULL_SIZED         0x00000020UL
#define LFLAGS_O_DRAWN_IN_FRONT     0x00000040UL

#define LFLAGS_UNEXPLORED           0x00000100UL


#endif /* LAYER_H */
/*
 * Layers. Copyright (c) Janne Gustafsson, 2020
 *
 */

#ifndef LAYER_H
#define LAYER_H

enum layer_types
{
    LAYER_FLOOR = 0,
    LAYER_FEATURE,
    LAYER_DOODAD,
    LAYER_OBJECT,
    LAYER_MONSTER,
    LAYER_MONSTER_EFFECT,
    LAYER_MISSILE,
    LAYER_COVER,
    LAYER_ENVIRONMENT,
    LAYER_GENERAL_EFFECT,
    LAYER_GENERAL_UI,
    MAX_LAYERS
};


struct layer_info {
    int glyph; /* For ascii compatibility */
    int bkglyph; /* For ascii compatibility */

    int layer_glyphs[MAX_LAYERS];

    unsigned long layer_flags;

    /* Monster info for display */
    struct obj object_data;     /* Note not a pointer to avoid spurious pointers, do not use pointers within */
    struct monst monster_data;  /* Note not a pointer to avoid spurious pointers, do not use pointers within */

    int damage_displayed;

};

#define LFLAGS_M_PET                0x00000001UL
#define LFLAGS_M_PEACEFUL           0x00000002UL
#define LFLAGS_M_DETECTED           0x00000004UL
#define LFLAGS_M_RIDDEN             0x00000008UL
#define LFLAGS_M_SADDLED            0x00000010UL
#define LFLAGS_M_RECEIVING_DAMAGE   0x00000020UL
#define LFLAGS_M_YOU                0x00000080UL
#define LFLAGS_M_MASK               0x000000FFUL

#define LFLAGS_O_DRAWN_IN_FRONT     0x00000100UL
#define LFLAGS_O_PILE               0x00000200UL
#define LFLAGS_O_MASK               0x00000F00UL

#define LFLAGS_DISINTEGRATED        0x00001000UL
#define LFLAGS_PETRIFIED            0x00002000UL
#define LFLAGS_CAITIFF              0x00004000UL
#define LFLAGS_BACKSTAB             0x00008000UL
#define LFLAGS_BREAK_WEAPON         0x00010000UL
#define LFLAGS_SMASH                0x00020000UL
#define LFLAGS_STUNNED_FROM_BLOW    0x00040000UL
#define LFLAGS_EXPLODE              0x00080000UL

#define LFLAGS_UNEXPLORED           0x10000000UL
#define LFLAGS_CMAP_MASK            0xF0000000UL


#define CMAP_FLAG_FEATURE_LAYER 0x00
#define CMAP_FLAG_FLOOR_LAYER 0x01


#endif /* LAYER_H */
/* GnollHack 4.0	mapglyph.c	$NHDT-Date: 1552945095 2019/03/18 21:38:15 $  $NHDT-Branch: GnollHack-3.6.2-beta01 $:$NHDT-Revision: 1.48 $ */
/* Copyright (c) David Cohrs, 1991                                */
/* GnollHack may be freely redistributed.  See license for details. */

#include "hack.h"
#if defined(TTY_GRAPHICS)
#include "wintty.h" /* for prototype of has_color() only */
#endif
#include "color.h"
#include "artifact.h"
#include "artilist.h"
#define HI_DOMESTIC CLR_WHITE /* monst.c */

#if !defined(TTY_GRAPHICS)
#define has_color(n) TRUE
#endif

#ifdef TEXTCOLOR
static const int explcolors[] = {
    CLR_BLACK,   /* dark    */
    CLR_GREEN,   /* noxious */
    CLR_BROWN,   /* muddy   */
    CLR_BLUE,    /* wet     */
    CLR_MAGENTA, /* magical */
    CLR_ORANGE,  /* fiery   */
    CLR_WHITE,   /* frosty  */
};

#define zap_color(n) color = iflags.use_color ? zapcolors[n] : NO_COLOR
#define cmap_color(n,cmap_type_index) color = iflags.use_color ? defsyms[n].color[cmap_type_index] : NO_COLOR
#define cmap_variation_color(n,cmap_type_index) color = iflags.use_color ? defsym_variations[n].color[cmap_type_index] : NO_COLOR
#define obj_color(n) color = iflags.use_color ? objects[n].oc_color : NO_COLOR
#define artifact_color(n) color = iflags.use_color ? artilist[n].ocolor : NO_COLOR
#define mon_color(n) color = iflags.use_color ? mons[n].mcolor : NO_COLOR
#define invis_color(n) color = NO_COLOR
#define pet_color(n) color = iflags.use_color ? mons[n].mcolor : NO_COLOR
#define warn_color(n) \
    color = iflags.use_color ? def_warnsyms[n].color : NO_COLOR
#define explode_color(n) color = iflags.use_color ? explcolors[n] : NO_COLOR

#else /* no text color */

#define zap_color(n)
#define cmap_color(n,cmap_idx)
#define obj_color(n)
#define mon_color(n)
#define invis_color(n)
#define pet_color(c)
#define warn_color(n)
#define explode_color(n)
#endif

#if defined(USE_TILES) && defined(MSDOS)
#define HAS_ROGUE_IBM_GRAPHICS \
    (currentgraphics == ROGUESET && SYMHANDLING(H_IBM) && !iflags.grmode)
#else
#define HAS_ROGUE_IBM_GRAPHICS \
    (currentgraphics == ROGUESET && SYMHANDLING(H_IBM))
#endif

#define is_objpile(x,y) (!Hallucination && level.objects[(x)][(y)] \
                         && level.objects[(x)][(y)]->nexthere)

/*ARGSUSED*/
int
mapglyph(signed_glyph, ochar, ocolor, ospecial, x, y)
int signed_glyph, *ocolor, x, y;
int *ochar;
unsigned long *ospecial;
{
    register int offset, idx;
    int color = NO_COLOR;
    nhsym ch;
    unsigned special = 0;
    /* condense multiple tests in macro version down to single */
    boolean has_rogue_ibm_graphics = HAS_ROGUE_IBM_GRAPHICS;
    boolean has_rogue_color = (has_rogue_ibm_graphics
                               && symset[currentgraphics].nocolor == 0);

    int glyph = abs(signed_glyph);
    if(signed_glyph < 0)
        special |= MG_H_FLIP;

    /*
     *  Map the glyph back to a character and color.
     *
     *  Warning:  For speed, this makes an assumption on the order of
     *            offsets.  The order is set in display.h.
     */
    if ((offset = (glyph - GLYPH_CURSOR_OFF)) >= 0)
    {
        /* Should never arrive here, these are UI elements */
        idx = '_';
        color = CLR_GRAY;
    }
    else if (
        (offset = (glyph - GLYPH_PLAYER_DEATH_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_DOOR_USE_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_ITEM_USE_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_KICK_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_SPECIAL_ATTACK_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_CAST_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_FIRE_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_THROW_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_ATTACK_OFF)) >= 0
        || (offset = (glyph - GLYPH_PLAYER_OFF)) >= 0
        )
    {
        int mnum = (Upolyd || !flags.showrace ? u.umonnum : urace.monsternum);
        idx = mons[mnum >= LOW_PM ? mnum : PM_HUMAN].mlet + SYM_OFF_M;
        mon_color(mnum);
#ifdef TEXTCOLOR
        /* special case the hero for `showrace' option */
        if (iflags.use_color && x == u.ux && y == u.uy
            && flags.showrace && !Upolyd)
            color = HI_DOMESTIC;
#endif
    }
	else if ((offset = (glyph - GLYPH_ARTIFACT_MISSILE_OFF)) >= 0 
        || (offset = (glyph - GLYPH_ARTIFACT_INVENTORY_LIT_OFF)) >= 0
        || (offset = (glyph - GLYPH_ARTIFACT_LIT_OFF)) >= 0
        || (offset = (glyph - GLYPH_ARTIFACT_INVENTORY_OFF)) >= 0
        || (offset = (glyph - GLYPH_ARTIFACT_OFF)) >= 0
        )
    { /* an artifact */
		int objoffset = artilist[offset].otyp;				
		if (artilist[offset].maskotyp != STRANGE_OBJECT)
		{
			/* We always use maskotyp for base case if there is one, since the item is specified to look like one */
			objoffset = artilist[offset].maskotyp;
		}
		/* Select the right symbol */
		idx = objects[objoffset].oc_class + SYM_OFF_O;

		if (has_rogue_color && iflags.use_color)
        {
			switch (objects[objoffset].oc_class)
            {
			case COIN_CLASS:
				color = CLR_YELLOW;
				break;
			case FOOD_CLASS:
				color = CLR_RED;
				break;
			default:
				color = CLR_BRIGHT_BLUE;
				break;
			}
		}
		else
		{
			if(artilist[offset].ocolor == NO_COLOR)
				obj_color(objoffset);
			else
				artifact_color(offset);
		}
		if (objoffset != BOULDER && is_objpile(x, y))
			special |= MG_OBJPILE;
	}
    else if ((offset = (glyph - GLYPH_FEMALE_STATUE_OFF)) >= 0)
    { /* a statue */
        if (flags.classic_statue_symbol)
        {
            idx = ROCK_CLASS + SYM_OFF_O;
        }
        else
        {
            idx = mons[offset].mlet + SYM_OFF_M;
        }
        if (has_rogue_color)
            color = CLR_RED;
        else
            obj_color(STATUE);
        special |= MG_STATUE;
        if (is_objpile(x, y))
            special |= MG_OBJPILE;
    }
    else if ((offset = (glyph - GLYPH_STATUE_OFF)) >= 0)
    { /* a statue */
		if (flags.classic_statue_symbol)
		{
			idx = ROCK_CLASS + SYM_OFF_O;
		}
		else
		{
			idx = mons[offset].mlet + SYM_OFF_M;
		}
		if (has_rogue_color)
			color = CLR_RED;
		else
			obj_color(STATUE);
		special |= MG_STATUE;
        if (is_objpile(x,y))
            special |= MG_OBJPILE;
    }
    else if ((offset = (glyph - GLYPH_WARNING_OFF)) >= 0)
    { /* warn flash */
        idx = offset + SYM_OFF_W;
        if (has_rogue_color)
            color = NO_COLOR;
        else
            warn_color(offset);
    }
    else if ((offset = (glyph - GLYPH_SWALLOW_OFF)) >= 0) 
    { /* swallow */
        /* see swallow_to_glyph() in display.c */
        idx = (S_sw_tl + (offset & 0x7)) + SYM_OFF_P;
        if (has_rogue_color && iflags.use_color)
            color = NO_COLOR;
        else
            mon_color(offset >> 3);
    }
    else if ((offset = (glyph - GLYPH_ZAP_OFF)) >= 0)
    { /* zap beam */
        /* see zapdir_to_glyph() in display.c */
        idx = (S_vbeam + (offset & 0x3)) + SYM_OFF_P;
        if (has_rogue_color && iflags.use_color)
            color = NO_COLOR;
        else
            zap_color((offset >> 2));
    } 
    else if ((offset = (glyph - GLYPH_EXPLODE_OFF)) >= 0)
    { /* explosion */
        idx = ((offset % MAX_EXPLOSION_CHARS) + S_explode1) + SYM_OFF_P;
        explode_color(offset / MAX_EXPLOSION_CHARS);
    }
    else if ((offset = (glyph - GLYPH_CMAP_VARIATION_OFF)) >= 0 || (offset = (glyph - GLYPH_CMAP_OFF)) >= 0)
    { /* cmap */
        boolean is_variation = FALSE;
        if ((glyph - GLYPH_CMAP_VARIATION_OFF) >= 0)
            is_variation = TRUE;
        int cmap_type_idx = 0;
        int cmap_offset = 0;
        int variation_index = 0;

        if (is_variation)
        {
            cmap_type_idx = max(0, offset / MAX_VARIATIONS);
            variation_index = max(0, offset - cmap_type_idx * MAX_VARIATIONS);
            cmap_offset = defsym_variations[variation_index].base_screen_symbol;
            idx = cmap_offset + SYM_OFF_P;
        }
        else
        {
            cmap_type_idx = offset / CMAP_TYPE_CHAR_NUM;
            cmap_offset = offset - cmap_type_idx * CMAP_TYPE_CHAR_NUM;
            idx = cmap_offset + SYM_OFF_P;
        }

        if (cmap_offset == S_extra_boulder)
            idx = SYM_BOULDER + SYM_OFF_X;

        if (has_rogue_color && iflags.use_color) 
        {
            if (cmap_offset >= S_vwall && cmap_offset <= S_hoportcullis)
                color = CLR_BROWN;
            else if (cmap_offset >= S_arrow_trap && cmap_offset <= S_polymorph_trap)
                color = CLR_MAGENTA;
            else if (cmap_offset == S_corr || cmap_offset == S_litcorr)
                color = CLR_GRAY;
            else if (cmap_offset >= S_room && cmap_offset <= S_water
                     && cmap_offset != S_darkroom)
                color = CLR_GREEN;
            else
                color = NO_COLOR;
#ifdef TEXTCOLOR
        /* provide a visible difference if normal and lit corridor
           use the same symbol */
        } 
        else if (iflags.use_color && cmap_offset == S_litcorr
                   && showsyms[idx] == showsyms[S_corr + SYM_OFF_P])
        {
            color = CLR_WHITE;
#endif
        /* try to provide a visible difference between water and lava
           if they use the same symbol and color is disabled */
        } 
        else if (!iflags.use_color && cmap_offset == S_lava
                   && (showsyms[idx] == showsyms[S_pool + SYM_OFF_P]
                       || showsyms[idx] == showsyms[S_water + SYM_OFF_P]))
        {
            special |= MG_BW_LAVA;
        } 
        else
        {
            if (is_variation && !flags.classic_colors)
                cmap_variation_color(variation_index, cmap_type_idx);
            else
                cmap_color(cmap_offset, flags.classic_colors ? 0 : cmap_type_idx);

#if 0
            if (iflags.use_color && !flags.classic_colors)
            {
                if (Inhell && !level.flags.is_maze_lev &&
                    !Is_valley(&u.uz) && !Is_juiblex_level(&u.uz) && !Is_orcus_level(&u.uz) && !Is_sanctum(&u.uz) 
                    && !In_V_tower(&u.uz) && !Is_modron_level(&u.uz) && !Is_bovine_level(&u.uz)
                    )
                {
                    if (cmap_offset >= S_vwall && cmap_offset <= S_trwall)
                    {
                        color = CLR_ORANGE;
                    }
                    else if (cmap_offset == S_room || cmap_offset == S_litcorr)
                    {
                        color = CLR_YELLOW;
                    }
                    else if (cmap_offset == S_darkroom || cmap_offset == S_corr)
                    {
                        color = CLR_BROWN;
                    }
                }
                else if (In_mines(&u.uz))
                {
                    if (cmap_offset >= S_vwall && cmap_offset <= S_trwall)
                    {
                        //color = CLR_BROWN;
                    }
                }
            }
#endif
        }
    } 
    else if ((offset = (glyph - GLYPH_OBJ_MISSILE_OFF)) >= 0 
               || (offset = (glyph - GLYPH_OBJ_INVENTORY_LIT_OFF)) >= 0
               || (offset = (glyph - GLYPH_OBJ_LIT_OFF)) >= 0
               || (offset = (glyph - GLYPH_OBJ_INVENTORY_OFF)) >= 0
               || (offset = (glyph - GLYPH_OBJ_OFF)) >= 0
               )
    { /* object */
        if (glyph - GLYPH_OBJ_MISSILE_OFF >= 0)
            offset = offset / NUM_MISSILE_DIRS;

        idx = objects[offset].oc_class + SYM_OFF_O;
        if (offset == BOULDER)
            idx = SYM_BOULDER + SYM_OFF_X;
        if (has_rogue_color && iflags.use_color) 
        {
            switch (objects[offset].oc_class)
            {
            case COIN_CLASS:
                color = CLR_YELLOW;
                break;
            case FOOD_CLASS:
                color = CLR_RED;
                break;
            default:
                color = CLR_BRIGHT_BLUE;
                break;
            }
        } 
        else
        {
            if(offset == BOULDER)
                cmap_color(S_extra_boulder, flags.classic_colors ? 0 : get_current_cmap_type_index());
            else
                obj_color(offset);
        }
        if (offset != BOULDER && is_objpile(x,y))
            special |= MG_OBJPILE;

    }
    else if ((offset = (glyph - GLYPH_INVIS_OFF)) >= 0)
    { /* invisible */
        idx = SYM_INVISIBLE + SYM_OFF_X;
        if (has_rogue_color)
            color = NO_COLOR; /* no need to check iflags.use_color */
        else
            invis_color(offset);
        special |= MG_INVIS;
    }
    else if (
    (offset = (glyph - GLYPH_FEMALE_DEATH_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_DOOR_USE_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_ITEM_USE_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_KICK_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_SPECIAL_ATTACK_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_CAST_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_FIRE_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_THROW_OFF)) >= 0
    || (offset = (glyph - GLYPH_FEMALE_ATTACK_OFF)) >= 0
    )
    { /* a female attacking monster */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color && iflags.use_color)
        {
            if (x == u.ux && y == u.uy)
                /* actually player should be yellow-on-gray if in corridor */
                color = CLR_YELLOW;
            else
                color = NO_COLOR;
        }
        else
        {
            mon_color(offset);
    #ifdef TEXTCOLOR
            /* special case the hero for `showrace' option */
            if (iflags.use_color && x == u.ux && y == u.uy
                && flags.showrace && !Upolyd)
                color = HI_DOMESTIC;
    #endif
        }
    }
    else if ((offset = (glyph - GLYPH_FEMALE_RIDDEN_OFF)) >= 0)
    { /* mon ridden */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color)
            /* This currently implies that the hero is here -- monsters */
            /* don't ride (yet...).  Should we set it to yellow like in */
            /* the monster case below?  There is no equivalent in rogue. */
            color = NO_COLOR; /* no need to check iflags.use_color */
        else
            mon_color(offset);
        special |= MG_RIDDEN;
    }
    else if ((offset = (glyph - GLYPH_FEMALE_BODY_OFF)) >= 0)
    { /* a corpse */
        idx = objects[CORPSE].oc_class + SYM_OFF_O;
        if (has_rogue_color && iflags.use_color)
            color = CLR_RED;
        else
            mon_color(offset);
        special |= MG_CORPSE;
        if (is_objpile(x, y))
            special |= MG_OBJPILE;
    }
    else if ((offset = (glyph - GLYPH_FEMALE_DETECT_OFF)) >= 0)
    { /* female mon detect */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color)
            color = NO_COLOR; /* no need to check iflags.use_color */
        else
            mon_color(offset);
        /* Disabled for now; anyone want to get reverse video to work? */
        /* is_reverse = TRUE; */
        special |= MG_DETECT;
    }
    else if ((offset = (glyph - GLYPH_FEMALE_PET_OFF)) >= 0)
    { /* a pet */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color)
            color = NO_COLOR; /* no need to check iflags.use_color */
        else
            pet_color(offset);
        special |= MG_PET;
    }
    else if ((offset = (glyph - GLYPH_FEMALE_MON_OFF)) >= 0)
    { /* a female monster */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color && iflags.use_color)
        {
            if (x == u.ux && y == u.uy)
                /* actually player should be yellow-on-gray if in corridor */
                color = CLR_YELLOW;
            else
                color = NO_COLOR;
        }
        else
        {
            mon_color(offset);
    #ifdef TEXTCOLOR
            /* special case the hero for `showrace' option */
            if (iflags.use_color && x == u.ux && y == u.uy
                && flags.showrace && !Upolyd)
                color = HI_DOMESTIC;
    #endif
        }
    }
    else if (
    (offset = (glyph - GLYPH_DEATH_OFF)) >= 0
    || (offset = (glyph - GLYPH_DOOR_USE_OFF)) >= 0
    || (offset = (glyph - GLYPH_ITEM_USE_OFF)) >= 0
    || (offset = (glyph - GLYPH_KICK_OFF)) >= 0
    || (offset = (glyph - GLYPH_SPECIAL_ATTACK_OFF)) >= 0
    || (offset = (glyph - GLYPH_CAST_OFF)) >= 0
    || (offset = (glyph - GLYPH_FIRE_OFF)) >= 0
    || (offset = (glyph - GLYPH_THROW_OFF)) >= 0
    || (offset = (glyph - GLYPH_ATTACK_OFF)) >= 0
    )
    { /* mon attack */
        idx = mons[glyph].mlet + SYM_OFF_M;
        if (has_rogue_color && iflags.use_color)
        {
            if (x == u.ux && y == u.uy)
                /* actually player should be yellow-on-gray if in corridor */
                color = CLR_YELLOW;
            else
                color = NO_COLOR;
        }
        else
        {
            mon_color(glyph);
    #ifdef TEXTCOLOR
            /* special case the hero for `showrace' option */
            if (iflags.use_color && x == u.ux && y == u.uy
                && flags.showrace && !Upolyd)
                color = HI_DOMESTIC;
    #endif
        }
    }
    else if ((offset = (glyph - GLYPH_RIDDEN_OFF)) >= 0)
    { /* mon ridden */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color)
            /* This currently implies that the hero is here -- monsters */
            /* don't ride (yet...).  Should we set it to yellow like in */
            /* the monster case below?  There is no equivalent in rogue. */
            color = NO_COLOR; /* no need to check iflags.use_color */
        else
            mon_color(offset);
        special |= MG_RIDDEN;
    } 
    else if ((offset = (glyph - GLYPH_BODY_OFF)) >= 0)
    { /* a corpse */
        idx = objects[CORPSE].oc_class + SYM_OFF_O;
        if (has_rogue_color && iflags.use_color)
            color = CLR_RED;
        else
            mon_color(offset);
        special |= MG_CORPSE;
        if (is_objpile(x,y))
            special |= MG_OBJPILE;
    } 
    else if ((offset = (glyph - GLYPH_DETECT_OFF)) >= 0) 
    { /* mon detect */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color)
            color = NO_COLOR; /* no need to check iflags.use_color */
        else
            mon_color(offset);
        /* Disabled for now; anyone want to get reverse video to work? */
        /* is_reverse = TRUE; */
        special |= MG_DETECT;
    } 
    else if ((offset = (glyph - GLYPH_PET_OFF)) >= 0)
    { /* a pet */
        idx = mons[offset].mlet + SYM_OFF_M;
        if (has_rogue_color)
            color = NO_COLOR; /* no need to check iflags.use_color */
        else
            pet_color(offset);
        special |= MG_PET;
    } 
    else 
    { /* a monster */
        idx = mons[glyph].mlet + SYM_OFF_M;
        if (has_rogue_color && iflags.use_color)
        {
            if (x == u.ux && y == u.uy)
                /* actually player should be yellow-on-gray if in corridor */
                color = CLR_YELLOW;
            else
                color = NO_COLOR;
        }
        else 
        {
            mon_color(glyph);
#ifdef TEXTCOLOR
            /* special case the hero for `showrace' option */
            if (iflags.use_color && x == u.ux && y == u.uy
                && flags.showrace && !Upolyd)
                color = HI_DOMESTIC;
#endif
        }
    }

    ch = showsyms[idx];
#ifdef TEXTCOLOR
    /* Turn off color if no color defined, or rogue level w/o PC graphics. */
    if (!has_color(color) || (Is_rogue_level(&u.uz) && !has_rogue_color))
        color = NO_COLOR;
#endif

//    if (ch == ' ' && color != NO_COLOR)  /* Does not look very good */
//        special |= MG_STONE_INVERSE;

    *ochar = (int) ch;
    *ospecial = special;
#ifdef TEXTCOLOR
    *ocolor = color;
#else
    nhUse(ocolor);
#endif
    return idx;
}

char *
encglyph(glyph)
int glyph;
{
    static char encbuf[20]; /* 10+1 would suffice */

    Sprintf(encbuf, "\\G%04X%04X", context.rndencode, glyph);
    return encbuf;
}

char *
decode_mixed(buf, str)
char *buf;
const char *str;
{
    static const char hex[] = "00112233445566778899aAbBcCdDeEfF";
    char *put = buf;

    if (!str)
        return strcpy(buf, "");

    while (*str) {
        if (*str == '\\') {
            int rndchk, dcount, so, gv, ch = 0, oc = 0;
            unsigned long os = 0;
            const char *dp, *save_str;

            save_str = str++;
            switch (*str) {
            case 'G': /* glyph value \GXXXXNNNN*/
                rndchk = dcount = 0;
                for (++str; *str && ++dcount <= 4; ++str)
                    if ((dp = index(hex, *str)) != 0)
                        rndchk = (rndchk * 16) + ((int) (dp - hex) / 2);
                    else
                        break;
                if (rndchk == context.rndencode) {
                    gv = dcount = 0;
                    for (; *str && ++dcount <= 4; ++str)
                        if ((dp = index(hex, *str)) != 0)
                            gv = (gv * 16) + ((int) (dp - hex) / 2);
                        else
                            break;
                    so = mapglyph(gv, &ch, &oc, &os, 0, 0);
                    *put++ = showsyms[so];
                    /* 'str' is ready for the next loop iteration and '*str'
                       should not be copied at the end of this iteration */
                    continue;
                } else {
                    /* possible forgery - leave it the way it is */
                    str = save_str;
                }
                break;
#if 0
            case 'S': /* symbol offset */
                so = rndchk = dcount = 0;
                for (++str; *str && ++dcount <= 4; ++str)
                    if ((dp = index(hex, *str)) != 0)
                        rndchk = (rndchk * 16) + ((int) (dp - hex) / 2);
                    else
                        break;
                if (rndchk == context.rndencode) {
                    dcount = 0;
                    for (; *str && ++dcount <= 2; ++str)
                        if ((dp = index(hex, *str)) != 0)
                            so = (so * 16) + ((int) (dp - hex) / 2);
                        else
                            break;
                }
                *put++ = showsyms[so];
                break;
#endif
            case '\\':
                break;
            }
        }
        *put++ = *str++;
    }
    *put = '\0';
    return buf;
}

/*
 * This differs from putstr() because the str parameter can
 * contain a sequence of characters representing:
 *        \GXXXXNNNN    a glyph value, encoded by encglyph().
 *
 * For window ports that haven't yet written their own
 * XXX_putmixed() routine, this general one can be used.
 * It replaces the encoded glyph sequence with a single
 * showsyms[] char, then just passes that string onto
 * putstr().
 */

void
genl_putmixed(window, attr, str)
winid window;
int attr;
const char *str;
{
    char buf[BUFSZ];

    /* now send it to the normal putstr */
    putstr(window, attr, decode_mixed(buf, str));
}

/*mapglyph.c*/

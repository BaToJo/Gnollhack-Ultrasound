/* GnollHack 4.0 tiledata.c */
/* Copyright (c) Janne Gustafsson 2020.                           */
/* GnollHack may be freely redistributed.  See license for details. */

#include "hack.h"
#include "artifact.h"
#include "artilist.h"

#ifdef USE_TILES
short glyph2tile[MAX_GLYPH] = { 0 }; /* moved here from tile.c */
#endif

int
process_tiledata(tsd, process_style, save_file_name, tilemaparray) /* Save tile data / read tile data / count tiles */
struct tileset_definition* tsd;
int process_style;  /* 0 = save data to file, 1 = read data from file, 2 = count tiles */
const char* save_file_name;
short* tilemaparray;
{
    const char* fq_save = save_file_name;
    const char* tile_section_name;
    const char* set_name;
    int fd;
    short tile_count = 0;
    char buf[BUFSIZ];
    strcpy(buf, "");
    int glyph_offset = 0;

    if (process_style == 0)
    {
        (void)remove(fq_save);

#ifdef MAC
        fd = macopen(fq_save, O_WRONLY | O_TEXT | O_CREAT | O_TRUNC, TEXT_TYPE);
#else
        fd = open(fq_save, O_WRONLY | O_TEXT | O_CREAT | O_TRUNC, FCMASK);
#endif
    }

    /* Monster tiles */
    tile_section_name = "monsters";
    for (int gender = 0; gender <= 1; gender++)
    {
        if (gender == 1)
        {
            if (tsd->female_tile_style == 0)
                continue;
        }
        const char* gender_name = (gender == 0 ? "base" : "female");

        for (int spset = 0; spset < 6; spset++)
        {
            if (spset == 1 && !tsd->has_pet_tiles)
                continue;
            if (spset == 2 && !tsd->has_detect_tiles)
                continue;
            if (spset == 3 && !tsd->has_body_tiles)
                continue;
            if (spset == 4 && !tsd->ridden_tile_style)
                continue;
            if (spset == 5 && !tsd->has_statue_tiles)
                continue;

            set_name = (spset == 0 ? "normal" : spset == 1 ? "pet" : spset == 2 ? "detect" :
                spset == 3 ? "body" : spset == 4 ? "ridden" : "statue");
            for (int i = LOW_PM; i < NUM_MONSTERS; i++)
            {
                if (gender == 1)
                {
                    if (tsd->female_tile_style == 2 && !(mons[i].geno & G_FEMALE_TILE))
                        continue;
                }

                if (spset == 4)
                {
                    if (tsd->ridden_tile_style == 2 && !(mons[i].mflags1 & M1_STEED))
                        continue;
                }

                if (process_style == 0)
                {
                    Sprintf(buf, "%s,%s,%s,%s\n", tile_section_name, gender_name, set_name, mons[i].mname);
                    (void)write(fd, buf, strlen(buf));
                }
                else if (process_style == 1)
                {
                    int glyph_offset = (spset == 0 ? GLYPH_MON_OFF : spset == 1 ? GLYPH_PET_OFF : spset == 2 ? GLYPH_DETECT_OFF :
                        spset == 3 ? GLYPH_BODY_OFF : spset == 4 ? GLYPH_RIDDEN_OFF : GLYPH_STATUE_OFF);
                    int female_glyph_offset = (spset == 0 ? GLYPH_FEMALE_MON_OFF : spset == 1 ? GLYPH_FEMALE_PET_OFF : spset == 2 ? GLYPH_FEMALE_DETECT_OFF :
                        spset == 3 ? GLYPH_FEMALE_BODY_OFF : spset == 4 ? GLYPH_FEMALE_RIDDEN_OFF : GLYPH_FEMALE_STATUE_OFF);

                    if (gender == 0)
                    {
                        tilemaparray[i + glyph_offset] = tile_count;
                        if (spset == 0)
                        {
                            if (!tsd->has_pet_tiles)
                                tilemaparray[i + GLYPH_PET_OFF] = tile_count;
                            if (!tsd->has_detect_tiles)
                                tilemaparray[i + GLYPH_DETECT_OFF] = tile_count;
                            if (tsd->ridden_tile_style != 1)
                                tilemaparray[i + GLYPH_RIDDEN_OFF] = tile_count;
                        }
                    }

                    /* write female versions twice just in case, first as base monster, and then override as female, if we get here */
                    tilemaparray[i + female_glyph_offset] = tile_count;
                    if (spset == 0)
                    {
                        if (!tsd->has_pet_tiles)
                            tilemaparray[i + GLYPH_FEMALE_PET_OFF] = tile_count;
                        if (!tsd->has_detect_tiles)
                            tilemaparray[i + GLYPH_FEMALE_DETECT_OFF] = tile_count;
                        if (tsd->ridden_tile_style != 1)
                            tilemaparray[i + GLYPH_FEMALE_RIDDEN_OFF] = tile_count;
                    }
                }
                tile_count++;
            }
        }
    }

    const char* missile_direction_name_array[NUM_MISSILE_DIRS] = {
            "top-left", "top-center", "top-right",
            "middle-right",  "middle-left",
            "bottom-left", "bottom-center", "bottom-right" };

    /* Object tiles */
    tile_section_name = "objects";
    for (int j = 0; j <= 4; j++)
    {
        /* j == 0 -> Normal objs */
        /* j == 1 -> Inventory objs */
        /* j == 2 -> Lit objs */
        /* j == 3 -> Lit inventory objs */
        /* j == 4 -> Missile objs */

        if (j == 1 && !tsd->inventory_tile_style)
            continue;
        if (j == 2 && !tsd->lit_tile_style)
            continue;
        if (j == 3 && (!tsd->lit_tile_style || !tsd->inventory_tile_style))
            continue;
        if (j == 4 && !tsd->missile_tile_style)
            continue;

        boolean first_scroll_found = FALSE;
        int nameless_idx = 0;
        set_name = (j == 0 ? "normal" : j == 1 ? "inventory" : j == 2 ? "lit" : j == 3 ? "inventory lit" : "missile");
        glyph_offset =
            (j == 0 ? GLYPH_OBJ_OFF :
                j == 1 ? GLYPH_OBJ_INVENTORY_OFF :
                j == 2 ? GLYPH_OBJ_LIT_OFF :
                j == 3 ? GLYPH_OBJ_INVENTORY_LIT_OFF :
                GLYPH_OBJ_MISSILE_OFF);

        for (int i = STRANGE_OBJECT; i < NUM_OBJECTS; i++)
        {
            int missile_tile_num = (objects[i].oc_flags4 & O4_SINGLE_MISSILE_TILE) ? 1 : NUM_MISSILE_DIRS;

            if (j == 1)
            {
                if (tsd->inventory_tile_style == 2 && !(objects[i].oc_flags4 & O4_INVENTORY_TILE))
                    continue;
            }
            else if (j == 2)
            {
                if (tsd->lit_tile_style == 2 && !(objects[i].oc_flags4 & O4_LIT_TILE))
                    continue;
            }
            else if (j == 3)
            {
                if (tsd->inventory_tile_style == 2 && !(objects[i].oc_flags4 & O4_INVENTORY_TILE))
                    continue;
                if (tsd->lit_tile_style == 2 && !(objects[i].oc_flags4 & O4_LIT_TILE))
                    continue;
            }
            else if (j == 4)
            {
                if (tsd->missile_tile_style == 2 && !(objects[i].oc_flags4 & O4_MISSILE_TILE))
                    continue;
            }


            const char* oclass_name = def_oc_syms[objects[i].oc_class].name;
            /* Jump over gems that all look the same, just take pieces of glass and luckstone */
            if (objects[i].oc_class == GEM_CLASS)
            {
                if (i <= LAST_GEM || (i > LUCKSTONE && i <= FLINT))
                    continue;
            }
            else if (objects[i].oc_class == SCROLL_CLASS)
            {
                /* Special case for scrolls - they all look the same, except mail, so only two special cases */
                if (first_scroll_found)
                    continue;

                first_scroll_found = TRUE;

                /* First, generic scroll tile */
                if (process_style == 0)
                {
                    if (j == 4)
                    {
                        for (int n = 0; n < missile_tile_num; n++)
                        {
                            Sprintf(buf, "%s,%s,%s,%s,%s,%s\n", tile_section_name, set_name, oclass_name, 
                                "generic", "scroll", 
                                missile_tile_num == 1 ? "generic" : missile_direction_name_array[n]);
                            (void)write(fd, buf, strlen(buf));
                            tile_count++;
                        }
                    }
                    else
                    {
                        Sprintf(buf, "%s,%s,%s,%s,%s\n", tile_section_name, set_name, oclass_name, "generic", "scroll");
                        (void)write(fd, buf, strlen(buf));
                        tile_count++;
                    }
                }
                else if (process_style == 1)
                {
                    if (j == 4)
                    {
                        for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                        {
                            /* Found scroll */
                            tilemaparray[i * NUM_MISSILE_DIRS + n + glyph_offset] = tile_count;
                            
                            /* Add the tile to all scrolls */
                            for (int m = STRANGE_OBJECT; m < NUM_OBJECTS; m++)
                            {
                                if (objects[m].oc_class == SCROLL_CLASS)
                                {
                                    tilemaparray[m * NUM_MISSILE_DIRS + n + glyph_offset] = tile_count;
                                }
                            }
                            if(missile_tile_num != 1)
                                tile_count++;
                        }
                        if (missile_tile_num == 1)
                            tile_count++;
                    }
                    else
                    {
                        tilemaparray[i + glyph_offset] = tile_count;

                        /* Add the tile to all scrolls */
                        for (int m = STRANGE_OBJECT; m < NUM_OBJECTS; m++)
                        {
                            if (objects[m].oc_class == SCROLL_CLASS)
                            {
                                /* Other scroll's main tile */
                                tilemaparray[m + glyph_offset] = tile_count;

                                /* Add others if they do not have their own */
                                if (j == 0)
                                {
                                    if (tsd->inventory_tile_style != 1)
                                    {
                                        int glyph_offset3 = GLYPH_OBJ_INVENTORY_OFF;
                                        tilemaparray[m + glyph_offset3] = tile_count;
                                        if (tsd->lit_tile_style != 1)
                                        {
                                            int glyph_offset4 = GLYPH_OBJ_INVENTORY_LIT_OFF;
                                            tilemaparray[m + glyph_offset4] = tile_count;
                                        }
                                    }
                                    if (tsd->lit_tile_style != 1)
                                    {
                                        int glyph_offset4 = GLYPH_OBJ_LIT_OFF;
                                        tilemaparray[m + glyph_offset4] = tile_count;
                                    }
                                    if (tsd->missile_tile_style != 1)
                                    {
                                        int glyph_offset4 = GLYPH_OBJ_MISSILE_OFF;
                                        for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                                        {
                                            tilemaparray[m * NUM_MISSILE_DIRS + n + glyph_offset4] = tile_count;
                                        }
                                    }
                                }
                            }
                        }

                        tile_count++;
                    }
                }
                else
                {
                    if (j == 4)
                        tile_count += missile_tile_num;
                    else
                        tile_count++;
                }

                /* Second, scroll of mail */
                if (process_style == 0)
                {
                    if (j == 4)
                    {
                        for (int n = 0; n < missile_tile_num; n++)
                        {
                            Sprintf(buf, "%s,%s,%s,%s,%s,%s\n", tile_section_name, set_name, oclass_name, 
                                "mail", "envelope", 
                                missile_tile_num == 1 ? "generic" : missile_direction_name_array[n]);
                            (void)write(fd, buf, strlen(buf));
                            if(missile_tile_num != 1)
                                tile_count++;
                        }
                        if(missile_tile_num == 1)
                            tile_count++;
                    }
                    else
                    {
                        Sprintf(buf, "%s,%s,%s,%s,%s\n", tile_section_name, set_name, oclass_name, "mail", "envelope");
                        (void)write(fd, buf, strlen(buf));
                        tile_count++;
                    }
                }
                else if (process_style == 1)
                {
                    /* Add the tile the scroll "mail" */
                    if (j == 4)
                    {
                        for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                        {
#ifdef MAIL
                            tilemaparray[SCR_MAIL * NUM_MISSILE_DIRS + n + glyph_offset] = tile_count;
#endif
                            if(missile_tile_num != 1)
                                tile_count++;
                        }
                        if (missile_tile_num == 1)
                            tile_count++;
                    }
                    else
                    {
#ifdef MAIL
                        /* Main tile */
                        tilemaparray[SCR_MAIL + glyph_offset] = tile_count;

                        /* Add to others, if they have not tiles of their own */
                        if (j == 0)
                        {
                            if (tsd->inventory_tile_style != 1)
                            {
                                int glyph_offset3 = GLYPH_OBJ_INVENTORY_OFF;
                                tilemaparray[SCR_MAIL + glyph_offset3] = tile_count;
                                if (tsd->lit_tile_style != 1)
                                {
                                    int glyph_offset4 = GLYPH_OBJ_INVENTORY_LIT_OFF;
                                    tilemaparray[SCR_MAIL + glyph_offset4] = tile_count;
                                }
                            }
                            if (tsd->lit_tile_style != 1)
                            {
                                int glyph_offset4 = GLYPH_OBJ_LIT_OFF;
                                tilemaparray[SCR_MAIL + glyph_offset4] = tile_count;
                            }
                            if (tsd->missile_tile_style != 1)
                            {
                                int glyph_offset4 = GLYPH_OBJ_MISSILE_OFF;
                                for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                                {
                                    tilemaparray[SCR_MAIL * NUM_MISSILE_DIRS + n + glyph_offset4] = tile_count;
                                }
                            }
                        }
#endif
                        tile_count++;
                    }
                }
                else
                {
                    if (j == 4)
                        tile_count += missile_tile_num;
                    else
                        tile_count++;
                }

                /* Move to next item after having found the first scroll */
                continue;
            }

            /* Normal item case starts here */
            boolean nameless = !OBJ_NAME(objects[i]);
            boolean no_description = !obj_descr[objects[i].oc_name_idx].oc_descr;
            char nameless_name[BUFSZ];
            Sprintf(nameless_name, "nameless-%d", nameless_idx);
            if (!OBJ_NAME(objects[i]))
            {
                nameless = TRUE;
                nameless_idx++;
            }

            if (process_style == 0)
            {
                if (j == 4)
                {
                    for (int n = 0; n < missile_tile_num; n++)
                    {
                        Sprintf(buf, "%s,%s,%s,%s,%s,%s\n", tile_section_name, set_name, oclass_name,
                            nameless ? nameless_name : OBJ_NAME(objects[i]),
                            no_description ? "no description" : obj_descr[objects[i].oc_name_idx].oc_descr,
                            missile_tile_num == 1 ? "generic" : missile_direction_name_array[n]);
                        (void)write(fd, buf, strlen(buf));
                        tile_count++;
                    }
                }
                else
                {
                    Sprintf(buf, "%s,%s,%s,%s,%s\n", tile_section_name, set_name, oclass_name,
                        nameless ? nameless_name : OBJ_NAME(objects[i]),
                        no_description ? "no description" : obj_descr[objects[i].oc_name_idx].oc_descr
                    );
                    (void)write(fd, buf, strlen(buf));
                    tile_count++;
                }
            }
            else if (process_style == 1)
            {
                if (j == 4)
                {
                    for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                    {
                        /* Write to the tile to the main glyph */
                        tilemaparray[i * NUM_MISSILE_DIRS + n + glyph_offset] = tile_count;

                        /* If this is a piece of glass or luckstone, add the tile to all other gems with the same color; others have been skipped */
                        if (objects[i].oc_class == GEM_CLASS && (i > LAST_GEM && i <= LUCKSTONE))
                        {
                            for (int m = STRANGE_OBJECT; m < NUM_OBJECTS; m++)
                            {
                                if (objects[m].oc_class == GEM_CLASS
                                    && (m <= LAST_GEM || (m > LUCKSTONE && m <= FLINT))
                                    && objects[m].oc_color == objects[i].oc_color
                                    )
                                {
                                    /* Write to the tile to the main glyph */
                                    tilemaparray[m * NUM_MISSILE_DIRS + n + glyph_offset] = tile_count;

                                }
                            }
                        }
                        if(missile_tile_num != 1)
                            tile_count++;
                    }
                    if (missile_tile_num == 1)
                        tile_count++;
                }
                else
                {
                    /* Write to the tile to the main glyph */
                    tilemaparray[i + glyph_offset] = tile_count;

                    /* Write to the tile to the inventory, lit, and inventory lit glyphs if they do not have their own */
                    if (j == 0)
                    {
                        if (tsd->inventory_tile_style != 1)
                        {
                            int glyph_offset3 = GLYPH_OBJ_INVENTORY_OFF;
                            tilemaparray[i + glyph_offset3] = tile_count;
                            if (tsd->lit_tile_style != 1)
                            {
                                int glyph_offset4 = GLYPH_OBJ_INVENTORY_LIT_OFF;
                                tilemaparray[i + glyph_offset4] = tile_count;
                            }
                        }
                        if (tsd->lit_tile_style != 1)
                        {
                            int glyph_offset4 = GLYPH_OBJ_LIT_OFF;
                            tilemaparray[i + glyph_offset4] = tile_count;
                        }
                        if (tsd->missile_tile_style != 1)
                        {
                            int glyph_offset4 = GLYPH_OBJ_MISSILE_OFF;
                            for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                            {
                                tilemaparray[i * NUM_MISSILE_DIRS + n + glyph_offset4] = tile_count;
                            }
                        }
                    }

                    /* If this is a piece of glass or luckstone, add the tile to all other gems with the same color; others have been skipped */
                    if (objects[i].oc_class == GEM_CLASS && (i > LAST_GEM && i <= LUCKSTONE))
                    {
                        for (int m = STRANGE_OBJECT; m < NUM_OBJECTS; m++)
                        {
                            if (objects[m].oc_class == GEM_CLASS
                                && (m <= LAST_GEM || (m > LUCKSTONE && m <= FLINT))
                                && objects[m].oc_color == objects[i].oc_color
                                )
                            {
                                /* Write to the tile to the main glyph */
                                tilemaparray[m + glyph_offset] = tile_count;

                                /* Write to the tile to the inventory, lit, and inventory lit glyphs if they do not have their own */
                                if (j == 0)
                                {
                                    if (tsd->inventory_tile_style != 1)
                                    {
                                        int glyph_offset3 = GLYPH_OBJ_INVENTORY_OFF;
                                        tilemaparray[m + glyph_offset3] = tile_count;
                                        if (tsd->lit_tile_style != 1)
                                        {
                                            int glyph_offset4 = GLYPH_OBJ_INVENTORY_LIT_OFF;
                                            tilemaparray[i + glyph_offset4] = tile_count;
                                        }
                                    }
                                    if (tsd->lit_tile_style != 1)
                                    {
                                        int glyph_offset4 = GLYPH_OBJ_LIT_OFF;
                                        tilemaparray[m + glyph_offset4] = tile_count;
                                    }
                                    if (tsd->missile_tile_style != 1)
                                    {
                                        int glyph_offset4 = GLYPH_OBJ_MISSILE_OFF;
                                        for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                                        {
                                            tilemaparray[m * NUM_MISSILE_DIRS + n + glyph_offset4] = tile_count;
                                        }
                                    }
                                }
                            }
                        }
                    }

                    /* Write generic corpse and statue tiles */
                    if (j == 0 &&
                        (!tsd->has_body_tiles && i == CORPSE)
                        || (!tsd->has_statue_tiles && i == STATUE)
                        )
                    {
                        for (int gender = 0; gender <= 1; gender++)
                        {
                            for (int k = LOW_PM; k < NUM_MONSTERS; k++)
                            {
                                int glyph_offset2 = (gender == 0 ? (i == CORPSE ? GLYPH_BODY_OFF : GLYPH_STATUE_OFF) : (i == CORPSE ? GLYPH_FEMALE_BODY_OFF : GLYPH_FEMALE_STATUE_OFF));
                                tilemaparray[k + glyph_offset2] = tile_count;
                            }
                        }
                    }


                    tile_count++;
                }
            }
            else
            {
                if (j == 4)
                    tile_count += missile_tile_num;
                else
                    tile_count++;
            }
        }
    }

    /* Artifact tiles */
    tile_section_name = "artifacts";
    for (int j = 0; j <= 4; j++)
    {
        if (j == 1 && !tsd->inventory_tile_style)
            continue;
        if (j == 2 && !tsd->lit_tile_style)
            continue;
        if (j == 3 && (!tsd->lit_tile_style || !tsd->inventory_tile_style))
            continue;
        if (j == 4 && !tsd->missile_tile_style)
            continue;

        set_name = (j == 0 ? "normal" : j == 1 ? "inventory" : j == 2 ? "lit" : j == 3 ? "inventory lit" : "missile");
        glyph_offset = (j == 0 ? GLYPH_ARTIFACT_OFF : 
            j == 1 ? GLYPH_ARTIFACT_INVENTORY_OFF :
            j == 2 ? GLYPH_ARTIFACT_LIT_OFF :
            j == 3 ? GLYPH_ARTIFACT_INVENTORY_LIT_OFF :
            GLYPH_ARTIFACT_MISSILE_OFF);

        for (int i = 1; i <= NUM_ARTIFACTS; i++)
        {
            int missile_tile_num = (artilist[i].aflags2 & AF2_SINGLE_MISSILE_TILE) ? 1 : NUM_MISSILE_DIRS;

            if (j == 1)
            {
                if (tsd->inventory_tile_style == 2 && !(artilist[i].aflags2 & AF2_INVENTORY_TILE))
                    continue;
            }
            else if (j == 2)
            {
                if (tsd->lit_tile_style == 2 && !(artilist[i].aflags2 & AF2_LIT_TILE))
                    continue;
            }
            else if (j == 3)
            {
                if (tsd->inventory_tile_style == 2 && !(artilist[i].aflags2 & AF2_INVENTORY_TILE))
                    continue;
                if (tsd->lit_tile_style == 2 && !(artilist[i].aflags2 & AF2_LIT_TILE))
                    continue;
            }
            else if (j == 4)
            {
                if (tsd->missile_tile_style == 2 && !(artilist[i].aflags2 & AF2_MISSILE_TILE))
                    continue;
            }


            int base_item = artilist[i].otyp;
            boolean no_description = !artilist[i].desc;
            boolean no_base_item_name = !OBJ_NAME(objects[base_item]);
            boolean no_base_item_description = !obj_descr[objects[base_item].oc_name_idx].oc_descr;
            if (process_style == 0)
            {
                if (j == 4)
                {
                    for (int n = 0; n < missile_tile_num; n++)
                    {
                        Sprintf(buf, "%s,%s,%s,%s,%s,%s,%s\n", tile_section_name, set_name,
                            artilist[i].name,
                            no_description ? "no artifact description" : artilist[i].desc,
                            no_base_item_name ? "nameless base item" : OBJ_NAME(objects[base_item]),
                            no_base_item_description ? "no base item description" : obj_descr[objects[base_item].oc_name_idx].oc_descr,
                            missile_tile_num == 1 ? "generic " : missile_direction_name_array[n]
                        );
                        (void)write(fd, buf, strlen(buf));
                        tile_count++;
                    }
                }
                else
                {
                    Sprintf(buf, "%s,%s,%s,%s,%s,%s\n", tile_section_name, set_name,
                        artilist[i].name,
                        no_description ? "no artifact description" : artilist[i].desc,
                        no_base_item_name ? "nameless base item" : OBJ_NAME(objects[base_item]),
                        no_base_item_description ? "no base item description" : obj_descr[objects[base_item].oc_name_idx].oc_descr
                    );
                    (void)write(fd, buf, strlen(buf));
                    tile_count++;

                }
            }
            else if (process_style == 1)
            {
                if (j == 4)
                {
                    for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                    {
                        tilemaparray[(i - 1) * NUM_MISSILE_DIRS + n + glyph_offset] = tile_count;
                        if(missile_tile_num != 1)
                            tile_count++;
                    }
                    if (missile_tile_num == 1)
                        tile_count++;
                }
                else
                {
                    if (j == 0)
                    {
                        if (tsd->inventory_tile_style != 1)
                        {
                            int glyph_offset3 = GLYPH_ARTIFACT_INVENTORY_OFF;
                            tilemaparray[(i - 1) + glyph_offset3] = tile_count;
                            if (tsd->lit_tile_style != 1)
                            {
                                int glyph_offset4 = GLYPH_ARTIFACT_INVENTORY_LIT_OFF;
                                tilemaparray[(i - 1) + glyph_offset4] = tile_count;
                            }
                        }
                        if (tsd->lit_tile_style != 1)
                        {
                            int glyph_offset4 = GLYPH_ARTIFACT_LIT_OFF;
                            tilemaparray[(i - 1) + glyph_offset4] = tile_count;
                        }
                        if (tsd->missile_tile_style != 1)
                        {
                            int glyph_offset4 = GLYPH_ARTIFACT_MISSILE_OFF;
                            for (int n = 0; n < NUM_MISSILE_DIRS; n++)
                            {
                                tilemaparray[(i - 1) * NUM_MISSILE_DIRS + n + glyph_offset4] = tile_count;
                            }
                        }
                    }
                    tilemaparray[(i - 1) + glyph_offset] = tile_count;
                    tile_count++;
                }
            }
            else
            {
                if (j == 4)
                    tile_count += missile_tile_num;
                else
                    tile_count++;
            }
        }
    }

    /* CMAP tiles */
    tile_section_name = "cmap";
    int num_cmaps = (tsd->has_full_cmap_set ? CMAP_TYPE_MAX : max(1, tsd->number_of_cmaps));
    for (int cmap_idx = 0; cmap_idx < num_cmaps; cmap_idx++)
    {
        char namebuf[BUFSZ];
        if (tsd->cmap_names[cmap_idx] && strcmp(tsd->cmap_names[cmap_idx], ""))
            Sprintf(namebuf, "%s", tsd->cmap_names[cmap_idx]);
        else
            Sprintf(namebuf, "unnamed-cmap-%d", cmap_idx);

        for (int i = 0; i < CMAP_TYPE_CHAR_NUM; i++)
        {
            if (cmap_idx > 0)
            {
                if (tsd->other_cmaps_have_only_walls == 1 && (i < S_vwall || i > S_trwall))
                    continue;
            }
            if (process_style == 0)
            {
                Sprintf(buf, "%s,%s,%s,%s\n", tile_section_name, tsd->has_full_cmap_set ? cmap_type_names[cmap_idx] : namebuf, get_cmap_tilename(i),
                    (defsyms[i].explanation && strcmp(defsyms[i].explanation, "")) ? defsyms[i].explanation : "no description");
                (void)write(fd, buf, strlen(buf));
            }
            else if (process_style == 1)
            {
                if (tsd->has_full_cmap_set)
                {
                    glyph_offset = GLYPH_CMAP_OFF + cmap_idx * CMAP_TYPE_CHAR_NUM;
                    tilemaparray[i + glyph_offset] = tile_count;
                    if (!tsd->has_variations && defsyms[i].variations > 0)
                    {
                        for (int m = 0; m < defsyms[i].variations; m++)
                        {
                            glyph_offset = GLYPH_CMAP_VARIATION_OFF + cmap_idx * MAX_VARIATIONS;
                            tilemaparray[m + defsyms[i].variation_offset+ glyph_offset] = tile_count;
                        }
                    }
                }
                else
                {
                    /* Go through all internal cmaps */
                    for (int k = 0; k < CMAP_TYPE_MAX; k++)
                    {
                        /* Write this cmap_idx for all internal CMAPs it is used for */
                        if (tsd->cmap_mapping[k] == cmap_idx)
                        {
                            glyph_offset = GLYPH_CMAP_OFF + k * CMAP_TYPE_CHAR_NUM;
                            tilemaparray[i + glyph_offset] = tile_count;
                            if (!tsd->has_variations && defsyms[i].variations > 0)
                            {
                                for (int m = 0; m < defsyms[i].variations; m++)
                                {
                                    glyph_offset = GLYPH_CMAP_VARIATION_OFF + cmap_idx * MAX_VARIATIONS;
                                    tilemaparray[m + defsyms[i].variation_offset + glyph_offset] = tile_count;
                                }
                            }
                        }
                    }
                }

                if (tsd->other_cmaps_have_only_walls == 1 && cmap_idx == 0 && num_cmaps > 1 && (i < S_vwall || i > S_trwall))
                {
                    /* copy non-walls to all other cmaps */
                    for (int k = 1; k < num_cmaps; k++)
                    {
                        int glyph_offset2 = GLYPH_CMAP_OFF + k * CMAP_TYPE_CHAR_NUM;
                        tilemaparray[i + glyph_offset2] = tile_count;
                        if (!tsd->has_variations && defsyms[i].variations > 0)
                        {
                            for (int m = 0; m < defsyms[i].variations; m++)
                            {
                                glyph_offset = GLYPH_CMAP_VARIATION_OFF + cmap_idx * MAX_VARIATIONS;
                                tilemaparray[m + defsyms[i].variation_offset + glyph_offset] = tile_count;
                            }
                        }
                    }
                }
            }
            tile_count++;
        }
    }

    if (tsd->has_variations)
    {
        /* CMAP variation tiles */
        tile_section_name = "cmap-variations";
        int num_cmaps = (tsd->has_full_cmap_set ? CMAP_TYPE_MAX : max(1, tsd->number_of_cmaps));
        for (int cmap_idx = 0; cmap_idx < num_cmaps; cmap_idx++)
        {
            char namebuf[BUFSZ];
            if (tsd->cmap_names[cmap_idx] && strcmp(tsd->cmap_names[cmap_idx], ""))
                Sprintf(namebuf, "%s", tsd->cmap_names[cmap_idx]);
            else
                Sprintf(namebuf, "unnamed-cmap-%d", cmap_idx);

            for (int i = 0; i < MAX_VARIATIONS; i++)
            {
                if (cmap_idx > 0)
                {
                    if (tsd->other_cmaps_have_only_walls == 1 && !is_wall_variation(i))
                        continue;
                }

                if (process_style == 0)
                {
                    Sprintf(buf, "%s,%s,%s\n", tile_section_name, tsd->has_full_cmap_set ? cmap_type_names[cmap_idx] : namebuf,
                        (defsym_variations[i].explanation && strcmp(defsym_variations[i].explanation, "")) ? defsym_variations[i].explanation : "no description");
                    (void)write(fd, buf, strlen(buf));
                }
                else if (process_style == 1)
                {
                    if (tsd->has_full_cmap_set)
                    {
                        glyph_offset = GLYPH_CMAP_VARIATION_OFF + cmap_idx * MAX_VARIATIONS;
                        tilemaparray[i + glyph_offset] = tile_count;
                    }
                    else
                    {
                        /* Go through all internal cmaps */
                        for (int k = 0; k < CMAP_TYPE_MAX; k++)
                        {
                            /* Write this cmap_idx for all internal CMAPs it is used for */
                            if (tsd->cmap_mapping[k] == cmap_idx)
                            {
                                glyph_offset = GLYPH_CMAP_VARIATION_OFF + k * MAX_VARIATIONS;
                                tilemaparray[i + glyph_offset] = tile_count;
                            }
                        }
                    }

                    if (tsd->other_cmaps_have_only_walls == 1 && cmap_idx == 0 && num_cmaps > 1 && !is_wall_variation(i))
                    {
                        /* copy non-walls to all other cmaps */
                        for (int k = 1; k < num_cmaps; k++)
                        {
                            int glyph_offset2 = GLYPH_CMAP_VARIATION_OFF + k * MAX_VARIATIONS;
                            tilemaparray[i + glyph_offset2] = tile_count;
                        }
                    }

                }
                tile_count++;
            }
        }
    }



    /* Miscellaneous tiles */
    tile_section_name = "misc";
    for (int misc_idx = 0; misc_idx < 5; misc_idx++)
    {
        set_name = (misc_idx == 0 ? "invisible" : misc_idx == 1 ? "explode" : misc_idx == 2 ? "zap" :
            misc_idx == 3 ? "swallow" : "warning");

        if (misc_idx == 0)
        {
            if (NUM_INVIS_GLYPHS == 1)
            {
                if (process_style == 0)
                {
                    Sprintf(buf, "%s,%s,generic\n", tile_section_name, set_name);
                    (void)write(fd, buf, strlen(buf));
                }
                else if (process_style == 1)
                {
                    tilemaparray[GLYPH_INVIS_OFF] = tile_count;
                }
                tile_count++;
            }
            else
            {
                for (int i = 0; i < NUM_INVIS_GLYPHS; i++)
                {
                    if (process_style == 0)
                    {
                        Sprintf(buf, "%s,%s,tile-%d\n", tile_section_name, set_name, i);
                        (void)write(fd, buf, strlen(buf));
                    }
                    else if (process_style == 1)
                    {
                        glyph_offset = GLYPH_INVIS_OFF;
                        tilemaparray[i + glyph_offset] = tile_count;
                    }
                    tile_count++;
                }
            }
        }
        else if (misc_idx == 1)
        {
            const char* explosion_direction_name_array[MAX_EXPLOSION_CHARS] = {
                    "top-left", "top-center", "top-right",
                    "middle-right", "middle-center", "middle-left",
                    "bottom-left", "bottom-center", "bottom-right" };

            if (tsd->has_all_explode_tiles == 0)
            {
                for (int i = 0; i < MAX_EXPLOSION_CHARS; i++)
                {
                    const char* explosion_direction_name = explosion_direction_name_array[i];

                    if (process_style == 0)
                    {
                        Sprintf(buf, "%s,%s,generic,%s\n", tile_section_name, set_name, explosion_direction_name);
                        (void)write(fd, buf, strlen(buf));
                    }
                    else if (process_style == 1)
                    {
                        for (int j = 0; j < EXPL_MAX; j++)
                        {
                            glyph_offset = GLYPH_EXPLODE_OFF + MAX_EXPLOSION_CHARS * j;
                            tilemaparray[i + glyph_offset] = tile_count;
                        }
                    }
                    tile_count++;
                }
            }
            else
            {
                for (int j = 0; j < EXPL_MAX; j++)
                {
                    const char* explosion_name = explosion_type_names[j];
                    for (int i = 0; i < MAX_EXPLOSION_CHARS; i++)
                    {
                        const char* explosion_direction_name = explosion_direction_name_array[i];
                        if (process_style == 0)
                        {
                            Sprintf(buf, "%s,%s,%s,%s\n", tile_section_name, set_name, explosion_name, explosion_direction_name);
                            (void)write(fd, buf, strlen(buf));
                        }
                        else if (process_style == 1)
                        {
                            glyph_offset = GLYPH_EXPLODE_OFF + MAX_EXPLOSION_CHARS * j;
                            tilemaparray[i + glyph_offset] = tile_count;
                        }
                        tile_count++;
                    }
                }
            }
        }
        else if (misc_idx == 2)
        {
            const char* zap_direction_name_array[MAX_ZAP_CHARS] = {
                "vertical", "horizontal", "diagonal-top-left-to-bottom-right", "diagonal-bottom-left-to-top-right" };

            if (tsd->has_all_zap_tiles == 0)
            {
                for (int i = 0; i < MAX_ZAP_CHARS; i++)
                {
                    const char* zap_direction_name = zap_direction_name_array[i];
                    if (process_style == 0)
                    {
                        Sprintf(buf, "%s,%s,generic,%s\n", tile_section_name, set_name, zap_direction_name);
                        (void)write(fd, buf, strlen(buf));
                    }
                    else if (process_style == 1)
                    {
                        for (int j = 0; j < NUM_ZAP; j++)
                        {
                            glyph_offset = GLYPH_ZAP_OFF + MAX_ZAP_CHARS * j;
                            tilemaparray[i + glyph_offset] = tile_count;
                        }
                    }
                    tile_count++;
                }
            }
            else
            {
                for (int j = 0; j < NUM_ZAP; j++)
                {
                    const char* zap_name_array[NUM_ZAP] = {
                        "magic", "fire", "frost", "sleep", "disintegration",
                        "lightning", "poison", "acid", "death",
                        "petrification" };
                    const char* zap_name = zap_name_array[j];

                    for (int i = 0; i < MAX_ZAP_CHARS; i++)
                    {
                        const char* zap_direction_name = zap_direction_name_array[i];
                        if (process_style == 0)
                        {
                            Sprintf(buf, "%s,%s,%s,%s\n", tile_section_name, set_name, zap_name, zap_direction_name);
                            (void)write(fd, buf, strlen(buf));
                        }
                        else if (process_style == 1)
                        {
                            glyph_offset = GLYPH_ZAP_OFF + MAX_ZAP_CHARS * j;
                            tilemaparray[i + glyph_offset] = tile_count;
                        }
                        tile_count++;
                    }
                }
            }
        }
        else if (misc_idx == 3)
        {
            const char* swallow_direction_name_array[MAX_SWALLOW_CHARS] = {
                    "top-left", "top-center", "top-right",
                    "middle-right", "middle-left",
                    "bottom-left", "bottom-center", "bottom-right" };

            if (tsd->swallow_tile_style == 0)
            {
                for (int i = 0; i < MAX_SWALLOW_CHARS; i++)
                {
                    const char* swallow_direction_name = swallow_direction_name_array[i];
                    if (process_style == 0)
                    {
                        Sprintf(buf, "%s,%s,generic,%s\n", tile_section_name, set_name, swallow_direction_name);
                        (void)write(fd, buf, strlen(buf));
                    }
                    else if (process_style == 1)
                    {
                        for (int j = 0; j < NUM_MONSTERS; j++)
                        {
                            glyph_offset = GLYPH_SWALLOW_OFF + MAX_SWALLOW_CHARS * j;
                            tilemaparray[i + glyph_offset] = tile_count;
                        }
                    }
                    tile_count++;
                }
            }
            else
            {
                boolean first_found = FALSE;
                for (int j = 0; j < NUM_MONSTERS; j++)
                {
                    if (tsd->swallow_tile_style == 2)
                    {
                        if (!attacktype(&mons[j], AT_ENGL))
                            continue;
                    }

                    for (int i = 0; i < MAX_SWALLOW_CHARS; i++)
                    {
                        const char* swallow_direction_name = swallow_direction_name_array[i];
                        if (process_style == 0)
                        {
                            Sprintf(buf, "%s,%s,%s,%s\n", tile_section_name, set_name, mons[j].mname, swallow_direction_name);
                            (void)write(fd, buf, strlen(buf));
                        }
                        else if (process_style == 1)
                        {
                            glyph_offset = GLYPH_SWALLOW_OFF + MAX_SWALLOW_CHARS * j;
                            tilemaparray[i + glyph_offset] = tile_count;
                        }
                        tile_count++;
                    }

                    /* Write the first found swallow tile set for all monsters, just in case */
                    if (tsd->swallow_tile_style == 2 && !first_found && process_style == 1)
                    {
                        first_found = TRUE;
                        for (int k = 0; k < NUM_MONSTERS; k++)
                        {
                            for (int m = 0; m < MAX_SWALLOW_CHARS; m++)
                            {
                                glyph_offset = GLYPH_SWALLOW_OFF + MAX_SWALLOW_CHARS * k;
                                tilemaparray[m + glyph_offset] = tile_count - MAX_SWALLOW_CHARS + m;
                            }
                        }
                    }
                }
            }
        }
        else if (misc_idx == 4)
        {
            for (int i = 0; i < WARNCOUNT; i++)
            {
                if (process_style == 0)
                {
                    Sprintf(buf, "%s,%s,warn-level-%d\n", tile_section_name, set_name, i);
                    (void)write(fd, buf, strlen(buf));
                }
                else if (process_style == 1)
                {
                    glyph_offset = GLYPH_WARNING_OFF;
                    tilemaparray[i + glyph_offset] = tile_count;
                }
                tile_count++;
            }
        }
    }


    /* Player tiles */
    tile_section_name = "player";
    if (tsd->player_tile_style == 0 || tsd->player_tile_style == 3) /* For style 3, fill out all cases with monster tiles, and override below */
    {
        /* Use player monster icons */
        if (process_style == 1)
        {
            for (int roleidx = 0; roleidx < NUM_ROLES; roleidx++)
            {
                int role_as_monster = roles[roleidx].monsternum;
                for (int raceidx = 0; raceidx < NUM_RACES; raceidx++)
                {
                    for (int gender = 0; gender <= 1; gender++)
                    {
                        for (int alignment = -1; alignment <= 1; alignment++)
                        {
                            for (int level = 0; level < NUM_PLAYER_GLYPH_LEVELS; level++)
                            {
                                int player_idx = player_to_glyph(roleidx, raceidx, gender, alignment + 1, level);
                                tilemaparray[player_idx] = tilemaparray[role_as_monster + ((gender == 0) ? GLYPH_MON_OFF : GLYPH_FEMALE_MON_OFF)];
                            }
                        }
                    }
                }
            }
        }
    }

    if (tsd->player_tile_style == 1)
    {
        if (process_style == 0)
        {
            Sprintf(buf, "%s,generic\n", tile_section_name);
            (void)write(fd, buf, strlen(buf));
        }
        else if (process_style == 1)
        {
            for (int roleidx = 0; roleidx < NUM_ROLES; roleidx++)
            {
                for (int raceidx = 0; raceidx < NUM_RACES; raceidx++)
                {
                    for (int gender = 0; gender <= 1; gender++)
                    {
                        for (int alignment = -1; alignment <= 1; alignment++)
                        {
                            for (int level = 0; level < NUM_PLAYER_GLYPH_LEVELS; level++)
                            {
                                int player_idx = player_to_glyph(roleidx, raceidx, gender, alignment + 1, level);
                                tilemaparray[player_idx] = tile_count;
                            }
                        }
                    }
                }
            }
        }
        tile_count++;
    }
    else if (tsd->player_tile_style == 2)
    {
        for (int roleidx = 0; roleidx < NUM_ROLES; roleidx++)
        {
            const char* role_name = roles[roleidx].name.m;
            for (int raceidx = 0; raceidx < NUM_RACES; raceidx++)
            {
                const char* race_name = races[raceidx].noun;
                for (int gender = 0; gender <= 1; gender++)
                {
                    const char* gender_name = (gender == 0 ? "male" : "female");
                    for (int alignment = -1; alignment <= 1; alignment++)
                    {
                        const char* align_name = (alignment == -1 ? "chaotic" : alignment == 0 ? "neutral" : alignment == 1 ? "lawful" : "unspecified");
                        for (int level = 0; level < NUM_PLAYER_GLYPH_LEVELS; level++)
                        {
                            if (process_style == 0)
                            {
                                Sprintf(buf, "%s,%s,%s,%s,%s,level-%d\n", tile_section_name, role_name, race_name, gender_name, align_name, level);
                                (void)write(fd, buf, strlen(buf));
                            }
                            else if (process_style == 1)
                            {
                                int player_idx = player_to_glyph(roleidx, raceidx, gender, alignment + 1, level);
                                tilemaparray[player_idx] = tile_count;
                            }
                            tile_count++;
                        }
                    }
                }
            }
        }
    }
    else if (tsd->player_tile_style == 3)
    {
        for (int roleidx = 0; roleidx < NUM_ROLES; roleidx++)
        {
            const char* role_name = roles[roleidx].name.m;
            for (int raceidx = 0; raceidx < NUM_RACES; raceidx++)
            {
                if (!validrace(roleidx, raceidx))
                    continue;

                const char* race_name = races[raceidx].noun;
                for (int gender = 0; gender <= 1; gender++)
                {
                    const char* gender_name = (gender == 0 ? "male" : "female");
                    for (int alignment = -1; alignment <= 1; alignment++)
                    {
                        if (alignment > -1 && !(roles[roleidx].allow & ROLE_ALIGNMENT_TILES))
                            continue;

                        const char* align_name = (roles[roleidx].allow & ROLE_ALIGNMENT_TILES) ? (alignment == -1 ? "chaotic" : alignment == 0 ? "neutral" : alignment == 1 ? "lawful" : "unspecified") : "any";
                        for (int level = 0; level < NUM_PLAYER_GLYPH_LEVELS; level++)
                        {
                            if (process_style == 0)
                            {
                                Sprintf(buf, "%s,%s,%s,%s,%s,level-%d\n", tile_section_name, role_name, race_name, gender_name, align_name, level);
                                (void)write(fd, buf, strlen(buf));
                            }
                            else if (process_style == 1)
                            {
                                if (alignment == -1 && !(roles[roleidx].allow & ROLE_ALIGNMENT_TILES))
                                {
                                    for (int k = 0; k <= 2; k++)
                                    {
                                        int player_idx = player_to_glyph(roleidx, raceidx, gender, k, level);
                                        tilemaparray[player_idx] = tile_count;
                                    }
                                }
                                else
                                {
                                    int player_idx = player_to_glyph(roleidx, raceidx, gender, alignment + 1, level);
                                    tilemaparray[player_idx] = tile_count;
                                }
                            }
                            tile_count++;
                        }
                    }
                }
            }
        }
    }

    if (process_style == 0)
    {
        /* Finished */
        (void)close(fd);
    }
    /* Nothing for other process_styles */

    return tile_count;
}


/*tiledata.c*/

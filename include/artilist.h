/* GnollHack 4.0  artilist.h      $NHDT-Date: 1433050874 2015/05/31 05:41:14 $  $NHDT-Branch: master $:$NHDT-Revision: 1.16 $ */
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/*-Copyright (c) Robert Patrick Rankin, 2017. */
/* GnollHack may be freely redistributed.  See license for details. */

#include "animation.h"
#include "general.h"

#ifdef MAKEDEFS_C
/* in makedefs.c, all we care about is the list of names */

#define GENERAL_ARTIFACT(nam, desc, hit_desc, typ, masktyp, exceptionality, mythic_prefix, mythic_suffix, aflags, aflags2, spfx, cspfx, mt, tohitdice, tohitsize, tohitplus, atk, dfn, cry, inv, inv_dur_dice, inv_dur_diesize, inv_dur_plus, manacost, repower, al, cl, rac, cost, glowclr, objclr, height, soundset, stand_anim, enlarge, replacement) nam
#define A(nam, desc, hit_desc, typ, masktyp, exceptionality, mythic_prefix, mythic_suffix, aflags, aflags2, spfx, cspfx, mt, tohitdice, tohitsize, tohitplus, atk, dfn, cry, inv, inv_dur_dice, inv_dur_diesize, inv_dur_plus, manacost, repower, al, cl, rac, cost, glowclr, objclr, height, soundset) nam

const char *artifact_names[] = {
#else
/* in artifact.c, set up the actual artifact list structure */

#define GENERAL_ARTIFACT(nam, desc, hit_desc, typ, masktyp, exceptionality, mythic_prefix, mythic_suffix, aflags, aflags2, spfx, cspfx, mt, tohitdice, tohitsize, tohitplus, atk, dfn, cry, inv, inv_dur_dice, inv_dur_diesize, inv_dur_plus, manacost, repower, al, cl, rac, cost, glowclr, objclr, height, soundset, stand_anim, enlarge, replacement) \
    {  typ, masktyp, nam, desc, hit_desc, exceptionality, mythic_prefix, mythic_suffix, aflags, aflags2, spfx, cspfx, mt, tohitdice, tohitsize, tohitplus, atk, dfn, cry, inv, inv_dur_dice, inv_dur_diesize, inv_dur_plus, manacost, repower, al, cl, rac, cost, glowclr, objclr, height, soundset, stand_anim, enlarge, replacement }

#define A(nam, desc, hit_desc, typ, masktyp, exceptionality, mythic_prefix, mythic_suffix, aflags, aflags2, spfx, cspfx, mt, tohitdice, tohitsize, tohitplus, atk, dfn, cry, inv, inv_dur_dice, inv_dur_diesize, inv_dur_plus, manacost, repower, al, cl, rac, cost, glowclr, objclr, height, soundset) \
    {  typ, masktyp, nam, desc, hit_desc, exceptionality, mythic_prefix, mythic_suffix, aflags, aflags2, spfx, cspfx, mt, tohitdice, tohitsize, tohitplus, atk, dfn, cry, inv, inv_dur_dice, inv_dur_diesize, inv_dur_plus, manacost, repower, al, cl, rac, cost, glowclr, objclr, height, soundset, NO_ANIMATION, NO_ENLARGEMENT, NO_REPLACEMENT }
//    GENERAL_ARTIFACT(nam, desc, hit_desc, typ, masktyp, aflags, aflags2, spfx, cspfx, mt, tohitdice, tohitsize, tohitplus, atk, dfn, cry, inv, inv_dur_dice, inv_dur_diesize, inv_dur_plus, manacost, repower, al, cl, rac, cost, glowclr, objclr, height, soundset, NO_ANIMATION, NO_ENLARGEMENT, NO_REPLACEMENT)

/* clang-format off */
#define     NO_ATTK          {0,0,0,0,0,0,0,0,0UL,0}               /* no attack */
#define     PHYS(a,b)        {0,AD_PHYS,a,b,0,0,0,0,0UL,0}         /* physical */
#define     PHYSI(a,b,c)     {0,AD_PHYS,a,b,c,0,0,0,0UL,0}         /* physical */
#define     DRLI(a,b)        {0,AD_DRLI,a,b,0,0,0,0,0UL,0}         /* life drain */
#define     COLD(a,b)        {0,AD_COLD,a,b,0,0,0,0,0UL,0}
#define     FIRE(a,b)        {0,AD_FIRE,a,b,0,0,0,0,0UL,0}
#define     ELEC(a,b)        {0,AD_ELEC,a,b,0,0,0,0,0UL,0}         /* electrical shock */
#define     STUN(a,b)        {0,AD_STUN,a,b,0,0,0,0,0UL,0}         /* magical attack */
/* clang-format on */

#define None (const char *)0

NEARDATA struct artifact artilist[] = {
#endif /* MAKEDEFS_C */

    /* Artifact cost rationale:
     * 1.  The more useful the artifact, the better its cost.
     * 2.  Quest artifacts are highly valued.
     * 3.  Chaotic artifacts are inflated due to scarcity (and balance).
     */

    /*  dummy element #0, so that all interesting indices are non-zero */
    A("", None, None, STRANGE_OBJECT, STRANGE_OBJECT, EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, AF_NONE, AF2_NONE, SPFX_NONE, SPFX_NONE, 0, 0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE,
      NON_PM, NON_PM, 0L, NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Excalibur", "gold-hilted long sword", None,  LONG_SWORD, LONG_SWORD,
      EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
        AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS | AF_MONSTERS_CAN_TRACK_ARTIFACT | AF_ANGERS_DEMONS,
      AF2_NAME_IS_PROPER_NAME,
      (SPFX_SEARCH), SPFX_NONE, 0,
      1, 5, 0, PHYS(1, 10), DRAIN_RESISTANCE, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, PM_KNIGHT, NON_PM, 4000L,
      NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),
    /*
     *      Stormbringer only has a 5 because it can drain a level,
     *      providing 8 + CON bonus more.
     */
    A("Stormbringer", "black runesword", "black blade", RUNESWORD, ELVEN_BROADSWORD,
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
        (AF_RESTR | AF_INTEL | AF_DRLI | AF_NAME_KNOWN_WHEN_PICKED_UP | AF_BLOODTHIRSTY),
        AF2_NAME_IS_PROPER_NAME,
        SPFX_DEATH_RES | SPFX_DRAIN_RES, SPFX_NONE, 0, 
        1, 5, 0, DRLI(1, 5), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_CHAOTIC, NON_PM, NON_PM, 8000L,
        NO_COLOR, CLR_BLACK, 0, OBJECT_SOUNDSET_NONE),
    /*
     *      Mjollnir will return to the hand of the wielder when thrown
     *      if the wielder is a Valkyrie wearing Gauntlets of Power.
     */
    A("Mjollnir", "runed war hammer", "massive hammer", HEAVY_WAR_HAMMER, WAR_HAMMER, /* Mjo:llnir */
       EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
       (AF_RESTR | AF_FAMOUS), AF2_MISSILE_TILE | AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, 0,
       1, 5, 0, ELEC(1, 20), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0,
      A_NEUTRAL, PM_VALKYRIE, NON_PM, 4000L, 
      NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    /* Note: Battle axe of cleaving is different, it mimicks the effect of Tsurugi of Muramasa --JG */
    A("Cleaver", "runed double-headed axe", None, BATTLE_AXE, BATTLE_AXE,  
      EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
      AF_RESTR | AF_HITS_ADJACENT_SQUARES, AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, 0,
      1, 3, 0, PHYS(1, 6), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NEUTRAL, PM_BARBARIAN, NON_PM, 1500L,
      NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    /*
     *      Grimtooth glows in warning when elves are present.
     */
    A("Grimtooth", "runed crude dagger", None, ORNAMENTAL_ORCISH_DAGGER, ORCISH_DAGGER,
      EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_ELF_SLAYING,
      (AF_RESTR | AF_DFLAG2 | AF_FLICKERS), AF2_NAME_IS_PROPER_NAME, SPFX_ELF_WARNING, SPFX_NONE, M2_ELF,
      1, 5, 0, PHYS(1, 10), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_CHAOTIC, NON_PM, PM_ORC, 500L,
      CLR_RED, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),
    /*
     *      Orcrist and Sting have same alignment as elves.
     *
     *      The combination of SPFX_WARN_OF_MON+SPFX_DFLAG2+M2_value will trigger
     *      EWarn_of_mon for all monsters that have the M2_value flag.
     *      Sting and Orcrist will warn of M2_ORC monsters.
     */
    A("Orcrist", "runed broadsword", None, ELVEN_BROADSWORD, ELVEN_BROADSWORD, 
      EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_ORC_SLAYING,
      (AF_DFLAG2 | AF_FLICKERS), AF2_NAME_IS_PROPER_NAME, SPFX_ORC_WARNING, SPFX_NONE, M2_ORC,
      1, 5, 0, PHYS(1, 20), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0,
      A_CHAOTIC, NON_PM, PM_ELF, 2000L,
      CLR_BRIGHT_BLUE, NO_COLOR, 0, OBJECT_SOUNDSET_NONE), /* bright blue is actually light blue */

    A("Sting", "runed dagger", None, ELVEN_RUNEDAGGER, ELVEN_DAGGER, 
         EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
         (AF_DFLAG2 | AF_FLICKERS), AF2_MISSILE_TILE | AF2_NAME_IS_PROPER_NAME, SPFX_ORC_WARNING, SPFX_NONE, M2_ORC,
         1, 5, 0, PHYS(1, 10), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_CHAOTIC, NON_PM, PM_ELF, 1000L, CLR_BRIGHT_BLUE, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),
    /*
     *      Magicbane is a bit different!  Its magic fanfare
     *      unbalances victims in addition to doing some damage.
     */
    A("Magicbane", "runed athame", None, ATHAME, ATHAME, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
        (AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED | AF_MAGIC_ABSORBING),
        AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, 0,
        1, 3, 0, STUN(1, 10), ANTIMAGIC, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NEUTRAL, PM_WIZARD, NON_PM, 3500L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Frost Brand", "iron-hilted long sword", "ice-cold blade", LONG_SWORD, LONG_SWORD, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
        (AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, COLD(ARTDMG_DOUBLE_DAMAGE, 0), COLD_IMMUNITY, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 3000L,
        NO_COLOR, CLR_WHITE, 0, OBJECT_SOUNDSET_NONE),

    A("Fire Brand", "copper-hilted long sword", "fiery blade", LONG_SWORD, LONG_SWORD, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
        (AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, FIRE(ARTDMG_DOUBLE_DAMAGE, 0), FIRE_IMMUNITY, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 3000L,
        NO_COLOR, CLR_RED, 0, OBJECT_SOUNDSET_NONE),

    A("Dragonbane", "mithril-hilted broadsword", None, BROADSWORD, BROADSWORD,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_DRAGON_SLAYING, 
        (AF_RESTR | AF_DCLAS | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_REFLECT, SPFX_NONE, S_DRAGON,
        1, 5, 0, PHYS(1, 20), WARN_DRAGON, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 500L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Demonbane", "runed silver long sword", None, SILVER_LONG_SWORD, SILVER_LONG_SWORD,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_DEMON_SLAYING, 
        (AF_RESTR | AF_DFLAG2 | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED | AF_ANGERS_DEMONS | AF_PREVENTS_SUMMONING_OF_MON),
        AF2_NAME_IS_PROPER_NAME,
        SPFX_DEMON_WARNING, SPFX_NONE, M2_DEMON,
        1, 5, 0, PHYS(1, 20), CURSE_RESISTANCE, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, NON_PM, NON_PM, 2500L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Werebane", "runed silver saber", None, SILVER_SABER, SILVER_SABER,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_LYCANTHROPE_SLAYING, 
        (AF_RESTR | AF_DFLAG2 | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, M2_WERE,
        1, 5, 0, PHYS(1, 20), WARN_LYCANTHROPE, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 1500L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Grayswandir", "diamond-encrusted silver saber", None, SILVER_SABER, SILVER_SABER, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_HALRES, SPFX_NONE, 0,
        1, 5, 0, PHYS(1, ARTDMG_DOUBLE_DAMAGE), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, NON_PM, NON_PM, 8000L,
        NO_COLOR, CLR_GRAY, 0, OBJECT_SOUNDSET_NONE),

    A("Giantslayer", "ruby-encrusted long sword", None, LONG_SWORD, LONG_SWORD,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_GIANT_SLAYING,
        (AF_RESTR | AF_DFLAG2 | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, M2_GIANT,
        1, 5, 0, PHYS(1, 20), WARN_GIANT, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NEUTRAL, NON_PM, NON_PM, 500L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Ogresmasher", "gold-hilted war hammer", None, WAR_HAMMER, WAR_HAMMER,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_OGRE_SLAYING, 
        (AF_RESTR | AF_DCLAS | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_CON_25, SPFX_NONE, S_OGRE,
        1, 5, 0, PHYS(1, 20), WARN_OGRE, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 500L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Trollsbane", "runed morning star", None, MORNING_STAR, MORNING_STAR,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_TROLL_SLAYING, 
        (AF_RESTR | AF_DCLAS | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NAME_IS_PROPER_NAME, SPFX_REGEN, SPFX_NONE, S_TROLL,
        1, 5, 0, PHYS(1, 20), WARN_TROLL, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 500L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Crossbow of the Gnoll Lords", "ornate repeating heavy crossbow", None, REPEATING_HEAVY_CROSSBOW, REPEATING_HEAVY_CROSSBOW, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED), AF2_NONE, SPFX_STLTH, SPFX_NONE, 0,
        1, 5, 0, PHYS(1, 5), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, PM_GNOLL, 2000L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("Howling Flail", "runed flail", None, RUNED_FLAIL, FLAIL, 
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, (AF_RESTR | AF_NAME_KNOWN_WHEN_INVOKED | AF_INVOKE_MAY_DRAIN_LIFE), AF2_NONE, SPFX_LUCK | SPFX_CHA_25, SPFX_NONE, 0,
        1, 5, 0, PHYS(1, 10), NO_POWER, NO_POWER, ARTINVOKE_TAMING, 0, 0, 0, 0, 200, A_CHAOTIC, NON_PM, PM_GNOLL, 6000L,
        NO_COLOR, HI_GOLD, 0, OBJECT_SOUNDSET_NONE),

    A("Luck Blade", "ornate broadsword", None, SWORD_OF_LUCKINESS, LONG_SWORD, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_NAME_KNOWN_WHEN_INVOKED | AF_NO_WISH | AF_INVOKE_EXPENDS_CHARGE), AF2_NONE, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, PHYS(1, 5), NO_POWER, NO_POWER, ARTINVOKE_WISHING, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 6000L, /* Note: Base item gives luck already */
        NO_COLOR, HI_METAL, 0, OBJECT_SOUNDSET_NONE),

    A("Wand of Orcus", "skull-headed obsidian mace", None, MACE_OF_THE_UNDERWORLD, MACE_OF_THE_UNDERWORLD, 
        EXCEPTIONALITY_INFERNAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_FAMOUS | AF_INVOKE_EXPENDS_CHARGE | AF_NO_WISH), AF2_NONE, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, DRLI(1, 10), NO_POWER, NO_POWER, ARTINVOKE_WAND_OF_DEATH, 0, 0, 0, 0, 150, A_CHAOTIC, NON_PM, NON_PM, 6000L,
        NO_COLOR, CLR_BLACK, 0, OBJECT_SOUNDSET_NONE),

    A("Triple-Headed Flail of Yeenoghu", "runed triple-headed flail", None, TRIPLE_HEADED_FLAIL, TRIPLE_HEADED_FLAIL,
        EXCEPTIONALITY_INFERNAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_FAMOUS | AF_NO_WISH | AF_DRLI), AF2_NONE, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, PHYS(1, 5), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_CHAOTIC, NON_PM, NON_PM, 4000L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("Rhongomyniad", "runed lance", None, LANCE, LANCE,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_FAMOUS), AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, PHYS(ARTDMG_TRIPLE_DAMAGE, 0), MAGIC_MISSILE_IMMUNITY, CURSE_RESISTANCE, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, PM_KNIGHT, NON_PM, 2500L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    /*
     *      Two problems:  1) doesn't let trolls regenerate heads,
     *      2) doesn't give unusual message for 2-headed monsters (but
     *      allowing those at all causes more problems than worth the effort).
     */
    A("Vorpal Blade", "runed long sword", "Vorpal Blade", LONG_SWORD, LONG_SWORD, 
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_BEHEAD), AF2_NONE, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, PHYSI(0, 0, 1), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NEUTRAL, NON_PM, NON_PM, 4000L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),
    /*
     *      Ah, never shall I forget the cry,
     *              or the shriek that shrieked he,
     *      As I gnashed my teeth, and from my sheath
     *              I drew my Snickersnee!
     *                      --Koko, Lord high executioner of Titipu
     *                        (From Sir W.S. Gilbert's "The Mikado")
     */
    A("Snickersnee", "gold-hilted katana", None, KATANA, KATANA, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        AF_RESTR, AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, 0,
        0, 0, 0, PHYS(ARTDMG_DOUBLE_DAMAGE, 0), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, PM_SAMURAI, NON_PM, 1200L,
        NO_COLOR, HI_GOLD, 0, OBJECT_SOUNDSET_NONE),

    A("Sunsword", "glowing long sword", None, LONG_SWORD, LONG_SWORD, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_DFLAG2 | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED | AF_ANGERS_DEMONS | AF_SHINES_MAGICAL_LIGHT),
        AF2_NAME_IS_PROPER_NAME, SPFX_NONE, SPFX_NONE, M2_UNDEAD | M2_DEMON,
        1, 5, 0, PHYS(ARTDMG_QUADRUPLE_DAMAGE, 0), FLASH_RESISTANCE, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, NON_PM, NON_PM, 1500L,
        NO_COLOR, HI_GOLD, 0, OBJECT_SOUNDSET_NONE),

    A("The Emerald Sword", "green two-handed gemstone sword", None, TWO_HANDED_GEMSTONE_SWORD, TWO_HANDED_GEMSTONE_SWORD, 
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED | AF_MONSTERS_CAN_TRACK_ARTIFACT | AF_ANGERS_DEMONS,
        AF2_NONE,
        SPFX_STR_25 | SPFX_WIS_25 | SPFX_REFLECT, SPFX_HALRES, 0,
        1, 5, 0, PHYS(ARTDMG_DOUBLE_DAMAGE, 0), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, PM_KNIGHT, NON_PM, 5000L,
        NO_COLOR, CLR_BRIGHT_GREEN, 0, OBJECT_SOUNDSET_NONE),

    /* Not associated with samurai to make it more useful in game play, as the samurai also have The Tsurugi of Muramasa as quest artifact  */
    A("The Katana of Masamune", "engraved katana", "razor-sharp blade", KATANA, KATANA,
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_BISECT), AF2_NONE, SPFX_LUCK, SPFX_NONE, 0,
        1, 5, 0, PHYS(1, 4), BISECTION_RESISTANCE, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, NON_PM, NON_PM, 6000L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("The Kusanagi", "engraved tsurugi", None, TSURUGI, TSURUGI,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_NAME_KNOWN_WHEN_INVOKED), AF2_APPLICABLE_AS_AXE, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, PHYSI(1, 5, 5), SICK_RESISTANCE, NO_POWER, ARTINVOKE_AIR_ELEMENTAL_SUMMON, 6, 6, 200, 50, 500, A_LAWFUL, PM_SAMURAI, NON_PM, 3000L,
        NO_COLOR, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),

    A("The Mace of Saint Cuthbert", "wooden mace", None, HEAVENLY_OAK_MACE, HEAVENLY_OAK_MACE,
        EXCEPTIONALITY_CELESTIAL, MYTHIC_PREFIX_HALLOWED, MYTHIC_SUFFIX_DISRUPTION, 
        AF_RESTR | AF_ANGERS_DEMONS | AF_DFLAG2, AF2_NONE, SPFX_DEMON_WARNING | SPFX_UNDEAD_WARNING, SPFX_NONE, M2_DEMON | M2_UNDEAD,
        1, 5, 5, PHYSI(1, 20, 5), FREE_ACTION, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, NON_PM, NON_PM, 2000L,
        NO_COLOR, HI_WOOD, 0, OBJECT_SOUNDSET_NONE),

    /* Artifact rings */
    A("The One Ring", "plain golden", None, RIN_SUPREME_POWER, RIN_SUPREME_POWER, 
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_INTEL | AF_MONSTERS_CAN_TRACK_ARTIFACT),
        AF2_NONE, SPFX_NONE, SPFX_AGGRAVATE_MONSTER | SPFX_UNLUCK, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 10000L,
        NO_COLOR, HI_GOLD, 16, OBJECT_SOUNDSET_NONE),

    A("The Ring of Three Wishes", "three-ruby-studded", None, RIN_THREE_CHARGES, RIN_THREE_CHARGES, 
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_NO_WISH | AF_NAME_KNOWN_WHEN_INVOKED | AF_INVOKE_EXPENDS_CHARGE | AF_INVOKE_REQUIRES_WORN),
        AF2_NONE, SPFX_NONE, SPFX_NONE, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, ARTINVOKE_WISHING, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 4500L,
        NO_COLOR, CLR_RED, 16, OBJECT_SOUNDSET_NONE),

    A("The Serpent Ring of Set", "serpent-shaped", None, RIN_THE_SERPENT_GOD, RIN_THE_SERPENT_GOD, 
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED | AF_INVOKE_REQUIRES_WORN),
        AF2_NONE, SPFX_EREGEN | SPFX_INT_25 | SPFX_WIS_25, SPFX_NONE, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, ARTINVOKE_DEMON_SUMMON, 6, 6, 200, 50, 500, A_CHAOTIC, NON_PM, NON_PM, 3000L,
        NO_COLOR, CLR_BLACK, 16, OBJECT_SOUNDSET_NONE),

    A("The Ring of Conflict", "ruby", None, RIN_SEVEN_CHARGES, RIN_SEVEN_CHARGES, 
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_RESTR | AF_NAME_KNOWN_WHEN_INVOKED | AF_INVOKE_EXPENDS_CHARGE | AF_INVOKE_REQUIRES_WORN),
        AF2_NONE, SPFX_NONE, SPFX_NONE, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, CONFLICT, 2, 10, 140, 0, 200, A_NONE, NON_PM, NON_PM, 3500L,
        NO_COLOR, CLR_RED, 16, OBJECT_SOUNDSET_NONE),

    /* Other non-weapon artifacts */
    A("The Rod of Disjunction", "black metal", None, WAN_DISJUNCTION, WAN_DISJUNCTION, 
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, (AF_RESTR | AF_FAMOUS),
        AF2_NONE, SPFX_NONE, SPFX_ANTIMAGIC, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 3000L,
        NO_COLOR, CLR_BLACK, 0, OBJECT_SOUNDSET_NONE),

    /* Special artifacts and crowning gifts  */
    A("The Gauntlets of Yin and Yang", "black and white gauntlets", None, GAUNTLETS_OF_BALANCE, GAUNTLETS_OF_BALANCE,
        EXCEPTIONALITY_EXCEPTIONAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED | AF_NO_WISH | AF_INVOKE_REQUIRES_WORN | AF_INVOKE_MAY_DRAIN_ENERGY), 
        AF2_FLOOR_TILE, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, PHYS(1, 10), NO_POWER, NO_POWER, ARTINVOKE_TIME_STOP, 0, 0, 0, 0, 1000, A_NONE, PM_MONK, NON_PM, 3500L,
        NO_COLOR, CLR_WHITE, 0, OBJECT_SOUNDSET_NONE),

    A("The Holy Grail", "wooden grail", None, GRAIL_OF_HEALING, GRAIL_OF_HEALING, 
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE,
        (AF_RESTR | AF_NAME_KNOWN_WHEN_INVOKED),
        AF2_NONE, SPFX_NONE, SPFX_PROTECT, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, ARTINVOKE_RECHARGE_ITSELF, 0, 0, 0, 0, 1500, A_LAWFUL, NON_PM, NON_PM, 3000L,
        NO_COLOR, HI_WOOD, 0, OBJECT_SOUNDSET_NONE),

    A("The Prime Codex", "ornamental white", None, SPE_BOOK_OF_MODRON, SPE_BOOK_OF_MODRON,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_FAMOUS | AF_READABLE | AF_NO_WISH), AF2_NONE, SPFX_NONE,
        (SPFX_HSPDAM | SPFX_HPHDAM | SPFX_TCTRL), 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, ARTINVOKE_LEVEL_TELEPORT, 0, 0, 0, 0, 40, A_NONE, NON_PM, NON_PM, 5000L,
        NO_COLOR, CLR_WHITE, 0, OBJECT_SOUNDSET_NONE),

    /*
     *      The artifacts for the quest dungeon, all self-willed.
     */

    A("The Orb of Detection", "runed crystal ball", None, CRYSTAL_BALL, CRYSTAL_BALL, //STARTMARKER FOR QUEST ARTIFACTS
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS), AF2_NONE, SPFX_NONE, SPFX_ANTIMAGIC, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, INVISIBILITY, 0, 0, 0, 0, 0, A_LAWFUL, PM_ARCHAEOLOGIST, NON_PM, 2500L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("The Heart of Ahriman", "glowing red jewel", None, LUCKSTONE, LUCKSTONE,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS), AF2_FLOOR_TILE, SPFX_NONE, SPFX_STLTH, 0,
      /* this stone does double damage if used as a projectile weapon */
        1, 5, 0, PHYS(ARTDMG_DOUBLE_DAMAGE, 0), NO_POWER, NO_POWER, LEVITATION, 0, 0, 0, 0, 0, A_NEUTRAL, PM_BARBARIAN, NON_PM, 2500L,
        NO_COLOR, CLR_RED, 24, OBJECT_SOUNDSET_NONE),

    A("The Sceptre of Might", "diamond-encrusted sceptre", None, RUNED_SCEPTRE, RUNED_SCEPTRE,
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_DALIGN | AF_FAMOUS | AF_INVOKE_EXPENDS_CHARGE), AF2_NONE, SPFX_NONE, SPFX_NONE, 0,
        1, 5, 0, PHYS(ARTDMG_DOUBLE_DAMAGE, 0), ANTIMAGIC, NO_POWER, CONFLICT, 2, 10, 140, 0, 300, A_LAWFUL, PM_CAVEMAN, NON_PM, 2500L,
        NO_COLOR, HI_GOLD, 0, OBJECT_SOUNDSET_NONE),

#if 0 /* OBSOLETE */
A("The Palantir of Westernesse",        CRYSTAL_BALL, CRYSTAL_BALL,
    AF_NONE, AF2_NONE, (SPFX_NOGEN|SPFX_RESTR|SPFX_INTEL),
                (SPFX_ESP|SPFX_REGEN|SPFX_HSPDAM), 0,
        NO_ATTK,        NO_POWER,        NO_POWER,
        ARTINVOKE_TAMING,         A_CHAOTIC, NON_PM , PM_ELF, 8000L, NO_COLOR, 0, OBJECT_SOUNDSET_NONE),
#endif

    A("The Staff of Aesculapius", "serpent-entwined quarterstaff", None, STAFF_OF_LIFE, QUARTERSTAFF,
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_DRLI | AF_FAMOUS), AF2_NONE, SPFX_REGEN, SPFX_NONE, 0,
        0, 0, 0, DRLI(0,0), DRAIN_RESISTANCE, NO_POWER, ARTINVOKE_HEALING, 0, 0, 0, 0, 150, A_NEUTRAL, PM_HEALER, NON_PM, 5000L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("The Magic Mirror of Merlin", "runed looking glass", None, MAGIC_MIRROR, MIRROR,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_SPEAK | AF_FAMOUS), AF2_NONE, SPFX_NONE, SPFX_ESP | SPFX_REFLECT, 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, DISPLACED, 0, 0, 0, 0, 25, A_LAWFUL, PM_KNIGHT, NON_PM, 1500L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("The Eyes of the Overworld", "runed eyeglasses", None, LENSES, LENSES,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS), AF2_NONE, (SPFX_XRAY | SPFX_BLIND_SEEING),  SPFX_NONE, 0,
        0, 0, 0, NO_ATTK, ANTIMAGIC, NO_POWER, ARTINVOKE_ENLIGHTENING, 0, 0, 0, 0, 40, A_NEUTRAL, PM_MONK, NON_PM, 2500L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("The Mitre of Holiness", "diamond-encrusted helmet", None, HELM_OF_BRILLIANCE, HELMET,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS), AF2_NONE, SPFX_PROTECT | SPFX_HALF_PHYSICAL_DAMAGE_AGAINST_UNDEAD_AND_DEMONS, SPFX_NONE, 0,
        0, 0, 0, NO_ATTK, NO_POWER, FIRE_IMMUNITY, ARTINVOKE_ENERGY_BOOST, 0, 0, 0, 0, 150, A_LAWFUL, PM_PRIEST, NON_PM, 2000L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("The Longbow of Diana", "shining long bow", None, DIVINE_LONG_BOW, LONG_BOW,
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS), AF2_NONE, SPFX_STLTH, SPFX_ESP, 0,
        0, 0, 20, PHYS(ARTDMG_DOUBLE_DAMAGE, 0), NO_POWER, NO_POWER, ARTINVOKE_ARROW_OF_DIANA, 0, 0, 0, 25, 100, A_CHAOTIC, PM_RANGER, NON_PM, 4000L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    /* MKoT has an additional carry property if the Key is not cursed (for
       rogues) or blessed (for non-rogues):  #untrap of doors and chests
       will always find any traps and disarming those will always succeed */
    A("The Master Key of Thievery", "ornamental key", None, MASTER_KEY, SKELETON_KEY,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_SPEAK | AF_FAMOUS), AF2_FLOOR_TILE, SPFX_NONE, (SPFX_WARNING | SPFX_TCTRL | SPFX_HPHDAM), 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, ARTINVOKE_UNTRAP, 0, 0, 0, 0, 40, A_CHAOTIC, PM_ROGUE, NON_PM, 3500L,
        NO_COLOR, CLR_MAGENTA, 24, OBJECT_SOUNDSET_NONE),

    A("The Tsurugi of Muramasa", "engraved tsurugi", "razor-sharp blade", TSURUGI, TSURUGI,
        EXCEPTIONALITY_ELITE, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_BISECT | AF_FAMOUS), AF2_NONE, (SPFX_LUCK | SPFX_PROTECT), SPFX_NONE, 0,
        0, 0, 0, PHYS(1, 8), NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_LAWFUL, PM_SAMURAI, NON_PM, 4500L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("The Platinum Yendorian Express Card", "black credit card", None, CREDIT_CARD, CREDIT_CARD,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS), AF2_FLOOR_TILE, SPFX_NONE, (SPFX_ESP | SPFX_CHA_25), 0,
        0, 0, 0, NO_ATTK, NO_POWER, ANTIMAGIC, ARTINVOKE_CHARGE_OBJ, 0, 0, 0, 0, 150, A_NEUTRAL, PM_TOURIST, NON_PM, 7000L,
        NO_COLOR, CLR_BLACK, 16, OBJECT_SOUNDSET_NONE),

    A("The Orb of Fate", "ornamental crystal ball", None, CRYSTAL_BALL, CRYSTAL_BALL,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS | AF_READABLE), AF2_NONE, SPFX_NONE, (SPFX_WARNING | SPFX_HSPDAM | SPFX_HPHDAM | SPFX_LUCK), 0,
        0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, ARTINVOKE_LEVEL_TELEPORT, 0, 0, 0, 0, 40, A_NEUTRAL, PM_VALKYRIE, NON_PM, 3500L,
        NO_COLOR, CLR_MAGENTA, 0, OBJECT_SOUNDSET_NONE),

    A("The Eye of the Aethiopica", "eye-shaped amulet", None, AMULET_OF_ESP, AMULET_OF_ESP,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS), AF2_FLOOR_TILE, SPFX_NONE, (SPFX_EREGEN | SPFX_HSPDAM), 0,
        0, 0, 0, NO_ATTK, ANTIMAGIC, NO_POWER, ARTINVOKE_CREATE_PORTAL, 0, 0, 0, 0, 40, A_NEUTRAL, PM_WIZARD, NON_PM, 4000L,
        NO_COLOR, CLR_MAGENTA, 24, OBJECT_SOUNDSET_NONE),

    A("The Ark of the Covenant", "gold-covered wooden chest", None, GOLDEN_CHEST, GOLDEN_CHEST,
        EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, 
        (AF_NOGEN | AF_RESTR | AF_INTEL | AF_FAMOUS | AF_NO_WISH), AF2_NONE, SPFX_NONE, (SPFX_LUCK | SPFX_PROTECT), 0,
        0, 0, 0, NO_ATTK, NO_POWER, ANTIMAGIC, ARTINVOKE_BLESS_CONTENTS, 0, 0, 0, 0, 250, A_LAWFUL, NON_PM, /* PM_ARCHAEOLOGIST */ NON_PM, 5000L,
        NO_COLOR, HI_GOLD, 0, OBJECT_SOUNDSET_NONE),


    /*
     *  terminator; otyp must be zero
     */
    A(0, 0, 0, 0, 0, EXCEPTIONALITY_NORMAL, MYTHIC_PREFIX_NONE, MYTHIC_SUFFIX_NONE, AF_NONE, AF2_NONE, SPFX_NONE, SPFX_NONE, 0, 0, 0, 0, NO_ATTK, NO_POWER, NO_POWER, NO_POWER, 0, 0, 0, 0, 0, A_NONE, NON_PM, NON_PM, 0L,
      0, 0, 0, OBJECT_SOUNDSET_NONE) /* 0 is CLR_BLACK rather than NO_COLOR but it doesn't matter here */

}; /* artilist[] (or artifact_names[]) */

#undef A

#ifndef MAKEDEFS_C
#undef NO_ATTK
#undef DFNS
#undef PHYS
#undef PHYSI
#undef DRLI
#undef COLD
#undef FIRE
#undef ELEC
#undef STUN
#undef None
#endif

/*artilist.h*/

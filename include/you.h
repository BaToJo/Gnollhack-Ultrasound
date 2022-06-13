/* GnollHack File Change Notice: This file has been changed from the original. Date of last change: 2022-06-13 */

/* GnollHack 4.0    you.h    $NHDT-Date: 1547514642 2019/01/15 01:10:42 $  $NHDT-Branch: GnollHack-3.6.2-beta01 $:$NHDT-Revision: 1.35 $ */
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/*-Copyright (c) Robert Patrick Rankin, 2016. */
/* GnollHack may be freely redistributed.  See license for details. */

#ifndef YOU_H
#define YOU_H

#ifndef CONFIG_H
#include "config.h"
#endif

#ifndef DUNGEON_H
#include "dungeon.h"
#endif

#include "attrib.h"
#include "monst.h"
#ifndef PROP_H
#include "prop.h" /* (needed here for util/makedefs.c) */
#endif
#include "skills.h"

#include <time.h>

enum role_types
{
    ROLE_ARCHAEOLOGIST = 0,
    ROLE_BARBARIAN,
    ROLE_CAVEMAN,
    ROLE_HEALER,
    ROLE_KNIGHT,
    ROLE_MONK,
    ROLE_PRIEST,
    ROLE_ROGUE,
    ROLE_RANGER,
    ROLE_SAMURAI,
    ROLE_TOURIST,
    ROLE_VALKYRIE,
    ROLE_WIZARD,
    NUM_ROLES
};


enum race_types
{
    RACE_HUMAN = 0,
    RACE_ELF,
    RACE_DWARF,
    RACE_GNOLL,
    RACE_ORC,
    NUM_RACES
};


enum gender_types
{
    GENDER_MALE = 0,
    GENDER_FEMALE,
    GENDER_NEUTER
};



/*** Substructures ***/

struct RoleName {
    const char *m; /* name when character is male */
    const char *f; /* when female; null if same as male */
};

struct RoleAdvance {
    /* "fix" is the fixed amount, "rnd" is the random amount */
    xchar infix, inrnd; /* at character initialization */
    xchar lofix, lornd; /* gained per level <  urole.xlev */
    xchar hifix, hirnd; /* gained per level >= urole.xlev */
};

struct u_have {
    Bitfield(amulet, 1);   /* carrying Amulet   */
    Bitfield(bell, 1);     /* carrying Bell     */
    Bitfield(book, 1);     /* carrying Book     */
    Bitfield(menorah, 1);  /* carrying Candelabrum */
    Bitfield(questart, 1); /* carrying the Quest Artifact */
    Bitfield(prime_codex, 1);  /* carrying Prime Codex */
    Bitfield(unused, 2);
};

struct u_event {
    Bitfield(minor_oracle, 1); /* received at least 1 cheap oracle */
    Bitfield(major_oracle, 1); /*  "  expensive oracle */
    Bitfield(read_tribute, 1); /* read a passage from a novel */
    Bitfield(qcalled, 1);      /* called by Quest leader to do task */
    Bitfield(qexpelled, 1);    /* expelled from the Quest dungeon */
    Bitfield(qcompleted, 1);   /* successfully completed Quest task */
    Bitfield(uheard_tune, 2);  /* 1=know about, 2=heard passtune */

    Bitfield(uopened_dbridge, 1);   /* opened the drawbridge */
    Bitfield(invoked, 1);           /* invoked Gate to the Sanctum level */
    Bitfield(gehennom_entered, 1);  /* entered Gehennom via Valley */
    Bitfield(modron_portal_hint, 1); /* modron portal hint given */
    Bitfield(modron_plane_entered, 1); /* entered the modron plane */
    Bitfield(bovine_portal_hint, 1); /* bovine portal hint given */
    Bitfield(hellish_pastures_entered, 1); /* entered the Hellish Pastures */
    Bitfield(quantum_portal_hint, 1); /* quantum portal hint given */
    Bitfield(large_circular_dgn_entered, 1); /* entered the Large Circular Dungeon */
    Bitfield(polymorph_trap_warning, 1); /* polymorph trap warning given */
    Bitfield(uhand_of_elbereth, 2); /* became Hand of Elbereth */
    Bitfield(udemigod, 1);          /* killed the wiz */
    Bitfield(uvibrated, 1);         /* stepped on "vibrating square" */
    Bitfield(ascended, 1);          /* has offered the Amulet */

};

struct u_achieve {
    /* Major Achievements */
    Bitfield(amulet, 1);  /* touched Amulet */
    Bitfield(bell, 1);    /* touched Bell */
    Bitfield(book, 1);    /* touched Book */
    Bitfield(menorah, 1); /* touched Candelabrum */
    Bitfield(prime_codex, 1); /* touched Prime Codex */
    Bitfield(enter_gehennom, 1); /* entered Gehennom (or Valley) by any means */
    Bitfield(ascended, 1); /* not quite the same as u.uevent.ascended */
    Bitfield(mines_luckstone, 1); /* got a luckstone at end of mines */
    Bitfield(finish_sokoban, 1);  /* obtained the sokoban prize */
    Bitfield(killed_medusa, 1);
    Bitfield(killed_yacc, 1);

    /* Minor Achievements */
    Bitfield(consulted_oracle, 1);
    Bitfield(read_discworld_novel, 1);
    Bitfield(entered_gnomish_mines, 1);
    Bitfield(entered_mine_town, 1);
    Bitfield(entered_shop, 1);
    Bitfield(entered_temple, 1);
    Bitfield(entered_sokoban, 1);
    Bitfield(entered_bigroom, 1);
    Bitfield(learned_castle_tune, 1);
    Bitfield(entered_large_circular_dungeon, 1);
};

struct u_realtime {
    long   realtime;     /* accumulated playing time in seconds */
    time_t start_timing; /* time game was started or restored or 'realtime'
                            was last updated (savegamestate for checkpoint) */
    time_t finish_time;  /* end of 'realtime' interval: time of save or
                            end of game; used for topten/logfile/xlogfile */
};

/* KMH, conduct --
 * These are voluntary challenges.  Each field denotes the number of
 * times a challenge has been violated.
 */
struct u_conduct {     /* number of times... */
    long unvegetarian; /* eaten any animal */
    long unvegan;      /* ... or any animal byproduct */
    long food;         /* ... or any comestible */
    long gnostic;      /* used prayer, priest, or altar */
    long weaphit;      /* hit a monster with a weapon */
    long killer;       /* killed a monster yourself */
    long literate;     /* read something (other than BotD) */
    long polypiles;    /* polymorphed an object */
    long polyselfs;    /* transformed yourself */
    long wishes;       /* used a wish */
    long wisharti;     /* wished for an artifact */
    /* genocides already listed at end of game */
};

struct u_roleplay {
    boolean blind;  /* permanently blind */
    boolean nudist; /* has not worn any armor, ever */
    long numbones;  /* # of bones files loaded  */
};

#define MAX_TRAIT_DESCRIPTIONS 5

/*** Unified structure containing role information ***/
struct Role {
    /*** Strings that name various things ***/
    struct RoleName name;    /* the role's name (from u_init.c) */
    struct RoleName rank[9]; /* names for experience levels (from botl.c) */
    const char *lgod, *ngod, *cgod; /* god names (from pray.c) */
    const char *filecode;           /* abbreviation for use in file names */
    const char *homebase; /* quest leader's location (from questpgr.c) */
    const char *intermed; /* quest intermediate goal (from questpgr.c) */
    short rolenum; /* increasing id number of the role */
    const char *trait_descriptions[MAX_TRAIT_DESCRIPTIONS]; /* Up to five descriptions of various role advantages and disadvantages */
    /*** Indices of important monsters and objects ***/
    short monsternum, /* index (PM_) (botl.c) */
        petnum,    /* PM_ of preferred pet (NON_PM == random) */
        ldrnum,    /* PM_ of quest leader (questpgr.c) */
        guardnum,  /* PM_ of quest guardians (questpgr.c) */
        neminum,   /* PM_ of quest nemesis (questpgr.c) */
        enemy1num, /* specific quest enemies (NON_PM == random) */
        enemy2num;
    char enemy1sym, /* quest enemies by class (S_) */
        enemy2sym;
    short questarti; /* index (ART_) of quest artifact (questpgr.c) */

    /*** Bitmasks ***/
    unsigned long allow;                  /* bit mask of allowed variations */
#define ROLE_ALIGNMENT_TILES  0x80000000UL     /* has alignment-specific tiles */
#define ROLE_GENDMASK         0x70000000UL     /* allowable genders */
#define ROLE_MALE             0x10000000UL
#define ROLE_FEMALE           0x20000000UL
#define ROLE_NEUTER           0x40000000UL
#define ROLE_RACEMASK         0x0ffffff8UL     /* allowable races 0x0ffffff8*/
#define ROLE_ALIGNMASK AM_MASK    /* allowable alignments */
#define ROLE_LAWFUL    AM_LAWFUL
#define ROLE_NEUTRAL   AM_NEUTRAL
#define ROLE_CHAOTIC   AM_CHAOTIC

    /*** Attributes (from attrib.c and exper.c) ***/
    xchar attrbase[A_MAX];    /* lowest initial attributes */
    xchar attrdist[A_MAX];    /* distribution of initial attributes */
    struct RoleAdvance hpadv; /* hit point advancement */
    struct RoleAdvance enadv; /* energy advancement */
    xchar xlev;               /* cutoff experience level */
    xchar initrecord;         /* initial alignment record */

    /*** Spell statistics (from spell.c) ***/
    int spelarmr; /* Except for monks, penalty for wearing metal armour */

    /*** Properties in variable-length arrays ***/
    /* intrinsics (see attrib.c) */
    /* initial inventory (see u_init.c) */
    /* skills (see u_init.c) */

    /*** Don't forget to add... ***/
    /* quest leader, guardians, nemesis (monst.c) */
    /* quest artifact (artilist.h) */
    /* quest dungeon definition (dat/Xyz.dat) */
    /* quest text (dat/quest.txt) */
    /* dictionary entries (dat/data.bas) */
    
    int skill_advance_levels[P_NUM_SKILLS][MAX_SKILL_LEVELS];
};

extern const struct Role roles[]; /* table of available roles */
extern struct Role urole;
#define Role_if(X) (urole.monsternum == (X))
#define Role_switch (urole.monsternum)

/* used during initialization for race, gender, and alignment
   as well as for character class */
#define ROLE_NONE (-1)
#define ROLE_RANDOM (-2)
/*** Unified structure specifying race information ***/

struct Race {
    /*** Strings that name various things ***/
    const char *noun;           /* noun ("human", "elf") */
    const char *adj;            /* adjective ("human", "elven") */
    const char *coll;           /* collective ("humanity", "elvenkind") */
    const char *filecode;       /* code for filenames */
    struct RoleName individual; /* individual as a noun ("man", "elf") */
    short racenum; /* increasing id number of the race */

    const char *trait_descriptions[MAX_TRAIT_DESCRIPTIONS]; /* Up to five descriptions of various race advantages and disadvantages */

    /*** Indices of important monsters and objects ***/
    short monsternum, /* PM_ as monster */
        mummynum,  /* PM_ as a mummy */
        zombienum; /* PM_ as a zombie */

    /*** Bitmasks ***/
    unsigned long allow;    /* bit mask of allowed variations */
    unsigned long selfmask, /* your own race's bit mask */
        lovemask,   /* bit mask of always peaceful */
        hatemask;   /* bit mask of always hostile */

    /*** Attributes ***/
    xchar attrmin[A_MAX];     /* minimum allowable attribute */
    xchar attrmax[A_MAX];     /* maximum allowable attribute */
    struct RoleAdvance hpadv; /* hit point advancement */
    struct RoleAdvance enadv; /* energy advancement */
#if 0 /* DEFERRED */
    int   nv_range;           /* night vision range */
    int   xray_range;         /* X-ray vision range */
#endif

    /*** Properties in variable-length arrays ***/
    /* intrinsics (see attrib.c) */

    /*** Don't forget to add... ***/
    /* quest leader, guardians, nemesis (monst.c) */
    /* quest dungeon definition (dat/Xyz.dat) */
    /* quest text (dat/quest.txt) */
    /* dictionary entries (dat/data.bas) */
};

extern const struct Race races[]; /* Table of available races */
extern struct Race urace;
#define Race_if(X) (urace.monsternum == (X))
#define Race_switch (urace.monsternum)

/*** Unified structure specifying gender information ***/
struct Gender {
    const char *adj;      /* male/female/neuter */
    const char *he;       /* he/she/it */
    const char *him;      /* him/her/it */
    const char *his;      /* his/her/its */
    const char *filecode; /* file code */
    unsigned long allow;  /* equivalent ROLE_ mask */
};
#define ROLE_GENDERS 2    /* number of permitted player genders
                             increment to 3 if you allow neuter roles */

extern const struct Gender genders[]; /* table of available genders */
/* pronouns for the hero */
#define uhe()      (genders[flags.female ? 1 : 0].he)
#define uhim()     (genders[flags.female ? 1 : 0].him)
#define uhis()     (genders[flags.female ? 1 : 0].his)
/* corresponding pronouns for monsters; yields "it" when mtmp can't be seen */
#define mhe(mtmp)  (genders[pronoun_gender(mtmp, FALSE)].he)
#define mhim(mtmp) (genders[pronoun_gender(mtmp, FALSE)].him)
#define mhis(mtmp) (genders[pronoun_gender(mtmp, FALSE)].his)
/* override "it" if reason is lack of visibility rather than neuter species */
#define noit_mhe(mtmp)  (genders[pronoun_gender(mtmp, TRUE)].he)
#define noit_mhim(mtmp) (genders[pronoun_gender(mtmp, TRUE)].him)
#define noit_mhis(mtmp) (genders[pronoun_gender(mtmp, TRUE)].his)

/*** Unified structure specifying alignment information ***/
struct Align {
    const char *noun;     /* law/balance/chaos */
    const char *adj;      /* lawful/neutral/chaotic */
    const char *filecode; /* file code */
    unsigned long allow;  /* equivalent ROLE_ mask */
    aligntyp value;       /* equivalent A_ value */
};
#define ROLE_ALIGNS 3     /* number of permitted player alignments */

extern const struct Align aligns[]; /* table of available alignments */

enum utraptypes {
    TT_NONE       = 0,
    TT_BEARTRAP   = 1,
    TT_PIT        = 2,
    TT_WEB        = 3,
    TT_LAVA       = 4,
    TT_INFLOOR    = 5,
    TT_BURIEDBALL = 6
};

/*** Information about the player ***/
struct you {
    xchar ux, uy;       /* current map coordinates */
    schar dx, dy, dz;   /* direction of move (or zap or ... ) */
    schar di;           /* direction of FF */
    xchar tx, ty;       /* destination of travel */
    xchar ux0, uy0;     /* initial position FF */
    d_level uz, uz0;    /* your level on this and the previous turn */
    d_level utolev;     /* level monster teleported you to, or uz */
    short utotype;      /* bitmask of goto_level() flags for utolev */
    boolean umoved;     /* changed map location (post-move) */
    int last_str_turn;  /* 0: none, 1: half turn, 2: full turn
                           +: turn right, -: turn left */
    int ulevel;         /* 1 to MAXULEV */
    int ulevelmax;
    unsigned long utrap;    /* trap timeout */
    uchar utraptype; /* defined if utrap nonzero. one of utraptypes */
    char urooms[5];         /* rooms (roomno + 3) occupied now */
    char urooms0[5];        /* ditto, for previous position */
    char uentered[5];       /* rooms (roomno + 3) entered this turn */
    char ushops[5];         /* shop rooms (roomno + 3) occupied now */
    char ushops0[5];        /* ditto, for previous position */
    char ushops_entered[5]; /* ditto, shops entered this turn */
    char ushops_left[5];    /* ditto, shops exited this turn */

    int uhunger;  /* refd only in eat.c and shk.c */
    unsigned uhs; /* hunger state - see eat.c */

    struct prop uprops[LAST_PROP + 1];

    unsigned umconf;

    /* These ranges can never be more than MAX_RANGE (vision.h). */
    int nv_range;   /* current night vision range */
    int xray_range; /* current xray vision range */

/*
 * These variables are valid globally only when punished and blind.
 */
#define BC_BALL 0x01  /* bit mask for ball  in 'bc_felt' below */
#define BC_CHAIN 0x02 /* bit mask for chain in 'bc_felt' below */
    int bglyph;       /* glyph under the ball */
    int cglyph;       /* glyph under the chain */
    int bc_order;     /* ball & chain order [see bc_order() in ball.c] */
    int bc_felt;      /* mask for ball/chain being felt */

    int umonster;               /* hero's "real" monster num */
    int umonnum;                /* current monster number */

    int mh, mhmax, basemhmax, mtimedone;   /* for polymorph-self */
    struct attribs macurr,      /* for monster attribs */
                   mamin,       /* for monster attribs */
                   mamax;       /* for monster attribs */
    int ulycn;                  /* lycanthrope type */

    unsigned ucreamed;
    unsigned uswldtim;          /* time you have been swallowed */
    boolean mfemale;            /* saved human value of flags.female (your true gender before polymorph) */

    Bitfield(uswallow, 1);      /* true if swallowed */
    Bitfield(uinwater, 1);      /* if you're currently in water (only
                                   underwater possible currently) */
    Bitfield(uundetected, 1);   /* if you're a hiding monster/piercer */
    Bitfield(uinvulnerable, 1); /* you're invulnerable (praying) */
    Bitfield(uburied, 1);       /* you're buried */
    Bitfield(uedibility, 1);    /* blessed food detect; sense unsafe food */
    /* 1 free bit! */

    unsigned udg_cnt;           /* how long you have been demigod */
    struct u_achieve uachieve;  /* achievements */
    struct u_event uevent;      /* certain events have happened */
    struct u_have uhave;        /* you're carrying special objects */
    struct u_conduct uconduct;  /* KMH, conduct */
    struct u_roleplay uroleplay;
    struct attribs acurr,       /* your current attributes (eg. str)*/
                    aexe,       /* for gain/loss via "exercise" */
                    abonus,     /* your bonus attributes (eg. str) */
                    afixmin,    /* your fixed min attributes (eg. str), set by an item */
                    afixmax,    /* your fixed max attributes (eg. str), set by an item */
                    amin,       /* your max attributes (eg. str) */
                    amax,       /* your max attributes (eg. str) */
                   atemp,       /* used for temporary loss/gain */
                   atime;       /* used for loss/gain countdown */
    align ualign;               /* character alignment */
#define CONVERT    2
#define A_ORIGINAL 1
#define A_CURRENT  0
    aligntyp ualignbase[CONVERT]; /* for ualign conversion record */
    schar uluck;
    long moreluck;    /* luck and luck bonus */
    boolean luck_does_not_timeout, unluck_does_not_timeout;
#define LUCKADD    3  /* value of u.moreluck when carrying luck stone;
                         + when blessed or uncursed, - when cursed */
#define Luck (u.uluck + (u.moreluck > 0 ? LUCKADD : u.moreluck < 0 ? -LUCKADD : 0))
#define LUCKMAX   10  /* maximum value of u.uluck */
#define LUCKMIN (-10) /* minimum value of u.uluck */
    schar ubasehitinc;        /* permanent intrinsic values not affected by items or anything else */
    schar ubasedaminc;
    schar ubaseacbonus;
    schar uhitinc;            /* variable extrinsic values affected by items and spells */
    schar udaminc;
    schar uacbonus;
    schar umcbonus;
    schar uspellcastingbonus_unrestricted;
    schar uspellcastingbonus_all;
    schar uexperiencebonus;
    schar uarcherybonus;
    schar uac;                 /* current armor class */
    schar umc;                 /* current magic cancellation */
    int uhp, uhpmax, ubasehpmax;         /* hit points, aka health */
    int uen, uenmax, ubaseenmax;         /* magical energy - M. Stephenson */
    xchar uhpinc[MAXULEV],   /* increases to uhpmax for each level gain */
          ueninc[MAXULEV];   /* increases to uenmax for each level gain */
    int uhp_fraction, uen_fraction, mh_fraction;
    int ugangr;              /* if the gods are angry at you */
    int ugifts;              /* number of artifacts bestowed */
    int ublessed;            /* amount of permanent divine protection bestowed upon you */
    int uprayer_timeout;     /* duration from #pray */
    long umoney0;
    long uspare1;
    long uexp, u_gamescore;
    long ucleansed;          /* to record moves when player was cleansed */
    long usleep;             /* sleeping; monstermove you last started */
    int uinvault;
    struct monst *ustuck;    /* engulfer or grabber, maybe grabbee if Upolyd */
    struct monst *usteed;    /* mount when riding */
    long ugallop;            /* turns steed will run after being kicked */
    int urideturns;          /* time spent riding, for skill advancement */
    int umortality;          /* how many times you died */
    int utruemortality;      /* how many times you truly died without counting life saving, just revives due to wizard, explore, and modern mode */
    int ugrave_arise;        /* you die and become something aside from a ghost */
    int weapon_slots;        /* unused skill slots */
    int max_weapon_slots;    /* max skill slots */
    int skills_advanced;     /* # of advances made so far */
    xchar skill_record[P_SKILL_LIMIT]; /* skill advancements */
    struct skills weapon_skills[P_NUM_SKILLS];
    boolean twoweap;         /* KMH -- Using two-weapon combat */
    boolean canadvanceskill; /* Can advance skill */
    int carrying_capacity_level;

    /* Data influencing what is shown in tiles */
    boolean facing_right;
    uchar action;

}; /* end of `struct you' */

#define Upolyd (u.umonnum != u.umonster)

#endif /* YOU_H */

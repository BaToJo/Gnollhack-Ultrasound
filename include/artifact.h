/* GnollHack 4.0	artifact.h	$NHDT-Date: 1433050871 2015/05/31 05:41:11 $  $NHDT-Branch: master $:$NHDT-Revision: 1.11 $ */
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/*-Copyright (c) Robert Patrick Rankin, 2011. */
/* GnollHack may be freely redistributed.  See license for details. */

#ifndef ARTIFACT_H
#define ARTIFACT_H

/* general and attack-based flags */
#define AF_NONE		0x00000000UL  /* no special effects, just a bonus */
#define AF_NOGEN	0x00000001UL  /* item is special, bequeathed by gods */
#define AF_RESTR	0x00000002UL  /* item is restricted - can't be named */
#define AF_INTEL	0x00000004UL  /* item is self-willed - intelligent */
#define AF_SPEAK	0x00000008UL  /* item can speak (finally implemented) */
#define AF_DRLI		0x00000010UL  /* drains a level from monsters */
#define AF_BEHEAD	0x00000020UL  /* beheads monsters */
#define AF_BISECT	0x00000040UL  /* bisects monsters */
#define AF_HITS_ADJACENT_SQUARES			0x00000080UL  /* hits adjacent squares (like Cleaver) */
#define AF_BLOODTHIRSTY						0x00000100UL  /* no attack confirmation (like Stormbringer) */
#define AF_MAGIC_ABSORBING					0x00000200UL  /* absorbs curses (like Magicbane) */
#define AF_PREVENTS_REVIVAL_OF_MON			0x00000400UL  /* prevents revival of specified monsters (like Trollsbane) */
#define AF_PREVENTS_SUMMONING_OF_MON		0x00000800UL  /* prevents summoning by specified monsters (like Demonbane) */
#define AF_MONSTERS_CAN_TRACK_ARTIFACT		0x00001000UL  /* Ditto */
#define AF_ANGERS_DEMONS					0x00002000UL  /* Ditto */
#define AF_SHINES_MAGICAL_LIGHT				0x00004000UL  /* shines like Sunsword when wielded */
#define AF_FLICKERS							0x00008000UL  /* flickers like Sting */
#define AF_FLICKERS_WHEN_CARRIED			0x00010000UL  /* flickers also when just carried */
#define AF_NAME_KNOWN_WHEN_PICKED_UP		0x00020000UL  /* Ditto */
#define AF_NAME_KNOWN_WHEN_WORN_OR_WIELDED	0x00040000UL  /* Ditto */
#define AF_NAME_KNOWN_WHEN_INVOKED			0x00080000UL  /* Ditto */

/* monster class flags and mask here */
#define AF_DMONS							0x00100000UL  /* attack bonus on one monster type */
#define AF_DCLAS							0x00200000UL  /* attack bonus on monsters w/ symbol mtype */
#define AF_DFLAG1							0x00400000UL  /* attack bonus on monsters w/ mflags1 flag */
#define AF_DFLAG2							0x00800000UL  /* attack bonus on monsters w/ mflags2 flag */
#define AF_DALIGN							0x01000000UL  /* attack bonus on non-aligned monsters  */
#define AF_DBONUS							0x01F00000UL  /* attack bonus mask */

#define AF_FAMOUS							0x02000000UL  /* Name is always known */
#define AF_INVOKE_REQUIRES_WORN				0x04000000UL  /* ditto */
#define AF_INVOKE_EXPENDS_CHARGE			0x08000000UL  /* ditto */
#define AF_INVOKE_MAY_DRAIN_ENERGY			0x10000000UL  /* ditto */
#define AF_INVOKE_MAY_DRAIN_LIFE			0x20000000UL  /* ditto */
#define AF_READABLE							0x40000000UL  /* readable even if base item is not */
#define AF_NO_WISH							0x80000000UL  /* not wishable, not that for artifacts the base item's no wish does not apply */

#define AF2_NONE							0x00000000UL  
#define AF2_MISSILE_TILE					0x00000001UL  
#define AF2_SINGLE_MISSILE_TILE				0x00000002UL  


/* wielded or carried special effects */
#define SPFX_NONE				0x00000000UL  /* No special effects, just a bonus */
/* free bit */
/* free bit */
/* free bit */
/* free bit */
#define SPFX_ANTIMAGIC			0x00000010UL  /* Antimagic */
#define SPFX_WARN_OF_MON		0x00000020UL  /* Item warns you of a specific monster type; also always flickers */
#define SPFX_SEARCH				0x00000040UL  /* Helps searching */
#define SPFX_HALRES				0x00000080UL  /* Blocks hallucinations */
#define SPFX_ESP				0x00000100UL  /* ESP (like amulet of ESP) */
#define SPFX_STLTH				0x00000200UL  /* Stealth */
#define SPFX_REGEN				0x00000400UL  /* Regeneration */
#define SPFX_EREGEN				0x00000800UL  /* Energy Regeneration */
#define SPFX_HSPDAM				0x00001000UL  /* 1/2 spell damage (on player) in combat */
#define SPFX_HPHDAM				0x00002000UL  /* 1/2 physical damage (on player) in combat */
#define SPFX_TCTRL				0x00004000UL  /* Teleportation Control */
#define SPFX_LUCK				0x00008000UL  /* Increase Luck (like Luckstone) */
#define SPFX_XRAY				0x00010000UL  /* Gives X-RAY vision to player */
#define SPFX_REFLECT			0x00020000UL  /* Reflection */
#define SPFX_PROTECT			0x00040000UL  /* Protection */
#define SPFX_AGGRAVATE_MONSTER	0x00080000UL  /* Aggravates monsters */
#define SPFX_UNLUCK				0x00100000UL  /* Brings bad luck */
#define SPFX_BLIND_SEEING		0x00200000UL  /* Blocks blindness */
#define SPFX_HALF_PHYSICAL_DAMAGE_AGAINST_UNDEAD_AND_DEMONS \
								0x00400000UL  /* Ditto, for Mitre of Holiness */
#define SPFX_WARNING			0x00800000UL  /* Item warns you of danger */
#define SPFX_ORC_WARNING		0x01000000UL  /* Item warns you of orcs */
#define SPFX_ELF_WARNING		0x02000000UL  /* Item warns you of elves */

#define SPFX_STR_25				0x04000000UL  /* Str is raised to 25 */
#define SPFX_DEX_25				0x08000000UL  /* Dex is raised to 25 */
#define SPFX_CON_25				0x10000000UL  /* Con is raised to 25 */
#define SPFX_INT_25				0x20000000UL  /* Int is raised to 25 */
#define SPFX_WIS_25				0x40000000UL  /* Wis is raised to 25 */
#define SPFX_CHA_25				0x80000000UL  /* Cha is raised to 25 */


struct artifact {
    short otyp;
	short maskotyp;
	const char *name;
	const char* desc;	   /* unidentified name */
	const char* hit_desc;  /* description used in artifact_hit: e.g., massive hammer, ice-cold blade, etc. */
	unsigned long aflags;  /* artifact flags */
	unsigned long aflags2; /* artifact flags2 */
	unsigned long spfx;    /* special effect from wielding/wearing */
    unsigned long cspfx;   /* special effect just from carrying obj */
    unsigned long mtype;   /* monster type, symbol, or flag */
	int tohit_dice;
	int tohit_diesize;
	int tohit_plus;
	struct attack attk;
	int worn_prop;		/* property conferred when wielded/worn */
	int carried_prop;	/* property conferred when carried */
	int inv_prop;       /* property obtained by invoking artifact */
	int inv_duration_dice;
	int inv_duration_diesize;
	int inv_duration_plus;
	int inv_mana_cost;
	int repower_time;   /* artifact invoke cooldown, if any */
    aligntyp alignment; /* alignment of bequeathing gods */
    short role;         /* character role associated with */
    short race;         /* character race associated with */
    long cost; /* price when sold to hero (default 100 x base cost) */
    char acolor;        /* color to use if artifact 'glows' */
	char ocolor;		/* color used for object instead of its normal color */
	int tile_floor_height;
	enum object_soundset_types soundset;

	short stand_animation;
	short enlargement;
	short replacement;
};

/* invoked properties with special powers */
enum invoke_prop_types {
    ARTINVOKE_TAMING = (LAST_PROP + 1),
    ARTINVOKE_HEALING,
    ARTINVOKE_ENERGY_BOOST,
    ARTINVOKE_UNTRAP,
    ARTINVOKE_CHARGE_OBJ,
    ARTINVOKE_LEVEL_TELEPORT,
    ARTINVOKE_CREATE_PORTAL,
    ARTINVOKE_ENLIGHTENING,
    ARTINVOKE_CREATE_AMMO,
	ARTINVOKE_ARROW_OF_DIANA,
	ARTINVOKE_WAND_OF_DEATH,
	ARTINVOKE_BLESS_CONTENTS,
	ARTINVOKE_WISHING,
	ARTINVOKE_DEMON_SUMMON,
	ARTINVOKE_RECHARGE_ITSELF,
	ARTINVOKE_TIME_STOP
};

#define NUM_ARTINVOKES (ARTINVOKE_TIME_STOP - ARTINVOKE_TAMING + 1)

extern const char* artifact_invoke_names[NUM_ARTINVOKES];


#endif /* ARTIFACT_H */

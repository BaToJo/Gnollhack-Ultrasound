/* GnollHack 4.0	shknam.c	$NHDT-Date: 1454485432 2016/02/03 07:43:52 $  $NHDT-Branch: GnollHack-3.6.0 $:$NHDT-Revision: 1.41 $ */
/* Copyright (c) Stichting Mathematisch Centrum, Amsterdam, 1985. */
/*-Copyright (c) Robert Patrick Rankin, 2011. */
/* GnollHack may be freely redistributed.  See license for details. */

/* shknam.c -- initialize a shop */

#include "hack.h"

STATIC_DCL boolean FDECL(stock_room_goodpos, (struct mkroom *, int, int, int, int));
STATIC_DCL int NDECL(shkveg);
STATIC_DCL void FDECL(mkveggy_at, (int, int));
STATIC_DCL void FDECL(mkshobj_at, (const struct shclass *, int, int,
                                   BOOLEAN_P, BOOLEAN_P));
STATIC_DCL void FDECL(nameshk, (struct monst *, const char *const *));
STATIC_DCL int FDECL(shkinit, (const struct shclass *, struct mkroom *));

/*
 *  Name prefix codes:
 *      dash          -  female, personal name
 *      underscore    _  female, general name
 *      plus          +  male, personal name
 *      vertical bar  |  male, general name (implied for most of shktools)
 *      equals        =  gender not specified, personal name
 *
 *  Personal names do not receive the honorific prefix "Mr." or "Ms.".
 */

static const char *const shkliquors[] = {
    /* Ukraine */
    "Njezjin", "Tsjernigof", "Ossipewsk", "Gorlowka",
    /* Belarus */
    "Gomel",
    /* N. Russia */
    "Konosja", "Weliki Oestjoeg", "Syktywkar", "Sablja", "Narodnaja", "Kyzyl",
    /* Silezie */
    "Walbrzych", "Swidnica", "Klodzko", "Raciborz", "Gliwice", "Brzeg",
    "Krnov", "Hradec Kralove",
    /* Schweiz */
    "Leuk", "Brig", "Brienz", "Thun", "Sarnen", "Burglen", "Elm", "Flims",
    "Vals", "Schuls", "Zum Loch", 0
};

static const char *const shkbooks[] = {
    /* Eire */
    "Skibbereen",  "Kanturk",   "Rath Luirc",     "Ennistymon",
    "Lahinch",     "Kinnegad",  "Lugnaquillia",   "Enniscorthy",
    "Gweebarra",   "Kittamagh", "Nenagh",         "Sneem",
    "Ballingeary", "Kilgarvan", "Cahersiveen",    "Glenbeigh",
    "Kilmihil",    "Kiltamagh", "Droichead Atha", "Inniscrone",
    "Clonegal",    "Lisnaskea", "Culdaff",        "Dunfanaghy",
    "Inishbofin",  "Kesh",      0
};

static const char *const shkarmors[] = {
    /* Turquie */
    "Demirci",    "Kalecik",    "Boyabai",    "Yildizeli", "Gaziantep",
    "Siirt",      "Akhalataki", "Tirebolu",   "Aksaray",   "Ermenak",
    "Iskenderun", "Kadirli",    "Siverek",    "Pervari",   "Malasgirt",
    "Bayburt",    "Ayancik",    "Zonguldak",  "Balya",     "Tefenni",
    "Artvin",     "Kars",       "Makharadze", "Malazgirt", "Midyat",
    "Birecik",    "Kirikkale",  "Alaca",      "Polatli",   "Nallihan",
    0
};

static const char *const shkwands[] = {
    /* Wales */
    "Yr Wyddgrug", "Trallwng", "Mallwyd", "Pontarfynach", "Rhaeader",
    "Llandrindod", "Llanfair-ym-muallt", "Y-Fenni", "Maesteg", "Rhydaman",
    "Beddgelert", "Curig", "Llanrwst", "Llanerchymedd", "Caergybi",
    /* Scotland */
    "Nairn", "Turriff", "Inverurie", "Braemar", "Lochnagar", "Kerloch",
    "Beinn a Ghlo", "Drumnadrochit", "Morven", "Uist", "Storr",
    "Sgurr na Ciche", "Cannich", "Gairloch", "Kyleakin", "Dunvegan", 0
};

static const char *const shkrings[] = {
    /* Hollandse familienamen */
    "Feyfer",     "Flugi",         "Gheel",      "Havic",   "Haynin",
    "Hoboken",    "Imbyze",        "Juyn",       "Kinsky",  "Massis",
    "Matray",     "Moy",           "Olycan",     "Sadelin", "Svaving",
    "Tapper",     "Terwen",        "Wirix",      "Ypey",
    /* Skandinaviske navne */
    "Rastegaisa", "Varjag Njarga", "Kautekeino", "Abisko",  "Enontekis",
    "Rovaniemi",  "Avasaksa",      "Haparanda",  "Lulea",   "Gellivare",
    "Oeloe",      "Kajaani",       "Fauske",     0
};

static const char *const shkfoods[] = {
    /* Indonesia */
    "Djasinga",    "Tjibarusa",   "Tjiwidej",      "Pengalengan",
    "Bandjar",     "Parbalingga", "Bojolali",      "Sarangan",
    "Ngebel",      "Djombang",    "Ardjawinangun", "Berbek",
    "Papar",       "Baliga",      "Tjisolok",      "Siboga",
    "Banjoewangi", "Trenggalek",  "Karangkobar",   "Njalindoeng",
    "Pasawahan",   "Pameunpeuk",  "Patjitan",      "Kediri",
    "Pemboeang",   "Tringanoe",   "Makin",         "Tipor",
    "Semai",       "Berhala",     "Tegal",         "Samoe",
    0
};

static const char *const shkweapons[] = {
    /* Perigord */
    "Voulgezac",   "Rouffiac",   "Lerignac",   "Touverac",  "Guizengeard",
    "Melac",       "Neuvicq",    "Vanzac",     "Picq",      "Urignac",
    "Corignac",    "Fleac",      "Lonzac",     "Vergt",     "Queyssac",
    "Liorac",      "Echourgnac", "Cazelon",    "Eypau",     "Carignan",
    "Monbazillac", "Jonzac",     "Pons",       "Jumilhac",  "Fenouilledes",
    "Laguiolet",   "Saujon",     "Eymoutiers", "Eygurande", "Eauze",
    "Labouheyre",  0
};

static const char *const shktools[] = {
    /* Spmi */
    "Ymla", "Eed-morra", "Elan Lapinski", "Cubask", "Nieb", "Bnowr Falr",
    "Sperc", "Noskcirdneh", "Yawolloh", "Hyeghu", "Niskal", "Trahnil",
    "Htargcm", "Enrobwem", "Kachzi Rellim", "Regien", "Donmyar", "Yelpur",
    "Nosnehpets", "Stewe", "Renrut", "Senna Hut", "-Zlaw", "Nosalnef",
    "Rewuorb", "Rellenk", "Yad", "Cire Htims", "Y-crad", "Nenilukah",
    "Corsh", "Aned", "Dark Eery", "Niknar", "Lapu", "Lechaim",
    "Rebrol-nek", "AlliWar Wickson", "Oguhmk", "Telloc Cyaj",
#ifdef OVERLAY
    "Erreip", "Nehpets", "Mron", "Snivek", "Kahztiy",
#endif
#ifdef WIN32
    "Lexa", "Niod",
#endif
#ifdef MAC
    "Nhoj-lee", "Evad\'kh", "Ettaw-noj", "Tsew-mot", "Ydna-s", "Yao-hang",
    "Tonbar", "Kivenhoug", "Llardom",
#endif
#ifdef AMIGA
    "Falo", "Nosid-da\'r", "Ekim-p", "Noslo", "Yl-rednow", "Mured-oog",
    "Ivrajimsal",
#endif
#ifdef TOS
    "Nivram",
#endif
#ifdef OS2
    "Nedraawi-nav",
#endif
#ifdef VMS
    "Lez-tneg", "Ytnu-haled",
#endif
    0
};

static const char *const shklight[] = {
    /* Romania */
    "Zarnesti", "Slanic", "Nehoiasu", "Ludus", "Sighisoara", "Nisipitu",
    "Razboieni", "Bicaz", "Dorohoi", "Vaslui", "Fetesti", "Tirgu Neamt",
    "Babadag", "Zimnicea", "Zlatna", "Jiu", "Eforie", "Mamaia",
    /* Bulgaria */
    "Silistra", "Tulovo", "Panagyuritshte", "Smolyan", "Kirklareli", "Pernik",
    "Lom", "Haskovo", "Dobrinishte", "Varvara", "Oryahovo", "Troyan",
    "Lovech", "Sliven", 0
};

static const char *const shkgeneral[] = {
    /* Suriname */
    "Hebiwerie",    "Possogroenoe", "Asidonhopo",   "Manlobbi",
    "Adjama",       "Pakka Pakka",  "Kabalebo",     "Wonotobo",
    "Akalapi",      "Sipaliwini",
    /* Greenland */
    "Annootok",     "Upernavik",    "Angmagssalik",
    /* N. Canada */
    "Aklavik",      "Inuvik",       "Tuktoyaktuk",  "Chicoutimi",
    "Ouiatchouane", "Chibougamau",  "Matagami",     "Kipawa",
    "Kinojevis",    "Abitibi",      "Maganasipi",
    /* Iceland */
    "Akureyri",     "Kopasker",     "Budereyri",    "Akranes",
    "Bordeyri",     "Holmavik",     0
};

static const char* const shkreagents[] = {
	/* AD&D mages and others*/
	"Merlin",    "Mordenkainen", "Leomund",   "Rary",
	"Bigby",     "Otiluke",  "Tenser", "Elminster",
	"Bucknard",  "Drawmij",  "Nystul", "Otto",
	"Gandalf",   "Saruman",     0
};


static const char *const shkhealthfoods[] = {
    /* Tibet */
    "Ga'er",    "Zhangmu",   "Rikaze",   "Jiangji",     "Changdu",
    "Linzhi",   "Shigatse",  "Gyantse",  "Ganden",      "Tsurphu",
    "Lhasa",    "Tsedong",   "Drepung",
    /* Hippie names */
    "=Azura",   "=Blaze",    "=Breanna", "=Breezy",     "=Dharma",
    "=Feather", "=Jasmine",  "=Luna",    "=Melody",     "=Moonjava",
    "=Petal",   "=Rhiannon", "=Starla",  "=Tranquilla", "=Windsong",
    "=Zennia",  "=Zoe",      "=Zora",    0
};

/*
 * To add new shop types, all that is necessary is to edit the shtypes[]
 * array.  See mkroom.h for the structure definition.  Typically, you'll
 * have to lower some or all of the probability fields in old entries to
 * free up some percentage for the new type.
 *
 * The placement type field is not yet used but will be in the near future.
 *
 * The iprobs array in each entry defines the probabilities for various kinds
 * of objects to be present in the given shop type.  You can associate with
 * each percentage either a generic object type (represented by one of the
 * *_CLASS macros) or a specific object (represented by an onames.h define).
 * In the latter case, prepend it with a unary minus so the code can know
 * (by testing the sign) whether to use mkobj() or mksobj().
 */
const struct shclass shtypes[] = {
    { "general store",
      RANDOM_CLASS,
	  "an item",
      39,
      D_SHOP,
      { { 100, RANDOM_CLASS },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
        { 0, 0 } },
      shkgeneral },
    { "used armor dealership",
      ARMOR_CLASS,
	  "a piece of armor or weapon",
	  14,
      D_SHOP,
      { { 90, ARMOR_CLASS },
        { 10, WEAPON_CLASS },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 } },
      shkarmors },
    { "second-hand bookstore",
      SCROLL_CLASS,
	  "a scroll or spellbook",
	  10,
      D_SHOP,
      { { 90, SCROLL_CLASS },
        { 10, SPBOOK_CLASS },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 } },
      shkbooks },
    { "liquor emporium",
      POTION_CLASS,
	  "a potion",
	  10,
      D_SHOP,
      { { 100, POTION_CLASS },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 } },
      shkliquors },
    { "antique weapons outlet",
      WEAPON_CLASS,
	  "a weapon or piece of armor",
	  5,
      D_SHOP,
      { { 90, WEAPON_CLASS },
        { 10, ARMOR_CLASS },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 } },
      shkweapons },
    { "delicatessen",
      FOOD_CLASS,
	  "a food item or potion",
	  5,
      D_SHOP,
      { { 81, FOOD_CLASS },
        { 2, POTION_CLASS },
        { 5, -POT_FRUIT_JUICE },
        { 4, -POT_BOOZE },
        { 5, -POT_WATER },
        { 3, -ICE_BOX },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 } },
      shkfoods },
    { "jewelers",
      RING_CLASS,
	  "a ring, gem, or amulet",
	  3,
      D_SHOP,
      { { 85, RING_CLASS },
        { 10, GEM_CLASS },
        { 5, AMULET_CLASS },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
        { 0, 0 },
        { 0, 0 } },
      shkrings },
    { "quality apparel and accessories",
      WAND_CLASS,
	  "a wand or apparel",
	  3,
      D_SHOP,
      { { 90, WAND_CLASS },
        { 5, -LEATHER_GLOVES },
        { 5, -ELVEN_CLOAK },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 } },
      shkwands },
    { "hardware store",
      TOOL_CLASS,
	  "a tool",
	  3,
      D_SHOP,
      { { 100, TOOL_CLASS },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 } },
      shktools },
	{ "rare books",
      SPBOOK_CLASS,
	  "a spellbook or scroll",
	  3,
      D_SHOP,
      { { 90, SPBOOK_CLASS },
        { 10, SCROLL_CLASS },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 },
        { 0, 0 },
        { 0, 0 },
        { 0, 0 } },
      shkbooks },
	{ "quality reagents and components",
		REAGENT_CLASS,
	    "a reagent or gem",
		3,
		D_SHOP,
		{ { 50, REAGENT_CLASS },
		  { 40, GEM_CLASS },
		  { 1, -BONE_DAGGER },
		  { 2, -HOLY_SYMBOL },
		  { 3, -MAGIC_MUSHROOM },
		  { 2, -PANTHER_CAP },
		  { 2, -DEATH_CAP },
		  { 0, 0 },
		  { 0, 0 },
		  { 0, 0 } },
		shkreagents },
	{ "health food store",
      FOOD_CLASS,
	  "a health food item",
	  2,
      D_SHOP,
      { { 67, VEGETARIAN_CLASS },
        { 20, -POT_FRUIT_JUICE },
        { 4, -POT_HEALING },
        { 3, -POT_FULL_HEALING },
        { 2, -SCR_FOOD_DETECTION },
		{ 1, -LUMP_OF_ROYAL_JELLY  },
		{ 3, -POT_GREATER_HEALING  },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 } },
      shkhealthfoods },
    /* Shops below this point are "unique".  That is they must all have a
     * probability of zero.  They are only created via the special level
     * loader.
     */
    { "lighting store",
      TOOL_CLASS,
	  "a lighting item",
	  0,
      D_SHOP,
      { { 30, -WAX_CANDLE },
        { 45, -TALLOW_CANDLE },
        { 5, -BRASS_LANTERN },
        { 9, -OIL_LAMP },
        { 3, -MAGIC_LAMP },
        { 5, -POT_OIL },
		{ 3, -MAGIC_CANDLE },
		{ 0, 0 },
		{ 0, 0 },
		{ 0, 0 } },
		  shklight },
		  /* sentinel */
    { (char *) 0,
      0,
	  (char*)0,
      0,
      0,
      { { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 }, { 0, 0 } },
      0 }
};

#if 0
/* validate shop probabilities; otherwise incorrect local changes could
   end up provoking infinite loops or wild subscripts fetching garbage */
void
init_shop_selection()
{
    register int i, j, item_prob, shop_prob;

    for (shop_prob = 0, i = 0; i < SIZE(shtypes); i++) {
        shop_prob += shtypes[i].prob;
        for (item_prob = 0, j = 0; j < SIZE(shtypes[0].iprobs); j++)
            item_prob += shtypes[i].iprobs[j].iprob;
        if (item_prob != 100)
            panic("item probabilities total to %d for %s shops!",
                  item_prob, shtypes[i].name);
    }
    if (shop_prob != 100)
        panic("shop probabilities total to %d!", shop_prob);
}
#endif /*0*/

/* decide whether an object or object type is considered vegetarian;
   for types, items which might go either way are assumed to be veggy */
boolean
veggy_item(obj, otyp)
struct obj *obj;
int otyp; /* used iff obj is null */
{
    int corpsenm;
    char oclass;

    if (obj) {
        /* actual object; will check tin content and corpse species */
        otyp = (int) obj->otyp;
        oclass = obj->oclass;
        corpsenm = obj->corpsenm;
    } else {
        /* just a type; caller will have to handle tins and corpses */
        oclass = objects[otyp].oc_class;
        corpsenm = PM_LICHEN; /* veggy standin */
    }

    if (oclass == FOOD_CLASS) {
        if (objects[otyp].oc_material == MAT_VEGGY || otyp == EGG)
            return TRUE;
        if (otyp == TIN && corpsenm == NON_PM) /* implies obj is non-null */
            return (boolean) (obj->special_quality == 1); /* 0 = empty, 1 = spinach */
        if (otyp == TIN || otyp == CORPSE)
            return (boolean) (corpsenm >= LOW_PM
                              && vegetarian(&mons[corpsenm]));
    }
    return FALSE;
}

STATIC_OVL int
shkveg()
{
    int i, j, maxprob, prob;
    char oclass = FOOD_CLASS;
    int ok[NUM_OBJECTS];

    j = maxprob = 0;
    ok[0] = 0; /* lint suppression */
    for (i = bases[(int) oclass]; i < NUM_OBJECTS; ++i) {
        if (objects[i].oc_class != oclass)
            break;

        if (veggy_item((struct obj *) 0, i)) {
            ok[j++] = i;
            maxprob += objects[i].oc_prob;
        }
    }
	if (maxprob < 1)
	{
		panic("shkveg no veggy objects");
		return 0;
	}
    prob = rnd(maxprob);

    j = 0;
    i = ok[0];
    while ((prob -= objects[i].oc_prob) > 0) {
        j++;
        i = ok[j];
    }

    if (objects[i].oc_class != oclass || !OBJ_NAME(objects[i]))
        panic("shkveg probtype error, oclass=%d i=%d", (int) oclass, i);
    return i;
}

/* make a random item for health food store */
STATIC_OVL void
mkveggy_at(sx, sy)
int sx, sy;
{
    struct obj *obj = mksobj_at(shkveg(), sx, sy, TRUE, TRUE);

    if (obj && obj->otyp == TIN)
        set_tin_variety(obj, HEALTHY_TIN);
    return;
}

/* make an object of the appropriate type for a shop square */
STATIC_OVL void
mkshobj_at(shp, sx, sy, mkspecl, deserted)
const struct shclass *shp;
int sx, sy;
boolean mkspecl;
boolean deserted;
{
    struct monst *mtmp;
    struct permonst *ptr;
    int atype;

	if (deserted && mkspecl)
	{
		if (!MON_AT(sx, sy) && !t_at(sx, sy)
			&& (mtmp = makemon(&mons[PM_GARGANTUAN_MIMIC], sx, sy, NO_MM_FLAGS)) != 0) {
			/* note: makemon will set the mimic symbol to a shop item */
			if (rn2(10) >= depth(&u.uz)) {
				mtmp->m_ap_type = M_AP_OBJECT;
				mtmp->mappearance = STRANGE_OBJECT;
			}
			(void)mongets(mtmp, WAN_IDENTIFY);
		}
		else
		{
			struct obj* otmp = mksobj_at(WAN_IDENTIFY, sx, sy, TRUE, FALSE);
		}
		return;
	}
	else
	{
		/* 3.6 tribute */
		if (mkspecl && (!strcmp(shp->name, "rare books")
						|| !strcmp(shp->name, "second-hand bookstore"))) {
			struct obj *novel = mksobj_at(SPE_NOVEL, sx, sy, FALSE, FALSE);

			if (novel)
				context.tribute.bookstock = TRUE;
			return;
		}
	}
    if ((!deserted && rn2(100) < min(10, depth(&u.uz)) && !MON_AT(sx, sy) && !t_at(sx, sy)
        && (ptr = mkclass(S_MIMIC, 0)) != 0
        && (mtmp = makemon(ptr, sx, sy, NO_MM_FLAGS)) != 0) || (deserted && !rn2(4) && !MON_AT(sx, sy)
			&& (ptr = mkclass(S_MIMIC, 0)) != 0
			&& (mtmp = makemon(ptr, sx, sy, NO_MM_FLAGS)) != 0)) {
        /* note: makemon will set the mimic symbol to a shop item */
        if (rn2(10) >= depth(&u.uz)) {
            mtmp->m_ap_type = M_AP_OBJECT;
            mtmp->mappearance = STRANGE_OBJECT;
        }
    } else if(!deserted || !rn2(2)) {
        atype = get_shop_item((int) (shp - shtypes));
        if (atype == VEGETARIAN_CLASS)
            mkveggy_at(sx, sy);
        else if (atype < 0)
            (void) mksobj_at(-atype, sx, sy, TRUE, TRUE);
        else
            (void) mkobj_at(atype, sx, sy, TRUE);
    }
}


/* extract a shopkeeper name for the given shop type */
STATIC_OVL void
nameshk(shk, nlp)
struct monst *shk;
const char *const *nlp;
{
    int i, trycnt, names_avail;
    const char *shname = 0;
    struct monst *mtmp;
    int name_wanted;
    s_level *sptr;

    if (nlp == shkfoods && In_mines(&u.uz) && Role_if(PM_MONK)
        && (sptr = Is_special(&u.uz)) != 0 && sptr->flags.town) {
        /* special-case override for minetown food store for monks */
        nlp = shkhealthfoods;
    }

    if (nlp == shklight && In_mines(&u.uz) && (sptr = Is_special(&u.uz)) != 0
        && sptr->flags.town) {
        /* special-case minetown lighting shk */
        shname = "+Izchak";
        shk->female = FALSE;
    } else {
        /* We want variation from game to game, without needing the save
           and restore support which would be necessary for randomization;
           try not to make too many assumptions about time_t's internals;
           use ledger_no rather than depth to keep mine town distinct. */
        int nseed = (int) ((long) ubirthday / 257L);

        name_wanted = ledger_no(&u.uz) + (nseed % 13) - (nseed % 5);
        if (name_wanted < 0)
            name_wanted += (13 + 5);
        shk->female = name_wanted & 1;

        for (names_avail = 0; nlp[names_avail]; names_avail++)
            continue;

        for (trycnt = 0; trycnt < 50; trycnt++) {
            if (nlp == shktools) {
                shname = shktools[rn2(names_avail)];
                shk->female = 0; /* reversed below for '_' prefix */
            } else if (name_wanted < names_avail) {
                shname = nlp[name_wanted];
            } else if ((i = rn2(names_avail)) != 0) {
                shname = nlp[i - 1];
            } else if (nlp != shkgeneral) {
                nlp = shkgeneral; /* try general names */
                for (names_avail = 0; nlp[names_avail]; names_avail++)
                    continue;
                continue; /* next `trycnt' iteration */
            } else {
                shname = shk->female ? "-Lucrezia" : "+Dirk";
            }
            if (*shname == '_' || *shname == '-')
                shk->female = 1;
            else if (*shname == '|' || *shname == '+')
                shk->female = 0;

            /* is name already in use on this level? */
            for (mtmp = fmon; mtmp; mtmp = mtmp->nmon) {
                if (DEADMONSTER(mtmp) || (mtmp == shk) || !mtmp->isshk)
                    continue;
                if (strcmp(ESHK(mtmp)->shknam, shname))
                    continue;
                break;
            }
            if (!mtmp)
                break; /* new name */
        }
    }
    (void) strncpy(ESHK(shk)->shknam, shname, PL_NSIZ);
    ESHK(shk)->shknam[PL_NSIZ - 1] = 0;
}

void
neweshk(mtmp)
struct monst *mtmp;
{
    if (!mtmp->mextra)
        mtmp->mextra = newmextra();
    if (!ESHK(mtmp))
        ESHK(mtmp) = (struct eshk *) alloc(sizeof(struct eshk));
    (void) memset((genericptr_t) ESHK(mtmp), 0, sizeof(struct eshk));
    ESHK(mtmp)->bill_p = (struct bill_x *) 0;
}

void
free_eshk(mtmp)
struct monst *mtmp;
{
    if (mtmp->mextra && ESHK(mtmp)) {
        free((genericptr_t) ESHK(mtmp));
        ESHK(mtmp) = (struct eshk *) 0;
    }
    mtmp->isshk = 0;
}

/* create a new shopkeeper in the given room */
STATIC_OVL int
shkinit(shp, sroom)
const struct shclass *shp;
struct mkroom *sroom;
{
    register int sh, sx, sy;
    struct monst *shk;
    struct eshk *eshkp;

    /* place the shopkeeper in the given room */
    sh = sroom->fdoor;
    sx = doors[sh].x;
    sy = doors[sh].y;

    /* check that the shopkeeper placement is sane */
    if (sroom->irregular) {
        int rmno = (int) ((sroom - rooms) + ROOMOFFSET);

        if (isok(sx - 1, sy) && !levl[sx - 1][sy].edge
            && (int) levl[sx - 1][sy].roomno == rmno)
            sx--;
        else if (isok(sx + 1, sy) && !levl[sx + 1][sy].edge
                 && (int) levl[sx + 1][sy].roomno == rmno)
            sx++;
        else if (isok(sx, sy - 1) && !levl[sx][sy - 1].edge
                 && (int) levl[sx][sy - 1].roomno == rmno)
            sy--;
        else if (isok(sx, sy + 1) && !levl[sx][sy + 1].edge
                 && (int) levl[sx][sy + 1].roomno == rmno)
            sy++;
        else
            goto shk_failed;
    } else if (sx == sroom->lx - 1) {
        sx++;
    } else if (sx == sroom->hx + 1) {
        sx--;
    } else if (sy == sroom->ly - 1) {
        sy++;
    } else if (sy == sroom->hy + 1) {
        sy--;
    } else {
    shk_failed:
#ifdef DEBUG
        /* Said to happen sometimes, but I have never seen it. */
        /* Supposedly fixed by fdoor change in mklev.c */
        if (wizard) {
            register int j = sroom->doorct;

            pline("Where is shopdoor?");
            pline("Room at (%d,%d),(%d,%d).", sroom->lx, sroom->ly, sroom->hx,
                  sroom->hy);
            pline("doormax=%d doorct=%d fdoor=%d", doorindex, sroom->doorct,
                  sh);
            while (j--) {
                pline("door [%d,%d]", doors[sh].x, doors[sh].y);
                sh++;
            }
            display_nhwindow(WIN_MESSAGE, FALSE);
        }
#endif
        return -1;
    }

    if (MON_AT(sx, sy))
        (void) rloc(m_at(sx, sy), FALSE); /* insurance */

    /* now initialize the shopkeeper monster structure */
    int shkomontype = PM_SHOPKEEPER;

    if (Inhell)
    {
        shkomontype = get_gehennom_undead_spellcaster(shkomontype);
    }

    if (!(shk = makemon(&mons[shkomontype], sx, sy, MM_ESHK)))
        return -1;

    eshkp = ESHK(shk); /* makemon(...,MM_ESHK) allocates this */
    shk->isshk = shk->mpeaceful = 1;
    set_malign(shk);
    shk->msleeping = 0;
    shk->mtrapseen = ~0; /* we know all the traps already */
    eshkp->shoproom = (schar) ((sroom - rooms) + ROOMOFFSET);
    sroom->resident = shk;
    eshkp->shoptype = sroom->rtype;
    assign_level(&eshkp->shoplevel, &u.uz);
    eshkp->shd = doors[sh];
    eshkp->shk.x = sx;
    eshkp->shk.y = sy;
    eshkp->robbed = eshkp->credit = eshkp->debit = eshkp->loan = 0L;
    eshkp->following = eshkp->surcharge = eshkp->dismiss_kops = FALSE;
    eshkp->billct = eshkp->visitct = 0;
    eshkp->bill_p = (struct bill_x *) 0;
    eshkp->customer[0] = '\0';
    mkmonmoney(shk, 1000L + 30L * (long) rnd(100)); /* initial capital */
    if (shp->shknms == shkrings)
        (void) mongets(shk, TOUCHSTONE);
    nameshk(shk, shp->shknms);

    return sh;
}

STATIC_OVL boolean
stock_room_goodpos(sroom, rmno, sh, sx, sy)
struct mkroom *sroom;
int rmno, sh, sx,sy;
{
    if (sroom->irregular) {
        if (levl[sx][sy].edge
            || (int) levl[sx][sy].roomno != rmno
            || distmin(sx, sy, doors[sh].x, doors[sh].y) <= 1)
            return FALSE;
    } else if ((sx == sroom->lx && doors[sh].x == sx - 1)
               || (sx == sroom->hx && doors[sh].x == sx + 1)
               || (sy == sroom->ly && doors[sh].y == sy - 1)
               || (sy == sroom->hy && doors[sh].y == sy + 1))
        return FALSE;
    return TRUE;
}

int
get_gehennom_undead_spellcaster(origtype)
int origtype;
{
    int shkomontype = origtype;
    boolean arch_lich_gone = (mvitals[PM_ARCH_LICH].mvflags & G_GONE);
    boolean master_lich_gone = (mvitals[PM_MASTER_LICH].mvflags & G_GONE);
    boolean demilich_gone = (mvitals[PM_DEMILICH].mvflags & G_GONE);
    boolean lich_gone = (mvitals[PM_LICH].mvflags & G_GONE);
    boolean illithilich_gone = (mvitals[PM_ILLITHILICH].mvflags & G_GONE);
    boolean ghost_gone = (mvitals[PM_GHOST].mvflags & G_GONE);
    boolean vampire_mage_gone = (mvitals[PM_VAMPIRE_MAGE].mvflags & G_GONE);
    boolean all_liches_gone = arch_lich_gone && master_lich_gone && demilich_gone && lich_gone;

    if (arch_lich_gone && all_liches_gone && vampire_mage_gone && ghost_gone)
        shkomontype = PM_SHOPKEEPER;
    else if (all_liches_gone && illithilich_gone && vampire_mage_gone)
        shkomontype = PM_GHOST;
    else if (all_liches_gone && illithilich_gone && !ghost_gone)
        shkomontype = !rn2(2) ? PM_VAMPIRE_MAGE : PM_GHOST;
    else if (all_liches_gone && illithilich_gone)
        shkomontype = PM_VAMPIRE_MAGE;
    else if (all_liches_gone)
        shkomontype = !rn2(2) ? PM_ILLITHILICH : PM_VAMPIRE_MAGE;
    else if (!arch_lich_gone && !illithilich_gone)
        shkomontype = !rn2(2) ? PM_ILLITHILICH : PM_ARCH_LICH;
    else if (!arch_lich_gone)
        shkomontype = PM_ARCH_LICH;
    else if (!master_lich_gone && !illithilich_gone)
        shkomontype = !rn2(2) ? PM_ILLITHILICH : PM_MASTER_LICH;
    else if (!arch_lich_gone)
        shkomontype = PM_MASTER_LICH;
    else if (!demilich_gone && !illithilich_gone)
        shkomontype = !rn2(2) ? PM_ILLITHILICH : PM_DEMILICH;
    else if (!demilich_gone)
        shkomontype = PM_DEMILICH;
    else if (!lich_gone && !illithilich_gone)
        shkomontype = !rn2(2) ? PM_ILLITHILICH : PM_LICH;
    else if (!lich_gone)
        shkomontype = PM_LICH;

    return shkomontype;
}

/* stock a newly-created room with objects */
void
stock_room(shp_indx, sroom, deserted)
int shp_indx;
register struct mkroom *sroom;
boolean deserted;
{
    /*
     * Someday soon we'll dispatch on the shdist field of shclass to do
     * different placements in this routine. Currently it only supports
     * shop-style placement (all squares except a row nearest the first
     * door get objects).
     */
    int sx = 0, sy = 0, sh = 0;
    int stockcount = 0, specialspot = 0;
    char buf[BUFSZ];
    int rmno = (int) ((sroom - rooms) + ROOMOFFSET);
    const struct shclass *shp = &shtypes[shp_indx];

    /* first, try to place a shopkeeper in the room */
	if(!deserted)
	{
		if ((sh = shkinit(shp, sroom)) < 0)
			return;
	}

	/* make sure no doorways without doors, and no trapped doors, in shops */
    sx = doors[sroom->fdoor].x;
    sy = doors[sroom->fdoor].y;
    if (levl[sx][sy].doormask == D_NODOOR && (!deserted || !rn2(2)))
	{
        levl[sx][sy].doormask = D_ISOPEN;
        newsym(sx, sy);
    }
    if (levl[sx][sy].typ == SDOOR) {
        cvt_sdoor_to_door(sx, sy); /* .typ = DOOR */
        newsym(sx, sy);
    }
    if (levl[sx][sy].doormask & D_TRAPPED)
        levl[sx][sy].doormask = deserted? D_ISOPEN : D_LOCKED;

    if (levl[sx][sy].doormask == D_LOCKED) {
        register int m = sx, n = sy;

        if (inside_shop(sx + 1, sy))
            m--;
        else if (inside_shop(sx - 1, sy))
            m++;
        if (inside_shop(sx, sy + 1))
            n--;
        else if (inside_shop(sx, sy - 1))
            n++;
        Sprintf(buf, "Closed for inventory");
        make_engr_at(m, n, buf, 0L, DUST);
    }

    if (deserted || (context.tribute.enabled && !context.tribute.bookstock)) {
        /*
         * Out of the number of spots where we're actually
         * going to put stuff, randomly single out one in particular.
         */
        for (sx = sroom->lx; sx <= sroom->hx; sx++)
            for (sy = sroom->ly; sy <= sroom->hy; sy++)
                if (deserted || stock_room_goodpos(sroom, rmno, sh, sx,sy))
                    stockcount++;
        specialspot = rnd(stockcount);
        stockcount = 0;
    }

    for (sx = sroom->lx; sx <= sroom->hx; sx++)
    {

        for (sy = sroom->ly; sy <= sroom->hy; sy++)
        {

            if (deserted || stock_room_goodpos(sroom, rmno, sh, sx,sy))
            {
                stockcount++;
                mkshobj_at(shp, sx, sy,
                           ((stockcount) && (stockcount == specialspot)), deserted);
            }
        }
    }

    /*
     * Special monster placements (if any) should go here: that way,
     * monsters will sit on top of objects and not the other way around.
     */

	if(deserted)
		level.flags.has_desertedshop = TRUE;
	else
		level.flags.has_shop = TRUE;
}

/* does shkp's shop stock this item type? */
boolean
saleable(shkp, obj)
struct monst *shkp;
struct obj *obj;
{
    int i, shp_indx = ESHK(shkp)->shoptype - SHOPBASE;
    const struct shclass *shp = &shtypes[shp_indx];

    if (shp->symb == RANDOM_CLASS)
        return TRUE;
    for (i = 0; i < SIZE(shtypes[0].iprobs) && shp->iprobs[i].iprob; i++) {
        /* pseudo-class needs special handling */
        if (shp->iprobs[i].itype == VEGETARIAN_CLASS)
		{
            if (veggy_item(obj, 0))
                return TRUE;
        }
		else if ((shp->iprobs[i].itype < 0)
                       ? shp->iprobs[i].itype == -obj->otyp
                       : shp->iprobs[i].itype == obj->oclass)
            return TRUE;
    }
    /* not found */
    return FALSE;
}

/* positive value: class; negative value: specific object type */
int
get_shop_item(type)
int type;
{
    const struct shclass *shp = shtypes + type;
    register int i, j;

    /* select an appropriate object type at random */
    for (j = rnd(100), i = 0; (j -= shp->iprobs[i].iprob) > 0; i++)
        continue;

    return shp->iprobs[i].itype;
}

/* version of shkname() for beginning of sentence */
char *
Shknam(mtmp)
struct monst *mtmp;
{
	char* nam;
	nam = shkname(mtmp);

    /* 'nam[]' is almost certainly already capitalized, but be sure */
    *nam = highc(*nam);
    return nam;
}

/* shopkeeper's name, without any visibility constraint; if hallucinating,
   will yield some other shopkeeper's name (not necessarily one residing
   in the current game's dungeon, or who keeps same type of shop) */
char *
shkname(mtmp)
struct monst *mtmp;
{
	static char nam[BUFSZ] = "shopkeeper";

    unsigned save_isshk = mtmp->isshk;

    mtmp->isshk = 0; /* don't want mon_nam() calling shkname() */
	if (mtmp->data)
		strcpy(nam, noit_mon_nam(mtmp));
	/* get a modifiable name buffer along with fallback result */
    mtmp->isshk = save_isshk;

    if (!mtmp->isshk) {
		impossible("shkname: \"%s\" is not a shopkeeper.", nam);
    } else if (!has_eshk(mtmp)) {
		panic("shkname: shopkeeper \"%s\" lacks 'eshk' data.", nam);
		return "";
    } else {
        const char *shknm = ESHK(mtmp)->shknam;

        if (Hallucination && !program_state.gameover) {
            const char *const *nlp;
            int num;

            /* count the number of non-unique shop types;
               pick one randomly, ignoring shop generation probabilities;
               pick a name at random from that shop type's list */
            for (num = 0; num < SIZE(shtypes); num++)
                if (shtypes[num].prob == 0)
                    break;
            if (num > 0) {
                nlp = shtypes[rn2(num)].shknms;
                for (num = 0; nlp[num]; num++)
                    continue;
                if (num > 0)
                    shknm = nlp[rn2(num)];
            }
        }
        /* strip prefix if present */
        if (!letter(*shknm))
            ++shknm;
        Strcpy(nam, shknm);
    }
    return nam;
}


const char*
shoptypename(shoptype)
int shoptype;
{
	const char* shopname = shtypes[shoptype - SHOPBASE].name;
	return shopname;
}

boolean
shkname_is_pname(mtmp)
struct monst *mtmp;
{
    const char *shknm = ESHK(mtmp)->shknam;

    return (boolean) (*shknm == '-' || *shknm == '+' || *shknm == '=');
}

boolean
is_izchak(shkp, override_hallucination)
struct monst *shkp;
boolean override_hallucination;
{
    const char *shknm;

    if (Hallucination && !override_hallucination)
        return FALSE;
    if (!shkp->isshk)
        return FALSE;
    /* outside of town, Izchak becomes just an ordinary shopkeeper */
    if (!in_town(shkp->mx, shkp->my))
        return FALSE;
    shknm = ESHK(shkp)->shknam;
    /* skip "+" prefix */
    if (!letter(*shknm))
        ++shknm;
    return (boolean) !strcmp(shknm, "Izchak");
}

/*shknam.c*/

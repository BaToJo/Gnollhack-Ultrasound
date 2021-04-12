
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.
   
   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.
   
   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.
   
   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 1 "lev_comp.y"

/* GnollHack 4.0  lev_comp.y	$NHDT-Date: 1543371691 2018/11/28 02:21:31 $  $NHDT-Branch: NetHack-3.6.2-beta01 $:$NHDT-Revision: 1.22 $ */
/*      Copyright (c) 1989 by Jean-Christophe Collet */
/* GnollHack may be freely redistributed.  See license for details. */

/*
 * This file contains the Level Compiler code
 * It may handle special mazes & special room-levels
 */

/* In case we're using bison in AIX.  This definition must be
 * placed before any other C-language construct in the file
 * excluding comments and preprocessor directives (thanks IBM
 * for this wonderful feature...).
 *
 * Note: some cpps barf on this 'undefined control' (#pragma).
 * Addition of the leading space seems to prevent barfage for now,
 * and AIX will still see the directive.
 */
#ifdef _AIX
 #pragma alloca         /* keep leading space! */
#endif

#define SPEC_LEV    /* for USE_OLDARGS (sp_lev.h) */
#include "hack.h"
#include "sp_lev.h"

#define ERR             (-1)
/* many types of things are put in chars for transference to NetHack.
 * since some systems will use signed chars, limit everybody to the
 * same number for portability.
 */
#define MAX_OF_TYPE     128

#define MAX_NESTED_IFS   20
#define MAX_SWITCH_CASES 20

#define New(type) \
        (type *) memset((genericptr_t) alloc(sizeof (type)), 0, sizeof (type))
#define NewTab(type, size)      (type **) alloc(sizeof (type *) * size)
#define Free(ptr)               free((genericptr_t) ptr)

extern void VDECL(lc_error, (const char *, ...));
extern void VDECL(lc_warning, (const char *, ...));
extern void FDECL(yyerror, (const char *));
extern void FDECL(yywarning, (const char *));
extern int NDECL(yylex);
int NDECL(yyparse);

extern int FDECL(get_floor_type, (CHAR_P));
extern int FDECL(get_room_type, (char *));
extern int FDECL(get_trap_type, (char *));
extern int FDECL(get_monster_id, (char *,CHAR_P));
extern int FDECL(get_object_id, (char *,CHAR_P));
extern boolean FDECL(check_monster_char, (CHAR_P));
extern boolean FDECL(check_object_char, (CHAR_P));
extern char FDECL(what_map_char, (CHAR_P));
extern void FDECL(scan_map, (char *, sp_lev *));
extern void FDECL(add_opcode, (sp_lev *, int, genericptr_t));
extern genericptr_t FDECL(get_last_opcode_data1, (sp_lev *, int));
extern genericptr_t FDECL(get_last_opcode_data2, (sp_lev *, int, int));
extern boolean FDECL(check_subrooms, (sp_lev *));
extern boolean FDECL(write_level_file, (char *,sp_lev *));
extern struct opvar *FDECL(set_opvar_int, (struct opvar *, long));
extern void VDECL(add_opvars, (sp_lev *, const char *, ...));
extern void FDECL(start_level_def, (sp_lev * *, char *));

extern struct lc_funcdefs *FDECL(funcdef_new, (long,char *));
extern void FDECL(funcdef_free_all, (struct lc_funcdefs *));
extern struct lc_funcdefs *FDECL(funcdef_defined, (struct lc_funcdefs *,
                                                   char *, int));
extern char *FDECL(funcdef_paramtypes, (struct lc_funcdefs *));
extern char *FDECL(decode_parm_str, (char *));

extern struct lc_vardefs *FDECL(vardef_new, (long,char *));
extern void FDECL(vardef_free_all, (struct lc_vardefs *));
extern struct lc_vardefs *FDECL(vardef_defined, (struct lc_vardefs *,
                                                 char *, int));

extern void NDECL(break_stmt_start);
extern void FDECL(break_stmt_end, (sp_lev *));
extern void FDECL(break_stmt_new, (sp_lev *, long));

extern void FDECL(splev_add_from, (sp_lev *, sp_lev *));

extern void FDECL(check_vardef_type, (struct lc_vardefs *, char *, long));
extern void FDECL(vardef_used, (struct lc_vardefs *, char *));
extern struct lc_vardefs *FDECL(add_vardef_type, (struct lc_vardefs *,
                                                  char *, long));

extern int FDECL(reverse_jmp_opcode, (int));

struct coord {
    long x;
    long y;
};

struct forloopdef {
    char *varname;
    long jmp_point;
};
static struct forloopdef forloop_list[MAX_NESTED_IFS];
static short n_forloops = 0;


sp_lev *splev = NULL;

static struct opvar *if_list[MAX_NESTED_IFS];

static short n_if_list = 0;

unsigned int max_x_map, max_y_map;
int obj_containment = 0;

int in_container_obj = 0;

/* integer value is possibly an inconstant value (eg. dice notation
   or a variable) */
int is_inconstant_number = 0;

int in_switch_statement = 0;
static struct opvar *switch_check_jump = NULL;
static struct opvar *switch_default_case = NULL;
static struct opvar *switch_case_list[MAX_SWITCH_CASES];
static long switch_case_value[MAX_SWITCH_CASES];
int n_switch_case_list = 0;

int allow_break_statements = 0;
struct lc_breakdef *break_list = NULL;

extern struct lc_vardefs *vardefs; /* variable definitions */


struct lc_vardefs *function_tmp_var_defs = NULL;
extern struct lc_funcdefs *function_definitions;
struct lc_funcdefs *curr_function = NULL;
struct lc_funcdefs_parm * curr_function_param = NULL;
int in_function_definition = 0;
sp_lev *function_splev_backup = NULL;

extern int fatal_error;
extern int got_errors;
extern int line_number;
extern const char *fname;

extern char curr_token[512];



/* Line 189 of yacc.c  */
#line 223 "lev_comp.tab.c"

/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif


/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     CHAR = 258,
     INTEGER = 259,
     BOOLEAN = 260,
     PERCENT = 261,
     SPERCENT = 262,
     MINUS_INTEGER = 263,
     PLUS_INTEGER = 264,
     MAZE_GRID_ID = 265,
     SOLID_FILL_ID = 266,
     MINES_ID = 267,
     ROGUELEV_ID = 268,
     MESSAGE_ID = 269,
     MAZE_ID = 270,
     LEVEL_ID = 271,
     LEV_INIT_ID = 272,
     TILESET_ID = 273,
     GEOMETRY_ID = 274,
     NOMAP_ID = 275,
     BOUNDARY_TYPE_ID = 276,
     OBJECT_ID = 277,
     COBJECT_ID = 278,
     MONSTER_ID = 279,
     TRAP_ID = 280,
     DOOR_ID = 281,
     DRAWBRIDGE_ID = 282,
     object_ID = 283,
     monster_ID = 284,
     terrain_ID = 285,
     MAZEWALK_ID = 286,
     WALLIFY_ID = 287,
     REGION_ID = 288,
     SPECIAL_REGION_ID = 289,
     SPECIAL_LEVREGION_ID = 290,
     SPECIAL_REGION_TYPE = 291,
     NAMING_ID = 292,
     NAMING_TYPE = 293,
     FILLING = 294,
     IRREGULAR = 295,
     JOINED = 296,
     ALTAR_ID = 297,
     ANVIL_ID = 298,
     NPC_ID = 299,
     LADDER_ID = 300,
     STAIR_ID = 301,
     NON_DIGGABLE_ID = 302,
     NON_PASSWALL_ID = 303,
     ROOM_ID = 304,
     ARTIFACT_NAME_ID = 305,
     PORTAL_ID = 306,
     TELEPRT_ID = 307,
     BRANCH_ID = 308,
     LEV = 309,
     MINERALIZE_ID = 310,
     CORRIDOR_ID = 311,
     GOLD_ID = 312,
     ENGRAVING_ID = 313,
     FOUNTAIN_ID = 314,
     THRONE_ID = 315,
     MODRON_PORTAL_ID = 316,
     LEVEL_TELEPORTER_ID = 317,
     LEVEL_TELEPORT_DIRECTION_TYPE = 318,
     LEVEL_TELEPORT_END_TYPE = 319,
     POOL_ID = 320,
     SINK_ID = 321,
     NONE = 322,
     RAND_CORRIDOR_ID = 323,
     DOOR_STATE = 324,
     LIGHT_STATE = 325,
     CURSE_TYPE = 326,
     ENGRAVING_TYPE = 327,
     KEYTYPE_ID = 328,
     LEVER_ID = 329,
     NO_PICKUP_ID = 330,
     DIRECTION = 331,
     RANDOM_TYPE = 332,
     RANDOM_TYPE_BRACKET = 333,
     A_REGISTER = 334,
     ALIGNMENT = 335,
     LEFT_OR_RIGHT = 336,
     CENTER = 337,
     TOP_OR_BOT = 338,
     ALTAR_TYPE = 339,
     UP_OR_DOWN = 340,
     ACTIVE_OR_INACTIVE = 341,
     MODRON_PORTAL_TYPE = 342,
     NPC_TYPE = 343,
     FOUNTAIN_TYPE = 344,
     SPECIAL_OBJECT_TYPE = 345,
     CMAP_TYPE = 346,
     FLOOR_TYPE = 347,
     FLOOR_TYPE_ID = 348,
     FLOOR_ID = 349,
     FLOOR_MAIN_TYPE = 350,
     FLOOR_MAIN_TYPE_ID = 351,
     ELEMENTAL_ENCHANTMENT_TYPE = 352,
     EXCEPTIONALITY_TYPE = 353,
     EXCEPTIONALITY_ID = 354,
     ELEMENTAL_ENCHANTMENT_ID = 355,
     ENCHANTMENT_ID = 356,
     SECRET_DOOR_ID = 357,
     USES_UP_KEY_ID = 358,
     MYTHIC_PREFIX_TYPE = 359,
     MYTHIC_SUFFIX_TYPE = 360,
     MYTHIC_PREFIX_ID = 361,
     MYTHIC_SUFFIX_ID = 362,
     CHARGES_ID = 363,
     SPECIAL_QUALITY_ID = 364,
     SPEFLAGS_ID = 365,
     SUBROOM_ID = 366,
     NAME_ID = 367,
     FLAGS_ID = 368,
     FLAG_TYPE = 369,
     MON_ATTITUDE = 370,
     MON_ALERTNESS = 371,
     SUBTYPE_ID = 372,
     NON_PASSDOOR_ID = 373,
     MON_APPEARANCE = 374,
     ROOMDOOR_ID = 375,
     IF_ID = 376,
     ELSE_ID = 377,
     TERRAIN_ID = 378,
     HORIZ_OR_VERT = 379,
     REPLACE_TERRAIN_ID = 380,
     LOCATION_SUBTYPE_ID = 381,
     DOOR_SUBTYPE = 382,
     BRAZIER_SUBTYPE = 383,
     SIGNPOST_SUBTYPE = 384,
     EXIT_ID = 385,
     SHUFFLE_ID = 386,
     QUANTITY_ID = 387,
     BURIED_ID = 388,
     LOOP_ID = 389,
     FOR_ID = 390,
     TO_ID = 391,
     SWITCH_ID = 392,
     CASE_ID = 393,
     BREAK_ID = 394,
     DEFAULT_ID = 395,
     ERODED_ID = 396,
     TRAPPED_STATE = 397,
     RECHARGED_ID = 398,
     INVIS_ID = 399,
     GREASED_ID = 400,
     INDESTRUCTIBLE_ID = 401,
     FEMALE_ID = 402,
     WAITFORU_ID = 403,
     CANCELLED_ID = 404,
     REVIVED_ID = 405,
     AVENGE_ID = 406,
     FLEEING_ID = 407,
     BLINDED_ID = 408,
     PARALYZED_ID = 409,
     STUNNED_ID = 410,
     CONFUSED_ID = 411,
     SEENTRAPS_ID = 412,
     ALL_ID = 413,
     MONTYPE_ID = 414,
     OBJTYPE_ID = 415,
     TERTYPE_ID = 416,
     TERTYPE2_ID = 417,
     LEVER_EFFECT_TYPE = 418,
     SWITCHABLE_ID = 419,
     CONTINUOUSLY_USABLE_ID = 420,
     TARGET_ID = 421,
     TRAPTYPE_ID = 422,
     EFFECT_FLAG_ID = 423,
     GRAVE_ID = 424,
     BRAZIER_ID = 425,
     SIGNPOST_ID = 426,
     ERODEPROOF_ID = 427,
     FUNCTION_ID = 428,
     MSG_OUTPUT_TYPE = 429,
     COMPARE_TYPE = 430,
     UNKNOWN_TYPE = 431,
     rect_ID = 432,
     fillrect_ID = 433,
     line_ID = 434,
     randline_ID = 435,
     grow_ID = 436,
     selection_ID = 437,
     flood_ID = 438,
     rndcoord_ID = 439,
     circle_ID = 440,
     ellipse_ID = 441,
     filter_ID = 442,
     complement_ID = 443,
     gradient_ID = 444,
     GRADIENT_TYPE = 445,
     LIMITED = 446,
     HUMIDITY_TYPE = 447,
     STRING = 448,
     MAP_ID = 449,
     NQSTRING = 450,
     VARSTRING = 451,
     CFUNC = 452,
     CFUNC_INT = 453,
     CFUNC_STR = 454,
     CFUNC_COORD = 455,
     CFUNC_REGION = 456,
     VARSTRING_INT = 457,
     VARSTRING_INT_ARRAY = 458,
     VARSTRING_STRING = 459,
     VARSTRING_STRING_ARRAY = 460,
     VARSTRING_VAR = 461,
     VARSTRING_VAR_ARRAY = 462,
     VARSTRING_COORD = 463,
     VARSTRING_COORD_ARRAY = 464,
     VARSTRING_REGION = 465,
     VARSTRING_REGION_ARRAY = 466,
     VARSTRING_MAPCHAR = 467,
     VARSTRING_MAPCHAR_ARRAY = 468,
     VARSTRING_MONST = 469,
     VARSTRING_MONST_ARRAY = 470,
     VARSTRING_OBJ = 471,
     VARSTRING_OBJ_ARRAY = 472,
     VARSTRING_SEL = 473,
     VARSTRING_SEL_ARRAY = 474,
     METHOD_INT = 475,
     METHOD_INT_ARRAY = 476,
     METHOD_STRING = 477,
     METHOD_STRING_ARRAY = 478,
     METHOD_VAR = 479,
     METHOD_VAR_ARRAY = 480,
     METHOD_COORD = 481,
     METHOD_COORD_ARRAY = 482,
     METHOD_REGION = 483,
     METHOD_REGION_ARRAY = 484,
     METHOD_MAPCHAR = 485,
     METHOD_MAPCHAR_ARRAY = 486,
     METHOD_MONST = 487,
     METHOD_MONST_ARRAY = 488,
     METHOD_OBJ = 489,
     METHOD_OBJ_ARRAY = 490,
     METHOD_SEL = 491,
     METHOD_SEL_ARRAY = 492,
     DICE = 493
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 151 "lev_comp.y"

    long    i;
    char    *map;
    struct {
        long room;
        long wall;
        long door;
    } corpos;
    struct {
        long area;
        long x1;
        long y1;
        long x2;
        long y2;
    } lregn;
    struct {
        long x;
        long y;
    } crd;
    struct {
        long ter;
        long lit;
    } terr;
    struct {
        long height;
        long width;
    } sze;
    struct {
        long die;
        long num;
    } dice;
    struct {
        long cfunc;
        char *varstr;
    } meth;



/* Line 214 of yacc.c  */
#line 536 "lev_comp.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 548 "lev_comp.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1267

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  256
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  184
/* YYNRULES -- Number of rules.  */
#define YYNRULES  493
/* YYNRULES -- Number of states.  */
#define YYNSTATES  1092

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   493

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,   251,   255,     2,
     195,   196,   249,   247,   193,   248,   253,   250,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   194,     2,
       2,   252,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   197,     2,   198,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   199,   254,   200,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   108,   109,   110,   111,   112,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,   137,   138,   139,   140,   141,   142,   143,   144,
     145,   146,   147,   148,   149,   150,   151,   152,   153,   154,
     155,   156,   157,   158,   159,   160,   161,   162,   163,   164,
     165,   166,   167,   168,   169,   170,   171,   172,   173,   174,
     175,   176,   177,   178,   179,   180,   181,   182,   183,   184,
     185,   186,   187,   188,   189,   190,   191,   192,   201,   202,
     203,   204,   205,   206,   207,   208,   209,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   228,   229,   230,   231,   232,
     233,   234,   235,   236,   237,   238,   239,   240,   241,   242,
     243,   244,   245,   246
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     6,     8,    11,    15,    19,    25,
      31,    37,    41,    58,    62,    66,    67,    70,    71,    74,
      75,    78,    80,    82,    83,    87,    91,    93,    94,    97,
     101,   103,   105,   107,   109,   111,   113,   115,   117,   119,
     121,   123,   125,   127,   129,   131,   133,   135,   137,   139,
     141,   143,   145,   147,   149,   151,   153,   155,   157,   159,
     161,   163,   165,   167,   169,   171,   173,   175,   177,   179,
     181,   183,   185,   187,   189,   191,   193,   195,   197,   199,
     201,   203,   205,   207,   209,   211,   213,   215,   217,   219,
     221,   223,   225,   227,   229,   231,   233,   235,   237,   239,
     241,   243,   245,   247,   249,   251,   253,   255,   257,   259,
     261,   263,   267,   271,   277,   281,   287,   293,   299,   303,
     307,   313,   319,   325,   333,   341,   349,   355,   357,   361,
     363,   367,   369,   373,   375,   379,   381,   385,   387,   391,
     393,   397,   398,   399,   408,   413,   415,   416,   418,   420,
     426,   430,   431,   432,   442,   443,   446,   447,   453,   454,
     459,   461,   464,   466,   473,   474,   478,   479,   486,   487,
     492,   493,   498,   500,   501,   506,   510,   512,   516,   520,
     526,   532,   540,   545,   546,   560,   561,   577,   578,   581,
     587,   589,   595,   597,   603,   605,   611,   613,   624,   631,
     633,   635,   637,   639,   641,   645,   647,   649,   650,   654,
     658,   662,   666,   668,   670,   672,   674,   676,   684,   690,
     692,   694,   696,   698,   702,   703,   709,   714,   715,   719,
     721,   723,   725,   727,   730,   732,   734,   736,   738,   740,
     744,   748,   752,   754,   756,   760,   762,   764,   766,   770,
     774,   775,   781,   784,   785,   789,   791,   795,   797,   801,
     805,   807,   809,   813,   815,   817,   819,   823,   825,   827,
     829,   833,   837,   841,   845,   849,   853,   857,   861,   865,
     867,   869,   871,   877,   885,   891,   900,   902,   906,   910,
     916,   922,   930,   938,   945,   951,   952,   955,   961,   965,
     977,   991,   998,   999,  1003,  1005,  1009,  1013,  1017,  1021,
    1023,  1025,  1029,  1033,  1037,  1041,  1045,  1049,  1051,  1053,
    1055,  1057,  1061,  1065,  1067,  1073,  1083,  1089,  1093,  1097,
    1103,  1113,  1119,  1125,  1126,  1140,  1141,  1143,  1151,  1163,
    1167,  1175,  1183,  1189,  1195,  1205,  1211,  1217,  1221,  1229,
    1233,  1241,  1249,  1253,  1259,  1267,  1277,  1279,  1281,  1283,
    1285,  1287,  1288,  1291,  1293,  1297,  1299,  1301,  1303,  1304,
    1308,  1310,  1311,  1315,  1317,  1318,  1322,  1324,  1326,  1328,
    1330,  1332,  1334,  1336,  1338,  1340,  1344,  1346,  1348,  1353,
    1355,  1357,  1362,  1364,  1366,  1371,  1373,  1378,  1384,  1386,
    1390,  1392,  1396,  1398,  1400,  1405,  1415,  1417,  1419,  1424,
    1426,  1432,  1434,  1436,  1441,  1443,  1445,  1451,  1453,  1455,
    1457,  1462,  1464,  1466,  1472,  1474,  1476,  1478,  1482,  1484,
    1486,  1490,  1492,  1497,  1501,  1505,  1509,  1513,  1517,  1521,
    1523,  1525,  1529,  1531,  1535,  1536,  1538,  1540,  1542,  1544,
    1548,  1549,  1551,  1553,  1556,  1559,  1564,  1571,  1576,  1583,
    1590,  1597,  1604,  1607,  1614,  1623,  1632,  1643,  1658,  1661,
    1663,  1667,  1669,  1673,  1675,  1677,  1679,  1681,  1683,  1685,
    1687,  1689,  1691,  1693,  1695,  1697,  1699,  1701,  1703,  1705,
    1707,  1709,  1711,  1722
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     257,     0,    -1,    -1,   258,    -1,   259,    -1,   259,   258,
      -1,   260,   268,   270,    -1,    16,   194,   201,    -1,    15,
     194,   201,   193,     3,    -1,    17,   194,    11,   193,   368,
      -1,    17,   194,    10,   193,     3,    -1,    17,   194,    13,
      -1,    17,   194,    12,   193,     3,   193,     3,   193,     5,
     193,     5,   193,   401,   193,   267,   266,    -1,    18,   194,
     431,    -1,    21,   194,    95,    -1,    -1,   193,   191,    -1,
      -1,   193,   408,    -1,    -1,   193,     3,    -1,     5,    -1,
      77,    -1,    -1,   113,   194,   269,    -1,   114,   193,   269,
      -1,   114,    -1,    -1,   272,   270,    -1,   199,   270,   200,
      -1,   313,    -1,   261,    -1,   262,    -1,   263,    -1,   382,
      -1,   381,    -1,   379,    -1,   380,    -1,   383,    -1,   384,
      -1,   385,    -1,   386,    -1,   357,    -1,   315,    -1,   278,
      -1,   277,    -1,   371,    -1,   327,    -1,   349,    -1,   388,
      -1,   389,    -1,   359,    -1,   360,    -1,   361,    -1,   387,
      -1,   293,    -1,   303,    -1,   305,    -1,   309,    -1,   307,
      -1,   290,    -1,   300,    -1,   286,    -1,   289,    -1,   352,
      -1,   362,    -1,   334,    -1,   350,    -1,   337,    -1,   343,
      -1,   372,    -1,   367,    -1,   355,    -1,   314,    -1,   373,
      -1,   374,    -1,   375,    -1,   376,    -1,   320,    -1,   318,
      -1,   366,    -1,   370,    -1,   369,    -1,   353,    -1,   354,
      -1,   356,    -1,   348,    -1,   351,    -1,   211,    -1,   213,
      -1,   215,    -1,   217,    -1,   219,    -1,   221,    -1,   223,
      -1,   225,    -1,   227,    -1,   210,    -1,   212,    -1,   214,
      -1,   216,    -1,   218,    -1,   220,    -1,   222,    -1,   224,
      -1,   226,    -1,   273,    -1,   274,    -1,   204,    -1,   204,
      -1,   274,    -1,   131,   194,   273,    -1,   275,   252,   420,
      -1,   275,   252,   182,   194,   429,    -1,   275,   252,   419,
      -1,   275,   252,   436,   194,   413,    -1,   275,   252,   435,
     194,   415,    -1,   275,   252,   434,   194,   417,    -1,   275,
     252,   408,    -1,   275,   252,   411,    -1,   275,   252,   199,
     284,   200,    -1,   275,   252,   199,   283,   200,    -1,   275,
     252,   199,   282,   200,    -1,   275,   252,   436,   194,   199,
     281,   200,    -1,   275,   252,   435,   194,   199,   280,   200,
      -1,   275,   252,   434,   194,   199,   279,   200,    -1,   275,
     252,   199,   285,   200,    -1,   418,    -1,   279,   193,   418,
      -1,   416,    -1,   280,   193,   416,    -1,   414,    -1,   281,
     193,   414,    -1,   412,    -1,   282,   193,   412,    -1,   409,
      -1,   283,   193,   409,    -1,   420,    -1,   284,   193,   420,
      -1,   419,    -1,   285,   193,   419,    -1,    -1,    -1,   173,
     203,   195,   287,   424,   196,   288,   271,    -1,   203,   195,
     427,   196,    -1,   130,    -1,    -1,     6,    -1,     6,    -1,
     197,   420,   175,   420,   198,    -1,   197,   420,   198,    -1,
      -1,    -1,   137,   294,   197,   407,   198,   295,   199,   296,
     200,    -1,    -1,   297,   296,    -1,    -1,   138,   432,   194,
     298,   270,    -1,    -1,   140,   194,   299,   270,    -1,   139,
      -1,   253,   253,    -1,   136,    -1,   135,   276,   252,   420,
     301,   420,    -1,    -1,   302,   304,   271,    -1,    -1,   134,
     197,   407,   198,   306,   271,    -1,    -1,   292,   194,   308,
     272,    -1,    -1,   121,   292,   310,   311,    -1,   271,    -1,
      -1,   271,   312,   122,   271,    -1,    14,   194,   419,    -1,
      68,    -1,    68,   194,   432,    -1,    68,   194,    77,    -1,
      56,   194,   316,   193,   316,    -1,    56,   194,   316,   193,
     432,    -1,   195,     4,   193,    76,   193,   331,   196,    -1,
     391,   291,   193,   401,    -1,    -1,   111,   194,   317,   193,
     324,   193,   326,   392,   395,   397,   399,   319,   271,    -1,
      -1,    49,   194,   317,   193,   323,   193,   325,   193,   326,
     392,   395,   397,   399,   321,   271,    -1,    -1,   193,     5,
      -1,   195,     4,   193,     4,   196,    -1,    77,    -1,   195,
       4,   193,     4,   196,    -1,    77,    -1,   195,   335,   193,
     336,   196,    -1,    77,    -1,   195,     4,   193,     4,   196,
      -1,    77,    -1,   120,   194,   328,   193,   400,   193,   329,
     193,   331,   332,    -1,    26,   194,   400,   193,   429,   332,
      -1,     5,    -1,    77,    -1,   330,    -1,    77,    -1,    76,
      -1,    76,   254,   330,    -1,     4,    -1,    77,    -1,    -1,
     332,   193,   333,    -1,   126,   194,   127,    -1,    73,   194,
     417,    -1,   109,   194,     4,    -1,   146,    -1,   102,    -1,
     103,    -1,   118,    -1,    20,    -1,    19,   194,   335,   193,
     336,   322,   202,    -1,    19,   194,   408,   322,   202,    -1,
      81,    -1,    82,    -1,    83,    -1,    82,    -1,    24,   194,
     339,    -1,    -1,    24,   194,   339,   338,   271,    -1,   415,
     193,   408,   340,    -1,    -1,   340,   193,   341,    -1,   419,
      -1,   115,    -1,   116,    -1,   403,    -1,   119,   419,    -1,
     147,    -1,   144,    -1,   149,    -1,   150,    -1,   151,    -1,
     152,   194,   407,    -1,   153,   194,   407,    -1,   154,   194,
     407,    -1,   155,    -1,   156,    -1,   157,   194,   342,    -1,
     148,    -1,   201,    -1,   158,    -1,   201,   254,   342,    -1,
      22,   194,   345,    -1,    -1,    23,   194,   345,   344,   271,
      -1,   417,   346,    -1,    -1,   346,   193,   347,    -1,    71,
      -1,   159,   194,   415,    -1,   433,    -1,   112,   194,   419,
      -1,   132,   194,   407,    -1,   133,    -1,    70,    -1,   141,
     194,   407,    -1,   172,    -1,    69,    -1,   142,    -1,   143,
     194,   407,    -1,   144,    -1,   145,    -1,   408,    -1,   100,
     194,    97,    -1,    99,   194,    98,    -1,   106,   194,   104,
      -1,   107,   194,   105,    -1,   101,   194,   407,    -1,   108,
     194,   407,    -1,   109,   194,   407,    -1,   110,   194,   407,
      -1,    73,   194,   417,    -1,   146,    -1,   103,    -1,    75,
      -1,    25,   194,   390,   193,   408,    -1,    27,   194,   408,
     193,    76,   193,   400,    -1,    31,   194,   408,   193,    76,
      -1,    31,   194,   408,   193,    76,   193,     5,   266,    -1,
      32,    -1,    32,   194,   429,    -1,    32,   194,   158,    -1,
      45,   194,   408,   193,    85,    -1,    46,   194,   408,   193,
      85,    -1,    46,   194,   438,   193,   438,   193,    85,    -1,
      51,   194,   438,   193,   438,   193,   201,    -1,    52,   194,
     438,   193,   438,   358,    -1,    53,   194,   438,   193,   438,
      -1,    -1,   193,    85,    -1,    59,   194,   429,   193,    89,
      -1,    60,   194,   429,    -1,    61,   194,   408,   193,   166,
     194,   408,   193,    87,   193,    86,    -1,    61,   194,   408,
     193,    62,   193,    63,   193,    64,   193,    87,   193,    86,
      -1,    74,   194,   408,   193,   163,   363,    -1,    -1,   363,
     193,   364,    -1,    86,    -1,   159,   194,   415,    -1,   160,
     194,   417,    -1,   161,   194,   368,    -1,   162,   194,   368,
      -1,   164,    -1,   165,    -1,   166,   194,   408,    -1,   167,
     194,   390,    -1,   126,   194,   365,    -1,    93,   194,   398,
      -1,   168,   194,     4,    -1,   109,   194,     4,    -1,     4,
      -1,    87,    -1,   127,    -1,    89,    -1,    66,   194,   429,
      -1,    65,   194,   429,    -1,     3,    -1,   195,     3,   193,
     401,   196,    -1,   125,   194,   411,   193,   413,   193,   413,
     193,     7,    -1,   123,   194,   429,   193,   413,    -1,    47,
     194,   411,    -1,    48,   194,   411,    -1,    37,   194,   201,
     193,    38,    -1,    37,   194,   201,   193,    38,   193,   159,
     194,   415,    -1,    34,   194,   411,   193,    36,    -1,    35,
     194,   438,   193,    36,    -1,    -1,    33,   194,   411,   193,
     401,   193,   391,   392,   395,   397,   399,   377,   378,    -1,
      -1,   271,    -1,    42,   194,   408,   193,   402,   193,   404,
      -1,    42,   194,   408,   193,   402,   193,   404,   193,   159,
     194,   415,    -1,    43,   194,   408,    -1,    43,   194,   408,
     193,   159,   194,   415,    -1,    94,   194,   429,   193,    95,
     193,    92,    -1,   117,   194,   429,   193,     4,    -1,    44,
     194,    88,   193,   408,    -1,    44,   194,    88,   193,   408,
     193,   159,   194,   415,    -1,   169,   194,   408,   193,   419,
      -1,   169,   194,   408,   193,    77,    -1,   169,   194,   408,
      -1,   170,   194,   408,   193,   128,   193,   401,    -1,   170,
     194,   408,    -1,   171,   194,   408,   193,   129,   193,   419,
      -1,   171,   194,   408,   193,   129,   193,    77,    -1,   171,
     194,   408,    -1,    57,   194,   420,   193,   408,    -1,    58,
     194,   408,   193,   437,   193,   419,    -1,    55,   194,   407,
     193,   407,   193,   407,   193,   407,    -1,    55,    -1,   201,
      -1,    77,    -1,   201,    -1,    77,    -1,    -1,   193,   393,
      -1,   394,    -1,   394,   193,   393,    -1,    39,    -1,    40,
      -1,    41,    -1,    -1,    96,   194,   396,    -1,    95,    -1,
      -1,    93,   194,   398,    -1,    92,    -1,    -1,   159,   194,
     415,    -1,    69,    -1,    77,    -1,    70,    -1,    77,    -1,
      80,    -1,   405,    -1,    77,    -1,    80,    -1,   405,    -1,
      79,   194,    77,    -1,    84,    -1,    77,    -1,    79,   197,
       4,   198,    -1,   201,    -1,   212,    -1,   213,   197,   420,
     198,    -1,   420,    -1,   409,    -1,   184,   195,   429,   196,
      -1,   216,    -1,   217,   197,   420,   198,    -1,   195,     4,
     193,     4,   196,    -1,    77,    -1,    78,   410,   198,    -1,
     192,    -1,   192,   193,   410,    -1,   412,    -1,   218,    -1,
     219,   197,   420,   198,    -1,   195,     4,   193,     4,   193,
       4,   193,     4,   196,    -1,   414,    -1,   220,    -1,   221,
     197,   420,   198,    -1,     3,    -1,   195,     3,   193,   401,
     196,    -1,   416,    -1,   222,    -1,   223,   197,   420,   198,
      -1,   201,    -1,     3,    -1,   195,     3,   193,   201,   196,
      -1,    77,    -1,   418,    -1,   224,    -1,   225,   197,   420,
     198,    -1,   201,    -1,     3,    -1,   195,     3,   193,   201,
     196,    -1,    77,    -1,    90,    -1,   406,    -1,   419,   253,
     406,    -1,     4,    -1,   430,    -1,   195,     8,   196,    -1,
     210,    -1,   211,   197,   420,   198,    -1,   420,   247,   420,
      -1,   420,   248,   420,    -1,   420,   249,   420,    -1,   420,
     250,   420,    -1,   420,   251,   420,    -1,   195,   420,   196,
      -1,   206,    -1,   207,    -1,   275,   194,   421,    -1,   422,
      -1,   423,   193,   422,    -1,    -1,   423,    -1,   420,    -1,
     419,    -1,   425,    -1,   426,   193,   425,    -1,    -1,   426,
      -1,   408,    -1,   177,   411,    -1,   178,   411,    -1,   179,
     408,   193,   408,    -1,   180,   408,   193,   408,   193,   420,
      -1,   181,   195,   429,   196,    -1,   181,   195,   330,   193,
     429,   196,    -1,   187,   195,     7,   193,   429,   196,    -1,
     187,   195,   429,   193,   429,   196,    -1,   187,   195,   413,
     193,   429,   196,    -1,   183,   408,    -1,   185,   195,   408,
     193,   420,   196,    -1,   185,   195,   408,   193,   420,   193,
      39,   196,    -1,   186,   195,   408,   193,   420,   193,   420,
     196,    -1,   186,   195,   408,   193,   420,   193,   420,   193,
      39,   196,    -1,   189,   195,   190,   193,   195,   420,   248,
     420,   264,   196,   193,   408,   265,   196,    -1,   188,   428,
      -1,   226,    -1,   195,   429,   196,    -1,   428,    -1,   428,
     255,   429,    -1,   246,    -1,    91,    -1,     4,    -1,     8,
      -1,     9,    -1,     4,    -1,     8,    -1,     9,    -1,     4,
      -1,   430,    -1,    28,    -1,    22,    -1,    29,    -1,    24,
      -1,    30,    -1,   123,    -1,    72,    -1,    77,    -1,   439,
      -1,    54,   195,     4,   193,     4,   193,     4,   193,     4,
     196,    -1,   195,     4,   193,     4,   193,     4,   193,     4,
     196,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   284,   284,   285,   288,   289,   292,   315,   320,   342,
     355,   367,   373,   402,   408,   415,   418,   425,   429,   436,
     439,   446,   447,   451,   454,   461,   465,   472,   475,   481,
     487,   488,   489,   490,   491,   492,   493,   494,   495,   496,
     497,   498,   499,   500,   501,   502,   503,   504,   505,   506,
     507,   508,   509,   510,   511,   512,   513,   514,   515,   516,
     517,   518,   519,   520,   521,   522,   523,   524,   525,   526,
     527,   528,   529,   530,   531,   532,   533,   534,   535,   536,
     537,   538,   539,   540,   541,   542,   543,   544,   547,   548,
     549,   550,   551,   552,   553,   554,   555,   558,   559,   560,
     561,   562,   563,   564,   565,   566,   569,   570,   571,   574,
     575,   578,   594,   600,   606,   612,   618,   624,   630,   636,
     642,   652,   662,   672,   682,   692,   702,   714,   719,   726,
     731,   738,   743,   750,   754,   760,   765,   772,   776,   782,
     786,   793,   815,   792,   829,   884,   891,   894,   900,   907,
     911,   920,   924,   919,   987,   988,   992,   991,  1005,  1004,
    1019,  1029,  1030,  1033,  1071,  1070,  1105,  1104,  1135,  1134,
    1167,  1166,  1192,  1203,  1202,  1230,  1236,  1241,  1246,  1253,
    1260,  1269,  1277,  1289,  1288,  1312,  1311,  1333,  1336,  1342,
    1352,  1358,  1367,  1373,  1378,  1384,  1389,  1395,  1406,  1412,
    1413,  1416,  1417,  1420,  1424,  1430,  1431,  1435,  1441,  1449,
    1454,  1459,  1464,  1469,  1474,  1479,  1487,  1494,  1502,  1510,
    1511,  1514,  1515,  1518,  1523,  1522,  1536,  1543,  1550,  1558,
    1563,  1569,  1575,  1581,  1587,  1592,  1597,  1602,  1607,  1612,
    1617,  1622,  1627,  1632,  1637,  1643,  1650,  1659,  1663,  1676,
    1685,  1684,  1702,  1712,  1718,  1726,  1732,  1737,  1742,  1747,
    1752,  1757,  1762,  1767,  1772,  1786,  1792,  1797,  1802,  1807,
    1812,  1817,  1822,  1827,  1832,  1837,  1842,  1847,  1852,  1857,
    1862,  1867,  1874,  1880,  1909,  1914,  1922,  1928,  1932,  1940,
    1947,  1954,  1964,  1974,  1989,  2000,  2003,  2009,  2015,  2021,
    2025,  2031,  2038,  2044,  2052,  2058,  2063,  2068,  2073,  2078,
    2084,  2090,  2095,  2100,  2105,  2110,  2115,  2122,  2122,  2122,
    2122,  2125,  2131,  2137,  2142,  2149,  2156,  2162,  2168,  2174,
    2179,  2186,  2192,  2203,  2202,  2234,  2237,  2243,  2248,  2255,
    2259,  2265,  2271,  2277,  2281,  2287,  2291,  2296,  2303,  2307,
    2314,  2318,  2323,  2330,  2336,  2343,  2347,  2354,  2362,  2365,
    2375,  2379,  2382,  2388,  2392,  2399,  2403,  2407,  2414,  2417,
    2423,  2430,  2433,  2439,  2446,  2450,  2457,  2458,  2461,  2462,
    2465,  2466,  2467,  2473,  2474,  2475,  2481,  2482,  2485,  2494,
    2499,  2506,  2517,  2523,  2527,  2531,  2538,  2548,  2555,  2559,
    2565,  2569,  2577,  2581,  2588,  2598,  2611,  2615,  2622,  2632,
    2641,  2652,  2656,  2663,  2673,  2684,  2693,  2703,  2709,  2713,
    2720,  2730,  2741,  2750,  2760,  2764,  2771,  2772,  2778,  2782,
    2786,  2790,  2798,  2807,  2811,  2815,  2819,  2823,  2827,  2830,
    2837,  2846,  2879,  2880,  2883,  2884,  2887,  2891,  2898,  2905,
    2916,  2919,  2927,  2931,  2935,  2939,  2943,  2948,  2952,  2956,
    2961,  2966,  2971,  2975,  2980,  2985,  2989,  2993,  2998,  3002,
    3009,  3015,  3019,  3025,  3032,  3033,  3036,  3037,  3038,  3041,
    3045,  3049,  3053,  3059,  3060,  3063,  3064,  3067,  3068,  3071,
    3072,  3075,  3079,  3105
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "CHAR", "INTEGER", "BOOLEAN", "PERCENT",
  "SPERCENT", "MINUS_INTEGER", "PLUS_INTEGER", "MAZE_GRID_ID",
  "SOLID_FILL_ID", "MINES_ID", "ROGUELEV_ID", "MESSAGE_ID", "MAZE_ID",
  "LEVEL_ID", "LEV_INIT_ID", "TILESET_ID", "GEOMETRY_ID", "NOMAP_ID",
  "BOUNDARY_TYPE_ID", "OBJECT_ID", "COBJECT_ID", "MONSTER_ID", "TRAP_ID",
  "DOOR_ID", "DRAWBRIDGE_ID", "object_ID", "monster_ID", "terrain_ID",
  "MAZEWALK_ID", "WALLIFY_ID", "REGION_ID", "SPECIAL_REGION_ID",
  "SPECIAL_LEVREGION_ID", "SPECIAL_REGION_TYPE", "NAMING_ID",
  "NAMING_TYPE", "FILLING", "IRREGULAR", "JOINED", "ALTAR_ID", "ANVIL_ID",
  "NPC_ID", "LADDER_ID", "STAIR_ID", "NON_DIGGABLE_ID", "NON_PASSWALL_ID",
  "ROOM_ID", "ARTIFACT_NAME_ID", "PORTAL_ID", "TELEPRT_ID", "BRANCH_ID",
  "LEV", "MINERALIZE_ID", "CORRIDOR_ID", "GOLD_ID", "ENGRAVING_ID",
  "FOUNTAIN_ID", "THRONE_ID", "MODRON_PORTAL_ID", "LEVEL_TELEPORTER_ID",
  "LEVEL_TELEPORT_DIRECTION_TYPE", "LEVEL_TELEPORT_END_TYPE", "POOL_ID",
  "SINK_ID", "NONE", "RAND_CORRIDOR_ID", "DOOR_STATE", "LIGHT_STATE",
  "CURSE_TYPE", "ENGRAVING_TYPE", "KEYTYPE_ID", "LEVER_ID", "NO_PICKUP_ID",
  "DIRECTION", "RANDOM_TYPE", "RANDOM_TYPE_BRACKET", "A_REGISTER",
  "ALIGNMENT", "LEFT_OR_RIGHT", "CENTER", "TOP_OR_BOT", "ALTAR_TYPE",
  "UP_OR_DOWN", "ACTIVE_OR_INACTIVE", "MODRON_PORTAL_TYPE", "NPC_TYPE",
  "FOUNTAIN_TYPE", "SPECIAL_OBJECT_TYPE", "CMAP_TYPE", "FLOOR_TYPE",
  "FLOOR_TYPE_ID", "FLOOR_ID", "FLOOR_MAIN_TYPE", "FLOOR_MAIN_TYPE_ID",
  "ELEMENTAL_ENCHANTMENT_TYPE", "EXCEPTIONALITY_TYPE", "EXCEPTIONALITY_ID",
  "ELEMENTAL_ENCHANTMENT_ID", "ENCHANTMENT_ID", "SECRET_DOOR_ID",
  "USES_UP_KEY_ID", "MYTHIC_PREFIX_TYPE", "MYTHIC_SUFFIX_TYPE",
  "MYTHIC_PREFIX_ID", "MYTHIC_SUFFIX_ID", "CHARGES_ID",
  "SPECIAL_QUALITY_ID", "SPEFLAGS_ID", "SUBROOM_ID", "NAME_ID", "FLAGS_ID",
  "FLAG_TYPE", "MON_ATTITUDE", "MON_ALERTNESS", "SUBTYPE_ID",
  "NON_PASSDOOR_ID", "MON_APPEARANCE", "ROOMDOOR_ID", "IF_ID", "ELSE_ID",
  "TERRAIN_ID", "HORIZ_OR_VERT", "REPLACE_TERRAIN_ID",
  "LOCATION_SUBTYPE_ID", "DOOR_SUBTYPE", "BRAZIER_SUBTYPE",
  "SIGNPOST_SUBTYPE", "EXIT_ID", "SHUFFLE_ID", "QUANTITY_ID", "BURIED_ID",
  "LOOP_ID", "FOR_ID", "TO_ID", "SWITCH_ID", "CASE_ID", "BREAK_ID",
  "DEFAULT_ID", "ERODED_ID", "TRAPPED_STATE", "RECHARGED_ID", "INVIS_ID",
  "GREASED_ID", "INDESTRUCTIBLE_ID", "FEMALE_ID", "WAITFORU_ID",
  "CANCELLED_ID", "REVIVED_ID", "AVENGE_ID", "FLEEING_ID", "BLINDED_ID",
  "PARALYZED_ID", "STUNNED_ID", "CONFUSED_ID", "SEENTRAPS_ID", "ALL_ID",
  "MONTYPE_ID", "OBJTYPE_ID", "TERTYPE_ID", "TERTYPE2_ID",
  "LEVER_EFFECT_TYPE", "SWITCHABLE_ID", "CONTINUOUSLY_USABLE_ID",
  "TARGET_ID", "TRAPTYPE_ID", "EFFECT_FLAG_ID", "GRAVE_ID", "BRAZIER_ID",
  "SIGNPOST_ID", "ERODEPROOF_ID", "FUNCTION_ID", "MSG_OUTPUT_TYPE",
  "COMPARE_TYPE", "UNKNOWN_TYPE", "rect_ID", "fillrect_ID", "line_ID",
  "randline_ID", "grow_ID", "selection_ID", "flood_ID", "rndcoord_ID",
  "circle_ID", "ellipse_ID", "filter_ID", "complement_ID", "gradient_ID",
  "GRADIENT_TYPE", "LIMITED", "HUMIDITY_TYPE", "','", "':'", "'('", "')'",
  "'['", "']'", "'{'", "'}'", "STRING", "MAP_ID", "NQSTRING", "VARSTRING",
  "CFUNC", "CFUNC_INT", "CFUNC_STR", "CFUNC_COORD", "CFUNC_REGION",
  "VARSTRING_INT", "VARSTRING_INT_ARRAY", "VARSTRING_STRING",
  "VARSTRING_STRING_ARRAY", "VARSTRING_VAR", "VARSTRING_VAR_ARRAY",
  "VARSTRING_COORD", "VARSTRING_COORD_ARRAY", "VARSTRING_REGION",
  "VARSTRING_REGION_ARRAY", "VARSTRING_MAPCHAR", "VARSTRING_MAPCHAR_ARRAY",
  "VARSTRING_MONST", "VARSTRING_MONST_ARRAY", "VARSTRING_OBJ",
  "VARSTRING_OBJ_ARRAY", "VARSTRING_SEL", "VARSTRING_SEL_ARRAY",
  "METHOD_INT", "METHOD_INT_ARRAY", "METHOD_STRING", "METHOD_STRING_ARRAY",
  "METHOD_VAR", "METHOD_VAR_ARRAY", "METHOD_COORD", "METHOD_COORD_ARRAY",
  "METHOD_REGION", "METHOD_REGION_ARRAY", "METHOD_MAPCHAR",
  "METHOD_MAPCHAR_ARRAY", "METHOD_MONST", "METHOD_MONST_ARRAY",
  "METHOD_OBJ", "METHOD_OBJ_ARRAY", "METHOD_SEL", "METHOD_SEL_ARRAY",
  "DICE", "'+'", "'-'", "'*'", "'/'", "'%'", "'='", "'.'", "'|'", "'&'",
  "$accept", "file", "levels", "level", "level_def", "lev_init",
  "tileset_detail", "boundary_type_detail", "opt_limited",
  "opt_coord_or_var", "opt_fillchar", "walled", "flags", "flag_list",
  "levstatements", "stmt_block", "levstatement", "any_var_array",
  "any_var", "any_var_or_arr", "any_var_or_unk", "shuffle_detail",
  "variable_define", "encodeobj_list", "encodemonster_list",
  "mapchar_list", "encoderegion_list", "encodecoord_list", "integer_list",
  "string_list", "function_define", "$@1", "$@2", "function_call",
  "exitstatement", "opt_percent", "comparestmt", "switchstatement", "$@3",
  "$@4", "switchcases", "switchcase", "$@5", "$@6", "breakstatement",
  "for_to_span", "forstmt_start", "forstatement", "$@7", "loopstatement",
  "$@8", "chancestatement", "$@9", "ifstatement", "$@10", "if_ending",
  "$@11", "message", "random_corridors", "corridor", "corr_spec",
  "room_begin", "subroom_def", "$@12", "room_def", "$@13", "roomfill",
  "room_pos", "subroom_pos", "room_align", "room_size", "door_detail",
  "secret", "door_wall", "dir_list", "door_pos", "door_infos", "door_info",
  "map_definition", "h_justif", "v_justif", "monster_detail", "$@14",
  "monster_desc", "monster_infos", "monster_info", "seen_trap_mask",
  "object_detail", "$@15", "object_desc", "object_infos", "object_info",
  "trap_detail", "drawbridge_detail", "mazewalk_detail", "wallify_detail",
  "ladder_detail", "stair_detail", "stair_region", "portal_region",
  "teleprt_region", "branch_region", "teleprt_detail", "fountain_detail",
  "throne_detail", "modron_portal_detail", "lever_detail", "lever_infos",
  "lever_info", "valid_subtype", "sink_detail", "pool_detail",
  "terrain_type", "replace_terrain_detail", "terrain_detail",
  "diggable_detail", "passwall_detail", "naming_detail",
  "special_region_detail", "special_levregion_detail", "region_detail",
  "@16", "region_detail_end", "altar_detail", "anvil_detail",
  "floor_detail", "subtype_detail", "npc_detail", "grave_detail",
  "brazier_detail", "signpost_detail", "gold_detail", "engraving_detail",
  "mineralize", "trap_name", "room_type", "optroomregionflags",
  "roomregionflags", "roomregionflag", "optfloormaintype", "floormaintype",
  "optfloortype", "floortype", "optmontype", "door_state", "light_state",
  "alignment", "alignment_prfx", "altar_type", "a_register",
  "string_or_var", "integer_or_var", "coord_or_var", "encodecoord",
  "humidity_flags", "region_or_var", "encoderegion", "mapchar_or_var",
  "mapchar", "monster_or_var", "encodemonster", "object_or_var",
  "encodeobj", "string_expr", "math_expr_var", "func_param_type",
  "func_param_part", "func_param_list", "func_params_list",
  "func_call_param_part", "func_call_param_list", "func_call_params_list",
  "ter_selection_x", "ter_selection", "dice", "tileset_number",
  "all_integers", "all_ints_push", "objectid", "monsterid", "terrainid",
  "engraving_type", "lev_region", "region", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,   363,   364,
     365,   366,   367,   368,   369,   370,   371,   372,   373,   374,
     375,   376,   377,   378,   379,   380,   381,   382,   383,   384,
     385,   386,   387,   388,   389,   390,   391,   392,   393,   394,
     395,   396,   397,   398,   399,   400,   401,   402,   403,   404,
     405,   406,   407,   408,   409,   410,   411,   412,   413,   414,
     415,   416,   417,   418,   419,   420,   421,   422,   423,   424,
     425,   426,   427,   428,   429,   430,   431,   432,   433,   434,
     435,   436,   437,   438,   439,   440,   441,   442,   443,   444,
     445,   446,   447,    44,    58,    40,    41,    91,    93,   123,
     125,   448,   449,   450,   451,   452,   453,   454,   455,   456,
     457,   458,   459,   460,   461,   462,   463,   464,   465,   466,
     467,   468,   469,   470,   471,   472,   473,   474,   475,   476,
     477,   478,   479,   480,   481,   482,   483,   484,   485,   486,
     487,   488,   489,   490,   491,   492,   493,    43,    45,    42,
      47,    37,    61,    46,   124,    38
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   256,   257,   257,   258,   258,   259,   260,   260,   261,
     261,   261,   261,   262,   263,   264,   264,   265,   265,   266,
     266,   267,   267,   268,   268,   269,   269,   270,   270,   271,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   272,   272,
     272,   272,   272,   272,   272,   272,   272,   272,   273,   273,
     273,   273,   273,   273,   273,   273,   273,   274,   274,   274,
     274,   274,   274,   274,   274,   274,   275,   275,   275,   276,
     276,   277,   278,   278,   278,   278,   278,   278,   278,   278,
     278,   278,   278,   278,   278,   278,   278,   279,   279,   280,
     280,   281,   281,   282,   282,   283,   283,   284,   284,   285,
     285,   287,   288,   286,   289,   290,   291,   291,   292,   292,
     292,   294,   295,   293,   296,   296,   298,   297,   299,   297,
     300,   301,   301,   302,   304,   303,   306,   305,   308,   307,
     310,   309,   311,   312,   311,   313,   314,   314,   314,   315,
     315,   316,   317,   319,   318,   321,   320,   322,   322,   323,
     323,   324,   324,   325,   325,   326,   326,   327,   327,   328,
     328,   329,   329,   330,   330,   331,   331,   332,   332,   333,
     333,   333,   333,   333,   333,   333,   334,   334,   334,   335,
     335,   336,   336,   337,   338,   337,   339,   340,   340,   341,
     341,   341,   341,   341,   341,   341,   341,   341,   341,   341,
     341,   341,   341,   341,   341,   341,   342,   342,   342,   343,
     344,   343,   345,   346,   346,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   347,   347,   347,   347,   347,   347,   347,   347,
     347,   347,   348,   349,   350,   350,   351,   351,   351,   352,
     353,   354,   355,   356,   357,   358,   358,   359,   360,   361,
     361,   362,   363,   363,   364,   364,   364,   364,   364,   364,
     364,   364,   364,   364,   364,   364,   364,   365,   365,   365,
     365,   366,   367,   368,   368,   369,   370,   371,   372,   373,
     373,   374,   375,   377,   376,   378,   378,   379,   379,   380,
     380,   381,   382,   383,   383,   384,   384,   384,   385,   385,
     386,   386,   386,   387,   388,   389,   389,   390,   390,   391,
     391,   392,   392,   393,   393,   394,   394,   394,   395,   395,
     396,   397,   397,   398,   399,   399,   400,   400,   401,   401,
     402,   402,   402,   403,   403,   403,   404,   404,   405,   406,
     406,   406,   407,   408,   408,   408,   408,   409,   409,   409,
     410,   410,   411,   411,   411,   412,   413,   413,   413,   414,
     414,   415,   415,   415,   416,   416,   416,   416,   417,   417,
     417,   418,   418,   418,   418,   418,   419,   419,   420,   420,
     420,   420,   420,   420,   420,   420,   420,   420,   420,   421,
     421,   422,   423,   423,   424,   424,   425,   425,   426,   426,
     427,   427,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   428,   428,   428,   428,   428,   428,   428,   428,   428,
     428,   429,   429,   430,   431,   431,   432,   432,   432,   433,
     433,   433,   433,   434,   434,   435,   435,   436,   436,   437,
     437,   438,   438,   439
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     1,     1,     2,     3,     3,     5,     5,
       5,     3,    16,     3,     3,     0,     2,     0,     2,     0,
       2,     1,     1,     0,     3,     3,     1,     0,     2,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     3,     3,     5,     3,     5,     5,     5,     3,     3,
       5,     5,     5,     7,     7,     7,     5,     1,     3,     1,
       3,     1,     3,     1,     3,     1,     3,     1,     3,     1,
       3,     0,     0,     8,     4,     1,     0,     1,     1,     5,
       3,     0,     0,     9,     0,     2,     0,     5,     0,     4,
       1,     2,     1,     6,     0,     3,     0,     6,     0,     4,
       0,     4,     1,     0,     4,     3,     1,     3,     3,     5,
       5,     7,     4,     0,    13,     0,    15,     0,     2,     5,
       1,     5,     1,     5,     1,     5,     1,    10,     6,     1,
       1,     1,     1,     1,     3,     1,     1,     0,     3,     3,
       3,     3,     1,     1,     1,     1,     1,     7,     5,     1,
       1,     1,     1,     3,     0,     5,     4,     0,     3,     1,
       1,     1,     1,     2,     1,     1,     1,     1,     1,     3,
       3,     3,     1,     1,     3,     1,     1,     1,     3,     3,
       0,     5,     2,     0,     3,     1,     3,     1,     3,     3,
       1,     1,     3,     1,     1,     1,     3,     1,     1,     1,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     1,
       1,     1,     5,     7,     5,     8,     1,     3,     3,     5,
       5,     7,     7,     6,     5,     0,     2,     5,     3,    11,
      13,     6,     0,     3,     1,     3,     3,     3,     3,     1,
       1,     3,     3,     3,     3,     3,     3,     1,     1,     1,
       1,     3,     3,     1,     5,     9,     5,     3,     3,     5,
       9,     5,     5,     0,    13,     0,     1,     7,    11,     3,
       7,     7,     5,     5,     9,     5,     5,     3,     7,     3,
       7,     7,     3,     5,     7,     9,     1,     1,     1,     1,
       1,     0,     2,     1,     3,     1,     1,     1,     0,     3,
       1,     0,     3,     1,     0,     3,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     1,     1,     4,     1,
       1,     4,     1,     1,     4,     1,     4,     5,     1,     3,
       1,     3,     1,     1,     4,     9,     1,     1,     4,     1,
       5,     1,     1,     4,     1,     1,     5,     1,     1,     1,
       4,     1,     1,     5,     1,     1,     1,     3,     1,     1,
       3,     1,     4,     3,     3,     3,     3,     3,     3,     1,
       1,     3,     1,     3,     0,     1,     1,     1,     1,     3,
       0,     1,     1,     2,     2,     4,     6,     4,     6,     6,
       6,     6,     2,     6,     8,     8,    10,    14,     2,     1,
       3,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,    10,     9
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     0,     3,     4,    23,     0,     0,     1,
       5,     0,    27,     0,     7,     0,   148,     0,     0,     0,
       0,   216,     0,     0,     0,     0,     0,     0,     0,     0,
     286,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   356,     0,     0,     0,
       0,     0,     0,     0,     0,   176,     0,     0,     0,     0,
       0,     0,     0,     0,   145,     0,     0,     0,   151,   160,
       0,     0,     0,     0,     0,     0,   108,    97,    88,    98,
      89,    99,    90,   100,    91,   101,    92,   102,    93,   103,
      94,   104,    95,   105,    96,    31,    32,    33,     6,    27,
     106,   107,     0,    45,    44,    62,    63,    60,     0,    55,
      61,   164,    56,    57,    59,    58,    30,    73,    43,    79,
      78,    47,    66,    68,    69,    86,    48,    67,    87,    64,
      83,    84,    72,    85,    42,    51,    52,    53,    65,    80,
      71,    82,    81,    46,    70,    74,    75,    76,    77,    36,
      37,    35,    34,    38,    39,    40,    41,    54,    49,    50,
       0,    26,    24,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   170,     0,     0,     0,
       0,   109,   110,     0,     0,     0,     0,     0,     0,   428,
       0,   431,     0,   473,     0,   429,   450,    28,     0,   168,
       0,     8,     0,   389,   390,     0,   426,   175,     0,     0,
       0,    11,   475,   474,    13,   398,     0,   219,   220,     0,
       0,   395,     0,     0,   187,   393,    14,   422,   424,   425,
       0,   421,   419,     0,   249,   253,   418,   250,   415,   417,
       0,   414,   412,     0,   223,     0,   411,   358,   357,     0,
     376,   377,     0,     0,     0,   288,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   469,   452,
     471,   287,     0,   403,     0,     0,   402,     0,     0,     0,
       0,   491,     0,     0,   339,     0,     0,     0,     0,     0,
     327,   328,   360,   359,     0,   146,     0,     0,     0,     0,
     392,     0,     0,     0,     0,     0,   298,     0,   322,   321,
     478,   476,   477,   178,   177,     0,     0,     0,     0,   199,
     200,     0,     0,     0,     0,   111,     0,     0,     0,   347,
     349,   352,   141,     0,     0,     0,     0,   150,     0,     0,
       0,     0,     0,   447,   446,   448,   451,     0,   484,   486,
     483,   485,   487,   488,     0,     0,     0,   118,   119,   114,
     112,     0,     0,     0,     0,    27,   165,    25,     0,     0,
       0,     0,     0,   400,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   252,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   453,   454,     0,     0,     0,   462,     0,
       0,     0,   468,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   147,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
     171,     0,     0,   166,     0,     0,     0,     0,     0,   444,
     430,   438,     0,     0,   433,   434,   435,   436,   437,     0,
     144,     0,   428,     0,     0,     0,     0,   135,   133,   139,
     137,     0,     0,     0,   169,     0,     0,   427,    10,   323,
       0,     9,     0,     0,   399,     0,     0,     0,   222,   221,
     187,   188,   218,     0,     0,     0,   251,     0,     0,   225,
     227,   282,   207,     0,   284,     0,     0,   203,     0,     0,
       0,     0,   409,     0,     0,   407,     0,     0,   406,     0,
       0,   470,   472,     0,     0,   378,   379,     0,   331,     0,
       0,   332,   329,   382,     0,   380,     0,   381,     0,   343,
     289,     0,   290,     0,   190,     0,     0,     0,     0,   295,
     294,     0,     0,   179,   180,   353,   489,   490,     0,   297,
       0,     0,   302,     0,   192,     0,     0,   342,     0,     0,
       0,   326,     0,     0,   162,     0,     0,   152,   346,   345,
       0,     0,     0,   442,   445,     0,   432,   149,   449,   113,
       0,     0,   122,     0,   121,     0,   120,     0,   126,     0,
     117,     0,   116,     0,   115,    29,   391,     0,     0,   401,
     394,     0,   396,     0,     0,   420,   481,   479,   480,   264,
     261,   255,     0,   281,     0,     0,     0,   280,     0,     0,
       0,     0,     0,     0,     0,   260,     0,   265,     0,   267,
     268,   279,     0,   263,   254,   269,   482,   257,     0,   413,
     226,   198,     0,     0,   455,     0,     0,     0,   457,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   404,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   182,     0,     0,   293,     0,     0,     0,     0,     0,
     301,     0,     0,     0,     0,     0,     0,   167,   161,   163,
       0,     0,     0,     0,     0,   142,     0,   134,   136,   138,
     140,     0,   127,     0,   129,     0,   131,     0,     0,   397,
     217,   423,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   416,     0,     0,   283,
      19,     0,   204,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   361,     0,     0,     0,     0,   387,   386,
     337,   340,     0,   291,     0,   194,     0,     0,   292,   296,
       0,     0,   354,     0,     0,     0,   341,     0,   196,     0,
     361,   202,     0,   201,   174,     0,   154,   348,   351,   350,
     439,   440,   441,   443,     0,     0,   125,     0,   124,     0,
     123,     0,     0,   278,   271,   270,   274,   272,   273,   275,
     276,   277,   258,   259,   262,   266,   256,     0,   383,   230,
     231,     0,   235,   234,   245,   236,   237,   238,     0,     0,
       0,   242,   243,     0,   228,   232,   384,   229,     0,   213,
     214,     0,   215,     0,   212,   208,     0,   285,   456,   458,
       0,   463,     0,   459,     0,   408,   461,   460,     0,     0,
       0,   368,     0,     0,     0,   388,     0,     0,     0,     0,
       0,     0,   205,   206,     0,     0,     0,   304,     0,     0,
       0,     0,     0,     0,     0,   309,   310,     0,     0,     0,
     303,     0,     0,   368,     0,     0,     0,     0,     0,   154,
     143,   128,   130,   132,   324,     0,     0,   233,     0,     0,
       0,     0,     0,     0,     0,    20,     0,     0,   410,     0,
       0,   365,   366,   367,   362,   363,     0,   371,     0,     0,
     330,     0,   344,   189,     0,   361,   355,   181,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     191,     0,   371,   207,   325,     0,   158,   153,   155,     0,
     385,   239,   240,   241,   247,   246,   244,   210,   211,   209,
     464,     0,   465,   434,     0,     0,     0,     0,   374,     0,
       0,     0,     0,   368,     0,     0,   373,   314,   316,   317,
     318,   320,   319,   313,   305,   306,   307,   308,   311,   312,
     315,     0,   374,   197,   156,    27,     0,     0,     0,     0,
       0,   405,   364,   370,   369,     0,     0,   333,     0,   493,
     338,   193,   371,     0,   299,   195,   183,    27,   159,     0,
     248,   466,    16,     0,   372,     0,   335,   492,   374,     0,
       0,   157,     0,     0,   375,   336,   334,   185,   300,   184,
       0,    17,     0,    21,    22,    19,     0,     0,   186,    12,
      18,   467
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     3,     4,     5,     6,    95,    96,    97,  1040,  1087,
     877,  1085,    12,   162,    98,   396,    99,   100,   101,   102,
     213,   103,   104,   741,   743,   745,   493,   494,   495,   496,
     105,   479,   824,   106,   107,   453,   108,   109,   214,   730,
     928,   929,  1057,  1035,   110,   606,   111,   112,   230,   113,
     603,   114,   394,   115,   352,   470,   599,   116,   117,   118,
     332,   324,   119,  1070,   120,  1082,   410,   576,   596,   797,
     810,   121,   351,   812,   538,   904,   681,   875,   122,   253,
     520,   123,   417,   274,   680,   864,   996,   124,   414,   264,
     413,   674,   125,   126,   127,   128,   129,   130,   131,   132,
     133,   134,   714,   135,   136,   137,   138,   720,   920,  1023,
     139,   140,   511,   141,   142,   143,   144,   145,   146,   147,
     148,  1066,  1076,   149,   150,   151,   152,   153,   154,   155,
     156,   157,   158,   159,   279,   325,   891,   954,   955,   957,
    1044,  1008,  1017,  1047,   282,   557,   566,   865,   790,   567,
     236,   329,   299,   255,   404,   305,   306,   547,   548,   275,
     276,   265,   266,   373,   330,   822,   613,   614,   615,   375,
     376,   377,   300,   434,   225,   244,   344,   677,   391,   392,
     393,   588,   310,   311
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -960
static const yytype_int16 yypact[] =
{
     135,  -124,  -110,    93,  -960,   135,   -11,   -93,   -89,  -960,
    -960,   -78,   803,   -71,  -960,    47,  -960,   -21,     0,    38,
      48,  -960,    65,    74,   105,   122,   131,   138,   144,   159,
     179,   182,   216,   222,   228,   229,   234,   259,   270,   276,
     279,   281,   286,   288,   289,   291,   292,   296,   301,   313,
     315,   316,   317,   327,   328,   333,   336,   337,   338,   340,
     358,     8,   361,   364,  -960,   368,   -32,   662,  -960,  -960,
     384,   386,   387,    90,    24,   -12,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,   803,
    -960,  -960,   -45,  -960,  -960,  -960,  -960,  -960,   389,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
     227,   141,  -960,  -112,   564,    63,   277,   376,   238,   238,
     118,   -17,    13,   210,   210,   854,  -120,  -120,    -9,   211,
     210,   210,   413,   210,   297,  -120,  -120,   -16,    -9,    -9,
      -9,    24,   390,    24,   210,   879,   879,   210,   879,   879,
      87,   210,   879,   -16,   879,    57,  -960,   879,  -120,   583,
      24,  -960,  -960,   332,   395,   210,   210,   210,   391,  -960,
      99,  -960,   403,  -960,   193,  -960,   151,  -960,   307,  -960,
     415,  -960,    47,  -960,  -960,   416,  -960,   362,   423,   426,
     427,  -960,  -960,  -960,  -960,  -960,   432,  -960,  -960,   433,
     625,  -960,   436,   441,   444,  -960,  -960,  -960,  -960,  -960,
     632,  -960,  -960,   447,  -960,  -960,  -960,  -960,  -960,  -960,
     635,  -960,  -960,   457,   461,   466,  -960,  -960,  -960,   473,
    -960,  -960,   484,   487,   493,  -960,  -120,  -120,   210,   210,
     492,   210,   494,   499,   501,   879,   502,   575,  -960,  -960,
     435,  -960,   695,  -960,   503,   511,  -960,   512,   517,   702,
     521,  -960,   522,   524,   526,   528,   542,   732,   544,   545,
    -960,  -960,  -960,  -960,   578,   751,   579,   580,   581,   582,
     294,   772,   585,   209,   586,   587,  -960,   588,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,   589,   590,   591,   592,  -960,
    -960,   593,   415,   594,   597,  -960,   595,    24,    24,   602,
     604,   606,  -960,   607,   249,    24,    24,  -960,    24,    24,
      24,    24,    24,   362,   294,  -960,   612,   611,  -960,  -960,
    -960,  -960,  -960,  -960,   617,   132,   111,  -960,  -960,   362,
     294,   619,   621,   622,   803,   803,  -960,  -960,    24,  -112,
     815,    30,   816,   638,   634,   879,   640,    24,   197,   834,
     639,   660,    24,   664,   415,   672,    24,   415,   210,   210,
     879,   791,   794,  -960,  -960,   680,   682,   766,  -960,   210,
     210,   410,  -960,   689,   687,   879,   692,    24,    40,   851,
     885,   697,   855,   856,   324,   733,   210,   808,   703,   810,
      -9,   -42,  -960,   705,    -9,    -9,    -9,    24,   706,    79,
     210,    20,   811,    32,   738,   807,   -29,   899,    13,   782,
    -960,    51,    51,  -960,   139,   707,   -22,   778,   780,   896,
    -960,  -960,   414,   420,   169,   169,  -960,  -960,  -960,   151,
    -960,   879,   714,   -65,   -30,     3,    15,  -960,  -960,   362,
     294,   230,    27,    62,  -960,   710,   425,  -960,  -960,  -960,
     908,  -960,   719,   432,  -960,   717,   911,   434,  -960,  -960,
     444,  -960,  -960,   715,   460,    68,  -960,   716,   495,  -960,
    -960,  -960,  -960,   725,   726,   210,   210,   668,   734,   729,
     736,   737,  -960,   742,   462,  -960,   744,   746,  -960,   755,
     767,  -960,  -960,   955,   500,  -960,  -960,   769,  -960,   770,
     960,  -960,   773,  -960,   768,  -960,   774,  -960,   775,   777,
    -960,   964,  -960,   784,  -960,   967,   785,    40,   786,   787,
    -960,   788,   909,  -960,  -960,  -960,  -960,  -960,   793,  -960,
     795,   781,  -960,   796,  -960,   980,   797,  -960,   798,   865,
     990,  -960,   801,   415,  -960,   743,    24,  -960,  -960,   362,
     802,   804,   805,  -960,   809,   812,  -960,  -960,  -960,  -960,
     994,   806,  -960,     2,  -960,    24,  -960,  -112,  -960,    28,
    -960,    36,  -960,    56,  -960,  -960,  -960,   817,  1000,  -960,
    -960,   813,  -960,   842,   840,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,   852,  -960,   853,   857,   858,  -960,   859,   860,
     861,   867,   875,   878,   881,  -960,   882,  -960,   883,  -960,
    -960,  -960,   884,  -960,  -960,  -960,  -960,  -960,   849,  -960,
     818,   880,    13,   999,  -960,   886,   929,   879,  -960,    24,
      24,   879,   888,    24,   879,   879,   887,   890,  -960,   -16,
    1044,   891,   926,  1046,   140,   118,   927,   -63,  1002,   895,
       4,  -960,   889,  1004,  -960,    24,   898,  -112,  1029,   210,
     900,  1005,   901,     9,   290,   415,    51,  -960,  -960,   294,
     902,    40,   -20,   175,   896,  -960,   112,  -960,  -960,   294,
     362,    67,  -960,   156,  -960,   172,  -960,    40,   905,  -960,
    -960,  -960,   238,  1001,  1006,    24,   998,  1019,    24,    24,
      24,  -112,    24,    24,    24,   118,  -960,   576,   306,  -960,
     932,    24,  -960,   930,   187,   322,   931,    40,   518,   933,
     934,    24,  1100,   935,   938,  1128,   939,   936,  -960,  -960,
     942,  -960,   943,  -960,  1132,  -960,   318,   945,  -960,  -960,
     946,    52,   362,   947,   948,   442,  -960,  1138,  -960,  1139,
     935,  -960,   951,  -960,  -960,   952,    78,  -960,  -960,   362,
    -960,  -960,  -960,  -960,   415,    28,  -960,    36,  -960,    56,
    -960,   950,  1142,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,   362,  -960,  -960,  -960,  -960,   153,  -960,  -960,
    -960,  -112,  -960,  -960,  -960,  -960,  -960,  -960,   954,   956,
     957,  -960,  -960,   958,  -960,  -960,  -960,   362,   959,  -960,
    -960,   961,  -960,   962,  -960,  -960,  1146,  -960,   294,  -960,
    1115,  -960,    24,  -960,   963,  -960,  -960,  -960,   299,   965,
     464,  1061,  1156,   968,   118,  -960,  1003,   118,   969,   970,
       9,    24,  -960,  -960,   971,  1102,  1077,  -960,   974,   975,
     976,   977,   978,   979,   981,  -960,  -960,   982,   983,   984,
    -960,   985,   986,  1061,    52,  1167,   123,   988,   987,    78,
    -960,  -960,  -960,  -960,  -960,   991,  1103,   362,    24,    24,
      24,   -87,   238,  1179,  1058,  -960,   992,   200,  -960,    24,
    1182,  -960,  -960,  -960,  -960,   996,   997,  1097,  1007,  1188,
    -960,  1008,  -960,  -960,   197,   935,  -960,  -960,  1010,  1011,
    1101,  1190,    60,   118,   238,    30,    30,   210,   -17,  1191,
    -960,  1192,  1097,  -960,  -960,  1012,  -960,  -960,  -960,  1193,
    -960,  -960,  -960,  -960,  -960,   953,  -960,  -960,  -960,  -960,
    -960,  1158,  -960,   218,  1009,   464,  1104,  1014,  1042,  1205,
    1015,   118,  1016,  1061,  1123,  1127,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  1018,  1042,   880,  -960,   803,  1022,   -87,  1020,  1026,
    1023,  -960,  -960,  -960,  -960,  1101,  1024,  -960,  1025,  -960,
    -960,  -960,  1097,  1027,  -960,  -960,  -960,   803,  -960,    40,
    -960,  -960,  -960,  1030,  -960,   118,   415,  -960,  1042,  1136,
     415,  -960,  1031,   210,  -960,  -960,  -960,  -960,  -960,  -960,
      80,  1032,   415,  -960,  -960,   932,   210,  1033,  -960,  -960,
    -960,  -960
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -960,  -960,  1221,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
     142,  -960,  -960,  1013,   -99,  -348,   836,  1028,  1161,  -456,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  1170,  -960,  -960,  -960,
     303,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
     776,  1035,  -960,  -960,  -960,  -960,   713,  -960,  -960,  -960,
     334,  -960,  -960,  -960,  -618,   312,   256,  -960,  -960,   445,
     278,  -960,  -960,  -960,  -960,  -960,   203,  -960,  -960,  1074,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -569,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,  -960,
    -960,  -960,  -960,  -960,   266,   547,  -783,   242,  -960,  -865,
    -960,  -908,   204,  -959,  -434,  -575,  -960,  -960,  -960,   481,
     862,  -199,  -165,  -379,   739,   -66,  -376,  -450,  -591,  -499,
    -588,  -496,  -582,  -150,   -68,  -960,   516,  -960,  -960,   762,
    -960,  -960,   972,  -158,   728,  -960,  -447,  -960,  -960,  -960,
    -960,  -960,  -164,  -960
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -225
static const yytype_int16 yytable[] =
{
     227,   254,   711,   632,   469,   630,   224,   497,   283,   284,
     498,   356,   584,   237,    16,   313,   314,   301,   316,   318,
     319,   601,   602,   612,   326,   327,   328,   923,   219,   334,
     268,   257,   337,   509,   598,   574,   345,   335,   336,   268,
     338,   339,   746,   744,   346,   308,   348,   742,   594,   353,
     359,   360,   361,   634,   542,   608,   902,   818,   982,   542,
     277,   322,   349,   387,  1019,   542,   526,   242,   772,   529,
       7,   994,   646,  1056,  1032,   302,   647,   648,   389,   245,
     246,   795,   280,   340,     8,  1083,   808,   341,   342,   233,
     281,   340,   586,     9,   590,   341,   342,   587,   303,   304,
     234,   235,    11,   219,   269,   258,   813,   363,    13,  1077,
     555,   307,    14,   269,   995,   219,    15,   556,   259,   320,
     321,   268,   160,   425,   426,   333,   428,   340,   621,   903,
     785,   341,   342,   749,   350,   622,   492,   649,   650,   651,
     363,   652,   354,   653,  1068,   245,   246,  1020,  1052,  1021,
       1,     2,   364,   575,   243,   219,   817,  1084,   374,   475,
     390,   161,   388,   623,   343,   210,   595,   654,   655,   656,
     624,   657,   831,   163,   658,   659,   660,   661,   662,   233,
     663,   233,  1013,   226,   278,   323,   309,  1022,   245,   246,
     234,   235,   234,   235,   164,   269,   625,   250,   591,   796,
     664,   665,   884,   626,   809,    74,   791,   228,   627,   666,
     667,   668,   669,   670,   671,   628,   926,   788,   927,   220,
     423,   424,   270,   260,   789,   510,   631,   672,   271,   261,
     231,   270,   165,   257,   221,   222,   499,   271,   933,   932,
     673,   257,   166,   931,   738,   737,   600,   515,   769,   272,
     273,   600,   249,   530,   531,   727,   833,   600,   581,   167,
     825,   633,   532,   250,   540,   541,   846,   826,   168,   539,
     223,   545,   546,   549,   331,   604,   815,   552,   612,   518,
     519,   569,   545,   546,   251,   252,   573,   245,   246,   474,
     578,   579,   580,   218,   220,   585,   505,   482,   483,   169,
     484,   485,   486,   487,   488,   782,   385,   258,   749,   221,
     222,   219,   233,   270,   223,   258,   170,   364,   500,   271,
     259,   221,   222,   234,   235,   171,   609,   220,   259,   378,
     506,   379,   172,   619,   232,   380,   381,   382,   173,   517,
     272,   273,   221,   222,   524,   223,   220,   936,   528,   827,
     703,   308,   233,   174,   245,   246,   828,   223,   247,   248,
     675,   221,   222,   234,   235,   829,   537,   811,   366,   554,
     684,   685,   830,   175,   245,   246,   176,   814,   223,   868,
     880,   820,   821,   881,   245,   246,   368,   369,   370,   371,
     372,   367,   605,  1001,   249,   960,  1002,   223,   962,   247,
     248,   563,   460,   564,   565,   250,  1026,  1027,   869,   870,
     177,  1039,   312,   542,   -15,   871,   178,   543,   370,   371,
     372,   374,   179,   180,   872,   260,   251,   252,   181,   629,
     383,   261,   873,   260,   368,   369,   370,   371,   372,   261,
     368,   369,   370,   371,   372,   481,   997,   368,   369,   370,
     371,   372,   874,   182,   262,   263,   368,   369,   370,   371,
     372,   249,   262,   263,   183,   692,   406,   370,   371,   372,
     184,   256,   250,   185,  1024,   186,   930,   740,  1025,   985,
     187,   249,   188,   189,  1072,   190,   191,   245,   246,   384,
     192,   249,   317,   251,   252,   193,   368,   369,   370,   371,
     372,   315,   385,   951,   952,   953,   386,   194,   233,   195,
     196,   197,  1050,   251,   252,   882,   800,   221,   222,   234,
     235,   198,   199,   251,   252,   303,   304,   200,   907,   773,
     201,   202,   203,   776,   204,   908,   779,   780,   729,   245,
     246,   368,   369,   370,   371,   372,   368,   949,   370,   371,
     372,   909,   205,   223,   804,   207,   836,   739,   208,   839,
     840,   841,   209,   843,   844,   845,  1074,   802,   910,   368,
     369,   370,   371,   372,   238,   239,   240,   241,   215,   406,
     216,   217,   819,   229,   357,   331,   362,   286,   287,   288,
     289,   290,   358,   291,   249,   292,   293,   294,   295,   296,
     365,   911,   912,   913,   914,   544,   915,   916,   917,   918,
     919,   842,   616,   398,   395,   399,   400,   867,   617,   401,
     402,   774,   775,   636,   403,   778,   251,   252,   405,   406,
     545,   546,   642,   407,   408,   411,   298,   409,   415,   286,
     287,   288,   289,   290,   412,   291,   249,   292,   293,   294,
     295,   296,   245,   246,   416,   847,   848,   297,   645,   418,
    -224,   368,   369,   370,   371,   372,   419,   368,   369,   370,
     371,   372,   368,   369,   370,   371,   372,   420,   251,   252,
     421,   368,   369,   370,   371,   372,   422,   427,   298,   429,
     435,   849,   850,   679,   430,   851,   431,   433,   698,   436,
     437,   937,   966,   878,   438,   439,   441,   368,   369,   370,
     371,   372,   440,   888,   442,   443,   885,   444,  1075,   445,
     852,   446,  1079,   853,   854,   855,   856,   857,   858,   859,
     860,   861,   862,   863,  1088,   447,   448,   449,   450,   991,
     992,   993,   368,   369,   370,   371,   372,   368,   369,   370,
     371,   372,   286,   287,   288,   289,   290,   452,   291,   249,
     292,   293,   294,   295,   296,   368,   369,   370,   371,   372,
     297,   451,   454,   455,   456,   457,   458,   233,   459,   461,
     462,   463,   464,   465,   466,   467,   468,   471,   234,   235,
     472,   251,   252,   473,    78,   476,    80,   477,    82,   478,
      84,   298,    86,   480,    88,   489,    90,   490,    92,    16,
      94,   491,  1028,   501,   947,   502,   503,    17,   508,   512,
      18,    19,    20,    21,    22,    23,    24,    25,    26,    27,
      28,   513,   514,   516,    29,    30,    31,    32,    33,   521,
      34,   522,   537,   245,   246,    35,    36,    37,    38,    39,
      40,    41,    42,   523,    43,    44,    45,   525,    46,    47,
      48,    49,    50,    51,    52,   527,   211,   533,    53,    54,
     534,    55,    77,   535,    79,   536,    81,    56,    83,   550,
      85,  1003,    87,   551,    89,   553,    91,   558,    93,   559,
     560,   561,   568,   570,   562,   572,   571,    57,   577,   582,
     589,   592,   593,   597,  -173,   607,   610,   620,  1081,   611,
     635,   637,   638,   640,    58,   641,   644,   678,   682,   683,
      59,  1090,   686,    60,    61,   688,    62,   687,    63,   689,
     690,   245,   246,    64,    65,   691,  1058,    66,    67,   694,
      68,   693,    69,   286,   287,   288,   289,   290,   695,   291,
     249,   292,   293,   294,   295,   296,   245,   246,  1071,   697,
     696,   297,   699,   700,   701,   703,   702,   704,   707,   705,
     706,   709,    70,    71,    72,   719,    73,   708,   710,   712,
     713,   715,   251,   252,   722,   716,   717,   725,   718,   721,
     723,   724,   298,   692,   726,   731,   728,   732,   736,   733,
      74,   302,   734,   748,   770,   537,    75,    76,   735,   749,
     747,   767,   285,    77,    78,    79,    80,    81,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,    92,    93,
      94,   286,   287,   288,   289,   290,   751,   291,   249,   292,
     293,   294,   295,   296,   750,   766,   752,   753,   784,   297,
     787,   754,   755,   756,   757,   758,   286,   287,   288,   289,
     290,   759,   291,   249,   292,   293,   294,   295,   296,   760,
     251,   252,   761,   768,   297,   762,   763,   764,   765,   771,
     298,   777,   781,   782,   785,   786,   792,   793,   794,   799,
     798,   801,   803,   805,   807,   251,   252,   806,   832,   834,
      76,   816,   837,   835,   889,   298,    77,    78,    79,    80,
      81,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      91,    92,    93,    94,   838,   876,   879,   883,   890,   886,
     887,   892,   893,   894,   895,   896,   898,   897,   900,   901,
     905,   906,   921,   922,   924,   925,   934,   935,   938,   945,
     939,   940,   941,   942,   946,   943,   944,   956,   950,   948,
     958,   959,   961,   964,   969,   963,   968,   967,   970,   971,
     972,   973,   974,   975,   984,   976,   977,   978,   979,   981,
     990,   980,   986,   998,   989,   999,  1004,   987,  1000,  1005,
    1007,  1006,  1010,  1016,  1018,  1030,  1031,  1038,  1036,  1043,
    1009,  1046,  1011,  1014,  1015,  1041,  1034,  1037,  1045,  1048,
    1053,  1049,  1051,  1054,  1055,  1059,  1061,  1062,  1065,  1063,
    1069,  1067,  1078,  1073,  1080,  1086,    10,  1089,   212,  1091,
     504,   206,   988,   643,   965,   583,   983,   355,   347,  1033,
    1060,   899,  1012,   267,  1029,   397,   783,  1042,   866,  1064,
     823,   618,   639,   676,     0,     0,     0,     0,     0,     0,
       0,   507,     0,     0,     0,     0,     0,   432
};

static const yytype_int16 yycheck[] =
{
      99,   166,   577,   502,   352,   501,    74,   386,   173,   174,
     386,   210,   459,   163,     6,   180,   181,   175,   183,   184,
     184,   471,   472,   479,   188,   189,   190,   810,     4,   194,
       3,     3,   197,     3,   468,    77,   201,   195,   196,     3,
     198,   199,   633,   631,   202,    54,   204,   629,    77,   207,
     215,   216,   217,   503,     3,    77,     4,    77,   923,     3,
      77,    77,     5,   228,     4,     3,   414,     4,   686,   417,
     194,   158,     4,  1032,   982,   195,     8,     9,   228,    77,
      78,    77,    69,     4,   194,     5,    77,     8,     9,   201,
      77,     4,    72,     0,    62,     8,     9,    77,   218,   219,
     212,   213,   113,     4,    77,    77,   724,     8,   201,  1068,
      70,   177,   201,    77,   201,     4,   194,    77,    90,   185,
     186,     3,   193,   288,   289,   193,   291,     4,   193,    77,
     193,     8,     9,   196,    77,   200,     4,    69,    70,    71,
       8,    73,   208,    75,  1052,    77,    78,    87,  1013,    89,
      15,    16,   220,   195,    91,     4,   731,    77,   226,   358,
     228,   114,   228,   193,    77,   197,   195,    99,   100,   101,
     200,   103,   747,   194,   106,   107,   108,   109,   110,   201,
     112,   201,   965,   195,   201,   201,   195,   127,    77,    78,
     212,   213,   212,   213,   194,    77,   193,   195,   166,   195,
     132,   133,   777,   200,   195,   197,   705,   252,   193,   141,
     142,   143,   144,   145,   146,   200,   138,    77,   140,   195,
     286,   287,   195,   195,    84,   195,   199,   159,   201,   201,
       3,   195,   194,     3,   210,   211,   386,   201,   829,   827,
     172,     3,   194,   825,   623,   621,   195,   405,   682,   222,
     223,   195,   184,   418,   419,   603,   752,   195,   457,   194,
     193,   199,   420,   195,   429,   430,   765,   200,   194,   427,
     246,   220,   221,   431,   195,   136,   726,   435,   734,    82,
      83,   446,   220,   221,   216,   217,   450,    77,    78,   357,
     454,   455,   456,   203,   195,   460,   395,   365,   366,   194,
     368,   369,   370,   371,   372,   193,   195,    77,   196,   210,
     211,     4,   201,   195,   246,    77,   194,   385,   386,   201,
      90,   210,   211,   212,   213,   194,   476,   195,    90,    22,
     398,    24,   194,   491,   193,    28,    29,    30,   194,   407,
     222,   223,   210,   211,   412,   246,   195,   194,   416,   193,
     197,    54,   201,   194,    77,    78,   200,   246,    81,    82,
     525,   210,   211,   212,   213,   193,    76,    77,   175,   437,
     535,   536,   200,   194,    77,    78,   194,   725,   246,    73,
     193,   206,   207,   196,    77,    78,   247,   248,   249,   250,
     251,   198,   253,   193,   184,   894,   196,   246,   897,    81,
      82,    77,   193,    79,    80,   195,   975,   976,   102,   103,
     194,   193,   201,     3,   196,   109,   194,     7,   249,   250,
     251,   489,   194,   194,   118,   195,   216,   217,   194,   199,
     123,   201,   126,   195,   247,   248,   249,   250,   251,   201,
     247,   248,   249,   250,   251,   196,   942,   247,   248,   249,
     250,   251,   146,   194,   224,   225,   247,   248,   249,   250,
     251,   184,   224,   225,   194,     3,     4,   249,   250,   251,
     194,    95,   195,   194,   973,   194,   824,   627,   974,   926,
     194,   184,   194,   194,  1059,   194,   194,    77,    78,   182,
     194,   184,   195,   216,   217,   194,   247,   248,   249,   250,
     251,    88,   195,    39,    40,    41,   199,   194,   201,   194,
     194,   194,  1011,   216,   217,   193,   715,   210,   211,   212,
     213,   194,   194,   216,   217,   218,   219,   194,    86,   687,
     194,   194,   194,   691,   194,    93,   694,   695,   606,    77,
      78,   247,   248,   249,   250,   251,   247,   248,   249,   250,
     251,   109,   194,   246,   719,   194,   755,   625,   194,   758,
     759,   760,   194,   762,   763,   764,  1065,   717,   126,   247,
     248,   249,   250,   251,    10,    11,    12,    13,   194,     4,
     194,   194,   732,   194,   252,   195,   195,   177,   178,   179,
     180,   181,   197,   183,   184,   185,   186,   187,   188,   189,
     197,   159,   160,   161,   162,   195,   164,   165,   166,   167,
     168,   761,   198,   197,   199,   253,   193,   767,   198,   193,
     193,   689,   690,   198,   192,   693,   216,   217,   195,     4,
     220,   221,   198,   197,   193,     3,   226,   193,     3,   177,
     178,   179,   180,   181,   197,   183,   184,   185,   186,   187,
     188,   189,    77,    78,   197,    79,    80,   195,   198,   193,
     199,   247,   248,   249,   250,   251,   193,   247,   248,   249,
     250,   251,   247,   248,   249,   250,   251,   193,   216,   217,
     193,   247,   248,   249,   250,   251,   193,   195,   226,   195,
     255,   115,   116,   198,   195,   119,   195,   195,   198,     4,
     197,   851,   901,   771,   193,   193,     4,   247,   248,   249,
     250,   251,   195,   781,   193,   193,   198,   193,  1066,   193,
     144,   193,  1070,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,  1082,   193,     4,   193,   193,   938,
     939,   940,   247,   248,   249,   250,   251,   247,   248,   249,
     250,   251,   177,   178,   179,   180,   181,     6,   183,   184,
     185,   186,   187,   188,   189,   247,   248,   249,   250,   251,
     195,   193,   193,   193,   193,   193,     4,   201,   193,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   212,   213,
     193,   216,   217,   198,   211,   193,   213,   193,   215,   193,
     217,   226,   219,   196,   221,   193,   223,   196,   225,     6,
     227,   194,   977,   194,   882,   194,   194,    14,     3,     3,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      27,   193,   198,   193,    31,    32,    33,    34,    35,     5,
      37,   202,    76,    77,    78,    42,    43,    44,    45,    46,
      47,    48,    49,   193,    51,    52,    53,   193,    55,    56,
      57,    58,    59,    60,    61,   193,   204,    76,    65,    66,
      76,    68,   210,   193,   212,   193,   214,    74,   216,   190,
     218,   949,   220,   196,   222,   193,   224,    36,   226,     4,
     193,    36,   159,    85,    38,    85,   193,    94,   193,   193,
      89,   163,    95,     4,   122,   198,   128,   193,  1073,   129,
     200,     3,   193,   196,   111,     4,   201,   201,   193,   193,
     117,  1086,   254,   120,   121,   196,   123,   193,   125,   193,
     193,    77,    78,   130,   131,   193,  1035,   134,   135,   193,
     137,   197,   139,   177,   178,   179,   180,   181,   193,   183,
     184,   185,   186,   187,   188,   189,    77,    78,  1057,     4,
     193,   195,   193,   193,     4,   197,   193,   193,     4,   194,
     193,     4,   169,   170,   171,   194,   173,   193,   193,   193,
     193,   193,   216,   217,     4,    76,   193,   122,   193,   193,
     193,   193,   226,     3,   193,   193,   253,   193,     4,   194,
     197,   195,   193,     3,     5,    76,   203,   204,   196,   196,
     193,   193,   158,   210,   211,   212,   213,   214,   215,   216,
     217,   218,   219,   220,   221,   222,   223,   224,   225,   226,
     227,   177,   178,   179,   180,   181,   196,   183,   184,   185,
     186,   187,   188,   189,   202,   196,   194,   194,     4,   195,
       4,   194,   194,   194,   194,   194,   177,   178,   179,   180,
     181,   194,   183,   184,   185,   186,   187,   188,   189,   194,
     216,   217,   194,   193,   195,   194,   194,   194,   194,   193,
     226,   193,   195,   193,   193,   159,   159,    85,   193,    85,
     201,   193,    63,   193,   193,   216,   217,    92,   193,    98,
     204,   199,   104,    97,     4,   226,   210,   211,   212,   213,
     214,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   226,   227,   105,   193,   196,   196,   193,   196,
     196,   193,     4,   194,   198,   193,     4,   194,   193,   193,
     193,   193,     4,     4,   193,   193,   196,     5,   194,     3,
     194,   194,   194,   194,    39,   194,   194,    96,   193,   196,
       4,   193,   159,   193,    87,   196,    64,   196,   194,   194,
     194,   194,   194,   194,     7,   194,   194,   194,   194,   193,
      77,   196,   194,     4,   193,   127,     4,   200,   196,   193,
      93,   194,     4,    92,     4,     4,     4,    39,     5,    95,
     193,   159,   194,   193,   193,   196,   194,   254,   194,     4,
      87,   196,   196,    86,   196,   193,   196,   191,   194,   196,
     193,   196,    86,   193,   193,   193,     5,  1085,    67,   196,
     394,    61,   929,   520,   900,   459,   924,   209,   203,   983,
    1037,   796,   964,   169,   978,   232,   699,  1005,   767,  1045,
     734,   489,   513,   525,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   399,    -1,    -1,    -1,    -1,    -1,   295
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,    15,    16,   257,   258,   259,   260,   194,   194,     0,
     258,   113,   268,   201,   201,   194,     6,    14,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    27,    31,
      32,    33,    34,    35,    37,    42,    43,    44,    45,    46,
      47,    48,    49,    51,    52,    53,    55,    56,    57,    58,
      59,    60,    61,    65,    66,    68,    74,    94,   111,   117,
     120,   121,   123,   125,   130,   131,   134,   135,   137,   139,
     169,   170,   171,   173,   197,   203,   204,   210,   211,   212,
     213,   214,   215,   216,   217,   218,   219,   220,   221,   222,
     223,   224,   225,   226,   227,   261,   262,   263,   270,   272,
     273,   274,   275,   277,   278,   286,   289,   290,   292,   293,
     300,   302,   303,   305,   307,   309,   313,   314,   315,   318,
     320,   327,   334,   337,   343,   348,   349,   350,   351,   352,
     353,   354,   355,   356,   357,   359,   360,   361,   362,   366,
     367,   369,   370,   371,   372,   373,   374,   375,   376,   379,
     380,   381,   382,   383,   384,   385,   386,   387,   388,   389,
     193,   114,   269,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   292,   194,   194,   194,
     197,   204,   274,   276,   294,   194,   194,   194,   203,     4,
     195,   210,   211,   246,   420,   430,   195,   270,   252,   194,
     304,     3,   193,   201,   212,   213,   406,   419,    10,    11,
      12,    13,     4,    91,   431,    77,    78,    81,    82,   184,
     195,   216,   217,   335,   408,   409,    95,     3,    77,    90,
     195,   201,   224,   225,   345,   417,   418,   345,     3,    77,
     195,   201,   222,   223,   339,   415,   416,    77,   201,   390,
      69,    77,   400,   408,   408,   158,   177,   178,   179,   180,
     181,   183,   185,   186,   187,   188,   189,   195,   226,   408,
     428,   429,   195,   218,   219,   411,   412,   411,    54,   195,
     438,   439,   201,   408,   408,    88,   408,   195,   408,   438,
     411,   411,    77,   201,   317,   391,   438,   438,   438,   407,
     420,   195,   316,   420,   408,   429,   429,   408,   429,   429,
       4,     8,     9,    77,   432,   408,   429,   317,   429,     5,
      77,   328,   310,   429,   411,   273,   407,   252,   197,   408,
     408,   408,   195,     8,   420,   197,   175,   198,   247,   248,
     249,   250,   251,   419,   420,   425,   426,   427,    22,    24,
      28,    29,    30,   123,   182,   195,   199,   408,   411,   419,
     420,   434,   435,   436,   308,   199,   271,   269,   197,   253,
     193,   193,   193,   192,   410,   195,     4,   197,   193,   193,
     322,     3,   197,   346,   344,     3,   197,   338,   193,   193,
     193,   193,   193,   411,   411,   408,   408,   195,   408,   195,
     195,   195,   428,   195,   429,   255,     4,   197,   193,   193,
     195,     4,   193,   193,   193,   193,   193,   193,     4,   193,
     193,   193,     6,   291,   193,   193,   193,   193,     4,   193,
     193,   193,   193,   193,   193,   193,   193,   193,   193,   271,
     311,   193,   193,   198,   420,   407,   193,   193,   193,   287,
     196,   196,   420,   420,   420,   420,   420,   420,   420,   193,
     196,   194,     4,   282,   283,   284,   285,   409,   412,   419,
     420,   194,   194,   194,   272,   270,   420,   406,     3,     3,
     195,   368,     3,   193,   198,   429,   193,   420,    82,    83,
     336,     5,   202,   193,   420,   193,   271,   193,   420,   271,
     408,   408,   429,    76,    76,   193,   193,    76,   330,   429,
     408,   408,     3,     7,   195,   220,   221,   413,   414,   429,
     190,   196,   429,   193,   420,    70,    77,   401,    36,     4,
     193,    36,    38,    77,    79,    80,   402,   405,   159,   408,
      85,   193,    85,   438,    77,   195,   323,   193,   438,   438,
     438,   407,   193,   316,   432,   408,    72,    77,   437,    89,
      62,   166,   163,    95,    77,   195,   324,     4,   400,   312,
     195,   413,   413,   306,   136,   253,   301,   198,    77,   419,
     128,   129,   275,   422,   423,   424,   198,   198,   425,   429,
     193,   193,   200,   193,   200,   193,   200,   193,   200,   199,
     417,   199,   415,   199,   413,   200,   198,     3,   193,   410,
     196,     4,   198,   322,   201,   198,     4,     8,     9,    69,
      70,    71,    73,    75,    99,   100,   101,   103,   106,   107,
     108,   109,   110,   112,   132,   133,   141,   142,   143,   144,
     145,   146,   159,   172,   347,   408,   430,   433,   201,   198,
     340,   332,   193,   193,   408,   408,   254,   193,   196,   193,
     193,   193,     3,   197,   193,   193,   193,     4,   198,   193,
     193,     4,   193,   197,   193,   194,   193,     4,   193,     4,
     193,   401,   193,   193,   358,   193,    76,   193,   193,   194,
     363,   193,     4,   193,   193,   122,   193,   271,   253,   420,
     295,   193,   193,   194,   193,   196,     4,   412,   409,   420,
     419,   279,   418,   280,   416,   281,   414,   193,     3,   196,
     202,   196,   194,   194,   194,   194,   194,   194,   194,   194,
     194,   194,   194,   194,   194,   194,   196,   193,   193,   400,
       5,   193,   330,   429,   420,   420,   429,   193,   420,   429,
     429,   195,   193,   391,     4,   193,   159,     4,    77,    84,
     404,   415,   159,    85,   193,    77,   195,   325,   201,    85,
     407,   193,   419,    63,   408,   193,    92,   193,    77,   195,
     326,    77,   329,   330,   271,   413,   199,   401,    77,   419,
     206,   207,   421,   422,   288,   193,   200,   193,   200,   193,
     200,   401,   193,   417,    98,    97,   407,   104,   105,   407,
     407,   407,   419,   407,   407,   407,   415,    79,    80,   115,
     116,   119,   144,   147,   148,   149,   150,   151,   152,   153,
     154,   155,   156,   157,   341,   403,   405,   419,    73,   102,
     103,   109,   118,   126,   146,   333,   193,   266,   420,   196,
     193,   196,   193,   196,   401,   198,   196,   196,   420,     4,
     193,   392,   193,     4,   194,   198,   193,   194,     4,   335,
     193,   193,     4,    77,   331,   193,   193,    86,    93,   109,
     126,   159,   160,   161,   162,   164,   165,   166,   167,   168,
     364,     4,     4,   392,   193,   193,   138,   140,   296,   297,
     271,   418,   416,   414,   196,     5,   194,   419,   194,   194,
     194,   194,   194,   194,   194,     3,    39,   420,   196,   248,
     193,    39,    40,    41,   393,   394,    96,   395,     4,   193,
     415,   159,   415,   196,   193,   326,   407,   196,    64,    87,
     194,   194,   194,   194,   194,   194,   194,   194,   194,   194,
     196,   193,   395,   331,     7,   432,   194,   200,   296,   193,
      77,   407,   407,   407,   158,   201,   342,   417,     4,   127,
     196,   193,   196,   420,     4,   193,   194,    93,   397,   193,
       4,   194,   336,   392,   193,   193,    92,   398,     4,     4,
      87,    89,   127,   365,   415,   417,   368,   368,   408,   390,
       4,     4,   397,   332,   194,   299,     5,   254,    39,   193,
     264,   196,   393,    95,   396,   194,   159,   399,     4,   196,
     415,   196,   395,    87,    86,   196,   399,   298,   270,   193,
     342,   196,   191,   196,   398,   194,   377,   196,   397,   193,
     319,   270,   401,   193,   415,   271,   378,   399,    86,   271,
     193,   408,   321,     5,    77,   267,   193,   265,   271,   266,
     408,   196
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}

/* Prevent warnings from -Wmissing-prototypes.  */
#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{


    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */
  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;

	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),
		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss_alloc, yyss);
	YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 6:

/* Line 1455 of yacc.c  */
#line 293 "lev_comp.y"
    {
			if (fatal_error > 0) {
				(void) fprintf(stderr,
              "%s: %d errors detected for level \"%s\". No output created!\n",
					       fname, fatal_error, (yyvsp[(1) - (3)].map));
				fatal_error = 0;
				got_errors++;
			} else if (!got_errors) {
				if (!write_level_file((yyvsp[(1) - (3)].map), splev)) {
                                    lc_error("Can't write output file for '%s'!",
                                             (yyvsp[(1) - (3)].map));
				    exit(EXIT_FAILURE);
				}
			}
			Free((yyvsp[(1) - (3)].map));
			Free(splev);
			splev = NULL;
			vardef_free_all(vardefs);
			vardefs = NULL;
		  ;}
    break;

  case 7:

/* Line 1455 of yacc.c  */
#line 316 "lev_comp.y"
    {
		      start_level_def(&splev, (yyvsp[(3) - (3)].map));
		      (yyval.map) = (yyvsp[(3) - (3)].map);
		  ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 321 "lev_comp.y"
    {
		      start_level_def(&splev, (yyvsp[(3) - (5)].map));
		      if ((yyvsp[(5) - (5)].i) == -1) {
			  add_opvars(splev, "iiiiiiiio",
				     VA_PASS9(LVLINIT_MAZEGRID, HWALL, 0,0,
					      0,0,0,0, SPO_INITLEVEL));
		      } else {
			  int bg = (int)what_map_char((char) (yyvsp[(5) - (5)].i));

			  add_opvars(splev, "iiiiiiiio",
				     VA_PASS9(LVLINIT_SOLIDFILL, bg, 0, 0,
					      0,0,0,0, SPO_INITLEVEL));
		      }
		      add_opvars(splev, "io",
				 VA_PASS2(MAZELEVEL, SPO_LEVEL_FLAGS));
		      max_x_map = COLNO-1;
		      max_y_map = ROWNO;
		      (yyval.map) = (yyvsp[(3) - (5)].map);
		  ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 343 "lev_comp.y"
    {
		      int filling = (int) (yyvsp[(5) - (5)].terr).ter;

		      if (filling == INVALID_TYPE || filling >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid fill char type.");
		      add_opvars(splev, "iiiiiiiio",
				 VA_PASS9(LVLINIT_SOLIDFILL, filling,
                                          0, (int) (yyvsp[(5) - (5)].terr).lit,
                                          0,0,0,0, SPO_INITLEVEL));
		      max_x_map = COLNO-1;
		      max_y_map = ROWNO;
		  ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 356 "lev_comp.y"
    {
		      int filling = (int) what_map_char((char) (yyvsp[(5) - (5)].i));

		      if (filling == INVALID_TYPE || filling >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid fill char type.");
                      add_opvars(splev, "iiiiiiiio",
				 VA_PASS9(LVLINIT_MAZEGRID, filling, 0,0,
					  0,0,0,0, SPO_INITLEVEL));
		      max_x_map = COLNO-1;
		      max_y_map = ROWNO;
		  ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 368 "lev_comp.y"
    {
		      add_opvars(splev, "iiiiiiiio",
				 VA_PASS9(LVLINIT_ROGUE,0,0,0,
					  0,0,0,0, SPO_INITLEVEL));
		  ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 374 "lev_comp.y"
    {
                      int fg = (int) what_map_char((char) (yyvsp[(5) - (16)].i)),
                          bg = (int) what_map_char((char) (yyvsp[(7) - (16)].i));
                      int smoothed = (int) (yyvsp[(9) - (16)].i),
                          joined = (int) (yyvsp[(11) - (16)].i),
                          lit = (int) (yyvsp[(13) - (16)].i),
                          walled = (int) (yyvsp[(15) - (16)].i),
                          filling = (int) (yyvsp[(16) - (16)].i);

		      if (fg == INVALID_TYPE || fg >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid foreground type.");
		      if (bg == INVALID_TYPE || bg >= MAX_TYPE)
			  lc_error("INIT_MAP: Invalid background type.");
		      if (joined && fg != CORR && fg != ROOM && fg != GRASS && fg != GROUND && fg != AIR && fg != CLOUD)
			  lc_error("INIT_MAP: Invalid foreground type for joined map.");

		      if (filling == INVALID_TYPE)
			  lc_error("INIT_MAP: Invalid fill char type.");

		      add_opvars(splev, "iiiiiiiio",
				 VA_PASS9(LVLINIT_MINES, filling, walled, lit,
					  joined, smoothed, bg, fg,
					  SPO_INITLEVEL));
			max_x_map = COLNO-1;
			max_y_map = ROWNO;
		  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 403 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((int)(yyvsp[(3) - (3)].i), SPO_TILESET));
		  ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 409 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((int)(yyvsp[(3) - (3)].i), SPO_BOUNDARY_TYPE));
		  ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 415 "lev_comp.y"
    {
		      (yyval.i) = 0;
		  ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 419 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(2) - (2)].i);
		  ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 425 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_COPY));
		      (yyval.i) = 0;
		  ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 430 "lev_comp.y"
    {
		      (yyval.i) = 1;
		  ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 436 "lev_comp.y"
    {
		      (yyval.i) = -1;
		  ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 440 "lev_comp.y"
    {
		      (yyval.i) = what_map_char((char) (yyvsp[(2) - (2)].i));
		  ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 451 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(0, SPO_LEVEL_FLAGS));
		  ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 455 "lev_comp.y"
    {
		      add_opvars(splev, "io",
                                 VA_PASS2((int) (yyvsp[(3) - (3)].i), SPO_LEVEL_FLAGS));
		  ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 462 "lev_comp.y"
    {
		      (yyval.i) = ((yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i));
		  ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 466 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 472 "lev_comp.y"
    {
		      (yyval.i) = 0;
		  ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 476 "lev_comp.y"
    {
		      (yyval.i) = 1 + (yyvsp[(2) - (2)].i);
		  ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 482 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(2) - (3)].i);
		  ;}
    break;

  case 111:

/* Line 1455 of yacc.c  */
#line 579 "lev_comp.y"
    {
		      struct lc_vardefs *vd;

		      if ((vd = vardef_defined(vardefs, (yyvsp[(3) - (3)].map), 1))) {
			  if (!(vd->var_type & SPOVAR_ARRAY))
			      lc_error("Trying to shuffle non-array variable '%s'",
                                       (yyvsp[(3) - (3)].map));
		      } else
                          lc_error("Trying to shuffle undefined variable '%s'",
                                   (yyvsp[(3) - (3)].map));
		      add_opvars(splev, "so", VA_PASS2((yyvsp[(3) - (3)].map), SPO_SHUFFLE_ARRAY));
		      Free((yyvsp[(3) - (3)].map));
		  ;}
    break;

  case 112:

/* Line 1455 of yacc.c  */
#line 595 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (3)].map), SPOVAR_INT);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (3)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (3)].map));
		  ;}
    break;

  case 113:

/* Line 1455 of yacc.c  */
#line 601 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map), SPOVAR_SEL);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 114:

/* Line 1455 of yacc.c  */
#line 607 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (3)].map), SPOVAR_STRING);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (3)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (3)].map));
		  ;}
    break;

  case 115:

/* Line 1455 of yacc.c  */
#line 613 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map), SPOVAR_MAPCHAR);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 116:

/* Line 1455 of yacc.c  */
#line 619 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map), SPOVAR_MONST);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 117:

/* Line 1455 of yacc.c  */
#line 625 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map), SPOVAR_OBJ);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 118:

/* Line 1455 of yacc.c  */
#line 631 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (3)].map), SPOVAR_COORD);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (3)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (3)].map));
		  ;}
    break;

  case 119:

/* Line 1455 of yacc.c  */
#line 637 "lev_comp.y"
    {
		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (3)].map), SPOVAR_REGION);
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(1) - (3)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (3)].map));
		  ;}
    break;

  case 120:

/* Line 1455 of yacc.c  */
#line 643 "lev_comp.y"
    {
		      int n_items = (int) (yyvsp[(4) - (5)].i);

		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map),
                                                SPOVAR_INT | SPOVAR_ARRAY);
		      add_opvars(splev, "iso",
				 VA_PASS3(n_items, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 121:

/* Line 1455 of yacc.c  */
#line 653 "lev_comp.y"
    {
		      int n_items = (int) (yyvsp[(4) - (5)].i);

		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map),
                                                SPOVAR_COORD | SPOVAR_ARRAY);
		      add_opvars(splev, "iso",
				 VA_PASS3(n_items, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 122:

/* Line 1455 of yacc.c  */
#line 663 "lev_comp.y"
    {
                      int n_items = (int) (yyvsp[(4) - (5)].i);

		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map),
                                                SPOVAR_REGION | SPOVAR_ARRAY);
		      add_opvars(splev, "iso",
				 VA_PASS3(n_items, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 123:

/* Line 1455 of yacc.c  */
#line 673 "lev_comp.y"
    {
                      int n_items = (int) (yyvsp[(6) - (7)].i);

		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (7)].map),
                                                SPOVAR_MAPCHAR | SPOVAR_ARRAY);
		      add_opvars(splev, "iso",
				 VA_PASS3(n_items, (yyvsp[(1) - (7)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (7)].map));
		  ;}
    break;

  case 124:

/* Line 1455 of yacc.c  */
#line 683 "lev_comp.y"
    {
		      int n_items = (int) (yyvsp[(6) - (7)].i);

		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (7)].map),
                                                SPOVAR_MONST | SPOVAR_ARRAY);
		      add_opvars(splev, "iso",
				 VA_PASS3(n_items, (yyvsp[(1) - (7)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (7)].map));
		  ;}
    break;

  case 125:

/* Line 1455 of yacc.c  */
#line 693 "lev_comp.y"
    {
                      int n_items = (int) (yyvsp[(6) - (7)].i);

		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (7)].map),
                                                SPOVAR_OBJ | SPOVAR_ARRAY);
		      add_opvars(splev, "iso",
				 VA_PASS3(n_items, (yyvsp[(1) - (7)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (7)].map));
		  ;}
    break;

  case 126:

/* Line 1455 of yacc.c  */
#line 703 "lev_comp.y"
    {
                      int n_items = (int) (yyvsp[(4) - (5)].i);

		      vardefs = add_vardef_type(vardefs, (yyvsp[(1) - (5)].map),
                                                SPOVAR_STRING | SPOVAR_ARRAY);
		      add_opvars(splev, "iso",
				 VA_PASS3(n_items, (yyvsp[(1) - (5)].map), SPO_VAR_INIT));
		      Free((yyvsp[(1) - (5)].map));
		  ;}
    break;

  case 127:

/* Line 1455 of yacc.c  */
#line 715 "lev_comp.y"
    {
		      add_opvars(splev, "O", VA_PASS1((yyvsp[(1) - (1)].i)));
		      (yyval.i) = 1;
		  ;}
    break;

  case 128:

/* Line 1455 of yacc.c  */
#line 720 "lev_comp.y"
    {
		      add_opvars(splev, "O", VA_PASS1((yyvsp[(3) - (3)].i)));
		      (yyval.i) = 1 + (yyvsp[(1) - (3)].i);
		  ;}
    break;

  case 129:

/* Line 1455 of yacc.c  */
#line 727 "lev_comp.y"
    {
		      add_opvars(splev, "M", VA_PASS1((yyvsp[(1) - (1)].i)));
		      (yyval.i) = 1;
		  ;}
    break;

  case 130:

/* Line 1455 of yacc.c  */
#line 732 "lev_comp.y"
    {
		      add_opvars(splev, "M", VA_PASS1((yyvsp[(3) - (3)].i)));
		      (yyval.i) = 1 + (yyvsp[(1) - (3)].i);
		  ;}
    break;

  case 131:

/* Line 1455 of yacc.c  */
#line 739 "lev_comp.y"
    {
		      add_opvars(splev, "m", VA_PASS1((yyvsp[(1) - (1)].i)));
		      (yyval.i) = 1;
		  ;}
    break;

  case 132:

/* Line 1455 of yacc.c  */
#line 744 "lev_comp.y"
    {
		      add_opvars(splev, "m", VA_PASS1((yyvsp[(3) - (3)].i)));
		      (yyval.i) = 1 + (yyvsp[(1) - (3)].i);
		  ;}
    break;

  case 133:

/* Line 1455 of yacc.c  */
#line 751 "lev_comp.y"
    {
		      (yyval.i) = 1;
		  ;}
    break;

  case 134:

/* Line 1455 of yacc.c  */
#line 755 "lev_comp.y"
    {
		      (yyval.i) = 1 + (yyvsp[(1) - (3)].i);
		  ;}
    break;

  case 135:

/* Line 1455 of yacc.c  */
#line 761 "lev_comp.y"
    {
		      add_opvars(splev, "c", VA_PASS1((yyvsp[(1) - (1)].i)));
		      (yyval.i) = 1;
		  ;}
    break;

  case 136:

/* Line 1455 of yacc.c  */
#line 766 "lev_comp.y"
    {
		      add_opvars(splev, "c", VA_PASS1((yyvsp[(3) - (3)].i)));
		      (yyval.i) = 1 + (yyvsp[(1) - (3)].i);
		  ;}
    break;

  case 137:

/* Line 1455 of yacc.c  */
#line 773 "lev_comp.y"
    {
		      (yyval.i) = 1;
		  ;}
    break;

  case 138:

/* Line 1455 of yacc.c  */
#line 777 "lev_comp.y"
    {
		      (yyval.i) = 1 + (yyvsp[(1) - (3)].i);
		  ;}
    break;

  case 139:

/* Line 1455 of yacc.c  */
#line 783 "lev_comp.y"
    {
		      (yyval.i) = 1;
		  ;}
    break;

  case 140:

/* Line 1455 of yacc.c  */
#line 787 "lev_comp.y"
    {
		      (yyval.i) = 1 + (yyvsp[(1) - (3)].i);
		  ;}
    break;

  case 141:

/* Line 1455 of yacc.c  */
#line 793 "lev_comp.y"
    {
		      struct lc_funcdefs *funcdef;

		      if (in_function_definition)
			  lc_error("Recursively defined functions not allowed (function %s).", (yyvsp[(2) - (3)].map));

		      in_function_definition++;

		      if (funcdef_defined(function_definitions, (yyvsp[(2) - (3)].map), 1))
			  lc_error("Function '%s' already defined once.", (yyvsp[(2) - (3)].map));

		      funcdef = funcdef_new(-1, (yyvsp[(2) - (3)].map));
		      funcdef->next = function_definitions;
		      function_definitions = funcdef;
		      function_splev_backup = splev;
		      splev = &(funcdef->code);
		      Free((yyvsp[(2) - (3)].map));
		      curr_function = funcdef;
		      function_tmp_var_defs = vardefs;
		      vardefs = NULL;
		  ;}
    break;

  case 142:

/* Line 1455 of yacc.c  */
#line 815 "lev_comp.y"
    {
		      /* nothing */
		  ;}
    break;

  case 143:

/* Line 1455 of yacc.c  */
#line 819 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(0, SPO_RETURN));
		      splev = function_splev_backup;
		      in_function_definition--;
		      curr_function = NULL;
		      vardef_free_all(vardefs);
		      vardefs = function_tmp_var_defs;
		  ;}
    break;

  case 144:

/* Line 1455 of yacc.c  */
#line 830 "lev_comp.y"
    {
		      struct lc_funcdefs *tmpfunc;

		      tmpfunc = funcdef_defined(function_definitions, (yyvsp[(1) - (4)].map), 1);
		      if (tmpfunc) {
			  int l;
			  int nparams = (int) strlen((yyvsp[(3) - (4)].map));
			  char *fparamstr = funcdef_paramtypes(tmpfunc);

			  if (strcmp((yyvsp[(3) - (4)].map), fparamstr)) {
			      char *tmps = strdup(decode_parm_str(fparamstr));

			      lc_error("Function '%s' requires params '%s', got '%s' instead.",
                                       (yyvsp[(1) - (4)].map), tmps, decode_parm_str((yyvsp[(3) - (4)].map)));
			      Free(tmps);
			  }
			  Free(fparamstr);
			  Free((yyvsp[(3) - (4)].map));
			  if (!(tmpfunc->n_called)) {
			      /* we haven't called the function yet, so insert it in the code */
			      struct opvar *jmp = New(struct opvar);

			      set_opvar_int(jmp, splev->n_opcodes+1);
			      add_opcode(splev, SPO_PUSH, jmp);
                              /* we must jump past it first, then CALL it, due to RETURN. */
			      add_opcode(splev, SPO_JMP, NULL);

			      tmpfunc->addr = splev->n_opcodes;

			      { /* init function parameter variables */
				  struct lc_funcdefs_parm *tfp = tmpfunc->params;
				  while (tfp) {
				      add_opvars(splev, "iso",
						 VA_PASS3(0, tfp->name,
							  SPO_VAR_INIT));
				      tfp = tfp->next;
				  }
			      }

			      splev_add_from(splev, &(tmpfunc->code));
			      set_opvar_int(jmp,
                                            splev->n_opcodes - jmp->vardata.l);
			  }
			  l = (int) (tmpfunc->addr - splev->n_opcodes - 2);
			  add_opvars(splev, "iio",
				     VA_PASS3(nparams, l, SPO_CALL));
			  tmpfunc->n_called++;
		      } else {
			  lc_error("Function '%s' not defined.", (yyvsp[(1) - (4)].map));
		      }
		      Free((yyvsp[(1) - (4)].map));
		  ;}
    break;

  case 145:

/* Line 1455 of yacc.c  */
#line 885 "lev_comp.y"
    {
		      add_opcode(splev, SPO_EXIT, NULL);
		  ;}
    break;

  case 146:

/* Line 1455 of yacc.c  */
#line 891 "lev_comp.y"
    {
		      (yyval.i) = 100;
		  ;}
    break;

  case 147:

/* Line 1455 of yacc.c  */
#line 895 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 148:

/* Line 1455 of yacc.c  */
#line 901 "lev_comp.y"
    {
		      /* val > rn2(100) */
		      add_opvars(splev, "iio",
				 VA_PASS3((int) (yyvsp[(1) - (1)].i), 100, SPO_RN2));
		      (yyval.i) = SPO_JG;
                  ;}
    break;

  case 149:

/* Line 1455 of yacc.c  */
#line 908 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(3) - (5)].i);
                  ;}
    break;

  case 150:

/* Line 1455 of yacc.c  */
#line 912 "lev_comp.y"
    {
		      /* boolean, explicit foo != 0 */
		      add_opvars(splev, "i", VA_PASS1(0));
		      (yyval.i) = SPO_JNE;
                  ;}
    break;

  case 151:

/* Line 1455 of yacc.c  */
#line 920 "lev_comp.y"
    {
		      is_inconstant_number = 0;
		  ;}
    break;

  case 152:

/* Line 1455 of yacc.c  */
#line 924 "lev_comp.y"
    {
		      struct opvar *chkjmp;

		      if (in_switch_statement > 0)
			  lc_error("Cannot nest switch-statements.");

		      in_switch_statement++;

		      n_switch_case_list = 0;
		      switch_default_case = NULL;

		      if (!is_inconstant_number)
			  add_opvars(splev, "o", VA_PASS1(SPO_RN2));
		      is_inconstant_number = 0;

		      chkjmp = New(struct opvar);
		      set_opvar_int(chkjmp, splev->n_opcodes+1);
		      switch_check_jump = chkjmp;
		      add_opcode(splev, SPO_PUSH, chkjmp);
		      add_opcode(splev, SPO_JMP, NULL);
		      break_stmt_start();
		  ;}
    break;

  case 153:

/* Line 1455 of yacc.c  */
#line 947 "lev_comp.y"
    {
		      struct opvar *endjump = New(struct opvar);
		      int i;

		      set_opvar_int(endjump, splev->n_opcodes+1);

		      add_opcode(splev, SPO_PUSH, endjump);
		      add_opcode(splev, SPO_JMP, NULL);

		      set_opvar_int(switch_check_jump,
			     splev->n_opcodes - switch_check_jump->vardata.l);

		      for (i = 0; i < n_switch_case_list; i++) {
			  add_opvars(splev, "oio",
				     VA_PASS3(SPO_COPY,
					      switch_case_value[i], SPO_CMP));
			  set_opvar_int(switch_case_list[i],
			 switch_case_list[i]->vardata.l - splev->n_opcodes-1);
			  add_opcode(splev, SPO_PUSH, switch_case_list[i]);
			  add_opcode(splev, SPO_JE, NULL);
		      }

		      if (switch_default_case) {
			  set_opvar_int(switch_default_case,
			 switch_default_case->vardata.l - splev->n_opcodes-1);
			  add_opcode(splev, SPO_PUSH, switch_default_case);
			  add_opcode(splev, SPO_JMP, NULL);
		      }

		      set_opvar_int(endjump, splev->n_opcodes - endjump->vardata.l);

		      break_stmt_end(splev);

		      add_opcode(splev, SPO_POP, NULL); /* get rid of the value in stack */
		      in_switch_statement--;


		  ;}
    break;

  case 156:

/* Line 1455 of yacc.c  */
#line 992 "lev_comp.y"
    {
		      if (n_switch_case_list < MAX_SWITCH_CASES) {
			  struct opvar *tmppush = New(struct opvar);

			  set_opvar_int(tmppush, splev->n_opcodes);
			  switch_case_value[n_switch_case_list] = (yyvsp[(2) - (3)].i);
			  switch_case_list[n_switch_case_list++] = tmppush;
		      } else lc_error("Too many cases in a switch.");
		  ;}
    break;

  case 157:

/* Line 1455 of yacc.c  */
#line 1002 "lev_comp.y"
    {
		  ;}
    break;

  case 158:

/* Line 1455 of yacc.c  */
#line 1005 "lev_comp.y"
    {
		      struct opvar *tmppush = New(struct opvar);

		      if (switch_default_case)
			  lc_error("Switch default case already used.");

		      set_opvar_int(tmppush, splev->n_opcodes);
		      switch_default_case = tmppush;
		  ;}
    break;

  case 159:

/* Line 1455 of yacc.c  */
#line 1015 "lev_comp.y"
    {
		  ;}
    break;

  case 160:

/* Line 1455 of yacc.c  */
#line 1020 "lev_comp.y"
    {
		      if (!allow_break_statements)
			  lc_error("Cannot use BREAK outside a statement block.");
		      else {
			  break_stmt_new(splev, splev->n_opcodes);
		      }
		  ;}
    break;

  case 163:

/* Line 1455 of yacc.c  */
#line 1034 "lev_comp.y"
    {
		      char buf[256], buf2[256];

		      if (n_forloops >= MAX_NESTED_IFS) {
			  lc_error("FOR: Too deeply nested loops.");
			  n_forloops = MAX_NESTED_IFS - 1;
		      }

		      /* first, define a variable for the for-loop end value */
		      Sprintf(buf, "%s end", (yyvsp[(2) - (6)].map));
		      /* the value of which is already in stack (the 2nd math_expr) */
		      add_opvars(splev, "iso", VA_PASS3(0, buf, SPO_VAR_INIT));

		      vardefs = add_vardef_type(vardefs, (yyvsp[(2) - (6)].map), SPOVAR_INT);
		      /* define the for-loop variable. value is in stack (1st math_expr) */
		      add_opvars(splev, "iso", VA_PASS3(0, (yyvsp[(2) - (6)].map), SPO_VAR_INIT));

		      /* calculate value for the loop "step" variable */
		      Sprintf(buf2, "%s step", (yyvsp[(2) - (6)].map));
		      /* end - start */
		      add_opvars(splev, "vvo",
				 VA_PASS3(buf, (yyvsp[(2) - (6)].map), SPO_MATH_SUB));
		      /* sign of that */
		      add_opvars(splev, "o", VA_PASS1(SPO_MATH_SIGN));
		      /* save the sign into the step var */
		      add_opvars(splev, "iso",
				 VA_PASS3(0, buf2, SPO_VAR_INIT));

		      forloop_list[n_forloops].varname = strdup((yyvsp[(2) - (6)].map));
		      forloop_list[n_forloops].jmp_point = splev->n_opcodes;

		      n_forloops++;
		      Free((yyvsp[(2) - (6)].map));
		  ;}
    break;

  case 164:

/* Line 1455 of yacc.c  */
#line 1071 "lev_comp.y"
    {
		      /* nothing */
		      break_stmt_start();
		  ;}
    break;

  case 165:

/* Line 1455 of yacc.c  */
#line 1076 "lev_comp.y"
    {
                      int l;
		      char buf[256], buf2[256];

		      n_forloops--;
		      Sprintf(buf, "%s step", forloop_list[n_forloops].varname);
		      Sprintf(buf2, "%s end", forloop_list[n_forloops].varname);
		      /* compare for-loop var to end value */
		      add_opvars(splev, "vvo",
				 VA_PASS3(forloop_list[n_forloops].varname,
					  buf2, SPO_CMP));
		      /* var + step */
		      add_opvars(splev, "vvo",
				VA_PASS3(buf, forloop_list[n_forloops].varname,
					 SPO_MATH_ADD));
		      /* for-loop var = (for-loop var + step) */
		      add_opvars(splev, "iso",
				 VA_PASS3(0, forloop_list[n_forloops].varname,
					  SPO_VAR_INIT));
		      /* jump back if compared values were not equal */
                      l = (int) (forloop_list[n_forloops].jmp_point
                                 - splev->n_opcodes - 1);
		      add_opvars(splev, "io", VA_PASS2(l, SPO_JNE));
		      Free(forloop_list[n_forloops].varname);
		      break_stmt_end(splev);
		  ;}
    break;

  case 166:

/* Line 1455 of yacc.c  */
#line 1105 "lev_comp.y"
    {
		      struct opvar *tmppush = New(struct opvar);

		      if (n_if_list >= MAX_NESTED_IFS) {
			  lc_error("LOOP: Too deeply nested conditionals.");
			  n_if_list = MAX_NESTED_IFS - 1;
		      }
		      set_opvar_int(tmppush, splev->n_opcodes);
		      if_list[n_if_list++] = tmppush;

		      add_opvars(splev, "o", VA_PASS1(SPO_DEC));
		      break_stmt_start();
		  ;}
    break;

  case 167:

/* Line 1455 of yacc.c  */
#line 1119 "lev_comp.y"
    {
		      struct opvar *tmppush;

		      add_opvars(splev, "oio", VA_PASS3(SPO_COPY, 0, SPO_CMP));

		      tmppush = (struct opvar *) if_list[--n_if_list];
		      set_opvar_int(tmppush,
                                    tmppush->vardata.l - splev->n_opcodes-1);
		      add_opcode(splev, SPO_PUSH, tmppush);
		      add_opcode(splev, SPO_JG, NULL);
		      add_opcode(splev, SPO_POP, NULL); /* discard count */
		      break_stmt_end(splev);
		  ;}
    break;

  case 168:

/* Line 1455 of yacc.c  */
#line 1135 "lev_comp.y"
    {
		      struct opvar *tmppush2 = New(struct opvar);

		      if (n_if_list >= MAX_NESTED_IFS) {
			  lc_error("IF: Too deeply nested conditionals.");
			  n_if_list = MAX_NESTED_IFS - 1;
		      }

		      add_opcode(splev, SPO_CMP, NULL);

		      set_opvar_int(tmppush2, splev->n_opcodes+1);

		      if_list[n_if_list++] = tmppush2;

		      add_opcode(splev, SPO_PUSH, tmppush2);

		      add_opcode(splev, reverse_jmp_opcode( (yyvsp[(1) - (2)].i) ), NULL);

		  ;}
    break;

  case 169:

/* Line 1455 of yacc.c  */
#line 1155 "lev_comp.y"
    {
		      if (n_if_list > 0) {
			  struct opvar *tmppush;

			  tmppush = (struct opvar *) if_list[--n_if_list];
			  set_opvar_int(tmppush,
                                        splev->n_opcodes - tmppush->vardata.l);
		      } else lc_error("IF: Huh?!  No start address?");
		  ;}
    break;

  case 170:

/* Line 1455 of yacc.c  */
#line 1167 "lev_comp.y"
    {
		      struct opvar *tmppush2 = New(struct opvar);

		      if (n_if_list >= MAX_NESTED_IFS) {
			  lc_error("IF: Too deeply nested conditionals.");
			  n_if_list = MAX_NESTED_IFS - 1;
		      }

		      add_opcode(splev, SPO_CMP, NULL);

		      set_opvar_int(tmppush2, splev->n_opcodes+1);

		      if_list[n_if_list++] = tmppush2;

		      add_opcode(splev, SPO_PUSH, tmppush2);

		      add_opcode(splev, reverse_jmp_opcode( (yyvsp[(2) - (2)].i) ), NULL);

		  ;}
    break;

  case 171:

/* Line 1455 of yacc.c  */
#line 1187 "lev_comp.y"
    {
		     /* do nothing */
		  ;}
    break;

  case 172:

/* Line 1455 of yacc.c  */
#line 1193 "lev_comp.y"
    {
		      if (n_if_list > 0) {
			  struct opvar *tmppush;

			  tmppush = (struct opvar *) if_list[--n_if_list];
			  set_opvar_int(tmppush,
                                        splev->n_opcodes - tmppush->vardata.l);
		      } else lc_error("IF: Huh?!  No start address?");
		  ;}
    break;

  case 173:

/* Line 1455 of yacc.c  */
#line 1203 "lev_comp.y"
    {
		      if (n_if_list > 0) {
			  struct opvar *tmppush = New(struct opvar);
			  struct opvar *tmppush2;

			  set_opvar_int(tmppush, splev->n_opcodes+1);
			  add_opcode(splev, SPO_PUSH, tmppush);

			  add_opcode(splev, SPO_JMP, NULL);

			  tmppush2 = (struct opvar *) if_list[--n_if_list];

			  set_opvar_int(tmppush2,
                                      splev->n_opcodes - tmppush2->vardata.l);
			  if_list[n_if_list++] = tmppush;
		      } else lc_error("IF: Huh?!  No else-part address?");
		  ;}
    break;

  case 174:

/* Line 1455 of yacc.c  */
#line 1221 "lev_comp.y"
    {
		      if (n_if_list > 0) {
			  struct opvar *tmppush;
			  tmppush = (struct opvar *) if_list[--n_if_list];
			  set_opvar_int(tmppush, splev->n_opcodes - tmppush->vardata.l);
		      } else lc_error("IF: Huh?! No end address?");
		  ;}
    break;

  case 175:

/* Line 1455 of yacc.c  */
#line 1231 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MESSAGE));
		  ;}
    break;

  case 176:

/* Line 1455 of yacc.c  */
#line 1237 "lev_comp.y"
    {
		      add_opvars(splev, "iiiiiio",
			      VA_PASS7(-1,  0, -1, -1, -1, -1, SPO_CORRIDOR));
		  ;}
    break;

  case 177:

/* Line 1455 of yacc.c  */
#line 1242 "lev_comp.y"
    {
		      add_opvars(splev, "iiiiiio",
			      VA_PASS7(-1, (yyvsp[(3) - (3)].i), -1, -1, -1, -1, SPO_CORRIDOR));
		  ;}
    break;

  case 178:

/* Line 1455 of yacc.c  */
#line 1247 "lev_comp.y"
    {
		      add_opvars(splev, "iiiiiio",
			      VA_PASS7(-1, -1, -1, -1, -1, -1, SPO_CORRIDOR));
		  ;}
    break;

  case 179:

/* Line 1455 of yacc.c  */
#line 1254 "lev_comp.y"
    {
		      add_opvars(splev, "iiiiiio",
				 VA_PASS7((yyvsp[(3) - (5)].corpos).room, (yyvsp[(3) - (5)].corpos).door, (yyvsp[(3) - (5)].corpos).wall,
					  (yyvsp[(5) - (5)].corpos).room, (yyvsp[(5) - (5)].corpos).door, (yyvsp[(5) - (5)].corpos).wall,
					  SPO_CORRIDOR));
		  ;}
    break;

  case 180:

/* Line 1455 of yacc.c  */
#line 1261 "lev_comp.y"
    {
		      add_opvars(splev, "iiiiiio",
				 VA_PASS7((yyvsp[(3) - (5)].corpos).room, (yyvsp[(3) - (5)].corpos).door, (yyvsp[(3) - (5)].corpos).wall,
					  -1, -1, (long)(yyvsp[(5) - (5)].i),
					  SPO_CORRIDOR));
		  ;}
    break;

  case 181:

/* Line 1455 of yacc.c  */
#line 1270 "lev_comp.y"
    {
			(yyval.corpos).room = (yyvsp[(2) - (7)].i);
			(yyval.corpos).wall = (yyvsp[(4) - (7)].i);
			(yyval.corpos).door = (yyvsp[(6) - (7)].i);
		  ;}
    break;

  case 182:

/* Line 1455 of yacc.c  */
#line 1278 "lev_comp.y"
    {
		      if (((yyvsp[(2) - (4)].i) < 100) && ((yyvsp[(1) - (4)].i) == OROOM))
			  lc_error("Only typed rooms can have a chance.");
		      else {
			  add_opvars(splev, "iii",
				     VA_PASS3((long)(yyvsp[(1) - (4)].i), (long)(yyvsp[(2) - (4)].i), (long)(yyvsp[(4) - (4)].i)));
		      }
                  ;}
    break;

  case 183:

/* Line 1455 of yacc.c  */
#line 1289 "lev_comp.y"
    {
		      long rflags = (yyvsp[(8) - (11)].i);
		      long flmt = (long)(yyvsp[(9) - (11)].i);
		      long flt = (long)(yyvsp[(10) - (11)].i);

		      if (rflags == -1) rflags = (1 << 0);
		      if (flmt == -1) flmt = ROOM;
		      if (flt == -1) flt = 0;

		      add_opvars(splev, "iiiiiiiiio",
				 VA_PASS10(flt, flmt, rflags, ERR, ERR,
					  (yyvsp[(5) - (11)].crd).x, (yyvsp[(5) - (11)].crd).y, (yyvsp[(7) - (11)].sze).width, (yyvsp[(7) - (11)].sze).height,
					  SPO_SUBROOM));
		      break_stmt_start();
		  ;}
    break;

  case 184:

/* Line 1455 of yacc.c  */
#line 1305 "lev_comp.y"
    {
		      break_stmt_end(splev);
		      add_opcode(splev, SPO_ENDROOM, NULL);
		  ;}
    break;

  case 185:

/* Line 1455 of yacc.c  */
#line 1312 "lev_comp.y"
    {
		      long rflags = (yyvsp[(10) - (13)].i);
		      long flmt = (long)(yyvsp[(11) - (13)].i);
		      long flt = (long)(yyvsp[(12) - (13)].i);

		      if (rflags == -1) rflags = (1 << 0);

		      add_opvars(splev, "iiiiiiiiio",
				 VA_PASS10(flt, flmt, rflags,
					  (yyvsp[(7) - (13)].crd).x, (yyvsp[(7) - (13)].crd).y, (yyvsp[(5) - (13)].crd).x, (yyvsp[(5) - (13)].crd).y,
					  (yyvsp[(9) - (13)].sze).width, (yyvsp[(9) - (13)].sze).height, SPO_ROOM));
		      break_stmt_start();
		  ;}
    break;

  case 186:

/* Line 1455 of yacc.c  */
#line 1326 "lev_comp.y"
    {
		      break_stmt_end(splev);
		      add_opcode(splev, SPO_ENDROOM, NULL);
		  ;}
    break;

  case 187:

/* Line 1455 of yacc.c  */
#line 1333 "lev_comp.y"
    {
			(yyval.i) = 1;
		  ;}
    break;

  case 188:

/* Line 1455 of yacc.c  */
#line 1337 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(2) - (2)].i);
		  ;}
    break;

  case 189:

/* Line 1455 of yacc.c  */
#line 1343 "lev_comp.y"
    {
			if ( (yyvsp[(2) - (5)].i) < 1 || (yyvsp[(2) - (5)].i) > 5 ||
			    (yyvsp[(4) - (5)].i) < 1 || (yyvsp[(4) - (5)].i) > 5 ) {
			    lc_error("Room positions should be between 1-5: (%li,%li)!", (yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].i));
			} else {
			    (yyval.crd).x = (yyvsp[(2) - (5)].i);
			    (yyval.crd).y = (yyvsp[(4) - (5)].i);
			}
		  ;}
    break;

  case 190:

/* Line 1455 of yacc.c  */
#line 1353 "lev_comp.y"
    {
			(yyval.crd).x = (yyval.crd).y = ERR;
		  ;}
    break;

  case 191:

/* Line 1455 of yacc.c  */
#line 1359 "lev_comp.y"
    {
			if ( (yyvsp[(2) - (5)].i) < 0 || (yyvsp[(4) - (5)].i) < 0) {
			    lc_error("Invalid subroom position (%li,%li)!", (yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].i));
			} else {
			    (yyval.crd).x = (yyvsp[(2) - (5)].i);
			    (yyval.crd).y = (yyvsp[(4) - (5)].i);
			}
		  ;}
    break;

  case 192:

/* Line 1455 of yacc.c  */
#line 1368 "lev_comp.y"
    {
			(yyval.crd).x = (yyval.crd).y = ERR;
		  ;}
    break;

  case 193:

/* Line 1455 of yacc.c  */
#line 1374 "lev_comp.y"
    {
		      (yyval.crd).x = (yyvsp[(2) - (5)].i);
		      (yyval.crd).y = (yyvsp[(4) - (5)].i);
		  ;}
    break;

  case 194:

/* Line 1455 of yacc.c  */
#line 1379 "lev_comp.y"
    {
		      (yyval.crd).x = (yyval.crd).y = ERR;
		  ;}
    break;

  case 195:

/* Line 1455 of yacc.c  */
#line 1385 "lev_comp.y"
    {
			(yyval.sze).width = (yyvsp[(2) - (5)].i);
			(yyval.sze).height = (yyvsp[(4) - (5)].i);
		  ;}
    break;

  case 196:

/* Line 1455 of yacc.c  */
#line 1390 "lev_comp.y"
    {
			(yyval.sze).height = (yyval.sze).width = ERR;
		  ;}
    break;

  case 197:

/* Line 1455 of yacc.c  */
#line 1396 "lev_comp.y"
    {
			/* ERR means random here */
			if ((yyvsp[(7) - (10)].i) == ERR && (yyvsp[(9) - (10)].i) != ERR) {
			    lc_error("If the door wall is random, so must be its pos!");
			} else {
			    add_opvars(splev, "iiiio",
				       VA_PASS5((long)(yyvsp[(9) - (10)].i), (long)(yyvsp[(5) - (10)].i), (long)(yyvsp[(3) - (10)].i),
						(long)(yyvsp[(7) - (10)].i), SPO_ROOM_DOOR));
			}
		  ;}
    break;

  case 198:

/* Line 1455 of yacc.c  */
#line 1407 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((long)(yyvsp[(3) - (6)].i), SPO_DOOR));
		  ;}
    break;

  case 203:

/* Line 1455 of yacc.c  */
#line 1421 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 204:

/* Line 1455 of yacc.c  */
#line 1425 "lev_comp.y"
    {
		      (yyval.i) = ((yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i));
		  ;}
    break;

  case 207:

/* Line 1455 of yacc.c  */
#line 1435 "lev_comp.y"
    {
		      struct opvar *stopit = New(struct opvar);
		      set_opvar_int(stopit, SP_D_V_END);
		      add_opcode(splev, SPO_PUSH, stopit);
		      (yyval.i) = 0x00;
		  ;}
    break;

  case 208:

/* Line 1455 of yacc.c  */
#line 1442 "lev_comp.y"
    {
		      if (( (yyvsp[(1) - (3)].i) & (yyvsp[(3) - (3)].i) ))
			  lc_error("DOOR extra info '%s' defined twice.", curr_token);
		      (yyval.i) = ( (yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i) );
		  ;}
    break;

  case 209:

/* Line 1455 of yacc.c  */
#line 1450 "lev_comp.y"
    {	
		      add_opvars(splev, "ii", VA_PASS2((yyvsp[(3) - (3)].i), SP_D_V_SUBTYPE));
		      (yyval.i) = 0x0001;
		  ;}
    break;

  case 210:

/* Line 1455 of yacc.c  */
#line 1455 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_D_V_KEY_TYPE));
		      (yyval.i) = 0x0002;
		  ;}
    break;

  case 211:

/* Line 1455 of yacc.c  */
#line 1460 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((yyvsp[(3) - (3)].i), SP_D_V_SPECIAL_QUALITY));
		      (yyval.i) = 0x0004;
		  ;}
    break;

  case 212:

/* Line 1455 of yacc.c  */
#line 1465 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_D_V_INDESTRUCTIBLE));
		      (yyval.i) = 0x0008;
		  ;}
    break;

  case 213:

/* Line 1455 of yacc.c  */
#line 1470 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_D_V_SECRET_DOOR));
		      (yyval.i) = 0x0010;
		  ;}
    break;

  case 214:

/* Line 1455 of yacc.c  */
#line 1475 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_D_V_USES_UP_KEY));
		      (yyval.i) = 0x0020;
		  ;}
    break;

  case 215:

/* Line 1455 of yacc.c  */
#line 1480 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_D_V_NON_PASSDOOR));
		      (yyval.i) = 0x0040;
		  ;}
    break;

  case 216:

/* Line 1455 of yacc.c  */
#line 1488 "lev_comp.y"
    {
		      add_opvars(splev, "ciisiio",
				 VA_PASS7(0, 0, 1, (char *) 0, 0, 0, SPO_MAP));
		      max_x_map = COLNO-1;
		      max_y_map = ROWNO;
		  ;}
    break;

  case 217:

/* Line 1455 of yacc.c  */
#line 1495 "lev_comp.y"
    {
		      add_opvars(splev, "cii",
				 VA_PASS3(SP_COORD_PACK(((yyvsp[(3) - (7)].i)), ((yyvsp[(5) - (7)].i))),
					  1, (int) (yyvsp[(6) - (7)].i)));
		      scan_map((yyvsp[(7) - (7)].map), splev);
		      Free((yyvsp[(7) - (7)].map));
		  ;}
    break;

  case 218:

/* Line 1455 of yacc.c  */
#line 1503 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(2, (int) (yyvsp[(4) - (5)].i)));
		      scan_map((yyvsp[(5) - (5)].map), splev);
		      Free((yyvsp[(5) - (5)].map));
		  ;}
    break;

  case 223:

/* Line 1455 of yacc.c  */
#line 1519 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(0, SPO_MONSTER));
		  ;}
    break;

  case 224:

/* Line 1455 of yacc.c  */
#line 1523 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(1, SPO_MONSTER));
		      in_container_obj++;
		      break_stmt_start();
		  ;}
    break;

  case 225:

/* Line 1455 of yacc.c  */
#line 1529 "lev_comp.y"
    {
		     break_stmt_end(splev);
		     in_container_obj--;
		     add_opvars(splev, "o", VA_PASS1(SPO_END_MONINVENT));
		 ;}
    break;

  case 226:

/* Line 1455 of yacc.c  */
#line 1537 "lev_comp.y"
    {
		      /* nothing */
		  ;}
    break;

  case 227:

/* Line 1455 of yacc.c  */
#line 1543 "lev_comp.y"
    {
		      struct opvar *stopit = New(struct opvar);

		      set_opvar_int(stopit, SP_M_V_END);
		      add_opcode(splev, SPO_PUSH, stopit);
		      (yyval.i) = 0x00000000;
		  ;}
    break;

  case 228:

/* Line 1455 of yacc.c  */
#line 1551 "lev_comp.y"
    {
		      if (( (yyvsp[(1) - (3)].i) & (yyvsp[(3) - (3)].i) ))
			  lc_error("MONSTER extra info defined twice.");
		      (yyval.i) = ( (yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i) );
		  ;}
    break;

  case 229:

/* Line 1455 of yacc.c  */
#line 1559 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_M_V_NAME));
		      (yyval.i) = 0x00000001;
		  ;}
    break;

  case 230:

/* Line 1455 of yacc.c  */
#line 1564 "lev_comp.y"
    {
		      add_opvars(splev, "ii",
				 VA_PASS2((int) (yyvsp[(1) - (1)].i), SP_M_V_PEACEFUL));
		      (yyval.i) = 0x00000002;
		  ;}
    break;

  case 231:

/* Line 1455 of yacc.c  */
#line 1570 "lev_comp.y"
    {
		      add_opvars(splev, "ii",
				 VA_PASS2((int) (yyvsp[(1) - (1)].i), SP_M_V_ASLEEP));
		      (yyval.i) = 0x00000004;
		  ;}
    break;

  case 232:

/* Line 1455 of yacc.c  */
#line 1576 "lev_comp.y"
    {
		      add_opvars(splev, "ii",
				 VA_PASS2((int) (yyvsp[(1) - (1)].i), SP_M_V_ALIGN));
		      (yyval.i) = 0x00000008;
		  ;}
    break;

  case 233:

/* Line 1455 of yacc.c  */
#line 1582 "lev_comp.y"
    {
		      add_opvars(splev, "ii",
				 VA_PASS2((int) (yyvsp[(1) - (2)].i), SP_M_V_APPEAR));
		      (yyval.i) = 0x00000010;
		  ;}
    break;

  case 234:

/* Line 1455 of yacc.c  */
#line 1588 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_FEMALE));
		      (yyval.i) = 0x00000020;
		  ;}
    break;

  case 235:

/* Line 1455 of yacc.c  */
#line 1593 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_INVIS));
		      (yyval.i) = 0x00000040;
		  ;}
    break;

  case 236:

/* Line 1455 of yacc.c  */
#line 1598 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_CANCELLED));
		      (yyval.i) = 0x00000080;
		  ;}
    break;

  case 237:

/* Line 1455 of yacc.c  */
#line 1603 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_REVIVED));
		      (yyval.i) = 0x00000100;
		  ;}
    break;

  case 238:

/* Line 1455 of yacc.c  */
#line 1608 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_AVENGE));
		      (yyval.i) = 0x00000200;
		  ;}
    break;

  case 239:

/* Line 1455 of yacc.c  */
#line 1613 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_M_V_FLEEING));
		      (yyval.i) = 0x00000400;
		  ;}
    break;

  case 240:

/* Line 1455 of yacc.c  */
#line 1618 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_M_V_BLINDED));
		      (yyval.i) = 0x00000800;
		  ;}
    break;

  case 241:

/* Line 1455 of yacc.c  */
#line 1623 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_M_V_PARALYZED));
		      (yyval.i) = 0x00001000;
		  ;}
    break;

  case 242:

/* Line 1455 of yacc.c  */
#line 1628 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_STUNNED));
		      (yyval.i) = 0x00002000;
		  ;}
    break;

  case 243:

/* Line 1455 of yacc.c  */
#line 1633 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_CONFUSED));
		      (yyval.i) = 0x00004000;
		  ;}
    break;

  case 244:

/* Line 1455 of yacc.c  */
#line 1638 "lev_comp.y"
    {
		      add_opvars(splev, "ii",
				 VA_PASS2((int) (yyvsp[(3) - (3)].i), SP_M_V_SEENTRAPS));
		      (yyval.i) = 0x00008000;
		  ;}
    break;

  case 245:

/* Line 1455 of yacc.c  */
#line 1644 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_M_V_WAITFORU));
		      (yyval.i) = 0x00010000;
		  ;}
    break;

  case 246:

/* Line 1455 of yacc.c  */
#line 1651 "lev_comp.y"
    {
		      int token = get_trap_type((yyvsp[(1) - (1)].map));

		      if (token == ERR || token == 0)
			  lc_error("Unknown trap type '%s'!", (yyvsp[(1) - (1)].map));
                      Free((yyvsp[(1) - (1)].map));
		      (yyval.i) = (1L << (token - 1));
		  ;}
    break;

  case 247:

/* Line 1455 of yacc.c  */
#line 1660 "lev_comp.y"
    {
		      (yyval.i) = (long) ~0;
		  ;}
    break;

  case 248:

/* Line 1455 of yacc.c  */
#line 1664 "lev_comp.y"
    {
		      int token = get_trap_type((yyvsp[(1) - (3)].map));
		      if (token == ERR || token == 0)
			  lc_error("Unknown trap type '%s'!", (yyvsp[(1) - (3)].map));

		      if ((1L << (token - 1)) & (yyvsp[(3) - (3)].i))
			  lc_error("Monster seen_traps, trap '%s' listed twice.", (yyvsp[(1) - (3)].map));
                      Free((yyvsp[(1) - (3)].map));
		      (yyval.i) = ((1L << (token - 1)) | (yyvsp[(3) - (3)].i));
		  ;}
    break;

  case 249:

/* Line 1455 of yacc.c  */
#line 1677 "lev_comp.y"
    {
		      int cnt = 0;

		      if (in_container_obj)
                          cnt |= SP_OBJ_CONTENT;
		      add_opvars(splev, "io", VA_PASS2(cnt, SPO_OBJECT));
		  ;}
    break;

  case 250:

/* Line 1455 of yacc.c  */
#line 1685 "lev_comp.y"
    {
		      int cnt = SP_OBJ_CONTAINER;

		      if (in_container_obj)
                          cnt |= SP_OBJ_CONTENT;
		      add_opvars(splev, "io", VA_PASS2(cnt, SPO_OBJECT));
		      in_container_obj++;
		      break_stmt_start();
		  ;}
    break;

  case 251:

/* Line 1455 of yacc.c  */
#line 1695 "lev_comp.y"
    {
		     break_stmt_end(splev);
		     in_container_obj--;
		     add_opcode(splev, SPO_POP_CONTAINER, NULL);
		 ;}
    break;

  case 252:

/* Line 1455 of yacc.c  */
#line 1703 "lev_comp.y"
    {
		      if (( (yyvsp[(2) - (2)].i) & 0x4000) && in_container_obj)
                          lc_error("Object cannot have a coord when contained.");
		      else if (!( (yyvsp[(2) - (2)].i) & 0x4000) && !in_container_obj)
                          lc_error("Object needs a coord when not contained.");
		  ;}
    break;

  case 253:

/* Line 1455 of yacc.c  */
#line 1712 "lev_comp.y"
    {
		      struct opvar *stopit = New(struct opvar);
		      set_opvar_int(stopit, SP_O_V_END);
		      add_opcode(splev, SPO_PUSH, stopit);
		      (yyval.i) = 0x00;
		  ;}
    break;

  case 254:

/* Line 1455 of yacc.c  */
#line 1719 "lev_comp.y"
    {
		      if (( (yyvsp[(1) - (3)].i) & (yyvsp[(3) - (3)].i) ))
			  lc_error("OBJECT extra info '%s' defined twice.", curr_token);
		      (yyval.i) = ( (yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i) );
		  ;}
    break;

  case 255:

/* Line 1455 of yacc.c  */
#line 1727 "lev_comp.y"
    {
		      add_opvars(splev, "ii",
				 VA_PASS2((int) (yyvsp[(1) - (1)].i), SP_O_V_CURSE));
		      (yyval.i) = 0x0001;
		  ;}
    break;

  case 256:

/* Line 1455 of yacc.c  */
#line 1733 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_CORPSENM));
		      (yyval.i) = 0x0002;
		  ;}
    break;

  case 257:

/* Line 1455 of yacc.c  */
#line 1738 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_SPE));
		      (yyval.i) = 0x0004;
		  ;}
    break;

  case 258:

/* Line 1455 of yacc.c  */
#line 1743 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_NAME));
		      (yyval.i) = 0x0008;
		  ;}
    break;

  case 259:

/* Line 1455 of yacc.c  */
#line 1748 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_QUAN));
		      (yyval.i) = 0x0010;
		  ;}
    break;

  case 260:

/* Line 1455 of yacc.c  */
#line 1753 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_BURIED));
		      (yyval.i) = 0x0020;
		  ;}
    break;

  case 261:

/* Line 1455 of yacc.c  */
#line 1758 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((int) (yyvsp[(1) - (1)].i), SP_O_V_LIT));
		      (yyval.i) = 0x0040;
		  ;}
    break;

  case 262:

/* Line 1455 of yacc.c  */
#line 1763 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_ERODED));
		      (yyval.i) = 0x0080;
		  ;}
    break;

  case 263:

/* Line 1455 of yacc.c  */
#line 1768 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(-1, SP_O_V_ERODED));
		      (yyval.i) = 0x0080;
		  ;}
    break;

  case 264:

/* Line 1455 of yacc.c  */
#line 1773 "lev_comp.y"
    {
		      if ((yyvsp[(1) - (1)].i) == D_LOCKED) {
			  add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_LOCKED));
			  (yyval.i) = 0x0100;
		      } else if ((yyvsp[(1) - (1)].i) == D_BROKEN) {
			  add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_BROKEN));
			  (yyval.i) = 0x0200;
		      } else if ((yyvsp[(1) - (1)].i) == D_ISOPEN) {
			  add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_OPEN));
			  (yyval.i) = 0x2000000;
		      } else
			  lc_error("DOOR state can only be locked or broken.");
		  ;}
    break;

  case 265:

/* Line 1455 of yacc.c  */
#line 1787 "lev_comp.y"
    {
		      add_opvars(splev, "ii",
                                 VA_PASS2((int) (yyvsp[(1) - (1)].i), SP_O_V_TRAPPED));
		      (yyval.i) = 0x0400;
		  ;}
    break;

  case 266:

/* Line 1455 of yacc.c  */
#line 1793 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_RECHARGED));
		      (yyval.i) = 0x0800;
		  ;}
    break;

  case 267:

/* Line 1455 of yacc.c  */
#line 1798 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_INVIS));
		      (yyval.i) = 0x1000;
		  ;}
    break;

  case 268:

/* Line 1455 of yacc.c  */
#line 1803 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_GREASED));
		      (yyval.i) = 0x2000;
		  ;}
    break;

  case 269:

/* Line 1455 of yacc.c  */
#line 1808 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_COORD));
		      (yyval.i) = 0x4000;
		  ;}
    break;

  case 270:

/* Line 1455 of yacc.c  */
#line 1813 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((int)(yyvsp[(3) - (3)].i), SP_O_V_ELEMENTAL_ENCHANTMENT));
		      (yyval.i) = 0x8000;
		  ;}
    break;

  case 271:

/* Line 1455 of yacc.c  */
#line 1818 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((int)(yyvsp[(3) - (3)].i), SP_O_V_EXCEPTIONALITY));
		      (yyval.i) = 0x10000;
		  ;}
    break;

  case 272:

/* Line 1455 of yacc.c  */
#line 1823 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((int)(yyvsp[(3) - (3)].i), SP_O_V_MYTHIC_PREFIX));
		      (yyval.i) = 0x2000000;
		  ;}
    break;

  case 273:

/* Line 1455 of yacc.c  */
#line 1828 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((int)(yyvsp[(3) - (3)].i), SP_O_V_MYTHIC_SUFFIX));
		      (yyval.i) = 0x4000000;
		  ;}
    break;

  case 274:

/* Line 1455 of yacc.c  */
#line 1833 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_ENCHANTMENT));
		      (yyval.i) = 0x20000;
		  ;}
    break;

  case 275:

/* Line 1455 of yacc.c  */
#line 1838 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_CHARGES));
		      (yyval.i) = 0x40000;
		  ;}
    break;

  case 276:

/* Line 1455 of yacc.c  */
#line 1843 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_SPECIAL_QUALITY));
		      (yyval.i) = 0x80000;
		  ;}
    break;

  case 277:

/* Line 1455 of yacc.c  */
#line 1848 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_SPEFLAGS));
		      (yyval.i) = 0x100000;
		  ;}
    break;

  case 278:

/* Line 1455 of yacc.c  */
#line 1853 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_O_V_KEY_TYPE));
		      (yyval.i) = 0x200000;
		  ;}
    break;

  case 279:

/* Line 1455 of yacc.c  */
#line 1858 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_INDESTRUCTIBLE));
		      (yyval.i) = 0x400000;
		  ;}
    break;

  case 280:

/* Line 1455 of yacc.c  */
#line 1863 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_USES_UP_KEY));
		      (yyval.i) = 0x800000;
		  ;}
    break;

  case 281:

/* Line 1455 of yacc.c  */
#line 1868 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2(1, SP_O_V_NO_PICKUP));
		      (yyval.i) = 0x1000000;
		  ;}
    break;

  case 282:

/* Line 1455 of yacc.c  */
#line 1875 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((int) (yyvsp[(3) - (5)].i), SPO_TRAP));
		  ;}
    break;

  case 283:

/* Line 1455 of yacc.c  */
#line 1881 "lev_comp.y"
    {
		       long dir, state = 0;

		       /* convert dir from a DIRECTION to a DB_DIR */
		       dir = (yyvsp[(5) - (7)].i);
		       switch (dir) {
		       case W_NORTH: dir = DB_NORTH; break;
		       case W_SOUTH: dir = DB_SOUTH; break;
		       case W_EAST:  dir = DB_EAST;  break;
		       case W_WEST:  dir = DB_WEST;  break;
		       default:
			   lc_error("Invalid drawbridge direction.");
			   break;
		       }

		       if ( (yyvsp[(7) - (7)].i) == D_ISOPEN )
			   state = 1;
		       else if ( (yyvsp[(7) - (7)].i) == D_CLOSED )
			   state = 0;
		       else if ( (yyvsp[(7) - (7)].i) == -1 )
			   state = -1;
		       else
			   lc_error("A drawbridge can only be open, closed or random!");
		       add_opvars(splev, "iio",
				  VA_PASS3(state, dir, SPO_DRAWBRIDGE));
		   ;}
    break;

  case 284:

/* Line 1455 of yacc.c  */
#line 1910 "lev_comp.y"
    {
		      add_opvars(splev, "iiio",
				 VA_PASS4((int) (yyvsp[(5) - (5)].i), 1, 0, SPO_MAZEWALK));
		  ;}
    break;

  case 285:

/* Line 1455 of yacc.c  */
#line 1915 "lev_comp.y"
    {
		      add_opvars(splev, "iiio",
				 VA_PASS4((int) (yyvsp[(5) - (8)].i), (int) (yyvsp[(7) - (8)].i),
					  (int) (yyvsp[(8) - (8)].i), SPO_MAZEWALK));
		  ;}
    break;

  case 286:

/* Line 1455 of yacc.c  */
#line 1923 "lev_comp.y"
    {
		      add_opvars(splev, "rio",
				 VA_PASS3(SP_REGION_PACK(-1,-1,-1,-1),
					  0, SPO_WALLIFY));
		  ;}
    break;

  case 287:

/* Line 1455 of yacc.c  */
#line 1929 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(1, SPO_WALLIFY));
		  ;}
    break;

  case 288:

/* Line 1455 of yacc.c  */
#line 1933 "lev_comp.y"
    {
		      add_opvars(splev, "rio",
				 VA_PASS3(SP_REGION_PACK(-1,-1,-1,-1),
					  2, SPO_WALLIFY));
		  ;}
    break;

  case 289:

/* Line 1455 of yacc.c  */
#line 1941 "lev_comp.y"
    {
		      add_opvars(splev, "io",
				 VA_PASS2((int) (yyvsp[(5) - (5)].i), SPO_LADDER));
		  ;}
    break;

  case 290:

/* Line 1455 of yacc.c  */
#line 1948 "lev_comp.y"
    {
		      add_opvars(splev, "io",
				 VA_PASS2((int) (yyvsp[(5) - (5)].i), SPO_STAIR));
		  ;}
    break;

  case 291:

/* Line 1455 of yacc.c  */
#line 1955 "lev_comp.y"
    {
		      add_opvars(splev, "iiiii iiiii iiso",
				 VA_PASS14((yyvsp[(3) - (7)].lregn).x1, (yyvsp[(3) - (7)].lregn).y1, (yyvsp[(3) - (7)].lregn).x2, (yyvsp[(3) - (7)].lregn).y2, (yyvsp[(3) - (7)].lregn).area,
					   (yyvsp[(5) - (7)].lregn).x1, (yyvsp[(5) - (7)].lregn).y1, (yyvsp[(5) - (7)].lregn).x2, (yyvsp[(5) - (7)].lregn).y2, (yyvsp[(5) - (7)].lregn).area,
				     (long) (((yyvsp[(7) - (7)].i)) ? LR_UPSTAIR : LR_DOWNSTAIR),
					   0, (char *) 0, SPO_LEVREGION));
		  ;}
    break;

  case 292:

/* Line 1455 of yacc.c  */
#line 1965 "lev_comp.y"
    {
		      add_opvars(splev, "iiiii iiiii iiso",
				 VA_PASS14((yyvsp[(3) - (7)].lregn).x1, (yyvsp[(3) - (7)].lregn).y1, (yyvsp[(3) - (7)].lregn).x2, (yyvsp[(3) - (7)].lregn).y2, (yyvsp[(3) - (7)].lregn).area,
					   (yyvsp[(5) - (7)].lregn).x1, (yyvsp[(5) - (7)].lregn).y1, (yyvsp[(5) - (7)].lregn).x2, (yyvsp[(5) - (7)].lregn).y2, (yyvsp[(5) - (7)].lregn).area,
					   LR_PORTAL, 0, (yyvsp[(7) - (7)].map), SPO_LEVREGION));
		      Free((yyvsp[(7) - (7)].map));
		  ;}
    break;

  case 293:

/* Line 1455 of yacc.c  */
#line 1975 "lev_comp.y"
    {
		      long rtyp = 0;
		      switch((yyvsp[(6) - (6)].i)) {
		      case -1: rtyp = LR_TELE; break;
		      case  0: rtyp = LR_DOWNTELE; break;
		      case  1: rtyp = LR_UPTELE; break;
		      }
		      add_opvars(splev, "iiiii iiiii iiso",
				 VA_PASS14((yyvsp[(3) - (6)].lregn).x1, (yyvsp[(3) - (6)].lregn).y1, (yyvsp[(3) - (6)].lregn).x2, (yyvsp[(3) - (6)].lregn).y2, (yyvsp[(3) - (6)].lregn).area,
					   (yyvsp[(5) - (6)].lregn).x1, (yyvsp[(5) - (6)].lregn).y1, (yyvsp[(5) - (6)].lregn).x2, (yyvsp[(5) - (6)].lregn).y2, (yyvsp[(5) - (6)].lregn).area,
					   rtyp, 0, (char *)0, SPO_LEVREGION));
		  ;}
    break;

  case 294:

/* Line 1455 of yacc.c  */
#line 1990 "lev_comp.y"
    {
		      add_opvars(splev, "iiiii iiiii iiso",
				 VA_PASS14((yyvsp[(3) - (5)].lregn).x1, (yyvsp[(3) - (5)].lregn).y1, (yyvsp[(3) - (5)].lregn).x2, (yyvsp[(3) - (5)].lregn).y2, (yyvsp[(3) - (5)].lregn).area,
					   (yyvsp[(5) - (5)].lregn).x1, (yyvsp[(5) - (5)].lregn).y1, (yyvsp[(5) - (5)].lregn).x2, (yyvsp[(5) - (5)].lregn).y2, (yyvsp[(5) - (5)].lregn).area,
					   (long) LR_BRANCH, 0,
					   (char *) 0, SPO_LEVREGION));
		  ;}
    break;

  case 295:

/* Line 1455 of yacc.c  */
#line 2000 "lev_comp.y"
    {
			(yyval.i) = -1;
		  ;}
    break;

  case 296:

/* Line 1455 of yacc.c  */
#line 2004 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(2) - (2)].i);
		  ;}
    break;

  case 297:

/* Line 1455 of yacc.c  */
#line 2010 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((int)(yyvsp[(5) - (5)].i), SPO_FOUNTAIN));
		  ;}
    break;

  case 298:

/* Line 1455 of yacc.c  */
#line 2016 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_THRONE));
		  ;}
    break;

  case 299:

/* Line 1455 of yacc.c  */
#line 2022 "lev_comp.y"
    {
		      add_opvars(splev, "iio", VA_PASS3((int) (yyvsp[(9) - (11)].i), (int) (yyvsp[(11) - (11)].i), SPO_MODRON_PORTAL));
		  ;}
    break;

  case 300:

/* Line 1455 of yacc.c  */
#line 2026 "lev_comp.y"
    {
		      add_opvars(splev, "iiiio", VA_PASS5((int) (yyvsp[(7) - (13)].i), (int) (yyvsp[(9) - (13)].i), (int) (yyvsp[(11) - (13)].i), (int) (yyvsp[(13) - (13)].i), SPO_MODRON_LEVEL_TELEPORTER));
		  ;}
    break;

  case 301:

/* Line 1455 of yacc.c  */
#line 2032 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((int) (yyvsp[(5) - (6)].i), SPO_LEVER));
		  ;}
    break;

  case 302:

/* Line 1455 of yacc.c  */
#line 2038 "lev_comp.y"
    {
		      struct opvar *stopit = New(struct opvar);
		      set_opvar_int(stopit, SP_L_V_END);
		      add_opcode(splev, SPO_PUSH, stopit);
		      (yyval.i) = 0x00;
		  ;}
    break;

  case 303:

/* Line 1455 of yacc.c  */
#line 2045 "lev_comp.y"
    {
		      if (( (yyvsp[(1) - (3)].i) & (yyvsp[(3) - (3)].i) ))
			  lc_error("LEVER extra info '%s' defined twice.", curr_token);
		      (yyval.i) = ( (yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i) );
		  ;}
    break;

  case 304:

/* Line 1455 of yacc.c  */
#line 2053 "lev_comp.y"
    {	
		      add_opvars(splev, "ii",
				 VA_PASS2((int) (yyvsp[(1) - (1)].i), SP_L_V_ACTIVE));
		      (yyval.i) = 0x0001;
		  ;}
    break;

  case 305:

/* Line 1455 of yacc.c  */
#line 2059 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_L_V_MONSTER));
		      (yyval.i) = 0x0002;
		  ;}
    break;

  case 306:

/* Line 1455 of yacc.c  */
#line 2064 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_L_V_OBJECT));
		      (yyval.i) = 0x0004;
		  ;}
    break;

  case 307:

/* Line 1455 of yacc.c  */
#line 2069 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((int)(yyvsp[(3) - (3)].terr).ter, SP_L_V_TERRAIN));
		      (yyval.i) = 0x0008;
		  ;}
    break;

  case 308:

/* Line 1455 of yacc.c  */
#line 2074 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((int)(yyvsp[(3) - (3)].terr).ter, SP_L_V_TERRAIN2));
		      (yyval.i) = 0x0010;
		  ;}
    break;

  case 309:

/* Line 1455 of yacc.c  */
#line 2079 "lev_comp.y"
    {	
		      add_opvars(splev, "ii",
				 VA_PASS2(1, SP_L_V_SWITCHABLE));
		      (yyval.i) = 0x0020;
		  ;}
    break;

  case 310:

/* Line 1455 of yacc.c  */
#line 2085 "lev_comp.y"
    {	
		      add_opvars(splev, "ii",
				 VA_PASS2(1, SP_L_V_CONTINUOUS));
		      (yyval.i) = 0x0040;
		  ;}
    break;

  case 311:

/* Line 1455 of yacc.c  */
#line 2091 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1(SP_L_V_COORD));
		      (yyval.i) = 0x0080;
		  ;}
    break;

  case 312:

/* Line 1455 of yacc.c  */
#line 2096 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((yyvsp[(3) - (3)].i), SP_L_V_TRAP));
		      (yyval.i) = 0x0100;
		  ;}
    break;

  case 313:

/* Line 1455 of yacc.c  */
#line 2101 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((yyvsp[(3) - (3)].i), SP_L_V_SUBTYPE));
		      (yyval.i) = 0x0200;
		  ;}
    break;

  case 314:

/* Line 1455 of yacc.c  */
#line 2106 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((yyvsp[(3) - (3)].i), SP_L_V_CATEGORY));
		      (yyval.i) = 0x0400;
		  ;}
    break;

  case 315:

/* Line 1455 of yacc.c  */
#line 2111 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((yyvsp[(3) - (3)].i), SP_L_V_EFFECT_FLAG));
		      (yyval.i) = 0x0800;
		  ;}
    break;

  case 316:

/* Line 1455 of yacc.c  */
#line 2116 "lev_comp.y"
    {
		      add_opvars(splev, "ii", VA_PASS2((yyvsp[(3) - (3)].i), SP_L_V_SPECIAL_QUALITY));
		      (yyval.i) = 0x1000;
		  ;}
    break;

  case 321:

/* Line 1455 of yacc.c  */
#line 2126 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SINK));
		  ;}
    break;

  case 322:

/* Line 1455 of yacc.c  */
#line 2132 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_POOL));
		  ;}
    break;

  case 323:

/* Line 1455 of yacc.c  */
#line 2138 "lev_comp.y"
    {
		      (yyval.terr).lit = -2;
		      (yyval.terr).ter = what_map_char((char) (yyvsp[(1) - (1)].i));
		  ;}
    break;

  case 324:

/* Line 1455 of yacc.c  */
#line 2143 "lev_comp.y"
    {
		      (yyval.terr).lit = (yyvsp[(4) - (5)].i);
		      (yyval.terr).ter = what_map_char((char) (yyvsp[(2) - (5)].i));
		  ;}
    break;

  case 325:

/* Line 1455 of yacc.c  */
#line 2150 "lev_comp.y"
    {
		      add_opvars(splev, "io",
				 VA_PASS2((yyvsp[(9) - (9)].i), SPO_REPLACETERRAIN));
		  ;}
    break;

  case 326:

/* Line 1455 of yacc.c  */
#line 2157 "lev_comp.y"
    {
		     add_opvars(splev, "o", VA_PASS1(SPO_TERRAIN));
		 ;}
    break;

  case 327:

/* Line 1455 of yacc.c  */
#line 2163 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_NON_DIGGABLE));
		  ;}
    break;

  case 328:

/* Line 1455 of yacc.c  */
#line 2169 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_NON_PASSWALL));
		  ;}
    break;

  case 329:

/* Line 1455 of yacc.c  */
#line 2175 "lev_comp.y"
    {
		      add_opvars(splev, "Miso", VA_PASS4(-1, (yyvsp[(5) - (5)].i), (yyvsp[(3) - (5)].map), SPO_NAMING));
		      Free((yyvsp[(3) - (5)].map));
		  ;}
    break;

  case 330:

/* Line 1455 of yacc.c  */
#line 2180 "lev_comp.y"
    {
		      add_opvars(splev, "iso", VA_PASS3((yyvsp[(5) - (9)].i), (yyvsp[(3) - (9)].map), SPO_NAMING));
		      Free((yyvsp[(3) - (9)].map));
		  ;}
    break;

  case 331:

/* Line 1455 of yacc.c  */
#line 2187 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((yyvsp[(5) - (5)].i), SPO_SPECIAL_REGION));
		  ;}
    break;

  case 332:

/* Line 1455 of yacc.c  */
#line 2193 "lev_comp.y"
    {
		      add_opvars(splev, "iiiii iiiii iiso",
				 VA_PASS14((yyvsp[(3) - (5)].lregn).x1, (yyvsp[(3) - (5)].lregn).y1, (yyvsp[(3) - (5)].lregn).x2, (yyvsp[(3) - (5)].lregn).y2, (yyvsp[(3) - (5)].lregn).area,
					   0, 0, 0, 0, 1,
					   (yyvsp[(5) - (5)].i) == REGION_SPECIAL_LEVEL_SEEN ? (long) LR_SPECIAL_MAP_SEEN : (long) LR_SPECIAL_MAP_NAME_REVEALED, 0,
					   (char *) 0, SPO_LEVREGION));
		  ;}
    break;

  case 333:

/* Line 1455 of yacc.c  */
#line 2203 "lev_comp.y"
    {
		      long irr;
		      long rt = (yyvsp[(7) - (11)].i);
		      long rflags = (yyvsp[(8) - (11)].i);
		      long flmt = (long)(yyvsp[(9) - (11)].i);
		      long flt = (long)(yyvsp[(10) - (11)].i);

		      if (rflags == -1) rflags = (1 << 0);
		      if (flmt == -1) flmt = ROOM;
		      if (flt == -1) flt = 0;

		      if (!(rflags & 1)) rt += MAXRTYPE+1;
		      irr = ((rflags & 2) != 0);
		      add_opvars(splev, "iiiiio",
				 VA_PASS6((long)(yyvsp[(5) - (11)].i), rt, rflags, flmt, flt, SPO_REGION));
		      (yyval.i) = (irr || (rflags & 1) || rt != OROOM);
		      break_stmt_start();
		  ;}
    break;

  case 334:

/* Line 1455 of yacc.c  */
#line 2222 "lev_comp.y"
    {
		      break_stmt_end(splev);
			  add_opcode(splev, SPO_ENDROOM, NULL);
		      /*if ( $<i>9 ||  $<i>10 ||  $<i>11 ) {
			  	add_opcode(splev, SPO_ENDROOM, NULL);
		       } else if ( $<i>12 )
			  	lc_error("Cannot use lev statements in non-permanent REGION");
		      */
		  ;}
    break;

  case 335:

/* Line 1455 of yacc.c  */
#line 2234 "lev_comp.y"
    {
		      (yyval.i) = 0;
		  ;}
    break;

  case 336:

/* Line 1455 of yacc.c  */
#line 2238 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 337:

/* Line 1455 of yacc.c  */
#line 2244 "lev_comp.y"
    {
		      add_opvars(splev, "Miio",
				 VA_PASS4(-1, (long)(yyvsp[(7) - (7)].i), (long)(yyvsp[(5) - (7)].i), SPO_ALTAR));
		  ;}
    break;

  case 338:

/* Line 1455 of yacc.c  */
#line 2249 "lev_comp.y"
    {
		      add_opvars(splev, "iio",
				 VA_PASS3((long)(yyvsp[(7) - (11)].i), (long)(yyvsp[(5) - (11)].i), SPO_ALTAR));
		  ;}
    break;

  case 339:

/* Line 1455 of yacc.c  */
#line 2256 "lev_comp.y"
    {
		      add_opvars(splev, "Mo", VA_PASS2(-1, SPO_ANVIL));
		  ;}
    break;

  case 340:

/* Line 1455 of yacc.c  */
#line 2260 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_ANVIL));
		  ;}
    break;

  case 341:

/* Line 1455 of yacc.c  */
#line 2266 "lev_comp.y"
    {
		      add_opvars(splev, "iio", VA_PASS3((int)(yyvsp[(7) - (7)].i), (int)(yyvsp[(5) - (7)].i), SPO_FLOOR));
		  ;}
    break;

  case 342:

/* Line 1455 of yacc.c  */
#line 2272 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((int)(yyvsp[(5) - (5)].i), SPO_SUBTYPE));
		  ;}
    break;

  case 343:

/* Line 1455 of yacc.c  */
#line 2278 "lev_comp.y"
    {
		      add_opvars(splev, "Mio", VA_PASS3(-1, (int)(yyvsp[(3) - (5)].i), SPO_NPC));
		  ;}
    break;

  case 344:

/* Line 1455 of yacc.c  */
#line 2282 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((int)(yyvsp[(3) - (9)].i), SPO_NPC));
		  ;}
    break;

  case 345:

/* Line 1455 of yacc.c  */
#line 2288 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(2, SPO_GRAVE));
		  ;}
    break;

  case 346:

/* Line 1455 of yacc.c  */
#line 2292 "lev_comp.y"
    {
		      add_opvars(splev, "sio",
				 VA_PASS3((char *)0, 1, SPO_GRAVE));
		  ;}
    break;

  case 347:

/* Line 1455 of yacc.c  */
#line 2297 "lev_comp.y"
    {
		      add_opvars(splev, "sio",
				 VA_PASS3((char *)0, 0, SPO_GRAVE));
		  ;}
    break;

  case 348:

/* Line 1455 of yacc.c  */
#line 2304 "lev_comp.y"
    {
		      add_opvars(splev, "iio", VA_PASS3((int)(yyvsp[(7) - (7)].i), (int)(yyvsp[(5) - (7)].i), SPO_BRAZIER));
		  ;}
    break;

  case 349:

/* Line 1455 of yacc.c  */
#line 2308 "lev_comp.y"
    {
		      add_opvars(splev, "iio",
				 VA_PASS3(1, 0, SPO_BRAZIER));
		  ;}
    break;

  case 350:

/* Line 1455 of yacc.c  */
#line 2315 "lev_comp.y"
    {
		      add_opvars(splev, "iio", VA_PASS3(2, (int)(yyvsp[(5) - (7)].i), SPO_SIGNPOST));
		  ;}
    break;

  case 351:

/* Line 1455 of yacc.c  */
#line 2319 "lev_comp.y"
    {
		      add_opvars(splev, "siio",
				 VA_PASS4((char *)0, 1, (int)(yyvsp[(5) - (7)].i), SPO_SIGNPOST));
		  ;}
    break;

  case 352:

/* Line 1455 of yacc.c  */
#line 2324 "lev_comp.y"
    {
		      add_opvars(splev, "sio",
				 VA_PASS4((char *)0, 0, 0, SPO_SIGNPOST));
		  ;}
    break;

  case 353:

/* Line 1455 of yacc.c  */
#line 2331 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_GOLD));
		  ;}
    break;

  case 354:

/* Line 1455 of yacc.c  */
#line 2337 "lev_comp.y"
    {
		      add_opvars(splev, "io",
				 VA_PASS2((long)(yyvsp[(5) - (7)].i), SPO_ENGRAVING));
		  ;}
    break;

  case 355:

/* Line 1455 of yacc.c  */
#line 2344 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MINERALIZE));
		  ;}
    break;

  case 356:

/* Line 1455 of yacc.c  */
#line 2348 "lev_comp.y"
    {
		      add_opvars(splev, "iiiio",
				 VA_PASS5(-1L, -1L, -1L, -1L, SPO_MINERALIZE));
		  ;}
    break;

  case 357:

/* Line 1455 of yacc.c  */
#line 2355 "lev_comp.y"
    {
			int token = get_trap_type((yyvsp[(1) - (1)].map));
			if (token == ERR)
			    lc_error("Unknown trap type '%s'!", (yyvsp[(1) - (1)].map));
			(yyval.i) = token;
			Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 359:

/* Line 1455 of yacc.c  */
#line 2366 "lev_comp.y"
    {
			int token = get_room_type((yyvsp[(1) - (1)].map));
			if (token == ERR) {
			    lc_warning("Unknown room type \"%s\"!  Making ordinary room...", (yyvsp[(1) - (1)].map));
				(yyval.i) = OROOM;
			} else
				(yyval.i) = token;
			Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 361:

/* Line 1455 of yacc.c  */
#line 2379 "lev_comp.y"
    {
			(yyval.i) = -1;
		  ;}
    break;

  case 362:

/* Line 1455 of yacc.c  */
#line 2383 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(2) - (2)].i);
		  ;}
    break;

  case 363:

/* Line 1455 of yacc.c  */
#line 2389 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 364:

/* Line 1455 of yacc.c  */
#line 2393 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i);
		  ;}
    break;

  case 365:

/* Line 1455 of yacc.c  */
#line 2400 "lev_comp.y"
    {
		      (yyval.i) = ((yyvsp[(1) - (1)].i) << 0);
		  ;}
    break;

  case 366:

/* Line 1455 of yacc.c  */
#line 2404 "lev_comp.y"
    {
		      (yyval.i) = ((yyvsp[(1) - (1)].i) << 1);
		  ;}
    break;

  case 367:

/* Line 1455 of yacc.c  */
#line 2408 "lev_comp.y"
    {
		      (yyval.i) = ((yyvsp[(1) - (1)].i) << 2);
		  ;}
    break;

  case 368:

/* Line 1455 of yacc.c  */
#line 2414 "lev_comp.y"
    {
			(yyval.i) = ROOM;
		  ;}
    break;

  case 369:

/* Line 1455 of yacc.c  */
#line 2418 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(3) - (3)].i);
		  ;}
    break;

  case 370:

/* Line 1455 of yacc.c  */
#line 2424 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 371:

/* Line 1455 of yacc.c  */
#line 2430 "lev_comp.y"
    {
			(yyval.i) = 0;
		  ;}
    break;

  case 372:

/* Line 1455 of yacc.c  */
#line 2434 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(3) - (3)].i);
		  ;}
    break;

  case 373:

/* Line 1455 of yacc.c  */
#line 2440 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 374:

/* Line 1455 of yacc.c  */
#line 2446 "lev_comp.y"
    {
			add_opvars(splev, "M", VA_PASS1(-1));
			(yyval.i) = -1;
		  ;}
    break;

  case 375:

/* Line 1455 of yacc.c  */
#line 2451 "lev_comp.y"
    {
			(yyval.i) = (yyvsp[(3) - (3)].i);
		  ;}
    break;

  case 382:

/* Line 1455 of yacc.c  */
#line 2468 "lev_comp.y"
    {
			(yyval.i) = - MAX_REGISTERS - 1;
		  ;}
    break;

  case 385:

/* Line 1455 of yacc.c  */
#line 2476 "lev_comp.y"
    {
			(yyval.i) = - MAX_REGISTERS - 1;
		  ;}
    break;

  case 388:

/* Line 1455 of yacc.c  */
#line 2486 "lev_comp.y"
    {
			if ( (yyvsp[(3) - (4)].i) >= 3 )
				lc_error("Register Index overflow!");
			else
				(yyval.i) = - (yyvsp[(3) - (4)].i) - 1;
		  ;}
    break;

  case 389:

/* Line 1455 of yacc.c  */
#line 2495 "lev_comp.y"
    {
		      add_opvars(splev, "s", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 390:

/* Line 1455 of yacc.c  */
#line 2500 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_STRING);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 391:

/* Line 1455 of yacc.c  */
#line 2507 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (4)].map),
                                        SPOVAR_STRING | SPOVAR_ARRAY);
		      vardef_used(vardefs, (yyvsp[(1) - (4)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (4)].map)));
		      Free((yyvsp[(1) - (4)].map));
		  ;}
    break;

  case 392:

/* Line 1455 of yacc.c  */
#line 2518 "lev_comp.y"
    {
		      /* nothing */
		  ;}
    break;

  case 393:

/* Line 1455 of yacc.c  */
#line 2524 "lev_comp.y"
    {
		      add_opvars(splev, "c", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 394:

/* Line 1455 of yacc.c  */
#line 2528 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_RNDCOORD));
		  ;}
    break;

  case 395:

/* Line 1455 of yacc.c  */
#line 2532 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_COORD);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 396:

/* Line 1455 of yacc.c  */
#line 2539 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (4)].map),
                                        SPOVAR_COORD | SPOVAR_ARRAY);
		      vardef_used(vardefs, (yyvsp[(1) - (4)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (4)].map)));
		      Free((yyvsp[(1) - (4)].map));
		  ;}
    break;

  case 397:

/* Line 1455 of yacc.c  */
#line 2549 "lev_comp.y"
    {
		      if ((yyvsp[(2) - (5)].i) < 0 || (yyvsp[(4) - (5)].i) < 0 || (yyvsp[(2) - (5)].i) >= COLNO || (yyvsp[(4) - (5)].i) >= ROWNO)
                          lc_error("Coordinates (%li,%li) out of map range!",
                                   (yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].i));
		      (yyval.i) = SP_COORD_PACK((yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].i));
		  ;}
    break;

  case 398:

/* Line 1455 of yacc.c  */
#line 2556 "lev_comp.y"
    {
		      (yyval.i) = SP_COORD_PACK_RANDOM(0);
		  ;}
    break;

  case 399:

/* Line 1455 of yacc.c  */
#line 2560 "lev_comp.y"
    {
		      (yyval.i) = SP_COORD_PACK_RANDOM((yyvsp[(2) - (3)].i));
		  ;}
    break;

  case 400:

/* Line 1455 of yacc.c  */
#line 2566 "lev_comp.y"
    {
		      (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 401:

/* Line 1455 of yacc.c  */
#line 2570 "lev_comp.y"
    {
		      if (((yyvsp[(1) - (3)].i) & (yyvsp[(3) - (3)].i)))
			  lc_warning("Humidity flag used twice.");
		      (yyval.i) = ((yyvsp[(1) - (3)].i) | (yyvsp[(3) - (3)].i));
		  ;}
    break;

  case 402:

/* Line 1455 of yacc.c  */
#line 2578 "lev_comp.y"
    {
		      /* nothing */
		  ;}
    break;

  case 403:

/* Line 1455 of yacc.c  */
#line 2582 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_REGION);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 404:

/* Line 1455 of yacc.c  */
#line 2589 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (4)].map),
                                        SPOVAR_REGION | SPOVAR_ARRAY);
		      vardef_used(vardefs, (yyvsp[(1) - (4)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (4)].map)));
		      Free((yyvsp[(1) - (4)].map));
		  ;}
    break;

  case 405:

/* Line 1455 of yacc.c  */
#line 2599 "lev_comp.y"
    {
		      long r = SP_REGION_PACK((yyvsp[(2) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(6) - (9)].i), (yyvsp[(8) - (9)].i));

		      if ((yyvsp[(2) - (9)].i) > (yyvsp[(6) - (9)].i) || (yyvsp[(4) - (9)].i) > (yyvsp[(8) - (9)].i))
			  lc_error("Region start > end: (%ld,%ld,%ld,%ld)!",
                                   (yyvsp[(2) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(6) - (9)].i), (yyvsp[(8) - (9)].i));

		      add_opvars(splev, "r", VA_PASS1(r));
		      (yyval.i) = r;
		  ;}
    break;

  case 406:

/* Line 1455 of yacc.c  */
#line 2612 "lev_comp.y"
    {
		      add_opvars(splev, "m", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 407:

/* Line 1455 of yacc.c  */
#line 2616 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_MAPCHAR);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 408:

/* Line 1455 of yacc.c  */
#line 2623 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (4)].map),
                                        SPOVAR_MAPCHAR | SPOVAR_ARRAY);
		      vardef_used(vardefs, (yyvsp[(1) - (4)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (4)].map)));
		      Free((yyvsp[(1) - (4)].map));
		  ;}
    break;

  case 409:

/* Line 1455 of yacc.c  */
#line 2633 "lev_comp.y"
    {
		      if (what_map_char((char) (yyvsp[(1) - (1)].i)) != INVALID_TYPE)
			  (yyval.i) = SP_MAPCHAR_PACK(what_map_char((char) (yyvsp[(1) - (1)].i)), -2);
		      else {
			  lc_error("Unknown map char type '%c'!", (yyvsp[(1) - (1)].i));
			  (yyval.i) = SP_MAPCHAR_PACK(STONE, -2);
		      }
		  ;}
    break;

  case 410:

/* Line 1455 of yacc.c  */
#line 2642 "lev_comp.y"
    {
		      if (what_map_char((char) (yyvsp[(2) - (5)].i)) != INVALID_TYPE)
			  (yyval.i) = SP_MAPCHAR_PACK(what_map_char((char) (yyvsp[(2) - (5)].i)), (yyvsp[(4) - (5)].i));
		      else {
			  lc_error("Unknown map char type '%c'!", (yyvsp[(2) - (5)].i));
			  (yyval.i) = SP_MAPCHAR_PACK(STONE, (yyvsp[(4) - (5)].i));
		      }
		  ;}
    break;

  case 411:

/* Line 1455 of yacc.c  */
#line 2653 "lev_comp.y"
    {
		      add_opvars(splev, "M", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 412:

/* Line 1455 of yacc.c  */
#line 2657 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_MONST);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 413:

/* Line 1455 of yacc.c  */
#line 2664 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (4)].map),
                                        SPOVAR_MONST | SPOVAR_ARRAY);
		      vardef_used(vardefs, (yyvsp[(1) - (4)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (4)].map)));
		      Free((yyvsp[(1) - (4)].map));
		  ;}
    break;

  case 414:

/* Line 1455 of yacc.c  */
#line 2674 "lev_comp.y"
    {
                      long m = get_monster_id((yyvsp[(1) - (1)].map), (char)0);
                      if (m == ERR) {
                          lc_error("Unknown monster \"%s\"!", (yyvsp[(1) - (1)].map));
                          (yyval.i) = -1;
                      } else
                          (yyval.i) = SP_MONST_PACK(m,
                                         def_monsyms[(int) mons[m].mlet].sym);
                      Free((yyvsp[(1) - (1)].map));
                  ;}
    break;

  case 415:

/* Line 1455 of yacc.c  */
#line 2685 "lev_comp.y"
    {
                        if (check_monster_char((char) (yyvsp[(1) - (1)].i)))
                            (yyval.i) = SP_MONST_PACK(-1, (yyvsp[(1) - (1)].i));
                        else {
                            lc_error("Unknown monster class '%c'!", (yyvsp[(1) - (1)].i));
                            (yyval.i) = -1;
                        }
                  ;}
    break;

  case 416:

/* Line 1455 of yacc.c  */
#line 2694 "lev_comp.y"
    {
                      long m = get_monster_id((yyvsp[(4) - (5)].map), (char) (yyvsp[(2) - (5)].i));
                      if (m == ERR) {
                          lc_error("Unknown monster ('%c', \"%s\")!", (yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].map));
                          (yyval.i) = -1;
                      } else
                          (yyval.i) = SP_MONST_PACK(m, (yyvsp[(2) - (5)].i));
                      Free((yyvsp[(4) - (5)].map));
                  ;}
    break;

  case 417:

/* Line 1455 of yacc.c  */
#line 2704 "lev_comp.y"
    {
                      (yyval.i) = -1;
                  ;}
    break;

  case 418:

/* Line 1455 of yacc.c  */
#line 2710 "lev_comp.y"
    {
		      add_opvars(splev, "O", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 419:

/* Line 1455 of yacc.c  */
#line 2714 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_OBJ);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 420:

/* Line 1455 of yacc.c  */
#line 2721 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (4)].map),
                                        SPOVAR_OBJ | SPOVAR_ARRAY);
		      vardef_used(vardefs, (yyvsp[(1) - (4)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (4)].map)));
		      Free((yyvsp[(1) - (4)].map));
		  ;}
    break;

  case 421:

/* Line 1455 of yacc.c  */
#line 2731 "lev_comp.y"
    {
		      long m = get_object_id((yyvsp[(1) - (1)].map), (char)0);
		      if (m == ERR) {
			  lc_error("Unknown object \"%s\"!", (yyvsp[(1) - (1)].map));
			  (yyval.i) = -1;
		      } else
                          /* obj class != 0 to force generation of a specific item */
                          (yyval.i) = SP_OBJ_PACK(m, 1);
                      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 422:

/* Line 1455 of yacc.c  */
#line 2742 "lev_comp.y"
    {
			if (check_object_char((char) (yyvsp[(1) - (1)].i)))
			    (yyval.i) = SP_OBJ_PACK(-1, (yyvsp[(1) - (1)].i));
			else {
			    lc_error("Unknown object class '%c'!", (yyvsp[(1) - (1)].i));
			    (yyval.i) = -1;
			}
		  ;}
    break;

  case 423:

/* Line 1455 of yacc.c  */
#line 2751 "lev_comp.y"
    {
		      long m = get_object_id((yyvsp[(4) - (5)].map), (char) (yyvsp[(2) - (5)].i));
		      if (m == ERR) {
			  lc_error("Unknown object ('%c', \"%s\")!", (yyvsp[(2) - (5)].i), (yyvsp[(4) - (5)].map));
			  (yyval.i) = -1;
		      } else
			  (yyval.i) = SP_OBJ_PACK(m, (yyvsp[(2) - (5)].i));
                      Free((yyvsp[(4) - (5)].map));
		  ;}
    break;

  case 424:

/* Line 1455 of yacc.c  */
#line 2761 "lev_comp.y"
    {
		      (yyval.i) = OBJECT_SPECIAL_CREATE_TYPE_RANDOM;
		  ;}
    break;

  case 425:

/* Line 1455 of yacc.c  */
#line 2765 "lev_comp.y"
    {
  			  (yyval.i) = (yyvsp[(1) - (1)].i);
		  ;}
    break;

  case 426:

/* Line 1455 of yacc.c  */
#line 2771 "lev_comp.y"
    { ;}
    break;

  case 427:

/* Line 1455 of yacc.c  */
#line 2773 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MATH_ADD));
		  ;}
    break;

  case 428:

/* Line 1455 of yacc.c  */
#line 2779 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 429:

/* Line 1455 of yacc.c  */
#line 2783 "lev_comp.y"
    {
		      is_inconstant_number = 1;
		  ;}
    break;

  case 430:

/* Line 1455 of yacc.c  */
#line 2787 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1((yyvsp[(2) - (3)].i)));
		  ;}
    break;

  case 431:

/* Line 1455 of yacc.c  */
#line 2791 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_INT);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		      is_inconstant_number = 1;
		  ;}
    break;

  case 432:

/* Line 1455 of yacc.c  */
#line 2799 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (4)].map),
					SPOVAR_INT | SPOVAR_ARRAY);
		      vardef_used(vardefs, (yyvsp[(1) - (4)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (4)].map)));
		      Free((yyvsp[(1) - (4)].map));
		      is_inconstant_number = 1;
		  ;}
    break;

  case 433:

/* Line 1455 of yacc.c  */
#line 2808 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MATH_ADD));
		  ;}
    break;

  case 434:

/* Line 1455 of yacc.c  */
#line 2812 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MATH_SUB));
		  ;}
    break;

  case 435:

/* Line 1455 of yacc.c  */
#line 2816 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MATH_MUL));
		  ;}
    break;

  case 436:

/* Line 1455 of yacc.c  */
#line 2820 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MATH_DIV));
		  ;}
    break;

  case 437:

/* Line 1455 of yacc.c  */
#line 2824 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_MATH_MOD));
		  ;}
    break;

  case 438:

/* Line 1455 of yacc.c  */
#line 2827 "lev_comp.y"
    { ;}
    break;

  case 439:

/* Line 1455 of yacc.c  */
#line 2831 "lev_comp.y"
    {
		      if (!strcmp("int", (yyvsp[(1) - (1)].map)) || !strcmp("integer", (yyvsp[(1) - (1)].map))) {
			  (yyval.i) = (int)'i';
		      } else
			  lc_error("Unknown function parameter type '%s'", (yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 440:

/* Line 1455 of yacc.c  */
#line 2838 "lev_comp.y"
    {
		      if (!strcmp("str", (yyvsp[(1) - (1)].map)) || !strcmp("string", (yyvsp[(1) - (1)].map))) {
			  (yyval.i) = (int)'s';
		      } else
			  lc_error("Unknown function parameter type '%s'", (yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 441:

/* Line 1455 of yacc.c  */
#line 2847 "lev_comp.y"
    {
		      struct lc_funcdefs_parm *tmp = New(struct lc_funcdefs_parm);

		      if (!curr_function) {
			  lc_error("Function parameters outside function definition.");
		      } else if (!tmp) {
			  lc_error("Could not alloc function params.");
		      } else {
			  long vt = SPOVAR_NULL;

			  tmp->name = strdup((yyvsp[(1) - (3)].map));
			  tmp->parmtype = (char) (yyvsp[(3) - (3)].i);
			  tmp->next = curr_function->params;
			  curr_function->params = tmp;
			  curr_function->n_params++;
			  switch (tmp->parmtype) {
			  case 'i':
                              vt = SPOVAR_INT;
                              break;
			  case 's':
                              vt = SPOVAR_STRING;
                              break;
			  default:
                              lc_error("Unknown func param conversion.");
                              break;
			  }
			  vardefs = add_vardef_type( vardefs, (yyvsp[(1) - (3)].map), vt);
		      }
		      Free((yyvsp[(1) - (3)].map));
		  ;}
    break;

  case 446:

/* Line 1455 of yacc.c  */
#line 2888 "lev_comp.y"
    {
			      (yyval.i) = (int)'i';
			  ;}
    break;

  case 447:

/* Line 1455 of yacc.c  */
#line 2892 "lev_comp.y"
    {
			      (yyval.i) = (int)'s';
			  ;}
    break;

  case 448:

/* Line 1455 of yacc.c  */
#line 2899 "lev_comp.y"
    {
			      char tmpbuf[2];
			      tmpbuf[0] = (char) (yyvsp[(1) - (1)].i);
			      tmpbuf[1] = '\0';
			      (yyval.map) = strdup(tmpbuf);
			  ;}
    break;

  case 449:

/* Line 1455 of yacc.c  */
#line 2906 "lev_comp.y"
    {
			      long len = strlen( (yyvsp[(1) - (3)].map) );
			      char *tmp = (char *) alloc(len + 2);
			      sprintf(tmp, "%c%s", (char) (yyvsp[(3) - (3)].i), (yyvsp[(1) - (3)].map) );
			      Free( (yyvsp[(1) - (3)].map) );
			      (yyval.map) = tmp;
			  ;}
    break;

  case 450:

/* Line 1455 of yacc.c  */
#line 2916 "lev_comp.y"
    {
			      (yyval.map) = strdup("");
			  ;}
    break;

  case 451:

/* Line 1455 of yacc.c  */
#line 2920 "lev_comp.y"
    {
			      char *tmp = strdup( (yyvsp[(1) - (1)].map) );
			      Free( (yyvsp[(1) - (1)].map) );
			      (yyval.map) = tmp;
			  ;}
    break;

  case 452:

/* Line 1455 of yacc.c  */
#line 2928 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_POINT));
		  ;}
    break;

  case 453:

/* Line 1455 of yacc.c  */
#line 2932 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_RECT));
		  ;}
    break;

  case 454:

/* Line 1455 of yacc.c  */
#line 2936 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_FILLRECT));
		  ;}
    break;

  case 455:

/* Line 1455 of yacc.c  */
#line 2940 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_LINE));
		  ;}
    break;

  case 456:

/* Line 1455 of yacc.c  */
#line 2944 "lev_comp.y"
    {
		      /* randline (x1,y1),(x2,y2), roughness */
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_RNDLINE));
		  ;}
    break;

  case 457:

/* Line 1455 of yacc.c  */
#line 2949 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(W_ANY, SPO_SEL_GROW));
		  ;}
    break;

  case 458:

/* Line 1455 of yacc.c  */
#line 2953 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((yyvsp[(3) - (6)].i), SPO_SEL_GROW));
		  ;}
    break;

  case 459:

/* Line 1455 of yacc.c  */
#line 2957 "lev_comp.y"
    {
		      add_opvars(splev, "iio",
			     VA_PASS3((yyvsp[(3) - (6)].i), SPOFILTER_PERCENT, SPO_SEL_FILTER));
		  ;}
    break;

  case 460:

/* Line 1455 of yacc.c  */
#line 2962 "lev_comp.y"
    {
		      add_opvars(splev, "io",
			       VA_PASS2(SPOFILTER_SELECTION, SPO_SEL_FILTER));
		  ;}
    break;

  case 461:

/* Line 1455 of yacc.c  */
#line 2967 "lev_comp.y"
    {
		      add_opvars(splev, "io",
				 VA_PASS2(SPOFILTER_MAPCHAR, SPO_SEL_FILTER));
		  ;}
    break;

  case 462:

/* Line 1455 of yacc.c  */
#line 2972 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_FLOOD));
		  ;}
    break;

  case 463:

/* Line 1455 of yacc.c  */
#line 2976 "lev_comp.y"
    {
		      add_opvars(splev, "oio",
				 VA_PASS3(SPO_COPY, 1, SPO_SEL_ELLIPSE));
		  ;}
    break;

  case 464:

/* Line 1455 of yacc.c  */
#line 2981 "lev_comp.y"
    {
		      add_opvars(splev, "oio",
				 VA_PASS3(SPO_COPY, (yyvsp[(7) - (8)].i), SPO_SEL_ELLIPSE));
		  ;}
    break;

  case 465:

/* Line 1455 of yacc.c  */
#line 2986 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2(1, SPO_SEL_ELLIPSE));
		  ;}
    break;

  case 466:

/* Line 1455 of yacc.c  */
#line 2990 "lev_comp.y"
    {
		      add_opvars(splev, "io", VA_PASS2((yyvsp[(9) - (10)].i), SPO_SEL_ELLIPSE));
		  ;}
    break;

  case 467:

/* Line 1455 of yacc.c  */
#line 2994 "lev_comp.y"
    {
		      add_opvars(splev, "iio",
				 VA_PASS3((yyvsp[(9) - (14)].i), (yyvsp[(3) - (14)].i), SPO_SEL_GRADIENT));
		  ;}
    break;

  case 468:

/* Line 1455 of yacc.c  */
#line 2999 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_COMPLEMENT));
		  ;}
    break;

  case 469:

/* Line 1455 of yacc.c  */
#line 3003 "lev_comp.y"
    {
		      check_vardef_type(vardefs, (yyvsp[(1) - (1)].map), SPOVAR_SEL);
		      vardef_used(vardefs, (yyvsp[(1) - (1)].map));
		      add_opvars(splev, "v", VA_PASS1((yyvsp[(1) - (1)].map)));
		      Free((yyvsp[(1) - (1)].map));
		  ;}
    break;

  case 470:

/* Line 1455 of yacc.c  */
#line 3010 "lev_comp.y"
    {
		      /* nothing */
		  ;}
    break;

  case 471:

/* Line 1455 of yacc.c  */
#line 3016 "lev_comp.y"
    {
		      /* nothing */
		  ;}
    break;

  case 472:

/* Line 1455 of yacc.c  */
#line 3020 "lev_comp.y"
    {
		      add_opvars(splev, "o", VA_PASS1(SPO_SEL_ADD));
		  ;}
    break;

  case 473:

/* Line 1455 of yacc.c  */
#line 3026 "lev_comp.y"
    {
		      add_opvars(splev, "iio",
				 VA_PASS3((yyvsp[(1) - (1)].dice).num, (yyvsp[(1) - (1)].dice).die, SPO_DICE));
		  ;}
    break;

  case 479:

/* Line 1455 of yacc.c  */
#line 3042 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 480:

/* Line 1455 of yacc.c  */
#line 3046 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 481:

/* Line 1455 of yacc.c  */
#line 3050 "lev_comp.y"
    {
		      add_opvars(splev, "i", VA_PASS1((yyvsp[(1) - (1)].i)));
		  ;}
    break;

  case 482:

/* Line 1455 of yacc.c  */
#line 3054 "lev_comp.y"
    {
		      /* nothing */
		  ;}
    break;

  case 491:

/* Line 1455 of yacc.c  */
#line 3076 "lev_comp.y"
    {
			(yyval.lregn) = (yyvsp[(1) - (1)].lregn);
		  ;}
    break;

  case 492:

/* Line 1455 of yacc.c  */
#line 3080 "lev_comp.y"
    {
			if ((yyvsp[(3) - (10)].i) <= 0 || (yyvsp[(3) - (10)].i) >= COLNO)
			    lc_error(
                          "Region (%ld,%ld,%ld,%ld) out of level range (x1)!",
                                     (yyvsp[(3) - (10)].i), (yyvsp[(5) - (10)].i), (yyvsp[(7) - (10)].i), (yyvsp[(9) - (10)].i));
			else if ((yyvsp[(5) - (10)].i) < 0 || (yyvsp[(5) - (10)].i) >= ROWNO)
			    lc_error(
                          "Region (%ld,%ld,%ld,%ld) out of level range (y1)!",
                                     (yyvsp[(3) - (10)].i), (yyvsp[(5) - (10)].i), (yyvsp[(7) - (10)].i), (yyvsp[(9) - (10)].i));
			else if ((yyvsp[(7) - (10)].i) <= 0 || (yyvsp[(7) - (10)].i) >= COLNO)
			    lc_error(
                          "Region (%ld,%ld,%ld,%ld) out of level range (x2)!",
                                     (yyvsp[(3) - (10)].i), (yyvsp[(5) - (10)].i), (yyvsp[(7) - (10)].i), (yyvsp[(9) - (10)].i));
			else if ((yyvsp[(9) - (10)].i) < 0 || (yyvsp[(9) - (10)].i) >= ROWNO)
			    lc_error(
                          "Region (%ld,%ld,%ld,%ld) out of level range (y2)!",
                                     (yyvsp[(3) - (10)].i), (yyvsp[(5) - (10)].i), (yyvsp[(7) - (10)].i), (yyvsp[(9) - (10)].i));
			(yyval.lregn).x1 = (yyvsp[(3) - (10)].i);
			(yyval.lregn).y1 = (yyvsp[(5) - (10)].i);
			(yyval.lregn).x2 = (yyvsp[(7) - (10)].i);
			(yyval.lregn).y2 = (yyvsp[(9) - (10)].i);
			(yyval.lregn).area = 1;
		  ;}
    break;

  case 493:

/* Line 1455 of yacc.c  */
#line 3106 "lev_comp.y"
    {
/* This series of if statements is a hack for MSC 5.1.  It seems that its
   tiny little brain cannot compile if these are all one big if statement. */
			if ((yyvsp[(2) - (9)].i) < 0 || (yyvsp[(2) - (9)].i) > (int) max_x_map)
			    lc_error(
                            "Region (%ld,%ld,%ld,%ld) out of map range (x1)!",
                                     (yyvsp[(2) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(6) - (9)].i), (yyvsp[(8) - (9)].i));
			else if ((yyvsp[(4) - (9)].i) < 0 || (yyvsp[(4) - (9)].i) > (int) max_y_map)
			    lc_error(
                            "Region (%ld,%ld,%ld,%ld) out of map range (y1)!",
                                     (yyvsp[(2) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(6) - (9)].i), (yyvsp[(8) - (9)].i));
			else if ((yyvsp[(6) - (9)].i) < 0 || (yyvsp[(6) - (9)].i) > (int) max_x_map)
			    lc_error(
                            "Region (%ld,%ld,%ld,%ld) out of map range (x2)!",
                                     (yyvsp[(2) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(6) - (9)].i), (yyvsp[(8) - (9)].i));
			else if ((yyvsp[(8) - (9)].i) < 0 || (yyvsp[(8) - (9)].i) > (int) max_y_map)
			    lc_error(
                            "Region (%ld,%ld,%ld,%ld) out of map range (y2)!",
                                     (yyvsp[(2) - (9)].i), (yyvsp[(4) - (9)].i), (yyvsp[(6) - (9)].i), (yyvsp[(8) - (9)].i));
			(yyval.lregn).area = 0;
			(yyval.lregn).x1 = (yyvsp[(2) - (9)].i);
			(yyval.lregn).y1 = (yyvsp[(4) - (9)].i);
			(yyval.lregn).x2 = (yyvsp[(6) - (9)].i);
			(yyval.lregn).y2 = (yyvsp[(8) - (9)].i);
		  ;}
    break;



/* Line 1455 of yacc.c  */
#line 7026 "lev_comp.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#if !defined(yyoverflow) || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}



/* Line 1675 of yacc.c  */
#line 3134 "lev_comp.y"


/*lev_comp.y*/


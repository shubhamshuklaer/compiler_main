/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2013 Free Software Foundation, Inc.

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
#define YYBISON_VERSION "3.0.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 1 "parser.y" /* yacc.c:339  */

	#define YYDEBUG 1
	#define MAX_CHILD 9
	#define MAX_LEVELS 30
	
	#include <stdio.h>
	#include <iostream>
	#include "sym_table.h"
	#include <string.h>
    #include <graphviz/cgraph.h>
	#include <vector>
	#include <fstream>
	#include <algorithm>
	using namespace std;
    /*#include <graphviz/ingraphs.h>*/

	#include "header.h"
	int yylex(void);
	void yyerror(const char *);

	bool levels[MAX_LEVELS];

	struct node{
		struct node *child[MAX_CHILD], *left_sib, *right_sib;
		char *name;
		int cur_childs;
        int graph_node_id;
        char *type;
        int var_type;
	};

	struct node *root;
	
	struct node *mk_node(const char *name);
	void mk_child(node *par, node *ch);
	void mk_sibling(node *from, node *to, bool right);

	void printtree(node *root, int level);
	void type_check(node *root, int level);
	
	node *init_tree();
    
    Agraph_t *syntax_graph;
    int node_id,edge_id,creation_id;

    Agnode_t * make_graph_node(node *);
	string main_func_name="__main__";
	string func_name=main_func_name;
	string garbage_dt="garbage";
	string data_type=garbage_dt;
	struct node* func_terminator_node;

	string cur_scope = main_func_name;

	void insert_var_in_symbol_table(string func_name,string var_name,string data_type,int var_type=0,int arr_size=0);
	sym_table<func_elem,func_def> *gst_obj;
	ofstream sym_tab_out("sym_tab_out.txt");
	void get_symbol_table_data();
	// #define YYSTYPE struct node *

#line 127 "parser.cpp" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "parser.hpp".  */
#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    IF = 258,
    ELSE = 259,
    WHILE = 260,
    DO = 261,
    FOR = 262,
    AND = 263,
    OR = 264,
    NOT_1 = 265,
    TRUE_1 = 266,
    FALSE_1 = 267,
    INT = 268,
    LONG = 269,
    CHAR = 270,
    FLOAT = 271,
    DOUBLE = 272,
    ADD = 273,
    SUB = 274,
    MULT = 275,
    DIV = 276,
    EXP = 277,
    MOD = 278,
    INC = 279,
    DEC = 280,
    BIN_NOT = 281,
    BIN_AND = 282,
    BIN_OR = 283,
    BIN_XOR = 284,
    BIN_LEFT = 285,
    BIN_RIGHT = 286,
    BIN_AND_ASSIGN = 287,
    BIN_IOR_ASSIGN = 288,
    BIN_XOR_ASSIGN = 289,
    ADD_ASSIGN = 290,
    SUB_ASSIGN = 291,
    MULT_ASSIGN = 292,
    DIV_ASSIGN = 293,
    MOD_ASSIGN = 294,
    LEFT_ASSIGN = 295,
    RIGHT_ASSIGN = 296,
    NUM = 297,
    IDENT = 298,
    VAR = 299,
    POINTER = 300,
    DREF = 301,
    ASSIGN = 302,
    TERMINATOR = 303,
    STRING = 304,
    CHARACTER = 305,
    OP = 306,
    CP = 307,
    CB = 308,
    OB = 309,
    OCB = 310,
    CCB = 311,
    EQ = 312,
    NOTEQ = 313,
    GT = 314,
    LT = 315,
    GE = 316,
    LE = 317,
    COMMENT = 318,
    MULTI_COMMENT = 319,
    DEFINE = 320,
    IFDEF = 321,
    IFNDEF = 322,
    FUNCTION = 323,
    COMMA = 324,
    PRINT = 325,
    SCAN = 326,
    RETURN = 327,
    LTGT = 328
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 62 "parser.y" /* yacc.c:355  */

	struct node *entry;
	char *terminal_value;

#line 246 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 261 "parser.cpp" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  75
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   817

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  74
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  45
/* YYNRULES -- Number of rules.  */
#define YYNRULES  147
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   328

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
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
      65,    66,    67,    68,    69,    70,    71,    72,    73
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   214,   214,   221,   226,   230,   239,   244,   252,   261,
     274,   290,   298,   306,   317,   322,   326,   335,   340,   345,
     350,   355,   360,   367,   383,   406,   427,   434,   438,   442,
     449,   468,   476,   499,   507,   529,   537,   544,   552,   560,
     566,   573,   580,   586,   594,   601,   608,   615,   623,   631,
     635,   639,   644,   649,   654,   673,   680,   689,   694,   699,
     705,   711,   717,   725,   733,   745,   757,   765,   772,   780,
     787,   791,   798,   806,   811,   816,   821,   826,   834,   842,
     853,   865,   875,   879,   886,   898,   907,   914,   920,   927,
     933,   939,   950,   957,   964,   970,   975,   979,   983,   995,
    1006,  1015,  1022,  1029,  1036,  1043,  1049,  1055,  1061,  1067,
    1072,  1077,  1087,  1092,  1097,  1102,  1107,  1112,  1117,  1125,
    1130,  1138,  1146,  1151,  1159,  1164,  1169,  1174,  1179,  1184,
    1192,  1197,  1205,  1210,  1215,  1220,  1225,  1233,  1241,  1246,
    1251,  1256,  1261,  1266,  1271,  1279,  1284,  1289
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "DO", "FOR",
  "AND", "OR", "NOT_1", "TRUE_1", "FALSE_1", "INT", "LONG", "CHAR",
  "FLOAT", "DOUBLE", "ADD", "SUB", "MULT", "DIV", "EXP", "MOD", "INC",
  "DEC", "BIN_NOT", "BIN_AND", "BIN_OR", "BIN_XOR", "BIN_LEFT",
  "BIN_RIGHT", "BIN_AND_ASSIGN", "BIN_IOR_ASSIGN", "BIN_XOR_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "NUM", "IDENT", "VAR", "POINTER", "DREF",
  "ASSIGN", "TERMINATOR", "STRING", "CHARACTER", "OP", "CP", "CB", "OB",
  "OCB", "CCB", "EQ", "NOTEQ", "GT", "LT", "GE", "LE", "COMMENT",
  "MULTI_COMMENT", "DEFINE", "IFDEF", "IFNDEF", "FUNCTION", "COMMA",
  "PRINT", "SCAN", "RETURN", "LTGT", "$accept", "super_block",
  "start_block", "comment_block", "defination_block", "const_block",
  "block", "general_block", "if_else_block", "if_condition", "loop_block",
  "while_loop_block", "while_condition", "do_while_loop_block",
  "do_while_condition", "for_loop_block", "for_initialization",
  "for_condition", "for_update", "function_def_block", "ident",
  "argument_list_block", "general_stmt", "function_call_block",
  "function_var_list", "declaration_block", "var_list", "data_type",
  "var_block", "array_block", "num", "ass_var_block", "assignment_block",
  "expr", "conditional_expr", "arith_condition_op", "bit_condition_op",
  "bit_unary_condition_op", "fixed_condition", "arith_binary_op",
  "arith_unary_op", "bit_binary_op", "bit_unary_op", "arith_assgn_op",
  "bit_assgn_op", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328
};
# endif

#define YYPACT_NINF -167

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-167)))

#define YYTABLE_NINF -107

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     330,   256,   -29,     6,   -50,     7,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,    11,  -167,  -167,  -167,
    -167,  -167,   666,  -167,  -167,    20,    22,    25,    30,   679,
      71,   679,    67,  -167,   256,   256,   266,  -167,  -167,   478,
     478,  -167,  -167,  -167,   404,   478,   266,    29,   -15,    26,
     713,    44,   219,    47,   308,  -167,   157,  -167,   679,   679,
     624,    45,   679,    50,    51,    34,    23,    53,  -167,    68,
     679,   266,    61,    83,    88,  -167,   478,   256,  -167,   404,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   308,   308,  -167,  -167,   404,  -167,  -167,   308,
     308,  -167,  -167,   -48,    69,   679,  -167,  -167,  -167,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,   666,   308,   308,   666,
     666,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,   679,   679,  -167,  -167,  -167,  -167,    89,  -167,    91,
    -167,    84,  -167,  -167,  -167,    60,   679,   -32,   754,   -20,
      71,    93,    77,  -167,   266,  -167,   551,   551,   202,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,   111,   -15,
     -15,   102,  -167,  -167,  -167,  -167,  -167,  -167,  -167,  -167,
    -167,  -167,   104,   105,   156,   770,   115,  -167,  -167,    45,
     -16,  -167,    45,   -14,  -167,   679,   308,   308,   109,   110,
     116,   -15,  -167,   119,  -167,  -167,  -167,   624,   624,   118,
     731,  -167,  -167,    45,  -167,  -167,    45,  -167,  -167,  -167,
    -167,  -167,   130,   117,  -167,   133,   134,   679,   121,   124,
     754,   127,    71,  -167,  -167,   624,   202,   196,  -167,   152,
    -167,   158,   731,   143,   731,   154,   165,  -167,    -1,   185,
     624,  -167,   731,  -167,   731,  -167,   624,  -167,  -167,   179,
    -167,  -167,   182,  -167,  -167
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,   121,   122,   123,    73,
      77,    76,    74,    75,   137,    12,     0,    78,    79,    83,
      11,    13,   106,     6,     7,     0,     0,     0,     0,   106,
       0,   106,     0,     2,     0,     0,    96,     4,    15,     0,
       0,    28,    29,    27,     0,     0,    97,     0,     0,    82,
      95,     0,   109,     0,   106,   110,     0,    21,   106,   106,
       0,     0,   106,     0,     0,     0,     0,     0,    55,     0,
     106,    95,     0,     0,     0,     1,     0,     0,    20,     0,
       3,   124,   125,   126,   127,   128,   129,   132,   133,   134,
     135,   136,   106,   106,    19,    18,     0,    14,    17,   106,
     106,    59,    68,    70,    72,   106,   145,   146,   147,   138,
     139,   140,   141,   142,   143,   144,   106,   106,   106,   106,
     106,    60,   119,   120,   112,   113,   114,   115,   116,   117,
     118,   106,   106,    61,   111,   105,    94,     0,    26,     0,
      31,     0,   130,   131,    43,     0,   106,     0,     0,     0,
       0,     0,    67,    91,   100,     8,     0,     0,    58,    62,
      63,    64,     5,    16,   101,   102,   103,   104,     0,     0,
       0,     0,    88,    85,    92,    93,    89,    86,    90,    87,
     107,   108,     0,     0,     0,     0,     0,    44,    42,     0,
       0,    39,     0,     0,    65,   106,   106,   106,     0,     0,
       0,     0,    81,     0,    69,    71,    84,     0,     0,     0,
      53,    35,    40,     0,    36,    41,     0,    66,    98,    99,
       9,    10,     0,    57,    80,     0,     0,   106,     0,    49,
       0,    50,     0,    37,    38,     0,    58,    23,    30,     0,
      33,     0,    53,    51,    53,    52,     0,    56,     0,     0,
       0,    45,    53,    46,    53,    54,     0,    25,    32,     0,
      47,    48,     0,    34,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -167,  -167,    24,    85,   206,   -46,   -37,   -25,    -4,  -167,
    -167,  -167,  -167,  -167,  -167,  -167,  -166,  -167,  -105,   -30,
    -167,     9,  -167,    -5,    48,  -167,  -124,  -157,   -45,  -167,
    -167,   -18,   -22,    58,     2,  -167,  -167,  -167,  -167,   -28,
    -100,   -19,  -167,  -167,  -167
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    76,    35,    36,    37,    38,    39,   137,
      40,    41,   139,    42,   239,    43,   146,   186,   228,    44,
      69,   200,    45,    46,   151,    47,   102,    48,    49,   104,
     203,    50,    51,    52,    53,   131,   132,    54,    55,   117,
     150,   118,    56,   119,   120
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      63,   201,     2,   103,    79,    60,   168,    97,    92,    78,
     135,    71,    73,    71,    94,    95,   188,    93,    99,   155,
      98,   169,    58,   211,    64,    57,   214,   100,   191,    17,
      18,    72,   212,    74,   215,   141,    71,   189,   136,   149,
      71,    71,   163,   148,    71,   204,   205,   233,   190,   192,
     234,    78,    71,   213,   256,   216,   147,    59,    61,    80,
     138,   140,    62,    65,   152,    66,    79,    75,    67,   142,
     143,    78,    64,    68,    71,    71,    15,   101,   156,   201,
     105,    71,    71,    20,    21,    34,    34,    71,    16,    17,
      18,    19,   121,   144,   172,   133,   145,   176,   178,    71,
      71,   162,   153,   154,    17,    18,    19,   171,   157,   159,
     232,   145,   134,    71,    71,    17,    18,    19,   173,   158,
      34,   177,   179,    63,   103,   103,   196,   185,    71,    96,
     243,   160,   193,   180,   181,   197,   161,   251,   170,   253,
     184,   182,   232,   183,   232,   194,   195,   260,   187,   261,
     164,   165,   232,   202,   232,   206,   223,   166,   167,   207,
     208,   209,    34,   210,    96,   220,   221,   149,   222,   227,
     149,   148,   224,   241,   148,   174,   175,    71,    71,    71,
     198,   199,   225,   226,   147,   235,   236,   147,   231,   237,
     238,   149,   230,   242,   149,   148,   244,   152,   148,    15,
     248,    17,    18,    19,   249,   229,    20,    21,   147,    71,
     246,   147,   252,   250,   245,     9,    10,    11,    12,    13,
     231,   255,   231,   254,   230,   259,   230,   122,   123,   240,
     231,   262,   231,   258,   230,   263,   230,   229,   264,   229,
      77,    34,    34,   217,   257,   247,     0,   229,     0,   229,
       0,     0,     0,     0,   218,   219,   -22,     1,     0,     2,
       0,     3,     4,     5,  -106,  -106,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,   124,   125,   126,   127,
     128,   129,    14,     0,    81,    82,    83,    84,    85,    86,
       0,     0,   130,    87,    88,    89,    90,    91,    15,    16,
      17,    18,    19,     0,  -106,    20,    21,    22,     0,     0,
       0,     0,   -22,  -106,  -106,  -106,  -106,  -106,  -106,    23,
      24,    25,    26,    27,    28,     0,    29,    30,    31,  -106,
     -22,     1,     0,     2,    14,     3,     4,     5,  -106,  -106,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
      15,    16,    17,    18,    19,     0,    14,    20,    21,    70,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    15,    16,    17,    18,    19,     0,  -106,    20,
      21,    22,     0,     0,     0,     0,     0,  -106,  -106,  -106,
    -106,  -106,  -106,    23,    24,    25,    26,    27,    28,     0,
      29,    30,    31,  -106,   -22,     1,     0,     2,     0,     3,
       4,     5,  -106,  -106,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
      19,     0,  -106,    20,    21,    22,     0,     0,     0,     0,
     -22,  -106,  -106,  -106,  -106,  -106,  -106,    23,    24,     0,
       0,     0,    28,     0,    29,    30,    31,  -106,   -22,     1,
       0,     2,     0,     3,     4,     5,  -106,  -106,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
       0,     0,     0,     0,    14,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
      15,    16,    17,    18,    19,     0,  -106,    20,    21,    22,
       0,     0,     0,     0,   -22,  -106,  -106,  -106,  -106,  -106,
    -106,    23,    24,     0,     0,     0,     0,     0,    29,    30,
      31,  -106,     1,     0,     2,     0,     3,     4,     5,  -106,
    -106,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,     0,     0,    14,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    15,    16,    17,    18,    19,     0,  -106,
      20,    21,    22,     0,     0,     0,     0,   -22,  -106,  -106,
    -106,  -106,  -106,  -106,    23,    24,    25,    26,    27,    28,
       0,    29,    30,    31,  -106,     1,     0,     2,     0,     3,
       4,     5,  -106,  -106,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,     0,     0,
      14,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    15,    16,    17,    18,
      19,     0,  -106,    20,    21,    22,     6,     7,     8,     0,
     -22,  -106,  -106,  -106,  -106,  -106,  -106,    23,    24,     6,
       7,     8,    14,     0,    29,    30,    31,  -106,     0,     0,
       0,     0,     0,     0,     0,    14,     0,     0,    15,    16,
      17,    18,    19,     0,     0,    20,    21,    22,     0,     0,
       0,    15,    16,    17,    18,    19,     0,     0,    20,    21,
      70,    81,    82,    83,    84,    85,    86,     0,     0,     0,
      87,    88,    89,    90,    91,   106,   107,   108,   109,   110,
     111,   112,   113,   114,   115,   142,   143,     0,     0,     0,
     116,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    16,    17,    18,    19,   142,   143,
       0,     0,   145,     0,     0,     0,   106,   107,   108,   109,
     110,   111,   112,   113,   114,   115,     0,     0,     0,     0,
       0,   116,   106,   107,   108,   109,   110,   111,   112,   113,
     114,   115,     0,     0,     0,     0,     0,   116
};

static const yytype_int16 yycheck[] =
{
      22,   158,     3,    48,    34,    55,    54,    44,    36,    34,
      56,    29,    30,    31,    39,    40,    48,    36,    46,    65,
      45,    69,    51,   189,    22,     1,   192,    46,    48,    44,
      45,    29,    48,    31,    48,    60,    54,    69,    56,    61,
      58,    59,    79,    61,    62,   169,   170,   213,   148,    69,
     216,    76,    70,    69,    55,    69,    61,    51,    51,    35,
      58,    59,    51,    43,    62,    43,    96,     0,    43,    24,
      25,    96,    70,    43,    92,    93,    42,    48,    55,   236,
      54,    99,   100,    49,    50,     0,     1,   105,    43,    44,
      45,    46,    48,    48,   116,    48,    51,   119,   120,   117,
     118,    77,    52,    52,    44,    45,    46,   105,    55,    48,
     210,    51,    54,   131,   132,    44,    45,    46,   116,    51,
      35,   119,   120,   145,   169,   170,   154,   145,   146,    44,
     230,    48,   150,   131,   132,   154,    48,   242,    69,   244,
      56,    52,   242,    52,   244,    52,    69,   252,   146,   254,
      92,    93,   252,    42,   254,    53,   201,    99,   100,    55,
      55,     5,    77,    48,    79,    56,    56,   189,    52,    51,
     192,   189,    53,    52,   192,   117,   118,   195,   196,   197,
     156,   157,   207,   208,   189,    55,    69,   192,   210,    56,
      56,   213,   210,    69,   216,   213,    69,   195,   216,    42,
       4,    44,    45,    46,    52,   210,    49,    50,   213,   227,
     235,   216,    69,    55,   232,    13,    14,    15,    16,    17,
     242,    56,   244,    69,   242,   250,   244,     8,     9,   227,
     252,   256,   254,    48,   252,    56,   254,   242,    56,   244,
      34,   156,   157,   195,   248,   236,    -1,   252,    -1,   254,
      -1,    -1,    -1,    -1,   196,   197,     0,     1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    57,    58,    59,    60,
      61,    62,    26,    -1,    18,    19,    20,    21,    22,    23,
      -1,    -1,    73,    27,    28,    29,    30,    31,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    65,    66,    67,    68,    -1,    70,    71,    72,    73,
       0,     1,    -1,     3,    26,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      42,    43,    44,    45,    46,    -1,    26,    49,    50,    51,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,    72,    73,     0,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    68,    -1,    70,    71,    72,    73,     0,     1,
      -1,     3,    -1,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    26,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    70,    71,
      72,    73,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    65,    66,    67,    68,
      -1,    70,    71,    72,    73,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    10,    11,    12,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    10,
      11,    12,    26,    -1,    70,    71,    72,    73,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    -1,    49,    50,    51,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    -1,    -1,    49,    50,
      51,    18,    19,    20,    21,    22,    23,    -1,    -1,    -1,
      27,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    24,    25,    -1,    -1,    -1,
      47,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    43,    44,    45,    46,    24,    25,
      -1,    -1,    51,    -1,    -1,    -1,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,
      -1,    47,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     5,     6,     7,    10,    11,    12,    13,
      14,    15,    16,    17,    26,    42,    43,    44,    45,    46,
      49,    50,    51,    63,    64,    65,    66,    67,    68,    70,
      71,    72,    75,    76,    77,    78,    79,    80,    81,    82,
      84,    85,    87,    89,    93,    96,    97,    99,   101,   102,
     105,   106,   107,   108,   111,   112,   116,    76,    51,    51,
      55,    51,    51,   106,   108,    43,    43,    43,    43,    94,
      51,   105,   108,   105,   108,     0,    77,    78,    81,    93,
      76,    18,    19,    20,    21,    22,    23,    27,    28,    29,
      30,    31,   113,   115,    81,    81,    77,    80,    81,   113,
     115,    48,   100,   102,   103,    54,    32,    33,    34,    35,
      36,    37,    38,    39,    40,    41,    47,   113,   115,   117,
     118,    48,     8,     9,    57,    58,    59,    60,    61,    62,
      73,   109,   110,    48,   107,    79,   105,    83,   108,    86,
     108,    81,    24,    25,    48,    51,    90,    97,   105,   106,
     114,    98,   108,    52,    52,    79,    55,    55,    51,    48,
      48,    48,    76,    80,   107,   107,   107,   107,    54,    69,
      69,   108,   106,   108,   107,   107,   106,   108,   106,   108,
     108,   108,    52,    52,    56,   105,    91,   108,    48,    69,
     114,    48,    69,   105,    52,    69,   113,   115,    76,    76,
      95,   101,    42,   104,   100,   100,    53,    55,    55,     5,
      48,    90,    48,    69,    90,    48,    69,    98,   107,   107,
      56,    56,    52,   102,    53,    81,    81,    51,    92,    97,
     105,   106,   114,    90,    90,    55,    69,    56,    56,    88,
     108,    52,    69,   114,    69,   105,    81,    95,     4,    52,
      55,    92,    69,    92,    69,    56,    55,    82,    48,    81,
      92,    92,    81,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    74,    75,    76,    76,    76,    77,    77,    78,    78,
      78,    79,    79,    79,    80,    80,    80,    81,    81,    81,
      81,    81,    81,    82,    82,    82,    83,    84,    84,    84,
      85,    86,    87,    88,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    92,    92,    92,    92,    92,
      92,    92,    92,    92,    93,    94,    95,    95,    95,    96,
      96,    96,    96,    96,    96,    97,    98,    98,    99,   100,
     100,   100,   100,   101,   101,   101,   101,   101,   102,   102,
     103,   104,   105,   105,   105,   106,   106,   106,   106,   106,
     106,   106,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   108,   108,   108,
     108,   108,   109,   109,   109,   109,   109,   109,   109,   110,
     110,   111,   112,   112,   113,   113,   113,   113,   113,   113,
     114,   114,   115,   115,   115,   115,   115,   116,   117,   117,
     117,   117,   117,   117,   117,   118,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     3,     5,
       5,     1,     1,     1,     2,     1,     3,     2,     2,     2,
       2,     2,     0,     7,    11,     9,     1,     1,     1,     1,
       7,     1,     9,     1,    10,     3,     3,     4,     4,     2,
       3,     3,     2,     1,     1,     3,     3,     4,     4,     1,
       1,     2,     2,     0,     8,     1,     4,     2,     0,     2,
       2,     2,     3,     3,     3,     4,     3,     1,     2,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       4,     1,     1,     1,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     1,     1,     1,     5,     5,
       3,     3,     3,     3,     3,     2,     0,     3,     3,     1,
       1,     2,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
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
  int yytoken = 0;
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

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
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
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 214 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = root;
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 221 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 226 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 1673 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 230 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 239 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("comment_block");	
							(yyvsp[0].entry) = mk_node("COMMENT");		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1694 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 244 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("comment_block");	
							(yyvsp[0].entry) = mk_node("MULTI_COMMENT");		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1704 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 252 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("defination_block");	
							(yyvsp[-2].entry) = mk_node("DEFINE");			
							(yyvsp[-1].entry) = mk_node("IDENT");		
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 1718 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 262 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("defination_block");
							(yyvsp[-4].entry) = mk_node("IFDEF");
							(yyvsp[-3].entry) = mk_node("IDENT");
							(yyvsp[-2].entry) = mk_node("OCB");
							(yyvsp[0].entry) = mk_node("CCB");
							mk_child((yyval.entry), (yyvsp[-4].entry)); 
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 275 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("defination_block");
							(yyvsp[-4].entry) = mk_node("IFNDEF");
							(yyvsp[-3].entry) = mk_node("IDENT");
							(yyvsp[-2].entry) = mk_node("OCB");
							(yyvsp[0].entry) = mk_node("CCB");
							mk_child((yyval.entry), (yyvsp[-4].entry)); 
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1752 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 290 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("STRING");		
							mk_child((yyvsp[0].entry), temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							strcpy((yyval.entry)->type, "string");
						}
#line 1765 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 298 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("NUM");
							mk_child((yyvsp[0].entry), temp);		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							strcpy((yyval.entry)->type, "int");
						}
#line 1778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 306 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("CHARACTER");		
							mk_child((yyvsp[0].entry), temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							strcpy((yyval.entry)->type, "char");
						}
#line 1791 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 317 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1801 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 322 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 326 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 											
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1821 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 335 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1831 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 340 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 345 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1851 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 350 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1861 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 355 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("error");
							mk_child((yyval.entry), (yyvsp[0].entry));
							yyclearin;
						}
#line 1871 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 360 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("/general_block");
						}
#line 1879 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 367 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("if_else_block");				
							(yyvsp[-6].entry) = mk_node("IF");			
							(yyvsp[-5].entry) = mk_node("OP");			
							(yyvsp[-3].entry) = mk_node("CP");			
							(yyvsp[-2].entry) = mk_node("OCB");			
							(yyvsp[0].entry) = mk_node("CCB");			
							mk_child((yyval.entry), (yyvsp[-6].entry)); 
							mk_child((yyval.entry), (yyvsp[-5].entry)); 
							mk_child((yyval.entry), (yyvsp[-4].entry)); 
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 1900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 383 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("if_else_block");				
							(yyvsp[-10].entry) = mk_node("IF");			
							(yyvsp[-9].entry) = mk_node("OP");			
							(yyvsp[-7].entry) = mk_node("CP");			
							(yyvsp[-6].entry) = mk_node("OCB");			
							(yyvsp[-4].entry) = mk_node("CCB");			
							(yyvsp[-3].entry) = mk_node("ELSE");			
							(yyvsp[-2].entry) = mk_node("OCB");			
							(yyvsp[0].entry) = mk_node("CCB");											
							mk_child((yyval.entry), (yyvsp[-10].entry)); 
							mk_child((yyval.entry), (yyvsp[-9].entry)); 
							mk_child((yyval.entry), (yyvsp[-8].entry)); 
							mk_child((yyval.entry), (yyvsp[-7].entry)); 
							mk_child((yyval.entry), (yyvsp[-6].entry)); 
							mk_child((yyval.entry), (yyvsp[-5].entry)); 
							mk_child((yyval.entry), (yyvsp[-4].entry)); 
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 1928 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 406 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("if_else_block");				
							(yyvsp[-8].entry) = mk_node("IF");	
							(yyvsp[-7].entry) = mk_node("OP");
							(yyvsp[-5].entry) = mk_node("CP");
							(yyvsp[-4].entry) = mk_node("OCB");
							(yyvsp[-2].entry) = mk_node("CCB");
							(yyvsp[-1].entry) = mk_node("ELSE");
							mk_child((yyval.entry), (yyvsp[-8].entry)); 
							mk_child((yyval.entry), (yyvsp[-7].entry)); 
							mk_child((yyval.entry), (yyvsp[-6].entry)); 
							mk_child((yyval.entry), (yyvsp[-5].entry)); 
							mk_child((yyval.entry), (yyvsp[-4].entry)); 
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1951 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 427 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
							(yyval.entry) = mk_node("if_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1960 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 434 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1969 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 438 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1978 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 442 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1987 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 449 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("while_loop_block");		
							(yyvsp[-6].entry) = mk_node("WHILE");			
							(yyvsp[-5].entry) = mk_node("OP");			
							(yyvsp[-3].entry) = mk_node("CP");			
							(yyvsp[-2].entry) = mk_node("OCB");			
							(yyvsp[0].entry) = mk_node("CCB");													
							mk_child((yyval.entry), (yyvsp[-6].entry));
							mk_child((yyval.entry), (yyvsp[-5].entry));
							mk_child((yyval.entry), (yyvsp[-4].entry));
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							 
						}
#line 2008 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 468 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
							(yyval.entry) = mk_node("while_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2018 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 476 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("do_while_loop_block");		
							(yyvsp[-8].entry) = mk_node("DO");			
							(yyvsp[-7].entry) = mk_node("OCB");			
							(yyvsp[-5].entry) = mk_node("CCB");			
							(yyvsp[-4].entry) = mk_node("WHILE");			
							(yyvsp[-3].entry) = mk_node("OP");			
							(yyvsp[-1].entry) = mk_node("CP");			
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[-8].entry)); 
							mk_child((yyval.entry), (yyvsp[-7].entry));
							mk_child((yyval.entry), (yyvsp[-6].entry));
							mk_child((yyval.entry), (yyvsp[-5].entry));
							mk_child((yyval.entry), (yyvsp[-4].entry));
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2043 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 499 "parser.y" /* yacc.c:1646  */
    {// explicit check for NILL condition 
							(yyval.entry) = mk_node("do_while_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 507 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_loop_block");		
							(yyvsp[-9].entry) = mk_node("FOR");			
							(yyvsp[-8].entry) = mk_node("OP");			
							(yyvsp[-5].entry) = mk_node("TERMINATOR");			
							(yyvsp[-3].entry) = mk_node("CP");			
							(yyvsp[-2].entry) = mk_node("OCB");			
							(yyvsp[-1].entry) = mk_node("CCB");			
							mk_child((yyval.entry), (yyvsp[-9].entry)); 
							mk_child((yyval.entry), (yyvsp[-8].entry));
							mk_child((yyval.entry), (yyvsp[-7].entry));
							mk_child((yyval.entry), (yyvsp[-6].entry));
							mk_child((yyval.entry), (yyvsp[-5].entry));
							mk_child((yyval.entry), (yyvsp[-4].entry));
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							
						}
#line 2077 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 529 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2090 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 537 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 544 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");											
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2115 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 552 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2128 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 560 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[0].entry) = mk_node("TERMINATOR");											
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2139 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 566 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[0].entry) = mk_node("TERMINATOR");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2151 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 573 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[0].entry) = mk_node("TERMINATOR");											
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2163 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 580 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[0].entry) = mk_node("TERMINATOR");
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2174 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 586 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2184 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 594 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2193 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 601 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");									
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2205 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 608 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");									
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2217 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 615 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2230 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 623 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2243 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 631 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2252 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 635 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2261 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 639 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2271 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 644 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2281 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 649 "parser.y" /* yacc.c:1646  */
    {
						}
#line 2288 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 654 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("function_def_block");						
							(yyvsp[-7].entry) = mk_node("FUNCTION");			
							(yyvsp[-5].entry) = mk_node("OP");			
							(yyvsp[-3].entry) = mk_node("CP");			
							(yyvsp[-2].entry) = mk_node("OCB");			
							(yyvsp[0].entry) = mk_node("CCB");										
							mk_child((yyval.entry), (yyvsp[-7].entry)); 
							mk_child((yyval.entry), (yyvsp[-6].entry));
							mk_child((yyval.entry), (yyvsp[-5].entry));
							mk_child((yyval.entry), (yyvsp[-4].entry));
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2309 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 673 "parser.y" /* yacc.c:1646  */
    {
						(yyval.entry) = mk_node("IDENT");
						struct node *temp = mk_node(yylval.terminal_value);
						mk_child((yyval.entry),temp);
						}
#line 2319 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 680 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("argument_list_block");			
							(yyvsp[-1].entry) = mk_node("COMMA");

							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2333 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 689 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("argument_list_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2343 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 694 "parser.y" /* yacc.c:1646  */
    {
						}
#line 2350 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 699 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");			
							(yyvsp[0].entry) = mk_node("TERMINATOR");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2361 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 705 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2372 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 711 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2383 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 717 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");
							(yyvsp[-2].entry) = mk_node("PRINT");
							(yyvsp[0].entry) = mk_node("TERMINATOR");
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
					}
#line 2396 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 725 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");
							(yyvsp[-2].entry) = mk_node("SCAN");
							(yyvsp[0].entry) = mk_node("TERMINATOR");
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry)); 
					}
#line 2409 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 733 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");
							(yyvsp[-2].entry) = mk_node("RETURN");
							(yyvsp[0].entry) = mk_node("TERMINATOR");
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry)); 
					}
#line 2422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 745 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("function_call_block");		
							(yyvsp[-3].entry) = mk_node("IDENT");						
							(yyvsp[-2].entry) = mk_node("OP");						
							(yyvsp[0].entry) = mk_node("CP");													
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2437 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 758 "parser.y" /* yacc.c:1646  */
    {
					   	 (yyval.entry) = mk_node("function_var_list");
					   	 (yyvsp[-1].entry) = mk_node("COMMA");
					   	 mk_child((yyval.entry), (yyvsp[-2].entry));
					   	 mk_child((yyval.entry), (yyvsp[-1].entry));
					   	 mk_child((yyval.entry), (yyvsp[0].entry));
					   }
#line 2449 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 765 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("function_var_list");
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2458 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 772 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("declaration_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2468 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 780 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");			
							(yyvsp[-1].entry) = mk_node("COMMA");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2480 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 787 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2489 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 791 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");				
							(yyvsp[-1].entry) = mk_node("COMMA");											
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2501 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 798 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2510 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 806 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");		
							(yyvsp[0].entry) = mk_node("INT");									
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2520 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 811 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("FLOAT");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2530 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 816 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");		
							(yyvsp[0].entry) = mk_node("DOUBLE");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2540 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 821 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("CHAR");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2550 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 826 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("LONG");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2560 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 834 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("var_block");			
							(yyvsp[0].entry) = mk_node("VAR");												
							mk_child((yyvsp[0].entry),temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 

						}
#line 2573 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 842 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("var_block");			
							(yyvsp[0].entry) = mk_node("POINTER");												
							mk_child((yyvsp[0].entry),temp);
							mk_child((yyval.entry), (yyvsp[0].entry));

						}
#line 2586 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 853 "parser.y" /* yacc.c:1646  */
    {//check for expr to return positive value. Run time check for negeative value.
							(yyval.entry) = mk_node("array_block");	
							(yyvsp[-2].entry) = mk_node("OB");	
							(yyvsp[0].entry) = mk_node("CB");												
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2600 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 865 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp=mk_node(yyval.terminal_value);
							(yyval.entry) = mk_node("num");
							(yyvsp[0].entry) = mk_node("NUM");
							mk_child((yyval.entry),temp);
							strcpy((yyvsp[0].entry)->type, "int");
						}
#line 2612 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 875 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("ass_var_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2621 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 879 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("ass_var_block");		
							(yyvsp[0].entry) = mk_node("DREF");
							mk_child((yyvsp[0].entry),temp);											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2633 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 886 "parser.y" /* yacc.c:1646  */
    {// check if expr is returning a index present in the array. 
							(yyval.entry) = mk_node("ass_var_block");		
							(yyvsp[-2].entry) = mk_node("OB");	
							(yyvsp[0].entry) = mk_node("CB");											
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2647 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 898 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");	
							(yyvsp[-1].entry) = mk_node("ASSIGN");													
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));

							 
						}
#line 2661 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 907 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2673 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 914 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 920 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							(yyvsp[-1].entry) = mk_node("ASSIGN");													
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2696 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 927 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2707 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 933 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2718 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 939 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");	
							(yyval.entry) = mk_node("expr");	
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2731 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 950 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2743 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 957 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 964 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2766 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 970 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 975 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 979 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 983 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");	
							(yyvsp[-4].entry) = mk_node("OP");	
							(yyvsp[-2].entry) = mk_node("CP");	
																		
							mk_child((yyval.entry), (yyvsp[-4].entry)); 
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2811 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 995 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");	
							(yyvsp[-4].entry) = mk_node("OP");	
							(yyvsp[-2].entry) = mk_node("CP");												
							mk_child((yyval.entry), (yyvsp[-4].entry)); 
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2827 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 1006 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");	
							(yyvsp[-2].entry) = mk_node("OP");	
							(yyvsp[0].entry) = mk_node("CP");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 1015 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2853 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1022 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2865 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1029 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2877 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1036 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 							
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2889 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1049 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");
						}
#line 2908 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1055 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							
						}
#line 2919 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1061 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							
						}
#line 2930 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1067 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2940 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1072 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1077 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
							
						}
#line 2962 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1087 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("EQ");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2972 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1092 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("NOTEQ");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2982 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1097 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("GT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2992 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1102 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3002 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1107 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("GE");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3012 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1112 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LE");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1117 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LTGT");
							mk_child((yyval.entry),(yyvsp[0].entry));
						}
#line 3032 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1125 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_condition_op");
							(yyvsp[0].entry) = mk_node("AND");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3042 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1130 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_condition_op");
							(yyvsp[0].entry) = mk_node("OR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1138 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_unary_condition_op");
							(yyvsp[0].entry) = mk_node("NOT_1");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3062 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1146 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("fixed_condition");
							(yyvsp[0].entry) = mk_node("TRUE_1");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3072 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1151 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("fixed_condition");
							(yyvsp[0].entry) = mk_node("FALSE_1");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3082 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1159 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("ADD");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3092 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1164 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("SUB");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3102 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1169 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("MULT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3112 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1174 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("DIV");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3122 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1179 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("EXP");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1184 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("MOD");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3142 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1192 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_unary_op");
							(yyvsp[0].entry) = mk_node("INC");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3152 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1197 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_unary_op");
							(yyvsp[0].entry) = mk_node("DEC");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3162 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1205 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_AND");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3172 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1210 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_OR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3182 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1215 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_XOR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3192 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1220 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_LEFT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3202 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1225 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_RIGHT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3212 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1233 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_unary_op");		
							(yyvsp[0].entry) = mk_node("BIN_NOT");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3222 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1241 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("ADD_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1246 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("SUB_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3242 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1251 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("MULT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3252 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1256 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("DIV_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3262 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1261 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("MOD_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3272 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1266 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("LEFT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3282 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1271 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("RIGHT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3292 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1279 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");
							(yyvsp[0].entry) = mk_node("BIN_AND_ASSIGN");											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3302 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1284 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");	
							(yyvsp[0].entry) = mk_node("BIN_IOR_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3312 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1289 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");	
							(yyvsp[0].entry) = mk_node("BIN_XOR_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3322 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3326 "parser.cpp" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
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
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 1297 "parser.y" /* yacc.c:1906  */


void yyerror(const char *err){
	printf(" ** %s\n",err);
}

int main(){
	#if YYDEBUG
	    yydebug = 1;
	#endif
    node_id=0;
    edge_id=0;
    creation_id=0;
	char graph_name[1];
	graph_name[0]='G';
    syntax_graph=agopen(graph_name, Agdirected, NULL);
	root = init_tree();
	gst_obj=new sym_table<func_elem,func_def>;
	vector<pair<string,var_def*> > temp_vctr {pair<string,var_def*>("__main__",new var_def(""))};
	gst_obj->insert(main_func_name,new func_def(temp_vctr,""));

	//yylex();
	yyparse();

	printf("\n\n-----------------   TREE   ------------------\n\n");
	printtree(root, 0);
	type_check(root, 0);
    FILE *fp=fopen("syntax_graph.gv","w+");
    agwrite(syntax_graph,fp);
    fclose(fp);
	gst_obj->print(sym_tab_out);
	get_symbol_table_data();
	sym_tab_out.close();
	return 0;
}

node *init_tree(){
	/*node *tmp = (node *)malloc(sizeof(node));*/
	/*for (int i = 0; i < MAX_CHILD; ++i){*/
		/*tmp->child[i] = NULL;*/
	/*}*/
	/*tmp->left_sib = NULL;*/
	/*tmp->right_sib = NULL;*/
	/*tmp->name = (char *)malloc(20*sizeof(char));*/
	/*strcpy(tmp->name, "super_block");*/
	/*tmp->cur_childs = 0;*/
    node *tmp=mk_node("super_block");

	for (int i = 0; i < MAX_LEVELS; ++i){
		levels[i] = false;
	}
	return tmp;
}

struct node *mk_node(const char *name){
	node *tmp = (node *)malloc(sizeof(node));
	tmp->name = (char *)malloc(20*sizeof(char));
	strcpy(tmp->name, name);
	tmp->cur_childs = 0;
	tmp->type = (char *)malloc(50*sizeof(char));
	strcpy(tmp->type, "notdef");
	tmp->left_sib = NULL;
	tmp->right_sib = NULL;
	for (int i = 0; i < MAX_CHILD; ++i){
		tmp->child[i] = NULL;
	}
	tmp->graph_node_id=node_id;
	node_id++;
    
	return tmp;
}

void mk_child(node *par, node *ch){
	par->child[par->cur_childs] = ch;
	par->cur_childs++;
    /*Agnode_t *par_node,*child_node;*/
    /*par_node=make_graph_node(par);*/
    /*child_node=make_graph_node(ch);*/
    /*char buf[50];*/
    /*sprintf(buf,"%d",edge_id);*/
    /*agedge(syntax_graph,par_node,child_node,(char *)buf,true);*/
    /*printf("creating egde %s -> %s\n",par_node->name,child_node->name);*/
    /*edge_id++;*/
}

void mk_sibling(node *from, node *to, bool right){
	if(right){
		from->right_sib = to;
		to->left_sib = from;
	}else{
		from->left_sib = to;
		to->right_sib = from;
	}
}

void printtree(node *root, int level){
	for (int i = 0; i < level-1; ++i){
		if(levels[i]){
			printf("|   ");
		}else{
			printf("\t");
		}
	}
	if(level)
		printf("|\n");
	for (int i = 0; i < level-1; ++i){
		if(levels[i]){
			printf("|   ");
		}else{
			printf("\t");
		}
	}
	if(level)
		printf("\\___");
	printf("%s\n", root->name);

	levels[level] = true;
    Agnode_t *graph_root,*graph_child;
    graph_root=make_graph_node(root);
    char buf[50];
	if(strcmp(root->name,"declaration_block")==0){
		data_type=string(root->child[0]->child[0]->name);	
		transform(data_type.begin(),data_type.end(),data_type.begin(),::tolower);
		struct node *var_list_block=root->child[1];
		while(var_list_block!=NULL){
			struct node *var_list_child=var_list_block->child[0];
			if(strcmp(var_list_child->name,"var_block")==0){
				struct node *var_block_child=var_list_child->child[0];
				string var_name=string(var_block_child->child[0]->name);
				if(strcmp(var_block_child->name,"VAR")==0){
					insert_var_in_symbol_table(func_name,var_name,data_type);	
				}else if(strcmp(var_block_child->name,"POINTER")==0){
					insert_var_in_symbol_table(func_name,var_name,data_type,1);	
				}
			}else if(strcmp(var_list_child->name,"array_block")==0){
				struct node *var_block=var_list_child->child[0];
				struct node *arr_size_block=var_list_child->child[2];

				struct node *var_block_child=var_block->child[0];
				string var_name=string(var_block_child->child[0]->name);
				
				int arr_size=atoi(arr_size_block->child[0]->name);
				if(strcmp(var_block_child->name,"VAR")==0){
					insert_var_in_symbol_table(func_name,var_name,data_type,2,arr_size);	
				}else if(strcmp(var_block_child->name,"POINTER")==0){
					insert_var_in_symbol_table(func_name,var_name,data_type,3,arr_size);	
				}
			}
			if(var_list_block->cur_childs==3)
				var_list_block=var_list_block->child[2];
			else
				var_list_block=NULL;
		}
	}else if(strcmp(root->name,"function_def_block")==0){
		struct node *func_name_node=root->child[1];
		struct node *argument_list_block=root->child[3];
		string temp_func_name=string(func_name_node->child[0]->name);
		func_name=temp_func_name;
		func_terminator_node=root->child[7];//the CCB
		vector<pair<string,var_def*> > temp_arg_list;
		//Now finding the argument list
		while(argument_list_block!=NULL){
			//Finding the data type
			struct node *data_type_node=argument_list_block->child[0]->child[0];
			string tdt;
			var_def *temp_def;
			tdt=string(data_type_node->name);	
			transform(tdt.begin(),tdt.end(),tdt.begin(),::tolower);
			
			//Finding the variable name
			struct node *var_block_child=argument_list_block->child[1]->child[0];
			string var_name=string(var_block_child->child[0]->name);
			if(strcmp(var_block_child->name,"VAR")==0){
				temp_def=new var_def(tdt);
			}else if(strcmp(var_block_child->name,"POINTER")==0){
				temp_def=new var_def(tdt,1);
			}
			temp_arg_list.push_back(pair<string,var_def*>(var_name,temp_def));
			////////////////////////////////////
			if(argument_list_block->cur_childs==4){
				argument_list_block=argument_list_block->child[3];
			}
			else
				argument_list_block=NULL;
		}	
		////////////////////////////////////////
		gst_obj->insert(temp_func_name,new func_def(temp_arg_list,""));
		vector<pair<string,var_def*> >::iterator it;
		for(it=temp_arg_list.begin();it!=temp_arg_list.end();it++){
			insert_var_in_symbol_table(func_name,it->first,it->second->data_type,it->second->var_type,it->second->arr_size);	
		}
	}else if(root==func_terminator_node){
		func_name=main_func_name;
	}

	for (int i = 0; i < root->cur_childs; ++i){
        graph_child=make_graph_node(root->child[i]);
        sprintf(buf,"%d",edge_id);
        agedge(syntax_graph,graph_root,graph_child,(char *)buf,true);
        edge_id++;
        if(root->cur_childs == i+1){
			levels[level] = false;
		}
		printtree(root->child[i], level+1);

	}
	levels[level] = false;

}

void type_check(node *root, int level){

	if(strcmp(root->name,"function_def_block")==0){
		if(strcmp(root->child[0]->name, "FUNCTION")==0){
			cur_scope = root->child[1]->child[0]->name;
		}
	}

	for (int i = 0; i < root->cur_childs; ++i){
		type_check(root->child[i], level+1);
	}

	if(strcmp(root->name,"function_def_block")==0){
		if(strcmp(root->child[7]->name, "CCB")==0){
			cur_scope = main_func_name;
		}
	}
	if(strcmp(root->name,"function_call_block")==0){

	}else if(strcmp(root->name,"conditional_expr")==0){
		if(root->cur_childs > 1){
			if(strcmp(root->child[1]->name, "arith_condition_op")==0 ||
				strcmp(root->child[1]->name, "bit_condition_op")==0){

				if(strcmp(root->child[0]->type, "notdef")==0){
					printf("type not defined 0");
				}else if(strcmp(root->child[2]->type, "notdef")==0){
					printf("type not defined 2");
				}else if(strcmp(root->child[2]->type, root->child[0]->type) != 0){
					cout << root->child[2]->name << ":" << root->child[2]->type << endl;
					// cout << root->child[0]->name << ":" << root->child[0]->type << endl;
					printf("type mismatch error\n");
				}else if(strcmp(root->child[2]->type, root->child[0]->type) == 0){
					// printf("type match\n");
					strcpy(root->type, root->child[2]->type);
				}
			}else if(strcmp(root->child[0]->name, "bit_unary_condition_op")==0){
				strcpy(root->type, root->child[1]->type);
			}
		}
		if(root->cur_childs == 1){
			if(strcmp(root->child[0]->name, "expr")==0){
				if(strcmp(root->child[0]->type, "notdef")==0){
					cout << root->child[0]->name << " : notdef" << endl;
				}else{
					cout << root->child[0]->type << ":" << root->child[0]->name << "->" << root->name << endl;
				}
				strcpy(root->type, root->child[0]->type);
			}else if(strcmp(root->child[0]->name, "fixed_condition")==0){
				if(strcmp(root->child[0]->type, "notdef")==0){
					cout << root->child[0]->name << " : notdef" << endl;
				}else{
					cout << root->child[0]->type << ":" << root->child[0]->name << "->" << root->name << endl;
				}
				strcpy(root->type, root->child[0]->type);
			}
		}
		
	}else if(strcmp(root->name,"expr")==0){
		if(root->cur_childs > 1){
			if(strcmp(root->child[1]->name, "arith_binary_op")==0 ||
				strcmp(root->child[1]->name, "bit_binary_op")==0){

				if(strcmp(root->child[0]->type, "notdef")==0){
					printf("type not defined 0\n");
				}else if(strcmp(root->child[2]->type, "notdef")==0){
					printf("type not defined 2\n");
					// cout << root->child[2]->name << ":" << root->child[2]->type << endl;
					// cout << root->child[0]->name << ":" << root->child[0]->type << endl;
					
				}else if(strcmp(root->child[2]->type, root->child[0]->type) != 0){
					cout << root->child[2]->name << ":" << root->child[2]->type << endl;
					cout << root->child[0]->name << ":" << root->child[0]->type << endl;
					printf("type mismatch error\n");
				}else if(strcmp(root->child[2]->type, root->child[0]->type) == 0){
					// printf("type match\n");

				}
			}else if(strcmp(root->child[0]->name, "bit_unary_op")==0){
				strcpy(root->type, root->child[1]->type);
			}else if(strcmp(root->child[1]->name, "conditional_expr")==0){
			
				if(root->cur_childs > 3){
					if(strcmp(root->child[1]->type, "notdef")==0){
						printf("type not defined 1\n");
					}else if(strcmp(root->child[4]->type, "notdef")==0){
						printf("type not defined 4\n");
					}else if(strcmp(root->child[4]->type, root->child[1]->type) != 0){
						cout << root->child[4]->name << ":" << root->child[4]->type << endl;
						cout << root->child[1]->name << ":" << root->child[1]->type << endl;
						
						printf("type mismatch error\n");
					}else if(strcmp(root->child[4]->type, root->child[1]->type) == 0){
						// printf("type match\n");
						strcpy(root->type, root->child[4]->type);
					}
				}
			}
		}
		if(root->cur_childs == 1){
			if(strcmp(root->child[0]->name, "ass_var_block")==0 ||
				strcmp(root->child[0]->name, "const_block")==0){
				if(strcmp(root->child[0]->type, "notdef")==0){
					cout << root->child[0]->name << " : notdef" << endl;
				}else{
					cout << root->child[0]->type << ":" << root->child[0]->name << "->" << root->name << endl;
				}
				strcpy(root->type, root->child[0]->type);
			}
		}
	}else if(strcmp(root->name,"assignment_block")==0){
		if(strcmp(root->child[1]->name,"ASSIGN")==0 ||
			strcmp(root->child[1]->name,"arith_assgn_op")==0 ||
			strcmp(root->child[1]->name,"bit_assgn_op")==0){

			if(strcmp(root->child[0]->type, "notdef")==0){
				printf("type not defined 0\n");
			}else if(strcmp(root->child[2]->type, "notdef")==0){
				printf("type not defined 2\n");
				cout << root->child[2]->name << ":" << root->child[2]->type << endl;
				cout << root->child[0]->name << ":" << root->child[0]->type << endl;
			}else if(strcmp(root->child[2]->type, root->child[0]->type) != 0){
				cout << root->child[2]->name << ":" << root->child[2]->type << endl;
				cout << root->child[0]->name << ":" << root->child[0]->type << endl;
				
				printf("type mismatch error\n");
			}else if(strcmp(root->child[2]->type, root->child[0]->type) == 0){
				// printf("type match\n");
				strcpy(root->type, root->child[2]->type);
			}
		}
	}else if(strcmp(root->name,"ass_var_block")==0){
		strcpy(root->type, root->child[0]->type);
		root->var_type = root->child[0]->var_type;
		
	}else if(strcmp(root->name,"var_block")==0){
		if(strcmp(root->child[0]->name,"VAR")==0){
			func_elem *fe=gst_obj->lookup(cur_scope);
			if(fe==NULL){
				cout<<"null dereferencing error"<<endl;
			}else{
				var_def *vd=fe->get_type(root->child[0]->child[0]->name);
				strcpy(root->child[0]->child[0]->type, vd->data_type.c_str());
				strcpy(root->child[0]->type, vd->data_type.c_str());
				strcpy(root->type, vd->data_type.c_str());
				root->child[0]->child[0]->var_type = vd->var_type;
				root->child[0]->var_type = vd->var_type;
				root->var_type = vd->var_type;	
			}
			cout << root->child[0]->child[0]->name << ":" << root->child[0]->child[0]->type << ":" << root->child[0]->child[0]->var_type << endl;
			
		}
		
	}
	
}

Agnode_t * make_graph_node(node *cur_node){
	char buf[255];
    sprintf(buf,"%s_%d",cur_node->name,cur_node->graph_node_id);
    Agnode_t *new_node= agnode(syntax_graph,(char *)buf,TRUE);
    return new_node;   
}


void insert_var_in_symbol_table(string func_name,string var_name,string data_type,int var_type,int arr_size){
	int ret_val;
	func_elem *fe=gst_obj->lookup(func_name);
	if(fe==NULL){
		sym_tab_out<<"func named "<<func_name<<" not found"<<endl;
	}else{
		ret_val=fe->insert(var_name,new var_def(data_type,var_type,arr_size));
		if(ret_val==0){
			sym_tab_out<<"Insertion successfull"<<endl;
		}else if(ret_val==elem_already_exist){
			sym_tab_out<<"var named "<<var_name<<" already exist"<<endl;	
		}
	}
}

void get_symbol_table_data(){
	ofstream sym_tab_data("sym_tab_data.txt");
	gst_obj->print_data(sym_tab_data);
	sym_tab_data.close();
}

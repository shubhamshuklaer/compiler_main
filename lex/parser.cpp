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
	#include <string.h>
    #include <graphviz/cgraph.h>
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
	};

	struct node *root;
	
	struct node *mk_node(const char *name);
	void mk_child(node *par, node *ch);
	void mk_sibling(node *from, node *to, bool right);

	void printtree(node *root, int level);

	node *init_tree();
    
    Agraph_t *syntax_graph;
    int node_id,edge_id;

	// #define YYSTYPE struct node *

#line 105 "parser.cpp" /* yacc.c:339  */

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
    LTGT = 326
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 40 "parser.y" /* yacc.c:355  */

	struct node *entry;
	char *terminal_value;

#line 222 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 237 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  72
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   884

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  44
/* YYNRULES -- Number of rules.  */
#define YYNRULES  146
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  265

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   326

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
      65,    66,    67,    68,    69,    70,    71
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   189,   189,   196,   201,   205,   214,   219,   227,   236,
     249,   265,   272,   279,   289,   294,   298,   307,   312,   317,
     322,   327,   333,   340,   356,   379,   393,   400,   404,   408,
     415,   434,   442,   465,   473,   495,   503,   510,   518,   526,
     532,   539,   546,   552,   560,   567,   574,   581,   589,   597,
     601,   605,   610,   615,   620,   640,   649,   654,   659,   665,
     671,   677,   691,   700,   712,   720,   727,   735,   742,   746,
     753,   761,   766,   771,   776,   781,   789,   796,   807,   819,
     823,   830,   843,   851,   858,   864,   871,   877,   883,   894,
     900,   906,   912,   917,   923,   927,   931,   935,   946,   956,
     964,   970,   976,   982,   988,   993,   999,  1004,  1009,  1013,
    1017,  1026,  1031,  1036,  1041,  1046,  1051,  1056,  1064,  1069,
    1077,  1085,  1090,  1098,  1103,  1108,  1113,  1118,  1123,  1131,
    1136,  1144,  1149,  1154,  1159,  1164,  1172,  1180,  1185,  1190,
    1195,  1200,  1205,  1210,  1218,  1223,  1228
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
  "PRINT", "LTGT", "$accept", "super_block", "start_block",
  "comment_block", "defination_block", "const_block", "block",
  "general_block", "if_else_block", "if_condition", "loop_block",
  "while_loop_block", "while_condition", "do_while_loop_block",
  "do_while_condition", "for_loop_block", "for_initialization",
  "for_condition", "for_update", "function_def_block",
  "argument_list_block", "general_stmt", "str", "function_call_block",
  "function_var_list", "declaration_block", "var_list", "data_type",
  "var_block", "array_block", "ass_var_block", "assignment_block", "expr",
  "conditional_expr", "arith_condition_op", "bit_condition_op",
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
     325,   326
};
# endif

#define YYPACT_NINF -151

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-151)))

#define YYTABLE_NINF -106

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     497,   425,   -32,   -18,   -31,   -10,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,    -8,  -151,
    -151,  -151,  -151,  -151,    25,  -151,  -151,   -20,   -13,     3,
      30,    15,    29,  -151,   425,   425,   393,  -151,  -151,   641,
     641,  -151,  -151,  -151,   569,   641,   393,    31,    88,    23,
     837,    48,    50,    51,   201,  -151,    60,   154,  -151,   250,
     250,   783,    37,   250,    49,    61,    42,    74,    80,    65,
    -151,    83,  -151,   641,   425,  -151,   569,  -151,  -151,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,   201,
     201,  -151,  -151,   569,  -151,  -151,   201,   201,  -151,  -151,
     -27,    77,   250,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,  -151,  -151,    25,   201,   201,   201,    25,    25,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,   250,
     250,  -151,   250,   434,  -151,   201,  -151,  -151,    91,  -151,
      95,  -151,    97,  -151,   164,   250,   -22,   297,   -17,    60,
     102,    89,  -151,   393,  -151,   712,   712,   240,    15,  -151,
    -151,  -151,  -151,  -151,  -151,   250,    88,    88,   104,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,  -151,
    -151,   106,   108,   161,   317,   121,  -151,  -151,    37,   -16,
    -151,    37,   -14,  -151,   250,   201,   201,   114,   115,   126,
      88,   132,   128,  -151,  -151,  -151,   783,   783,   135,    94,
    -151,  -151,    37,  -151,  -151,    37,  -151,  -151,  -151,  -151,
    -151,   134,   118,  -151,  -151,   137,   145,   250,   138,   142,
     297,   144,    60,  -151,  -151,   783,   240,   210,  -151,   167,
    -151,   166,    94,   147,    94,   153,   168,  -151,    11,   185,
     783,  -151,    94,  -151,    94,  -151,   783,  -151,  -151,   180,
    -151,  -151,   183,  -151,  -151
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,   120,   121,   122,    71,
      75,    74,    72,    73,   129,   130,   136,    12,     0,    76,
      77,    80,    11,    13,   105,     6,     7,     0,     0,     0,
       0,     0,     0,     2,     0,     0,    95,     4,    15,     0,
       0,    28,    29,    27,     0,     0,    96,     0,     0,    79,
      94,     0,   108,     0,   105,   109,     0,     0,    21,   105,
     105,     0,     0,   105,     0,     0,     0,     0,     0,     0,
      62,     0,     1,     0,     0,    20,     0,     3,   123,   124,
     125,   126,   127,   128,   131,   132,   133,   134,   135,   105,
     105,    19,    18,     0,    14,    17,   105,   105,    58,    66,
      68,    70,   105,   144,   145,   146,   137,   138,   139,   140,
     141,   142,   143,   105,   105,   105,   105,   105,   105,    59,
     118,   119,   111,   112,   113,   114,   115,   116,   117,   105,
     105,    60,   105,    94,   110,   105,   104,    92,     0,    26,
       0,    31,     0,    43,     0,   105,     0,     0,     0,     0,
       0,    65,    88,    99,     8,     0,     0,    57,     0,     5,
      16,   100,   101,   102,   103,   105,     0,     0,     0,    85,
      82,    89,    90,    91,    86,    83,    87,    84,   106,   107,
      93,     0,     0,     0,     0,     0,    44,    42,     0,     0,
      39,     0,     0,    63,   105,   105,   105,     0,     0,     0,
       0,     0,     0,    67,    69,    81,     0,     0,     0,    53,
      35,    40,     0,    36,    41,     0,    64,    97,    98,     9,
      10,     0,    56,    61,    78,     0,     0,   105,     0,    49,
       0,    50,     0,    37,    38,     0,    57,    23,    30,     0,
      33,     0,    53,    51,    53,    52,     0,    55,     0,     0,
       0,    45,    53,    46,    53,    54,     0,    25,    32,     0,
      47,    48,     0,    34,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -151,  -151,     4,    21,   206,    -3,   -19,   -33,    10,  -151,
    -151,  -151,  -151,  -151,  -151,  -151,   -40,  -151,  -118,   -21,
      27,  -151,   101,   -60,    75,  -151,  -150,  -146,   -44,  -151,
     175,   -24,   152,   -15,  -151,  -151,  -151,  -151,   -28,   -47,
     -26,  -151,  -151,  -151
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    73,    35,    36,    37,    38,    39,   138,
      40,    41,   140,    42,   239,    43,   145,   185,   228,    44,
     199,    45,    71,    46,   150,    47,    99,    48,    49,   101,
      50,    51,    52,    53,   129,   130,    54,    55,   114,    56,
     116,    57,   117,   118
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    75,   146,   115,   100,    58,    91,    92,    89,    65,
      90,   200,    95,    76,     2,   149,   203,   204,    96,    59,
      97,    34,    34,    66,    61,    94,   187,   165,   142,    72,
      67,   190,   211,    60,   214,     6,     7,     8,   148,    77,
      75,    62,   166,    63,   139,   141,    68,   188,   151,    14,
      15,    16,   191,   212,   136,   215,    34,   160,   120,   121,
      75,    14,    15,   154,    70,    93,   256,    17,    18,    19,
      20,    21,    76,    69,    22,    23,    24,   102,   159,    98,
      18,    19,    20,    21,    17,   143,   115,   168,   144,   169,
     200,    22,    23,   174,   176,    34,   119,    93,   170,   131,
     189,   152,   175,   177,    19,    20,    21,   122,   123,   124,
     125,   126,   127,   153,   178,   179,   157,    65,    14,    15,
      64,   128,   100,   100,   251,   195,   253,   196,   146,   155,
     186,   146,    19,    20,   260,   156,   261,    18,    19,    20,
      21,   149,   158,   181,   149,   144,   167,   182,   210,   229,
     202,   213,   146,   183,   193,   146,   222,   205,   194,   197,
     198,   206,   232,   207,   148,   149,   208,   148,   149,   209,
     219,   220,   233,   225,   226,   234,    34,    34,   221,   151,
     223,   224,   229,   243,   229,   231,   227,   236,   148,   235,
     241,   148,   229,   237,   229,   232,    17,   232,    19,    20,
      21,   238,   246,    22,    23,   232,   134,   232,    19,    20,
      21,   242,   240,   244,   248,   144,   252,   259,   231,   249,
     231,   250,   254,   262,   255,    14,    15,    16,   231,   133,
     231,   135,   137,   258,   133,   133,   263,   147,   133,   264,
      74,   161,   162,    17,    18,    19,    20,    21,   163,   164,
      22,    23,   132,     9,    10,    11,    12,    13,   257,   201,
       6,     7,     8,   247,   133,   133,   171,   172,   173,   216,
       0,   133,   133,     0,    14,    15,    16,   133,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   180,     0,   133,
     133,   133,    17,    18,    19,    20,    21,     0,     0,    22,
      23,   132,     0,     0,   133,   133,     0,   133,     0,     0,
     133,     0,     0,     0,     0,     0,     0,     0,     0,   184,
     133,    14,    15,     0,   192,     0,     0,     0,     0,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
     133,     0,     0,     0,   113,     0,     0,   217,   218,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,   147,   113,     0,   147,     0,     0,   133,
     133,   133,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   230,     0,     0,   147,     0,     0,
     147,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   133,     0,     0,     0,     0,   245,     0,     0,
       0,    78,    79,    80,    81,    82,    83,   230,     0,   230,
      84,    85,    86,    87,    88,   -22,     1,   230,     2,   230,
       3,     4,     5,  -105,  -105,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,    14,
      15,    16,    78,    79,    80,    81,    82,    83,    14,    15,
       0,    84,    85,    86,    87,    88,     0,    17,    18,    19,
      20,    21,     0,  -105,    22,    23,    24,     0,     0,     0,
       0,   -22,  -105,  -105,  -105,  -105,  -105,  -105,    25,    26,
      27,    28,    29,    30,     0,    31,  -105,   -22,     1,     0,
       2,     0,     3,     4,     5,  -105,  -105,     6,     7,     8,
       9,    10,    11,    12,    13,     0,     0,     0,     0,     0,
       0,    14,    15,    16,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    17,
      18,    19,    20,    21,     0,  -105,    22,    23,    24,     0,
       0,     0,     0,     0,  -105,  -105,  -105,  -105,  -105,  -105,
      25,    26,    27,    28,    29,    30,     0,    31,  -105,   -22,
       1,     0,     2,     0,     3,     4,     5,  -105,  -105,     6,
       7,     8,     9,    10,    11,    12,    13,     0,     0,     0,
       0,     0,     0,    14,    15,    16,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,    17,    18,    19,    20,    21,     0,  -105,    22,    23,
      24,     0,     0,     0,     0,   -22,  -105,  -105,  -105,  -105,
    -105,  -105,    25,    26,     0,     0,     0,    30,     0,    31,
    -105,   -22,     1,     0,     2,     0,     3,     4,     5,  -105,
    -105,     6,     7,     8,     9,    10,    11,    12,    13,     0,
       0,     0,     0,     0,     0,    14,    15,    16,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    17,    18,    19,    20,    21,     0,  -105,
      22,    23,    24,     0,     0,     0,     0,   -22,  -105,  -105,
    -105,  -105,  -105,  -105,    25,    26,     0,     0,     0,     0,
       0,    31,  -105,     1,     0,     2,     0,     3,     4,     5,
    -105,  -105,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,     0,
    -105,    22,    23,    24,     0,     0,     0,     0,   -22,  -105,
    -105,  -105,  -105,  -105,  -105,    25,    26,    27,    28,    29,
      30,     0,    31,  -105,     1,     0,     2,     0,     3,     4,
       5,  -105,  -105,     6,     7,     8,     9,    10,    11,    12,
      13,     0,     0,     0,     0,     0,     0,    14,    15,    16,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
       0,  -105,    22,    23,    24,     0,     0,     0,     0,   -22,
    -105,  -105,  -105,  -105,  -105,  -105,    25,    26,     0,     0,
       0,     0,     0,    31,  -105,    78,    79,    80,    81,    82,
      83,    14,    15,     0,    84,    85,    86,    87,    88,   103,
     104,   105,   106,   107,   108,   109,   110,   111,   112,     0,
       0,     0,     0,     0,   113
};

static const yytype_int16 yycheck[] =
{
      24,    34,    62,    50,    48,     1,    39,    40,    36,    24,
      36,   157,    45,    34,     3,    62,   166,   167,    46,    51,
      46,     0,     1,    43,    55,    44,    48,    54,    61,     0,
      43,    48,    48,    51,    48,    10,    11,    12,    62,    35,
      73,    51,    69,    51,    59,    60,    43,    69,    63,    24,
      25,    26,    69,    69,    57,    69,    35,    76,     8,     9,
      93,    24,    25,    66,    49,    44,    55,    42,    43,    44,
      45,    46,    93,    43,    49,    50,    51,    54,    74,    48,
      43,    44,    45,    46,    42,    48,   133,   102,    51,   113,
     236,    49,    50,   117,   118,    74,    48,    76,   113,    48,
     147,    52,   117,   118,    44,    45,    46,    57,    58,    59,
      60,    61,    62,    52,   129,   130,    51,   132,    24,    25,
     144,    71,   166,   167,   242,   153,   244,   153,   188,    55,
     145,   191,    44,    45,   252,    55,   254,    43,    44,    45,
      46,   188,    59,    52,   191,    51,    69,    52,   188,   209,
     165,   191,   212,    56,    52,   215,   200,    53,    69,   155,
     156,    55,   209,    55,   188,   212,     5,   191,   215,    48,
      56,    56,   212,   206,   207,   215,   155,   156,    52,   194,
      48,    53,   242,   230,   244,   209,    51,    69,   212,    55,
      52,   215,   252,    56,   254,   242,    42,   244,    44,    45,
      46,    56,   235,    49,    50,   252,    54,   254,    44,    45,
      46,    69,   227,    69,     4,    51,    69,   250,   242,    52,
     244,    55,    69,   256,    56,    24,    25,    26,   252,    54,
     254,    56,    57,    48,    59,    60,    56,    62,    63,    56,
      34,    89,    90,    42,    43,    44,    45,    46,    96,    97,
      49,    50,    51,    13,    14,    15,    16,    17,   248,   158,
      10,    11,    12,   236,    89,    90,   114,   115,   116,   194,
      -1,    96,    97,    -1,    24,    25,    26,   102,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   135,    -1,   114,
     115,   116,    42,    43,    44,    45,    46,    -1,    -1,    49,
      50,    51,    -1,    -1,   129,   130,    -1,   132,    -1,    -1,
     135,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   144,
     145,    24,    25,    -1,   149,    -1,    -1,    -1,    -1,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
     165,    -1,    -1,    -1,    47,    -1,    -1,   195,   196,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,   188,    47,    -1,   191,    -1,    -1,   194,
     195,   196,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   209,    -1,    -1,   212,    -1,    -1,
     215,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   227,    -1,    -1,    -1,    -1,   232,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,   242,    -1,   244,
      27,    28,    29,    30,    31,     0,     1,   252,     3,   254,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    18,    19,    20,    21,    22,    23,    24,    25,
      -1,    27,    28,    29,    30,    31,    -1,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,     0,     1,    -1,
       3,    -1,     5,     6,     7,     8,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,
      43,    44,    45,    46,    -1,    48,    49,    50,    51,    -1,
      -1,    -1,    -1,    -1,    57,    58,    59,    60,    61,    62,
      63,    64,    65,    66,    67,    68,    -1,    70,    71,     0,
       1,    -1,     3,    -1,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    42,    43,    44,    45,    46,    -1,    48,    49,    50,
      51,    -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,
      61,    62,    63,    64,    -1,    -1,    -1,    68,    -1,    70,
      71,     0,     1,    -1,     3,    -1,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    42,    43,    44,    45,    46,    -1,    48,
      49,    50,    51,    -1,    -1,    -1,    -1,    56,    57,    58,
      59,    60,    61,    62,    63,    64,    -1,    -1,    -1,    -1,
      -1,    70,    71,     1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    65,    66,    67,
      68,    -1,    70,    71,     1,    -1,     3,    -1,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      -1,    48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,
      57,    58,    59,    60,    61,    62,    63,    64,    -1,    -1,
      -1,    -1,    -1,    70,    71,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    40,    41,    -1,
      -1,    -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     5,     6,     7,    10,    11,    12,    13,
      14,    15,    16,    17,    24,    25,    26,    42,    43,    44,
      45,    46,    49,    50,    51,    63,    64,    65,    66,    67,
      68,    70,    73,    74,    75,    76,    77,    78,    79,    80,
      82,    83,    85,    87,    91,    93,    95,    97,    99,   100,
     102,   103,   104,   105,   108,   109,   111,   113,    74,    51,
      51,    55,    51,    51,   103,   105,    43,    43,    43,    43,
      49,    94,     0,    75,    76,    79,    91,    74,    18,    19,
      20,    21,    22,    23,    27,    28,    29,    30,    31,   110,
     112,    79,    79,    75,    78,    79,   110,   112,    48,    98,
     100,   101,    54,    32,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    47,   110,   111,   112,   114,   115,    48,
       8,     9,    57,    58,    59,    60,    61,    62,    71,   106,
     107,    48,    51,   102,   104,   102,    77,   102,    81,   105,
      84,   105,    79,    48,    51,    88,    95,   102,   103,   111,
      96,   105,    52,    52,    77,    55,    55,    51,    59,    74,
      78,   104,   104,   104,   104,    54,    69,    69,   105,   103,
     105,   104,   104,   104,   103,   105,   103,   105,   105,   105,
     104,    52,    52,    56,   102,    89,   105,    48,    69,   111,
      48,    69,   102,    52,    69,   110,   112,    74,    74,    92,
      99,    94,   105,    98,    98,    53,    55,    55,     5,    48,
      88,    48,    69,    88,    48,    69,    96,   104,   104,    56,
      56,    52,   100,    48,    53,    79,    79,    51,    90,    95,
     102,   103,   111,    88,    88,    55,    69,    56,    56,    86,
     105,    52,    69,   111,    69,   102,    79,    92,     4,    52,
      55,    90,    69,    90,    69,    56,    55,    80,    48,    79,
      90,    90,    79,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    82,    82,    82,
      83,    84,    85,    86,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    92,    92,    92,    93,    93,
      93,    93,    94,    95,    96,    96,    97,    98,    98,    98,
      98,    99,    99,    99,    99,    99,   100,   100,   101,   102,
     102,   102,   103,   103,   103,   103,   103,   103,   103,   104,
     104,   104,   104,   104,   104,   104,   104,   104,   104,   104,
     104,   104,   104,   104,   104,   104,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     108,   109,   109,   110,   110,   110,   110,   110,   110,   111,
     111,   112,   112,   112,   112,   112,   113,   114,   114,   114,
     114,   114,   114,   114,   115,   115,   115
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     3,     5,
       5,     1,     1,     1,     2,     1,     3,     2,     2,     2,
       2,     2,     0,     7,    11,     9,     1,     1,     1,     1,
       7,     1,     9,     1,    10,     3,     3,     4,     4,     2,
       3,     3,     2,     1,     1,     3,     3,     4,     4,     1,
       1,     2,     2,     0,     8,     4,     2,     0,     2,     2,
       2,     5,     1,     4,     3,     1,     2,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     4,     1,
       1,     4,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     2,     3,     1,     1,     1,     5,     5,     3,
       3,     3,     3,     3,     2,     0,     3,     3,     1,     1,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1
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
#line 189 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = root;
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1644 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 196 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1654 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 201 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 1663 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 205 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 1674 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 214 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("comment_block");	
							(yyvsp[0].entry) = mk_node("COMMENT");		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1684 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 219 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("comment_block");	
							(yyvsp[0].entry) = mk_node("MULTI_COMMENT");		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1694 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 227 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("defination_block");	
							(yyvsp[-2].entry) = mk_node("DEFINE");			
							(yyvsp[-1].entry) = mk_node("IDENT");		
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 1708 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 237 "parser.y" /* yacc.c:1646  */
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
#line 1725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 250 "parser.y" /* yacc.c:1646  */
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
#line 1742 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 265 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("STRING");		
							mk_child((yyvsp[0].entry), temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1754 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 272 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("NUM");
							mk_child((yyvsp[0].entry), temp);		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1766 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 279 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("CHARACTER");		
							mk_child((yyvsp[0].entry), temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1778 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 289 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1788 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 294 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 298 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 											
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1808 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 307 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1818 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 312 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1828 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 317 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 322 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1848 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 327 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("error");
							mk_child((yyval.entry), (yyvsp[0].entry));
							yyerrok;
							yyclearin;
						}
#line 1859 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 333 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("/general_block");
						}
#line 1867 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 340 "parser.y" /* yacc.c:1646  */
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
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 356 "parser.y" /* yacc.c:1646  */
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
#line 1916 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 379 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("if_else_block");				
							(yyvsp[-8].entry) = mk_node("INT");			
							(yyvsp[-8].entry) = mk_node("INT");			
							(yyvsp[-8].entry) = mk_node("INT");			
							(yyvsp[-8].entry) = mk_node("INT");			
							(yyvsp[-8].entry) = mk_node("INT");			
							(yyvsp[-8].entry) = mk_node("INT");			
							(yyvsp[-8].entry) = mk_node("INT");											
							mk_child((yyval.entry), (yyvsp[-8].entry)); 
						}
#line 1932 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 393 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
							(yyval.entry) = mk_node("if_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1941 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 400 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1950 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 404 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1959 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 408 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1968 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 415 "parser.y" /* yacc.c:1646  */
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
#line 1989 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 434 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
							(yyval.entry) = mk_node("while_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 1999 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 442 "parser.y" /* yacc.c:1646  */
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
#line 2024 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 465 "parser.y" /* yacc.c:1646  */
    {// explicit check for NILL condition 
							(yyval.entry) = mk_node("do_while_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2034 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 473 "parser.y" /* yacc.c:1646  */
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
#line 2058 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 495 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2071 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 503 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2083 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 510 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");											
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2096 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 518 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2109 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 526 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[0].entry) = mk_node("TERMINATOR");											
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2120 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 532 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[0].entry) = mk_node("TERMINATOR");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2132 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 539 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[0].entry) = mk_node("TERMINATOR");											
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2144 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 546 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[0].entry) = mk_node("TERMINATOR");
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2155 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 552 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2165 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 560 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2174 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 567 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");									
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2186 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 574 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");									
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2198 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 581 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2211 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 589 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2224 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 597 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2233 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 601 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2242 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 605 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2252 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 610 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2262 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 615 "parser.y" /* yacc.c:1646  */
    {
						}
#line 2269 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 620 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("function_def_block");						
							(yyvsp[-7].entry) = mk_node("FUNCTION");			
							(yyvsp[-6].entry) = mk_node("IDENT");			
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
#line 2291 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 640 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("argument_list_block");			
							(yyvsp[-1].entry) = mk_node("COMMA");
							(yyvsp[-3].entry) = mk_node("INT");												
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2305 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 649 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("argument_list_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2315 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 654 "parser.y" /* yacc.c:1646  */
    {
						}
#line 2322 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 659 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");			
							(yyvsp[0].entry) = mk_node("TERMINATOR");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2333 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 665 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2344 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 671 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2355 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 678 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");
							(yyvsp[-4].entry) = mk_node("PRINT");
							(yyvsp[-2].entry) = mk_node("GT");
							(yyvsp[0].entry) = mk_node("TERMINATOR");
							mk_child((yyval.entry), (yyvsp[-4].entry));
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2371 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 692 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("STRING");
							mk_child((yyval.entry), temp);
						}
#line 2381 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 700 "parser.y" /* yacc.c:1646  */
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
#line 2396 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 713 "parser.y" /* yacc.c:1646  */
    {
					   	 (yyval.entry) = mk_node("function_var_list");
					   	 (yyvsp[-1].entry) = mk_node("COMMA");
					   	 mk_child((yyval.entry), (yyvsp[-2].entry));
					   	 mk_child((yyval.entry), (yyvsp[-1].entry));
					   	 mk_child((yyval.entry), (yyvsp[0].entry));
					   }
#line 2408 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 720 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("function_var_list");
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2417 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 727 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("declaration_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2427 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 735 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");			
							(yyvsp[-1].entry) = mk_node("COMMA");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2439 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 742 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2448 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 746 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");				
							(yyvsp[-1].entry) = mk_node("COMMA");											
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2460 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 753 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2469 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 761 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("sdata_type");		
							(yyvsp[0].entry) = mk_node("INT");									
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2479 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 766 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("FLOAT");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2489 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 771 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");		
							(yyvsp[0].entry) = mk_node("DOUBLE");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2499 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 776 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("CHAR");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 781 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("LONG");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2519 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 789 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("var_block");			
							(yyvsp[0].entry) = mk_node("VAR");												
							mk_child((yyvsp[0].entry),temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2531 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 796 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("var_block");			
							(yyvsp[0].entry) = mk_node("POINTER");												
							mk_child((yyvsp[0].entry),temp);
							mk_child((yyval.entry), (yyvsp[0].entry));

						}
#line 2544 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 807 "parser.y" /* yacc.c:1646  */
    {//check for expr to return positive value. Run time check for negeative value.
							(yyval.entry) = mk_node("array_block");	
							(yyvsp[-2].entry) = mk_node("OB");	
							(yyvsp[0].entry) = mk_node("CB");												
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2558 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 819 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("ass_var_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2567 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 823 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("ass_var_block");		
							(yyvsp[0].entry) = mk_node("DREF");
							mk_child((yyvsp[0].entry),temp);											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2579 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 830 "parser.y" /* yacc.c:1646  */
    {// check if expr is returning a index present in the array. 
							(yyval.entry) = mk_node("ass_var_block");		
							(yyvsp[-2].entry) = mk_node("OB");	
							(yyvsp[0].entry) = mk_node("CB");											
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 843 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");	
							(yyvsp[-1].entry) = mk_node("ASSIGN");													
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							 
						}
#line 2607 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 851 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2619 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 858 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 864 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							(yyvsp[-1].entry) = mk_node("ASSIGN");													
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2642 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 871 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2653 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 877 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2664 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 883 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");	
							(yyval.entry) = mk_node("expr");	
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2677 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 894 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 900 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2699 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 906 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2710 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 912 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2720 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 917 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2731 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 923 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2740 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 927 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2749 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 931 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2758 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 935 "parser.y" /* yacc.c:1646  */
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
#line 2774 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 946 "parser.y" /* yacc.c:1646  */
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
#line 2789 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 956 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");	
							(yyvsp[-2].entry) = mk_node("OP");	
							(yyvsp[0].entry) = mk_node("CP");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2802 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 964 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2813 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 970 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2824 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 976 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2835 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 982 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 							
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2846 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 988 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2856 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 993 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");
						}
#line 2864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 999 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
						}
#line 2874 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1004 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
						}
#line 2884 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1009 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2893 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1013 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2902 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1017 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2913 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1026 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("EQ");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2923 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1031 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("NOTEQ");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2933 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1036 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("GT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2943 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1041 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2953 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1046 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("GE");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2963 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1051 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LE");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2973 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1056 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LTGT");
							mk_child((yyval.entry),(yyvsp[0].entry));
						}
#line 2983 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1064 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_condition_op");
							(yyvsp[0].entry) = mk_node("AND");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1069 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_condition_op");
							(yyvsp[0].entry) = mk_node("OR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1077 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_unary_condition_op");
							(yyvsp[0].entry) = mk_node("NOT_1");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3013 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1085 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("fixed_condition");
							(yyvsp[0].entry) = mk_node("TRUE_1");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3023 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1090 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("fixed_condition");
							(yyvsp[0].entry) = mk_node("FALSE_1");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3033 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1098 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("ADD");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3043 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1103 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("SUB");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3053 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1108 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("MULT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3063 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1113 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("DIV");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3073 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1118 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("EXP");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3083 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1123 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("MOD");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3093 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1131 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_unary_op");
							(yyvsp[0].entry) = mk_node("INC");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3103 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1136 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_unary_op");
							(yyvsp[0].entry) = mk_node("DEC");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3113 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1144 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_AND");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3123 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1149 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_OR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3133 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1154 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_XOR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3143 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1159 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_LEFT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3153 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1164 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_RIGHT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3163 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1172 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_unary_op");		
							(yyvsp[0].entry) = mk_node("ADD_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3173 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1180 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("ADD_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3183 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1185 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("SUB_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3193 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1190 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("MULT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3203 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1195 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("DIV_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3213 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1200 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("MOD_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3223 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1205 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("LEFT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3233 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1210 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("RIGHT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3243 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1218 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");
							(yyvsp[0].entry) = mk_node("BIN_AND_ASSIGN");											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3253 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1223 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");	
							(yyvsp[0].entry) = mk_node("BIN_IOR_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3263 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1228 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");	
							(yyvsp[0].entry) = mk_node("BIN_XOR_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3273 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3277 "parser.cpp" /* yacc.c:1646  */
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
#line 1236 "parser.y" /* yacc.c:1906  */


void yyerror(const char *err){
	printf(" ** %s\n",err);
}

int main(){
	#if YYDEBUG
	    yydebug = 1;
	#endif
    node_id=0;
    edge_id=0;
    syntax_graph=agopen("G", Agdirected, NULL);
	root = init_tree();

	//yylex();
	yyparse();

	printf("\n\n-----------------   TREE   ------------------\n\n");
	printtree(root, 0);
    FILE *fp=fopen("syntax_graph.gv","w+");
    agwrite(syntax_graph,fp);
    fclose(fp);
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
	tmp->left_sib = NULL;
	tmp->right_sib = NULL;
	for (int i = 0; i < MAX_CHILD; ++i){
		tmp->child[i] = NULL;
	}
    char buf[255];
    sprintf(buf,"%s_%d",tmp->name,node_id);
    agnode(syntax_graph,(char *)buf,TRUE);
    tmp->graph_node_id=node_id;
    node_id++;
	return tmp;
}

void mk_child(node *par, node *ch){
	par->child[par->cur_childs] = ch;
	par->cur_childs++;
    Agnode_t *par_node,*child_node;
    char buf[255];
    sprintf(buf,"%s_%d",par->name,par->graph_node_id);
    par_node=agnode(syntax_graph,(char *)buf,FALSE);
    sprintf(buf,"%s_%d",ch->name,ch->graph_node_id);
    child_node=agnode(syntax_graph,(char *)buf,FALSE);
    sprintf(buf,"%d",edge_id);
    agedge(syntax_graph,par_node,child_node,(char *)buf,TRUE);
    edge_id++;
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
	for (int i = 0; i < root->cur_childs; ++i){
		if(root->cur_childs == i+1){
			levels[level] = false;
		}
		printtree(root->child[i], level+1);
	}
	levels[level] = false;
	
}

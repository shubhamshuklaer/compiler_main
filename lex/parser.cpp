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
	};

	struct node *root;
	
	struct node *mk_node(const char *name);
	void mk_child(node *par, node *ch);
	void mk_sibling(node *from, node *to, bool right);

	void printtree(node *root, int level);

	node *init_tree();
    
    Agraph_t *syntax_graph;
    int node_id,edge_id,creation_id;

    Agnode_t * make_graph_node(node *);
	string main_func_name="__main__";
	string func_name=main_func_name;
	string garbage_dt="garbage";
	string data_type=garbage_dt;

	void insert_var_in_symbol_table(string func_name,string var_name,string data_type,int var_type=0,int arr_size=0);
	sym_table<func_elem,func_def> *gst_obj;
	ofstream sym_tab_out("sym_tab_out.txt");
	// #define YYSTYPE struct node *

#line 120 "parser.cpp" /* yacc.c:339  */

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
#line 55 "parser.y" /* yacc.c:355  */

	struct node *entry;
	char *terminal_value;

#line 237 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 252 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  73
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   853

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  72
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  46
/* YYNRULES -- Number of rules.  */
#define YYNRULES  148
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  267

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
       0,   206,   206,   213,   218,   222,   231,   236,   244,   253,
     266,   282,   289,   296,   306,   311,   315,   324,   329,   334,
     339,   344,   349,   356,   372,   395,   416,   423,   427,   431,
     438,   457,   465,   488,   496,   518,   526,   533,   541,   549,
     555,   562,   569,   575,   583,   590,   597,   604,   612,   620,
     624,   628,   633,   638,   643,   663,   671,   680,   685,   690,
     696,   702,   708,   722,   731,   743,   751,   758,   766,   773,
     777,   784,   792,   797,   802,   807,   812,   820,   827,   838,
     850,   858,   862,   869,   882,   890,   897,   903,   910,   916,
     922,   933,   939,   945,   951,   956,   962,   966,   970,   974,
     985,   995,  1003,  1009,  1015,  1021,  1027,  1032,  1038,  1043,
    1048,  1052,  1056,  1065,  1070,  1075,  1080,  1085,  1090,  1095,
    1103,  1108,  1116,  1124,  1129,  1137,  1142,  1147,  1152,  1157,
    1162,  1170,  1175,  1183,  1188,  1193,  1198,  1203,  1211,  1219,
    1224,  1229,  1234,  1239,  1244,  1249,  1257,  1262,  1267
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
  "for_condition", "for_update", "function_def_block", "ident",
  "argument_list_block", "general_stmt", "str", "function_call_block",
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
     325,   326
};
# endif

#define YYPACT_NINF -182

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-182)))

#define YYTABLE_NINF -108

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     450,   378,   -26,   -11,   -10,    -9,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,     5,  -182,
    -182,  -182,  -182,  -182,   224,  -182,  -182,    10,    17,    29,
      31,    36,    78,  -182,   378,   378,   346,  -182,  -182,   594,
     594,  -182,  -182,  -182,   522,   594,   346,    44,   -13,    39,
     790,    48,     9,    49,   263,  -182,    63,   106,  -182,   253,
     253,   736,   301,   253,    47,    52,    34,    46,    57,  -182,
      60,  -182,    54,  -182,   594,   378,  -182,   522,  -182,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
     263,   263,  -182,  -182,   522,  -182,  -182,   263,   263,  -182,
    -182,   -34,    50,   253,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,  -182,  -182,   224,   263,   263,   263,   224,   224,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
     253,   253,  -182,   253,   387,  -182,   263,  -182,  -182,    64,
    -182,    66,  -182,    67,  -182,    13,   253,   -19,   295,   -18,
      63,    68,    53,  -182,   346,  -182,   665,   665,   122,    36,
    -182,  -182,  -182,  -182,  -182,  -182,    91,   -13,   -13,    87,
    -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,  -182,
    -182,  -182,    88,    94,   152,   806,   129,  -182,  -182,   301,
     -15,  -182,   301,   -14,  -182,   253,   263,   263,   118,   125,
     139,   -13,   130,  -182,   141,  -182,  -182,  -182,   736,   736,
     144,    81,  -182,  -182,   301,  -182,  -182,   301,  -182,  -182,
    -182,  -182,  -182,   145,   132,  -182,  -182,   146,   147,   253,
     153,   142,   295,   143,    63,  -182,  -182,   736,   122,   206,
    -182,   162,  -182,   160,    81,   149,    81,   157,   165,  -182,
       7,   179,   736,  -182,    81,  -182,    81,  -182,   736,  -182,
    -182,   172,  -182,  -182,   175,  -182,  -182
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     0,     0,   122,   123,   124,    72,
      76,    75,    73,    74,   131,   132,   138,    12,     0,    77,
      78,    82,    11,    13,   107,     6,     7,     0,     0,     0,
       0,     0,     0,     2,     0,     0,    97,     4,    15,     0,
       0,    28,    29,    27,     0,     0,    98,     0,     0,    81,
      96,     0,   110,     0,   107,   111,     0,     0,    21,   107,
     107,     0,     0,   107,     0,     0,     0,     0,     0,    55,
       0,    63,     0,     1,     0,     0,    20,     0,     3,   125,
     126,   127,   128,   129,   130,   133,   134,   135,   136,   137,
     107,   107,    19,    18,     0,    14,    17,   107,   107,    59,
      67,    69,    71,   107,   146,   147,   148,   139,   140,   141,
     142,   143,   144,   145,   107,   107,   107,   107,   107,   107,
      60,   120,   121,   113,   114,   115,   116,   117,   118,   119,
     107,   107,    61,   107,    96,   112,   107,   106,    94,     0,
      26,     0,    31,     0,    43,     0,   107,     0,     0,     0,
       0,     0,    66,    90,   101,     8,     0,     0,    58,     0,
       5,    16,   102,   103,   104,   105,     0,     0,     0,     0,
      87,    84,    91,    92,    93,    88,    85,    89,    86,   108,
     109,    95,     0,     0,     0,     0,     0,    44,    42,     0,
       0,    39,     0,     0,    64,   107,   107,   107,     0,     0,
       0,     0,     0,    80,     0,    68,    70,    83,     0,     0,
       0,    53,    35,    40,     0,    36,    41,     0,    65,    99,
     100,     9,    10,     0,    57,    62,    79,     0,     0,   107,
       0,    49,     0,    50,     0,    37,    38,     0,    58,    23,
      30,     0,    33,     0,    53,    51,    53,    52,     0,    56,
       0,     0,     0,    45,    53,    46,    53,    54,     0,    25,
      32,     0,    47,    48,     0,    34,    24
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -182,  -182,     2,     4,   199,   -30,   -25,   -33,    -6,  -182,
    -182,  -182,  -182,  -182,  -182,  -182,  -168,  -182,  -181,   -12,
    -182,    -1,  -182,    79,   -47,    45,  -182,   -79,  -147,   -39,
    -182,  -182,   126,   -24,    56,   -16,  -182,  -182,  -182,  -182,
     -23,   -48,   -20,  -182,  -182,  -182
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    74,    35,    36,    37,    38,    39,   139,
      40,    41,   141,    42,   241,    43,   146,   186,   230,    44,
      70,   200,    45,    72,    46,   151,    47,   100,    48,    49,
     102,   204,    50,    51,    52,    53,   130,   131,    54,    55,
     115,    56,   117,    57,   118,   119
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      64,    76,   116,    58,    34,    34,    92,    93,    65,   101,
       2,   201,    96,    90,   150,   147,    91,   121,   122,    95,
     166,   212,    77,    97,   215,    59,    98,   137,   143,   188,
     191,    19,    20,   213,   216,   167,   155,    78,   149,    34,
      60,    76,    62,   140,   142,    61,   235,   152,    94,   236,
     189,   192,   161,    66,   214,   217,    63,    19,    20,    21,
      67,    76,   258,   253,   145,   255,   123,   124,   125,   126,
     127,   128,    68,   262,    69,   263,    17,   160,    73,    34,
     129,    94,    77,    22,    23,    71,   116,   169,   205,   206,
     170,   201,    99,   103,   175,   177,   120,   132,   171,   153,
     190,   156,   176,   178,   154,    14,    15,    19,    20,    21,
     135,   158,   157,   159,   179,   180,   182,    65,   183,   168,
     194,    64,   195,   184,    18,    19,    20,    21,   101,   101,
     187,   196,   145,   203,   197,     9,    10,    11,    12,    13,
     207,   150,   147,   208,   150,   147,   162,   163,    17,   209,
      19,    20,    21,   164,   165,    22,    23,   210,   198,   199,
      34,    34,   224,   234,   231,   149,   150,   147,   149,   150,
     147,   172,   173,   174,   221,   227,   228,   211,   225,   152,
     134,   222,   136,   138,   245,   134,   134,   233,   148,   134,
     149,   223,   181,   149,   226,   229,   234,   231,   234,   231,
     237,   238,   239,   240,   248,   243,   234,   231,   234,   231,
     250,   244,   246,   242,   251,   252,   134,   134,   254,   261,
     233,   257,   233,   134,   134,   264,   256,   260,   265,   134,
     233,   266,   233,    75,     6,     7,     8,   249,   202,     0,
     218,   134,   134,   134,   259,     0,     0,     0,    14,    15,
      16,     0,   219,   220,     0,     0,   134,   134,     0,   134,
       0,     0,   134,     6,     7,     8,    17,    18,    19,    20,
      21,   185,   134,    22,    23,    24,   193,    14,    15,    16,
       0,     0,     0,     0,     0,     0,     0,    14,    15,    16,
       0,     0,     0,     0,     0,    17,    18,    19,    20,    21,
       0,     0,    22,    23,   133,    17,    18,    19,    20,    21,
       0,     0,    22,    23,   133,   148,     0,     0,   148,    14,
      15,   134,   134,   134,     0,    14,    15,   104,   105,   106,
     107,   108,   109,   110,   111,   112,   113,   232,     0,     0,
     148,     0,   114,   148,    18,    19,    20,    21,     0,   144,
       0,     0,   145,     0,     0,   134,     0,     0,     0,     0,
     247,     0,     0,     0,    79,    80,    81,    82,    83,    84,
     232,     0,   232,    85,    86,    87,    88,    89,   -22,     1,
     232,     2,   232,     3,     4,     5,  -107,  -107,     6,     7,
       8,     9,    10,    11,    12,    13,     0,     0,     0,     0,
       0,     0,    14,    15,    16,    79,    80,    81,    82,    83,
      84,    14,    15,     0,    85,    86,    87,    88,    89,     0,
      17,    18,    19,    20,    21,     0,  -107,    22,    23,    24,
       0,     0,     0,     0,   -22,  -107,  -107,  -107,  -107,  -107,
    -107,    25,    26,    27,    28,    29,    30,     0,    31,  -107,
     -22,     1,     0,     2,     0,     3,     4,     5,  -107,  -107,
       6,     7,     8,     9,    10,    11,    12,    13,     0,     0,
       0,     0,     0,     0,    14,    15,    16,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    17,    18,    19,    20,    21,     0,  -107,    22,
      23,    24,     0,     0,     0,     0,     0,  -107,  -107,  -107,
    -107,  -107,  -107,    25,    26,    27,    28,    29,    30,     0,
      31,  -107,   -22,     1,     0,     2,     0,     3,     4,     5,
    -107,  -107,     6,     7,     8,     9,    10,    11,    12,    13,
       0,     0,     0,     0,     0,     0,    14,    15,    16,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    17,    18,    19,    20,    21,     0,
    -107,    22,    23,    24,     0,     0,     0,     0,   -22,  -107,
    -107,  -107,  -107,  -107,  -107,    25,    26,     0,     0,     0,
      30,     0,    31,  -107,   -22,     1,     0,     2,     0,     3,
       4,     5,  -107,  -107,     6,     7,     8,     9,    10,    11,
      12,    13,     0,     0,     0,     0,     0,     0,    14,    15,
      16,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    17,    18,    19,    20,
      21,     0,  -107,    22,    23,    24,     0,     0,     0,     0,
     -22,  -107,  -107,  -107,  -107,  -107,  -107,    25,    26,     0,
       0,     0,     0,     0,    31,  -107,     1,     0,     2,     0,
       3,     4,     5,  -107,  -107,     6,     7,     8,     9,    10,
      11,    12,    13,     0,     0,     0,     0,     0,     0,    14,
      15,    16,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    17,    18,    19,
      20,    21,     0,  -107,    22,    23,    24,     0,     0,     0,
       0,   -22,  -107,  -107,  -107,  -107,  -107,  -107,    25,    26,
      27,    28,    29,    30,     0,    31,  -107,     1,     0,     2,
       0,     3,     4,     5,  -107,  -107,     6,     7,     8,     9,
      10,    11,    12,    13,     0,     0,     0,     0,     0,     0,
      14,    15,    16,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    17,    18,
      19,    20,    21,     0,  -107,    22,    23,    24,     0,     0,
       0,     0,   -22,  -107,  -107,  -107,  -107,  -107,  -107,    25,
      26,     0,     0,     0,     0,     0,    31,  -107,    79,    80,
      81,    82,    83,    84,    14,    15,     0,    85,    86,    87,
      88,    89,   104,   105,   106,   107,   108,   109,   110,   111,
     112,   113,     0,     0,     0,     0,     0,   114,   104,   105,
     106,   107,   108,   109,   110,   111,   112,   113,     0,     0,
       0,     0,     0,   114
};

static const yytype_int16 yycheck[] =
{
      24,    34,    50,     1,     0,     1,    39,    40,    24,    48,
       3,   158,    45,    36,    62,    62,    36,     8,     9,    44,
      54,   189,    34,    46,   192,    51,    46,    57,    61,    48,
      48,    44,    45,    48,    48,    69,    66,    35,    62,    35,
      51,    74,    51,    59,    60,    55,   214,    63,    44,   217,
      69,    69,    77,    43,    69,    69,    51,    44,    45,    46,
      43,    94,    55,   244,    51,   246,    57,    58,    59,    60,
      61,    62,    43,   254,    43,   256,    42,    75,     0,    75,
      71,    77,    94,    49,    50,    49,   134,   103,   167,   168,
     114,   238,    48,    54,   118,   119,    48,    48,   114,    52,
     148,    55,   118,   119,    52,    24,    25,    44,    45,    46,
      54,    51,    55,    59,   130,   131,    52,   133,    52,    69,
      52,   145,    69,    56,    43,    44,    45,    46,   167,   168,
     146,   154,    51,    42,   154,    13,    14,    15,    16,    17,
      53,   189,   189,    55,   192,   192,    90,    91,    42,    55,
      44,    45,    46,    97,    98,    49,    50,     5,   156,   157,
     156,   157,   201,   211,   211,   189,   214,   214,   192,   217,
     217,   115,   116,   117,    56,   208,   209,    48,    48,   195,
      54,    56,    56,    57,   232,    59,    60,   211,    62,    63,
     214,    52,   136,   217,    53,    51,   244,   244,   246,   246,
      55,    69,    56,    56,   237,    52,   254,   254,   256,   256,
       4,    69,    69,   229,    52,    55,    90,    91,    69,   252,
     244,    56,   246,    97,    98,   258,    69,    48,    56,   103,
     254,    56,   256,    34,    10,    11,    12,   238,   159,    -1,
     195,   115,   116,   117,   250,    -1,    -1,    -1,    24,    25,
      26,    -1,   196,   197,    -1,    -1,   130,   131,    -1,   133,
      -1,    -1,   136,    10,    11,    12,    42,    43,    44,    45,
      46,   145,   146,    49,    50,    51,   150,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,
      -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,    42,    43,    44,    45,    46,
      -1,    -1,    49,    50,    51,   189,    -1,    -1,   192,    24,
      25,   195,   196,   197,    -1,    24,    25,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,   211,    -1,    -1,
     214,    -1,    47,   217,    43,    44,    45,    46,    -1,    48,
      -1,    -1,    51,    -1,    -1,   229,    -1,    -1,    -1,    -1,
     234,    -1,    -1,    -1,    18,    19,    20,    21,    22,    23,
     244,    -1,   246,    27,    28,    29,    30,    31,     0,     1,
     254,     3,   256,     5,     6,     7,     8,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,
      -1,    -1,    24,    25,    26,    18,    19,    20,    21,    22,
      23,    24,    25,    -1,    27,    28,    29,    30,    31,    -1,
      42,    43,    44,    45,    46,    -1,    48,    49,    50,    51,
      -1,    -1,    -1,    -1,    56,    57,    58,    59,    60,    61,
      62,    63,    64,    65,    66,    67,    68,    -1,    70,    71,
       0,     1,    -1,     3,    -1,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    -1,    -1,
      -1,    -1,    -1,    -1,    24,    25,    26,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    42,    43,    44,    45,    46,    -1,    48,    49,
      50,    51,    -1,    -1,    -1,    -1,    -1,    57,    58,    59,
      60,    61,    62,    63,    64,    65,    66,    67,    68,    -1,
      70,    71,     0,     1,    -1,     3,    -1,     5,     6,     7,
       8,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      -1,    -1,    -1,    -1,    -1,    -1,    24,    25,    26,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    42,    43,    44,    45,    46,    -1,
      48,    49,    50,    51,    -1,    -1,    -1,    -1,    56,    57,
      58,    59,    60,    61,    62,    63,    64,    -1,    -1,    -1,
      68,    -1,    70,    71,     0,     1,    -1,     3,    -1,     5,
       6,     7,     8,     9,    10,    11,    12,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,    45,
      46,    -1,    48,    49,    50,    51,    -1,    -1,    -1,    -1,
      56,    57,    58,    59,    60,    61,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    70,    71,     1,    -1,     3,    -1,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,
      25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,    44,
      45,    46,    -1,    48,    49,    50,    51,    -1,    -1,    -1,
      -1,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    -1,    70,    71,     1,    -1,     3,
      -1,     5,     6,     7,     8,     9,    10,    11,    12,    13,
      14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,    -1,
      24,    25,    26,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    42,    43,
      44,    45,    46,    -1,    48,    49,    50,    51,    -1,    -1,
      -1,    -1,    56,    57,    58,    59,    60,    61,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    70,    71,    18,    19,
      20,    21,    22,    23,    24,    25,    -1,    27,    28,    29,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,    41,    -1,    -1,    -1,    -1,    -1,    47,    32,    33,
      34,    35,    36,    37,    38,    39,    40,    41,    -1,    -1,
      -1,    -1,    -1,    47
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     5,     6,     7,    10,    11,    12,    13,
      14,    15,    16,    17,    24,    25,    26,    42,    43,    44,
      45,    46,    49,    50,    51,    63,    64,    65,    66,    67,
      68,    70,    73,    74,    75,    76,    77,    78,    79,    80,
      82,    83,    85,    87,    91,    94,    96,    98,   100,   101,
     104,   105,   106,   107,   110,   111,   113,   115,    74,    51,
      51,    55,    51,    51,   105,   107,    43,    43,    43,    43,
      92,    49,    95,     0,    75,    76,    79,    91,    74,    18,
      19,    20,    21,    22,    23,    27,    28,    29,    30,    31,
     112,   114,    79,    79,    75,    78,    79,   112,   114,    48,
      99,   101,   102,    54,    32,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    47,   112,   113,   114,   116,   117,
      48,     8,     9,    57,    58,    59,    60,    61,    62,    71,
     108,   109,    48,    51,   104,   106,   104,    77,   104,    81,
     107,    84,   107,    79,    48,    51,    88,    96,   104,   105,
     113,    97,   107,    52,    52,    77,    55,    55,    51,    59,
      74,    78,   106,   106,   106,   106,    54,    69,    69,   107,
     105,   107,   106,   106,   106,   105,   107,   105,   107,   107,
     107,   106,    52,    52,    56,   104,    89,   107,    48,    69,
     113,    48,    69,   104,    52,    69,   112,   114,    74,    74,
      93,   100,    95,    42,   103,    99,    99,    53,    55,    55,
       5,    48,    88,    48,    69,    88,    48,    69,    97,   106,
     106,    56,    56,    52,   101,    48,    53,    79,    79,    51,
      90,    96,   104,   105,   113,    88,    88,    55,    69,    56,
      56,    86,   107,    52,    69,   113,    69,   104,    79,    93,
       4,    52,    55,    90,    69,    90,    69,    56,    55,    80,
      48,    79,    90,    90,    79,    56,    56
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    72,    73,    74,    74,    74,    75,    75,    76,    76,
      76,    77,    77,    77,    78,    78,    78,    79,    79,    79,
      79,    79,    79,    80,    80,    80,    81,    82,    82,    82,
      83,    84,    85,    86,    87,    88,    88,    88,    88,    88,
      88,    88,    88,    88,    89,    90,    90,    90,    90,    90,
      90,    90,    90,    90,    91,    92,    93,    93,    93,    94,
      94,    94,    94,    95,    96,    97,    97,    98,    99,    99,
      99,    99,   100,   100,   100,   100,   100,   101,   101,   102,
     103,   104,   104,   104,   105,   105,   105,   105,   105,   105,
     105,   106,   106,   106,   106,   106,   106,   106,   106,   106,
     106,   106,   106,   106,   106,   106,   106,   106,   107,   107,
     107,   107,   107,   108,   108,   108,   108,   108,   108,   108,
     109,   109,   110,   111,   111,   112,   112,   112,   112,   112,
     112,   113,   113,   114,   114,   114,   114,   114,   115,   116,
     116,   116,   116,   116,   116,   116,   117,   117,   117
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
       2,     2,     5,     1,     4,     3,     1,     2,     3,     1,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     4,
       1,     1,     1,     4,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     2,     3,     1,     1,     1,     5,
       5,     3,     3,     3,     3,     3,     2,     0,     3,     3,
       1,     1,     2,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1
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
#line 206 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = root;
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1653 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 213 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1663 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 218 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 1672 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 222 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("start_block");
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 1683 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 231 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("comment_block");	
							(yyvsp[0].entry) = mk_node("COMMENT");		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1693 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 236 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("comment_block");	
							(yyvsp[0].entry) = mk_node("MULTI_COMMENT");		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1703 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 244 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("defination_block");	
							(yyvsp[-2].entry) = mk_node("DEFINE");			
							(yyvsp[-1].entry) = mk_node("IDENT");		
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 1717 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 254 "parser.y" /* yacc.c:1646  */
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
#line 1734 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 267 "parser.y" /* yacc.c:1646  */
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
#line 1751 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 282 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("STRING");		
							mk_child((yyvsp[0].entry), temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1763 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 289 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("NUM");
							mk_child((yyvsp[0].entry), temp);		
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1775 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 296 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("const_block");	
							(yyvsp[0].entry) = mk_node("CHARACTER");		
							mk_child((yyvsp[0].entry), temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1787 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 306 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1797 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 311 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1806 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 315 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 											
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1817 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 324 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1827 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 329 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1837 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 334 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1847 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 339 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1857 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 344 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("error");
							mk_child((yyval.entry), (yyvsp[0].entry));
							yyclearin;
						}
#line 1867 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 349 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("/general_block");
						}
#line 1875 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 356 "parser.y" /* yacc.c:1646  */
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
#line 1896 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 372 "parser.y" /* yacc.c:1646  */
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
#line 1924 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 395 "parser.y" /* yacc.c:1646  */
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
#line 1947 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 416 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
							(yyval.entry) = mk_node("if_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1956 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 423 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1965 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 427 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1974 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 431 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("loop_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 1983 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 438 "parser.y" /* yacc.c:1646  */
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
#line 2004 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 457 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
							(yyval.entry) = mk_node("while_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2014 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 465 "parser.y" /* yacc.c:1646  */
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
#line 2039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 488 "parser.y" /* yacc.c:1646  */
    {// explicit check for NILL condition 
							(yyval.entry) = mk_node("do_while_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2049 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 496 "parser.y" /* yacc.c:1646  */
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
#line 2073 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 518 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2086 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 526 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2098 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 533 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[-1].entry) = mk_node("COMMA");											
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2111 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 541 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2124 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 549 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[0].entry) = mk_node("TERMINATOR");											
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2135 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 555 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[0].entry) = mk_node("TERMINATOR");										
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2147 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 562 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");					
							(yyvsp[0].entry) = mk_node("TERMINATOR");											
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2159 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 569 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");				
							(yyvsp[0].entry) = mk_node("TERMINATOR");
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2170 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 575 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_initialization");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2180 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 583 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_condition");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 590 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");									
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2201 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 597 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");									
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2213 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 604 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2226 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 612 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");						
							(yyvsp[-1].entry) = mk_node("COMMA");										
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2239 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 620 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2248 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 624 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2257 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 628 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2267 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 633 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("for_update");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2277 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 638 "parser.y" /* yacc.c:1646  */
    {
						}
#line 2284 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 643 "parser.y" /* yacc.c:1646  */
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
							func_name=main_func_name;
						}
#line 2306 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 663 "parser.y" /* yacc.c:1646  */
    {
						(yyval.entry) = mk_node("IDENT");
						struct node *temp = mk_node(yylval.terminal_value);
						func_name=string(yylval.terminal_value);
						mk_child((yyval.entry),temp);
						}
#line 2317 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 671 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("argument_list_block");			
							(yyvsp[-1].entry) = mk_node("COMMA");
							(yyvsp[-3].entry) = mk_node("INT");												
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2331 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 680 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("argument_list_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2341 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 685 "parser.y" /* yacc.c:1646  */
    {
						}
#line 2348 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 690 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");			
							(yyvsp[0].entry) = mk_node("TERMINATOR");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2359 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 696 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2370 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 702 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("general_stmt");		
							(yyvsp[0].entry) = mk_node("TERMINATOR");													
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2381 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 709 "parser.y" /* yacc.c:1646  */
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
#line 2397 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 723 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("STRING");
							mk_child((yyval.entry), temp);
						}
#line 2407 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 731 "parser.y" /* yacc.c:1646  */
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
#line 2422 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 744 "parser.y" /* yacc.c:1646  */
    {
					   	 (yyval.entry) = mk_node("function_var_list");
					   	 (yyvsp[-1].entry) = mk_node("COMMA");
					   	 mk_child((yyval.entry), (yyvsp[-2].entry));
					   	 mk_child((yyval.entry), (yyvsp[-1].entry));
					   	 mk_child((yyval.entry), (yyvsp[0].entry));
					   }
#line 2434 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 751 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("function_var_list");
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2443 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 758 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("declaration_block");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2453 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 766 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");			
							(yyvsp[-1].entry) = mk_node("COMMA");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2465 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 773 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2474 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 777 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");				
							(yyvsp[-1].entry) = mk_node("COMMA");											
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2486 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 784 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("var_list");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2495 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 792 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");		
							(yyvsp[0].entry) = mk_node("INT");									
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2505 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 797 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("FLOAT");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2515 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 802 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");		
							(yyvsp[0].entry) = mk_node("DOUBLE");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2525 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 807 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("CHAR");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2535 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 812 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("data_type");			
							(yyvsp[0].entry) = mk_node("LONG");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 820 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("var_block");			
							(yyvsp[0].entry) = mk_node("VAR");												
							mk_child((yyvsp[0].entry),temp);
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2557 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 827 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("var_block");			
							(yyvsp[0].entry) = mk_node("POINTER");												
							mk_child((yyvsp[0].entry),temp);
							mk_child((yyval.entry), (yyvsp[0].entry));

						}
#line 2570 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 838 "parser.y" /* yacc.c:1646  */
    {//check for expr to return positive value. Run time check for negeative value.
							(yyval.entry) = mk_node("array_block");	
							(yyvsp[-2].entry) = mk_node("OB");	
							(yyvsp[0].entry) = mk_node("CB");												
							mk_child((yyval.entry), (yyvsp[-3].entry));
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2584 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 850 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp=mk_node(yyval.terminal_value);
							(yyval.entry) = mk_node("NUM");
							mk_child((yyval.entry),temp);
						}
#line 2594 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 858 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("ass_var_block");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2603 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 862 "parser.y" /* yacc.c:1646  */
    {
							struct node *temp = mk_node(yylval.terminal_value);
							(yyval.entry) = mk_node("ass_var_block");		
							(yyvsp[0].entry) = mk_node("DREF");
							mk_child((yyvsp[0].entry),temp);											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2615 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 869 "parser.y" /* yacc.c:1646  */
    {// check if expr is returning a index present in the array. 
							(yyval.entry) = mk_node("ass_var_block");		
							(yyvsp[-2].entry) = mk_node("OB");	
							(yyvsp[0].entry) = mk_node("CB");											
							mk_child((yyval.entry), (yyvsp[-3].entry)); 
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2630 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 882 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");	
							(yyvsp[-1].entry) = mk_node("ASSIGN");													
							mk_child((yyval.entry), (yyvsp[-2].entry));
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							 
						}
#line 2643 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 890 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
							
						}
#line 2655 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 897 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2666 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 903 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							(yyvsp[-1].entry) = mk_node("ASSIGN");													
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2678 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 910 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2689 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 916 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2700 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 922 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("assignment_block");	
							(yyval.entry) = mk_node("expr");	
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry));
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2713 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 933 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2724 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 939 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 945 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2746 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 951 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2756 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 956 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2767 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 962 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2776 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 966 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 970 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2794 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 974 "parser.y" /* yacc.c:1646  */
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
#line 2810 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 985 "parser.y" /* yacc.c:1646  */
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
#line 2825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 995 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");	
							(yyvsp[-2].entry) = mk_node("OP");	
							(yyvsp[0].entry) = mk_node("CP");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2838 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 1003 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2849 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 1009 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2860 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 1015 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2871 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 1021 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 							
							mk_child((yyval.entry), (yyvsp[0].entry));
						}
#line 2882 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 1027 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2892 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 1032 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("expr");
						}
#line 2900 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 1038 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
						}
#line 2910 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 1043 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-2].entry)); 
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
						}
#line 2920 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 1048 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2929 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 1052 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2938 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 1056 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("conditional_expr");												
							mk_child((yyval.entry), (yyvsp[-1].entry)); 
							mk_child((yyval.entry), (yyvsp[0].entry)); 
							
						}
#line 2949 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 1065 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("EQ");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2959 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 1070 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("NOTEQ");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2969 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 1075 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("GT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2979 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 1080 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2989 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 1085 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("GE");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 2999 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 1090 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LE");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3009 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 1095 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_condition_op");
							(yyvsp[0].entry) = mk_node("LTGT");
							mk_child((yyval.entry),(yyvsp[0].entry));
						}
#line 3019 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 1103 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_condition_op");
							(yyvsp[0].entry) = mk_node("AND");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3029 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 1108 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_condition_op");
							(yyvsp[0].entry) = mk_node("OR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3039 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 1116 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_unary_condition_op");
							(yyvsp[0].entry) = mk_node("NOT_1");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3049 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 1124 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("fixed_condition");
							(yyvsp[0].entry) = mk_node("TRUE_1");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3059 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 1129 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("fixed_condition");
							(yyvsp[0].entry) = mk_node("FALSE_1");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3069 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 1137 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("ADD");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3079 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 1142 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("SUB");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3089 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 1147 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("MULT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3099 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 1152 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("DIV");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3109 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 1157 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("EXP");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3119 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 1162 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_binary_op");
							(yyvsp[0].entry) = mk_node("MOD");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3129 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 1170 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_unary_op");
							(yyvsp[0].entry) = mk_node("INC");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3139 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 1175 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_unary_op");
							(yyvsp[0].entry) = mk_node("DEC");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3149 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 1183 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_AND");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3159 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 1188 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_OR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3169 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 1193 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_XOR");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3179 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 1198 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_LEFT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3189 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 1203 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_binary_op");
							(yyvsp[0].entry) = mk_node("BIN_RIGHT");														
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3199 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 1211 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_unary_op");		
							(yyvsp[0].entry) = mk_node("ADD_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3209 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 1219 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("ADD_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3219 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 1224 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("SUB_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3229 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 1229 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("MULT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3239 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 1234 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("DIV_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3249 "parser.cpp" /* yacc.c:1646  */
    break;

  case 143:
#line 1239 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("MOD_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3259 "parser.cpp" /* yacc.c:1646  */
    break;

  case 144:
#line 1244 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("LEFT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3269 "parser.cpp" /* yacc.c:1646  */
    break;

  case 145:
#line 1249 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("arith_assgn_op");
							(yyvsp[0].entry) = mk_node("RIGHT_ASSIGN");													
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3279 "parser.cpp" /* yacc.c:1646  */
    break;

  case 146:
#line 1257 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");
							(yyvsp[0].entry) = mk_node("BIN_AND_ASSIGN");											
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3289 "parser.cpp" /* yacc.c:1646  */
    break;

  case 147:
#line 1262 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");	
							(yyvsp[0].entry) = mk_node("BIN_IOR_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3299 "parser.cpp" /* yacc.c:1646  */
    break;

  case 148:
#line 1267 "parser.y" /* yacc.c:1646  */
    {
							(yyval.entry) = mk_node("bit_assgn_op");	
							(yyvsp[0].entry) = mk_node("BIN_XOR_ASSIGN");												
							mk_child((yyval.entry), (yyvsp[0].entry)); 
						}
#line 3309 "parser.cpp" /* yacc.c:1646  */
    break;


#line 3313 "parser.cpp" /* yacc.c:1646  */
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
#line 1275 "parser.y" /* yacc.c:1906  */


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
    FILE *fp=fopen("syntax_graph.gv","w+");
    agwrite(syntax_graph,fp);
    fclose(fp);
	gst_obj->print(sym_tab_out);
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
		struct node *var_list_child=root->child[1]->child[0];
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
	}else if(strcmp(root->name,"function_def_block")==0){
		struct node *func_name_node=root->child[1];
		struct node *argument_list_block=root->child[3];
		string temp_func_name=string(func_name_node->child[0]->name);
		vector<pair<string,var_def*> > temp_arg_list;
		//Now finding the argument list
		while(argument_list_block!=NULL){
			//Finding the data type
			struct node *data_type_node=argument_list_block->child[0];
			string tdt;
			tdt=string(root->child[0]->child[0]->name);	
			transform(tdt.begin(),tdt.end(),tdt.begin(),::tolower);
			
			//Finding the variable name
			struct node *var_block_node=argument_list_block->child[1];
			if(argument_list_block->cur_childs==4)
				argument_list_block=argument_list_block->child[3];
			else
				argument_list_block=NULL;
		}	
		////////////////////////////////////////
		gst_obj->insert(temp_func_name,new func_def(temp_arg_list,""));
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

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
	#include <stdio.h>
	#include <string.h>

	#include "header.h"
	int yylex(void);
	void yyerror(const char *);

	struct node{
		struct node *child[MAX_CHILD], *left_sib, *right_sib;
		char *name;
		int cur_childs;
	};

	struct node *root;
	
	struct node *mk_node(const char *name);
	void mk_child(node *par, node *ch);
	void mk_sibling(node *from, node *to, bool right);

	void printtree(node *root, int level);

	node *init_tree();

	// #define YYSTYPE struct node *

#line 95 "parser.cpp" /* yacc.c:339  */

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
    NOT = 265,
    TRUE = 266,
    FALSE = 267,
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
    QUES = 281,
    BIN_NOT = 282,
    BIN_AND = 283,
    BIN_OR = 284,
    BIN_XOR = 285,
    BIN_LEFT = 286,
    BIN_RIGHT = 287,
    BIN_AND_ASSIGN = 288,
    BIN_IOR_ASSIGN = 289,
    BIN_XOR_ASSIGN = 290,
    ADD_ASSIGN = 291,
    SUB_ASSIGN = 292,
    MULT_ASSIGN = 293,
    DIV_ASSIGN = 294,
    MOD_ASSIGN = 295,
    LEFT_ASSIGN = 296,
    RIGHT_ASSIGN = 297,
    NUM = 298,
    IDENT = 299,
    VAR = 300,
    POINTER = 301,
    DREF = 302,
    ASSIGN = 303,
    TERMINATOR = 304,
    COLON = 305,
    STRING = 306,
    CHARACTER = 307,
    OP = 308,
    CP = 309,
    CB = 310,
    OB = 311,
    OCB = 312,
    CCB = 313,
    EQ = 314,
    NOTEQ = 315,
    GT = 316,
    LT = 317,
    GE = 318,
    LE = 319,
    COMMENT = 320,
    MULTI_COMMENT = 321,
    WHITESPACE = 322,
    DEFINE = 323,
    IFDEF = 324,
    IFNDEF = 325,
    FUNCTION = 326,
    COMMA = 327,
    SYN_ERROR = 328,
    PRINT = 329,
    LTGT = 330
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 30 "parser.y" /* yacc.c:355  */

	int num;
	char *str;
	int type;
	struct node *entry;

#line 218 "parser.cpp" /* yacc.c:355  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_HPP_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 233 "parser.cpp" /* yacc.c:358  */

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
#define YYFINAL  63
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   630

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  76
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  43
/* YYNRULES -- Number of rules.  */
#define YYNRULES  142
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  249

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   330

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
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   185,   185,   191,   196,   200,   209,   214,   222,   234,
     239,   244,   252,   256,   260,   267,   271,   275,   279,   283,
     289,   305,   328,   342,   349,   353,   357,   364,   376,   383,
     396,   403,   417,   422,   427,   432,   437,   442,   447,   452,
     457,   465,   472,   477,   482,   487,   492,   496,   500,   504,
     508,   513,   526,   531,   535,   540,   545,   550,   559,   567,
     574,   579,   583,   588,   595,   599,   603,   607,   614,   619,
     624,   629,   634,   642,   647,   655,   662,   666,   670,   677,
     681,   685,   689,   693,   697,   701,   708,   712,   716,   720,
     724,   728,   732,   736,   740,   744,   748,   752,   756,   760,
     764,   768,   772,   778,   782,   786,   790,   794,   801,   806,
     811,   816,   821,   826,   834,   839,   847,   855,   860,   868,
     873,   878,   883,   888,   893,   901,   906,   914,   919,   924,
     929,   934,   942,   950,   955,   960,   965,   970,   975,   980,
     988,   993,   998
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "DO", "FOR",
  "AND", "OR", "NOT", "TRUE", "FALSE", "INT", "LONG", "CHAR", "FLOAT",
  "DOUBLE", "ADD", "SUB", "MULT", "DIV", "EXP", "MOD", "INC", "DEC",
  "QUES", "BIN_NOT", "BIN_AND", "BIN_OR", "BIN_XOR", "BIN_LEFT",
  "BIN_RIGHT", "BIN_AND_ASSIGN", "BIN_IOR_ASSIGN", "BIN_XOR_ASSIGN",
  "ADD_ASSIGN", "SUB_ASSIGN", "MULT_ASSIGN", "DIV_ASSIGN", "MOD_ASSIGN",
  "LEFT_ASSIGN", "RIGHT_ASSIGN", "NUM", "IDENT", "VAR", "POINTER", "DREF",
  "ASSIGN", "TERMINATOR", "COLON", "STRING", "CHARACTER", "OP", "CP", "CB",
  "OB", "OCB", "CCB", "EQ", "NOTEQ", "GT", "LT", "GE", "LE", "COMMENT",
  "MULTI_COMMENT", "WHITESPACE", "DEFINE", "IFDEF", "IFNDEF", "FUNCTION",
  "COMMA", "SYN_ERROR", "PRINT", "LTGT", "$accept", "super_block",
  "start_block", "comment_block", "defination_block", "const_block",
  "block", "general_block", "if_else_block", "if_condition", "loop_block",
  "while_loop_block", "while_condition", "do_while_loop_block",
  "do_while_condition", "for_loop_block", "for_initialization",
  "for_condition", "for_update", "function_def_block",
  "argument_list_block", "general_stmt", "function_call_block",
  "declaration_block", "var_list", "ass_var_list", "data_type",
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
     325,   326,   327,   328,   329,   330
};
# endif

#define YYPACT_NINF -177

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-177)))

#define YYTABLE_NINF -103

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     360,   -21,    -6,    -3,     5,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,    15,  -177,  -177,  -177,  -177,  -177,
     273,  -177,  -177,    34,    38,    29,  -177,   360,   360,   598,
    -177,  -177,   494,   494,  -177,  -177,  -177,   427,   494,   598,
      48,    -9,    43,   533,    51,    53,   117,   101,   412,   412,
     494,   198,   101,  -177,  -177,  -177,    50,    61,    52,   479,
    -177,    20,    58,  -177,   494,   360,  -177,   427,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
     479,   479,  -177,  -177,   427,  -177,  -177,   479,   479,  -177,
    -177,   -15,    40,   479,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,   273,   479,   479,   479,   273,   273,
    -177,  -177,   479,  -177,  -177,   412,    81,   583,  -177,    82,
    -177,    80,  -177,    62,   412,   -32,   552,   -16,   117,    44,
      86,    70,  -177,  -177,  -177,  -177,  -177,  -177,  -177,  -177,
    -177,   412,   412,   598,  -177,  -177,   116,  -177,  -177,  -177,
    -177,  -177,  -177,   479,    -9,    -9,    90,  -177,  -177,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -177,    92,    94,   151,
     448,   110,  -177,  -177,   198,   -11,  -177,   198,    -7,   101,
    -177,   101,  -177,  -177,   479,   479,   106,    -9,   111,  -177,
    -177,  -177,   494,   494,   112,   297,  -177,  -177,   198,  -177,
    -177,   198,  -177,  -177,  -177,  -177,   115,    97,  -177,   118,
     119,   412,   125,   108,   552,   113,   117,  -177,  -177,   494,
     116,   169,  -177,   128,  -177,   127,   297,   120,   297,   121,
     129,  -177,     7,   140,   494,  -177,   297,  -177,   297,  -177,
     494,  -177,  -177,   132,  -177,  -177,   133,  -177,  -177
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
      19,     0,     0,     0,     0,    68,    72,    71,    69,    70,
     125,   126,   132,    10,     0,    73,    74,    77,     9,    11,
     102,     6,     7,     0,     0,     0,     2,    19,    19,    92,
       4,    13,    19,    19,    25,    26,    24,    19,    19,    93,
       0,     0,    76,    91,     0,     0,     0,     0,   102,   102,
      19,     0,     0,   116,   117,   118,     0,   105,     0,   102,
     106,     0,     0,     1,    19,    19,    18,    19,     3,   119,
     120,   121,   122,   123,   124,   127,   128,   129,   130,   131,
     102,   102,    17,    16,    19,    12,    15,   102,   102,    55,
      59,    61,    63,   102,   140,   141,   142,   133,   134,   135,
     136,   137,   138,   139,   102,   102,   102,   102,   102,   102,
      56,    57,   102,   101,    89,   102,     0,    91,    23,     0,
      28,     0,    40,     0,   102,     0,     0,     0,     0,    67,
       0,    65,    85,   114,   115,   108,   109,   110,   111,   112,
     113,   102,   102,    96,   107,     8,    54,     5,    14,    97,
      98,    99,   100,   102,     0,     0,     0,    82,    79,    86,
      87,    88,    83,    80,    84,    81,    90,     0,     0,     0,
       0,     0,    41,    39,     0,     0,    36,     0,     0,     0,
      58,     0,   103,   104,   102,   102,     0,     0,     0,    60,
      62,    78,    19,    19,     0,    50,    32,    37,     0,    33,
      38,     0,    66,    64,    94,    95,     0,    53,    75,     0,
       0,   102,     0,    46,     0,    47,     0,    34,    35,    19,
      54,    20,    27,     0,    30,     0,    50,    48,    50,    49,
       0,    52,     0,     0,    19,    42,    50,    43,    50,    51,
      19,    22,    29,     0,    44,    45,     0,    31,    21
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -177,  -177,   -12,    18,   168,   -38,   -18,   -25,   -29,  -177,
    -177,  -177,  -177,  -177,  -177,  -177,  -150,  -177,  -176,     3,
     -13,  -177,    54,  -177,  -111,  -153,  -145,   -37,  -177,   153,
     -20,   -14,   -28,  -177,  -177,  -177,  -177,   -24,   -40,   -17,
    -177,  -177,  -177
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    25,    26,    64,    28,    29,    30,    31,    32,   116,
      33,    34,   119,    35,   223,    36,   124,   171,   212,    37,
     186,    38,    39,    40,    90,   130,    41,    42,    92,    43,
      44,    45,    58,   141,   142,    59,    60,   105,    46,   107,
      47,   108,   109
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      56,   187,    66,   106,    91,    80,    57,    82,    83,   113,
       1,   128,    81,    86,   129,    87,    68,   173,    27,    85,
     118,   120,    88,   145,   196,   121,   202,   199,   203,    63,
      67,   127,    48,   176,    57,    57,    15,    16,   197,    66,
     174,   153,   200,   189,   190,   144,    27,    49,   217,   148,
     235,   218,   237,   147,    50,    84,   177,   154,    51,    66,
     244,   198,   245,    13,   240,   201,   149,   150,    52,   133,
     134,    18,    19,   151,   152,   187,   158,   106,    61,   156,
     163,   165,    62,    27,   157,    84,   175,    67,   162,   164,
      57,   159,   160,   161,    57,    57,   172,    89,   166,    93,
     110,    57,   111,    56,   132,   125,   143,    15,    16,    17,
      57,   146,   155,   182,   183,   123,   179,    91,    91,   184,
     135,   136,   137,   138,   139,   140,   185,    57,    57,     5,
       6,     7,     8,     9,   128,   167,   168,   128,   169,   188,
     180,   129,   181,   129,    13,   191,    15,    16,    17,   192,
     207,   193,    18,    19,   127,   216,   194,   127,   128,   195,
     206,   128,    15,    16,    17,   211,   208,   209,   210,   220,
     204,   205,   219,   232,   227,   215,   221,   222,   127,   225,
     226,   127,   233,   224,   234,   228,   216,   239,   216,   242,
     247,   248,   236,   238,   230,    65,   216,    57,   216,   112,
     114,   117,   117,   241,   126,   131,   215,   231,   215,   243,
       0,     0,   117,     0,     0,   246,   215,     0,   215,     0,
       0,     0,    10,    11,     0,     0,     0,     0,   125,     0,
       0,   125,     0,   117,   117,     0,     0,     0,     0,     0,
     117,   117,    14,    15,    16,    17,   117,   122,     0,   213,
       0,   123,   125,     0,     0,   125,     0,     0,   117,   117,
     117,     0,     0,     0,     0,   117,     0,     0,   117,     0,
       0,     0,     0,     0,     0,     0,   170,   117,     0,     0,
     213,   178,   213,    53,    54,    55,     0,     0,     0,     0,
     213,     0,   213,     0,   117,   117,     0,    10,    11,     0,
      12,     0,     0,     0,     0,     0,   117,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    13,    14,    15,    16,
      17,    10,    11,     0,    18,    19,    20,   126,     0,     0,
     126,     0,   131,     0,   131,     0,     0,   117,   117,     0,
       0,    14,    15,    16,    17,     0,     0,     0,   214,     0,
     123,   126,     0,     0,   126,     0,     0,     0,     0,     0,
       0,     0,     0,     1,   117,     2,     3,     4,     0,   229,
       0,     0,     0,     5,     6,     7,     8,     9,     0,   214,
       0,   214,     0,     0,    10,    11,     0,    12,     0,   214,
       0,   214,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    13,    14,    15,    16,    17,     0,  -102,
       0,    18,    19,    20,     0,     0,     0,     0,     0,     0,
       0,     0,    53,    54,    55,    21,    22,     0,    23,     0,
       1,    24,     2,     3,     4,     0,    10,    11,     0,    12,
       5,     6,     7,     8,     9,     0,     0,     0,     0,     0,
       0,    10,    11,     0,    12,    13,    14,    15,    16,    17,
       0,     0,     0,    18,    19,   115,     0,     0,     0,     0,
      13,    14,    15,    16,    17,     0,  -102,     0,    18,    19,
      20,    94,    95,    96,    97,    98,    99,   100,   101,   102,
     103,     0,    21,    22,     0,     0,   104,     1,    24,     2,
       3,     4,     0,    10,    11,     0,    12,     5,     6,     7,
       8,     9,     0,     0,     0,     0,     0,     0,    10,    11,
       0,    12,    13,    14,    15,    16,    17,     0,     0,     0,
      18,    19,   115,     0,     0,     0,     0,    13,    14,    15,
      16,    17,     0,  -102,     0,    18,    19,    20,     0,     0,
       0,    69,    70,    71,    72,    73,    74,    10,    11,    21,
      22,    75,    76,    77,    78,    79,    94,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    10,    11,     0,     0,
       0,   104,     0,     0,     0,    94,    95,    96,    97,    98,
      99,   100,   101,   102,   103,     0,     0,     0,     0,     0,
     104,    69,    70,    71,    72,    73,    74,    10,    11,     0,
       0,    75,    76,    77,    78,    79,    69,    70,    71,    72,
      73,    74,     0,     0,     0,     0,    75,    76,    77,    78,
      79
};

static const yytype_int16 yycheck[] =
{
      20,   146,    27,    43,    41,    29,    20,    32,    33,    47,
       3,    51,    29,    38,    52,    39,    28,    49,     0,    37,
      48,    49,    39,    61,   174,    50,   179,   177,   181,     0,
      27,    51,    53,    49,    48,    49,    45,    46,    49,    64,
      72,    56,    49,   154,   155,    59,    28,    53,   198,    67,
     226,   201,   228,    65,    57,    37,    72,    72,    53,    84,
     236,    72,   238,    43,    57,    72,    80,    81,    53,     8,
       9,    51,    52,    87,    88,   220,   104,   117,    44,    93,
     108,   109,    44,    65,   104,    67,   126,    84,   108,   109,
     104,   105,   106,   107,   108,   109,   124,    49,   112,    56,
      49,   115,    49,   123,    54,    51,    54,    45,    46,    47,
     124,    53,    72,   141,   142,    53,    72,   154,   155,   143,
      59,    60,    61,    62,    63,    64,   143,   141,   142,    13,
      14,    15,    16,    17,   174,    54,    54,   177,    58,   153,
      54,   179,    72,   181,    43,    55,    45,    46,    47,    57,
     187,    57,    51,    52,   174,   195,     5,   177,   198,    49,
      54,   201,    45,    46,    47,    53,    55,   192,   193,    72,
     184,   185,    57,     4,   214,   195,    58,    58,   198,    54,
      72,   201,    54,   211,    57,    72,   226,    58,   228,    49,
      58,    58,    72,    72,   219,    27,   236,   211,   238,    46,
      47,    48,    49,   232,    51,    52,   226,   220,   228,   234,
      -1,    -1,    59,    -1,    -1,   240,   236,    -1,   238,    -1,
      -1,    -1,    24,    25,    -1,    -1,    -1,    -1,   174,    -1,
      -1,   177,    -1,    80,    81,    -1,    -1,    -1,    -1,    -1,
      87,    88,    44,    45,    46,    47,    93,    49,    -1,   195,
      -1,    53,   198,    -1,    -1,   201,    -1,    -1,   105,   106,
     107,    -1,    -1,    -1,    -1,   112,    -1,    -1,   115,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   123,   124,    -1,    -1,
     226,   128,   228,    10,    11,    12,    -1,    -1,    -1,    -1,
     236,    -1,   238,    -1,   141,   142,    -1,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,   153,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    43,    44,    45,    46,
      47,    24,    25,    -1,    51,    52,    53,   174,    -1,    -1,
     177,    -1,   179,    -1,   181,    -1,    -1,   184,   185,    -1,
      -1,    44,    45,    46,    47,    -1,    -1,    -1,   195,    -1,
      53,   198,    -1,    -1,   201,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,   211,     5,     6,     7,    -1,   216,
      -1,    -1,    -1,    13,    14,    15,    16,    17,    -1,   226,
      -1,   228,    -1,    -1,    24,    25,    -1,    27,    -1,   236,
      -1,   238,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    43,    44,    45,    46,    47,    -1,    49,
      -1,    51,    52,    53,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    10,    11,    12,    65,    66,    -1,    68,    -1,
       3,    71,     5,     6,     7,    -1,    24,    25,    -1,    27,
      13,    14,    15,    16,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    24,    25,    -1,    27,    43,    44,    45,    46,    47,
      -1,    -1,    -1,    51,    52,    53,    -1,    -1,    -1,    -1,
      43,    44,    45,    46,    47,    -1,    49,    -1,    51,    52,
      53,    33,    34,    35,    36,    37,    38,    39,    40,    41,
      42,    -1,    65,    66,    -1,    -1,    48,     3,    71,     5,
       6,     7,    -1,    24,    25,    -1,    27,    13,    14,    15,
      16,    17,    -1,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    27,    43,    44,    45,    46,    47,    -1,    -1,    -1,
      51,    52,    53,    -1,    -1,    -1,    -1,    43,    44,    45,
      46,    47,    -1,    49,    -1,    51,    52,    53,    -1,    -1,
      -1,    18,    19,    20,    21,    22,    23,    24,    25,    65,
      66,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,    41,    42,    24,    25,    -1,    -1,
      -1,    48,    -1,    -1,    -1,    33,    34,    35,    36,    37,
      38,    39,    40,    41,    42,    -1,    -1,    -1,    -1,    -1,
      48,    18,    19,    20,    21,    22,    23,    24,    25,    -1,
      -1,    28,    29,    30,    31,    32,    18,    19,    20,    21,
      22,    23,    -1,    -1,    -1,    -1,    28,    29,    30,    31,
      32
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     3,     5,     6,     7,    13,    14,    15,    16,    17,
      24,    25,    27,    43,    44,    45,    46,    47,    51,    52,
      53,    65,    66,    68,    71,    77,    78,    79,    80,    81,
      82,    83,    84,    86,    87,    89,    91,    95,    97,    98,
      99,   102,   103,   105,   106,   107,   114,   116,    53,    53,
      57,    53,    53,    10,    11,    12,   106,   107,   108,   111,
     112,    44,    44,     0,    79,    80,    83,    95,    78,    18,
      19,    20,    21,    22,    23,    28,    29,    30,    31,    32,
     113,   115,    83,    83,    79,    82,    83,   113,   115,    49,
     100,   103,   104,    56,    33,    34,    35,    36,    37,    38,
      39,    40,    41,    42,    48,   113,   114,   115,   117,   118,
      49,    49,   105,    81,   105,    53,    85,   105,   108,    88,
     108,    83,    49,    53,    92,    98,   105,   106,   114,    81,
     101,   105,    54,     8,     9,    59,    60,    61,    62,    63,
      64,   109,   110,    54,   107,    81,    53,    78,    82,   107,
     107,   107,   107,    56,    72,    72,   107,   106,   108,   107,
     107,   107,   106,   108,   106,   108,   107,    54,    54,    58,
     105,    93,   108,    49,    72,   114,    49,    72,   105,    72,
      54,    72,   108,   108,   113,   115,    96,   102,   107,   100,
     100,    55,    57,    57,     5,    49,    92,    49,    72,    92,
      49,    72,   101,   101,   107,   107,    54,   103,    55,    83,
      83,    53,    94,    98,   105,   106,   114,    92,    92,    57,
      72,    58,    58,    90,   108,    54,    72,   114,    72,   105,
      83,    96,     4,    54,    57,    94,    72,    94,    72,    58,
      57,    84,    49,    83,    94,    94,    83,    58,    58
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    76,    77,    78,    78,    78,    79,    79,    80,    81,
      81,    81,    82,    82,    82,    83,    83,    83,    83,    83,
      84,    84,    84,    85,    86,    86,    86,    87,    88,    89,
      90,    91,    92,    92,    92,    92,    92,    92,    92,    92,
      92,    93,    94,    94,    94,    94,    94,    94,    94,    94,
      94,    95,    96,    96,    96,    97,    97,    97,    98,    99,
     100,   100,   100,   100,   101,   101,   101,   101,   102,   102,
     102,   102,   102,   103,   103,   104,   105,   105,   105,   106,
     106,   106,   106,   106,   106,   106,   107,   107,   107,   107,
     107,   107,   107,   107,   107,   107,   107,   107,   107,   107,
     107,   107,   107,   108,   108,   108,   108,   108,   109,   109,
     109,   109,   109,   109,   110,   110,   111,   112,   112,   113,
     113,   113,   113,   113,   113,   114,   114,   115,   115,   115,
     115,   115,   116,   117,   117,   117,   117,   117,   117,   117,
     118,   118,   118
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     1,     3,     1,     1,     3,     1,
       1,     1,     2,     1,     3,     2,     2,     2,     2,     0,
       7,    11,     9,     1,     1,     1,     1,     7,     1,     9,
       1,    10,     3,     3,     4,     4,     2,     3,     3,     2,
       1,     1,     3,     3,     4,     4,     1,     1,     2,     2,
       0,     8,     4,     2,     0,     2,     2,     2,     4,     2,
       3,     1,     3,     1,     3,     1,     3,     1,     1,     1,
       1,     1,     1,     1,     1,     4,     1,     1,     4,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     2,
       3,     1,     1,     1,     5,     5,     3,     3,     3,     3,
       3,     2,     0,     3,     3,     1,     1,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1
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
#line 185 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = root;
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1585 "parser.cpp" /* yacc.c:1646  */
    break;

  case 3:
#line 191 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("start_block");
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1595 "parser.cpp" /* yacc.c:1646  */
    break;

  case 4:
#line 196 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("start_block");
												mk_child((yyval.entry), (yyvsp[0].entry));
											}
#line 1604 "parser.cpp" /* yacc.c:1646  */
    break;

  case 5:
#line 200 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("start_block");
												mk_child((yyval.entry), (yyvsp[-2].entry));
												mk_child((yyval.entry), (yyvsp[-1].entry));
												mk_child((yyval.entry), (yyvsp[0].entry));
											}
#line 1615 "parser.cpp" /* yacc.c:1646  */
    break;

  case 6:
#line 209 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("comment_block");	
												(yyvsp[0].entry) = mk_node("COMMENT");		
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1625 "parser.cpp" /* yacc.c:1646  */
    break;

  case 7:
#line 214 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("comment_block");	
												(yyvsp[0].entry) = mk_node("MULTI_COMMENT");		
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1635 "parser.cpp" /* yacc.c:1646  */
    break;

  case 8:
#line 222 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("defination_block");	
												(yyvsp[-2].entry) = mk_node("DEFINE");			
												(yyvsp[-1].entry) = mk_node("IDENT");		
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
												mk_child((yyval.entry), (yyvsp[0].entry)); 
												
											}
#line 1649 "parser.cpp" /* yacc.c:1646  */
    break;

  case 9:
#line 234 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("const_block");	
												(yyvsp[0].entry) = mk_node("STRING");		
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1659 "parser.cpp" /* yacc.c:1646  */
    break;

  case 10:
#line 239 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("const_block");	
												(yyvsp[0].entry) = mk_node("NUM");		
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1669 "parser.cpp" /* yacc.c:1646  */
    break;

  case 11:
#line 244 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("const_block");	
												(yyvsp[0].entry) = mk_node("CHARACTER");		
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1679 "parser.cpp" /* yacc.c:1646  */
    break;

  case 12:
#line 252 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("block");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 1688 "parser.cpp" /* yacc.c:1646  */
    break;

  case 13:
#line 256 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("block");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1697 "parser.cpp" /* yacc.c:1646  */
    break;

  case 14:
#line 260 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 1706 "parser.cpp" /* yacc.c:1646  */
    break;

  case 15:
#line 267 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("general_block");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 1715 "parser.cpp" /* yacc.c:1646  */
    break;

  case 16:
#line 271 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("general_block");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 1724 "parser.cpp" /* yacc.c:1646  */
    break;

  case 17:
#line 275 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("general_block");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 1733 "parser.cpp" /* yacc.c:1646  */
    break;

  case 18:
#line 279 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("general_block");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 1742 "parser.cpp" /* yacc.c:1646  */
    break;

  case 19:
#line 283 "parser.y" /* yacc.c:1646  */
    {
											}
#line 1749 "parser.cpp" /* yacc.c:1646  */
    break;

  case 20:
#line 289 "parser.y" /* yacc.c:1646  */
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
#line 1770 "parser.cpp" /* yacc.c:1646  */
    break;

  case 21:
#line 305 "parser.y" /* yacc.c:1646  */
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
#line 1798 "parser.cpp" /* yacc.c:1646  */
    break;

  case 22:
#line 328 "parser.y" /* yacc.c:1646  */
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
#line 1814 "parser.cpp" /* yacc.c:1646  */
    break;

  case 23:
#line 342 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
												(yyval.entry) = mk_node("if_condition");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1823 "parser.cpp" /* yacc.c:1646  */
    break;

  case 24:
#line 349 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("loop_block");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1832 "parser.cpp" /* yacc.c:1646  */
    break;

  case 25:
#line 353 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("loop_block");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1841 "parser.cpp" /* yacc.c:1646  */
    break;

  case 26:
#line 357 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("loop_block");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1850 "parser.cpp" /* yacc.c:1646  */
    break;

  case 27:
#line 364 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("while_loop_block");		
												(yyvsp[-6].entry) = mk_node("INT");			
												(yyvsp[-6].entry) = mk_node("INT");			
												(yyvsp[-6].entry) = mk_node("INT");			
												(yyvsp[-6].entry) = mk_node("INT");			
												(yyvsp[-6].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[-6].entry)); 
											}
#line 1864 "parser.cpp" /* yacc.c:1646  */
    break;

  case 28:
#line 376 "parser.y" /* yacc.c:1646  */
    {//explicit check for NILL condition
												(yyval.entry) = mk_node("while_condition");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1873 "parser.cpp" /* yacc.c:1646  */
    break;

  case 29:
#line 383 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("do_while_loop_block");		
												(yyvsp[-8].entry) = mk_node("INT");			
												(yyvsp[-8].entry) = mk_node("INT");			
												(yyvsp[-8].entry) = mk_node("INT");			
												(yyvsp[-8].entry) = mk_node("INT");			
												(yyvsp[-8].entry) = mk_node("INT");			
												(yyvsp[-8].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[-8].entry)); 
											}
#line 1888 "parser.cpp" /* yacc.c:1646  */
    break;

  case 30:
#line 396 "parser.y" /* yacc.c:1646  */
    {// explicit check for NILL condition 
												(yyval.entry) = mk_node("do_while_condition");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 1897 "parser.cpp" /* yacc.c:1646  */
    break;

  case 31:
#line 403 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_loop_block");		
												(yyvsp[-9].entry) = mk_node("INT");			
												(yyvsp[-9].entry) = mk_node("INT");			
												(yyvsp[-9].entry) = mk_node("INT");			
												(yyvsp[-9].entry) = mk_node("INT");			
												(yyvsp[-9].entry) = mk_node("INT");			
												(yyvsp[-9].entry) = mk_node("INT");			
												(yyvsp[-9].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[-9].entry)); 
											}
#line 1913 "parser.cpp" /* yacc.c:1646  */
    break;

  case 32:
#line 417 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");				
												(yyvsp[-2].entry) = mk_node("INT");											
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 1923 "parser.cpp" /* yacc.c:1646  */
    break;

  case 33:
#line 422 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");				
												(yyvsp[-2].entry) = mk_node("INT");											
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 1933 "parser.cpp" /* yacc.c:1646  */
    break;

  case 34:
#line 427 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");				
												(yyvsp[-3].entry) = mk_node("INT");											
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 1943 "parser.cpp" /* yacc.c:1646  */
    break;

  case 35:
#line 432 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");					
												(yyvsp[-3].entry) = mk_node("INT");										
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 1953 "parser.cpp" /* yacc.c:1646  */
    break;

  case 36:
#line 437 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");				
												(yyvsp[-1].entry) = mk_node("INT");											
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 1963 "parser.cpp" /* yacc.c:1646  */
    break;

  case 37:
#line 442 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");					
												(yyvsp[-2].entry) = mk_node("INT");										
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 1973 "parser.cpp" /* yacc.c:1646  */
    break;

  case 38:
#line 447 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");					
												(yyvsp[-2].entry) = mk_node("INT");											
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 1983 "parser.cpp" /* yacc.c:1646  */
    break;

  case 39:
#line 452 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");				
												(yyvsp[-1].entry) = mk_node("INT");														(yyvsp[-1].entry) = mk_node("INT");											
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 1993 "parser.cpp" /* yacc.c:1646  */
    break;

  case 40:
#line 457 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_initialization");		
												(yyvsp[0].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2003 "parser.cpp" /* yacc.c:1646  */
    break;

  case 41:
#line 465 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_condition");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2012 "parser.cpp" /* yacc.c:1646  */
    break;

  case 42:
#line 472 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");						
												(yyvsp[-2].entry) = mk_node("INT");									
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2022 "parser.cpp" /* yacc.c:1646  */
    break;

  case 43:
#line 477 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");						
												(yyvsp[-2].entry) = mk_node("INT");									
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2032 "parser.cpp" /* yacc.c:1646  */
    break;

  case 44:
#line 482 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");						
												(yyvsp[-3].entry) = mk_node("INT");									
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 2042 "parser.cpp" /* yacc.c:1646  */
    break;

  case 45:
#line 487 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");						
												(yyvsp[-3].entry) = mk_node("INT");									
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 2052 "parser.cpp" /* yacc.c:1646  */
    break;

  case 46:
#line 492 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2061 "parser.cpp" /* yacc.c:1646  */
    break;

  case 47:
#line 496 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2070 "parser.cpp" /* yacc.c:1646  */
    break;

  case 48:
#line 500 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2079 "parser.cpp" /* yacc.c:1646  */
    break;

  case 49:
#line 504 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("for_update");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2088 "parser.cpp" /* yacc.c:1646  */
    break;

  case 50:
#line 508 "parser.y" /* yacc.c:1646  */
    {
											}
#line 2095 "parser.cpp" /* yacc.c:1646  */
    break;

  case 51:
#line 513 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("function_def_block");						
												(yyvsp[-7].entry) = mk_node("INT");			
												(yyvsp[-7].entry) = mk_node("INT");			
												(yyvsp[-7].entry) = mk_node("INT");			
												(yyvsp[-7].entry) = mk_node("INT");			
												(yyvsp[-7].entry) = mk_node("INT");			
												(yyvsp[-7].entry) = mk_node("INT");										
												mk_child((yyval.entry), (yyvsp[-7].entry)); 
											}
#line 2110 "parser.cpp" /* yacc.c:1646  */
    break;

  case 52:
#line 526 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("argument_list_block");			
												(yyvsp[-3].entry) = mk_node("INT");														(yyvsp[-3].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 2120 "parser.cpp" /* yacc.c:1646  */
    break;

  case 53:
#line 531 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("argument_list_block");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2129 "parser.cpp" /* yacc.c:1646  */
    break;

  case 54:
#line 535 "parser.y" /* yacc.c:1646  */
    {
											}
#line 2136 "parser.cpp" /* yacc.c:1646  */
    break;

  case 55:
#line 540 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("general_stmt");			
												(yyvsp[-1].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2146 "parser.cpp" /* yacc.c:1646  */
    break;

  case 56:
#line 545 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("general_stmt");		
												(yyvsp[-1].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2156 "parser.cpp" /* yacc.c:1646  */
    break;

  case 57:
#line 550 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("general_stmt");		
												(yyvsp[-1].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2166 "parser.cpp" /* yacc.c:1646  */
    break;

  case 58:
#line 559 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("function_call_block");		
												(yyvsp[-3].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 2176 "parser.cpp" /* yacc.c:1646  */
    break;

  case 59:
#line 567 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("declaration_block");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2185 "parser.cpp" /* yacc.c:1646  */
    break;

  case 60:
#line 574 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("var_list");			
												(yyvsp[-2].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2195 "parser.cpp" /* yacc.c:1646  */
    break;

  case 61:
#line 579 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("var_list");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2204 "parser.cpp" /* yacc.c:1646  */
    break;

  case 62:
#line 583 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("var_list");				
												(yyvsp[-2].entry) = mk_node("INT");											
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2214 "parser.cpp" /* yacc.c:1646  */
    break;

  case 63:
#line 588 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("var_list");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2223 "parser.cpp" /* yacc.c:1646  */
    break;

  case 64:
#line 595 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("ass_var_list");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2232 "parser.cpp" /* yacc.c:1646  */
    break;

  case 65:
#line 599 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("ass_var_list");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2241 "parser.cpp" /* yacc.c:1646  */
    break;

  case 66:
#line 603 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("ass_var_list");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2250 "parser.cpp" /* yacc.c:1646  */
    break;

  case 67:
#line 607 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("ass_var_list");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2259 "parser.cpp" /* yacc.c:1646  */
    break;

  case 68:
#line 614 "parser.y" /* yacc.c:1646  */
    {
												// $$ = mk_node("sdata_type");		
												// $1 = mk_node("INT");									
												// mk_child($$, $1); 
											}
#line 2269 "parser.cpp" /* yacc.c:1646  */
    break;

  case 69:
#line 619 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("data_type");			
												(yyvsp[0].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2279 "parser.cpp" /* yacc.c:1646  */
    break;

  case 70:
#line 624 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("data_type");		
												(yyvsp[0].entry) = mk_node("INT");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2289 "parser.cpp" /* yacc.c:1646  */
    break;

  case 71:
#line 629 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("data_type");			
												(yyvsp[0].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2299 "parser.cpp" /* yacc.c:1646  */
    break;

  case 72:
#line 634 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("data_type");			
												(yyvsp[0].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2309 "parser.cpp" /* yacc.c:1646  */
    break;

  case 73:
#line 642 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("var_block");			
												(yyvsp[0].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2319 "parser.cpp" /* yacc.c:1646  */
    break;

  case 74:
#line 647 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("var_block");			
												(yyvsp[0].entry) = mk_node("INT");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2329 "parser.cpp" /* yacc.c:1646  */
    break;

  case 75:
#line 655 "parser.y" /* yacc.c:1646  */
    {//check for expr to return positive value. Run time check for negeative value.
												(yyval.entry) = mk_node("array_block");												
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 2338 "parser.cpp" /* yacc.c:1646  */
    break;

  case 76:
#line 662 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("ass_var_block");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2347 "parser.cpp" /* yacc.c:1646  */
    break;

  case 77:
#line 666 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("ass_var_block");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2356 "parser.cpp" /* yacc.c:1646  */
    break;

  case 78:
#line 670 "parser.y" /* yacc.c:1646  */
    {// check if expr is returning a index present in the array. 
												(yyval.entry) = mk_node("ass_var_block");												
												mk_child((yyval.entry), (yyvsp[-3].entry)); 
											}
#line 2365 "parser.cpp" /* yacc.c:1646  */
    break;

  case 79:
#line 677 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("assignment_block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2374 "parser.cpp" /* yacc.c:1646  */
    break;

  case 80:
#line 681 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("assignment_block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2383 "parser.cpp" /* yacc.c:1646  */
    break;

  case 81:
#line 685 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("assignment_block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2392 "parser.cpp" /* yacc.c:1646  */
    break;

  case 82:
#line 689 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("assignment_block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2401 "parser.cpp" /* yacc.c:1646  */
    break;

  case 83:
#line 693 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("assignment_block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2410 "parser.cpp" /* yacc.c:1646  */
    break;

  case 84:
#line 697 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("assignment_block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2419 "parser.cpp" /* yacc.c:1646  */
    break;

  case 85:
#line 701 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("assignment_block");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2428 "parser.cpp" /* yacc.c:1646  */
    break;

  case 86:
#line 708 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2437 "parser.cpp" /* yacc.c:1646  */
    break;

  case 87:
#line 712 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2446 "parser.cpp" /* yacc.c:1646  */
    break;

  case 88:
#line 716 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2455 "parser.cpp" /* yacc.c:1646  */
    break;

  case 89:
#line 720 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2464 "parser.cpp" /* yacc.c:1646  */
    break;

  case 90:
#line 724 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2473 "parser.cpp" /* yacc.c:1646  */
    break;

  case 91:
#line 728 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2482 "parser.cpp" /* yacc.c:1646  */
    break;

  case 92:
#line 732 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2491 "parser.cpp" /* yacc.c:1646  */
    break;

  case 93:
#line 736 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2500 "parser.cpp" /* yacc.c:1646  */
    break;

  case 94:
#line 740 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-4].entry)); 
											}
#line 2509 "parser.cpp" /* yacc.c:1646  */
    break;

  case 95:
#line 744 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-4].entry)); 
											}
#line 2518 "parser.cpp" /* yacc.c:1646  */
    break;

  case 96:
#line 748 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2527 "parser.cpp" /* yacc.c:1646  */
    break;

  case 97:
#line 752 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2536 "parser.cpp" /* yacc.c:1646  */
    break;

  case 98:
#line 756 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2545 "parser.cpp" /* yacc.c:1646  */
    break;

  case 99:
#line 760 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2554 "parser.cpp" /* yacc.c:1646  */
    break;

  case 100:
#line 764 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2563 "parser.cpp" /* yacc.c:1646  */
    break;

  case 101:
#line 768 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("expr");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2572 "parser.cpp" /* yacc.c:1646  */
    break;

  case 102:
#line 772 "parser.y" /* yacc.c:1646  */
    {
												
											}
#line 2580 "parser.cpp" /* yacc.c:1646  */
    break;

  case 103:
#line 778 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("conditional_expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2589 "parser.cpp" /* yacc.c:1646  */
    break;

  case 104:
#line 782 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("conditional_expr");												
												mk_child((yyval.entry), (yyvsp[-2].entry)); 
											}
#line 2598 "parser.cpp" /* yacc.c:1646  */
    break;

  case 105:
#line 786 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("conditional_expr");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2607 "parser.cpp" /* yacc.c:1646  */
    break;

  case 106:
#line 790 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("conditional_expr");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2616 "parser.cpp" /* yacc.c:1646  */
    break;

  case 107:
#line 794 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("conditional_expr");												
												mk_child((yyval.entry), (yyvsp[-1].entry)); 
											}
#line 2625 "parser.cpp" /* yacc.c:1646  */
    break;

  case 108:
#line 801 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_condition_op");
												(yyvsp[0].entry) = mk_node("EQ");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2635 "parser.cpp" /* yacc.c:1646  */
    break;

  case 109:
#line 806 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_condition_op");
												(yyvsp[0].entry) = mk_node("NOTEQ");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2645 "parser.cpp" /* yacc.c:1646  */
    break;

  case 110:
#line 811 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_condition_op");
												(yyvsp[0].entry) = mk_node("GT");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2655 "parser.cpp" /* yacc.c:1646  */
    break;

  case 111:
#line 816 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_condition_op");
												(yyvsp[0].entry) = mk_node("LT");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2665 "parser.cpp" /* yacc.c:1646  */
    break;

  case 112:
#line 821 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_condition_op");
												(yyvsp[0].entry) = mk_node("GE");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2675 "parser.cpp" /* yacc.c:1646  */
    break;

  case 113:
#line 826 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_condition_op");
												(yyvsp[0].entry) = mk_node("LE");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2685 "parser.cpp" /* yacc.c:1646  */
    break;

  case 114:
#line 834 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_condition_op");
												(yyvsp[0].entry) = mk_node("AND");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2695 "parser.cpp" /* yacc.c:1646  */
    break;

  case 115:
#line 839 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_condition_op");
												(yyvsp[0].entry) = mk_node("OR");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2705 "parser.cpp" /* yacc.c:1646  */
    break;

  case 116:
#line 847 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_unary_condition_op");
												(yyvsp[0].entry) = mk_node("NOT");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2715 "parser.cpp" /* yacc.c:1646  */
    break;

  case 117:
#line 855 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("fixed_condition");
												(yyvsp[0].entry) = mk_node("TRUE");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2725 "parser.cpp" /* yacc.c:1646  */
    break;

  case 118:
#line 860 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("fixed_condition");
												(yyvsp[0].entry) = mk_node("FALSE");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2735 "parser.cpp" /* yacc.c:1646  */
    break;

  case 119:
#line 868 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2745 "parser.cpp" /* yacc.c:1646  */
    break;

  case 120:
#line 873 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2755 "parser.cpp" /* yacc.c:1646  */
    break;

  case 121:
#line 878 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2765 "parser.cpp" /* yacc.c:1646  */
    break;

  case 122:
#line 883 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2775 "parser.cpp" /* yacc.c:1646  */
    break;

  case 123:
#line 888 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2785 "parser.cpp" /* yacc.c:1646  */
    break;

  case 124:
#line 893 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2795 "parser.cpp" /* yacc.c:1646  */
    break;

  case 125:
#line 901 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_unary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2805 "parser.cpp" /* yacc.c:1646  */
    break;

  case 126:
#line 906 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_unary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2815 "parser.cpp" /* yacc.c:1646  */
    break;

  case 127:
#line 914 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2825 "parser.cpp" /* yacc.c:1646  */
    break;

  case 128:
#line 919 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2835 "parser.cpp" /* yacc.c:1646  */
    break;

  case 129:
#line 924 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2845 "parser.cpp" /* yacc.c:1646  */
    break;

  case 130:
#line 929 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2855 "parser.cpp" /* yacc.c:1646  */
    break;

  case 131:
#line 934 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_binary_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");														
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2865 "parser.cpp" /* yacc.c:1646  */
    break;

  case 132:
#line 942 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_unary_op");		
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2875 "parser.cpp" /* yacc.c:1646  */
    break;

  case 133:
#line 950 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_assgn_op");
												(yyvsp[0].entry) = mk_node("ADD_ASSIGN");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2885 "parser.cpp" /* yacc.c:1646  */
    break;

  case 134:
#line 955 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_assgn_op");
												(yyvsp[0].entry) = mk_node("SUB_ASSIGN");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2895 "parser.cpp" /* yacc.c:1646  */
    break;

  case 135:
#line 960 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_assgn_op");
												(yyvsp[0].entry) = mk_node("MULT_ASSIGN");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2905 "parser.cpp" /* yacc.c:1646  */
    break;

  case 136:
#line 965 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_assgn_op");
												(yyvsp[0].entry) = mk_node("DIV_ASSIGN");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2915 "parser.cpp" /* yacc.c:1646  */
    break;

  case 137:
#line 970 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_assgn_op");
												(yyvsp[0].entry) = mk_node("MOD_ASSIGN");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2925 "parser.cpp" /* yacc.c:1646  */
    break;

  case 138:
#line 975 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_assgn_op");
												(yyvsp[0].entry) = mk_node("LEFT_ASSIGN");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2935 "parser.cpp" /* yacc.c:1646  */
    break;

  case 139:
#line 980 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("arith_assgn_op");
												(yyvsp[0].entry) = mk_node("RIGHT_ASSIGN");													
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2945 "parser.cpp" /* yacc.c:1646  */
    break;

  case 140:
#line 988 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_assgn_op");
												(yyvsp[0].entry) = mk_node("BIN_AND_ASSIGN");											
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2955 "parser.cpp" /* yacc.c:1646  */
    break;

  case 141:
#line 993 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_assgn_op");	
												(yyvsp[0].entry) = mk_node("BIN_IOR_ASSIGN");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2965 "parser.cpp" /* yacc.c:1646  */
    break;

  case 142:
#line 998 "parser.y" /* yacc.c:1646  */
    {
												(yyval.entry) = mk_node("bit_assgn_op");	
												(yyvsp[0].entry) = mk_node("BIN_XOR_ASSIGN");												
												mk_child((yyval.entry), (yyvsp[0].entry)); 
											}
#line 2975 "parser.cpp" /* yacc.c:1646  */
    break;


#line 2979 "parser.cpp" /* yacc.c:1646  */
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
#line 1006 "parser.y" /* yacc.c:1906  */


void yyerror(const char *err){
	printf(" ** %s\n",err);
}

int main(){
	#if YYDEBUG
	    yydebug = 1;
	#endif
	root = init_tree();

	//yylex();
	yyparse();

	printtree(root, 0);
	return 0;
}

node *init_tree(){
	node *tmp = (node *)malloc(sizeof(node));
	for (int i = 0; i < MAX_CHILD; ++i){
		tmp->child[i] = NULL;
	}
	tmp->left_sib = NULL;
	tmp->right_sib = NULL;
	tmp->name = (char *)malloc(20*sizeof(char));
	strcpy(tmp->name, "super_block");
	tmp->cur_childs = 0;

	return tmp;
}

struct node *mk_node(const char *name){
	node *tmp = (node *)malloc(sizeof(node));
	strcpy(tmp->name, name);
	tmp->cur_childs = 0;
	tmp->left_sib = NULL;
	tmp->right_sib = NULL;
	for (int i = 0; i < MAX_CHILD; ++i){
		tmp->child[i] = NULL;
	}
	return tmp;
}

void mk_child(node *par, node *ch){
	par->child[par->cur_childs] = ch;
	par->cur_childs++;
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
	for (int i = 0; i < level; ++i)
	{
		printf("\t");
	}
	printf("%s\n", root->name);

	for (int i = 0; i < root->cur_childs; ++i)
	{
		printtree(root->child[i], level+1);
	}
}

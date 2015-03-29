/* A Bison parser, made by GNU Bison 3.0.2.  */

/* Bison interface for Yacc-like parsers in C

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

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
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
    TNUM = 258,
    CHARCONSTANT = 259,
    STRING_LITERAL = 260,
    CCODE = 261,
    TIDENT = 262,
    TNT = 263,
    TNTLHS = 264,
    TLEFT = 265,
    TRIGHT = 266,
    TNONASSOC = 267,
    TTOKEN = 268,
    TPREC = 269,
    TTYPE = 270,
    TSTART = 271,
    TUNION = 272,
    TPURE_PARSER = 273,
    TSEMANTIC_PARSER = 274,
    TEXPECT = 275,
    TTHONG = 276,
    TMARK = 277,
    TLCURL = 278,
    TRCURL = 279,
    TSEMICOL = 280,
    TPIPE = 281,
    TOPENBRACES = 282,
    TCLOSEBRACES = 283,
    TLT = 284,
    TGT = 285,
    TCOMMA = 286,
    TEPSILON = 287
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE YYSTYPE;
union YYSTYPE
{
#line 38 "yaccviso.y" /* yacc.c:1909  */

  char           *ccode;		/* a char* that holds the c code*/
  node           *nptr;
  symentry	 *symptr;		/* for non terminals (LHS, RHS), 
					   terminals, identifiers  */

#line 94 "y.tab.h" /* yacc.c:1909  */
};
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

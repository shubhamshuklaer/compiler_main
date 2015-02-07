%{

#include <stdio.h>
#include <stdlib.h>
#include "parser.hpp"
#define TOKEN(t) (yylval.token=t)

%}

ALPHA	[a-zA-Z]
DIG		[0-9]



%%

"if" 									return IF;
"else" 									return ELSE;
"while" 								return WHILE;
"do" 									return DO;
"for" 									return FOR;
"true" 									return TRUE;
"false" 								return FALSE;
"int" 									return INT;
"long"									return LONG;
"char" 									return CHAR;
"float" 								return FLOAT;
"double" 								return DOUBLE;
(" "|"\t"|"\r"|"\s")*					/* ignore */
","										return COMMA;
"+"										return ADD;
"-" 									return SUB;
"*" 									return MULT;
"/" 									return DIV;
"^^"									return EXP;
"?" 									return QUES;
"%" 									return MOD;
"==" 									return EQ;
"!=" 									return NOTEQ;
">" 									return GT;
"<" 									return LT;
">="									return GE;
"<="									return LE;
"="										return ASSIGN;
";"										return TERMINATOR;
":"										return COLON;
"("										return OP;
")"										return CP;
"["										return OB;
"]"										return CB;
"{"										return OCB;
"}"										return CCB;
"++"									return INC;
"--"									return DEC;
"&&"									return AND;		
"||"									return OR;
"!"										return NOT;
"~"										return BIN_NOT;
"&"										return BIN_AND;
"|"										return BIN_OR;
"^"										return BIN_XOR;
"<<"									return BIN_LEFT;
">>"									return BIN_RIGHT;
"+="									return ADD_ASSIGN;
"-="									return SUB_ASSIGN;
"*="									return MULT_ASSIGN;
"/="									return DIV_ASSIGN;
"%="									return MOD_ASSIGN;
"<<="									return LEFT_ASSIGN;
">>="									return RIGHT_ASSIGN;
"&="									return BIN_AND_ASSIGN;
"^="									return BIN_XOR_ASSIGN;
"|="									return BIN_IOR_ASSIGN;
"/*"(.|"\n")*"*/"						{yylval.str=strdup(yytext);return MULTI_COMMENT;}
"#define ".*"\n"						{yylval.str=strdup(yytext);return DEFINE;}
"#ifdef ".*"\n"							{yylval.str=strdup(yytext);return IFDEF;}
"#ifndef ".*"\n"						{yylval.str=strdup(yytext);return IFNDEF;}
"function"								return FUNCTION;
(_|{ALPHA})(_|{ALPHA}|{DIG})*			{yylval.num=atoi(yytext);return IDENT;}
{DIG}+(\.{DIG}+)?						{yylval.num=atoi(yytext);return NUM;}
"# ".*"\n"								{yylval.str=strdup(yytext);return COMMENT;}
.										;
%%

/*
int main(int argc, char** argv)
{
  if (argc > 1)
    yyin = fopen(argv[1], "r");
  else
    yyin = stdin;
  return yylex();
}

*/
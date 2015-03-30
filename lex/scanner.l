%{
#include <stdio.h>
#include <stdlib.h>
#include "parser.hpp"
#define TOKEN(t) (yylval.token=t)
%}

ALPHA	[a-zA-Z]
DIG		[0-9]



%%

"if" 										{printf("<keyword : \'if\'> "); return IF;}
"else" 										{printf("<keyword : \'else\'> ");return ELSE;}
"while" 									{printf("<keyword : \'while\'> ");return WHILE;}
"do" 										{printf("<keyword : \'do\'> ");return DO;}
"for" 										{printf("<keyword : \'for\'> ");return FOR;}
"true" 										{printf("<keyword : \'true\'> ");return TRUE;}
"false" 									{printf("<keyword : \'false\'> ");return FALSE;}
"int" 										{printf("<keyword : \'int\'> ");  return INT;}
"long"										{printf("<keyword : \'long\'> "); return LONG;}
"char" 										{printf("<keyword : \'char\'> "); return CHAR;}
"float" 									{printf("<keyword : \'float\'> "); return FLOAT;}
"double" 									{printf("<keyword : \'double\'> "); return DOUBLE;}
(" "|"\t"|"\r"|"\s")*						{/* ignore */}
","											{printf("<operator : \',\'> ");return COMMA;}
"+"											{printf("<operator : \'+\'> ");return ADD;}
"-" 										{printf("<operator : \'-\'> ");return SUB;}
"*" 										{printf("<operator : \'*\'> ");return MULT;}
"/" 										{printf("<operator : \'/\'> ");return DIV;}
"^^"										{printf("<operator : \'^^\'> ");return EXP;}
"?" 										{printf("<operator : \'?\'> ");return QUES;}
"%" 										{printf("<operator : \'%%\'> ");return MOD;}
"==" 										{printf("<operator : \'==\'> ");return EQ;}
"!=" 										{printf("<operator : \'!=\'> ");return NOTEQ;}
">" 										{printf("<operator : \'>\'> ");return GT;}
"<" 										{printf("<operator : \'<\'> ");return LT;}
">="										{printf("<operator : \'>=\'> ");return GE;}
"<="										{printf("<operator : \'<=\'> ");return LE;}
"<>"										{printf("<operator : \'<>\'> ");return LTGT;}
"="											{printf("<operator : \'=\'> ");return ASSIGN;}
";"											{printf("<keyword : \';\'> ");return TERMINATOR;}
":"											{printf("<keyword : \':\'> ");return COLON;}
"("											{printf("<keyword : \'(\'> ");return OP;}
")"											{printf("<keyword : \')\'> ");return CP;}
"["											{printf("<keyword : \'[\'> ");return OB;}
"]"											{printf("<keyword : \']\'> ");return CB;}
"{"											{printf("<keyword : \'{\'> ");return OCB;}
"}"											{printf("<keyword : \'}\'> ");return CCB;}
"++"										{printf("<operator : \'++\'> ");return INC;}
"--"										{printf("<operator : \'--\'> ");return DEC;}
"&&"										{printf("<operator : \'&&\'> ");return AND;}		
"||"										{printf("<operator : \'||\'> ");return OR;}
"!"											{printf("<operator : \'!\'> ");return NOT;}
"~"											{printf("<operator : \'~\'> ");return BIN_NOT;}
"&"											{printf("<operator : \'&\'> ");return BIN_AND;}
"|"											{printf("<operator : \'|\'> ");return BIN_OR;}
"^"											{printf("<operator : \'^\'> ");return BIN_XOR;}
"<<"										{printf("<operator : \'<<\'> ");return BIN_LEFT;}
">>"										{printf("<operator : \'>>\'> ");return BIN_RIGHT;}
"+="										{printf("<operator : \'+=\'> ");return ADD_ASSIGN;}
"-="										{printf("<operator : \'-=\'> ");return SUB_ASSIGN;}
"*="										{printf("<operator : \'*=\'> ");return MULT_ASSIGN;}
"/="										{printf("<operator : \'/=\'> ");return DIV_ASSIGN;}
"%="										{printf("<operator : \'%%=\'> ");return MOD_ASSIGN;}
"<<="										{printf("<operator : \'<<=\'> ");return LEFT_ASSIGN;}
">>="										{printf("<operator : \'>>=\'> ");return RIGHT_ASSIGN;}
"&="										{printf("<operator : \'&=\'> ");return BIN_AND_ASSIGN;}
"^="										{printf("<operator : \'^=\'> ");return BIN_XOR_ASSIGN;}
"|="										{printf("<operator : \'|=\'> ");return BIN_IOR_ASSIGN;}
"-"."-"										{printf("<keyword : \'character\'> "); yylval.terminal_value = strdup(yytext); return CHARACTER;}
"--"(_|\.|{ALPHA}|{DIG})*"--"				{printf("<keyword : \'string\'> "); yylval.terminal_value = strdup(yytext); return STRING;}
"/*"(.|"\n")*"*/"							{printf("<plainText : \'/* */\'> "); return MULTI_COMMENT;}
"#define "									{printf("<preprocess : \'#define\'> "); return DEFINE;}
"#ifdef "									{printf("<preprocess : \'#ifdef\'> ");  return IFDEF;}
"#ifndef "									{printf("<preprocess : \'#ifndef\'> "); return IFNDEF;}
"# ".*"\n"									{printf("<plainText : \'#\'> ");return COMMENT;}
"function "									{printf("<keyword : \'function\'> "); return FUNCTION;}
"print "									{printf("<keyword : \'print\'> "); return PRINT;}
(_|{ALPHA})(_|{ALPHA}|{DIG})*				{ printf("<fidentifier : \'%s\'> ",strdup(yytext));  yylval.terminal_value = strdup(yytext); return IDENT; }
$(_|{ALPHA})(_|{ALPHA}|{DIG})*				{ printf("<identifier : \'%s\'> ",strdup(yytext)); yylval.terminal_value = strdup(yytext); return VAR; }
@(_|{ALPHA})(_|{ALPHA}|{DIG})*				{ printf("<pointer : \'%s\'> ",strdup(yytext)); yylval.terminal_value = strdup(yytext); return POINTER; }
"*"(_|{ALPHA})(_|{ALPHA}|{DIG})*			{ printf("<dref : \'%s\'> ",strdup(yytext));  yylval.terminal_value = strdup(yytext); return DREF; }
{DIG}+(\.{DIG}+)?							{printf("<constant : \'%d\'> ",atoi(yytext)); yylval.terminal_value = strdup(yytext); return NUM;}
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

%{
	#define YYDEBUG 1
	#include <stdio.h>
	#include "header.h"
	int yylex(void);
	void yyerror(const char *);
%}



%union {
	int num;
	char *str;
}


%token IF ELSE WHILE DO FOR AND OR NOT TRUE FALSE INT CHAR FLOAT DOUBLE
%token ADD SUB MULT DIV EXP MOD INC DEC QUES
%token BIN_NOT BIN_AND BIN_OR BIN_XOR BIN_LEFT BIN_RIGHT
%token BIN_AND_ASSIGN BIN_IOR_ASSIGN BIN_XOR_ASSIGN
%token ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%token NUM IDENT ASSIGN TERMINATOR COLON
%token OP CP CB OB OCB CCB
%token EQ NOTEQ GT LT GE LE
%token COMMENT MULTI_COMMENT
%token WHITESPACE
%token DEFINE IFDEF IFNDEF

%start term_block
%%

arith_bi_op			:	ADD
					|	SUB
					|	MULT
					|	DIV
					|	MOD
					|	EXP
					;

arith_un_op			:	INC
					|	DEC
					;

logic_bi_op			:	EQ								
							{printf(" ** equals\n");}
					|	NOTEQ
					|	GT
					|	LT
					|	GE
					|	LE
					|	AND
					|	OR
					;

logic_un_op			:	NOT
					;

bit_un_op			:	BIN_NOT
					;

bit_bi_op			:	BIN_AND
					|	BIN_OR
					|	BIN_XOR
					|	BIN_LEFT
					|	BIN_RIGHT
					;

assign_op			:	ASSIGN
					|	ADD_ASSIGN
					|	SUB_ASSIGN
					|	MULT_ASSIGN
					| 	DIV_ASSIGN
					|	MOD_ASSIGN
					|	LEFT_ASSIGN
					|	RIGHT_ASSIGN
					|	BIN_AND_ASSIGN
					|	BIN_XOR_ASSIGN
					|	BIN_IOR_ASSIGN
					;

op 					: 	arith_bi_op
					|	arith_un_op
					|	logic_bi_op
					|	logic_un_op
					|	bit_un_op
					|	bit_bi_op
					|	assign_op
					;

expr				:	expr op expr								
							{printf(" ** expr\n");}
					| 	OP expr CP	
					|	IDENT
					|	NUM
					;


assignment			:	IDENT assign_op expr						
							{printf(" ** assignment\n");}
					|	WHITESPACE
					;

block 				:	assignment
					|	block block
					|	OCB term_block CCB	
					|	if_block
					|	while_block
					|	for_block
					|	comment_block
					|	multi_comment_block
					|	def_block
					;

term_block			:	block
					|	term_block term_block
					|	block TERMINATOR
					|	do_while_block
					|	ternary_block
					|	condition TERMINATOR
					|	TERMINATOR
					;

condition 			:	expr									
							{printf(" ** cond\n");}
					;

ternary_block 		:	condition QUES block COLON block TERMINATOR				
							{printf(" ** ternary\n");}
					|	condition QUES expr COLON expr					
							{printf(" ** ternary\n");}
					;

def_block			:	DEFINE
					|	IFDEF
					|	IFNDEF

if_block 			:	IF condition term_block								
							{printf(" ** if\n");}
					|	IF condition term_block ELSE term_block				
							{printf(" ** if\n");}
					;

while_block			:	WHILE condition block							
							{printf(" ** while\n");}
					;

do_while_block		:	DO block WHILE condition TERMINATOR 			
							{printf(" ** do while\n");}
					;

for_block			:	FOR OP assignment TERMINATOR condition 
						TERMINATOR assignment CP block 						
							{printf(" ** for\n");}
					;

comment_block 		:	COMMENT 										
							{printf(" ** comment\n");}
					;

multi_comment_block	:	MULTI_COMMENT
							{printf(" ** comment\n");}
					;


%%

void yyerror(const char *err){
	printf(" ** %s\n",err);
}

int main(){
	#if YYDEBUG
	    yydebug = 1;
	#endif
	//yylex();
	yyparse();
	return 0;
}
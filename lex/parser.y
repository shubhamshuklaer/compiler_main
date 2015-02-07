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

%token IF ELSE WHILE DO FOR AND OR NOT TRUE FALSE
%token INT LONG CHAR FLOAT DOUBLE
%token ADD SUB MULT DIV EXP MOD INC DEC QUES
%token BIN_NOT BIN_AND BIN_OR BIN_XOR BIN_LEFT BIN_RIGHT
%token BIN_AND_ASSIGN BIN_IOR_ASSIGN BIN_XOR_ASSIGN
%token ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIV_ASSIGN 
	MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%token NUM IDENT ASSIGN TERMINATOR COLON
%token OP CP CB OB OCB CCB
%token EQ NOTEQ GT LT GE LE
%token COMMENT MULTI_COMMENT
%token WHITESPACE
%token DEFINE IFDEF IFNDEF
%token FUNCTION
%token COMMA

%right ASSIGN
%left AND OR
%left LT GT LE GE EQ NOTEQ
%left ADD SUB
%left MULT DIV
%left NOT

%start term_block

%%

data_type 			:	INT 
					|	LONG
					|	CHAR
					|	FLOAT 
					|	DOUBLE
					|	LONG LONG
					|	LONG FLOAT
					|	LONG DOUBLE
					;

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

expr				:	condition
							{printf(" ** expr\n");}
					| 	OP expr CP	
					|	term
					|	function_block
					|	function_block OB expr CB
					;

term 				:	IDENT
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
					|	data_def_block
					;

data_def_block 		:	data_type arr_elem_block TERMINATOR
					|	data_type arr_elem_block ASSIGN expr TERMINATOR
							{printf(" ** data define\n");}
					;

ident_block 		:	IDENT
					|	ident_block COMMA IDENT
					;

arr_elem 			:	IDENT OB expr CB 
					|	IDENT
					;

arr_elem_block 		: 	arr_elem
					|	arr_elem COMMA arr_elem_block
					;

term_block			:	block
					|	term_block term_block
					|	block TERMINATOR
					|	do_while_block
					|	ternary_block
					|	condition TERMINATOR
					|	TERMINATOR
					|	function_def_block
					;

condition 			:	expr op expr
					|	TRUE
					|	FALSE
							{printf(" ** cond\n");}
					;

function_block 		:	IDENT OP ident_block CP
							{printf(" ** function\n");}
					;

function_def_block	:	FUNCTION IDENT OP arg_def_block CP OCB term_block CCB
							{printf(" ** function define\n");}
					;

arg_def_block		:	data_type IDENT COMMA arg_def_block
					|	data_type IDENT
					;

ternary_block 		:	condition QUES block COLON block TERMINATOR							|	expr QUES block COLON block TERMINATOR	
							{printf(" ** ternary\n");}
					|	condition QUES expr COLON expr			
					|	expr QUES expr COLON expr
							{printf(" ** ternary\n");}
					;

def_block			:	DEFINE
					|	IFDEF
					|	IFNDEF
					;

if_block 			:	IF condition term_block	
					|	IF expr term_block							
							{printf(" ** if\n");}
					|	IF condition term_block ELSE term_block		
					|	IF expr term_block ELSE term_block				
							{printf(" ** if\n");}
					;

while_block			:	WHILE condition block	
					|	WHILE expr block						
							{printf(" ** while\n");}
					;

do_while_block		:	DO block WHILE condition TERMINATOR 
					|	DO block WHILE expr TERMINATOR
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
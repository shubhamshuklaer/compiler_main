%{
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
%}

%union {
	struct node *entry;
	char *terminal_value;
}

%token IF ELSE WHILE DO FOR AND OR NOT_1 TRUE_1 FALSE_1
%token INT LONG CHAR FLOAT DOUBLE
%token ADD SUB MULT DIV EXP MOD INC DEC
%token BIN_NOT BIN_AND BIN_OR BIN_XOR BIN_LEFT BIN_RIGHT
%token BIN_AND_ASSIGN BIN_IOR_ASSIGN BIN_XOR_ASSIGN
%token ADD_ASSIGN SUB_ASSIGN MULT_ASSIGN DIV_ASSIGN MOD_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN
%token NUM IDENT VAR POINTER DREF ASSIGN TERMINATOR STRING CHARACTER
%token OP CP CB OB OCB CCB
%token EQ NOTEQ GT LT GE LE


%token COMMENT MULTI_COMMENT
%token DEFINE IFDEF IFNDEF
%token FUNCTION
%token COMMA 
%token PRINT

%right ASSIGN
%left AND OR
%left LT GT LE GE LTGT EQ NOTEQ
%left ADD SUB
%left MULT DIV
%left NOT_1

%start super_block

%type <entry> IF 
%type <entry> ELSE 
%type <entry> WHILE 
%type <entry> DO 
%type <entry> FOR 
%type <entry> AND 
%type <entry> OR 
%type <entry> NOT_1 
%type <entry> TRUE_1 
%type <entry> FALSE_1
%type <entry> INT 
%type <entry> LONG 
%type <entry> CHAR 
%type <entry> FLOAT 
%type <entry> DOUBLE
%type <entry> ADD 
%type <entry> SUB 
%type <entry> MULT 
%type <entry> DIV 
%type <entry> EXP 
%type <entry> MOD 
%type <entry> INC 
%type <entry> DEC 
%type <entry> BIN_NOT 
%type <entry> BIN_AND 
%type <entry> BIN_OR 
%type <entry> BIN_XOR 
%type <entry> BIN_LEFT 
%type <entry> BIN_RIGHT
%type <entry> BIN_AND_ASSIGN 
%type <entry> BIN_IOR_ASSIGN 
%type <entry> BIN_XOR_ASSIGN
%type <entry> ADD_ASSIGN 
%type <entry> SUB_ASSIGN 
%type <entry> MULT_ASSIGN 
%type <entry> DIV_ASSIGN 
%type <entry> MOD_ASSIGN 
%type <entry> LEFT_ASSIGN 
%type <entry> RIGHT_ASSIGN
%type <entry> NUM 
%type <entry> IDENT 
%type <entry> VAR 
%type <entry> POINTER 
%type <entry> DREF 
%type <entry> ASSIGN 
%type <entry> TERMINATOR 
%type <entry> STRING 
%type <entry> CHARACTER
%type <entry> OP 
%type <entry> CP 
%type <entry> CB 
%type <entry> OB 
%type <entry> OCB 
%type <entry> CCB
%type <entry> EQ 
%type <entry> NOTEQ 
%type <entry> GT 
%type <entry> LT 
%type <entry> GE 
%type <entry> LE
%type <entry> LTGT

%type <entry> COMMENT 
%type <entry> MULTI_COMMENT
%type <entry> DEFINE 
%type <entry> IFDEF 
%type <entry> IFNDEF
%type <entry> FUNCTION
%type <entry> COMMA 

%type <entry> PRINT

%type <entry> super_block
%type <entry> start_block
%type <entry> comment_block
%type <entry> defination_block
%type <entry> const_block
%type <entry> block
%type <entry> general_block
%type <entry> if_else_block
%type <entry> if_condition
%type <entry> loop_block
%type <entry> while_loop_block
%type <entry> while_condition
%type <entry> do_while_loop_block
%type <entry> do_while_condition
%type <entry> for_loop_block
%type <entry> for_initialization
%type <entry> for_condition
%type <entry> for_update
%type <entry> function_def_block
%type <entry> argument_list_block
%type <entry> general_stmt
%type <entry> function_call_block
%type <entry> declaration_block
%type <entry> var_list
%type <entry> data_type
%type <entry> var_block
%type <entry> array_block
%type <entry> ass_var_block
%type <entry> assignment_block
%type <entry> expr
%type <entry> conditional_expr
%type <entry> arith_condition_op
%type <entry> bit_condition_op
%type <entry> bit_unary_condition_op
%type <entry> fixed_condition
%type <entry> arith_binary_op
%type <entry> arith_unary_op
%type <entry> bit_binary_op
%type <entry> bit_unary_op
%type <entry> arith_assgn_op
%type <entry> bit_assgn_op
%type <entry> str
%type <entry> function_var_list
%%

super_block								
					:	start_block{
							$$ = root;
							mk_child($$, $1); 
						}
					;

start_block 							
					:	defination_block start_block{
							$$ = mk_node("start_block");
							mk_child($$, $1); 
							mk_child($$, $2); 
						}
					|	block{
							$$ = mk_node("start_block");
							mk_child($$, $1);
						}
					|	comment_block defination_block start_block{
							$$ = mk_node("start_block");
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
						}
					;

comment_block 							
					:	COMMENT{
							$$ = mk_node("comment_block");	
							$1 = mk_node("COMMENT");		
							mk_child($$, $1); 
						}
					|	MULTI_COMMENT{
							$$ = mk_node("comment_block");	
							$1 = mk_node("MULTI_COMMENT");		
							mk_child($$, $1); 
						}
					;

defination_block 						
					:	DEFINE IDENT const_block{
							$$ = mk_node("defination_block");	
							$1 = mk_node("DEFINE");			
							$2 = mk_node("IDENT");		
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
							
						}
					| IFDEF IDENT OCB start_block CCB 
						{
							$$ = mk_node("defination_block");
							$1 = mk_node("IFDEF");
							$2 = mk_node("IDENT");
							$3 = mk_node("OCB");
							$5 = mk_node("CCB");
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
							mk_child($$, $4); 
							mk_child($$, $5); 
						}
					| IFNDEF IDENT OCB start_block CCB
						{
							$$ = mk_node("defination_block");
							$1 = mk_node("IFNDEF");
							$2 = mk_node("IDENT");
							$3 = mk_node("OCB");
							$5 = mk_node("CCB");
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
							mk_child($$, $4); 
							mk_child($$, $5); 
						}
					;

const_block 							
					:	STRING{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("const_block");	
							$1 = mk_node("STRING");		
							mk_child($1, temp);
							mk_child($$, $1); 
						}
					|	NUM{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("const_block");	
							$1 = mk_node("NUM");
							mk_child($1, temp);		
							mk_child($$, $1); 
						}
					|	CHARACTER{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("const_block");	
							$1 = mk_node("CHARACTER");		
							mk_child($1, temp);
							mk_child($$, $1); 
						}
					;

block 									
					:	function_def_block block{
							$$ = mk_node("block");												
							mk_child($$, $1); 											
							mk_child($$, $2); 
						}
					|	general_block{
							$$ = mk_node("block");												
							mk_child($$, $1); 
						}
					|	comment_block function_def_block block{
							$$ = mk_node("block");												
							mk_child($$, $1); 											
							mk_child($$, $2); 											
							mk_child($$, $3); 
						}
					;

general_block 							
					:	general_stmt general_block{
							$$ = mk_node("general_block");												
							mk_child($$, $1); 											
							mk_child($$, $2); 
						}
					|	loop_block general_block{
							$$ = mk_node("general_block");												
							mk_child($$, $1); 											
							mk_child($$, $2); 
						}
					|	if_else_block general_block {
							$$ = mk_node("general_block");												
							mk_child($$, $1); 											
							mk_child($$, $2); 
						}
					|	comment_block general_block{
							$$ = mk_node("general_block");												
							mk_child($$, $1); 											
							mk_child($$, $2); 
						}
					|   error start_block {
							$$ = mk_node("error");
							mk_child($$, $2);
							yyerrok;
							yyclearin;
						}
					|	{
							$$ = mk_node("/general_block");
						}
					;


if_else_block 							
					:	IF OP if_condition CP OCB general_block CCB{
							$$ = mk_node("if_else_block");				
							$1 = mk_node("IF");			
							$2 = mk_node("OP");			
							$4 = mk_node("CP");			
							$5 = mk_node("OCB");			
							$7 = mk_node("CCB");			
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
							mk_child($$, $4); 
							mk_child($$, $5); 
							mk_child($$, $6); 
							mk_child($$, $7); 
							
						}
					|	IF OP if_condition CP OCB general_block CCB ELSE OCB general_block CCB{
							$$ = mk_node("if_else_block");				
							$1 = mk_node("IF");			
							$2 = mk_node("OP");			
							$4 = mk_node("CP");			
							$5 = mk_node("OCB");			
							$7 = mk_node("CCB");			
							$8 = mk_node("ELSE");			
							$9 = mk_node("OCB");			
							$11 = mk_node("CCB");											
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
							mk_child($$, $4); 
							mk_child($$, $5); 
							mk_child($$, $6); 
							mk_child($$, $7); 
							mk_child($$, $8); 
							mk_child($$, $9); 
							mk_child($$, $10); 
							mk_child($$, $11); 
							
						}
					|	IF OP if_condition CP OCB general_block CCB ELSE if_else_block{
							$$ = mk_node("if_else_block");				
							$1 = mk_node("INT");			
							$1 = mk_node("INT");			
							$1 = mk_node("INT");			
							$1 = mk_node("INT");			
							$1 = mk_node("INT");			
							$1 = mk_node("INT");			
							$1 = mk_node("INT");											
							mk_child($$, $1); 
						}
					;

if_condition 							
					:	conditional_expr {//explicit check for NILL condition
							$$ = mk_node("if_condition");												
							mk_child($$, $1); 
						}
					;

loop_block 								
					:	for_loop_block{
							$$ = mk_node("loop_block");												
							mk_child($$, $1); 
						}
					|	while_loop_block{
							$$ = mk_node("loop_block");												
							mk_child($$, $1); 
						}
					|	do_while_loop_block{
							$$ = mk_node("loop_block");												
							mk_child($$, $1); 
						}
					;

while_loop_block 						
					:	WHILE OP while_condition CP OCB general_block CCB{
							$$ = mk_node("while_loop_block");		
							$1 = mk_node("WHILE");			
							$2 = mk_node("OP");			
							$4 = mk_node("CP");			
							$5 = mk_node("OCB");			
							$7 = mk_node("CCB");													
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
							mk_child($$, $5);
							mk_child($$, $6);
							mk_child($$, $7);
							 
						}
					;

while_condition 						
					:	conditional_expr {//explicit check for NILL condition
							$$ = mk_node("while_condition");												
							mk_child($$, $1); 
							
						}
					;

do_while_loop_block 					
					:	DO OCB general_block CCB WHILE OP do_while_condition CP TERMINATOR{
							$$ = mk_node("do_while_loop_block");		
							$1 = mk_node("DO");			
							$2 = mk_node("OCB");			
							$4 = mk_node("CCB");			
							$5 = mk_node("WHILE");			
							$6 = mk_node("OP");			
							$8 = mk_node("CP");			
							$9 = mk_node("TERMINATOR");													
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
							mk_child($$, $5);
							mk_child($$, $6);
							mk_child($$, $7);
							mk_child($$, $8);
							mk_child($$, $9);
							
						}
					;

do_while_condition
					:	conditional_expr {// explicit check for NILL condition 
							$$ = mk_node("do_while_condition");												
							mk_child($$, $1); 
							
						}
					;

for_loop_block
					:	FOR OP for_initialization for_condition TERMINATOR for_update CP OCB general_block CCB{
							$$ = mk_node("for_loop_block");		
							$1 = mk_node("FOR");			
							$2 = mk_node("OP");			
							$5 = mk_node("TERMINATOR");			
							$7 = mk_node("CP");			
							$8 = mk_node("OCB");			
							$9 = mk_node("CCB");			
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
							mk_child($$, $5);
							mk_child($$, $6);
							mk_child($$, $7);
							mk_child($$, $8);
							mk_child($$, $9);
							
						}
					;

for_initialization
					:	function_call_block COMMA for_initialization{
							$$ = mk_node("for_initialization");				
							$2 = mk_node("COMMA");										
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							
						}
					|	assignment_block COMMA for_initialization{
							$$ = mk_node("for_initialization");				
							$2 = mk_node("COMMA");										
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	ass_var_block arith_unary_op COMMA for_initialization{
							$$ = mk_node("for_initialization");				
							$3 = mk_node("COMMA");											
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					|	arith_unary_op ass_var_block COMMA for_initialization{
							$$ = mk_node("for_initialization");					
							$3 = mk_node("COMMA");										
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					|	assignment_block TERMINATOR{
							$$ = mk_node("for_initialization");				
							$2 = mk_node("TERMINATOR");											
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	ass_var_block arith_unary_op TERMINATOR{
							$$ = mk_node("for_initialization");					
							$3 = mk_node("TERMINATOR");										
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	arith_unary_op ass_var_block TERMINATOR{
							$$ = mk_node("for_initialization");					
							$3 = mk_node("TERMINATOR");											
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	function_call_block TERMINATOR{
							$$ = mk_node("for_initialization");				
							$2 = mk_node("TERMINATOR");
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	TERMINATOR{
							$$ = mk_node("for_initialization");		
							$1 = mk_node("TERMINATOR");													
							mk_child($$, $1); 
						}
					;

for_condition 	 
					:	conditional_expr{
							$$ = mk_node("for_condition");												
							mk_child($$, $1); 
						}
					;

for_update		 
					:	function_call_block COMMA for_update{
							$$ = mk_node("for_update");						
							$2 = mk_node("COMMA");									
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	assignment_block COMMA for_update{
							$$ = mk_node("for_update");						
							$2 = mk_node("COMMA");									
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	ass_var_block arith_unary_op COMMA for_update{
							$$ = mk_node("for_update");						
							$3 = mk_node("COMMA");										
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					|	arith_unary_op ass_var_block COMMA for_update{
							$$ = mk_node("for_update");						
							$3 = mk_node("COMMA");										
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					|	function_call_block{
							$$ = mk_node("for_update");												
							mk_child($$, $1); 
						}
					|	assignment_block{
							$$ = mk_node("for_update");												
							mk_child($$, $1); 
						}
					|	ass_var_block arith_unary_op{
							$$ = mk_node("for_update");												
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	arith_unary_op ass_var_block{
							$$ = mk_node("for_update");												
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	{
						}
					; 

function_def_block
					:	FUNCTION IDENT OP argument_list_block CP OCB general_block CCB{
							$$ = mk_node("function_def_block");						
							$1 = mk_node("FUNCTION");			
							$2 = mk_node("IDENT");			
							$3 = mk_node("OP");			
							$5 = mk_node("CP");			
							$6 = mk_node("OCB");			
							$8 = mk_node("CCB");										
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
							mk_child($$, $5);
							mk_child($$, $6);
							mk_child($$, $7);
							mk_child($$, $8);
						}
					;

argument_list_block
					:	data_type var_block COMMA argument_list_block{
							$$ = mk_node("argument_list_block");			
							$3 = mk_node("COMMA");
							$1 = mk_node("INT");												
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					|	data_type var_block{
							$$ = mk_node("argument_list_block");												
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	{
						}
					;

general_stmt
					:	declaration_block TERMINATOR {
							$$ = mk_node("general_stmt");			
							$2 = mk_node("TERMINATOR");												
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	assignment_block TERMINATOR  {
							$$ = mk_node("general_stmt");		
							$2 = mk_node("TERMINATOR");													
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	conditional_expr TERMINATOR{
							$$ = mk_node("general_stmt");		
							$2 = mk_node("TERMINATOR");													
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					|	PRINT str GT str TERMINATOR
						{
							$$ = mk_node("general_stmt");
							$1 = mk_node("PRINT");
							$3 = mk_node("GT");
							$5 = mk_node("TERMINATOR");
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
							mk_child($$, $5);
						}
					;

str 				: STRING
						{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("STRING");
							mk_child($$, temp);
						}
					;

function_call_block
					:	IDENT OP function_var_list CP {
							$$ = mk_node("function_call_block");		
							$1 = mk_node("IDENT");						
							$2 = mk_node("OP");						
							$4 = mk_node("CP");													
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					;

function_var_list   :  conditional_expr COMMA function_var_list
					   {
					   	 $$ = mk_node("function_var_list");
					   	 $2 = mk_node("COMMA");
					   	 mk_child($$, $1);
					   	 mk_child($$, $2);
					   	 mk_child($$, $3);
					   }
					| conditional_expr{
							$$ = mk_node("function_var_list");
							mk_child($$, $1);
						}
					;

declaration_block
					:	data_type var_list{
							$$ = mk_node("declaration_block");												
							mk_child($$, $1); 
							mk_child($$, $2);
						}
					;

var_list
					:	var_block COMMA var_list{
							$$ = mk_node("var_list");			
							$2 = mk_node("COMMA");												
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	var_block{
							$$ = mk_node("var_list");												
							mk_child($$, $1); 
						}
					|	array_block COMMA var_list{
							$$ = mk_node("var_list");				
							$2 = mk_node("COMMA");											
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	array_block{
							$$ = mk_node("var_list");												
							mk_child($$, $1); 
						}
					;


data_type 	
					:	INT{
							$$ = mk_node("sdata_type");		
							$1 = mk_node("INT");									
							mk_child($$, $1); 
						}
					|	FLOAT{
							$$ = mk_node("data_type");			
							$1 = mk_node("FLOAT");												
							mk_child($$, $1); 
						}
					|	DOUBLE{
							$$ = mk_node("data_type");		
							$1 = mk_node("DOUBLE");													
							mk_child($$, $1); 
						}
					|	CHAR{
							$$ = mk_node("data_type");			
							$1 = mk_node("CHAR");												
							mk_child($$, $1); 
						}
					|	LONG{
							$$ = mk_node("data_type");			
							$1 = mk_node("LONG");												
							mk_child($$, $1); 
						}
					;

var_block 	
					:	VAR{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("var_block");			
							$1 = mk_node("VAR");												
							mk_child($1,temp);
							mk_child($$, $1); 
						}
					|	POINTER{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("var_block");			
							$1 = mk_node("POINTER");												
							mk_child($1,temp);
							mk_child($$, $1);

						}
					;

array_block 
					:	var_block OB conditional_expr CB {//check for expr to return positive value. Run time check for negeative value.
							$$ = mk_node("array_block");	
							$2 = mk_node("OB");	
							$4 = mk_node("CB");												
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					;

ass_var_block
					:	var_block{
							$$ = mk_node("ass_var_block");												
							mk_child($$, $1); 
						}
					|	DREF{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("ass_var_block");		
							$1 = mk_node("DREF");
							mk_child($1,temp);											
							mk_child($$, $1); 
						}
					|	var_block OB conditional_expr CB {// check if expr is returning a index present in the array. 
							$$ = mk_node("ass_var_block");		
							$2 = mk_node("OB");	
							$4 = mk_node("CB");											
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
							mk_child($$, $4); 
							
						}
					;

assignment_block
					:	ass_var_block ASSIGN conditional_expr{
							$$ = mk_node("assignment_block");	
							$2 = mk_node("ASSIGN");													
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
							 
						}
					|	ass_var_block arith_assgn_op conditional_expr{
							$$ = mk_node("assignment_block");												
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
							
						}
					|	ass_var_block bit_assgn_op conditional_expr{
							$$ = mk_node("assignment_block");												
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	ass_var_block ASSIGN assignment_block{
							$$ = mk_node("assignment_block");												
							$2 = mk_node("ASSIGN");													
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	ass_var_block arith_assgn_op assignment_block{
							$$ = mk_node("assignment_block");												
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	ass_var_block bit_assgn_op assignment_block{
							$$ = mk_node("assignment_block");												
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	OP assignment_block CP{
							$$ = mk_node("assignment_block");	
							$$ = mk_node("expr");	
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2);
							mk_child($$, $3);
						}
					;

expr 			
					:	ass_var_block arith_binary_op expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
						}
					|	ass_var_block arith_unary_op expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
						}
					|	ass_var_block bit_binary_op expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
						}
					|	bit_unary_op ass_var_block {
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
						}
					|	arith_unary_op ass_var_block expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3); 
						}
					|	ass_var_block{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
						}
					|	const_block{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
						}
					|	function_call_block{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
						}
					|	OP conditional_expr CP arith_binary_op expr{
							$$ = mk_node("expr");	
							$1 = mk_node("OP");	
							$3 = mk_node("CP");	
																		
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3);
							mk_child($$, $4);
							mk_child($$, $5);
						}
					|	OP conditional_expr CP bit_binary_op expr{
							$$ = mk_node("expr");	
							$1 = mk_node("OP");	
							$3 = mk_node("CP");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3);
							mk_child($$, $4);
							mk_child($$, $5);
						}
					|	OP conditional_expr CP{
							$$ = mk_node("expr");	
							$1 = mk_node("OP");	
							$3 = mk_node("CP");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3);
						}
					|	const_block arith_binary_op expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3);
						}
					|	const_block bit_binary_op expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3);
						}
					|	function_call_block arith_binary_op expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3);
						}
					|	function_call_block bit_binary_op expr{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 							
							mk_child($$, $3);
						}
					|	bit_unary_op const_block{
							$$ = mk_node("expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
						}
					|	{
							$$ = mk_node("expr");
						}
					;

conditional_expr
					:	expr arith_condition_op conditional_expr{
							$$ = mk_node("conditional_expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
						}
					|	expr bit_condition_op conditional_expr{
							$$ = mk_node("conditional_expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
						}
					|	expr{
							$$ = mk_node("conditional_expr");												
							mk_child($$, $1); 
						}
					|	fixed_condition{
							$$ = mk_node("conditional_expr");												
							mk_child($$, $1); 
						}
					|	bit_unary_condition_op expr{
							$$ = mk_node("conditional_expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							
						}
					; 

arith_condition_op
					:	EQ {
							$$ = mk_node("arith_condition_op");
							$1 = mk_node("EQ");														
							mk_child($$, $1); 
						}
					|	NOTEQ {
							$$ = mk_node("arith_condition_op");
							$1 = mk_node("NOTEQ");														
							mk_child($$, $1); 
						}
					|	GT {
							$$ = mk_node("arith_condition_op");
							$1 = mk_node("GT");														
							mk_child($$, $1); 
						}
					|	LT {
							$$ = mk_node("arith_condition_op");
							$1 = mk_node("LT");														
							mk_child($$, $1); 
						}
					|	GE {
							$$ = mk_node("arith_condition_op");
							$1 = mk_node("GE");														
							mk_child($$, $1); 
						}
					|	LE{
							$$ = mk_node("arith_condition_op");
							$1 = mk_node("LE");														
							mk_child($$, $1); 
						}
					|	LTGT{
							$$ = mk_node("arith_condition_op");
							$1 = mk_node("LTGT");
							mk_child($$,$1);
						}
					;

bit_condition_op
					:	AND {
							$$ = mk_node("bit_condition_op");
							$1 = mk_node("AND");														
							mk_child($$, $1); 
						}
					|	OR {
							$$ = mk_node("bit_condition_op");
							$1 = mk_node("OR");														
							mk_child($$, $1); 
						}
					;

bit_unary_condition_op
					:	NOT_1{
							$$ = mk_node("bit_unary_condition_op");
							$1 = mk_node("NOT_1");														
							mk_child($$, $1); 
						}
					;

fixed_condition
					:	TRUE_1{
							$$ = mk_node("fixed_condition");
							$1 = mk_node("TRUE_1");												
							mk_child($$, $1); 
						}
					|	FALSE_1{
							$$ = mk_node("fixed_condition");
							$1 = mk_node("FALSE_1");												
							mk_child($$, $1); 
						}
					;

arith_binary_op
					:	ADD {
							$$ = mk_node("arith_binary_op");
							$1 = mk_node("ADD");														
							mk_child($$, $1); 
						}
					|	SUB {
							$$ = mk_node("arith_binary_op");
							$1 = mk_node("SUB");														
							mk_child($$, $1); 
						}
					|	MULT{
							$$ = mk_node("arith_binary_op");
							$1 = mk_node("MULT");														
							mk_child($$, $1); 
						}
					|	DIV {
							$$ = mk_node("arith_binary_op");
							$1 = mk_node("DIV");														
							mk_child($$, $1); 
						}
					|	EXP {
							$$ = mk_node("arith_binary_op");
							$1 = mk_node("EXP");														
							mk_child($$, $1); 
						}
					|	MOD{
							$$ = mk_node("arith_binary_op");
							$1 = mk_node("MOD");														
							mk_child($$, $1); 
						}
					;

arith_unary_op
					:	INC{
							$$ = mk_node("arith_unary_op");
							$1 = mk_node("INC");														
							mk_child($$, $1); 
						}
					|	DEC{
							$$ = mk_node("arith_unary_op");
							$1 = mk_node("DEC");														
							mk_child($$, $1); 
						}
					;

bit_binary_op 	
					:	BIN_AND {
							$$ = mk_node("bit_binary_op");
							$1 = mk_node("BIN_AND");														
							mk_child($$, $1); 
						}
					|	BIN_OR{
							$$ = mk_node("bit_binary_op");
							$1 = mk_node("BIN_OR");														
							mk_child($$, $1); 
						}
					|	BIN_XOR {
							$$ = mk_node("bit_binary_op");
							$1 = mk_node("BIN_XOR");														
							mk_child($$, $1); 
						}
					|	BIN_LEFT {
							$$ = mk_node("bit_binary_op");
							$1 = mk_node("BIN_LEFT");														
							mk_child($$, $1); 
						}
					|	BIN_RIGHT{
							$$ = mk_node("bit_binary_op");
							$1 = mk_node("BIN_RIGHT");														
							mk_child($$, $1); 
						}
					;

bit_unary_op 	
					:	BIN_NOT{
							$$ = mk_node("bit_unary_op");		
							$1 = mk_node("ADD_ASSIGN");												
							mk_child($$, $1); 
						}
					;

arith_assgn_op
					:	ADD_ASSIGN {
							$$ = mk_node("arith_assgn_op");
							$1 = mk_node("ADD_ASSIGN");													
							mk_child($$, $1); 
						}
					|	SUB_ASSIGN{
							$$ = mk_node("arith_assgn_op");
							$1 = mk_node("SUB_ASSIGN");													
							mk_child($$, $1); 
						}
					|	MULT_ASSIGN {
							$$ = mk_node("arith_assgn_op");
							$1 = mk_node("MULT_ASSIGN");													
							mk_child($$, $1); 
						}
					|	DIV_ASSIGN{
							$$ = mk_node("arith_assgn_op");
							$1 = mk_node("DIV_ASSIGN");													
							mk_child($$, $1); 
						}
					|	MOD_ASSIGN{
							$$ = mk_node("arith_assgn_op");
							$1 = mk_node("MOD_ASSIGN");													
							mk_child($$, $1); 
						}
					|	LEFT_ASSIGN{
							$$ = mk_node("arith_assgn_op");
							$1 = mk_node("LEFT_ASSIGN");													
							mk_child($$, $1); 
						}
					|	RIGHT_ASSIGN{
							$$ = mk_node("arith_assgn_op");
							$1 = mk_node("RIGHT_ASSIGN");													
							mk_child($$, $1); 
						}
					;

bit_assgn_op
					:	BIN_AND_ASSIGN{
							$$ = mk_node("bit_assgn_op");
							$1 = mk_node("BIN_AND_ASSIGN");											
							mk_child($$, $1); 
						}
					|	BIN_IOR_ASSIGN{
							$$ = mk_node("bit_assgn_op");	
							$1 = mk_node("BIN_IOR_ASSIGN");												
							mk_child($$, $1); 
						}
					|	BIN_XOR_ASSIGN{
							$$ = mk_node("bit_assgn_op");	
							$1 = mk_node("BIN_XOR_ASSIGN");												
							mk_child($$, $1); 
						}
					;


%%

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

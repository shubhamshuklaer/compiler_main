%{
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
	#include <bits/stdc++.h>
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
	bool syntax_err=false;
	bool semantic_err=false;
	// #define YYSTYPE struct node *

	void code_generation_traversal(node *root,int i);
	void function_call_block_code_generation(node *temp);
	void expr_code_generation(node *temp);
	void function_var_block_code_generation(node *temp);
	void conditional_code_generation(node *temp);
	void operations_code(node *temp);
	void conditional_operations_code(node *temp);
    void code_generation_general_block(node *temp);
    void code_generation_general_stmt(node *temp);
    void assignment_block_code_generation(node *temp);
    void assignment_operations_code_generation(node *temp);
    void code_generation_if_else(node *temp);
    void code_generation_loop_block(node *temp);
    void code_generation_for_loop(node *temp);
	void code_generation_while_loop(node *temp);
	void code_generation_do_loop(node *temp);
	void code_generation_for_intialization(node *temp);
	void code_generation_for_update(node *temp);
	void code_generation_ass_var_block(node *temp,string reg,string co);
	void code_generation_function_def_block(node *temp);
	void code_generation_function_arg_list(node *temp,string name);

    ofstream fcout("test.s");

	int iflable = 1;
	int loop = 1;
	int function_2=0;
	string function_name_2;
	vector<string> function_vars;
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
%token PRINT SCAN RETURN CPRINT CSCAN

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
%type <entry> SCAN
%type <entry> RETURN
%type <entry> CPRINT
%type <entry> CSCAN

%type <entry> super_block
%type <entry> start_block
%type <entry> comment_block
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

%type <entry> bit_binary_op
%type <entry> bit_unary_op
%type <entry> arith_assgn_op
%type <entry> bit_assgn_op
%type <entry> function_var_list
%type <entry> ident
%type <entry> num
%%

super_block								
					:	start_block{
							$$ = root;
							mk_child($$, $1); 
						}
					;

start_block 							
					:	block{
							$$ = mk_node("start_block");
							mk_child($$, $1);
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



const_block 							
					:	STRING{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("const_block");	
							$1 = mk_node("STRING");		
							mk_child($1, temp);
							mk_child($$, $1); 
							strcpy($$->type, "string");
						}
					|	NUM{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("const_block");	
							$1 = mk_node("NUM");
							mk_child($1, temp);		
							mk_child($$, $1); 
							strcpy($$->type, "int");
						}
					|	CHARACTER{
							struct node *temp = mk_node(yylval.terminal_value);
							$$ = mk_node("const_block");	
							$1 = mk_node("CHARACTER");		
							mk_child($1, temp);
							mk_child($$, $1); 
							strcpy($$->type, "char");
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
							syntax_err=true;
							$$ = mk_node("error");
							mk_child($$, $2);
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
							$1 = mk_node("IF");	
							$2 = mk_node("OP");
							$4 = mk_node("CP");
							$5 = mk_node("OCB");
							$7 = mk_node("CCB");
							$8 = mk_node("ELSE");
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
							$10 = mk_node("CCB");			
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
					|	assignment_block TERMINATOR{
							$$ = mk_node("for_initialization");				
							$2 = mk_node("TERMINATOR");											
							mk_child($$, $1); 
							mk_child($$, $2);
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
					|	function_call_block{
							$$ = mk_node("for_update");												
							mk_child($$, $1); 
						}
					|	assignment_block{
							$$ = mk_node("for_update");												
							mk_child($$, $1); 
						}
					|	{
							$$ = mk_node("Nothing");
						}
					; 

function_def_block
					:	FUNCTION ident OP argument_list_block CP OCB general_block CCB{
							$$ = mk_node("function_def_block");						
							$1 = mk_node("FUNCTION");			
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

ident
				  :    IDENT{
						$$ = mk_node("IDENT");
						struct node *temp = mk_node(yylval.terminal_value);
						mk_child($$,temp);
						}
					;
argument_list_block
					:	data_type var_block COMMA argument_list_block{
							$$ = mk_node("argument_list_block");			
							$3 = mk_node("COMMA");

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
							$$ = mk_node("vhi");
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
					|	PRINT conditional_expr TERMINATOR
						{
							$$ = mk_node("general_stmt");
							$1 = mk_node("PRINT");
							$3 = mk_node("TERMINATOR");
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
						}
					|	CPRINT conditional_expr TERMINATOR
						{
							$$ = mk_node("general_stmt");
							$1 = mk_node("CPRINT");
							$3 = mk_node("TERMINATOR");
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
						}
					| 	SCAN ass_var_block TERMINATOR
						{
							$$ = mk_node("general_stmt");
							$1 = mk_node("SCAN");
							$3 = mk_node("TERMINATOR");
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);	
						}
					| 	CSCAN ass_var_block TERMINATOR
						{
							$$ = mk_node("general_stmt");
							$1 = mk_node("CSCAN");
							$3 = mk_node("TERMINATOR");
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);	
						}
					|   RETURN conditional_expr TERMINATOR
						{
							$$ = mk_node("general_stmt");
							$1 = mk_node("RETURN");
							$3 = mk_node("TERMINATOR");
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3); 
						}

					;


function_call_block
					:	ident OP function_var_list CP {
							$$ = mk_node("function_call_block");		
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
							$$ = mk_node("data_type");		
							$1 = mk_node("INT");									
							mk_child($$, $1); 
						}
					|	CHAR{
							$$ = mk_node("data_type");			
							$1 = mk_node("CHAR");												
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

array_block  		: var_block OB num CB {//check for expr to return positive value.
							$$ = mk_node("array_block");	
							$2 = mk_node("OB");	
							$4 = mk_node("CB");												
							mk_child($$, $1);
							mk_child($$, $2);
							mk_child($$, $3);
							mk_child($$, $4);
						}
					;

num
					:	NUM{
							struct node *temp=mk_node(yyval.terminal_value);
							$$ = mk_node("num");
							$1 = mk_node("NUM");
							mk_child($$,temp);
							strcpy($1->type, "int");
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
							mk_child($$, $3);
							
						}
					|	expr bit_condition_op conditional_expr{
							$$ = mk_node("conditional_expr");												
							mk_child($$, $1); 
							mk_child($$, $2); 
							mk_child($$, $3);
							
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
							$1 = mk_node("BIN_NOT");												
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
	syntax_err=true;
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
    // syntax_graph=agopen(graph_name, Agdirected, NULL);
	root = init_tree();
	gst_obj=new sym_table<func_elem,func_def>;
	vector<pair<string,var_def*> > temp_vctr {pair<string,var_def*>("__main__",new var_def(""))};
	gst_obj->insert(main_func_name,new func_def(temp_vctr,""));

	//yylex();
	yyparse();

	printf("\n\n-----------------   TREE   ------------------\n\n");
	printtree(root, 0);
	if(!syntax_err){
		type_check(root, 0);
		gst_obj->print(sym_tab_out);
			if(!semantic_err){
				get_symbol_table_data();
				code_generation_traversal(root,0);
				fcout<<"jr $ra";
			}else{
				cout<<"Semantic error"<<endl;
			}
	}else{
		cout<<"Syntax err"<<endl;
	}

    FILE *fp=fopen("syntax_graph.gv","w+");
    // agwrite(syntax_graph,fp);
    fclose(fp);
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
    // Agnode_t *graph_root,*graph_child;
    // graph_root=make_graph_node(root);
    char buf[50];
	if(!syntax_err){
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
			int temp_ret_val=gst_obj->insert(temp_func_name,new func_def(temp_arg_list,""));

			if(temp_ret_val==0){
				sym_tab_out<<"Everything fine"<<endl;
			}else if(temp_ret_val==elem_already_exist){
				semantic_err=true;
				sym_tab_out<<"function named foo already exist"<<endl;
			}

			vector<pair<string,var_def*> >::iterator it;
			for(it=temp_arg_list.begin();it!=temp_arg_list.end();it++){
				insert_var_in_symbol_table(func_name,it->first,it->second->data_type,it->second->var_type,it->second->arr_size);	
			}
		}else if(root==func_terminator_node){
			func_name=main_func_name;
		}
	}

	for (int i = 0; i < root->cur_childs; ++i){
        // graph_child=make_graph_node(root->child[i]);
        // sprintf(buf,"%d",edge_id);
        // agedge(syntax_graph,graph_root,graph_child,(char *)buf,true);
        // edge_id++;
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
					// printf("type not defined 0");
				}else if(strcmp(root->child[2]->type, "notdef")==0){
					// printf("type not defined 2");
				}else if(strcmp(root->child[2]->type, root->child[0]->type) != 0){
					// cout << root->child[2]->name << ":" << root->child[2]->type << endl;
					// cout << root->child[0]->name << ":" << root->child[0]->type << endl;
					printf("type mismatch error\n");
					semantic_err = true;
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
					// cout << root->child[0]->name << " : notdef" << endl;
				}else{
					// cout << root->child[0]->type << ":" << root->child[0]->name << "->" << root->name << endl;
				}
				strcpy(root->type, root->child[0]->type);
			}else if(strcmp(root->child[0]->name, "fixed_condition")==0){
				if(strcmp(root->child[0]->type, "notdef")==0){
					// cout << root->child[0]->name << " : notdef" << endl;
				}else{
					// cout << root->child[0]->type << ":" << root->child[0]->name << "->" << root->name << endl;
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
					// cout << root->child[2]->name << ":" << root->child[2]->type << endl;
					// cout << root->child[0]->name << ":" << root->child[0]->type << endl;
					printf("type mismatch error\n");
					semantic_err = true;
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
						// cout << root->child[4]->name << ":" << root->child[4]->type << endl;
						// cout << root->child[1]->name << ":" << root->child[1]->type << endl;
						
						printf("type mismatch error\n");
						semantic_err = true;
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
					// cout << root->child[0]->name << " : notdef" << endl;
				}else{
					// cout << root->child[0]->type << ":" << root->child[0]->name << "->" << root->name << endl;
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
				// cout << root->child[2]->name << ":" << root->child[2]->type << endl;
				// cout << root->child[0]->name << ":" << root->child[0]->type << endl;
			}else if(strcmp(root->child[2]->type, root->child[0]->type) != 0){
				// cout << root->child[2]->name << ":" << root->child[2]->type << endl;
				// cout << root->child[0]->name << ":" << root->child[0]->type << endl;
				
				printf("type mismatch error\n");
				semantic_err = true;
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
			// cout << root->child[0]->child[0]->name << ":" << root->child[0]->child[0]->type << ":" << root->child[0]->child[0]->var_type << endl;
			
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
		semantic_err=true;
	}else{
		ret_val=fe->insert(var_name,new var_def(data_type,var_type,arr_size));
		if(ret_val==0){
			sym_tab_out<<"Insertion successfull"<<endl;
		}else if(ret_val==elem_already_exist){
			semantic_err=true;
			sym_tab_out<<"var named "<<var_name<<" already exist"<<endl;	
		}
	}
}

void get_symbol_table_data(){
	fcout<<".data"<<endl;
	gst_obj->print_data(fcout);
	fcout<<".text"<<endl;
}


void operations_code(node *temp)
{
	string second = temp->name;
	 if(second == "arith_binary_op")
		{	
		//	cout<<"second"<<endl;
			std::string operation = temp->child[0]->name;
				if(operation == "ADD")
				{
					fcout<<"lw $t0,0($sp)"<<std::endl<<"addu $a0, $a0, $t0"<<std::endl;
				} 
				else if(operation == "SUB")
				{
					fcout<<"lw $t0,0($sp)"<<std::endl<<"subu $a0, $a0, $t0"<<std::endl;
				}
				else if(operation == "MULT")
				{
					fcout<<"lw $t0,0($sp)"<<std::endl<<"mult $a0, $t0"<<std::endl<<"mflo $a0"<<std::endl;
				}
				else if(operation == "DIV")
				{
					fcout<<"lw $t0,0($sp)"<<std::endl<<"div $a0, $t0"<<std::endl<<"mflo $a0"<<std::endl;	
				}
				else if(operation == "MOD")
				{
					fcout<<"lw $t0,0($sp)"<<std::endl<<"div $a0, $t0"<<std::endl<<"mfhi $a0"<<std::endl;
				}
				else
				{
					//after loops.. we will do it.. 
				}
		}
		else
		{
			std::string operation = temp->child[0]->name;
			if(operation == "BIN_AND"){
				fcout<<"lw $t0,0($sp)"<<endl<<"and $a0,$a0,$t0"<<endl;
			}
			else if(operation == "BIN_OR")
			{
				fcout<<"lw $t0,0($sp)"<<endl<<"or $a0,$a0,$t0"<<endl;
			}
			else if(operation == "BIN_XOR")
			{
				fcout<<"lw $t0,0($sp)"<<endl<<"xor $a0,$a0,$t0"<<endl;
			}
			else if(operation == "BIN_LEFT")
			{
				fcout<<"lw $t0,0($sp)"<<endl<<"sllv $a0,$a0,$t0"<<endl;
			}
			else if(operation == "BIN_RIGHT")
			{
				fcout<<"lw $t0,0($sp)"<<endl<<"srlv $a0,$a0,$t0"<<endl;
			}
		}
}


void code_generation_traversal(node *root,int j)
{
	//std::cout<<root->name<<" "<<j<<std::endl;
	for(int i=0;i<root->cur_childs;++i)
	{
		std::string s = root->child[i]->name;
		//cout<<s<<endl;
		if(s == "general_block")
		{
			fcout<<"main: "<<endl;
			function_2 = 0;
			code_generation_general_block(root->child[i]);
		}
		else if(s == "function_def_block")
		{
			function_2 = 1;
			function_vars.assign(0,"");
			code_generation_function_def_block(root->child[i]);
		}
		else 
		{
			code_generation_traversal(root->child[i],j+1);
		}
	}
}
void code_generation_function_def_block(node *temp)
{
	 string s = temp->child[1]->child[0]->name;
	 fcout<<temp->child[1]->child[0]->name<<": "<<endl;
	 function_name_2 = s;
	 cout<<function_name_2<<endl;
	 code_generation_function_arg_list(temp->child[3],s);
	 code_generation_general_block(temp->child[6]);
	 if(temp->child[3]->cur_childs>=1)
	 {
	 	fcout<<"jr $ra"<<endl;
	 }
	 else
	 {
	 	fcout<<"addi $sp,$sp,4"<<endl;
	 	fcout<<"jr $ra"<<endl;
	 }
}
void code_generation_function_arg_list(node *temp,string name)
{
	if(temp->cur_childs>=1)
	{
		if(temp->cur_childs > 2){
			code_generation_function_arg_list(temp->child[3],name);
		}
		string s = temp->child[1]->child[0]->child[0]->name;
		fcout<<"addi $sp,$sp,4"<<endl<<"lw $a0, 0($sp)"<<endl;
		function_vars.push_back(name+"_"+s.substr(1,s.length()-1));
		fcout<<"sw $a0,"<<name<<"_"<<s.substr(1,s.length()-1)<<endl;
		 
	}
}
void code_generation_general_block(node *temp)
{
	if(temp->cur_childs > 0)
	{
		std::string s = temp->child[0]->name;
		if(s=="general_stmt")
		{
			code_generation_general_stmt(temp->child[0]);
		}
		else if(s=="loop_block")
		{	
			code_generation_loop_block(temp->child[0]);
		}
		else if(s=="if_else_block")
		{
			code_generation_if_else(temp->child[0]);
		}
		else
		{

		}
		code_generation_general_block(temp->child[1]);
	}
}
void code_generation_loop_block(node *temp)
{
	string s = temp->child[0]->name;
	if(s=="for_loop_block")
	{
		code_generation_for_loop(temp->child[0]);
	}
	else if(s=="while_loop_block")
	{
		code_generation_while_loop(temp->child[0]);
	}
	else
	{
		code_generation_do_loop(temp->child[0]);
	}
}
void code_generation_for_loop(node *temp)
{
	code_generation_for_intialization(temp->child[2]);
	int store = loop;
	loop++;
	loop++;
	fcout<<"loop"<<store<<": "<<endl;
	conditional_code_generation(temp->child[3]->child[0]);
	fcout<<"lui $t0,0x0"<<endl<<"srl $t0,$t0,16"<<endl;
	fcout<<"beq $a0,$t0,loop"<<(store+1)<<endl;
	code_generation_general_block(temp->child[8]);
	code_generation_for_update(temp->child[5]);
	fcout<<"j loop"<<store<<endl;
	fcout<<"loop"<<store+1<<": "<<endl;
}
void code_generation_for_intialization(node *temp)
{
	if(temp->cur_childs!=1)
	{
		if((string)temp->child[0]->name == "function_call_block")
		{
			function_call_block_code_generation(temp->child[0]);
		}
		else
		{
			assignment_block_code_generation(temp->child[0]);
		}
		if(temp->cur_childs == 3)
		{
			code_generation_for_intialization(temp->child[2]);
		}
	}
}
void code_generation_for_update(node *temp)
{
	if(temp->cur_childs!=0)
	{
		if((string)temp->child[0]->name == "function_call_block")
		{
			function_call_block_code_generation(temp->child[0]);
		}
		else
		{
			assignment_block_code_generation(temp->child[0]);
		}
		if(temp->cur_childs == 3)
		{
			code_generation_for_update(temp->child[2]);
		}
	}
}
void code_generation_while_loop(node *temp)
{
	fcout<<"loop"<<loop<<": "<<endl;
	int l = loop;
	loop++;
	loop++;
	conditional_code_generation(temp->child[2]->child[0]);
	fcout<<"lui $t0,0x0"<<endl<<"srl $t0,$t0,16"<<endl;
	fcout<<"beq $a0,$t0,loop"<<(l+1)<<endl;
	code_generation_general_block(temp->child[5]);
	fcout<<"j loop"<<l<<endl;
	fcout<<"loop"<<(l+1)<<": "<<endl;
}
void code_generation_do_loop(node *temp)
{
	int store = loop;
	loop++;
	loop++;
	loop++;
	fcout<<"loop"<<store+2<<": "<<endl;
	code_generation_general_block(temp->child[2]);
	fcout<<"loop"<<store<<": "<<endl;
	conditional_code_generation(temp->child[6]->child[0]);
	fcout<<"lui $t0,0x0"<<endl<<"srl $t0,$t0,16"<<endl;
	fcout<<"beq $a0,$t0,loop"<<(store+1)<<endl;
	fcout<<"j loop"<<store+2<<endl;
	fcout<<"loop"<<store+1<<": "<<endl;
}
void code_generation_if_else(node *temp)
{
	if(temp->cur_childs == 11)
	{
		conditional_code_generation(temp->child[2]->child[0]);
		fcout<<"lui $t0,0x0"<<endl<<"srl $t0,$t0,16"<<endl;
		int store = iflable;
		iflable++;
		iflable++;
		fcout<<"beq $a0,$t0, iflable"<<store<<endl;
		code_generation_general_block(temp->child[5]);
		fcout<<"j iflable"<<(store+1)<<endl;
		fcout<<"iflable"<<(store)<<": "<<endl;		
		code_generation_general_block(temp->child[9]);
		fcout<<"iflable"<<(store+1)<<": "<<endl;
	}
	else if(temp->cur_childs == 9)
	{
		conditional_code_generation(temp->child[2]->child[0]);
		fcout<<"lui $t0,0x0"<<endl<<"srl $t0,$t0,16"<<endl;
		int store = iflable;
		iflable++;
		iflable++;
		fcout<<"beq $a0,$t0, iflable"<<store<<endl;
		code_generation_general_block(temp->child[5]);
		fcout<<"j iflable"<<store+1<<endl;
		fcout<<"iflable"<<store<<": "<<endl;
		code_generation_if_else(temp->child[8]);
		fcout<<"iflable"<<store+1<<": "<<endl;
	}
	else 
	{
		conditional_code_generation(temp->child[2]->child[0]);
		fcout<<"lui $t0,0x0"<<endl<<"srl $t0,$t0,16"<<endl;
		int store = iflable;
		iflable++;
		fcout<<"beq $a0,$t0, iflable"<<store<<endl;
		code_generation_general_block(temp->child[5]);
		fcout<<"iflable"<<store<<": "<<endl;
	}
}
void code_generation_general_stmt(node *temp)
{
	if(temp->cur_childs > 0)
	{
		std::string s = temp->child[0]->name;
		if(s=="declaration_block")
		{
			// symbol table one .. so ignore already handled.
		}
		else if(s=="assignment_block")
		{
			assignment_block_code_generation(temp->child[0]);
		}
		else if(s=="conditional_expr")
		{
			conditional_code_generation(temp->child[0]);
		}
		else if(s == "PRINT")
		{
			conditional_code_generation(temp->child[1]);
			fcout<<"li $v0, 1"<<endl;
			fcout<<"syscall"<<endl;
		}
		else if(s == "CPRINT")
		{
			conditional_code_generation(temp->child[1]);
			fcout<<"li $v0, 11"<<endl;
			fcout<<"syscall"<<endl;
		}
		else if(s== "RETURN")
		{
			conditional_code_generation(temp->child[1]);
			if(function_2 == 1)
			{
				if(function_vars.size() == 0)
				{
					fcout<<"addi $sp,$sp,4"<<endl;
				}
			}
			fcout<<"jr $ra"<<endl;
		}
		else if(s=="SCAN")
		{
			code_generation_ass_var_block(temp->child[1],"$t0","sw");
			fcout<<"sw $a0, 0($sp)"<<endl;
			fcout<<"lw $t0, 0($sp)"<<endl;
			fcout<<"li $v0, 5"<<endl;
			fcout<<"syscall"<<endl;
			fcout<<"lui $a0 ,0x0"<<endl<<"srl $a0,$a0,16"<<endl;
			fcout<<"add $a0,$a0,$v0"<<endl;
			fcout<<"sw $a0, 0($t0)"<<endl;	
		}
		else
		{
			code_generation_ass_var_block(temp->child[1],"$t0","sw");
			fcout<<"sw $a0, 0($sp)"<<endl;
			fcout<<"lw $t0, 0($sp)"<<endl;
			fcout<<"li $v0, 12"<<endl;
			fcout<<"syscall"<<endl;
			fcout<<"lui $a0 ,0x0"<<endl<<"srl $a0,$a0,16"<<endl;
			fcout<<"add $a0,$a0,$v0"<<endl;
			fcout<<"sw $a0, 0($t0)"<<endl;
		}
	}
}
void assignment_block_code_generation(node *temp)
{
	string s = temp->child[0]->name;

	if(s=="ass_var_block")
	{

		string var=temp->child[0]->child[0]->child[0]->child[0]->name;
		s = temp->child[1]->name;
		if(s == "ASSIGN")
		{
			s = temp->child[2]->name;
			cout<<s<<endl;
			if(s=="conditional_expr")
			{
				conditional_code_generation(temp->child[2]);
				
			}
			else
			{
				assignment_block_code_generation(temp->child[2]);
			}

		}
		else if(s == "arith_assgn_op")
		{
			s = temp->child[2]->name;
			cout<<s<<endl;
			if(s=="conditional_expr")
			{
				cout<<"entered"<<endl;
				conditional_code_generation(temp->child[2]);
			}
			else
			{
				assignment_block_code_generation(temp->child[2]);
			}	
			//fcout<<"lw $t0, "<<var.substr(1,var.length()-1)<<"($0)"<<endl;
			fcout<<"sw $a0,0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
			code_generation_ass_var_block(temp->child[0],"$t0","lw");
			fcout<<"addi $sp,$sp,4"<<endl<<"lw $a0,0($sp)"<<endl;
			assignment_operations_code_generation(temp->child[1]);
		}
		else
		{
			s = temp->child[2]->name;
			cout<<s<<endl;
			if(s=="conditional_expr")
			{
				cout<<"entered"<<endl;
				conditional_code_generation(temp->child[2]);
			}
			else
			{
				assignment_block_code_generation(temp->child[2]);
			}
			//fcout<<"lw $t0, "<<var.substr(1,var.length()-1)<<"($0)"<<endl;
			fcout<<"sw $a0,0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
			code_generation_ass_var_block(temp->child[0],"$t0","lw");
			fcout<<"addi $sp,$sp,4"<<endl<<"lw $a0,0($sp)"<<endl;
			assignment_operations_code_generation(temp->child[1]);
		}
		
		fcout<<"sw $a0,0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
		code_generation_ass_var_block(temp->child[0],"$t0","sw");
		fcout<<"addi $sp,$sp,4"<<endl<<"lw $t0,0($sp)"<<endl;

		fcout<<"sw $t0, 0"<<"($a0)"<<endl;
	}
	else
	{
		assignment_block_code_generation(temp->child[0]);
	}
}
void assignment_operations_code_generation(node *temp)
{
	string type = temp->name;
	//cout<<type;
	if(type == "arith_assgn_op")
	{
		string op = temp->child[0]->name;
		if(op == "ADD_ASSIGN")
		{
			fcout<<"addu $a0, $a0, $t0"<<std::endl;
		}
		else if(op == "SUB_ASSIGN")
		{
			fcout<<"sub $a0, $t0, $a0"<<std::endl;
		}
		else if(op == "MULT_ASSIGN")
		{
			fcout<<"mult $a0, $t0"<<std::endl;
			fcout<<"mflo $a0"<<std::endl;
		}
		else if(op == "DIV_ASSIGN")
		{
			fcout<<"div $t0, $a0"<<std::endl;
			fcout<<"mflo $a0"<<std::endl;
		}
		else if(op == "MOD_ASSIGN")
		{
			fcout<<"div $t0, $a0"<<std::endl;
			fcout<<"mfhi $a0"<<std::endl;
		}
		else if(op == "LEFT_ASSIGN")
		{
			fcout<<"sllv $a0,$t0,$a0"<<endl;
		}
		else 
		{
			fcout<<"srlv $a0,$t0,$a0"<<endl;
		}
	}
	else
	{
		string op = temp->child[0]->name;
		if(op == "BIN_AND_ASSIGN")
		{
			fcout<<"and $a0,$a0,$t0"<<endl;
		}
		else if(op == "BIN_IOR_ASSIGN")
		{
			fcout<<"OR $a0,$a0,$t0"<<endl;
		}
		else
		{
			fcout<<"xor $a0,$a0,$t0"<<endl;
		}
	}
}
void code_generation_ass_var_block(node *temp,string reg,string co)
{
	//fcout<<"lw "<<reg<<", "<<first.substr(1,first.length()-1)<<"($0)"<<std::endl;
	std::string first = temp->child[0]->name;
	cout<<first<<endl;
	first = temp->child[0]->child[0]->child[0]->name;
	if(temp->cur_childs > 1)
	{
		fcout<<"addi $sp,$sp,-4"<<endl;
		conditional_code_generation(temp->child[2]);	
		fcout<<"addi $sp,$sp,4"<<endl;
		if(function_2 == 0)
		{
			fcout<<"la $t6, "<<first.substr(1,first.length()-1)<<endl;
		}
		else
		{
			fcout<<"la $t6, "<<function_name_2<<"_"<<first.substr(1,first.length()-1)<<endl;	
		}
		fcout<<"add $a0,$a0,$a0"<<endl<<"add $a0,$a0,$a0"<<endl;
		fcout<<"add $a0,$t6,$a0"<<endl;
		if(co=="lw")
		{
			fcout<<co<<" "<<reg<<", 0"<<"($a0)"<<std::endl;	
		}
		else 
		{

		}
	}
	else 
	{
		if(co=="lw")
		{
			if(function_2 == 0)
			{
				fcout<<co<<" "<<reg<<", "<<first.substr(1,first.length()-1)<<"($0)"<<std::endl;
			}
			else
			{
				fcout<<co<<" "<<reg<<", "<<function_name_2<<"_"<<first.substr(1,first.length()-1)<<"($0)"<<std::endl;	
			}			
		}
		else 
		{
			if(function_2 == 0)
			{
				fcout<<"la $a0, "<<first.substr(1,first.length()-1)<<endl;
			}
			else
			{
				fcout<<"la $a0, "<<function_name_2<<"_"<<first.substr(1,first.length()-1)<<endl;	
			}
		}
	}
}
void expr_code_generation(node *temp)
{
	if(temp->cur_childs == 3)
	{
		
		std::string temp2 = temp->child[0]->name;
		if(temp2 == "const_block")
		{
			expr_code_generation(temp->child[2]);
			fcout<<"sw $a0, 0($sp)"<<std::endl;
			if((string)temp->child[0]->child[0]->name == "CHARACTER")
			{
				std::string first = temp->child[0]->child[0]->child[0]->name;
				first = first.substr(1,first.length()-2);
				int no = first[0];
				cout<<no<<endl<<first<<endl;
				std::stringstream ss;
				ss <<(std::hex)<< no;
				cout<<no<<endl<<ss.str()<<endl;
				std::string res (ss.str());
				fcout<<"lui $a0, 0x"<<res<<std::endl;
				fcout<<"srl $a0, $a0, 16"<<std::endl;
			}
			else 
			{
				std::string first = temp->child[0]->child[0]->child[0]->name;
				std::stringstream ss(first),yy;
				int no;
				ss >> no;
				yy<< std::hex << no;
				std::string res (yy.str());
				fcout<<"lui $a0, 0x"<<res<<std::endl;
				fcout<<"srl $a0, $a0, 16"<<std::endl;
			}
		}
		else if(temp2 == "ass_var_block")
		{
			expr_code_generation(temp->child[2]);
			fcout<<"sw $a0, 0($sp)"<<std::endl;
			std::string first = temp->child[0]->child[0]->child[0]->child[0]->name;
			code_generation_ass_var_block(temp->child[0],"$a0","lw");
		}
		else if(temp2 == "OP")
		{
			conditional_code_generation(temp->child[1]);
			return ;
		}
		else if(temp2 == "function_call_block")
		{
			function_call_block_code_generation(temp->child[0]);
			fcout<<"sw $a0, 0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
			expr_code_generation(temp->child[2]);
			
			fcout<<"addi $sp,$sp,4"<<endl;
		}
		operations_code(temp->child[1]);
	}
	else if(temp->cur_childs == 2)
	{
		std::string temp2 = temp->child[1]->name;
		if(temp2 == "const_block")
		{
			if((string)temp->child[0]->child[0]->name == "CHARACTER")
			{
				std::string first = temp->child[0]->child[0]->child[0]->name;
				first = first.substr(1,first.length()-2);
				int no = first[0];
				cout<<no<<endl<<first<<endl;
				std::stringstream ss;
				ss <<(std::hex)<< no;
				cout<<no<<endl<<ss.str()<<endl;
				std::string res (ss.str());
				fcout<<"lui $a0, 0x"<<res<<std::endl;
				fcout<<"srl $a0, $a0, 16"<<std::endl;
			}
			else 
			{
				std::string first = temp->child[0]->child[0]->child[0]->name;
				std::stringstream ss(first),yy;
				int no;
				ss >> no;
				yy<< std::hex << no;
				std::string res (yy.str());
				fcout<<"lui $a0, 0x"<<res<<std::endl;
				fcout<<"srl $a0, $a0, 16"<<std::endl;
			}
		}
		else if(temp2 == "ass_var_block")
		{
			std::string first = temp->child[1]->child[0]->child[0]->child[0]->name;
			//fcout<<"lw $a0, "<<first.substr(1,first.length()-1)<<"($0)"<<std::endl;
			code_generation_ass_var_block(temp->child[1],"$a0","lw");
		}
		fcout<<"lui $t0,0"<<endl<<"srl $t0,$t0,16"<<endl;
		fcout<<"nor $a0,$a0,$t0"<<endl;
	}
	else if(temp->cur_childs > 3)
	{
		 conditional_code_generation(temp->child[1]);
		 fcout<<"sw $a0, 0($sp)"<<std::endl<<"addi $sp,$sp,-4"<<endl;
		 expr_code_generation(temp->child[4]);
		 fcout<<"addi $sp,$sp,4"<<endl;
		 operations_code(temp->child[3]);
	}
	else
	{
		if(temp->cur_childs > 0 )
		{
			std::string temp2 = temp->child[0]->name;
			if(temp2 == "const_block")
			{
				if((string)temp->child[0]->child[0]->name == "CHARACTER")
				{	
					std::string first = temp->child[0]->child[0]->child[0]->name;
					first = first.substr(1,first.length()-2);
					int no = first[0];
					cout<<no<<endl<<first<<endl;
					std::stringstream ss;
					ss <<(std::hex)<< no;
					cout<<no<<endl<<ss.str()<<endl;
					std::string res (ss.str());
					fcout<<"lui $a0, 0x"<<res<<std::endl;
					fcout<<"srl $a0, $a0, 16"<<std::endl;
				}
				else 
				{
					std::string first = temp->child[0]->child[0]->child[0]->name;
					std::stringstream ss(first),yy;
					int no;
					ss >> no;
					yy<< std::hex << no;
					std::string res (yy.str());
					fcout<<"lui $a0, 0x"<<res<<std::endl;
					fcout<<"srl $a0, $a0, 16"<<std::endl;
				}
			}
			else if(temp2 == "ass_var_block")
			{
				std::string first = temp->child[0]->child[0]->child[0]->child[0]->name;
				//fcout<<"lw $a0, "<<first.substr(1,first.length()-1)<<"($0)"<<std::endl;
				code_generation_ass_var_block(temp->child[0],"$a0","lw");
			}
			else if(temp2 == "function_call_block")
			{
				function_call_block_code_generation(temp->child[0]);
			}
		}
	}
}
void function_call_block_code_generation(node *temp)
{
	fcout<<"sw $ra,0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
	if(function_2==1)
	{
		for(int i=0;i<function_vars.size();i++)
		{
			fcout<<"lw $a0, "<<function_vars[i]<<"($0)"<<endl;
			fcout<<"sw $a0, 0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
		}
	}
	function_var_block_code_generation(temp->child[2]);
	fcout<<"jal "<<temp->child[0]->child[0]->name<<endl;
	if(function_2==1)
	{
		for(int i=0;i<function_vars.size();i++)
		{
			fcout<<"addi $sp,$sp,4"<<endl<<"lw $t0, 0($sp)"<<endl;
			fcout<<"sw $t0, "<<function_vars[i]<<"($0)"<<endl;
		}
	}
	fcout<<"addi $sp,$sp,4"<<endl<<"lw $ra,0($sp)"<<endl;
}
void function_var_block_code_generation(node *temp)
{
	if(temp->cur_childs == 3)
	{
		conditional_code_generation(temp->child[0]);
		fcout<<"sw $a0,0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
		function_var_block_code_generation(temp->child[2]);
	}
	else
	{
		conditional_code_generation(temp->child[0]);
		fcout<<"sw $a0,0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
	}
}
void conditional_code_generation(node *temp)
{
	if(temp->cur_childs == 3)
	{
		expr_code_generation(temp->child[0]);
		fcout<<"sw $a0,0($sp)"<<endl<<"addi $sp,$sp,-4"<<endl;
		conditional_code_generation(temp->child[2]);
		fcout<<"addi $sp,$sp,4"<<endl;
		fcout<<"lw $t0,0($sp)"<<endl;
		conditional_operations_code(temp->child[1]);
	}
	else if(temp->cur_childs == 2)
	{
		expr_code_generation(temp->child[1]);
		fcout<<"slti $a0,$a0,0"<<endl;
	}
	else
	{
		if((string)temp->child[0]->name == "expr")
		{
			expr_code_generation(temp->child[0]);
		}
		else
		{

			if((string)temp->child[0]->child[0]->name == "TRUE_1")
			{
				fcout<<"lui $a0,0x1"<<endl<<"srl $a0,$a0,16"<<endl;
			}
			else 
			{
				fcout<<"lui $a0,0x0"<<endl<<"srl $a0,$a0,16"<<endl;
			}
		}
	}
}
void conditional_operations_code(node *temp)
{
	string type = temp->name;
	if(type == "arith_condition_op")
	{
		string operation = temp->child[0]->name;
		if(operation == "EQ")
		{
			fcout<<"slt $t1,$a0,$t0"<<endl<<"slt $a0, $t0,$a0"<<endl<<"or $a0,$t1,$a0"<<endl<<"lui $t4,0x1"<<endl<<"srl $t4,$t4,16"<<endl<<"sub $a0,$t4,$a0"<<endl;
		}
		else if(operation == "NOTEQ")
		{
			fcout<<"slt $t1,$a0,$t0"<<endl<<"slt $a0, $t0,$a0"<<endl<<"or $a0,$t1,$a0"<<endl<<"lui $t4,0x1"<<endl<<"srl $t4,$t4,16"<<endl;
		}
		else if(operation == "GT")
		{
			fcout<<"slt $a0,$a0,$t0"<<endl;
		}
		else if(operation == "LT")
		{
			fcout<<"slt $a0,$t0,$a0"<<endl;
		}
		else if(operation == "GE")
		{
			fcout<<"slt $t5,$a0,$t0"<<endl;
			fcout<<"slt $t1,$a0,$t0"<<endl<<"slt $a0, $t0,$a0"<<endl<<"or $a0,$t1,$a0"<<endl<<"lui $t4,0x1"<<endl<<"srl $t4,$t4,16"<<endl<<"sub $a0,$t4,$a0"<<endl;
			fcout<<"or $a0,$t5,$a0"<<endl;
		}
		else if(operation == "LE")
		{
			fcout<<"slt $t5,$t0,$a0"<<endl;
			fcout<<"slt $t1,$a0,$t0"<<endl<<"slt $a0, $t0,$a0"<<endl<<"or $a0,$t1,$a0"<<endl<<"lui $t4,0x1"<<endl<<"srl $t4,$t4,16"<<endl<<"sub $a0,$t4,$a0"<<endl;
			fcout<<"or $a0,$t5,$a0"<<endl;
		}
		else 
		{
			fcout<<"slt $t1, $a0,$t0"<<endl<<"slt $a0, $t0,$a0"<<endl<<"or $a0,$t1,$a0"<<endl<<"lui $t4,0x1"<<endl<<"srl $t4,$t4,16"<<endl;
		}
	
	}
	else 
	{
		string operation = temp->child[0]->name;
		if(operation == "AND")
		{
			fcout<<"lui $t1,0x0"<<endl<<"srl $t1,$t1,16"<<endl;
			fcout<<"slt $a0,$t1,$a0"<<endl<<"slt $t2,$t1,$t0"<<endl<<"and $a0,$a0,$t2"<<endl;
		}
		else if(operation == "OR")
		{
			fcout<<"lui $t1,0x0"<<endl<<"srl $t1,$t1,16"<<endl;
			fcout<<"slt $a0,$t1,$a0"<<endl<<"slt $t2,$t1,$t0"<<endl<<"or $a0,$a0,$t2"<<endl;
		}
	}
}
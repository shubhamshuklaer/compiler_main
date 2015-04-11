#include <iostream>
#include "sym_table.h"
#include <vector>
#include <fstream>

using namespace std;

sym_table<func_elem,func_def> *gst_obj;

void func_insertion_code();
void check_func_type_code();
void insert_var_in_fst_code();
void check_var_type_code();
void get_type();

int main(){

	//creating global sym table obj
	gst_obj=new sym_table<func_elem,func_def>;
	
	func_insertion_code();
	check_func_type_code();
	insert_var_in_fst_code();
	check_var_type_code();
	get_type();
	ofstream sym_tab_out("sym_tab_out.txt");
	gst_obj->print(sym_tab_out);
	sym_tab_out.close();

	return 0;
}


void func_insertion_code(){
	int ret_val;
	//inserting a func 
	// double foo(int,float)
	vector<pair<string,var_def *> > _arg_list;
	_arg_list.push_back(pair<string,var_def*>("$a",new var_def("int")));
	_arg_list.push_back(pair<string,var_def*>("$b",new var_def("int")));
	func_def *_fd=new func_def(_arg_list,"double");
	ret_val=gst_obj->insert("foo",_fd);

	if(ret_val==0){
		cout<<"Everything fine"<<endl;
	}else if(ret_val==elem_already_exist){
		cout<<"function named foo already exist"<<endl;
	}
}

void check_func_type_code(){
	int ret_val;
	//To check a function has a correct type
	//create a func_def obj with arugments which you wanna check for correctness
	
	//take eg of func double foo(int,float)
	vector<pair<string,var_def *> > _arg_list;
	_arg_list.push_back(pair<string,var_def*>("",new var_def("int")));
	_arg_list.push_back(pair<string,var_def*>("",new var_def("int")));
	func_def *_fd=new func_def(_arg_list,"double");

	ret_val=gst_obj->check_type("foo",_fd);
	if(ret_val==0){
		cout<<"correct_type"<<endl;
	}else{
		if(ret_val==elem_not_found){
			cout<<"func named foo doesn't exist"<<endl;
		}else if(ret_val==func_wrong_ret_type){
			cout<<"wrong ret type"<<endl;
		}else if(ret_val==func_wrong_num_args){
			cout<<"wrong num args"<<endl;
		}else if(ret_val==func_wrong_arg_type){
			cout<<"wrong arg_type"<<endl;
		}
	}

}


void insert_var_in_fst_code(){
	//insert int abc in func foo scope
	int ret_val;
	func_elem *fe=gst_obj->lookup("foo");
	if(fe==NULL){
		cout<<"func named foo not found"<<endl;
	}else{
		//insert int abc
		ret_val=fe->insert("abc",new var_def("int"));
		if(ret_val==0){
			cout<<"Insertion successfull"<<endl;
		}else if(ret_val==elem_already_exist){
			cout<<"element named abc already exist"<<endl;	
		}
	}
}

void check_var_type_code(){
	//check type of abc in func foo scope
	
	int ret_val;
	func_elem *fe=gst_obj->lookup("foo");
	if(fe==NULL){
		cout<<"func named foo not found"<<endl;
	}else{
		ret_val=fe->check_type("abc",new var_def("int",0,0));
		if(ret_val==0){
			cout<<"var type match"<<endl;
		}else if(ret_val==elem_not_found){
			cout<<"var named abc not found"<<endl;
		}else if(ret_val==var_wrong_type){
			cout<<"var worong type"<<endl;	
		}
	}
}


void get_type(){
	func_elem *fe=gst_obj->lookup("foo");
	var_def *vd=fe->get_type("abc");
	ofstream temp_text("temp_text.txt");
	if(vd!=NULL)
		vd->print(temp_text);
	temp_text.close();
}
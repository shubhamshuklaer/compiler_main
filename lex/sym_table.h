#ifndef _SYM_TABLE_H_
#define _SYM_TABLE_H_
#include <iostream>
#include <map>
#include <vector>
#include <fstream>
#include <iomanip>

using namespace std;

const int elem_already_exist=-1;
const int elem_not_found=-2;
const int func_wrong_ret_type=-3;
const int func_wrong_num_args=-4;
const int func_wrong_arg_type=-5;
const int var_wrong_type=-6;

const int step_width=15;

string dummy_func_name="__main__";

template <typename T,typename R>
class sym_table;

class var_def{
	public:
		string data_type;
		int var_type;//0 means normal_var 1 mearns pointer 2 means arr 3 means pointer array
		int arr_size;//valid for arr

		var_def(string _data_type,int _var_type=0,int _arr_size=0){
			data_type=_data_type;
			var_type=_var_type;
			arr_size=_arr_size;
		}

		var_def(var_def *_vd){
			data_type=_vd->data_type;
			var_type=_vd->var_type;
			arr_size=_vd->arr_size;
		}

		~var_def(){
		}
		int check_type(var_def *_vd){
			if(data_type==_vd->data_type)
				return 0;
			else
				return var_wrong_type;
		}
		void print(ofstream &out_stream,int width=0){
			out_stream<<setw(width)<<"Var Def"<<endl;
			width+=step_width;
			out_stream<<setw(width)<<"data type "<<data_type<<endl;
			out_stream<<setw(width)<<"var_type "<<var_type<<endl;
			out_stream<<setw(width)<<"arr_size "<<arr_size<<endl;
		}

		void print_data(ofstream &data_stream,string prefix){
			data_stream<<prefix;
			if(var_type==0){
				if(data_type=="char")
					data_stream<<" .byte \'0\'"<<endl;
				else if(data_type=="int")
					data_stream<<" .word 0"<<endl;
			}else if(var_type==2){
				if(data_type=="char"){
					data_stream<<" .byte ";
					for(int i=0;i<arr_size;i++){
						if(i==0)
							data_stream<<"0";
						else
							data_stream<<",0";
					}
					data_stream<<endl;
				}else if(data_type=="int"){
					data_stream<<" .word ";
					for(int i=0;i<arr_size;i++){
						if(i==0)
							data_stream<<"\'0\'";
						else
							data_stream<<",\'0\'";
					}
					data_stream<<endl;
				}
			}
		}	
};

class func_def{
	public:
		//string is the variable name and var_def is the var_def obj for that variable
		vector<pair<string,var_def*> > arg_list;
		string ret_type;

		func_def(vector<pair<string,var_def *> > _arg_list,string _ret_type){
			vector<pair<string,var_def *> >::iterator it;
			for(it=_arg_list.begin();it!=_arg_list.end();it++)
				arg_list.push_back(*it);
			ret_type=_ret_type;
		}
		
		func_def(func_def *fd){
			vector<pair<string,var_def*> >::iterator it;
			for(it=fd->arg_list.begin();it!=fd->arg_list.end();it++)
				arg_list.push_back(*it);
			ret_type=fd->ret_type;
		}

		~func_def(){
			vector<pair<string,var_def*> >::iterator it;
			for(it=arg_list.begin();it!=arg_list.end();it++)
				delete it->second;

		}

		int check_type(func_def *_fd){
			if(_fd->ret_type!=ret_type)	
				return func_wrong_ret_type;
			if(_fd->arg_list.size()!=arg_list.size())
				return func_wrong_num_args;
			
			int len=arg_list.size();
			for(int i=0;i<len;i++){
				if(arg_list[i].second->check_type(_fd->arg_list[i].second)!=0)
					return func_wrong_arg_type;
			}

			return 0;
		}

		void print(ofstream &out_stream,int width=0){
			out_stream<<setw(width)<<"func Def"<<endl;
			width+=step_width;
			out_stream<<setw(width)<<"Arg list : "<<endl;
			vector<pair<string,var_def*> >::iterator it;
			for(it=arg_list.begin();it!=arg_list.end();it++){
				out_stream<<setw(width)<<it->first<<endl;
				it->second->print(out_stream,width+step_width);
			}
			out_stream<<setw(width)<<"Ret type : "<<ret_type<<endl;
		}

};


class var_elem{
	var_def *vd;

	public:
		int check_type(var_def *_vd){
			return vd->check_type(_vd);
		}

		var_elem(var_def *_vd){
			vd=new var_def(_vd);
		}

		~var_elem(){
			delete vd;
		}

		void print(ofstream &out_stream,int width=0){
			vd->print(out_stream,width);
		}

		void print_data(ofstream &data_stream,string prefix){
			vd->print_data(data_stream,prefix);
		}

		var_def *get_type(){
			return vd;
		}
};


class func_elem{
	func_def *fd;
	sym_table<var_elem,var_def> *fst;

	public:

		func_elem(func_def* _fd);
		~func_elem();

		int check_type(func_def* _fd);

		int check_type(string,var_def*);
		var_def *get_type(string);
		int insert(string,var_def*);
		var_elem *lookup(string);
		void print(ofstream &,int);
		void print_data(ofstream &,string prefix);
};


//T-var_elem/func_elem
//R-var_def/func_def
template <typename T,typename R>
class sym_table{
	map<string,T*> *st_map;

	public:
		int insert(string key,R* val){
			int ret_val;

			T *new_elem=new T(val);

			if(st_map->find(key)==st_map->end()){
				st_map->insert(pair<string,T*>(key,new_elem));	
				ret_val=0;
			}else{
				ret_val=elem_already_exist;
			}

			return ret_val;
		}

		T* lookup(string key){
			typename map<string,T*>::iterator it;
			
			it=st_map->find(key);

			if(it==st_map->end())
				return NULL;
			else
				return it->second;
		}

		int check_type(string key,R* val){
			typename map<string,T*>::iterator it;
			it=st_map->find(key);

			if(it!=st_map->end())
				return it->second->check_type(val);
			else
				return elem_not_found;

		}


		sym_table(){
			st_map=new map<string,T*>;
		}

		~sym_table(){
			delete st_map;
		}

		void print(ofstream &out_stream,int width=0){
			typename map<string,T*>::iterator it;

			for(it=st_map->begin();it!=st_map->end();it++){
				out_stream<<setw(width)<<"key : "<<it->first<<endl;
				it->second->print(out_stream,width+step_width);
			}
		}

		void print_data(ofstream &data_stream,string prefix="",bool func=true){
			typename map<string,T*>::iterator it;

			for(it=st_map->begin();it!=st_map->end();it++){
				if(func){
					if(it->first==dummy_func_name)
						it->second->print_data(data_stream,prefix);
					else
						it->second->print_data(data_stream,prefix+it->first+"_");
				}else{
					string temp_name=it->first;
					if(temp_name[0]=='$'){
						temp_name.erase(0,1);
					}
					it->second->print_data(data_stream,prefix+temp_name+" : ");
				}
			}
		}
};


//put at last
//to prevent invalid use of incomplete type sym_table<var_elem,var_def>
func_elem::func_elem(func_def* _fd){
	fd=new func_def(_fd);
	fst=new sym_table<var_elem,var_def>();
}

func_elem::~func_elem(){
	delete fd;
	delete fst;
}

int func_elem::insert(string key,var_def *_vd){
	return fst->insert(key,_vd);
}

var_elem * func_elem::lookup(string key){
	return fst->lookup(key);
}

int func_elem::check_type(string key,var_def *_vd){
	return fst->check_type(key,_vd);
}

int func_elem::check_type(func_def *_fd){
	return fd->check_type(_fd);
}

void func_elem::print(ofstream &out_stream,int width=0){
	fd->print(out_stream,width);
	out_stream<<setw(width)<<"FST   : "<<endl;
	width+=step_width;
	fst->print(out_stream,width);

}

void func_elem::print_data(ofstream &data_stream,string prefix=""){
	fst->print_data(data_stream,prefix,false);	
}

var_def *func_elem::get_type(string key){
	var_elem *ve=fst->lookup(key);
	if(ve!=NULL){
		return ve->get_type();
	}else{
		return NULL;
	}
}
#endif

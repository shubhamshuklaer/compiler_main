#ifndef _SYM_TABLE_H_
#define _SYM_TABLE_H_
#include <iostream>
#include <map>
#include <vector>

using namespace std;

const int elem_already_exist=-1;
const int elem_not_found=-2;
const int func_wrong_ret_type=-3;
const int func_wrong_num_args=-4;
const int func_wrong_arg_type=-5;
const int var_wrong_type=-6;

template <typename T,typename R>
class sym_table;

class var_def{
	public:
		string type;

		var_def(string _type){
			type=_type;
		}

		var_def(var_def *_vd){
			type=_vd->type;
		}

		~var_def(){
		}
		int check_type(var_def *_vd){
			if(type==_vd->type)
				return 0;
			else
				return var_wrong_type;
		}
};

class func_def{
	public:
		vector<string> arg_type_list;
		string ret_type;

		func_def(vector<string> _arg_type_list,string _ret_type){
			vector<string>::iterator it;
			for(it=_arg_type_list.begin();it!=_arg_type_list.end();it++)
				arg_type_list.push_back(*it);
			ret_type=_ret_type;
		}
		
		func_def(func_def *fd){
			vector<string>::iterator it;
			for(it=fd->arg_type_list.begin();it!=fd->arg_type_list.end();it++)
				arg_type_list.push_back(*it);
			ret_type=fd->ret_type;
		}

		~func_def(){
		}

		int check_type(func_def *_fd){
			if(_fd->ret_type!=ret_type)	
				return func_wrong_ret_type;
			if(_fd->arg_type_list.size()!=arg_type_list.size())
				return func_wrong_num_args;
			
			int len=arg_type_list.size();
			for(int i=0;i<len;i++){
				if(arg_type_list[i]!=_fd->arg_type_list[i])
					return func_wrong_arg_type;
			}

			return 0;
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
};


class func_elem{
	func_def *fd;
	sym_table<var_elem,var_def> *fst;

	public:

		func_elem(func_def* _fd);
		~func_elem();

		int check_type(func_def* _fd);

		int check_type(string,var_def*);
		int insert(string,var_def*);
		var_elem *lookup(string);
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

#endif

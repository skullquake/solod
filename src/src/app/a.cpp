#include<iostream>
#include<dlfcn.h>
#include"mod/shapefactory.h"
int main(int argc,char** argv){
	/*
	std::string sopath("./lib/liba.so");
	void *handle;
	if((handle=dlopen(sopath.c_str(),RTLD_LAZY))==NULL){
		std::cerr<<"Failed to load "<<sopath<<std::endl;
		return -1;
	}
	std::cerr<<"Loaded "<<sopath<<std::endl;
	*/
	std::string libnam("./lib/liba.so");
	ShapeFactory sf;
	Shape* s0=sf.create(libnam);
	Shape* s1=sf.create(libnam);
	sf.remove(libnam);
	Shape* s2=sf.create(libnam);
	Shape* s3=sf.create(libnam);
	//--------------------------------------------------------------------------
	/*
	Shape* (*mkr)();
	mkr=(Shape* (*)())dlsym(handle,"maker");
	if(mkr==NULL){
		std::cerr<<"Failed to get function"<<std::endl;
		dlclose(handle);
		return -1;
	}
	//void* m=mkr();
	Shape *my_Shape = mkr();//static_cast<Shape *()>(mkr)();
	dlclose(handle);
	*/
	//delete my_Shape;
	//--------------------------------------------------------------------------
	return 0;
}

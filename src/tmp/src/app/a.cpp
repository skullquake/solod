#include<iostream>
#include<dlfcn.h>
#include"mod/shapefactory.h"
#include"app/a.h"
#ifndef SOEXT
#define SOEXT "so"
#endif
int main(int argc,char** argv){
	std::string libnam;
	ShapeFactory sf;
		/*
	{
		libnam=((std::string("./lib/libshape")+std::string(SOEXT)).c_str());
		Shape* s0=sf.create(libnam);
		Shape* s1=sf.create(libnam);
		sf.remove(libnam);
		Shape* s2=sf.create(libnam);
		Shape* s3=sf.create(libnam);
	}
		*/
	{
		std::cout<<"----------------------------------------"<<std::endl;
		libnam=((std::string("./lib/libtriangle")+std::string(SOEXT)).c_str());
		Shape* s0=sf.create(libnam);
		Shape* s1=sf.create(libnam);
		sf.remove(libnam);
		Shape* s2=sf.create(libnam);
		Shape* s3=sf.create(libnam);
	}
	{
		std::cout<<"----------------------------------------"<<std::endl;
		libnam=((std::string("./lib/libsquare")+std::string(SOEXT)).c_str());
		Shape* s0=sf.create(libnam);
		Shape* s1=sf.create(libnam);
		sf.remove(libnam);
		Shape* s2=sf.create(libnam);
		Shape* s3=sf.create(libnam);
	}

	return 0;
}

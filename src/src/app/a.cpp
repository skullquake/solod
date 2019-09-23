#include<iostream>
#include<dlfcn.h>
#include"mod/shapefactory.h"
#ifndef SOEXT
#define SOEXT "so"
#endif
int main(int argc,char** argv){
	std::string libnam((std::string("./lib/liba")+std::string(SOEXT)).c_str());
	ShapeFactory sf;
	Shape* s0=sf.create(libnam);
	Shape* s1=sf.create(libnam);
	sf.remove(libnam);
	Shape* s2=sf.create(libnam);
	Shape* s3=sf.create(libnam);
	return 0;
}

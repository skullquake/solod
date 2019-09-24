#include<iostream>
#include<dlfcn.h>
#include"shape/shapefactory.h"
#include"app/a.h"
#ifndef SOEXT
#define SOEXT "so"
#endif
int main(int argc,char** argv){
	std::string libnam;
	ShapeFactory sf;
	sf.load((std::string("./lib/libtriangle")+std::string(SOEXT)).c_str());
	sf.load((std::string("./lib/libsquare")+std::string(SOEXT)).c_str());
	sf.load((std::string("./lib/libtriangle")+std::string(SOEXT)).c_str());
	sf.load((std::string("./lib/libsquare")+std::string(SOEXT)).c_str());
	sf.load((std::string("./lib/libparallelogram")+std::string(SOEXT)).c_str());
	sf.unload((std::string("./lib/libtriangle")+std::string(SOEXT)).c_str());
	sf.unload((std::string("./lib/libsquare")+std::string(SOEXT)).c_str());
	sf.load((std::string("./lib/libtriangle")+std::string(SOEXT)).c_str());
	sf.load((std::string("./lib/libsquare")+std::string(SOEXT)).c_str());
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

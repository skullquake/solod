#ifndef APP_SHAPEFACTORY_H
#define APP_SHAPEFACTORY_H
#include"shape.h"
#include<map>
class ShapeFactory{
	public:
		ShapeFactory();
		~ShapeFactory();
		Shape* create(std::string);
		bool remove(std::string);
	private:
		std::map<std::string,Shape* (*)()> mf;
};
#endif

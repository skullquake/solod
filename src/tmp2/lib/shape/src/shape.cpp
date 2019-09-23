#include"shape/shape.h"
#include<iostream>
Shape::Shape(){
	std::cout<<"Shape()"<<std::endl;
}
Shape::~Shape(){
	std::cout<<"~Shape()"<<std::endl;
}
extern "C" {
	Shape* maker(){
		return new Shape;
	}
}

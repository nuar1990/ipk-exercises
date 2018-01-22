/*
 * newtonFractal.cc
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#include "newtonFractal.hh"

Newton_Fractal::Newton_Fractal():Complex_Poly() {}

Newton_Fractal::~Newton_Fractal() {}


std::unique_ptr<Point> Newton_Fractal::recurance(Point& z, Point& c){
	//ToDo: implement recurance
	z=Point(pow(z.x(),2)-pow(z.y(),2)+c.x(),2*z.x()*z.y()+c.y());
	return std::make_unique<Point>(z);
}

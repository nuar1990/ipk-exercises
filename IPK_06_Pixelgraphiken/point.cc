/*
 * point.cc
 *
 *  Created on: Dec 8, 2017
 *      Author: nuar
 */

#include "point.hh"

Point::Point():x(0),y(0){}

Point::Point(double _x, double _y):x(_x),y(_y){}

Point::~Point() {}

double Point::_x()const{
	return this->x;
}
double Point::_y()const{
	return this->y;
}

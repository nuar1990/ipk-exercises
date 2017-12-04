/*
 * Point.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: nuar
 */

#include "Point.h"
#include <iostream>

Point::Point():x(0),y(0){};

Point::Point(double x, double y){
	this->x=x;
	this->y=y;
}
std::ostream& operator<<(std::ostream& output, Point& point) {
	output<<point.x<<" "<<point.y;
	return output;
}
std::istream& operator>>(std::istream& input, Point& point) {
	input>>point.x>>point.y;
	return input;
}
void Point::setX(double x){
	this->x=x;
}
void Point::setY(double y){
	this->y=y;
}
Point::~Point() {
}


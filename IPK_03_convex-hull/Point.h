/*
 * Point.h
 *
 *  Created on: Nov 16, 2017
 *      Author: nuar
 */

#ifndef POINT_H_
#define POINT_H_
#include<iostream>

class Point {
private:
	double x;
	double y;
public:
	Point();
	Point(double, double);

	bool operator< (const Point &other) const {
		return x<other.x;
	}

	friend std::istream& operator>>(std::istream&,Point&);
	friend std::ostream& operator<<(std::ostream&,Point&);

	void setX(double);
	void setY(double);
	double getX() const{return x;}
	double getY() const{return y;}
	virtual ~Point();
};

#endif /* POINT_H_ */

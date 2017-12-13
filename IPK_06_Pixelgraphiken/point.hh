/*
 * point.hh
 *
 *  Created on: Dec 8, 2017
 *      Author: nuar
 */

#ifndef POINT_HH_
#define POINT_HH_

class Point {
private:
	double x,y;
public:
	Point();
	Point(double x,double y);
	double _x()const;
	double _y()const;
	virtual ~Point();
};

#endif /* POINT_HH_ */

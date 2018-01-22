/*
 * complex_poly.hh
 *
 *  Created on: Jan 3, 2018
 *      Author: nuar
 */

#ifndef COMPLEX_POLY_HH_
#define COMPLEX_POLY_HH_
#include "iterationResult.hh"
#include <iostream>
#include <string>
#include "histogram.hh"
#include "pgm.hh"
#include "canvas.hh"
/*
 * Abstract class drawing the design of a complex polygon
 * inheriting classes implement the method iterate.
 * Design-Choice instead of a purely abstract function a smart pointer is returned
 * pointing to the Iteration Object.
 */
class Complex_Poly {
public:
	Complex_Poly();
	IterationResult iterate(Point z,Point c, double threshold, int maxIt);
	virtual std::unique_ptr<Point> recurance(Point& z, Point& c)=0;
	virtual ~Complex_Poly();
};

#endif /* COMPLEX_POLY_HH_ */

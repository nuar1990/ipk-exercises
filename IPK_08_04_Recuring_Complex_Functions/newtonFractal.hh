	/*
 * newtonFractal.hh
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#ifndef NEWTONFRACTAL_HH_
#define NEWTONFRACTAL_HH_

#include "iterationResult.hh"
#include "complex_poly.hh"
#include <iostream>

class Newton_Fractal: public virtual Complex_Poly {
public:
	Newton_Fractal();
	virtual ~Newton_Fractal();
	std::unique_ptr<Point> recurance(Point& z, Point& c);
	void calc();
};

#endif /* NEWTONFRACTAL_HH_ */

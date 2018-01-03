/*
 * complex_poly.hh
 *
 *  Created on: Jan 3, 2018
 *      Author: nuar
 */

#ifndef COMPLEX_POLY_HH_
#define COMPLEX_POLY_HH_
#include "iterationResult.hh"
/*
 * Abstract class drawing the design of a complex polygon
 * inheriting classes implement the method iterate.
 * Design-Choice instead of a purely abstract function a smart pointer is returned
 * pointing to the Iteration Object.
 */
class Complex_Poly {
public:
	Complex_Poly();
	virtual std::unique_ptr<IterationResult> iterate(Point z,Point c, double threshold, int maxIt)=0;
	virtual void calc()=0;
	virtual ~Complex_Poly();
};

#endif /* COMPLEX_POLY_HH_ */

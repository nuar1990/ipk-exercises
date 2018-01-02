/*
 * mandelbrot.hh
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#ifndef MANDELBROT_HH_
#define MANDELBROT_HH_

#include "iterationResult.hh"
#include "mandelbrot.hh"

class Mandelbrot: public IterationResult {
public:
	Mandelbrot();
	virtual ~Mandelbrot();
	IterationResult* iterate(Point z,Point c, double threshold, int maxIt);
	void calc();
};

#endif /* MANDELBROT_HH_ */

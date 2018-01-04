/*
 * newtonFractal.cc
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#include "newtonFractal.hh"

Newton_Fractal::Newton_Fractal():Complex_Poly() {}

Newton_Fractal::~Newton_Fractal() {}

std::unique_ptr<IterationResult> Newton_Fractal::iterate(Point z,Point c, double threshold, int maxIt){
	std::unique_ptr<IterationResult> result(new IterationResult());

	return result;
}


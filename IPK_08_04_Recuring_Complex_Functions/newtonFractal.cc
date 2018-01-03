/*
 * newtonFractal.cc
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#include "newtonFractal.hh"

Newton_Fractal::Newton_Fractal():Complex_Poly() {
	// TODO Auto-generated constructor stub

}

Newton_Fractal::~Newton_Fractal() {
	// TODO Auto-generated destructor stub
}

void Newton_Fractal::calc(){
	std::cout<<"Newton_Fractal"<<std::endl;
}

std::unique_ptr<IterationResult> Newton_Fractal::iterate(Point z,Point c, double threshold, int maxIt){
	std::unique_ptr<IterationResult> result(new IterationResult());
	return result;
}

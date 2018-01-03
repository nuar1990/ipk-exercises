/*
 * unit_test.cc
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */


#include "mandelbrot.hh"
#include "newtonFractal.hh"

void pronounceYourName(Complex_Poly& object){
	object.calc();
}

int main(){
	Mandelbrot hallo=Mandelbrot();
	Newton_Fractal hallo2=Newton_Fractal();
	pronounceYourName(hallo2);
}



/*
 * unit_test.cc
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */


#include "mandelbrot.hh"
#include "newtonFractal.hh"

void pronounceYourName(IterationResult& object){
	object.calc();
}
void createImage(IterationResult& object){
	object.iterate()
}

int main(){
	Mandelbrot hallo=Mandelbrot();
	Newton_Fractal hallo2=Newton_Fractal();

	IterationResult blub=IterationResult();

	pronounceYourName(hallo2);

}



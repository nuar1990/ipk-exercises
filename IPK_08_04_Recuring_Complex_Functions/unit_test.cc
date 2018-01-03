/*
 * unit_test.cc
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */


#include "mandelbrot.hh"
#include "newtonFractal.hh"
#include "complex_poly.hh"

int main(){
	Mandelbrot hallo=Mandelbrot();
	Newton_Fractal hallo2=Newton_Fractal();


	Point center=Point(-1,0);
	Canvas picture=Canvas(center,4,3,4000,3000);
	hallo.draw(picture,2,1000,"mandelbrot.pgm",0);
	//mandelbrot(picture,2,1000,"mandelbrot_smooth.pgm",true);

}



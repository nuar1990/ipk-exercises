/*
 * unit_test.cc
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */


#include "mandelbrot.hh"
#include "newtonFractal.hh"
#include "complex_poly.hh"

void rescale(std::string filename){
	Histogram hist=Histogram();
	std::vector<std::vector<int> > grayScaleValues=read_pgm(filename);
	for(auto y:grayScaleValues){
		for(auto x:y){
			if(x!=0)hist.insert(x);
		}
	}
	hist.cutDataSet(5);
	int min=hist.min();
	int max=hist.max();
	for(auto& row:grayScaleValues){
		int i=0;
		for(auto& col:row){
			if(col<=min+1)row[i]=0;
			if(col>min+1&&col<max-1) row[i]=255*(col/max);
			if(col>=max-1)row[i]=255;
			i++;
		}
	}
	write_pgm(grayScaleValues,"rescaled_"+filename);
}

int main(){
	Mandelbrot hallo=Mandelbrot();
	//Newton_Fractal hallo2=Newton_Fractal();


	Point center=Point(-1,0);
	Canvas picture=Canvas(center,4,3,400,300);
	hallo.draw(picture,2,1000,"mandelbrot.pgm");
	hallo.draw(picture,2,1000,"mandelbrot_smooth.pgm",true);

}



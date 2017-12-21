/*
 * mandelbrot.cc
 *
 *  Created on: Dec 21, 2017
 *      Author: nuar
 */
#include "iterationResult.hh"
#include "canvas.hh"
#include <iostream>
#include <string>


void mandelbrot(Canvas& canvas , double threshold, int maxIt, std::string filename){
	IterationResult result=IterationResult();
	Point z=Point();

	for(int i=0;i<canvas.horPixels();i++){
		for(int j=0;j<canvas.vertPixels();j++){
			result=result.iterate(z,canvas.coord(i,j),threshold,maxIt);
			if(result.iterations()>0 && result.iterations()<maxIt){
				canvas(i,j)=log(result.iterations())*100;
			}
		}
	}
	canvas.write(filename);
}

int main(){
	//IterationResult result=IterationResult();
	//Point c=Point(-0.2,0.9);
	//Point z=Point();
	//result=result.iterate(z,c,2.0,100);
	//std::cout<<result.iterations()<<std::endl;
	Point center=Point(-1,0);
	Canvas picture=Canvas(center,4,3,4000,3000);
	mandelbrot(picture,2,2000,"mandelbrot.pgm");
}






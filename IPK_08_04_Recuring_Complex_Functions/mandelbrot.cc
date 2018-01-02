/*
 * mandelbrot.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#include "mandelbrot.hh"

Mandelbrot::Mandelbrot():IterationResult(){}

Mandelbrot::~Mandelbrot() {}

IterationResult* Mandelbrot::iterate(Point z,Point c, double threshold, int maxIt){
	IterationResult result=IterationResult();
	if(std::abs(c.x())>threshold || std::abs(c.y())>threshold ) return result;
	for(int i=0;i<maxIt;i++){
		//std::cout<<"x: "<<z.x()<<" "<<" y: "<<z.y()<<std::endl;
		if(std::abs(z.x())>threshold || std::abs(z.y())>threshold){
			break;
		}
		z=Point(pow(z.x(),2)-pow(z.y(),2)+c.x(),2*z.x()*z.y()+c.y());
		result++;
		result.setLastTrack(z);
	}
	return result;
}

void Mandelbrot::calc(){
	std::cout<<"Mandelbrot"<<std::endl;
}


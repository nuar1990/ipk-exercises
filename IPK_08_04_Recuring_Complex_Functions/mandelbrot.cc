/*
 * mandelbrot.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#include "mandelbrot.hh"

Mandelbrot::Mandelbrot():Complex_Poly(){}

Mandelbrot::~Mandelbrot() {}

std::unique_ptr<IterationResult> Mandelbrot::iterate(Point z,Point c, double threshold, int maxIt){
	std::unique_ptr<IterationResult> result(new IterationResult);
	if(std::abs(c.x())>threshold || std::abs(c.y())>threshold ) return result;
	for(int i=0;i<maxIt;i++){
		//std::cout<<"x: "<<z.x()<<" "<<" y: "<<z.y()<<std::endl;
		if(std::abs(z.x())>threshold || std::abs(z.y())>threshold){
			break;
		}
		z=Point(pow(z.x(),2)-pow(z.y(),2)+c.x(),2*z.x()*z.y()+c.y());
		(*result)++;
		result->setLastTrack(z);
	}
	return result;
}

void Mandelbrot::mandelbrot(Canvas& canvas , double threshold, int maxIt, std::string filename, bool smooth){
	IterationResult result=IterationResult();
	Point z=Point();

	for(int i=0;i<canvas.horPixels();i++){
		for(int j=0;j<canvas.vertPixels();j++){
			result=*iterate(z,canvas.coord(i,j),threshold,maxIt);
			if(result.iterations()>0 && result.iterations()<maxIt){
				if(smooth&& i!=0 && j!=0){
					double k=result.iterations()-log2(log(sqrt(pow(result.lastTrack().x(),2)+
							(result.lastTrack().y(),2)))/log(threshold));
					canvas(i,j)= k;
				}
				else canvas(i,j)=log10(result.iterations())*100;
			}
		}
	}
	canvas.write(filename);
}

void Mandelbrot::julia(Point c,Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth){
	IterationResult result=IterationResult();

	for(int i=0;i<canvas.horPixels();i++){
		for(int j=0;j<canvas.vertPixels();j++){
			result=*iterate(canvas.coord(i,j),c,threshold,maxIt);
			if(result.iterations()>0 && result.iterations()<maxIt){
				if(smooth&& i!=0 && j!=0){
					double k=result.iterations()-log2(log(sqrt(pow(result.lastTrack().x(),2)+
							(result.lastTrack().y(),2)))/log(threshold));
					canvas(i,j)= k;
				}
				else canvas(i,j)=log10(result.iterations())*100;
			}
		}
	}
	canvas.write(filename);
}

void Mandelbrot::calc(){
	std::cout<<"Mandelbrot"<<std::endl;
}


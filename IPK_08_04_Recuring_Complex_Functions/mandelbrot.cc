/*
 * mandelbrot.cpp
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#include "mandelbrot.hh"

Mandelbrot::Mandelbrot():Complex_Poly(){}

Mandelbrot::~Mandelbrot() {}

std::unique_ptr<Point> Mandelbrot::recurance(Point& z, Point& c){
	z=Point(pow(z.x(),2)-pow(z.y(),2)+c.x(),2*z.x()*z.y()+c.y());
	return std::make_unique<Point>(z);
}

void Mandelbrot::draw(Canvas& canvas , double threshold, int maxIt, std::string filename, bool smooth){
	std::cout<<"Drawing Mandelbrot, please wait..."<<std::endl;
	IterationResult result=IterationResult();
	Point z=Point();

	for(int i=0;i<canvas.horPixels();i++){
		for(int j=0;j<canvas.vertPixels();j++){
			result=iterate(z,canvas.coord(i,j),threshold,maxIt);
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
	std::cout<<"Done."<<std::endl;
}


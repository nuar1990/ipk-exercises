/*
 * mandelbrot.cc
 *
 *  Created on: Dec 21, 2017
 *      Author: nuar
 */
#include "iterationResult.hh"
#include "canvas.hh"
#include "histogram.hh"
#include <iostream>
#include <string>
#include <math.h>


void mandelbrot(Canvas& canvas , double threshold, int maxIt, std::string filename, bool smooth =false){
	IterationResult result=IterationResult();
	Point z=Point();

	for(int i=0;i<canvas.horPixels();i++){
		for(int j=0;j<canvas.vertPixels();j++){
			result=result.iterate(z,canvas.coord(i,j),threshold,maxIt);
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
void julia(Point c,Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth =false){
	IterationResult result=IterationResult();

	for(int i=0;i<canvas.horPixels();i++){
		for(int j=0;j<canvas.vertPixels();j++){
			result=result.iterate(canvas.coord(i,j),c,threshold,maxIt);
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
	Point center=Point(-1,0);
	Canvas picture=Canvas(center,4,3,4000,3000);
	mandelbrot(picture,2,1000,"mandelbrot.pgm");
	mandelbrot(picture,2,1000,"mandelbrot_smooth.pgm",true);
	Point c=Point(-0.8,0.156);
	Canvas picture2=Canvas(c,5,3,4000,3000);
	julia(c,picture2,2,1000,"julia.pgm");
	julia(c,picture2,2,1000,"julia_smooth.pgm",true);
	rescale("julia_smooth.pgm");
	rescale("julia.pgm");
	rescale("mandelbrot.pgm");
	rescale("mandelbrot_smooth.pgm");
}






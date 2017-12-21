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

int main(){
IterationResult result=IterationResult();
Point c=Point();
Point z=Point();
result=result.iterate(z,c,10,100);
std::cout<<result.iterations()<<std::endl;
}


void mandelbrot(Canvas& canvas , double threshold, int maxIt, std::string filename){

}



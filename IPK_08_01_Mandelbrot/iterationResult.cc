/*
 * iterationResult.cpp
 *
 *  Created on: Dec 21, 2017
 *      Author: nuar
 */

#include "iterationResult.hh"

IterationResult::IterationResult()
	:_lastTrack(Point()),
	 _iterations(0)
{}

IterationResult::~IterationResult()
{}

int IterationResult::iterations() const{
	return _iterations;
}

Point IterationResult::lastTrack() const {
	return _lastTrack;
}

void IterationResult::operator++(int){
	_iterations++;
}

void IterationResult::setLastTrack(Point& lastTrack){
	_lastTrack=lastTrack;
}

IterationResult IterationResult::iterate(Point z,Point c, double threshold, int maxIt){
	IterationResult result=IterationResult();
	if(std::abs(c.x())>threshold || std::abs(c.y())>threshold ) return result;
	for(int i=0;i<maxIt;i++){
		//std::cout<<"x: "<<z.x()<<" "<<" y: "<<z.y()<<std::endl;
		if(std::abs(z.x())>threshold || std::abs(z.y())>threshold){
			break;
		}
		z=Point(pow(z.x(),2)-pow(z.y(),2)+c.x(),2*z.x()*z.y()+c.y());
		result++;
	}
	return result;
}

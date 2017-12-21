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
	for(int i=0;i<maxIt;i++){

	}
	return result;
}

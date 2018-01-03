/*
 * iterationResult.cc
 *
 *  Created on: Dec 26, 2017
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

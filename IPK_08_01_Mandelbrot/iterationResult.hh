/*
 * iterationResult.h
 *
 *  Created on: Dec 21, 2017
 *      Author: nuar
 */

#ifndef ITERATIONRESULT_HH_
#define ITERATIONRESULT_HH_
#include "point.hh"
#include <cmath>
#include <iostream>

class IterationResult {
private:
	Point _lastTrack;
	int _iterations;
public:
	IterationResult();
	//ToDo: Defining Non-Standard Constructor - yet unsure about Parameters
	IterationResult iterate(Point z, Point c, double threshold, int maxIt);
	int iterations() const;
	Point lastTrack() const;
	void operator++(int);
	void setLastTrack(Point& lastTrack);
	virtual ~IterationResult();
};

#endif /* ITERATIONRESULT_HH_ */

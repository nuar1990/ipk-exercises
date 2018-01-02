/*
 * iterationResult.hh
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#ifndef ITERATIONRESULT_HH_
#define ITERATIONRESULT_HH_
#include <iostream>
#include "point.hh"
#include <cmath>

class IterationResult {
private:
	Point _lastTrack;
	int _iterations;
public:
	IterationResult();
	virtual ~IterationResult();
	int iterations() const;
	Point lastTrack() const;
	void operator++(int);
	void setLastTrack(Point& lastTrack);
	virtual IterationResult* iterate(Point z,Point c, double threshold, int maxIt)=0;
	virtual void calc();
};

#endif /* ITERATIONRESULT_HH_ */

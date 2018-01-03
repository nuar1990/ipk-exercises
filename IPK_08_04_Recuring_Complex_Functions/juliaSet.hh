/*
 * juliaSet.hh
 *
 *  Created on: Jan 3, 2018
 *      Author: nuar
 */

#ifndef JULIASET_HH_
#define JULIASET_HH_

#include "complex_poly.hh"

class Julia_Set: public virtual Complex_Poly {
public:
	Julia_Set();
	std::unique_ptr<IterationResult> iterate(Point z,Point c, double threshold, int maxIt);
	virtual ~Julia_Set();
	void draw(Point c,Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth=false);
};

#endif /* JULIASET_HH_ */

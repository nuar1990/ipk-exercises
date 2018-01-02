	/*
 * newtonFractal.hh
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#ifndef NEWTONFRACTAL_HH_
#define NEWTONFRACTAL_HH_

#include "iterationResult.hh"
#include <iostream>

class Newton_Fractal: public virtual IterationResult {
public:
	Newton_Fractal();
	virtual ~Newton_Fractal();
	void calc();
};

#endif /* NEWTONFRACTAL_HH_ */

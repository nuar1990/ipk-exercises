/*
 * complex_poly.cc
 *
 *  Created on: Jan 3, 2018
 *      Author: nuar
 */

#include "complex_poly.hh"

Complex_Poly::Complex_Poly() {
	// TODO Auto-generated constructor stub

}

Complex_Poly::~Complex_Poly() {
	// TODO Auto-generated destructor stub
}

IterationResult Complex_Poly::iterate(Point z,Point c, double threshold, int maxIt){
	IterationResult result=IterationResult();
	if(std::abs(c.x())>threshold || std::abs(c.y())>threshold ) return result;
	for(int i=0;i<maxIt;i++){
		if(std::abs(z.x())>threshold || std::abs(z.y())>threshold){
			break;
		}
		z=*recurance(z,c);
		result++;
		result.setLastTrack(z);
	}
	return result;
}

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

void Complex_Poly::rescale(std::string filename){
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

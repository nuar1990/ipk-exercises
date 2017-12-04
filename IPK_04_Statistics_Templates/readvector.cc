/*
 * readvector.cc
 *
 *  Created on: Nov 23, 2017
 *      Author: nuar
 */
#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include "io.hh"
#include "statistics.h"

int main(int argc, char *argv[]){
	std::vector<double> ioVector= read_vector();
	std::array<int, 3> a2 = {1, 2, 3};
	std::cout<<"Average: "<<mean(a2)<<std::endl;
    //std::cout<<"Median: "<<median(ioVector)<<std::endl;
    //std::cout<<"Moment m_4: "<<moment(ioVector,4)<<std::endl;
    //std::cout<<"Standard Deviation: "<<standard_deviation(ioVector)<<std::endl;

    //std::cout<<"Compare Functions a: "<< pow(standard_deviation(ioVector),2);
    //std::cout<<"   b:"<<moment(ioVector,2)-mean(ioVector)*mean(ioVector)<<std::endl;
    return 0;
}

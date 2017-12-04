/*
 * normal.cc
 *
 *  Created on: Nov 23, 2017
 *      Author: nuar
 */
#include <iostream>
#include <vector>
#include <cmath>
#include "io.hh"
#include "statistics.h"

int main(int argc, char *argv[]){
    std::cout<<"This is the random normal_distribution with "<<pow(10,4)<<" vector elements:"<<std::endl;
    std::vector<double> normalVector= normal_distribution(random_seed(),pow(10,4),10.9233123,6.21231122);
	std::cout<<"Average: "<<mean(normalVector)<<std::endl;
	std::cout<<"Median: "<<median(normalVector)<<std::endl;
	std::cout<<"Moment m_4: "<<moment(normalVector,4)<<std::endl;
	std::cout<<"Standard Deviation: "<<standard_deviation(normalVector)<<std::endl;

    std::cout<<"Compare Functions a: "<< pow(standard_deviation(normalVector),2);
    std::cout<<"   b:"<<moment(normalVector,2)-mean(normalVector)*mean(normalVector)<<std::endl;
	return 0;
}



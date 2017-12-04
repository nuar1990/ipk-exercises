/*
 * uniform.cc
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
 std::cout<<"This is the random unified_distribution with "<<pow(10,6)<<" vector elements:"<<std::endl;
    std::vector<double> uniformVector= uniform_distribution(random_seed(),pow(10,2),0,6.100);
    std::cout<<"Average: "<<mean(uniformVector)<<std::endl;
    std::cout<<"Median: "<<median(uniformVector)<<std::endl;
    std::cout<<"Moment m_4: "<<moment(uniformVector,4)<<std::endl;
    std::cout<<"Standard Deviation: "<<standard_deviation(uniformVector)<<std::endl;

    std::cout<<"Compare Functions a: "<< pow(standard_deviation(uniformVector),2);
    std::cout<<"   b:"<<moment(uniformVector,2)-mean(uniformVector)*mean(uniformVector)<<std::endl;
return 0;
}

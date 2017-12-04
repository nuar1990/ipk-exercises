/*
 * statistics.cpp
 *
 *  Created on: Nov 23, 2017
 *      Author: nuar
 */

#include "statistics.h"
#include <algorithm>
#include <cmath>
#include <iostream>

double mean(const std::vector<double> &v){
	double mean=0;
	for(unsigned int i=0;i<v.size();i++){
		mean+=v[i];
	}
	if(v.empty()){
		return 0;
	}
	return mean/v.size();
}
double median(const std::vector<double> &v){
	double median=0;
	std::vector<double> sortedVector;
	std::vector<double>::iterator it;

	it=sortedVector.begin();
	sortedVector.insert(it,v.begin(),v.end());

	std::sort(sortedVector.begin(),sortedVector.end());

	if(!v.empty()){
		if(sortedVector.size()%2==0){
			//if n-amount of vector object is even return the sum of the (v_n v_n+1)/2 element
			median= 0.5*(sortedVector[(sortedVector.size()/2)-1]+sortedVector[(sortedVector.size()/2)]);
		}
		if(sortedVector.size()%2!=0){
			median=sortedVector[((sortedVector.size()+1)/2)-1];
		}
	}
	return median;
}
double moment(const std::vector<double> &v,int k){
	double moment=0;
	for(unsigned int i=0;i<v.size();i++){
		moment+=pow(v[i], k);
	}
	if(v.empty()){
		return 0;
	}
	return moment/v.size();
}
double standard_deviation(const std::vector<double> &v){
	double standard=0;
	for(unsigned int i=0;i<v.size();i++){
		standard+=pow(v[i]-mean(v), 2);
	}
	if(v.empty()) return 0;
	standard=sqrt(standard/(v.size()));
	return standard;
}

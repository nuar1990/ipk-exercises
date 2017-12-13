/*
 * histogram.h
 *
 *  Created on: Dec 13, 2017
 *      Author: nuar
 */

#ifndef HISTOGRAM_HH_
#define HISTOGRAM_HH_
#include <vector>
#include <iostream>
#include <iomanip>
#include <algorithm>
class Histogram {
private:
	std::vector<double> data_set;
protected:
	//method to avoid code copying
	void output(std::vector<int> &bin);
	void output_normal(std::vector<int>&bin);
	std::vector<int> initialize(unsigned int bin_count);
	//helper function for i/o
	unsigned GetNumberOfDigits(unsigned i);
public:
	//default constructible
	Histogram();
	//deconstructor
	virtual ~Histogram();
	//add new number to data set
	void insert(double x);
	// return size of data set
	unsigned int size() const;
	// return smallest value in data set
	double min() const;
	// return largest value in data set
	double max() const;
	// classify the data into bin_count bins and
	// print the histogram for the data set to stdout
	void print(unsigned int bin_count);
	//normalized output of previous method
	void print_normalized(unsigned int bin_count);

};
#endif /* HISTOGRAM_HH_ */

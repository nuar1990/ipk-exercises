/*
 * statistics.h
 *
 *  Created on: Nov 23, 2017
 *      Author: nuar
 */

#ifndef STATISTICS_H_
#define STATISTICS_H_

#include <vector>
#include "statistics.h"

template <class T> double mean(const T v);
double median(const std::vector<double> &v);
double moment(const std::vector<double> &v,int k);
double standard_deviation(const std::vector<double> &v);

#endif /* STATISTICS_H_ */

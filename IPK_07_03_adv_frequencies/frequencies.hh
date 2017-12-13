/*
 * frequencies.hh
 *
 *  Created on: Dec 13, 2017
 *      Author: nuar
 */

#ifndef FREQUENCIES_HH_
#define FREQUENCIES_HH_

#include <unordered_map>
#include <map>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <typeinfo>

template <typename Map> void print_frequencies_sorted(const Map& map);
bool cleanup(std::string & word);
bool cleanup(char& c);
#endif /* FREQUENCIES_HH_ */

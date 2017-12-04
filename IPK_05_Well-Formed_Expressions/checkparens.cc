/*
 * main_expressions.cc
 *
 *  Created on: Dec 4, 2017
 *      Author: nuar
 */
#include "input.hh"
#include "lint.hh"
#include <iostream>
int main(){
	lint customString=lint();
	std::string str=read_stream(std::cin);
	bool isTrue=customString.check_parentheses(str);
}

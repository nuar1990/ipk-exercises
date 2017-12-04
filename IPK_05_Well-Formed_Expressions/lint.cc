/*
 * lint.cc
 *
 *  Created on: Dec 4, 2017
 *      Author: nuar
 */

#include "lint.hh"

lint::lint() {
	// TODO Auto-generated constructor stub

}

lint::~lint() {
	// TODO Auto-generated destructor stub
}

bool lint::check_parentheses(std::string symbols){
	char compare;
	std::stack<char> pStack;
	for(std::string::iterator it=symbols.begin();it!=symbols.end();++it){
		if(*it=='('||*it=='['||*it=='{'){
			pStack.push(*it);
		}
		if(*it==')'||*it==']'||*it=='}'){

			if(!pStack.empty()){
				compare=pStack.top();
				pStack.pop();
				switch(compare){
				case '(':
							if(*it==')') break;
							else{
								std::cerr<<"expected a )"<<std::endl;
								return false;
							}
				case '[':
						if(*it==']') break;
						else{
							std::cerr<<"expected a ]"<<std::endl;
							return false;
						}
				case '{':
						if(*it=='}') break;
						else{
							std::cerr<<"expected a }"<<std::endl;
							return false;
						}

				default:
						std::cerr<<"wrong use of parenthesis"<<std::endl;
						return false;
				}
			}
			else{
				std::cerr<<"wrong use of parenthesis"<<std::endl;
				break;
			}
		}

	}
	if(pStack.empty()) return true;
	else{
		std::cerr<<"missing parentheses."<<std::endl;
	}
	return false;
}

/*
 * wordfrequencies.cc
 *
 *  Created on: Dec 12, 2017
 *      Author: nuar
 */


#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <iomanip>
#include "sanitizeword.hh"


std::unordered_map<std::string,int> get_frequencies(){
	std::unordered_map<std::string,int> frequencies;
	while(1){
		//creating string putting line into stringstream
		std::string str;
		std::ws(std::cin);
		std::getline(std::cin,str);
		std::istringstream iss(str);

		if(std::cin.eof()) {
			std::cout<<" terminating:" <<std::endl;
			break;
		}
		std::string word;
		while(iss>>word){
			//the sanctitity of strings
			word=sanitize_word(word);
			bool exist=false;
			for(auto& entry:frequencies){
				if(entry.first==word){
					entry.second+=1;
					exist=true;
					break;
				}
			}
			if(!exist) frequencies.insert(std::pair<std::string,int>(word,1));
		}
	}
	return frequencies;
}

void print_frequencies(const std::unordered_map<std::string,int>& frequencies){
	long int sum=0;
	for(auto entry:frequencies){
		sum+=entry.second;
	}

	for(auto entry:frequencies){
		std::cout<<std::right<<std::setfill(' ')<<entry.first<<":"<<std::setw(30-entry.first.size())<<(double)entry.second<<std::endl;
	}
	std::cout<<"words counted: " <<sum<<std::endl;
}


int main(){
	auto a=get_frequencies();
	print_frequencies(a);
	return 0;
}

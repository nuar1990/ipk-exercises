/*
 * letterfrequencies.cc
 *
 *  Created on: Dec 12, 2017
 *      Author: nuar
 */

#include <map>
#include <iostream>
#include <string>

std::map<char,int>  get_frequencies(){
	std::map<char,int> frequencies;
	while(1){
		unsigned char c;
		//read in char
		std::cin>>c;
		//abort if input closed
		if(not std::cin) break;
		if(!std::isalpha(c)){
			std::cin.ignore();
			std::cin.clear();
			continue;
		}
		c=std::toupper(c);
		bool exist=false;
		for(auto& entry: frequencies){
			if(entry.first==c){
				entry.second+=1;
				exist=true;
				break;
			}
		}
		if(!exist) frequencies.insert(std::pair<char,int>(c,1));
	}
	return frequencies;
}

void print_frequencies(const std::map<char,int>& frequencies){
	long int sum=0;
	for(auto entry:frequencies){
		sum+=entry.second;
	}

	for(auto entry:frequencies){
		std::cout<<entry.first<<"    "<<(double)entry.second/sum *100<<"%"<<std::endl;
	}
	std::cout<<"characters counted: " <<sum<<std::endl;

}


int main(int argc, char *argv[]){
	auto a=get_frequencies();
	print_frequencies(a);
	return 0;
}

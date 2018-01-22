/*
 * letterfrequencies.cc
 *
 *  Created on: Dec 12, 2017
 *      Author: nuar
 */

#include <map>
#include <iostream>
#include <fstream>
#include <string>

std::map<char,int>  get_frequencies(const std::string& file =std::string() ){
	std::map<char,int> frequencies;
	//handle .txt files
	if(file.size()>0){
		std::string line;
		std::ifstream data(file);
		if(!data.is_open()) std::cerr<<"The file doesn't exist"<<std::endl;
		else{
			while(std::getline(data,line)){
				std::string no_ws;
				for(auto it=line.begin();it!=line.end();it++){
					if(!std::isalpha(*it)) continue; //ignoring everything but letters.
					*it=std::toupper(*it);
					std::map<char,int>::iterator iter=frequencies.find(*it);
					if(iter==frequencies.end()) frequencies.insert(std::pair<char,int>(*it,1));
					else iter->second++;
				}
			}
		}
	}
	//handle manual terminal entries
	else{
		while(1){
			unsigned char c;
			//read in char
			std::cin>>c;
			//abort if input closed
			if(!std::cin) break;
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
	}
	return frequencies;
}

void print_frequencies(const std::map<char,int>& frequencies){
	long int sum=0;
	for(auto entry:frequencies)
		sum+=entry.second;

	for(auto entry:frequencies)
		std::cout<<entry.first<<"    "<<(double)entry.second/sum*100<<"%"<<std::endl;
}


int main(int argc, char *argv[]){

	auto a=get_frequencies();
	print_frequencies(a);
	return 0;
}

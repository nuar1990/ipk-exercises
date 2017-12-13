/*
 * frequencies.cc
 *
 *  Created on: Dec 13, 2017
 *      Author: nuar
 */

#include "frequencies.hh"
#include "sanitizeword.hh"
#include "histogram.hh"

bool cleanup(std::string& word){
	word=	sanitize_word(word);
	return true;
}
bool cleanup(char &c){
	if(!std::isalpha(c)) return false;
	else c=std::toupper(c);
	return true;
}
template <typename Map> void print_frequencies_sorted(const Map& map){
	Map frequencies=map;
	while(1){
		//read input
		typename Map::key_type key;
		std::cin>>key;
		//abort if input is closed
		if(not std::cin) break;
		//overloaded cleanup function
		if(!cleanup(key))continue;

		bool exist=false;
		for(auto& entry:frequencies){
			if(entry.first==key){
				entry.second+=1;
				exist=true;
				break;
			}
		}
		if(!exist) frequencies.insert(std::pair<typename Map::key_type,int>(key,1));
	}

	/* Sorting by Value by inverting key/value in ordered map*/
	long int sum=0;
	std::map<int,typename Map::key_type,std::greater<int>> orderedMap;
	for(auto entry:frequencies){
		sum+=entry.second;
		orderedMap.insert(std::pair<int,typename Map::key_type>(entry.second,entry.first));
	}
	for(auto entry:orderedMap){
		std::cout<<entry.second<<": "<<std::internal<<std::setw(30)<<((double)entry.first/sum)*100<<"%"<<std::endl;
	}
	if(std::is_same<typename Map::key_type,char>::value) std::cout<<"characters counted: "<<sum<<std::endl<<std::endl;
	else std::cout<<"words counted: " <<sum<<std::endl<<std::endl;

	Histogram histo=Histogram();
	for(auto entry:frequencies){
		histo.insert(entry.second);
	}
	histo.print(frequencies.size());

}

int main(){
	//std::map<char,int> frequencies;
	std::map<std::string,int> frequencies;
	//std::unordered_map<char,int> frequencies;
	//std::unordered_map<std::string,int> frequencies;

	print_frequencies_sorted(frequencies);

	return 0;

}



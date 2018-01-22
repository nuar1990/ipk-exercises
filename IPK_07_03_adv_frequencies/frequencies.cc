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

template <typename Map>
void print_frequencies_sorted(const Map& map){
	Map frequencies=map;
	typename Map::key_type key;
	std::vector<std::pair<int,typename Map::key_type>> tokens;
	//reading in data
	while(std::cin>>key){
		//specialized function
		if(!cleanup(key)) continue;
		typename Map::iterator iter=frequencies.find(key);
		if(iter==frequencies.end()) frequencies.insert(std::pair<typename Map::key_type,int>(key,1));
		else iter->second++;
	}
	//pushing data into vector
	for(auto entry:frequencies){
		tokens.emplace_back(entry.second,entry.first);
	}
	//and sort it
	std::sort(tokens.begin(),tokens.end());

	//now print
	for(auto entry:tokens){
		std::cout<<(double)entry.first/tokens.size()*100<<"%  "<<std::setw(30)<<entry.second<<std::endl;
	}

}

int main(){
	std::map<char,int> frequencies_a;
	std::map<std::string,int> frequencies_b;
	std::unordered_map<char,int> frequencies_c;
	std::unordered_map<std::string,int> frequencies_d;

	print_frequencies_sorted(frequencies_d);

	return 0;

}



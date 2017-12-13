	/*
 * histogram.cpp
 *
 *  Created on: Dec 13, 2017
 *      Author: nuar
 */

#include "histogram.hh"

#include "io.hh"

Histogram::Histogram() {}

Histogram::~Histogram() {}

void Histogram::insert(double x){	data_set.push_back(x);}

unsigned int Histogram::size() const{	return data_set.size(); }

double Histogram::min() const{
	double min=*std::min_element(data_set.begin(),data_set.end());
	return min;
}

double Histogram::max() const {
	double max=*std::max_element(data_set.begin(),data_set.end());
	return max;
}

std::vector<int> Histogram::initialize(unsigned int bin_count){
	std::vector<int> bin;
	std::sort(data_set.begin(),data_set.end());

	/* set interval*/
	double interval=(max()-min())/bin_count;

	/*(Re-) Initialization*/
	double pos=min();
	bin_count=0;
	bin.push_back(0);

	/* Storing values in bins*/
	for(auto it=data_set.begin();it!=data_set.end();++it){
		if(*it<=pos+interval){
			bin[bin_count]++;
		}
		else{
			pos+=interval;
			bin_count++;
			bin.push_back(1);
		}
	}
	return bin;
}

void Histogram::print(unsigned int bin_count){
	std::vector<int> hist=initialize(bin_count);
	output(hist);
}

void Histogram::print_normalized(unsigned int bin_count){
	std::vector<int> hist=initialize(bin_count);
	output_normal(hist);
}

void Histogram::output(std::vector<int> &bin){
	output_normal(bin);
}

void Histogram::output_normal(std::vector<int> &bin){
	double pos=min();
	double interval=(max()-min())/bin.size();

	std::cout<<std::setprecision(2)<<std::fixed<<"Histogram of "<<size()<<" entries, min = "<<min()<<", max = "<<max()<<std::endl;
	for(auto it=bin.begin();it!=bin.end();++it){
		std::cout<<std::setfill(' ')<<std::setprecision(2)<<std::fixed<<std::setw(GetNumberOfDigits(max())+4)<<pos;
		pos+=interval;
		double value=*it;
		int bar=(int)(100*(value/data_set.size()));
		std::cout	<<" -- "<<std::setfill(' ')<<std::setprecision(2)<<std::fixed<<std::setw(GetNumberOfDigits(max())+4)
					<<std::internal<<pos<<": "
					<<std::setfill('*')<<std::setw(bar)<<""<<std::setfill(' ')<<std::setw(100-bar)<<"0."
					<<std::setprecision(3)<<(int)((value/data_set.size())*10)<<std::setw(GetNumberOfDigits(data_set.size()))
					<<std::setprecision(2)<<std::fixed<<"("<<value<<")"<<std::endl;
	}
}

unsigned Histogram::GetNumberOfDigits(unsigned i){
	return i > 0 ? (int) log10 ((double) i) + 1 : 1;
}

int main(){
	Histogram test=Histogram();
	auto vec=normal_distribution(random_seed(),36512,25.0, 500.0);
	for(auto it:vec){
		test.insert(it);
	}
	test.print(5);
	std::cout<<std::endl;
	test.print_normalized(5);

}

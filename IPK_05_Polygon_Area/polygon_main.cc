/*
 * polygon_main.cc
 *
 *  Created on: Dec 3, 2017
 *      Author: nuar
 */
#include <iostream>
#include <vector>
#include <cmath>

struct Point{
	double x;
	double y;
};
struct Polygon{
	std::vector<std::pair<Point,Point>> tupel;
};
Polygon construct(const std::vector<double>& x, const std::vector<double>& y){
	Point point[x.size()];
	Polygon polygon;
	for(unsigned int i=0;i<x.size();i++){
		point[i]={x[i],y[i]};
	}
	for(unsigned int i=0;i<x.size();i++){
		if(i==x.size()-1){
			polygon.tupel.push_back(std::make_pair(point[i],point[0]));
		}
		else{
			polygon.tupel.push_back(std::make_pair(point[i],point[i+1]));
		}
	}
	return polygon;
}
double volume(const Polygon& polygon){
	if (polygon.tupel.size()<3){
		return 0.0;
	}
	/*
	 * If all the points are the same, or have the same y, or if there a max. of 2 different y's --> zero edges
	 */
	std::vector<double> countUnique;
	countUnique.push_back(polygon.tupel[0].first.y);

	for(unsigned int i=1;i<polygon.tupel.size();i++){
		for(unsigned int j=0;j<polygon.tupel.size();i++){
			if(countUnique[j]!=polygon.tupel[i].first.y){
				countUnique.push_back(polygon.tupel[i].first.y);
			}
			if(countUnique.size()>1) break;
		}

	}
	if (countUnique.size()<=1){
		return 0.0;
	}
	//using formula
	double volume=0;
	for(unsigned int i=0;i<polygon.tupel.size();i++){
		volume+=	(polygon.tupel[i].first.x * polygon.tupel[i].second.y)
				+	(polygon.tupel[i].second.x * polygon.tupel[i].first.y);
	}
	volume=volume*0.5;

	return volume;
}

int main(){
	std::vector<double> a;
	std::vector<double> b;
	const double pi=M_PI;
	Polygon test;

	for(int n=1	;n<=10;n++){
		for(int i=0;i<100;i++){
			a.push_back(std::cos((i/n)*2*pi));
			b.push_back(std::sin((i/n)*2*pi));
		}
		test=construct(a,b);
		std::cout<<"Volume of n="<<n<<": "<<volume(test)<<std::endl;
	}
	//Polygon test=construct(a,b);
	/*
	for(int i=0;i< test.tupel.size();i++){
		std::cout<<"First x: "<<test.tupel[i].first.x<<" y: "<<test.tupel[i].first.y<<"    Second x: "<<test.tupel[i].second.x<<" y: "<<test.tupel[i].second.y<<std::endl;
	}*/

	return 0;
}

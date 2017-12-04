/*
 * main.cpp
 *
 *  Created on: Nov 16, 2017
 *      Author: nuar
 */


#include <vector>
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Point.h"

std::vector<Point> read_problem();
void determineNodes(std::vector<Point>& points);
std::vector<Point> sortNodes(std::vector<Point>& points);
std::vector<Point> smoothEdges(std::vector<Point>& points);


int main(){
	Point a=Point();
	Point b=Point(0.1,0.3);
	Point c;
	//std::cin>>c;
	//std::cout<<c<<" X: "<<c.getX()<<" Y: "<<c.getY();
	std::vector<Point> points =read_problem();
	determineNodes(points);
	return 0;
}


std::vector<Point> read_problem(){
	std::ifstream list("convex-hull-points.txt");
	std::streambuf *cinbuf = std::cin.rdbuf();
	std::cin.rdbuf(list.rdbuf()); //redirect cin to .txt!

	unsigned int numberOfPoints;
	std::cin>>numberOfPoints;
	std::cout<<numberOfPoints<<" Points:"<<std::endl;

	Point point;
	std::vector<Point>	points;
	for (unsigned int i=0;i<numberOfPoints;i++){
		std::cin>>point;
		points.push_back(point);
		std::cout<<i<<". "<<point<<std::endl;
	}
	 std::cin.rdbuf(cinbuf);   //reset to standard input
	return points;
}
/*
 * Konturpolygon:
 */
void determineNodes(std::vector<Point>& points){
	//works with operator < defined on attribute x of Point, this sorts all Points according to their x-value
	std::sort(points.begin(),points.end());
	std::vector<Point> relevantPoints;

	//traverse right and find list of max points
	Point referenceMax=points.at(0);

	relevantPoints.push_back(referenceMax);

	for(unsigned int i=1;i<points.size();i++){
		if(points.at(i).getY()>referenceMax.getY()){
			relevantPoints.push_back(points.at(i));
			referenceMax=points.at(i);
		}
	}

	//traverse left and find list of min points
	Point referenceMin=points.back();

	relevantPoints.push_back(referenceMin);
	for(unsigned int i=points.size()-1;i>0;i--){
		if(points.at(i).getY()<referenceMin.getY()){
			relevantPoints.push_back(points.at(i));
			referenceMin=points.at(i);
		}
	}
	relevantPoints=smoothEdges(relevantPoints);
}

/*
 * Smooth edges--> only include Points which are outer boundaries.
 */
std::vector<Point> smoothEdges(std::vector<Point>& points){
	Point max=Point();
	Point min=Point();

	unsigned int turn;
	for(unsigned int i=0;i<points.size();i++){
		if(points.at(i).getY()>=max.getY()){
			max=points.at(i);
		}
		if(i>0){
			if(points.at(i-1).getY() >points.at(i).getY()){
				turn=i;
				break;
			}
		}
	}
	std::cout<<std::endl;
	std::cout<<"Y- max is:"<<max.getY()<<std::endl;
	for(unsigned int i=0;i<points.size();i++){
		if(points.at(i).getY()<=min.getY()){
			min=points.at(i);
		}
	}
	//Erase all Elements on the vector that are encapsuled by other Nodes
	// That is achieved by looking at the slope of the nodes towards the ordinate
	//From starting to highest Point:
	//Point(y)/Point(x) < Startingpoint(y)/StartingPoint(x)
	//Last Point on the x-Axis is always within the volume.
	//Once you reverse the x-Axis:
	//Point(y)/Point(x) > Endingpoint(y)/EndingPoint(x)
	double slope;
	double edgeStartToMax=	(max.getY()-points.at(0).getY())/(max.getX()-points.at(0).getX());

	std::vector<Point> convexPoint;
	convexPoint.push_back(points.at(0));


	for(std::vector<Point>::iterator it=points.begin();it!=points.end();++it){
		if(it->getX()<=max.getX()){
			slope=	(it->getY()-points.at(0).getY())/(it->getX()-points.at(0).getX());
			if(slope>=edgeStartToMax){
				convexPoint.push_back(*it);
			}
		}
		else{
			break;
		}
	}
	double edgeMinToTurn= (points.at(turn).getY()-min.getY())/(points.at(turn).getX()-min.getX());
	convexPoint.push_back(points.at(turn));
	std::cout<<"Compare Slope:"<<edgeMinToTurn<<std::endl;
	for(unsigned int i=turn+1;i<points.size();i++){
		slope=	(points.at(i).getY()-points.at(0).getY())/(points.at(i).getX()-points.at(0).getX());
		std::cout<<slope<<std::endl;
		if(slope<edgeMinToTurn){
			convexPoint.push_back(points.at(i));
		}
	}


	int i=0;
	for (std::vector<Point>::iterator it=convexPoint.begin();it!=convexPoint.end();++it){
		std::cout<<"("<<i<<") "<<it->getX()<<" "<<it->getY()<<" "<<std::endl;
		i++;
	}
	return points;
}
std::vector<Point> sortNodes(std::vector<Point>& points){
	std::sort(points.begin(),points.end());
	std::vector<Point> convexHullOrder;

	//We start at the first Element of the x-axis
	Point previous=points.at(0);
	convexHullOrder.push_back(previous);
	//Then we proceed with x_n+1>x_n with y_n+1>y_n
	unsigned int iterator=0;
	for(unsigned int i=1; i<points.size();i++){
		if(points.at(i).getY()>previous.getY()){
			convexHullOrder.push_back(points.at(i));
			previous=points.at(i);
			iterator=i;
		}
	}
	//x_n+1>x_n with y_n+1<y_n but y_n+1>y_end
	for(unsigned int i=iterator+1;i<points.size();i++){
		if(points.at(i).getY()<previous.getY() && points.at(i).getY()>=points.back().getY()){
			convexHullOrder.push_back(points.at(i));
			previous=points.at(i);
		}
	}
	//Once we arrived at max x: we proceed with x_n+1<x_n, y_n+1<y_n
	for (unsigned int i=points.size()-1;i>0;i--){
		if(points.at(i).getY()<previous.getY()){
			convexHullOrder.push_back(points.at(i));
			previous=points.at(i);
		}
	}
	return convexHullOrder;
}



/*
 * juliaSet.cc
 *
 *  Created on: Jan 3, 2018
 *      Author: nuar
 */

#include "juliaSet.hh"

Julia_Set::Julia_Set():Complex_Poly() {
	// TODO Auto-generated constructor stub

}

Julia_Set::~Julia_Set() {
	// TODO Auto-generated destructor stub
}
std::unique_ptr<Point> Julia_Set::recurance(Point& z, Point& c){
	z=Point(pow(z.x(),2)-pow(z.y(),2)+c.x(),2*z.x()*z.y()+c.y());
	return std::make_unique<Point>(z);
}

void Julia_Set::draw(Point c,Canvas& canvas, double threshold, int maxIt, std::string filename, bool smooth){
	std::cout<<"Drawing Julia_Set, please wait..."<<std::endl;
	IterationResult result=IterationResult();

	for(int i=0;i<canvas.horPixels();i++){
		for(int j=0;j<canvas.vertPixels();j++){
			result=iterate(canvas.coord(i,j),c,threshold,maxIt);
			if(result.iterations()>0 && result.iterations()<maxIt){
				if(smooth&& i!=0 && j!=0){
					double k=result.iterations()-log2(log(sqrt(pow(result.lastTrack().x(),2)+
							(result.lastTrack().y(),2)))/log(threshold));
					canvas(i,j)= k;
				}
				else canvas(i,j)=log10(result.iterations())*100;
			}
		}
	}
	canvas.write(filename);
	std::cout<<"Done."<<std::endl;
}

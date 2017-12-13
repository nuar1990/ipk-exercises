/*
 * plot.cc
 *
 *  Created on: Dec 8, 2017
 *      Author: nuar
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <iostream>
#include <iomanip>
#include "point.hh"
#include "canvas.hh"
#include "mypng.hh"

int main(){
	double width=4.0;
	double height=3.0;
	int horPixels=20;
	int vertPixels=30;
	Point center=Point(width/2,height/2);
	Canvas canv=Canvas(center,width,height,horPixels,vertPixels);

	MyPNG test=MyPNG();
	FILE* f;

	canv.write(f);
	char hello[]="demo.png";
	test.read_png_file(hello);
	test.process_png_file();
	char hello2[]="demoA.png";
	test.write_png_file(hello2);
	/*
	for(int j=0;j<vertPixels;j++){
		for(int i=0;i<horPixels;i++){
			//canv.pixel(i,j)<<" ";
		}
		std::cout<<std::endl;
	}
	*/
	//canv.write("test.pgm");

	return 0;
}



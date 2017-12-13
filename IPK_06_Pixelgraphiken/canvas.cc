/*
 * canvas.cc
 *
 *  Created on: Dec 8, 2017
 *      Author: nuar
 */

#include "canvas.hh"
#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "mypng.hh"


Canvas::Canvas(const Point& _center,double _width, double _height,int _horPixels,int _vertPixels)
:center(_center),width(_width),height(_height),horPixels(_horPixels),vertPixels(_vertPixels),min(0),max(0){
	this->grayScale= std::vector<std::vector<double>>(horPixels,std::vector<double>(vertPixels));
	this->setGrayScale();
}

Canvas::~Canvas() {}

Point Canvas::coord(int i,int j)const{

	double x=width*((double)i/horPixels);
	double y=height*((double)j/vertPixels);

	Point coordinate=Point(x,y);
	return coordinate;
}

/*
 * protected function to determine intern double values for the grayScale interpolation.
 * function will be called on constructor call & for every change to Canvas members.
 */
void Canvas::setGrayScale(){
	for(int x=0;x<this->horPixels;x++){
		for(int y=0;y<this->vertPixels;y++){
			this->grayScale[x][y]=getGrayScale(this->coord(x,y)._x(),this->coord(x,y)._y());
			//std::cout<<"i:"<<coord(x,y)._x()<<" j:"<<coord(x,y)._y()<<"  f(x,y):"<<this->grayScale[x][y]<<std::endl;
			this->max=std::max(this->max,this->grayScale[x][y]);
			this->min=std::min(this->min,this->grayScale[x][y]);
		}
	}
}
double Canvas::getGrayScale(double x,double y){
	return std::max(0.0,sin(pow(x,-1))*sin(pow(y,-1)));
}

void Canvas::write(FILE* fp){
	png_structp png_ptr = NULL;
	png_infop info_ptr = NULL;
	size_t x, y;
	png_bytepp row_pointers;

	png_ptr = png_create_write_struct(PNG_LIBPNG_VER_STRING, NULL, NULL, NULL);
	if (png_ptr == NULL) {
		return ;
	}
    info_ptr = png_create_info_struct(png_ptr);
    if (info_ptr == NULL) {
        png_destroy_write_struct(&png_ptr, NULL);
        return ;
    }

    if (setjmp(png_jmpbuf(png_ptr))) {
    	png_destroy_write_struct(&png_ptr, &info_ptr);
	    return ;
	}

	png_set_IHDR(png_ptr, info_ptr,
	             horPixels, vertPixels, // width and height
	             16, // bit depth
	             PNG_COLOR_TYPE_GRAY, // color type
	             PNG_INTERLACE_NONE, PNG_COMPRESSION_TYPE_DEFAULT, PNG_FILTER_TYPE_DEFAULT);

	    /* Initialize rows of PNG. */
	    row_pointers = (png_bytep*)png_malloc(png_ptr,vertPixels *png_sizeof(png_bytep));

	    for (int i=0; i<vertPixels; i++)
	       row_pointers[i]=NULL;

	    for (int i=0; i<vertPixels; i++)
	    	row_pointers[i]=(png_bytep)png_malloc(png_ptr, vertPixels*2);

	    //set row data
	    for (y = 0; y < vertPixels; ++y) {
	        png_bytep row = row_pointers[y];
	        for (x = 0; x < horPixels; ++x) {
	                short color =(short) pixel(x,y);
	                *row++ = (png_byte)(color >> 8);
	                *row++ = (png_byte)(color & 0xFF);
	                std::cout<<"We are here "<<row++<<std::endl;
	        }
	    }
	    std::cout<<"We are here"<<std::endl;

	    /* Actually write the image data. */
	    png_init_io(png_ptr, fp);
	    png_set_rows(png_ptr, info_ptr, row_pointers);
	    png_write_png(png_ptr, info_ptr, PNG_TRANSFORM_IDENTITY, NULL);
	    png_write_image(png_ptr, row_pointers);
	    std::cout<<"We are here"<<std::endl;

	    /* Cleanup. */
	    for (y = 0; y < vertPixels; y++) {
	        png_free(png_ptr, row_pointers[y]);
	    }
	    png_free(png_ptr, row_pointers);
	    png_destroy_write_struct(&png_ptr, &info_ptr);
}

void Canvas::import(const std::string& filename){
	//this->grayScale=read_pgm(filename);
}
/*
 * To interpolate this function requires a fully filled two dimensional double array
 * After the creation of such, it will determine a sufficient variation to determine a good spread.
 *
 */
int Canvas::pixel(int i,int j){
	if(this->grayScale[i][j]==min) return 0;
	if(this->grayScale[i][j]==max) return 255;
	//linear interp.

	double linPol=(int)255+(0-255)/(0-max)*(grayScale[i][j]-max);
	return (int) linPol;
}

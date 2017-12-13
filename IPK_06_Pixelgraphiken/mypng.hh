/*
 * png.hh
 *
 *  Created on: Dec 10, 2017
 *      Author: nuar
 */

#ifndef MYPNG_HH_
#define MYPNG_HH_
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <png.h>
#include "canvas.hh"

class MyPNG{
private:
	png_bytep *row_pointers;
	int width, height;
	png_byte bit_depth;
	png_byte color_type;

public:
	MyPNG();
	//MyPNG(png_bytep* _row_pointers, int _width, int _height, png_byte _bit_depth, png_byte _color_type );
	virtual ~MyPNG();
	void read_png_file(char* file_name);
	void write_png_file(char* file_name);
	void process_png_file();
};

#endif /* MYPNG_HH_ */

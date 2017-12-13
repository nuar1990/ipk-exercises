/*
 * canvas.hh
 *
 *  Created on: Dec 8, 2017
 *      Author: nuar
 */

#ifndef CANVAS_HH_
#define CANVAS_HH_
#include <vector>
#include "point.hh"
#include <string>

#include "mypng.hh"

class Canvas {
private:
	const Point center;
	const double width,height;
	const int	horPixels,vertPixels;
	std::vector<std::vector<double>> grayScale;
	double min,max;
protected:
	void setGrayScale();
public:
	Canvas(const Point& _center,const double _width, const double _height,const int _horPixels,const int _vertPixels);
	Point coord(int i, int j)const;
	virtual ~Canvas();
	void write(FILE* fp);
	void import(const std::string& filename);
	double getGrayScale(double x, double y);
	int pixel(int i, int j);

};

#endif /* CANVAS_HH_ */

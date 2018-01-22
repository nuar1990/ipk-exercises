/*
 * mandelbrot.hh
 *
 *  Created on: Dec 26, 2017
 *      Author: nuar
 */

#ifndef MANDELBROT_HH_
#define MANDELBROT_HH_

#include "iterationResult.hh"
#include "complex_poly.hh"
class Mandelbrot: public Complex_Poly {
public:
	Mandelbrot();
	virtual ~Mandelbrot();
	std::unique_ptr<Point> recurance(Point& z, Point& c);
	void draw(Canvas& canvas , double threshold, int maxIt, std::string filename, bool smooth=false);
};

#endif /* MANDELBROT_HH_ */

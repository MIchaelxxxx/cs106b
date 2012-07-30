#include <iostream>
#include <cmath>
#include "graphics.h"
#include "gtypes.h"
#include "simpio.h"
#include "random.h"

using namespace std;

/* Function prototypes */
GPoint drawFractalLine(GPoint pt, double len, double theta, int order);


/* Main program */
int main() { 
	initGraphics(); 
	cout << "Program to draw a fractal coastline" << endl;
	
//	double size = getReal("Enter edge length in pixels: ");
//	int order = getInteger("Enter order of fractal: ");

	double size = 100;
	int order = 5;
	
	double cx = getWindowWidth() / 2;
	double cy = getWindowHeight() / 2;
//	GPoint pt(cx - size / 2, cy - sqrt(3.0) * size / 6);
//	pt = drawFractalLine(pt, size, 0, order);
//	pt = drawFractalLine(pt, size, -120, order);
//	pt = drawFractalLine(pt, size, +120, order);
	
	GPoint p(0, cy);
	p = drawFractalLine(p, size, 0, order);
	p = drawFractalLine(p, size, 45, order);
	p = drawFractalLine(p, size, -45, order);
	p = drawFractalLine(p, size, 0, order);
	p = drawFractalLine(p, size, -22.5, order);
	p = drawFractalLine(p, size, 22.5, order);
	p = drawFractalLine(p, size, -45, order);
	p = drawFractalLine(p, size, 45, order);
	
	return 0;
}



GPoint drawFractalLine(GPoint pt, double len, double theta, int order) { 
	int x = theta >= 0 ? 60 : -60;
	
	if (order == 0) {
		return drawPolarLine(pt, len, theta);
	} else {
		pt = drawFractalLine(pt, len / 3, theta, order - 1); 
		
		pt = drawFractalLine(pt, len / 3, theta + x, order - 1); 
		pt = drawFractalLine(pt, len / 3, theta - x, order - 1); 
		return drawFractalLine(pt, len / 3, theta, order - 1);
	}
}
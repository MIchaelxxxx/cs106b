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

	double size = 130;
	int order = 7;
	
	double cx = getWindowWidth() / 2;
	double cy = getWindowHeight() / 2;
	
	GPoint p(cx, cy*2);
	
	drawFractalLine(p, size, 90, order);
	
	return 0;
}



GPoint drawFractalLine(GPoint pt, double len, double theta, int order) { 	
	float m = 0.6;
	if (order == 0) {
		GPoint p = drawPolarLine(pt, len, theta);
		drawPolarLine(p, len * m, theta + 45);
		drawPolarLine(p, len * m, theta - 45);
		return p;
	} else {
		GPoint p = drawFractalLine(pt, len, theta, order - 1); 
		drawFractalLine(p, len * m, theta + 45, order - 1);
		drawFractalLine(p, len * m, theta - 45, order - 1);
		return p;
	}
}
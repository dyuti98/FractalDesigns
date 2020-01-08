#include "CircleSierpinski.h"

void createFractal(int xc, int yc, int r)
{
	CircleDraw(xc, yc, r);
	if (r > 5)
	{
		createFractal(xc + r / 2, yc, r / 2);
		createFractal(xc - r / 2, yc, r / 2);
		createFractal(xc, yc + r / 2, r / 2);
	}
}

void setupCircleSierpinski(){
	int r = HEIGHT < WIDTH ? (HEIGHT / 2) : (WIDTH / 2);
	int xc = (WIDTH / 2);
	int yc = (HEIGHT / 2);
	createFractal(xc, yc, r);
}

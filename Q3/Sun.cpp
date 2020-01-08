#include "Sun.h"

void cantorSun(int xc, int yc, int r) {
	CircleDraw(xc,yc,r);
	if (r >=1) {
		cantorSun(xc, yc, r/2);
		cantorSun(xc , yc, r/3);
		cantorSun(xc, yc, r/4);
	}
}

void drawSun(int x, int y, int r){
	int xc = x;
	int yc = y;
	cantorSun(xc, yc, r);
	CircleDraw(xc,yc,1.375*r);
	CircleDraw(xc,yc,1.5*r);
	CircleDraw(xc,yc,1.125*r);
	CircleDraw(xc,yc,1.25*r);
	CircleDraw(xc,yc,r);
	cantorSun(xc, yc, r/2);
	cantorSun(xc+(r/2), yc, r);
	cantorSun(xc-(r/2), yc, r);
	cantorSun(xc, yc+(r/2), r);
	cantorSun(xc, yc-(r/2), r);
}
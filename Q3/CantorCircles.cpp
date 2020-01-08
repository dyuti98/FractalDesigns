#include "CantorCircles.h"

void setupCantorCircles(){
	int r = HEIGHT < WIDTH ? (HEIGHT/4) : (WIDTH/4);
	int xc = (WIDTH/2);
	int yc = (HEIGHT/2);
	//cantor(xc, yc, r);
	CircleDraw(xc-(r/2), yc, r*1.5);
	CircleDraw(xc+(r/2), yc, r*1.5);
	cantor(xc+(r/2), yc, r*1.5);
	cantor(xc-(r/2), yc, r*1.5);
	cantor(xc, yc-(r/2), r*1.5);
	cantor(xc, yc+(r/2), r*1.5);
	cantor(xc+(r/2), yc, r);
	cantor(xc-(r/2), yc, r);
	cantor(xc, yc+(r/2), r);
	cantor(xc, yc-(r/2), r);
}

void cantor(int xc, int yc, int r){
	if (r >=1) {
	CircleDraw(xc, yc, r);
		cantor(xc+r, yc, r/3);
		cantor(xc , yc-(r*2/3), r/3);
		cantor(xc-r, yc, r/3);
		cantor(xc , yc+(r*2/3), r/3);		
		

	}
}
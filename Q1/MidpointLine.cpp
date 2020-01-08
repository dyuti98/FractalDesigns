#include "variables.h"
#include "MidpointLine.h"

int abs(int x)
{
 	if(x>=0)
 		return x;
 	else
 		return -x;
}

int sign(int x)
{
	if(x>0)
 		return 1;
 	else if(x==0)
 		return 0;
	else
		return -1;
}

void AddPixel(int x, int y)
{
	vertexPositions.push_back(x);
	vertexPositions.push_back(y);
	vertexPositions.push_back(0.0);
}

void MidpointLineDraw(int xi, int yi, int xf, int yf)
{
	int x=xi;
	int y=yi;
	int dx = abs(xf-xi);
	int dy = abs(yf-yi);
	int s1 = sign(xf-xi);
	int s2 = sign(yf-yi);

	int interchange = 0;

	if(dy>dx)
	{
		int t = dx;
		dx=dy;
		dy=t;
		interchange=1;
	}
	else
	{
		interchange=0;
	}

	int d = 2*dy-dx;
	int incrE = 2*dy;
	int incrNE = 2*(dy-dx);

	AddPixel(x,y);

	for(int i=1;i<=dx;i++)
	{
		if(d<0)
		{
			d+=incrE;
			if(interchange==0)
				x += s1;
			else
				y += s2;
		}
		else
		{
			d += incrNE;
		 	x += s1;
		 	y += s2;
		}
		AddPixel(x,y);
	}

}
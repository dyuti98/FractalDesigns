#include "Ikeda.h"

void setupIkeda()
{
	float xn = 0;
	float yn = 0;
	float u = 0.7;
	int count = 500;
	int steps = 200;

	int scale = 150;

	AddPixel(xn,yn);

	for(int j=0;j<steps;j++){

		u+=0.0015;

		for(double i = 0;i<count;i++){
			float tn = 0.4 - (6/(1+(xn*xn)+(yn*yn)));
			float xn1 = 1 + u*(xn*glm::cos(tn) - yn*glm::sin(tn));
			float yn1 = u*(xn*glm::sin(tn) + yn*glm::cos(tn));
			AddPixel(scale*xn1-150+(WIDTH/2),scale*yn1+100+(HEIGHT/2));
			xn = xn1;
			yn = yn1;
		}

	}

}
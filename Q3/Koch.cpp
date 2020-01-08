#include "Koch.h"

int rCount = 0;

void setupKoch()
{
	rCount = 0;
	int xa = 200+200;
	int ya = 200;
	int xb = 650+200;
	int yb = 200;
	int xc = 425+200;
	int yc = 590;

	lineSetup(xa,ya,xb,yb);
	lineSetup(xb,yb,xc,yc);
	lineSetup(xc,yc,xa,ya);

	buildKoch();
}

void lineSetup(float xi,float yi,float xf,float yf)
{
	glm::vec3 begin = glm::vec3(xi,yi,1);
	glm::vec3 end = glm::vec3(xf,yf,1);
	
	line l;
	l.begin = begin;
	l.end = end;
	lines.push_back(l);
}

void buildKoch()
{
	createKoch();
	drawKoch();
}

void createKoch(){

	if(rCount<5){

		for(int i=lines.size()-1;i>=0;i--){
			line l = lines[i];
			int xi = l.begin.x;
			int yi = l.begin.y;
			int xf = l.end.x;
			int yf = l.end.y;
			//float angle = b.angle;
			int xa = xi + (xf-xi)/3;
			int ya = yi + (yf-yi)/3;
			int xc = xi + (2*(xf-xi))/3;
			int yc = yi + (2*(yf-yi))/3;

			glm::vec3 a = glm::vec3(xi,yi,1);
			glm::vec3 b = glm::vec3(xa,ya,1);
			glm::vec3 d = glm::vec3(xc,yc,1);
			glm::vec3 e = glm::vec3(xf,yf,1);

			glm::vec3 c = translate(b.x,b.y)*rotate(60)*translate(-b.x,-b.y)*d;

			line A,B,C,D;
			A.begin = a;
			A.end = b;
			B.begin = b;
			B.end = c;
			C.begin = c;
			C.end = d;
			D.begin = d;
			D.end = e;
			lines.erase(lines.begin()+i);
			lines.push_back(A);
			lines.push_back(B);
			lines.push_back(C);
			lines.push_back(D);		
		}
		rCount++;
		createKoch();
	}

}

void drawKoch(){
	for(int i=lines.size()-1;i>=0;i--){
		line l = lines[i];
			MidpointLineDraw(l.begin.x,l.begin.y,l.end.x,l.end.y);
	}

};
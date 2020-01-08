#include "Tree.h"

int count = 0;

void treeSetup(float x, float y, float len)
{
	glm::vec3 begin;
	begin = translate(x,y)*glm::vec3(0,0,1);
	glm::vec3 end = translate(0,len)*begin;
	
	branch b;
	b.begin = begin;
	b.end = end;
	b.angle = 0;
	b.len = len;
	b.drawn = false;
	branches.push_back(b);
}

void drawBranches(){
	for(int i=branches.size()-1;i>=0;i--){
		branch b = branches[i];
		MidpointLineDraw(b.begin.x,b.begin.y,b.end.x,b.end.y);
	}

	//drawPoints();

};

void buildTree()
{
	createBranches();
	drawBranches();
}

void createBranches(){

	while(count < 8)
	{
		for(int i=branches.size()-1;i>=0;i--){
			branch b = branches[i];
			if(b.drawn == true)
				continue;
			branchLeft(b);
			branchRight(b);
			b.drawn = true;
		}
		count++;
	}

}

void branchLeft(branch b)
{
	branch left;
	left.begin = b.end;
	float times = (rand()%90);
	if(times<50)
		times=50;
	if(times>67)
		times=67;
	left.len = ((b.len)*times/100);
	left.angle = b.angle+30;
	left.drawn = false;
	left.end = translate(b.end.x,b.end.y)*rotate(b.angle+30)*translate(-b.end.x,-b.end.y)*translate(0,left.len)*b.end;
	branches.push_back(left);
}

void branchRight(branch b){
	branch right;
	right.begin = b.end;
	float times = (rand()%90);
	if(times<50)
		times=50;
	if(times>67)
		times=67;
	right.len = ((b.len)*times/100);
	right.angle = b.angle-30;
	right.drawn = false;	
	right.end = translate(b.end.x,b.end.y)*rotate(b.angle-30)*translate(-b.end.x,-b.end.y)*translate(0,right.len)*b.end;
	branches.push_back(right);
}

void drawTree(){
	count = 0;
	int trees = 13;

	srand(time(0));

	for(int i=1;i<trees;i++){
		int treeY = rand()%(landHeight-20);
		if(treeY<40)
			treeY = 40;
		int treeHeight = rand()%100;
		if(treeHeight<60)
			treeHeight=60;
		treeSetup((i*WIDTH)/trees,treeY,treeHeight);
	}
	buildTree();
}


void drawLand(){

	srand(time(0));
	int sign = 1;
	int inc = 10;

	int xi = 0, yi= landHeight;
	int xf = xi;
	int yf = yi;
	while(xi<WIDTH){
		int dis = rand()%5;
		xf = xi + inc;
		yf = yi + (sign*dis);
		MidpointLineDraw(xi,yi,xf,yf);
		sign *= -1;
		xi = xf;
		yi=yf;
	}
}
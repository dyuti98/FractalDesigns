#include "DragonCurve.h"

std::string current;
char states[] = {'u', 'r', 'd', 'l'};
int stateIndex;

void nextGeneration()
{
	std::string next = "";
	for (int i = 0; i < current.length(); i++)
	{
		if (current[i] == 'X')
		{
			next.append("X+YF+");
		}
		else if (current[i] == 'Y')
		{
			next.append("-FX-Y");
		}
		else
		{
			next.append(1, current[i]);
		}
	}
	current = next;
}

void drawDragon()
{
	int xi = WIDTH / 4, yi = 3 * HEIGHT / 4;
	int xf = xi, yf = yi;
	int lineLen = 7;
	for (int i = 0; i < current.length(); i++)
	{
		char c = current[i];
		if (c == '+')
		{ 
			stateIndex++;
			if (stateIndex == 4)
				stateIndex = 0;
		}
		else if (c == '-')
		{
			stateIndex--;
			if (stateIndex == -1)
				stateIndex = 3;
		}
		else if (c == 'F')
		{
			char currState = states[stateIndex];
			if (currState == 'u')
			{
				yf = yi + lineLen;
			}
			else if (currState == 'r')
			{
				xf = xi + lineLen;
			}
			else if (currState == 'd')
			{
				yf = yi - lineLen;
			}
			else if (currState == 'l')
			{
				xf = xi - lineLen;
			}
			MidpointLineDraw(xi+200, yi+20, xf+200, yf+20);
			xi = xf;
			yi = yf;
		}
	}
}

void setupDragon(){
	
	stateIndex=0;
	current = "FX";

	for (int i = 0; i < 12; i++)
		{
			nextGeneration();
		}
		drawDragon();
}
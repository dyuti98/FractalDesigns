#include <vector>
#include <stdio.h>
using namespace std;
#include "variables.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include<cstdlib>
#include<ctime>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Transform.h"
#include "MidpointLine.h"

const int landHeight = 125;

void treeSetup(float x, float y, float len);
void drawBranches();
void buildTree();
void createBranches();
void branchLeft(branch b);
void branchRight(branch b);
void drawTree();
void drawLand();
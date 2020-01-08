#include <stdio.h>
#include <vector>
using namespace std;

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shaders.h"
#include "Transform.h"
#include "Ikeda.h"
#include "Tree.h"
#include "Sun.h"
#include "Koch.h"
#include "DragonCurve.h"
#include "CantorCircles.h"
#include "CircleSierpinski.h"

//Windows Dimensions
const GLint WIDTH = 1152, HEIGHT = 670;
GLuint VAO, VBO, programID;
GLuint projectionviewPos;
glm::mat4 projection;
std::vector<GLfloat> vertexPositions;
vector<line> lines;
vector<branch> branches;

void drawPoints();
void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods);
void printHelp();

int main(void)
{

	//Initailize GLFW
	if (!glfwInit())
	{
		printf("GLFW initialization failed. Exiting..\n");
		glfwTerminate();
		return 1;
	}

	//Setup GLFW Windows Properties
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//No backward compatibilty
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Forward Compatibilty
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);

	//Create a window
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Koch Snowflake", NULL, NULL);
	if (!mainWindow)
	{
		printf("Window Not Created. Exiting..\n");
		glfwTerminate();
		return 1;
	}

	glfwSetKeyCallback(mainWindow, keyCallBack);

	glfwSetWindowSizeLimits(mainWindow, WIDTH,HEIGHT,WIDTH,HEIGHT);

	//Get Buffer Size Info
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//Set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	//Allow Modern Features
	glewExperimental = GL_TRUE;

	//Initialize GLEW
	if (glewInit() != GLEW_OK)
	{
		printf("GLEW initialization failed. Exiting..\n");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
		return 1;
	}

	//Setup Viewport
	glViewport(0, 0, bufferWidth, bufferHeight);

	//Compile Shaders and link it to the current program(programID)
	programID = compileShaders();

	printHelp();

	while (!glfwWindowShouldClose(mainWindow))
	{

		//Get and Handle User Events 
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

			setupOrtho();

			glBindVertexArray(VAO);

				glDrawArrays(GL_POINTS,0,vertexPositions.size());

				glEnable(GL_PROGRAM_POINT_SIZE);

			glBindVertexArray(0);

		glUseProgram(0);

		glfwSwapBuffers(mainWindow);
	}

	return 0;

}

void drawPoints()
{

	glGenVertexArrays(1, &VAO);
	glBindVertexArray(VAO);

	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER,vertexPositions.size()*sizeof(GLfloat),&vertexPositions[0],GL_STATIC_DRAW);

	glVertexAttribPointer(0,3,GL_FLOAT,GL_FALSE,0,0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER,0);

	glBindVertexArray(0);

}

void keyCallBack(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if(action == GLFW_PRESS){
		vertexPositions.clear();
		lines.clear();
		branches.clear();
		switch(key){
			case GLFW_KEY_1:
				drawLand();
				drawTree();
				drawSun(1000,540,60);
				drawPoints();
				break;
			case GLFW_KEY_2:
				setupKoch();
				drawPoints();
				break;
			case GLFW_KEY_3:
				setupCantorCircles();
				drawPoints();
				break;
			case GLFW_KEY_4:
				setupIkeda();
				drawPoints();
				break;
			case GLFW_KEY_5:
				setupDragon();
				drawPoints();
				break;
			case GLFW_KEY_6:
				setupCircleSierpinski();
				drawPoints();
				break;
		}
	}
}

void printHelp(){
	printf("Press 1: Child's Fractals\n");
	printf("Press 2: Koch Snowflake\n");
	printf("Press 3: Cantor Circles\n");
	printf("Press 4: Ikeda Map\n");
	printf("Press 5: Dragon Curve\n");
	printf("Press 6: Sierpinski Triangle from circles\n");
}
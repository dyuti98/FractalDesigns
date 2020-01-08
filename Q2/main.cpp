#include <stdio.h>
#include <vector>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Shaders.h"
#include "variables.h"
#include "MidpointCircle.h"

#include<cstdlib>
#include<ctime>

//Windows Dimensions
const GLint WIDTH = 640, HEIGHT = 480;

GLuint VAO, VBO, programID;

GLuint projectionviewPos;
glm::mat4 projection;

std::vector<GLfloat> vertexPositions;

void setupRandCircle();
void drawPoints();

int main(void)
{

	//Initailize GLFW
	if (!glfwInit())
	{
		printf("GLFW initia lization failed. Exiting..\n");
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
	GLFWwindow *mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Main Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("Window Not Created. Exiting..\n");
		glfwTerminate();
		return 1;
	}

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

	while (!glfwWindowShouldClose(mainWindow))
	{

		//Get and Handle User Events 
		glfwPollEvents();

		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		glUseProgram(programID);

			glm::mat4 projection = glm::ortho(0.0f, (GLfloat)WIDTH, 0.0f, (GLfloat)HEIGHT, -1.0f, 1.0f);
			glUniformMatrix4fv(glGetUniformLocation(programID, "projection"), 1, GL_FALSE, &projection[0][0]);
			
			setupRandCircle();

			glBindVertexArray(VAO);

				glDrawArrays(GL_POINTS,0,vertexPositions.size());

				glEnable(GL_PROGRAM_POINT_SIZE);

			glBindVertexArray(0);

			vertexPositions.clear();

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

void setupRandCircle()
{
	srand(time(0));
	int r = HEIGHT < WIDTH ? rand() % (HEIGHT / 4) : rand() % (WIDTH / 4);
	int xc = WIDTH / 4 + rand() % (WIDTH / 2);
	int yc = HEIGHT / 4 + rand() % (HEIGHT / 2);
	CircleDraw(xc, yc, r);
	drawPoints();;
}
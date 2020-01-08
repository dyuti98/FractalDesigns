#include "Transform.h"

void setupOrtho(){
	glm::mat4 projection = glm::ortho(0.0f, (GLfloat)WIDTH, 0.0f, (GLfloat)HEIGHT, -1.0f, 1.0f);
	glUniformMatrix4fv(glGetUniformLocation(programID, "projection"), 1, GL_FALSE, &projection[0][0]);
}

glm::mat3 translate(const float &tx, const float &ty) 
{
  glm::mat3 trans = glm::mat3(1,0,0,0,1,0,tx,ty,1);
  return trans;
}

glm::mat3 rotate(const float degrees) 
{
  // YOUR CODE FOR HW2 HERE
  float PI = glm::pi<float>();
  float cosdeg = glm::cos(degrees * PI/180.0);
  float sindeg = glm::sin(degrees * PI/180.0);
  glm::mat3 rot = glm::mat3(cosdeg,-sindeg,0,sindeg,cosdeg,0,0,0,1);
  return rot;
}
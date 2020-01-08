#include <vector>
using namespace std;
#include "variables.h"

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

glm::mat3 rotate(const float degrees);
glm::mat3 translate(const float &tx, const float &ty);
void setupOrtho();
#ifndef OBJLOADER_H_INCLUDED
#define OBJLOADER_H_INCLUDED

#include <string>
#include <vector>
#include "glm.hpp"
#include "glew.h"

struct vertexStruct
{
	GLfloat position[3];
	GLfloat normals[3];
	GLfloat uv[2];
};

bool loadOBJ(const std::string & path, std::vector<vertexStruct> & verticies);


#endif

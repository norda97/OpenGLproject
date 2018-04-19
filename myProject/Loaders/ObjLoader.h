#ifndef OBJLOADER_H
#define OBJLOADER_H

#include "../Graphics/Model/Material.h"
#include "../Graphics/Model/Model.h"
#include <map>
#include <string>
#include <vector>

#include "glm.hpp"
#include "glew.h"



Model * loadOBJ(const std::string & path);
void sortVerticies(std::vector<glm::vec3> * temp_vertices, std::vector<glm::vec3>* temp_normals, std::vector<glm::vec2>* temp_uvs, std::vector< unsigned int >* vertexIndices);
std::map<std::string, Material> loadMaterial(const std::string & path);


#endif

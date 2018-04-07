#include "CubeMap.h"

#include <iostream>


#include "glew.h"
#include "..\..\Utils\stb_image.h"

#define NO_TEXTURE_FOUND 0

const unsigned & loadCubeMap(const std::vector<std::string> & paths)
{
	if (paths.size() == 0)
		return NO_TEXTURE_FOUND;

	unsigned textureID = 0;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_CUBE_MAP, textureID);

	int width, height, nrChannels;
	unsigned char *data = nullptr;

	for (int i = 0; i < paths.size(); i++)
	{
		data = stbi_load(paths[i].c_str(), &width, &height, &nrChannels, 0);
		if (!data)
		{
			std::cout << "Cubemap texture to load at path: " << paths[i] << std::endl;
			return NO_TEXTURE_FOUND;
		}

		glTexImage2D(GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, data);
		stbi_image_free(data);

		data = nullptr;
	}
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);

	glBindTexture(GL_TEXTURE_CUBE_MAP, 0);

	return textureID;
}

#include "Texture.h"

//########## Initilize STBI ###############
#define STB_IMAGE_IMPLEMENTATION
#include "../../Utils/stb_image.h"
#include <iostream>

Texture::Texture(const std::string & path, const bool & useMIPMAP)
	:	data(nullptr),
		width(0),
		height(0),
		nrChannels(0)
{
	glGenTextures(1, &this->textureID);
	glBindTexture(GL_TEXTURE_2D, this->textureID);

	data = stbi_load(("Resources/" + path).c_str(), &width, &height, &nrChannels, 0);
	if (data)
	{
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		
		if (useMIPMAP)
		{
			glGenerateMipmap(GL_TEXTURE_2D);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		}
	}
	else
		std::cout << "ERROR: " << path << " could not be found!" << std::endl;
}


Texture::~Texture()
{
	stbi_image_free(data);
}

void Texture::loadTexture(const unsigned & target)
{	
	glActiveTexture(GL_TEXTURE0 + target);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
	glUniform1i(this->textureID, target);
}

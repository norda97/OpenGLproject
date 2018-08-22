#include "Texture.h"

//########## Initilize STBI ###############
#define STB_IMAGE_IMPLEMENTATION
#include "../../Utils/stb_image.h"
#include <iostream>
#include "..\..\Core\Display.h"

Texture::Texture(const std::string & path, const bool & useMIPMAP)
	:	data(nullptr),
		usedSTBI(false)
{
	this->width = this->height = this->nrChannels = 0;

	glGenTextures(1, &this->textureID);
	this->setTexture(path, useMIPMAP);
	
}

Texture & Texture::operator=(const Texture & other)
{
	if (this != &other)
	{
		if (usedSTBI)
		{
			stbi_image_free(data);
		}

		this->width = other.width;
		this->height = other.height;
		this->nrChannels = other.nrChannels;
		this->data = other.data;
		this->usedSTBI = other.usedSTBI;
		this->textureID = other.textureID;
	}

	return *this;
}


Texture::~Texture()
{
	if(usedSTBI)
		stbi_image_free(data);

	glDeleteTextures(1, &this->textureID);
}

const unsigned & Texture::getTextureID()
{
	return this->textureID;
}

void Texture::setTexture(const std::string & path, const bool & useMIPMAP)
{
	glBindTexture(GL_TEXTURE_2D, this->textureID);

	if (path != "empty")
	{
		data = stbi_load(("Resources/Textures/" + path).c_str(), &width, &height, &nrChannels, 0);
		
		if (data)
		{
			this->usedSTBI = true;
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
	else
	{
		this->width = Display::getInstance().getWidth();
		this->height = Display::getInstance().getHeight();
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height,
			0, GL_RGB, GL_UNSIGNED_BYTE, NULL);

		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	}

	glBindTexture(GL_TEXTURE_2D, 0);
}

void Texture::loadTexture(const unsigned & target) const
{	
	glActiveTexture(GL_TEXTURE0 + target);
	glBindTexture(GL_TEXTURE_2D, this->textureID);
}

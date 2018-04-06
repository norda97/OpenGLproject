#ifndef TEXTURE_H
#define TEXTURE_H

#include "glew.h"

#include <vector>
#include <string>


class Texture
{
public:
	Texture(const std::string & path, const bool & useMIPMAP);
	~Texture();

	void loadTexture(const unsigned & target);

private:
	int width, height, nrChannels;
	unsigned textureID;

	unsigned char *data;
};

#endif

#ifndef TEXTURE_H
#define TEXTURE_H

#include "glew.h"

#include <vector>
#include <string>



class Texture
{
public:
	Texture(const std::string & path = "defaultTex.png", const bool & useMIPMAP = false);
	Texture& operator=(const Texture& other);

	~Texture();
	const unsigned& getTextureID();
	void setTexture(const std::string & path, const bool & useMIPMAP = false);
	void loadTexture(const unsigned & target) const;
private:
	int width, height, nrChannels;
	unsigned textureID;
	bool usedSTBI;

	unsigned char *data;
};

#endif

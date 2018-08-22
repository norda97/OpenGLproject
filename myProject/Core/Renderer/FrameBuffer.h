#ifndef FRAMEBUFFER_H
#define FRAMEBUFFER_H

#include "..\..\Graphics\Textures\Texture.h"
#include "glm.hpp"


class FrameBuffer
{
public:
	enum Attachments { Color, Depth, DepthRBO };

	FrameBuffer(std::vector<Attachments> attachments = std::vector<Attachments>{ Color, DepthRBO });
	~FrameBuffer();

	void bind() const;
	// texNum must be lower than textures size
	Texture* getTexture(const unsigned& texNum);
private:
	GLuint fbo;
	GLuint rbo;
	std::vector<Texture> textures;
};

#endif
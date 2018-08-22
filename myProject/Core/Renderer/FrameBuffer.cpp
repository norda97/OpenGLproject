#include "FrameBuffer.h"
#include "..\Display.h"



FrameBuffer::FrameBuffer(std::vector<Attachments> attachments)
{
	glGenFramebuffers(1, &fbo);
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);

	unsigned colorAttachIterator = 0;
	for (unsigned i = 0; i < attachments.size(); i++)
	{
		if (attachments[i] == Attachments::Color)
		{
			Texture temp("empty");
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0 + colorAttachIterator++, GL_TEXTURE_2D, temp.getTextureID(), 0);
			textures.push_back(temp);

		}
		else if (attachments[i] == Attachments::DepthRBO)
		{
			glGenRenderbuffers(1, &rbo);
			glBindRenderbuffer(GL_RENDERBUFFER, rbo);
			glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, Display::getInstance().getWidth(), Display::getInstance().getHeight());			glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, rbo);			glBindRenderbuffer(GL_RENDERBUFFER, 0);
		}
		else
		{
			Texture temp("empty");
			glFramebufferTexture2D(GL_FRAMEBUFFER, GL_DEPTH_COMPONENT, GL_TEXTURE_2D, temp.getTextureID(), 0);
			textures.push_back(temp);
		}
	}

	if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)		printf("Failed to create FrameBuffer");
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
}

FrameBuffer::~FrameBuffer()
{
	glDeleteFramebuffers(1, &fbo);
	glDeleteRenderbuffers(1, &rbo);
}

void FrameBuffer::bind() const
{
	glBindFramebuffer(GL_FRAMEBUFFER, fbo);
	glClearColor(0.1f, 0.1f, 0.1f, 1.0f);	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
}

Texture* FrameBuffer::getTexture(const unsigned & texNum) 
{
	if (texNum < this->textures.size())
		return &this->textures[texNum];

	return nullptr;
}


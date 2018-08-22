#include "ParticleRenderer.h"

ParticleRenderer::ParticleRenderer()
{
	this->loadVao(DATA_LENGTH);
	this->addInstancedAttribute(1, 4, DATA_LENGTH, 0);
	this->addInstancedAttribute(2, 4, DATA_LENGTH, 4);
	this->addInstancedAttribute(3, 4, DATA_LENGTH, 8);
	this->addInstancedAttribute(4, 4, DATA_LENGTH, 12);
}


ParticleRenderer::~ParticleRenderer()
{
}

void ParticleRenderer::render(const std::vector<ParticleEmitter*>& emitters, const Camera & cam)
{



	this->floatBuffer.clear();
}

void ParticleRenderer::loadVao(int floatCount)
{
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);

	glGenBuffers(1, &vbo[0]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[0]);
	glBufferData(GL_ARRAY_BUFFER, 8 * sizeof(float), (void*)0, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 2, GL_FLOAT, false, 0, (void*)0);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	//Model View Matrix
	glGenBuffers(1, &vbo[1]);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, floatCount * sizeof(float), (void*)0,GL_STREAM_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);

	glBindVertexArray(0);

}

void ParticleRenderer::addInstancedAttribute(int attribute, int dataSize, int instancedData, int offset)
{
	glBindVertexArray(this->vao);
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);

	glVertexAttribPointer(attribute, dataSize, GL_FLOAT, false, instancedData * sizeof(float), (void*)(offset * 4));
	glVertexAttribDivisor(attribute, 1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);
}

void ParticleRenderer::prepare()
{
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glEnableVertexAttribArray(2);
	glEnableVertexAttribArray(3);
	glEnableVertexAttribArray(4);
}

void ParticleRenderer::finishRendering()
{
	glDisableVertexAttribArray(0);
	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(2);
	glDisableVertexAttribArray(3);
	glDisableVertexAttribArray(4);
}

void ParticleRenderer::updateModelViewMatrix(const glm::vec3 & position, float rotation, float scale)
{
}

void ParticleRenderer::updateVbo()
{
	glBindBuffer(GL_ARRAY_BUFFER, vbo[1]);
	glBufferData(GL_ARRAY_BUFFER, floatBuffer.size() * sizeof(float), (void*)0, GL_STREAM_DRAW);
	glBufferSubData(GL_ARRAY_BUFFER, 0, this->floatBuffer.size() * sizeof(float), &floatBuffer[0]);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}


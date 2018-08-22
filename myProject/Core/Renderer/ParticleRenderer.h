#ifndef PARTICLERENDERER_H
#define PARTICLERENDERER_H

#include <vector>

#include "glew.h"
#include "glm.hpp"

//forward declartions
class ParticleEmitter;
class Camera;

#define MAX_PARTICLES 10000
#define DATA_LENGTH 16

//quad for particles
float verticies[8] = { -0.5, 0.5, -0.5, -0.5, 0.5, 0.5, 0.5, -0.5 };

class ParticleRenderer
{
public:
	ParticleRenderer();
	~ParticleRenderer();


	void render(const std::vector<ParticleEmitter*>& emitters, const Camera& cam);
private:
	void loadVao(int floatCount);
	void addInstancedAttribute(int attribute, int dataSize, int instancedData, int offset);

	void prepare();
	void finishRendering();

	void updateModelViewMatrix(const glm::vec3& position, float rotation, float scale);
	void updateVbo();

	GLuint vao, vbo[2];
	std::vector<float> floatBuffer;
};

#endif
#ifndef PARTICLE_H
#define PARTICLE_H

#include "glm.hpp"

class Particle
{
public:
	Particle(const glm::vec3& position = {0.0f, 0.0f, 0.0f}, const glm::vec3& color = { 1.0f, 0.0f, 0.0f }, const glm::vec3& velocity = { 0.0f, 1.0f, 0.0f },
		const float& life = 3, const float& rotation = 0.0f, const float& scale = 1.0f, const float& gravity = -1.0f);
	~Particle();

	const glm::vec3& getPosition();
	const float& getRotation();
	const float& getScale();

	bool update(const float& dt);

private:
	glm::vec3 position, color, velocity;
	float life, elapsedTime, rotation, scale, gravity;
};

#endif
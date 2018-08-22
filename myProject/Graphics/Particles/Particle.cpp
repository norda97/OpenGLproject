#include "Particle.h"

Particle::Particle(const glm::vec3 & position, const glm::vec3 & color, const glm::vec3 & velocity, const float & life, const float & rotation, const float & scale, const float & gravity)
{
}

Particle::~Particle()
{
}

const glm::vec3 & Particle::getPosition()
{
	return this->position;
}

const float & Particle::getRotation()
{
	return this->rotation;
}

const float & Particle::getScale()
{
	return this->scale;
}

bool Particle::update(const float& dt)
{
	this->velocity.y += this->gravity * dt;
	this->position += this->velocity * dt;
	this->elapsedTime += dt;

	return this->elapsedTime < this->life;
}

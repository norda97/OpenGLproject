#include "ParticleEmitter.h"





ParticleEmitter::ParticleEmitter(const glm::vec3 & position, unsigned ParticlesPerSecond)
{
	this->position = position;
	this->particlesPerSec = ParticlesPerSecond;
}

ParticleEmitter::~ParticleEmitter()
{
}

void ParticleEmitter::setPosition(const glm::vec3 & position)
{
	this->position = position;
}

const glm::vec3 & ParticleEmitter::getPosition()
{
	return this->position;
}

void ParticleEmitter::setVelocity(const glm::vec3 & velocity)
{
	this->velocity = velocity;
}

void ParticleEmitter::setColor(const glm::vec3 & color)
{
	this->color = color;
}

void ParticleEmitter::setLife(const float & life)
{
	this->life = life;
}

void ParticleEmitter::setRotation(const float & rotation)
{
	this->rotation = rotation;
}

void ParticleEmitter::setScale(const float & scale)
{
	this->scale = scale;
}

void ParticleEmitter::setGravity(const float & gravity)
{
	this->gravity = gravity;
}

void ParticleEmitter::update(float dt)
{
	for (int i = 0; i < particles.size(); i++)
		this->particles[i].update(dt);
}

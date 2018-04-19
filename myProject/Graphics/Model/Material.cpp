#include "Material.h"



Material::Material()
{
}


Material::~Material()
{
}

void Material::setKa(const glm::vec3 & Ka)
{
	this->Ka = Ka;
}

void Material::setKd(const glm::vec3 & Kd)
{
	this->Kd = Kd;
}

void Material::setKs(const glm::vec3 & Ks)
{
	this->Ks = Ks;
}

void Material::setNs(const float & Ns)
{
	this->Ns = Ns;
}

void Material::setD(const float & d)
{
	this->d = d;
}

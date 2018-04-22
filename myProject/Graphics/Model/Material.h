#ifndef MATERIAL_H
#define MATERIAL_H

#include "glm.hpp"

class Material
{
public:
	Material();
	~Material();

	void setKa(const glm::vec3 & Ka);
	void setKd(const glm::vec3 & Kd);
	void setKs(const glm::vec3 & Ks);
	void setNs(const float & Ns);
	void setD(const float & d);


private:
	glm::vec3 Ka;
	float Ns;
	glm::vec3 Kd;
	float d;
	glm::vec3 Ks;
};

#endif
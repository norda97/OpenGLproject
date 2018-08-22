#ifndef CAMERA_H
#define CAMERA_H

#include "../../Core/Settings.h"

#include "glm.hpp"

class Camera
{
public:
	Camera(const glm::vec3 & position = glm::vec3(0.0f, 0.0f, -10.0f), const bool & ortho = false);
	~Camera();

	void input(const double & dt);
	void update(const double& dt);

	const glm::mat4 & getView() const;
	const glm::mat4 & getProj() const;
	const glm::vec3 & getPosition() const;

	void updateProj(const float& fovy, const float& near, const float& far);

private:
	void updateView();
	const glm::vec3& calculateDirection(const float & yaw, const float & pitch, const float & roll);

	bool lockCamera;
	bool isOrtho;

	double xPos, yPos, lastX, lastY;
	float yaw, pitch;

	glm::mat4 viewMatrix, projMatrix;
	glm::vec3 forward, position;

	float cameraSpeed;
};


#endif
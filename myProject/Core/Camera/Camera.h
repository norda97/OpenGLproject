#ifndef CAMERA_H
#define CAMERA_H

#include "../../Core/Settings.h"

#include "glm.hpp"
#include "../Display.h"
#include "../../Shaders/Shader.h"

class Camera
{
public:
	Camera(const glm::vec3 & position = glm::vec3(0.0f, 0.0f, -10.0f));
	~Camera();

	void input(Display * display);
	void update(const double& dt);

	const glm::mat4 & getView();
	const glm::mat4 & getProj();

private:
	void updateView();
	const glm::vec3& calculateDirection(const float & yaw, const float & pitch, const float & roll);

	bool lockCamera;

	double xPos, yPos, lastX, lastY;
	float yaw, pitch;

	glm::mat4 viewMatrix, projMatrix;
	glm::vec3 forward, position;

	float cameraSpeed;
};


#endif
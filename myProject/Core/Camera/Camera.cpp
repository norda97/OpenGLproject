#include "Camera.h"

#include "gtc\matrix_transform.hpp"
#include <iostream>
Camera::Camera(const glm::vec3 & position)
{
	this->position = position;
	this->forward = glm::vec3(0.0f, 0.0f, 1.0f);
	this->projMatrix = glm::perspective(glm::radians(45.0f), (float)640 / (float)480, 0.1f, 100.0f);
	this->updateView();

	lockCamera = true;
}

Camera::~Camera()
{
}

void Camera::input(Display * display)
{
	if (glfwGetKey(display->getWindow(), GLFW_KEY_C) == GLFW_PRESS)
	{
		lockCamera = !lockCamera; 
	}

	if (lockCamera)
	{
		glfwSetInputMode(display->getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		glfwGetCursorPos(display->getWindow(), &xPos, &yPos);

		xPos -= (double)display->getWidth() / 2;
		yPos -= (double)display->getHeight() / 2;

		float sensitivity = 0.1;
		this->yaw -= (float)(xPos*sensitivity);
		this->pitch -= (float)(yPos*sensitivity);

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		glm::vec3 front;
		front.z = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		front.y = sin(glm::radians(pitch));
		front.x = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		this->forward = glm::normalize(front);
		display->centerMouse();
	}

	float cameraSpeed = 0.25f; // adjust accordingly
	if (glfwGetKey(display->getWindow(), GLFW_KEY_W) == GLFW_PRESS)
		this->position += cameraSpeed * this->forward;
	if (glfwGetKey(display->getWindow(), GLFW_KEY_S) == GLFW_PRESS)
		this->position -= cameraSpeed * this->forward;
	if (glfwGetKey(display->getWindow(), GLFW_KEY_A) == GLFW_PRESS)
		this->position -= glm::normalize(glm::cross(this->forward, GLOBAL_UP)) * cameraSpeed;
	if (glfwGetKey(display->getWindow(), GLFW_KEY_D) == GLFW_PRESS)
		this->position += glm::normalize(glm::cross(this->forward, GLOBAL_UP)) * cameraSpeed;

	this->updateView();

}

void Camera::update(const double & dt)
{
	this->cameraSpeed = 2.5f * (float)dt;
}

const glm::mat4 & Camera::getView() const
{
	return this->viewMatrix;
}

const glm::mat4 & Camera::getProj() const
{
	return this->projMatrix;
}

void Camera::updateView()
{
	this->viewMatrix = glm::lookAt(this->position, this->position + this->forward, GLOBAL_UP);
}


const glm::vec3 & Camera::calculateDirection(const float & yaw, const float & pitch, const float & roll)
{
	glm::vec3 direction(1.0f);

	direction.x = cos(glm::radians(pitch)) * cos(glm::radians(yaw));
	direction.y = sin(glm::radians(pitch));
	direction.z = cos(glm::radians(pitch)) * sin(glm::radians(yaw));

	return direction;
}



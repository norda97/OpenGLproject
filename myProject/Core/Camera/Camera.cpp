#include "Camera.h"

#include "gtc\matrix_transform.hpp"
#include <iostream>
#include "../Display.h"

Camera::Camera(const glm::vec3 & position, const bool & ortho)
{
	this->lockCamera = true;
	this->isOrtho = ortho;

	this->position = position;
	this->forward = glm::vec3(0.0f, 0.0f, -1.0f);
	this->updateProj(glm::radians(45.0f), 0.1f, 100.0f);
	this->updateView();	
}

Camera::~Camera()
{
}

void Camera::input(const double & dt)
{
	glfwSetInputMode(Display::getInstance().getWindow(), GLFW_STICKY_KEYS, 1);

	static int oldPressedC = GLFW_RELEASE;
	int newPressedC = glfwGetKey(Display::getInstance().getWindow(), GLFW_KEY_C);
	if (newPressedC == GLFW_RELEASE && oldPressedC == GLFW_PRESS)
	{
		lockCamera = !lockCamera; 
	}
	oldPressedC = newPressedC;

	if (lockCamera)
	{
		glfwSetInputMode(Display::getInstance().getWindow(), GLFW_CURSOR, GLFW_CURSOR_HIDDEN);

		glfwGetCursorPos(Display::getInstance().getWindow(), &xPos, &yPos);

		xPos -= (double)Display::getInstance().getWidth() / 2;
		yPos -= (double)Display::getInstance().getHeight() / 2;

		float sensitivity = 0.1f;
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
		Display::getInstance().centerMouse();
	}

	float cameraSpeed = 0.25f; // adjust accordingly
	if (glfwGetKey(Display::getInstance().getWindow(), GLFW_KEY_W) == GLFW_PRESS)
		this->position += cameraSpeed * this->forward;
	if (glfwGetKey(Display::getInstance().getWindow(), GLFW_KEY_S) == GLFW_PRESS)
		this->position -= cameraSpeed * this->forward;
	if (glfwGetKey(Display::getInstance().getWindow(), GLFW_KEY_A) == GLFW_PRESS)
		this->position -= glm::normalize(glm::cross(this->forward, GLOBAL_UP)) * cameraSpeed;
	if (glfwGetKey(Display::getInstance().getWindow(), GLFW_KEY_D) == GLFW_PRESS)
		this->position += glm::normalize(glm::cross(this->forward, GLOBAL_UP)) * cameraSpeed;

	this->updateView();

	static int oldPressedO = GLFW_RELEASE;
	int newPressedO = glfwGetKey(Display::getInstance().getWindow(), GLFW_KEY_O);
	if (newPressedO == GLFW_RELEASE && oldPressedO == GLFW_PRESS)
	{
		this->isOrtho = !this->isOrtho;
		this->updateProj(glm::radians(45.0f), 0.1f, 100.0f);
	}
	oldPressedO = newPressedO;
	
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

const glm::vec3 & Camera::getPosition() const
{
	return this->position;
}

void Camera::updateProj(const float& fovy, const float& near, const float& far)
{
	
	if (this->isOrtho)
		this->projMatrix = glm::ortho(-5.0f, 5.0f, -5.0f, 5.0f, near, far);
	else
	{
		int width = Display::getInstance().getWidth();
		int height = Display::getInstance().getHeight();
		this->projMatrix = glm::perspective(fovy, width / (float)height, near, far);
	}
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



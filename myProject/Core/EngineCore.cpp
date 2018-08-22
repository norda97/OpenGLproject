#include "EngineCore.h"
#include <iostream>

#include "Display.h"

EngineCore::EngineCore()
	:	mGUI(&entityManager),
		skyBox(std::vector<std::string>
			{
			"./Resources/skybox/right.jpg",
			"./Resources/skybox/left.jpg",
			"./Resources/skybox/top.jpg",
			"./Resources/skybox/bottom.jpg",
			"./Resources/skybox/front.jpg",
			"./Resources/skybox/back.jpg"
			}
			)
{
	timeCounter = fps = 0;
}


EngineCore::~EngineCore()
{
	
}

void EngineCore::init()
{
	this->mGUI.setCamera(&cam);

	this->entityManager.addModel("./Resources/Mesh/Bunny/bunny.obj", "bunny");
	this->entityManager.addEntity("Bunny", "bunny");
	this->entityManager.getEntity("Bunny")->setPosition(glm::vec3(5.0f, 2.0f, 0.0f));

	renderer.setShader(Renderer::Shaders::phong, this->entityManager.getEntities());
	
	glfwSwapInterval(0);  // Turns off vSync
	double t, oldt(0), dt(0);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(Display::getInstance().getWindow()) && !glfwGetKey(Display::getInstance().getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		// ############## Delta timer #################
		t = glfwGetTime();
		dt = t - oldt;
		oldt = t;
		// ############################################

		this->input(dt);
		this->update(dt);
		this->render();

	}

	this->clean();
}

void EngineCore::update(const double& dt)
{
	this->cam.update(dt);
}

void EngineCore::render()
{
	/* Render here */
	glClearColor(0.0, 0.0, 0.0, 1.0);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	// Render to screen
	this->skyBox.render(this->cam);
	this->renderer.render(Renderer::Shaders::phong, this->entityManager.getEntities(), cam);
	
	//render GUI
	this->mGUI.render();

	/* Swap front and back buffers */
	glfwSwapBuffers(Display::getInstance().getWindow());

	/* Poll for and process events */
	glfwPollEvents();
}

void EngineCore::input(const double & dt)
{
	this->cam.input(dt);
}

void EngineCore::clean()
{
}

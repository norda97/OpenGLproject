#include "EngineCore.h"
#include <iostream>


EngineCore::EngineCore()
	:	display(WINDOW_WIDTH, WINDOW_HEIGHT),
		test("scout.png"),
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
	double t, oldt(0), dt(0);
	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(display.getWindow()) && !glfwGetKey(display.getWindow(), GLFW_KEY_ESCAPE) == GLFW_PRESS)
	{
		// ############## Delta timer #################
		t = glfwGetTime();
		dt = t - oldt;
		oldt = t;
		// ############################################

		// ############## FPS counter in console #################
		this->timeCounter += dt;
		this->fps++;
		if (timeCounter >= 1)
		{
			std::cout << fps << std::endl;
			fps = timeCounter = 0;
		}
		// #######################################################

		this->input();
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
	glClearColor(0, 0, 0, 1);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	this->skyBox.render(this->cam);
	this->test.render(this->cam);

	/* Swap front and back buffers */
	glfwSwapBuffers(display.getWindow());

	/* Poll for and process events */
	glfwPollEvents();
}

void EngineCore::input()
{
	this->cam.input(&this->display);
}

void EngineCore::clean()
{
}

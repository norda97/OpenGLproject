#include "Display.h"

#include<iostream>

Display::Display(const unsigned& width, const unsigned& height)
{
	this->width = width;
	this->height = height;

	this->init();
}


Display::~Display()
{
	glfwTerminate();
}

void Display::init()
{
	glewExperimental = GL_TRUE;

	if (!glfwInit())
	{
		fprintf(stderr, "Failed to initialize GLFW!");
		exit(EXIT_FAILURE);
	}

	this->createWindow();

#ifdef __APPLE__
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // Make MacOS happy
#endif

	 // --------------- INIT GLEW ---------------
	glewExperimental = true; // Needed in core profile
	if (glewInit() != GLEW_OK)
	{
		fprintf(stderr, "Failed to initialize GLEW!");
		exit(EXIT_FAILURE);
	}

	/* Initialize the library */
	glEnable(GL_DEPTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);	
	

	this->centerMouse();
}

void Display::createWindow()
{
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	glfwWindowHint(GLFW_DEPTH_BITS, 32);
	
	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(this->width, this->height, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
	}

	glfwMakeContextCurrent(this->window);
}

GLFWwindow * Display::getWindow()
{
	return this->window;
}

unsigned Display::getWidth() const
{
	return this->width;
}

unsigned Display::getHeight() const
{
	return this->height;
}

void Display::centerMouse() const
{
	//Set cursor to center of window
	glfwSetCursorPos(this->window, (double)this->width / 2, (double)this->height / 2);
}

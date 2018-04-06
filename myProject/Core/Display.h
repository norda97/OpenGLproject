#ifndef DISPLAY_H
#define DISPLAY_H

#include <glew.h>
#include <glfw3.h>

class Display
{
public:
	Display(const unsigned& width, const unsigned& height);
	~Display();

	void init();
	void createWindow();

	GLFWwindow* getWindow();
	unsigned getWidth() const;
	unsigned getHeight() const;

	void centerMouse() const;
private:
	GLFWwindow* window;
	unsigned width;
	unsigned height;
};

#endif // !DISPLAY_H


#ifndef DISPLAY_H
#define DISPLAY_H

#include <glew.h>
#include <glfw3.h>

// SINGLETON class
class Display
{
public:
	

	void init();
	void createWindow();

	GLFWwindow* getWindow();
	unsigned getWidth() const;
	unsigned getHeight() const;

	unsigned setWidth() const;
	unsigned setHeight() const;

	void centerMouse() const;
private:
	GLFWwindow* window;
	unsigned width;
	unsigned height;

	Display();
	~Display();
	Display(Display const&);              // Don't Implement
	void operator=(Display const&);		// Don't Implement

public:
	static Display& getInstance()
	{
		static Display instance;	// Guaranteed to be destroyed.
									// Instantiated on first use.
		return instance;
	}

	/*Display(Display const&) = delete;
	void operator=(Display const&) = delete;*/
};

#endif



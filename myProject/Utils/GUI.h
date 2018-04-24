#ifndef GUI_H
#define GUI_H

#include "imgui\imgui.h"

class Display;
class EntityManager;

class GUI
{
public:
	GUI(Display * display, EntityManager * entities);
	~GUI();

	void render();

private:
	void ShowEntityMenuFile();

	bool show_demo_window;
	bool show_another_window;
	ImVec4 clear_color;
	EntityManager* mEntities;
};

#endif
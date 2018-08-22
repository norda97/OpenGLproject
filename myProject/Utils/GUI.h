#ifndef GUI_H
#define GUI_H

#include "imgui\imgui.h"
#include "..\Core\Camera\Camera.h"

class Display;
class EntityManager;

class GUI
{
public:
	GUI(EntityManager * entities);
	~GUI();

	void render();
	void setCamera(Camera* cam);

private:
	void ShowEntityMenuFile();
	Camera* cam;
	bool show_demo_window;
	bool show_another_window;
	ImVec4 clear_color;
	EntityManager* mEntities;
};

#endif
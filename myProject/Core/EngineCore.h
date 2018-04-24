#ifndef ENGINECORE_H
#define ENGINECORE_H


#include "Settings.h"
//Glew has to be included before display!!
#include "Display.h"

//Temporary includes
#include "..\Core\Entity\Entity.h"
#include "Camera\Camera.h"
#include "..\Graphics\Skybox\Skybox.h"
#include "..\Core\Entity\EntityManager.h"
#include "Renderer\Renderer.h"
#include "..\Utils\GUI.h"

class EngineCore
{
public:
	EngineCore();
	~EngineCore();

	void init();
	void update(const double& dt);
	void render();
	void input();
private:
	void clean();

	Display display;

	//##### For FPS counter ######
	unsigned fps;
	double timeCounter;
	//############################


	//Creating things
	GUI mGUI;
	Camera cam;
	Skybox skyBox;
	EntityManager entityManager;
	Renderer renderer;

};

#endif
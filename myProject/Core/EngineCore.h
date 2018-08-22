#ifndef ENGINECORE_H
#define ENGINECORE_H


#include "Settings.h"
//Glew has to be included before display!!


//Temporary includes
#include "..\Core\Entity\Entity.h"
#include "Camera\Camera.h"
#include "..\Graphics\Skybox\Skybox.h"
#include "..\Core\Entity\EntityManager.h"
#include "Renderer\Renderer.h"
#include "..\Utils\GUI.h"
#include "Renderer\FrameBuffer.h"

class EngineCore
{
public:
	EngineCore();
	~EngineCore();

	void init();
	void update(const double& dt);
	void input(const double & dt);
	void render();
private:
	void clean();

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
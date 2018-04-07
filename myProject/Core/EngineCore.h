#ifndef ENGINECORE_H
#define ENGINECORE_H


#include "Settings.h"
//Glew has to be included before display!!
#include "Display.h"

//Temporary includes
#include "..\Blocks\Block.h"
#include "Camera\Camera.h"
#include "..\Graphics\Skybox\Skybox.h"

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
	int fps;
	double timeCounter;
	//############################


	//Creating things
	Camera cam;
	Skybox skyBox;
	Block test;


};

#endif
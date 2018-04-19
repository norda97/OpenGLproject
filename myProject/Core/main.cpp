
#include <iostream>
#include "EngineCore.h"


int main()
{
	// Initilization
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	
	EngineCore core;

	core.init();

	return 0;
}
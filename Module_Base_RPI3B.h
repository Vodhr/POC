#pragma once
#include "BasicPOCModule.h"

class Module_Base_RPI3B : public BasicPOCModule
{
	Module_Base_RPI3B();
	void init();
	void selfTest();
	const uint16_t getId();
	const string getClassName();
};


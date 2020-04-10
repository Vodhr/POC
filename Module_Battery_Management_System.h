#pragma once
#include "BasicPOCModule.h"

class Module_Battery_Management_System :
	public BasicPOCModule {
public:
	Module_Battery_Management_System();
	void init() final;
	void selfTest() final;
	const uint16_t getId() final;
	const string getClassName() final;
};


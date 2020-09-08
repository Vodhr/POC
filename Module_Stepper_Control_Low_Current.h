#pragma once
#include "BasicPOCModule.h"

class Module_Stepper_Control_Low_Current : public BasicPOCModule {
	Module_Stepper_Control_Low_Current();
	const uint16_t getId() const;
	const string getClassName() const;
};


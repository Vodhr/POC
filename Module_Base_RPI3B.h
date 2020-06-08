#pragma once
#include "BasicPOCModule.h"
#include "PAC1720.h"

class Module_Base_RPI3B : public BasicPOCModule
{
private:
	PAC1720 pac;
public:
	Module_Base_RPI3B();
	void init();
	void selfTest();
	const uint16_t getId();
	const string getClassName();
	double getCurrentDrawHS();
	double getVoltageHS();
	double getPowerHS();
	double getCurrentDrawLS();
	double getVoltageLS();
	double getPowerLS();
};


#pragma once
#include "POCModuleComponent.h"
#include <list>
#include "I2CDevice.h"
#include "BasicPOCModule.h"

class PAC1720 :
	public POCModuleComponent, I2CDevice {
public:
	PAC1720(BasicPOCModule* itsPOCModule, list<POCModuleComponent*>& componentList);
	void init() final;
	void selfTest() final;
	unsigned int getCurrentDrawHS();
	unsigned int getVoltageHS();
	unsigned int getPowerHS();
	unsigned int getCurrentDrawLS();
	unsigned int getVoltageLS();
	unsigned int getPowerLS();
};


#pragma once
#include "BasicPOCModuleI2CComponent.h"
#include <list>
#include "I2CDevice.h"
#include "BasicPOCModule.h"

class PAC1720 :
	public BasicPOCModuleI2CComponent {
public:
	PAC1720(BasicPOCModule* itsPOCModule, list<BasicPOCModuleI2CComponent*>& componentList);
	void init() final;
	void selfTest() final;
	unsigned int getCurrentDrawHS();
	unsigned int getVoltageHS();
	unsigned int getPowerHS();
	unsigned int getCurrentDrawLS();
	unsigned int getVoltageLS();
	unsigned int getPowerLS();
};


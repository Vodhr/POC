#pragma once
#include "I2CComponent.h"
#include <list>
#include "BasicPOCModule.h"

class PAC1720 :
	public I2CComponent {
public:
	PAC1720(BasicPOCModule* itsPOCModule, list<Component*>& componentList);
	void init() final;
	void selfTest() final;
	unsigned int getCurrentDrawHS();
	unsigned int getVoltageHS();
	unsigned int getPowerHS();
	unsigned int getCurrentDrawLS();
	unsigned int getVoltageLS();
	unsigned int getPowerLS();
};


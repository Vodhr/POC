#pragma once
#include "SPIComponent.h"
class ADS114S08B : public SPIComponent {
public:
	ADS114S08B(BasicPOCModule* itsPOCModule, list<Component*>& componentList);
	unsigned char readRegister(unsigned char reg) final;
	void writeRegister(unsigned char reg, unsigned char data) final;
	int getConversionData();

	void init() final;
	void selfTest() final;
};

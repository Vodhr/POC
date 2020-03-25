#pragma once
#include "I2CDevice.h"
#include <string>

class PowerLogger : public I2CDevice {
public:
	PowerLogger(string name, short i2CAddress);
	void init() final;
	void selfTest() final;
};


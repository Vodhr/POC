#pragma once
#include "I2CDevice.h"
class BDLCMotorDriver :
	public I2CDevice
{
private:
	double position;
	double current;
public:
	void active();
	void deactive();
	void init() final;
	void selfTest() final;
};


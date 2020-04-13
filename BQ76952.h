#pragma once
#include "I2CDevice.h"
class BQ76952 :
	public I2CDevice {
	BQ76952();

	struct Status5 {
		//TODO
	};

	void init() final;
	void selfTest() final;

	Status5 getStatus5();
};


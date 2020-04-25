#pragma once
#include "I2CDevice.h"
#include "TimedState.h"

struct Status5 {
	//TODO

};

class BQ76952 :
	public I2CDevice {

	TimedState<Status5> STATUS5;

	BQ76952();

	void init() final;
	void selfTest() final;

	TimedState<Status5> getStatus5();
};


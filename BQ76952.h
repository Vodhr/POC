#pragma once
#include <memory>
#include "I2CDevice.h"
#include "TimedState.h"
#include "POCModuleComponent.h"

struct Status5 {
	//TODO

};

class BQ76952 :
	public I2CDevice, POCModuleComponent {

	TimedState<Status5> status5;
public:
	BQ76952(BasicPOCModule* itsPOCModule);

	void init() final;
	void selfTest() final;

	TimedState<Status5> getStatus5();
};


#pragma once
#include <memory>
#include <list>
#include "I2CDevice.h"
#include "TimedState.h"
#include "BasicPOCModuleI2CComponent.h"

struct Status5 {
	//TODO

};

class BQ76952 :
	public BasicPOCModuleI2CComponent {

	TimedState<Status5> status5;
public:
	BQ76952(BasicPOCModule* itsPOCModule, list<BasicPOCModuleI2CComponent*>& componentlist);

	void init() final;
	void selfTest() final;

	TimedState<Status5> getStatus5();
};


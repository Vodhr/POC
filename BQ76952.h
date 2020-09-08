#pragma once
#include <memory>
#include <list>
#include "TimedState.h"
#include "I2CComponent.h"

struct Status5 {
	//TODO

};

class BQ76952 :
	public I2CComponent {

	TimedState<Status5> status5;
public:
	BQ76952(BasicPOCModule* itsPOCModule, list<Component*>& componentlist);

	void init() final;
	void selfTest() final;

	TimedState<Status5> getStatus5();
};


#pragma once
#include "BasicPOCModule.h"
#include "TimedState.h"
#include <atomic>

class Module_Temperature_Measurement :
	public BasicPOCModule
{
private:
	 TimedState<double> t1, t2, t3, t4, t5, t6;

public:
	TimedState<double> getTemperature1() const;
	TimedState<double> getTemperature2() const;
	TimedState<double> getTemperature3() const;
	TimedState<double> getTemperature4() const;
	TimedState<double> getTemperature5() const;
	TimedState<double> getTemperature6() const;

	const uint16_t getId() const final;
	const string getClassName() const final;

};




///-------------------------------------------------------------------------------------------------
/// @file	POC\Module_Temperature_Measurement.h.
///
/// @brief	Declares the module temperature measurement class

#pragma once
#include "BasicPOCModule.h"
#include "RepeatedTask.h"
#include "TimedState.h"
#include <atomic>
#include <functional>
#include "ADS114S08B.h"

///-------------------------------------------------------------------------------------------------
/// @class	Module_Temperature_Measurement
///
/// @brief	A module temperature measurement.
///
/// @author	Benjamin
/// @date	28.09.2020
using namespace std;

class Module_Temperature_Measurement :
	public BasicPOCModule
{
private:
	POCController pocController;
	ADS114S08B adc;
	TimedState<double> t1, t2, t3, t4, t5, t6;
	void updateTemperatures();
	RepeatedTask temperatureTask;

public:
	Module_Temperature_Measurement();

	TimedState<double> getTemperature1() const;
	TimedState<double> getTemperature2() const;
	TimedState<double> getTemperature3() const;
	TimedState<double> getTemperature4() const;
	TimedState<double> getTemperature5() const;
	TimedState<double> getTemperature6() const;

	const uint16_t getId() const final;
	const string getClassName() const final;

	void init() final;
	void selfTest() final;

};




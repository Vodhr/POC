///-------------------------------------------------------------------------------------------------
/// @file	POC\Module_Temperature_Measurement.cpp.
///
/// @brief	Implements the module temperature measurement class

#include "Module_Temperature_Measurement.h"

Module_Temperature_Measurement::Module_Temperature_Measurement() : 
	pocController("Controller", 0x43, this, componentList),
	BasicPOCModule("Module Temperature Mesaurement", shared_ptr<POCController>(&pocController)),
	temperatureTask(bind(&Module_Temperature_Measurement::updateTemperatures, this)),
	adc(this, componentList)
{
	adc.init();
	temperatureTask.start();
}

void Module_Temperature_Measurement::updateTemperatures() {
	adc.getConversionData();
}

///-------------------------------------------------------------------------------------------------
/// @fn	TimedState<double> Module_Temperature_Measurement::getTemperature1() const
///
/// @brief	Gets temperature 1
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The temperature 1.

TimedState<double> Module_Temperature_Measurement::getTemperature1() const {
	return t1;
}

///-------------------------------------------------------------------------------------------------
/// @fn	TimedState<double> Module_Temperature_Measurement::getTemperature2() const
///
/// @brief	Gets temperature 2
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The temperature 2.

TimedState<double> Module_Temperature_Measurement::getTemperature2() const {
	return t2;
}

///-------------------------------------------------------------------------------------------------
/// @fn	TimedState<double> Module_Temperature_Measurement::getTemperature3() const
///
/// @brief	Gets temperature 3
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The temperature 3.

TimedState<double> Module_Temperature_Measurement::getTemperature3() const {
	return t3;
}

///-------------------------------------------------------------------------------------------------
/// @fn	TimedState<double> Module_Temperature_Measurement::getTemperature4() const
///
/// @brief	Gets temperature 4
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The temperature 4.

TimedState<double> Module_Temperature_Measurement::getTemperature4() const {
	return t4;
}

///-------------------------------------------------------------------------------------------------
/// @fn	TimedState<double> Module_Temperature_Measurement::getTemperature5() const
///
/// @brief	Gets temperature 5
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The temperature 5.

TimedState<double> Module_Temperature_Measurement::getTemperature5() const {
	return t5;
}

///-------------------------------------------------------------------------------------------------
/// @fn	TimedState<double> Module_Temperature_Measurement::getTemperature6() const
///
/// @brief	Gets temperature 6
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The temperature 6.

TimedState<double> Module_Temperature_Measurement::getTemperature6() const {
	return t6;
}

void Module_Temperature_Measurement::init() {
	//TODO
}

void Module_Temperature_Measurement::selfTest() {
	//TODO
}

const uint16_t Module_Temperature_Measurement::getId() const {
	return 0xFFFF;
}

const string Module_Temperature_Measurement::getClassName() const {
	return "Module_Temperature_Measurement";
}

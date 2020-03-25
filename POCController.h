#pragma once
#include "I2CDevice.h"
#include <string>
#include <iostream>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	POCController
///
/// @brief	A PoC modules controller
///
/// @author	Benjamin
/// @date	09.01.2020

class POCController : public I2CDevice {
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	POCController::POCController(string name, short slaveid);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	name   	The name of this controller.
	/// @param 	slaveid	The I2C slave id of this controller.

	POCController(string name, short slaveid);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void POCController::init() final;
	///
	/// @brief	Initializes this controller
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	void init() final;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void POCController::selfTest() final;
	///
	/// @brief	Executes a self test routine on this controller
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	void selfTest() final;
};


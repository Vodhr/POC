///-------------------------------------------------------------------------------------------------
/// @file	POC\POCController.h.
///
/// @brief	Declares the poc controller class

#pragma once
#include "ATtiny814.h"
#include <string>
#include <iostream>
#include <list>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	POCController
///
/// @brief	A PoC modules controller
///
/// @author	Benjamin
/// @date	09.01.2020

class POCController : public ATtiny814 {
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	POCController::POCController(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 		   	name		 	The name of this controller.
	/// @param 		   	slaveID		 	The I2C slave id of this controller.
	/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
	/// @param [in,out]	componentList	[in,out] If non-null, list of components.

	POCController(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList);

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

	///-------------------------------------------------------------------------------------------------
	/// @fn	void POCController::activateSPISlot(unsigned char slotNr);
	///
	/// @brief	Activates the spi slot described by slotNr
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	slotNr	The slot nr.

	void activateSPISlot(unsigned char slotNr);

	///-------------------------------------------------------------------------------------------------
	/// @fn	double POCController::getBoardTemperature();
	///
	/// @brief	Gets board temperature
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The board temperature.

	//double getBoardTemperature();

	///-------------------------------------------------------------------------------------------------
	/// @fn	double POCController::setBoardTargetTemperature();
	///
	/// @brief	Sets board target temperature
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	A double.

	//double setBoardTargetTemperature();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void POCController::activateBoardHeater();
	///
	/// @brief	Activates the board heater
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	//void activateBoardHeater();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void POCController::deactivateBoardHeater();
	///
	/// @brief	Deactivate board heater
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	//void deactivateBoardHeater();

	void transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx);
	unsigned char readRegister(unsigned char reg);
	void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);
	void writeRegister(unsigned char reg, unsigned char data);
	void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);
};


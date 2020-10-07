///-------------------------------------------------------------------------------------------------
/// @file	POC\ATtiny814.cpp.
///
/// @brief	Implements the ttiny 814 class

#include "ATtiny814.h"

///-------------------------------------------------------------------------------------------------
/// @fn	ATtiny814::ATtiny814(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 		   	name		 	The name.
/// @param 		   	slaveID		 	Identifier for the slave.
/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
/// @param [in,out]	componentList	[in,out] If non-null, list of components.

ATtiny814::ATtiny814(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList) :
	I2CComponent(name, slaveID, false, 100000, itsPOCModule, componentList) {

}
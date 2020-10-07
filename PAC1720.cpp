///-------------------------------------------------------------------------------------------------
/// @file	POC\PAC1720.cpp.
///
/// @brief	Implements the pac 1720 class

#include "PAC1720.h"

///-------------------------------------------------------------------------------------------------
/// @fn	PAC1720::PAC1720(BasicPOCModule* itsPOCModule, list<Component*>& componentList)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
/// @param [in,out]	componentList	[in,out] If non-null, list of components.

PAC1720::PAC1720(BasicPOCModule* itsPOCModule, list<Component*>& componentList) : 
	I2CComponent("PAC1720", 0x29, false, 100000, itsPOCModule, componentList) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	void PAC1720::init()
///
/// @brief	Initializes this object
///
/// @author	Benjamin
/// @date	28.09.2020

void PAC1720::init() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void PAC1720::selfTest()
///
/// @brief	Tests self
///
/// @author	Benjamin
/// @date	28.09.2020

void PAC1720::selfTest() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int PAC1720::getCurrentDrawHS()
///
/// @brief	Gets current draw hs
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The current draw hs.

unsigned int PAC1720::getCurrentDrawHS() {
	//TODO
	return ((readRegister(0x0D) & (0xEF)) << 4) | (readRegister(0x0E) >> 4);
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int PAC1720::getVoltageHS()
///
/// @brief	Gets voltage hs
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The voltage hs.

unsigned int PAC1720::getVoltageHS() {
	return (readRegister(0x11) << 3) | (readRegister(0x12) >> 5);
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int PAC1720::getPowerHS()
///
/// @brief	Gets power hs
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The power hs.

unsigned int PAC1720::getPowerHS() {
	return (readRegister(0x15) << 8) | readRegister(0x16);
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int PAC1720::getCurrentDrawLS()
///
/// @brief	Gets current draw ls
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The current draw ls.

unsigned int PAC1720::getCurrentDrawLS() {
	return ((readRegister(0x0F) & (0xEF)) << 4) | (readRegister(0x10) >> 4);
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int PAC1720::getVoltageLS()
///
/// @brief	Gets voltage ls
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The voltage ls.

unsigned int PAC1720::getVoltageLS() {
	return (readRegister(0x13) << 3) | (readRegister(0x14) >> 5);
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int PAC1720::getPowerLS()
///
/// @brief	Gets power ls
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The power ls.

unsigned int PAC1720::getPowerLS() {
	return (readRegister(0x17) << 8) | readRegister(0x18);
}


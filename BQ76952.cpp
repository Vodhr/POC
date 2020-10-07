///-------------------------------------------------------------------------------------------------
/// @file	POC\BQ76952.cpp.
///
/// @brief	Implements the bq 76952 class

#include "BQ76952.h"

///-------------------------------------------------------------------------------------------------
/// @fn	BQ76952::BQ76952(BasicPOCModule* itsPOCModule, list<Component*>& componentList)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
/// @param [in,out]	componentList	[in,out] If non-null, list of components.

BQ76952::BQ76952(BasicPOCModule* itsPOCModule, list<Component*>& componentList) : I2CComponent("BQ76952", 0x42, false, 100000, itsPOCModule, componentList) {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BQ76952::init()
///
/// @brief	Initializes this object
///
/// @author	Benjamin
/// @date	28.09.2020

void BQ76952::init() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BQ76952::selfTest()
///
/// @brief	Tests self
///
/// @author	Benjamin
/// @date	28.09.2020

void BQ76952::selfTest() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	TimedState<Status5> BQ76952::getStatus5()
///
/// @brief	Gets status 5
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The status 5.

TimedState<Status5> BQ76952::getStatus5() {
	//TODO
	return status5;
}
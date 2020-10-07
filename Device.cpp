///-------------------------------------------------------------------------------------------------
/// @file	POC\Device.cpp.
///
/// @brief	Implements the device class

#include "Device.h"

list<Device*> Device::deviceList;

///-------------------------------------------------------------------------------------------------
/// @fn	Device::Device(string name)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	name	The name.

Device::Device(string name) {
	this->name = name;

	Device::deviceList.push_back(this);
}

///-------------------------------------------------------------------------------------------------
/// @fn	string Device::getName()
///
/// @brief	Gets the name
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The name.

string Device::getName() {
	return name;
}

///-------------------------------------------------------------------------------------------------
/// @fn	void Device::initAll()
///
/// @brief	Initializes all
///
/// @author	Benjamin
/// @date	28.09.2020

void Device::initAll() {
	for (auto e = deviceList.begin(); e != deviceList.end(); e++) {
		(*e)->init();
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	void Device::selfTestAll()
///
/// @brief	Self test all
///
/// @author	Benjamin
/// @date	28.09.2020

void Device::selfTestAll() {
	for (auto e = deviceList.begin(); e != deviceList.end(); e++) {
		(*e)->selfTest();
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	Device::~Device()
///
/// @brief	Destructor
///
/// @author	Benjamin
/// @date	28.09.2020

Device::~Device() {
	deviceList.remove(this);
}
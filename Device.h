#pragma once
#include <list>
#include <string>
#include <iostream>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	Device
///
/// @brief	A device.
///
/// @author	Benjamin
/// @date	09.01.2020

class Device
{
private:
protected:	

	/// @brief	List of devices
	static list<Device*> deviceList;

	/// @brief	The user friendly name of this device
	string name;
	
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	Device::Device(string name);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	name	The name of this device.

	Device(string name);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void Device::init() = 0;
	///
	/// @brief	Initializes this device
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	virtual void init() = 0;

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void Device::selfTest() = 0;
	///
	/// @brief	Self tests this device.
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	virtual void selfTest() = 0;

	///-------------------------------------------------------------------------------------------------
	/// @fn	string Device::getName();
	///
	/// @brief	Gets the name of the device.
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @returns	The name.

	string getName();

	///-------------------------------------------------------------------------------------------------
	/// @fn	static void Device::initAll();
	///
	/// @brief	Initializes all devices.
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	static void initAll();

	///-------------------------------------------------------------------------------------------------
	/// @fn	static void Device::selfTestAll();
	///
	/// @brief	Self test all devices.
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	static void selfTestAll();

	///-------------------------------------------------------------------------------------------------
	/// @fn	Device::~Device();
	///
	/// @brief	Destructor, unlists this device from DeviceList
	///
	/// @author	Benjamin
	/// @date	16.01.2020

	~Device();
};


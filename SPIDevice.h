#pragma once
#include "Device.h"
#include <string>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	SPIDevice
///
/// @brief	A SPI (Serial Peripheral Interface) device
///
/// @author	Benjamin
/// @date	09.01.2020

class SPIDevice :
	public Device
{
private:

	/// @brief	SPI clock phase mode (when cpol = false: rising edge = false, falling edge = true)
	bool cpha;

	/// @brief	SPI clock polarity mode (idle at low = false, idle at high = true)
	bool cpol;

	/// @brief	The maximum frequency at which this device can operate on SPI
	long fmax;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	SPIDevice::SPIDevice(string name, bool cpha, bool cpol, long fmax);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	name	The name of this device.
	/// @param 	cpha	The SPI clock phase mode of this device.
	/// @param 	cpol	The SPI clock polarity mode of this device.
	/// @param 	fmax	The maximum frequency at which this device can operate with.

	SPIDevice(string name, bool cpha, bool cpol, long fmax);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void SPIDevice::transfere(char* buffer, int n);
	///
	/// @brief	Simultaniously transmits and receives n bytes from buffer to/from this SPI device.
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param [in,out]	buffer	If non-null, bytes from buffer are transmitted and overwritten by recieved bytes from this device
	/// @param 		   	n	  	The number of bytes to be transmitted/received 

	void transfere(char* buffer, int n);
};


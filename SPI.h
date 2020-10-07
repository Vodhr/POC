///-------------------------------------------------------------------------------------------------
/// @file	POC\SPI.h.
///
/// @brief	Declares the spi class

#pragma once
#include "Device.h"
#include <string>
#include <linux/spi/spidev.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>
#include <mutex>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	SPI
///
/// @brief	A SPI (Serial Peripheral Interface) device
///
/// @author	Benjamin
/// @date	08.09.2020

class SPI
{
private:

	/// @brief	SPI clock phase mode (when cpol = false: rising edge = false, falling edge = true)
	bool cpha;

	/// @brief	SPI clock polarity mode (idle at low = false, idle at high = true)
	bool cpol;

	/// @brief	The maximum frequency at which this device can operate on SPI
	long fmax;

	static mutex spiMutex;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	SPI::SPI(bool cpha, bool cpol, long fmax);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	cpha	The SPI clock phase mode of this device.
	/// @param 	cpol	The SPI clock polarity mode of this device.
	/// @param 	fmax	The maximum frequency at which this device can operate with.

	SPI(bool cpha, bool cpol, long fmax);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void SPI::transfere(char* buffer, int n);
	///
	/// @brief	Simultaniously transmits and receives n bytes from buffer to/from this SPI device.
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param [in,out]	buffer	If non-null, bytes from buffer are transmitted and overwritten by
	/// 						recieved bytes from this device.
	/// @param 		   	n	  	The number of bytes to be transmitted/received.

	virtual void transfere(unsigned char* buffer, int n);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual unsigned char SPI::readRegister(unsigned char reg);
	///
	/// @brief	Reads a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg	The register.
	///
	/// @returns	The register.

	virtual unsigned char readRegister(unsigned char reg);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void SPI::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);
	///
	/// @brief	Reads a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg		  	The register.
	/// @param 	readBuffer	Buffer for read data.
	/// @param 	n		  	An int to process.

	virtual void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void SPI::writeRegister(unsigned char reg, unsigned char data);
	///
	/// @brief	Writes a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg 	The register.
	/// @param 	data	The data.

	virtual void writeRegister(unsigned char reg, unsigned char data);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void SPI::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);
	///
	/// @brief	Writes a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg		   	The register.
	/// @param 	writeBuffer	Buffer for write data.
	/// @param 	n		   	An int to process.

	virtual void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);
};


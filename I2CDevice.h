#pragma once
#include "Device.h"
#include <string>
#include <iostream>
#include <vector>
#include <linux/i2c-dev.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/ioctl.h>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	I2CDevice
///
/// @brief	An I2C (Inter Integrated Circuit) Device
///
/// @author	Benjamin
/// @date	09.01.2020

class I2CDevice : public Device
{
private:

	/// @brief	The maximum frequency at which this device can operate on the I2C bus
	long fmax;

	/// @brief	True if this device supports 10 bit addressing
	bool supports10BitAddressing;
protected:

	/// @brief	The I2C slave id of this device
	short i2cAddress;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	I2CDevice::I2CDevice(string name, short slaveID, bool supports10BitAddressing, long fmax);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	name				   	The name of this device.
	/// @param 	slaveID				   	The I2C slave id of this device.
	/// @param 	supports10BitAddressing	True if this device supports 10 bit addressing.
	/// @param 	fmax				   	The maximum frequency at which this device can operate on the I2C bus.

	I2CDevice(string name, short slaveID, bool supports10BitAddressing, long fmax);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void I2CDevice::transfere(char* tx, char* rx, int ntx, int nrx);
	///
	/// @brief	Transmits ntx bytes from the tx array to this device, then receives nrx bytes into rx from this device
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param [in]		tx 	If non-null, transmits ntx bytes from tx to this device 
	/// @param [out]	rx 	If non-null, receives nrx bytes from the this device and stores them in rx
	/// @param 		   	ntx	The number of bytes to be transmitted.
	/// @param 		   	nrx	The number of bytes to be received.

	virtual void transfere(unsigned char* tx, unsigned char* rx,unsigned int ntx, unsigned int nrx);

	virtual unsigned char readRegister(unsigned char reg);

	virtual void readRegister(unsigned char reg, unsigned char readBuffer[]);

	virtual void writeRegister(unsigned char reg, unsigned char data);

	virtual void writeRegister(unsigned char reg, unsigned char writeBuffer[]);

	short getI2CAddress();
};


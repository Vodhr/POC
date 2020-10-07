///-------------------------------------------------------------------------------------------------
/// @file	POC\I2C.h.
///
/// @brief	Declares the I2C interface

#pragma once
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
#include <mutex>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	I2C
///
/// @brief	An I2C (Inter Integrated Circuit) Device
///
/// @author	Benjamin
/// @date	08.09.2020

class I2C
{
private:

	/// @brief	The maximum frequency at which this device can operate on the I2C bus
	long fmax;

	/// @brief	True if this device supports 10 bit addressing
	bool supports10BitAddressing;

	static mutex i2cMutex;
protected:

	/// @brief	The I2C slave id of this device
	short i2cAddress;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	I2C::I2C(short slaveID, bool supports10BitAddressing, long fmax);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	slaveID				   	The I2C slave id of this device.
	/// @param 	supports10BitAddressing	True if this device supports 10 bit addressing.
	/// @param 	fmax				   	The maximum frequency at which this device can operate on the
	/// 								I2C bus.

	I2C(short slaveID, bool supports10BitAddressing, long fmax);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void I2C::transfere(unsigned char* tx, unsigned char* rx, int ntx, int nrx);
	///
	/// @brief	Transmits ntx bytes from the tx array to this device, then receives nrx bytes into rx
	/// 		from this device
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param [in]		tx 	If non-null, transmits ntx bytes from tx to this device.
	/// @param [out]	rx 	If non-null, receives nrx bytes from the this device and stores them in
	/// 					rx.
	/// @param 			ntx	The number of bytes to be transmitted.
	/// @param 			nrx	The number of bytes to be received.

	virtual void transfere(unsigned char* tx, unsigned char* rx, int ntx, int nrx);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void I2C::write(unsigned char data);
	///
	/// @brief	Writes a single byte to the device
	///
	/// @author	Benjamin
	/// @date	04.09.2020
	///
	/// @param 	data	The data byte to write.

	virtual void write(unsigned char data);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual unsigned char I2C::read();
	///
	/// @brief	Reads a single byte of data from the device
	///
	/// @author	Benjamin
	/// @date	08.09.2020
	///
	/// @returns	A char.

	virtual unsigned char read();

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual unsigned char I2C::readRegister(unsigned char reg);
	///
	/// @brief	Reads a register by first writing the register address and then reading from the
	/// 		device
	///
	/// @author	Benjamin
	/// @date	04.09.2020
	///
	/// @param 	reg	The register to be read from.
	///
	/// @returns	The the content of register or whatever the device returns.

	virtual unsigned char readRegister(unsigned char reg);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void I2C::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);
	///
	/// @brief	Reads n bytes from the register
	///
	/// @author	Benjamin
	/// @date	04.09.2020
	///
	/// @param 	reg		  	The register to be read from.
	/// @param 	readBuffer	Buffer for date read from the device.
	/// @param 	n		  	Number of bytes to be read from the register.

	virtual void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void I2C::writeRegister(unsigned char reg, unsigned char data);
	///
	/// @brief	Writes a register by first writing the register address and then writing the content
	/// 		to be stored in the register
	///
	/// @author	Benjamin
	/// @date	04.09.2020
	///
	/// @param 	reg 	The register to be written to.
	/// @param 	data	The data to be written to the register.

	virtual void writeRegister(unsigned char reg, unsigned char data);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void I2C::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);
	///
	/// @brief	Writes one byte each from writeBuffer to the registers following reg for n registers.
	/// 		(Not supported by all devices)
	///
	/// @author	Benjamin
	/// @date	04.09.2020
	///
	/// @param 	reg		   	The first register to be written to.
	/// @param 	writeBuffer	Buffer for write data.
	/// @param 	n		   	The number of bytes to write to the register.

	virtual void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);

	///-------------------------------------------------------------------------------------------------
	/// @fn	short I2C::getI2CAddress();
	///
	/// @brief	Gets the i2c address of the device
	///
	/// @author	Benjamin
	/// @date	04.09.2020
	///
	/// @returns	The i2c address.

	short getI2CAddress();
};


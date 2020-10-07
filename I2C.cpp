///-------------------------------------------------------------------------------------------------
/// @file	POC\I2C.cpp.
///
/// @brief	Declares the I2C interface

#include "I2C.h"

/// @brief	List of 2 c devices
vector<I2C> I2CDeviceList;

///-------------------------------------------------------------------------------------------------
/// @fn	I2C::I2C(short slaveID, bool supports10BitAddressing, long fmax)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	slaveID				   	Identifier for the slave.
/// @param 	supports10BitAddressing	True to supports 10 bit addressing.
/// @param 	fmax				   	The fmax.

I2C::I2C(short slaveID, bool supports10BitAddressing, long fmax) : 
	fmax(fmax),
	supports10BitAddressing(supports10BitAddressing),
	i2cAddress(slaveID) {

}

mutex I2C::i2cMutex;

///-------------------------------------------------------------------------------------------------
/// @fn	void I2C::transfere(unsigned char* tx, unsigned char* rx, int ntx, int nrx)
///
/// @brief	Transferes
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	tx 	If non-null, the transmit.
/// @param [in,out]	rx 	If non-null, the receive.
/// @param 		   	ntx	The ntx.
/// @param 		   	nrx	The nrx.

void I2C::transfere(unsigned char* tx, unsigned char* rx, int ntx, int nrx) {
	//TODO
	
	i2cMutex.lock();

	int file;


	///dev/i2c-0 for OPI
	file = open("/dev/i2c-0", O_RDWR);
	if (file < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		cout << "could not open I2C file" << endl;
	}

	if (ioctl(file, I2C_SLAVE, i2cAddress & 0xFF) < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		cout << "could not set I2C address" << endl;
	}

	if (::write(file, tx, ntx) != ntx) {
		/* ERROR HANDLING: I2C transaction failed */
		cout << "i2c send failed " << hex << i2cAddress << endl;
	}

	//usleep(100);
	
	//cout << "reading " << (int)nrx << " bytes from I2C" << endl;

	if (nrx > 0) {
		if (::read(file, rx, nrx) != nrx) {
			cout << "i2c receive failed " << hex << i2cAddress << endl;
		}
	}

	close(file);

	i2cMutex.unlock();
	//usleep(10000);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2C::write(unsigned char data)
///
/// @brief	Writes the given data
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	data	The data to write.

void I2C::write(unsigned char data) {
	unsigned char readBuffer[0];
	unsigned char writeBuffer[1]{ data };

	transfere(writeBuffer, readBuffer, 1, 0);
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned char I2C::read()
///
/// @brief	Gets the read
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	A char.

unsigned char I2C::read() {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[0];
	
	transfere(writeBuffer, readBuffer, 0, 1);

	return readBuffer[0];
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned char I2C::readRegister(unsigned char reg)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg	The register.
///
/// @returns	The register.

unsigned char I2C::readRegister(unsigned char reg) {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);

	return readBuffer[0];
}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2C::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		  	The register.
/// @param 	readBuffer	Buffer for read data.
/// @param 	n		  	An int to process.

void I2C::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, n);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2C::writeRegister(unsigned char reg, unsigned char data)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg 	The register.
/// @param 	data	The data.

void I2C::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char readBuffer[0];
	unsigned char writeBuffer[2]{ reg , data};

	transfere(writeBuffer, readBuffer, 2, 0);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2C::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		   	The register.
/// @param 	writeBuffer	Buffer for write data.
/// @param 	n		   	An int to process.

void I2C::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	unsigned char writeBufferComplete[1 + n];

	writeBufferComplete[0] = reg;

	for (unsigned int i = 1; i <= n; i++) {
		writeBufferComplete[i] = writeBuffer[i - 1];
	}

	transfere(writeBufferComplete, nullptr, n + 1, 0);
}

///-------------------------------------------------------------------------------------------------
/// @fn	short I2C::getI2CAddress()
///
/// @brief	Gets i 2 c address
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The i 2 c address.

short I2C::getI2CAddress() {
	return i2cAddress;
}
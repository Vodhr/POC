///-------------------------------------------------------------------------------------------------
/// @file	POC\SPI.cpp.
///
/// @brief	Implements the spi class

#include "SPI.h"

mutex SPI::spiMutex;

///-------------------------------------------------------------------------------------------------
/// @fn	SPI::SPI(bool cpha, bool cpol, long fmax)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	cpha	True to cpha.
/// @param 	cpol	True to cpol.
/// @param 	fmax	The fmax.

SPI::SPI(bool cpha, bool cpol, long fmax) : cpha(cpha), cpol(cpol), fmax(fmax) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPI::transfere(char* buffer, int n)
///
/// @brief	Transferes
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	buffer	If non-null, the buffer.
/// @param 		   	n	  	An int to process.

void SPI::transfere(unsigned char* buffer, int n) {
	spiMutex.lock();

	int file;

	unsigned char mode = 0;

	if (cpha) mode |= SPI_CPHA;
	if (cpol) mode |= SPI_CPOL;

	file = open("/dev/spidev0.0", O_RDWR);

	if (file < 0) {
		cout << "could not open SPI file" << endl;
	}

	if (ioctl(file, SPI_IOC_WR_MODE, &mode) < 0) {
		cout << "can't set spi mode" << endl;
	}

	if (ioctl(file, SPI_IOC_RD_MODE, &mode) < 0) {
		cout << "SPI rd_mode" << endl;
	}

	if (ioctl(file, SPI_IOC_WR_MAX_SPEED_HZ, &fmax) < 0) {
		cout << "can't set max speed hz" << endl;
	}

	if (ioctl(file, SPI_IOC_RD_MAX_SPEED_HZ, &fmax) < 0) {
		cout << "SPI max_speed_hz" << endl;
	}

	if (write(file, buffer, n) != n) {
		cout << "SPI send failed" << endl;
	}

	if (read(file, buffer, n) != n) {
		cout << "SPI receive failed" << endl;
	}
	
	close(file);

	spiMutex.unlock();
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned char SPI::readRegister(unsigned char reg)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg	The register.
///
/// @returns	The register.

unsigned char SPI::readRegister(unsigned char reg) {
	unsigned char readBuffer[1]{ reg };
	transfere(readBuffer, 1);
	return readBuffer[0];
}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPI::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		  	The register.
/// @param 	readBuffer	Buffer for read data.
/// @param 	n		  	An int to process.

void SPI::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	unsigned char readBufferTemp[n];
	readBufferTemp[0] = reg;


	for (unsigned int i = 1; i < n; i++) {
		readBufferTemp[i] = 0;
	}

	transfere(readBufferTemp, n);

	for (unsigned int i = 1; i < n; i++) {
		readBuffer[i - 1] = readBufferTemp[i];
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPI::writeRegister(unsigned char reg, unsigned char data)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg 	The register.
/// @param 	data	The data.

void SPI::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char writeBuffer[2]{ reg, data };

	transfere(writeBuffer, 2);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPI::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		   	The register.
/// @param 	writeBuffer	Buffer for write data.
/// @param 	n		   	An int to process.

void SPI::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	unsigned char writeBufferTemp[n + 1];

	writeBufferTemp[0] = reg;

	for (unsigned int i = 1; i < n + 1; i++) {
		writeBufferTemp[n] = writeBuffer[n - 1];
	}

	transfere(writeBufferTemp, n + 1);
}
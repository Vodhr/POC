///-------------------------------------------------------------------------------------------------
/// @file	POC\I2CComponent.cpp.
///
/// @brief	Declares the I2CComponent interface

#include "I2CComponent.h"
#include "BasicPOCModule.h"

///-------------------------------------------------------------------------------------------------
/// @fn	I2CComponent::I2CComponent(string name, short slaveID, bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, list<Component*>& componentList)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 		   	name				   	The name.
/// @param 		   	slaveID				   	Identifier for the slave.
/// @param 		   	supports10BitAddressing	True to supports 10 bit addressing.
/// @param 		   	fmax				   	The fmax.
/// @param [in,out]	itsPOCModule		   	If non-null, its poc module.
/// @param [in,out]	componentList		   	[in,out] If non-null, list of components.

I2CComponent::I2CComponent(string name, short slaveID, 
		bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, 
		list<Component*>& componentList) : 
		Component(name, itsPOCModule), I2C(slaveID, supports10BitAddressing, fmax)  {

	componentList.push_back(this);
}

///-------------------------------------------------------------------------------------------------
/// @fn	I2CComponent::~I2CComponent()
///
/// @brief	Destructor
///
/// @author	Benjamin
/// @date	28.09.2020

I2CComponent::~I2CComponent() {

}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2CComponent::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx)
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

void I2CComponent::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx) {
	itsPOCModule->activate();
	I2C::transfere(tx, rx, ntx, nrx);
	//TODO
	itsPOCModule->canBeDeactivated();
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned char I2CComponent::readRegister(unsigned char reg)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg	The register.
///
/// @returns	The register.

unsigned char I2CComponent::readRegister(unsigned char reg) {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);

	return readBuffer[0];
}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2CComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		  	The register.
/// @param 	readBuffer	Buffer for read data.
/// @param 	n		  	An int to process.

void I2CComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, n);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2CComponent::writeRegister(unsigned char reg, unsigned char data)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg 	The register.
/// @param 	data	The data.

void I2CComponent::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char readBuffer[0]{ };
	unsigned char writeBuffer[2]{ reg, data };

	transfere(writeBuffer, readBuffer, 2, 0);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void I2CComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		   	The register.
/// @param 	writeBuffer	Buffer for write data.
/// @param 	n		   	An int to process.

void I2CComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	unsigned char writeBufferComplete[1 + n];

	writeBufferComplete[0] = reg;

	for (unsigned int i = 1; i <= n; i++) {
		writeBufferComplete[i] = writeBuffer[i - 1];
	}

	transfere(writeBufferComplete, nullptr, n + 1, 0);
}
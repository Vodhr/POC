///-------------------------------------------------------------------------------------------------
/// @file	POC\SPIComponent.cpp.
///
/// @brief	Implements the spi component class

#include "SPIComponent.h"
#include "BasicPOCModule.h"

///-------------------------------------------------------------------------------------------------
/// @fn	SPIComponent::SPIComponent(string name, unsigned char slotNumber, bool cpha, bool cpol, long fmax, BasicPOCModule* itsPOCModule, list<Component*>& componentList)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 		   	name		 	The name.
/// @param 		   	slotNumber   	The slot number.
/// @param 		   	cpha		 	True to cpha.
/// @param 		   	cpol		 	True to cpol.
/// @param 		   	fmax		 	The fmax.
/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
/// @param [in,out]	componentList	[in,out] If non-null, list of components.

SPIComponent::SPIComponent(string name, unsigned char slotNumber, bool cpha, bool cpol, long fmax, BasicPOCModule* itsPOCModule,
	list<Component*>& componentList) : 
	slotNr(slotNumber),
	Component(name, itsPOCModule), 
	SPI(cpha, cpol, fmax) {

	componentList.push_back(this);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPIComponent::transfere(char* buffer, int n)
///
/// @brief	Transferes
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	buffer	If non-null, the buffer.
/// @param 		   	n	  	An int to process.

void SPIComponent::transfere(unsigned char* buffer, int n) {
	//TODO
	
	itsPOCModule->activate(*this);

	SPI::transfere(buffer, n);

	itsPOCModule->canBeDeactivated(*this);
}

void SPIComponent::write(unsigned char data) {
	unsigned char writeBuffer[1]{ data };

	transfere(writeBuffer, 1);
}

unsigned char SPIComponent::read() {
	unsigned char writeBuffer[1]{ 0x00 };

	transfere(writeBuffer, 1);

	return writeBuffer[0];
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned char SPIComponent::readRegister(unsigned char reg)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg	The register.
///
/// @returns	The register.

unsigned char SPIComponent::readRegister(unsigned char reg) {
	//TODO
	return 0;
}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPIComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n)
///
/// @brief	Reads a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		  	The register.
/// @param 	readBuffer	Buffer for read data.
/// @param 	n		  	An int to process.

void SPIComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPIComponent::writeRegister(unsigned char reg, unsigned char data)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg 	The register.
/// @param 	data	The data.

void SPIComponent::writeRegister(unsigned char reg, unsigned char data) {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void SPIComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n)
///
/// @brief	Writes a register
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	reg		   	The register.
/// @param 	writeBuffer	Buffer for write data.
/// @param 	n		   	An int to process.

void SPIComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	SPIComponent::~SPIComponent()
///
/// @brief	Destructor
///
/// @author	Benjamin
/// @date	28.09.2020

SPIComponent::~SPIComponent() {

}
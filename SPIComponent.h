///-------------------------------------------------------------------------------------------------
/// @file	POC\SPIComponent.h.
///
/// @brief	Declares the spi component class

#pragma once
#include "SPI.h"
#include "Component.h"

///-------------------------------------------------------------------------------------------------
/// @class	BasicPOCModule
///
/// @brief	A basic poc module.
///
/// @author	Benjamin
/// @date	28.09.2020

class BasicPOCModule;

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	SPIComponent
///
/// @brief	A basic SPI Component located on a POC module and accessable through SPI. Due to the
/// 		architecture of POC, the basic R/W-functions have to be overwritten.
///
/// @author	Benjamin
/// @date	08.09.2020

class SPIComponent : public SPI, public Component {
private:
public:
	/// @brief	The slot nr
	const unsigned char slotNr;

	///-------------------------------------------------------------------------------------------------
	/// @fn	SPIComponent::SPIComponent(string name, unsigned char slotNr, bool cpha, bool cpol, long fmax, BasicPOCModule* itsPOCModule, list<Component*>& componentList);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 		   	name		 	The name.
	/// @param 		   	slotNr		 	The slot nr.
	/// @param 		   	cpha		 	True to cpha.
	/// @param 		   	cpol		 	True to cpol.
	/// @param 		   	fmax		 	The fmax.
	/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
	/// @param [in,out]	componentList	[in,out] If non-null, list of components.

	SPIComponent(string name, unsigned char slotNr, bool cpha, bool cpol, long fmax, BasicPOCModule* itsPOCModule,
		list<Component*>& componentList);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void SPIComponent::transfere(char* buffer, int n);
	///
	/// @brief	Transferes
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param [in,out]	buffer	If non-null, the buffer.
	/// @param 		   	n	  	An int to process.

	virtual void transfere(unsigned char* buffer, int n);

	virtual void write(unsigned char data);

	virtual unsigned char read();

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned char SPIComponent::readRegister(unsigned char reg);
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
	/// @fn	void SPIComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);
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
	/// @fn	void SPIComponent::writeRegister(unsigned char reg, unsigned char data);
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
	/// @fn	void SPIComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);
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

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual SPIComponent::~SPIComponent();
	///
	/// @brief	Destructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	virtual ~SPIComponent();
};


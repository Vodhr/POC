///-------------------------------------------------------------------------------------------------
/// @file	POC\I2CComponent.h.
///
/// @brief	Declares the I2CComponent interface

#pragma once
#include <list>
#include "I2C.h"
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
/// @class	I2CComponent
///
/// @brief	A basic I2C component located on a POC module accessable through I2C. Due to the
/// 		architecture of POC, the basic R/W-functions have to be overwritten.
///
/// @author	Benjamin
/// @date	08.09.2020

class I2CComponent : public I2C, public Component {
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	I2CComponent::I2CComponent(string name, short slaveID, bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, list<Component*>& componentList);
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

	I2CComponent(string name, short slaveID, 
		bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, 
		list<Component*>& componentList);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void I2CComponent::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx);
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

	void transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx);

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned char I2CComponent::readRegister(unsigned char reg);
	///
	/// @brief	Reads a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg	The register.
	///
	/// @returns	The register.

	unsigned char readRegister(unsigned char reg);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void I2CComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);
	///
	/// @brief	Reads a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg		  	The register.
	/// @param 	readBuffer	Buffer for read data.
	/// @param 	n		  	An int to process.

	void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void I2CComponent::writeRegister(unsigned char reg, unsigned char data);
	///
	/// @brief	Writes a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg 	The register.
	/// @param 	data	The data.

	void writeRegister(unsigned char reg, unsigned char data);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void I2CComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);
	///
	/// @brief	Writes a register
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	reg		   	The register.
	/// @param 	writeBuffer	Buffer for write data.
	/// @param 	n		   	An int to process.

	void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual I2CComponent::~I2CComponent();
	///
	/// @brief	Destructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	virtual ~I2CComponent();
};

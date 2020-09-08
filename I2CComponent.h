#pragma once
#include <list>
#include "I2C.h"
#include "Component.h"

class BasicPOCModule;

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	I2CComponent
///
/// @brief	A basic I2C component located on a POC module accessable through I2C.
/// 		Due to the architecture of POC, the basic R/W-functions have to be overwritten.
///
/// @author	Benjamin
/// @date	08.09.2020

class I2CComponent : public I2C, public Component {
public:
	I2CComponent(string name, short slaveID, 
		bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, 
		list<Component*>& componentList);
	
	void transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx);

	unsigned char readRegister(unsigned char reg);

	void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);

	void writeRegister(unsigned char reg, unsigned char data);

	void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);

	virtual ~I2CComponent();
};

#pragma once
#include "SPI.h"
#include "Component.h"

class BasicPOCModule;

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	SPIComponent
///
/// @brief	A basic SPI Component located on a POC module and accessable through SPI. 
/// 		Due to the architecture of POC, the basic R/W-functions have to be overwritten.
///
/// @author	Benjamin
/// @date	08.09.2020

class SPIComponent : public SPI, public Component {
private:
public:
	const unsigned char slotNr;

	SPIComponent(string name, unsigned char slotNr, bool cpha, bool cpol, long fmax, BasicPOCModule* itsPOCModule,
		list<Component*>& componentList);

	void transfere(char* buffer, int n);

	unsigned char readRegister(unsigned char reg);

	void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);

	void writeRegister(unsigned char reg, unsigned char data);

	void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);

	virtual ~SPIComponent();
};


#pragma once
#include "I2CComponent.h"
#include <list>

using namespace std;

class ATtiny814 :
	public I2CComponent
{
public:
	ATtiny814(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList);
	void transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx);
	unsigned char readRegister(unsigned char reg);
	void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);
	void writeRegister(unsigned char reg, unsigned char data);
	void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);
};


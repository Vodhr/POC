#pragma once
#include <list>
#include "I2CDevice.h"

class BasicPOCModule;

using namespace std;

class BasicPOCModuleI2CComponent : public I2CDevice{
protected:
	BasicPOCModule* itsPOCModule;

private:
public:
	BasicPOCModuleI2CComponent(string name, short slaveID, 
		bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, 
		list<BasicPOCModuleI2CComponent*>& componentList);
	
	void transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx);

	unsigned char readRegister(unsigned char reg);

	void readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n);

	void writeRegister(unsigned char reg, unsigned char data);

	void writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n);

	virtual ~BasicPOCModuleI2CComponent();
};

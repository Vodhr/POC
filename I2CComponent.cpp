#include "I2CComponent.h"
#include "BasicPOCModule.h"

I2CComponent::I2CComponent(string name, short slaveID, 
		bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, 
		list<Component*>& componentList) : 
		Component(name, itsPOCModule), I2C(slaveID, supports10BitAddressing, fmax)  {

	componentList.push_back(this);
}

I2CComponent::~I2CComponent() {

}

void I2CComponent::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx) {
	itsPOCModule->activate();
	I2C::transfere(tx, rx, ntx, nrx);
	//TODO
	itsPOCModule->canBeDeactivated();
}

unsigned char I2CComponent::readRegister(unsigned char reg) {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);

	return readBuffer[0];
}

void I2CComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, n);
}

void I2CComponent::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char readBuffer[0]{ };
	unsigned char writeBuffer[2]{ reg, data };

	transfere(writeBuffer, readBuffer, 2, 0);
}

void I2CComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	unsigned char writeBufferComplete[1 + n];

	writeBufferComplete[0] = reg;

	for (unsigned int i = 1; i <= n; i++) {
		writeBufferComplete[i] = writeBuffer[i - 1];
	}

	transfere(writeBufferComplete, nullptr, n + 1, 0);
}
#include "BasicPOCModuleI2CComponent.h"
#include "BasicPOCModule.h"

BasicPOCModuleI2CComponent::BasicPOCModuleI2CComponent(string name, short slaveID, 
		bool supports10BitAddressing, long fmax, BasicPOCModule* itsPOCModule, 
		list<BasicPOCModuleI2CComponent*>& componentList) : 
		I2CDevice(name, slaveID, supports10BitAddressing, fmax), 
		itsPOCModule(itsPOCModule) {

	componentList.push_back(this);
}

BasicPOCModuleI2CComponent::~BasicPOCModuleI2CComponent() {

}

void BasicPOCModuleI2CComponent::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx) {
	itsPOCModule->activate();
	I2CDevice::transfere(tx, rx, ntx, nrx);
	itsPOCModule->deactivate();
}

unsigned char BasicPOCModuleI2CComponent::readRegister(unsigned char reg) {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);

	return readBuffer[0];
}

void BasicPOCModuleI2CComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, n);
}

void BasicPOCModuleI2CComponent::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char readBuffer[1]{ data };
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);
}

void BasicPOCModuleI2CComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	unsigned char writeBufferComplete[1 + n];

	writeBufferComplete[0] = reg;

	for (unsigned int i = 1; i <= n; i++) {
		writeBufferComplete[i] = writeBuffer[i - 1];
	}

	transfere(writeBufferComplete, nullptr, n + 1, 0);
}
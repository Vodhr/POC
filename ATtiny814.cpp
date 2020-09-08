#include "ATtiny814.h"

ATtiny814::ATtiny814(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList) :
	I2CComponent(name, slaveID, false, 100000, itsPOCModule, componentList) {

}

void ATtiny814::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx) {
	I2C::transfere(tx, rx, ntx, nrx);
}

unsigned char ATtiny814::readRegister(unsigned char reg) {
	return I2C::readRegister(reg);
}

void ATtiny814::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	I2C::readRegister(reg, readBuffer, n);
}

void ATtiny814::writeRegister(unsigned char reg, unsigned char data) {
	I2C::writeRegister(reg, data);
}

void ATtiny814::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	I2C::writeRegister(reg, writeBuffer, n);
}
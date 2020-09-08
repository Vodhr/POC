#include "PAC1720.h"

PAC1720::PAC1720(BasicPOCModule* itsPOCModule, list<Component*>& componentList) : 
	I2CComponent("PAC1720", 0x29, false, 100000, itsPOCModule, componentList) {

}

void PAC1720::init() {
	//TODO
}

void PAC1720::selfTest() {
	//TODO
}

unsigned int PAC1720::getCurrentDrawHS() {
	//TODO
	return ((readRegister(0x0D) & (0xEF)) << 4) | (readRegister(0x0E) >> 4);
}

unsigned int PAC1720::getVoltageHS() {
	return (readRegister(0x11) << 3) | (readRegister(0x12) >> 5);
}

unsigned int PAC1720::getPowerHS() {
	return (readRegister(0x15) << 8) | readRegister(0x16);
}

unsigned int PAC1720::getCurrentDrawLS() {
	return ((readRegister(0x0F) & (0xEF)) << 4) | (readRegister(0x10) >> 4);
}

unsigned int PAC1720::getVoltageLS() {
	return (readRegister(0x13) << 3) | (readRegister(0x14) >> 5);
}

unsigned int PAC1720::getPowerLS() {
	return (readRegister(0x17) << 8) | readRegister(0x18);
}


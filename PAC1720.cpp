#include "PAC1720.h"

PAC1720::PAC1720(BasicPOCModule* itsPOCModule, list<POCModuleComponent*>& componentList) : POCModuleComponent(itsPOCModule, componentList), I2CDevice("PAX1720", 0x29, false, 100000){

}

void PAC1720::init() {
	//TODO
}

void PAC1720::selfTest() {
	//TODO
}

unsigned int PAC1720::getCurrentDrawHS() {
	itsPOCModule->activate();

	char writeBuffer[]{ 0x0D };
	char readBuffer1[1];
	char readBuffer2[1];

	transfere(writeBuffer, readBuffer1, sizeof(writeBuffer), sizeof(readBuffer1));

	writeBuffer[0] = 0x0E;

	transfere(writeBuffer, readBuffer2, sizeof(writeBuffer), sizeof(readBuffer2));

	itsPOCModule->deactivate();

	return ((readBuffer1[0] & (0xEF)) << 4) | (readBuffer2[0] >> 4);
}

unsigned int PAC1720::getVoltageHS() {
	itsPOCModule->activate();

	char writeBuffer[]{ 0x11 };
	char readBuffer1[1];
	char readBuffer2[1];

	transfere(writeBuffer, readBuffer1, sizeof(writeBuffer), sizeof(readBuffer1));

	writeBuffer[0] = 0x11;

	transfere(writeBuffer, readBuffer2, sizeof(writeBuffer), sizeof(readBuffer2));

	itsPOCModule->deactivate();

	return (readBuffer1[0]  << 3) | (readBuffer2[0] >> 5);
}

unsigned int PAC1720::getPowerHS() {
	itsPOCModule->activate();

	char writeBuffer[]{ 0x15 };
	char readBuffer1[1];
	char readBuffer2[1];

	transfere(writeBuffer, readBuffer1, sizeof(writeBuffer), sizeof(readBuffer1));

	writeBuffer[0] = 0x16;

	transfere(writeBuffer, readBuffer2, sizeof(writeBuffer), sizeof(readBuffer2));

	itsPOCModule->deactivate();

	return (readBuffer1[0] << 8) | readBuffer2[0];
}

unsigned int PAC1720::getCurrentDrawLS() {
	itsPOCModule->activate();

	char writeBuffer[]{ 0x0F };
	char readBuffer1[1];
	char readBuffer2[1];

	transfere(writeBuffer, readBuffer1, sizeof(writeBuffer), sizeof(readBuffer1));

	writeBuffer[0] = 0x10;

	transfere(writeBuffer, readBuffer2, sizeof(writeBuffer), sizeof(readBuffer2));

	itsPOCModule->deactivate();

	return ((readBuffer1[0] & (0xEF)) << 4) | (readBuffer2[0] >> 4);
}

unsigned int PAC1720::getVoltageLS() {
	itsPOCModule->activate();

	char writeBuffer[]{ 0x13 };
	char readBuffer1[1];
	char readBuffer2[1];

	transfere(writeBuffer, readBuffer1, sizeof(writeBuffer), sizeof(readBuffer1));

	writeBuffer[0] = 0x14;

	transfere(writeBuffer, readBuffer2, sizeof(writeBuffer), sizeof(readBuffer2));

	itsPOCModule->deactivate();

	return (readBuffer1[0] << 3) | (readBuffer2[0] >> 5);
}

unsigned int PAC1720::getPowerLS() {
	itsPOCModule->activate();

	char writeBuffer[]{ 0x17 };
	char readBuffer1[1];
	char readBuffer2[1];

	transfere(writeBuffer, readBuffer1, sizeof(writeBuffer), sizeof(readBuffer1));

	writeBuffer[0] = 0x18;

	transfere(writeBuffer, readBuffer2, sizeof(writeBuffer), sizeof(readBuffer2));

	itsPOCModule->deactivate();

	return (readBuffer1[0] << 8) | readBuffer2[0];
}


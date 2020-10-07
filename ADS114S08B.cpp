#include "ADS114S08B.h"

ADS114S08B::ADS114S08B(BasicPOCModule* itsPOCModule, list<Component*>& componentList) : SPIComponent("ADC", 1, true, false, 1000000, itsPOCModule, componentList) {

}

unsigned char ADS114S08B::readRegister(unsigned char reg) {
	unsigned char readBuffer[2]{ reg | 0b00100000, 0 };
	transfere(readBuffer, 2);
	return readBuffer[1];
}

void ADS114S08B::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char writeBuffer[2]{ reg | 0b01000000, data };
	transfere(writeBuffer, 2);
}

int ADS114S08B::getConversionData() {
	unsigned char readBuffer[3] { 0b00100010, 0, 0 };

	int temp;

	for (unsigned char i = 0; i < 16; i++) {
		writeRegister(2, i << 4);

		transfere(readBuffer, 3);
		temp = readBuffer[1] << 8 | readBuffer[2];

		cout << temp << endl;
	}

	return temp;
}

void ADS114S08B::init() {
	//wake up
	write(0b00000010);

	//start conversion
	write(0b00001000);
}

void ADS114S08B::selfTest() {
	//TODO
}
#include "BMI055.h"

BMI055::BMI055(BasicPOCModule* pocModule, list<BasicPOCModuleI2CComponent*>& componentList) : BasicPOCModuleI2CComponent("BMI055", 0x42, false, 100000, pocModule, componentList) {

}

void BMI055::init() {
	//TODO
	// Set FIFO Mode to Stream
	writeRegister(0x3E, 0b10000000);
}

void BMI055::selfTest() {
	//TODO
}



unsigned char BMI055::getAccelerationData(int accelerationX[32], int accelerationY[32], int accelerationZ[32]) {
	unsigned char n = readRegister(0x0E) & 0b01111111;
	unsigned char readBuffer[32 * 3 * 2];

	readRegister(0x3F, readBuffer, n);

	for (unsigned int i = 0; i < n; i++) {
		accelerationX[i] = readBuffer[6 * i + 1] << 8 | readBuffer[6 * i];
		accelerationY[i] = readBuffer[6 * i + 3] << 8 | readBuffer[6 * i + 2];
		accelerationZ[i] = readBuffer[6 * i + 5] << 8 | readBuffer[6 * i + 4];
	}

	return n;
}

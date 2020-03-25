#include "PowerLogger.h"

PowerLogger::PowerLogger(string name, short i2CAddress) : I2CDevice(name, i2CAddress, false, 0) {

}

void PowerLogger::init() {
	//TODO
}

void PowerLogger::selfTest() {
	//TODO
}
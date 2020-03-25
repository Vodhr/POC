#include "POCController.h"

//TODO
POCController::POCController(string name, short i2CAddress) : I2CDevice::I2CDevice(name, i2CAddress, true, 0) {

}

void POCController::init() {
	cout << this->getName() << ": Initialising ...\n";
	//TODO
	cout << this->getName() << ": Done!\n";
}

void POCController::selfTest() {
	cout << this->getName() << ": Self Test ...\n";
	//TODO
	cout << this->getName() << ": Done, Success!\n";
}
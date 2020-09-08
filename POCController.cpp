#include "POCController.h"

//TODO
POCController::POCController(string name, short i2CAddress, BasicPOCModule* itsPOCModule, list<Component*>& componentList) : ATtiny814(name, i2CAddress, itsPOCModule, componentList) {

}

void I2C::write(unsigned char data) {
	unsigned char readBuffer[0];
	unsigned char readBuffer[1]{ data };
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

void POCController::activateSPISlot(unsigned char slotNr) {
	if (slotNr < 64)
		write(slotNr);
	cout << name << ": Slot number is too big" << endl;
}
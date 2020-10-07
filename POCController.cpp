///-------------------------------------------------------------------------------------------------
/// @file	POC\POCController.cpp.
///
/// @brief	Implements the poc controller class

#include "POCController.h"

///-------------------------------------------------------------------------------------------------
/// @fn	POCController::POCController(string name, short i2CAddress, BasicPOCModule* itsPOCModule, list<Component*>& componentList)
///
/// @brief	TODO
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 		   	name		 	The name.
/// @param 		   	i2CAddress   	Zero-based index of the 2 c address.
/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
/// @param [in,out]	componentList	[in,out] If non-null, list of components.

POCController::POCController(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList) : ATtiny814(name, slaveID, itsPOCModule, componentList) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	void POCController::init()
///
/// @brief	Initializes this object
///
/// @author	Benjamin
/// @date	28.09.2020

void POCController::init() {
	cout << this->getName() << ": Initialising ...\n";
	//TODO
	cout << this->getName() << ": Done!\n";
}

///-------------------------------------------------------------------------------------------------
/// @fn	void POCController::selfTest()
///
/// @brief	Tests self
///
/// @author	Benjamin
/// @date	28.09.2020

void POCController::selfTest() {
	cout << this->getName() << ": Self Test ...\n";
	//TODO
	cout << this->getName() << ": Done, Success!\n";
}

///-------------------------------------------------------------------------------------------------
/// @fn	void POCController::activateSPISlot(unsigned char slotNr)
///
/// @brief	Activates the spi slot described by slotNr
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	slotNr	The slot nr.

void POCController::activateSPISlot(unsigned char slotNr) {
	if (slotNr < 64)
		write(slotNr);
	else 
		cout << name << ": Slot number is too big" << endl;
}

void POCController::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx) {
	I2C::transfere(tx, rx, ntx, nrx);
}
unsigned char POCController::readRegister(unsigned char reg) {
	return I2C::readRegister(reg);
}
void POCController::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	I2C::readRegister(reg, readBuffer, n);
}
void POCController::writeRegister(unsigned char reg, unsigned char data) {
	I2C::writeRegister(reg, data);
}
void POCController::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	I2C::writeRegister(reg, writeBuffer, n);
}
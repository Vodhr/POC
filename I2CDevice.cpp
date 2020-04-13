#include "I2CDevice.h"

vector<I2CDevice> I2CDeviceList;

I2CDevice::I2CDevice(string name, short slaveID, bool supports10BitAddressing, long fmax) : 
	Device::Device(name), 
	fmax(fmax),
	supports10BitAddressing(supports10BitAddressing),
	slaveID(slaveID) {
}

void I2CDevice::transfere(char* tx, char* rx, int ntx, int nrx) {
	//TODO
}

short I2CDevice::getI2CAddress() {
	return slaveID;
}
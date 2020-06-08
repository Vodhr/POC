#include "I2CDevice.h"

vector<I2CDevice> I2CDeviceList;

I2CDevice::I2CDevice(string name, short slaveID, bool supports10BitAddressing, long fmax) : 
	Device::Device(name), 
	fmax(fmax),
	supports10BitAddressing(supports10BitAddressing),
	i2cAddress(slaveID) {

}

void I2CDevice::transfere(char* tx, char* rx, int ntx, int nrx) {
	//TODO
	int file;


	///dev/i2c-0 for OPI
	file = open("/dev/i2c-1", O_RDWR);
	if (file < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		cout << "could not open I2C file" << endl;
	}

	if (ioctl(file, I2C_SLAVE, i2cAddress & 0xFF) < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		cout << "could not open I2C file" << endl;
	}

	if (write(file, tx, ntx) != ntx) {
		/* ERROR HANDLING: I2C transaction failed */
		cout << "i2c send failed" << endl;
	}
	

	if (nrx > 0) {
		if (read(file, rx, nrx) != ntx) {
			cout << "i2c receive failed" << endl;
		}
	}

	close(file);

	usleep(1000);
}

short I2CDevice::getI2CAddress() {
	return i2cAddress;
}
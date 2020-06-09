#include "I2CDevice.h"

vector<I2CDevice> I2CDeviceList;

I2CDevice::I2CDevice(string name, short slaveID, bool supports10BitAddressing, long fmax) : 
	Device::Device(name), 
	fmax(fmax),
	supports10BitAddressing(supports10BitAddressing),
	i2cAddress(slaveID) {

}

void I2CDevice::transfere(unsigned char* tx, unsigned char* rx, unsigned int ntx, unsigned int nrx) {
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

unsigned char I2CDevice::readRegister(unsigned char reg) {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);

	return readBuffer[0];
}

void I2CDevice::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, n);
}

void I2CDevice::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char readBuffer[1]{ data };
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);
}

void I2CDevice::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	unsigned char writeBufferComplete[1 + n];

	writeBufferComplete[0] = reg;

	for (unsigned int i = 1; i <= n; i++) {
		writeBufferComplete[i] = writeBuffer[i - 1];
	}

	transfere(writeBufferComplete, nullptr, n + 1, 0);
}



short I2CDevice::getI2CAddress() {
	return i2cAddress;
}
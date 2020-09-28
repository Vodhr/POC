#include "I2C.h"

vector<I2C> I2CDeviceList;

I2C::I2C(short slaveID, bool supports10BitAddressing, long fmax) : 
	fmax(fmax),
	supports10BitAddressing(supports10BitAddressing),
	i2cAddress(slaveID) {

}

void I2C::transfere(unsigned char* tx, unsigned char* rx, int ntx, int nrx) {
	//TODO
	int file;


	///dev/i2c-0 for OPI
	file = open("/dev/i2c-0", O_RDWR);
	if (file < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		cout << "could not open I2C file" << endl;
	}

	if (ioctl(file, I2C_SLAVE, i2cAddress & 0xFF) < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		cout << "could not open I2C file" << endl;
	}

	if (::write(file, tx, ntx) != ntx) {
		/* ERROR HANDLING: I2C transaction failed */
		cout << "i2c send failed" << endl;
	}

	//usleep(100);
	
	//cout << "reading " << (int)nrx << " bytes from I2C" << endl;

	if (nrx > 0) {
		if (::read(file, rx, nrx) != nrx) {
			cout << "i2c receive failed" << endl;
		}
	}

	close(file);

	//usleep(10000);
}

void I2C::write(unsigned char data) {
	unsigned char readBuffer[0];
	unsigned char writeBuffer[1]{ data };

	transfere(writeBuffer, readBuffer, 1, 0);
}

unsigned char I2C::read() {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[0];
	
	transfere(writeBuffer, readBuffer, 0, 1);

	return readBuffer[0];
}

unsigned char I2C::readRegister(unsigned char reg) {
	unsigned char readBuffer[1];
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, 1);

	return readBuffer[0];
}

void I2C::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	unsigned char writeBuffer[1]{ reg };

	transfere(writeBuffer, readBuffer, 1, n);
}

void I2C::writeRegister(unsigned char reg, unsigned char data) {
	unsigned char readBuffer[0];
	unsigned char writeBuffer[2]{ reg , data};

	transfere(writeBuffer, readBuffer, 2, 0);
}

void I2C::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	unsigned char writeBufferComplete[1 + n];

	writeBufferComplete[0] = reg;

	for (unsigned int i = 1; i <= n; i++) {
		writeBufferComplete[i] = writeBuffer[i - 1];
	}

	transfere(writeBufferComplete, nullptr, n + 1, 0);
}



short I2C::getI2CAddress() {
	return i2cAddress;
}
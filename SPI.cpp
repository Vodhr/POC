#include "SPI.h"

SPI::SPI(bool cpha, bool cpol, long fmax) : cpha(cpha), cpol(cpol), fmax(fmax) {

}

void SPI::transfere(char* buffer, int n) {
	//TODO
	int file;


	///dev/i2c-0 for OPI
	file = open("/dev/spidev-0", O_RDWR);
	if (file < 0) {
		/* ERROR HANDLING; you can check errno to see what went wrong */
		cout << "could not open SPI file" << endl;
	}


	if (write(file, buffer, n) != n) {
		/* ERROR HANDLING: I2C transaction failed */
		cout << "SPI send failed" << endl;
	}

	//usleep(100);

	//cout << "reading " << (int)nrx << " bytes from I2C" << endl;

	if (read(file, buffer, n) != n) {
		cout << "SPI receive failed" << endl;
	}
	

	close(file);
}

unsigned char SPI::readRegister(unsigned char reg) {
	//TODO
	return 0;
}

void SPI::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	//TODO
}

void SPI::writeRegister(unsigned char reg, unsigned char data) {
	//TODO
}

void SPI::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	//TODO
}
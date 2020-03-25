#include "SPIDevice.h"

SPIDevice::SPIDevice(string name, bool cpha, bool cpol, long fmax) : Device::Device(name), cpha(cpha), cpol(cpol), fmax(fmax) {

}

void SPIDevice::transfere(char* buffer, int n) {
	//TODO
}
#include "Device.h"

list<Device*> Device::deviceList;

Device::Device(string name) {
	this->name = name;

	Device::deviceList.push_back(this);
}

string Device::getName() {
	return name;
}

void Device::initAll() {
	for (auto e = deviceList.begin(); e != deviceList.end(); e++) {
		(*e)->init();
	}
}

void Device::selfTestAll() {
	for (auto e = deviceList.begin(); e != deviceList.end(); e++) {
		(*e)->selfTest();
	}
}

Device::~Device() {
	deviceList.remove(this);
}
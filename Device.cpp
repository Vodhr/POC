#include "Device.h"

list<Device*> Device::DeviceList;

Device::Device(string name) {
	this->name = name;

	Device::DeviceList.push_back(this);
}

string Device::getName() {
	return name;
}

void Device::initAll() {
	for (auto e = DeviceList.begin(); e != DeviceList.end(); e++) {
		(*e)->init();
	}
}

void Device::selfTestAll() {
	for (auto e = DeviceList.begin(); e != DeviceList.end(); e++) {
		(*e)->selfTest();
	}
}

Device::~Device() {
	DeviceList.remove(this);
}
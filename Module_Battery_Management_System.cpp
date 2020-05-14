#include "Module_Battery_Management_System.h"

Module_Battery_Management_System::Module_Battery_Management_System() 
	: BasicPOCModule(getClassName(), 0x42), bq(this){

}

void Module_Battery_Management_System::init() {
	//TODO
}

void Module_Battery_Management_System::selfTest() {
	//TODO
}

const uint16_t Module_Battery_Management_System::getId() {
	//See PoC Module Table
	return 0x020;
}

const string Module_Battery_Management_System::getClassName() {
	return "Battery Management System";
}

Module_Battery_Management_System::Cell::Cell(unsigned int number) : number(number) {

}

unsigned int Module_Battery_Management_System::Cell::getNumber() {
	return number;
}

double Module_Battery_Management_System::Cell::getVoltage() {
	//TODO
	return 0.0;
}

void Module_Battery_Management_System::Cell::setMaxVoltage(double maxVoltage) {
	this->maxVoltage = maxVoltage;
}

double Module_Battery_Management_System::Cell::getMaxVoltage() {
	return maxVoltage;
}

void Module_Battery_Management_System::Cell::setMaxCapacity(double maxCapacity) {
	this->maxCapacity = maxCapacity;
}

double Module_Battery_Management_System::Cell::getMaxCapacity() {
	return maxCapacity;
}

void Module_Battery_Management_System::Cell::setMinVoltage(double minVoltage) {
	this->minVoltage = minVoltage;
}

double Module_Battery_Management_System::Cell::getMinVoltage() {
	return minVoltage;
}

bool Module_Battery_Management_System::Cell::getIsActive() {
	return isActive;
}

void Module_Battery_Management_System::Cell::activate() {
	isActive = true;
}

void Module_Battery_Management_System::Cell::deactivate() {
	isActive = false;
}

double Module_Battery_Management_System::getBatteryCapacityLeft() {
	double capacityLeft = 0;

	for (auto e = cells.begin(); e != cells.end(); e++) {
		if ((*e)->getIsActive()) {
			//TODO Battery is no Capacitor lul
			capacityLeft += (*e)->getVoltage() / (*e)->getMaxVoltage() * (*e)->getMaxCapacity();
		}
	}

	return capacityLeft;
}

double Module_Battery_Management_System::getBatteryMaxCapacity() {
	double totalCapacity = 0;

	for (auto e = cells.begin(); e != cells.end(); e++) {
		if ((*e)->getIsActive()) {
			totalCapacity += (*e)->getMaxCapacity();
		}
	}

	return totalCapacity;
}

double Module_Battery_Management_System::getBatteryState() {
	return getBatteryCapacityLeft() / getBatteryMaxCapacity();
}

double Module_Battery_Management_System::getCurrentDraw() {
	//TODO
	return 0.0;
} 
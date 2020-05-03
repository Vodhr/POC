#include "Module_Battery_Management_System.h"

Module_Battery_Management_System::Module_Battery_Management_System() 
	: BasicPOCModule(getClassName(), 0x42) {

}

void Module_Battery_Management_System::init() {
	//TODO
}

void Module_Battery_Management_System::selfTest() {
	//TODO
}

const uint16_t Module_Battery_Management_System::getId() {
	return 0x020;
}

const string Module_Battery_Management_System::getClassName() {
	return "Battery Management System";
}

Module_Battery_Management_System::Cell::Cell(unsigned int number) : number(number), maxVoltage(3.3) {

}

Module_Battery_Management_System::Cell::Cell(unsigned int number, double maxVoltage) : number(number), maxVoltage(maxVoltage) {

}

unsigned int Module_Battery_Management_System::Cell::getNumber() {
	return number;
}

double Module_Battery_Management_System::Cell::getVoltage() {
	//TODO
	return 0.0;
}

double Module_Battery_Management_System::Cell::getMaxVoltage() {
	return maxVoltage;
}

void Module_Battery_Management_System::addCell(unsigned int cellNumber) {
	bool found = false;

	for (auto e = cells.begin(); e != cells.end(); e++) {
		if ((*e)->getNumber() == cellNumber) {
			found = true;
		}
	}

	if (!found) {
		cells.push_back(make_shared<Module_Battery_Management_System::Cell>(cellNumber));
	}
}

void Module_Battery_Management_System::removeCell(unsigned int cellNumber) {
	for (auto e = cells.begin(); e != cells.end(); e++) {
		if ((*e)->getNumber() == cellNumber) {
			cells.remove((*e));
		}
	}
}

void Module_Battery_Management_System::useAllCells() {
	const unsigned int maxCells = 8;		//this might not be correct
	for (unsigned int i = 0; i < maxCells; i++) {
		Module_Battery_Management_System::addCell(i);
	}
}

double Module_Battery_Management_System::getBatteryState() {
	double batteryState = 0;
	for (auto e = cells.begin(); e != cells.end(); e++) {
		batteryState += (*e)->getVoltage / (*e)->getMaxVoltage();
	}

	batteryState /= cells.size();

	return batteryState;
}

double Module_Battery_Management_System::getCellVoltage(unsigned int cellNumber) {
	bool found = false;
	shared_ptr<Cell> foundCell;

	for (auto e = cells.begin(); e != cells.end(); e++) {
		if ((*e)->getNumber == cellNumber) {
			if (!found) {
				foundCell = *e;
				found = true;
			}
			else {
				//TODO
				throw new exception();
			}
		}
	}

	return foundCell->getVoltage();
}

double Module_Battery_Management_System::getCurrentDraw() {
	//TODO
	return 0.0;
}
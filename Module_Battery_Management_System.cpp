#include "Module_Battery_Management_System.h"

Module_Battery_Management_System::Module_Battery_Management_System() : BasicPOCModule(getClassName(), 0x42) {

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
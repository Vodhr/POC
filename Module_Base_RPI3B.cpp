#include "Module_Base_RPI3B.h"

Module_Base_RPI3B::Module_Base_RPI3B() : BasicPOCModule(getClassName(), 0x42) {

}

void Module_Base_RPI3B::init() {
	//TODO
}

void Module_Base_RPI3B::selfTest() {
	//TODO
}

const uint16_t Module_Base_RPI3B::getId() {
	return 0xB01;
}

const string Module_Base_RPI3B::getClassName() {
	return "Raspberry 3B Base Module";
}
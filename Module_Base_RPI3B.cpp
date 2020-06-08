#include "Module_Base_RPI3B.h"

Module_Base_RPI3B::Module_Base_RPI3B() : BasicPOCModule(getClassName(), 0x42), pac(this, componentList) {

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

double Module_Base_RPI3B::getCurrentDrawHS() {
	return static_cast<double>(pac.getCurrentDrawHS()) * 10 / 2047;
}

double Module_Base_RPI3B::getVoltageHS() {
	return static_cast<double>(pac.getVoltageHS()) * 0.01952;
}

double Module_Base_RPI3B::getPowerHS() {
	return static_cast<double>(pac.getPowerHS()) * 0.0061;
}

double Module_Base_RPI3B::getCurrentDrawLS() {
	return static_cast<double>(pac.getCurrentDrawLS()) * 10 / 2047;
}

double Module_Base_RPI3B::getVoltageLS() {
	return static_cast<double>(pac.getVoltageLS()) * 0.01952;
}

double Module_Base_RPI3B::getPowerLS() {
	return static_cast<double>(pac.getPowerLS()) * 0.0061;
}
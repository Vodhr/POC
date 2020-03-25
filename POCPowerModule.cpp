#include "POCPowerModule.h"

list<POCPowerModule&> POCPowerModule::moduleList;

POCPowerModule::POCPowerModule() : BasicPOCModule::BasicPOCModule("Power Module " + to_string(POCPowerModule::moduleList.size()), 0x00) {
	POCPowerModule::moduleList.push_back(*this);
	//TODO
}

void POCPowerModule::init() {
	//TODO
}

void POCPowerModule::selfTest() {
	//TODO
}

double POCPowerModule::getPowerDraw() {
	//TODO
	return 0.0;
}

double POCPowerModule::getBatteryState() {
	//TODO
	return 0.0;
}

POCPowerModule::~POCPowerModule() {
	moduleList.remove(*this);
}

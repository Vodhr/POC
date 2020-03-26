#include "POCMotorModule.h"

list<POCMotorModule*> POCMotorModule::moduleList;

POCMotorModule::POCMotorModule() : BasicPOCModule::BasicPOCModule("Motor Module " + to_string(moduleList.size()), 0x00) {
	moduleList.push_back(this);
	//TODO
}

void POCMotorModule::init() {
	//TODO
}

void POCMotorModule::selfTest() {
	//TODO
}

POCMotorModule::~POCMotorModule() {
	moduleList.remove(this);
}
#include "BasicPOCModule.h"

list<BasicPOCModule*> BasicPOCModule::moduleList;

BasicPOCModule::BasicPOCModule(string name, short slaveID) : Device(name), POCCONTROLLER(name + " Controller", slaveID) {
	BasicPOCModule::moduleList.push_back(this);
}

void BasicPOCModule::fixAddressConflicts() {
	//TODO
}

void BasicPOCModule::activate() {
	//TODO
}

void BasicPOCModule::deactivate() {
	//TODO
}

void BasicPOCModule::listAllModules() {
	for (auto e = BasicPOCModule::moduleList.begin(); e != BasicPOCModule::moduleList.end(); e++) {
		cout << (*e)->getName() << "\n";
	}
}

BasicPOCModule::~BasicPOCModule() {
	moduleList.remove(this);
}
#include "BasicPOCModule.h"

list<BasicPOCModule*> BasicPOCModule::moduleList;

mutex BasicPOCModule::pocMutex;

BasicPOCModule::BasicPOCModule(string name, short slaveID) : Device(name + " " + to_string(moduleList.size())), POCCONTROLLER(name + " Controller", slaveID) {
	BasicPOCModule::moduleList.push_back(this);
}

void BasicPOCModule::fixAddressConflicts() {
	//TODO
}

void BasicPOCModule::activate() {
	//TODO
	BasicPOCModule::pocMutex.lock();

	POCCONTROLLER.transfere(nullptr, nullptr, 0, 0);
}

void BasicPOCModule::deactivate() {
	//TODO
	char buf[]{ 0xFF };

	POCCONTROLLER.transfere(buf, buf, 1, 0);

	BasicPOCModule::pocMutex.unlock();
}

bool BasicPOCModule::getIsActive() {
	return isActive;
}

void BasicPOCModule::listAllModules() {
	for (auto e = BasicPOCModule::moduleList.begin(); e != BasicPOCModule::moduleList.end(); e++) {
		cout << (*e)->getName() << ". " << hex << "0x" << (*e)->getId() << ", I2C: " << (*e)->POCCONTROLLER.getI2CAddress() << "\n";
	}
}

BasicPOCModule::~BasicPOCModule() {
	moduleList.remove(this);
}
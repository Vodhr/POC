#include "BasicPOCModule.h"

list<BasicPOCModule*> BasicPOCModule::moduleList;

mutex BasicPOCModule::pocMutex;

BasicPOCModule::BasicPOCModule(string name, shared_ptr<POCController> pocControllerRef) : Device(name + " " + to_string(moduleList.size())), pocControllerRef(pocControllerRef) {
	if (pocControllerRef == nullptr) {
		pocControllerRef = make_shared<POCController>("POCController", 0x42, this, componentList);
	}
	BasicPOCModule::moduleList.push_back(this);
}

void BasicPOCModule::fixAddressConflicts() {
	//TODO
}

void BasicPOCModule::activate() {
	//TODO
	

	if (!isActive) {
		BasicPOCModule::pocMutex.lock();
		//TODO
		/*
		if (lastUsedModule != nullptr && lastUsedModule != this) {
			lastUsedModule->deactivate();
		}

		lastUsedModule = this;
		*/
		pocControllerRef->transfere(nullptr, nullptr, 0, 0);

		isActive = true;
	}
}

void BasicPOCModule::deactivate() {
	pocMutex.lock();	//Make sure module is not used

	unsigned char writeBuffer[1]{ 0xFF };

	pocControllerRef->transfere(writeBuffer, writeBuffer, 1, 0);

	isActive = false;

	pocMutex.unlock();
}

void BasicPOCModule::canBeDeactivated() {
	//TODO
	BasicPOCModule::pocMutex.unlock();
}

void BasicPOCModule::activate(SPIComponent& component) {
	spiMutex.lock();

	if (activeSPIComponent != &component) {
		activeSPIComponent = &component;
		pocControllerRef->activateSPISlot(component.slotNr);
	}
	
}

void BasicPOCModule::canBeDeactivated(SPIComponent& component) {
	spiMutex.unlock();
}

bool BasicPOCModule::getIsActive() const {
	return isActive;
}

void BasicPOCModule::listAllModules() {
	for (auto e = BasicPOCModule::moduleList.begin(); e != BasicPOCModule::moduleList.end(); e++) {
		cout << (*e)->getName() << ". " << hex << "0x" << (*e)->getId() << ", I2C: " << (*e)->pocControllerRef->getI2CAddress() << "\n";
	}
}

BasicPOCModule::~BasicPOCModule() {
	moduleList.remove(this);
}
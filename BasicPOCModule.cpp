///-------------------------------------------------------------------------------------------------
/// @file	POC\BasicPOCModule.cpp.
///
/// @brief	Implements the basic poc module class

#include "BasicPOCModule.h"

list<BasicPOCModule*> BasicPOCModule::moduleList;

mutex BasicPOCModule::pocMutex;

///-------------------------------------------------------------------------------------------------
/// @fn	BasicPOCModule::BasicPOCModule(string name, shared_ptr<POCController> pocControllerRef)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	name				The name.
/// @param 	pocControllerRef	The poc controller reference.

BasicPOCModule::BasicPOCModule(string name, shared_ptr<POCController> pocControllerRef) : Device(name + " " + to_string(moduleList.size())), pocControllerRef(pocControllerRef) {
	if (pocControllerRef == nullptr) {
		pocControllerRef = make_shared<POCController>("POCController", 0x42, this, componentList);
	}
	BasicPOCModule::moduleList.push_back(this);

	//deactivate();
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BasicPOCModule::fixAddressConflicts()
///
/// @brief	Fix address conflicts
///
/// @author	Benjamin
/// @date	28.09.2020

void BasicPOCModule::fixAddressConflicts() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BasicPOCModule::activate()
///
/// @brief	Activates this object
///
/// @author	Benjamin
/// @date	28.09.2020

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

///-------------------------------------------------------------------------------------------------
/// @fn	void BasicPOCModule::deactivate()
///
/// @brief	Deactivates this object
///
/// @author	Benjamin
/// @date	28.09.2020

void BasicPOCModule::deactivate() {
	pocMutex.lock();	//Make sure module is not used

	unsigned char writeBuffer[1]{ 0xFF };

	pocControllerRef->transfere(writeBuffer, nullptr, 1, 0);

	isActive = false;

	pocMutex.unlock();
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BasicPOCModule::canBeDeactivated()
///
/// @brief	Can be deactivated
///
/// @author	Benjamin
/// @date	28.09.2020

void BasicPOCModule::canBeDeactivated() {
	//TODO
	BasicPOCModule::pocMutex.unlock();
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BasicPOCModule::activate(SPIComponent& component)
///
/// @brief	Activates the given component
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	component	The component.

void BasicPOCModule::activate(SPIComponent& component) {
	spiMutex.lock();

	if (activeSPIComponent != &component) {
		activeSPIComponent = &component;
		pocControllerRef->activateSPISlot(component.slotNr);
	}
	
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BasicPOCModule::canBeDeactivated(SPIComponent& component)
///
/// @brief	Can be deactivated
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	component	The component.

void BasicPOCModule::canBeDeactivated(SPIComponent& component) {
	spiMutex.unlock();
}

///-------------------------------------------------------------------------------------------------
/// @fn	bool BasicPOCModule::getIsActive() const
///
/// @brief	Gets is active
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	True if it succeeds, false if it fails.

bool BasicPOCModule::getIsActive() const {
	return isActive;
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BasicPOCModule::listAllModules()
///
/// @brief	List all modules
///
/// @author	Benjamin
/// @date	28.09.2020

void BasicPOCModule::listAllModules() {
	for (auto e = BasicPOCModule::moduleList.begin(); e != BasicPOCModule::moduleList.end(); e++) {
		cout << (*e)->getName() << ". " << hex << "0x" << (*e)->getId() << ", I2C: " << (*e)->pocControllerRef->getI2CAddress() << "\n";
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	BasicPOCModule::~BasicPOCModule()
///
/// @brief	Destructor
///
/// @author	Benjamin
/// @date	28.09.2020

BasicPOCModule::~BasicPOCModule() {
	moduleList.remove(this);
}
///-------------------------------------------------------------------------------------------------
/// @file	POC\BasicPOCModule.h.
///
/// @brief	Declares the basic poc module class

#pragma once
#include "Device.h"
#include "POCController.h"
#include "Component.h"
#include "SPIComponent.h"
#include <shared_mutex>
#include <list>
#include <exception>
#include <memory>
#include <atomic>


using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	BasicPOCModule
///
/// @brief	A basic PoC module
///
/// @author	Benjamin
/// @date	09.01.2020

class BasicPOCModule :
	public Device {
private:

	/// @brief	List of modules
	static list<BasicPOCModule*> moduleList;

	/// @brief	True if is module is active, false if not
	atomic<bool> isActive = false;

	///-------------------------------------------------------------------------------------------------
	/// @brief	The mutex that guards the module de-/activation, only one board may be active at a
	/// 		time

	static mutex pocMutex;		

	/// @brief	The currently active module
	BasicPOCModule* activeModule = nullptr;

	///-------------------------------------------------------------------------------------------------
	/// @brief	The mutex that guards the module SPI component de-/activation, only one SPI component
	/// 		may be active on a board at a time

	mutex spiMutex;

	/// @brief	The currently active SPI component
	SPIComponent* activeSPIComponent = nullptr;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BasicPOCModule::deactivate();
	///
	/// @brief	Deactivates this module
	///
	/// @author	Benjamin
	/// @date	05.09.2020

	void deactivate();

protected:

	/// @brief	The a reference to this module's controller, used by the module for de-/activation
	shared_ptr<POCController> pocControllerRef;

	/// @brief	List of I2C/SPI components located on this board
	list<Component*> componentList;

public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BasicPOCModule::activate();
	///
	/// @brief	Activates this module.
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	void activate();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BasicPOCModule::canBeDeactivated();
	///
	/// @brief	Deactivates this module.
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	void canBeDeactivated();

	///-------------------------------------------------------------------------------------------------
	/// @fn	BasicPOCModule::BasicPOCModule(string name, shared_ptr<POCController> pocControllerRef = nullptr);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	name				The name of this module.
	/// @param 	pocControllerRef	(Optional) default I2C Slave-Id for the controller of this module.

	BasicPOCModule(string name, shared_ptr<POCController> pocControllerRef = nullptr);

	///-------------------------------------------------------------------------------------------------
	/// @fn	static void BasicPOCModule::fixAddressConflicts();
	///
	/// @brief	Fix address conflicts between modules
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	static void fixAddressConflicts();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BasicPOCModule::activate(SPIComponent& component);
	///
	/// @brief	Activates the given SPI component. If another SPI component is still active, is waits
	/// 		until the other SPI component calls canBeDeactivated. After that the POCController
	/// 		will by itself deactivated the other SPI component befor activating this SPI Component
	///
	/// @author	Benjamin
	/// @date	05.09.2020
	///
	/// @param [in,out]	component	The SPI component that will be activated.

	void activate(SPIComponent& component);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BasicPOCModule::canBeDeactivated(SPIComponent& component);
	///
	/// @brief	Declares the component ready for deactivation
	///
	/// @author	Benjamin
	/// @date	05.09.2020
	///
	/// @param [in,out]	component	The component.

	void canBeDeactivated(SPIComponent& component);

	///-------------------------------------------------------------------------------------------------
	/// @fn	static void BasicPOCModule::listAllModules();
	///
	/// @brief	prints the names of all modules
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	static void listAllModules();

	///-------------------------------------------------------------------------------------------------
	/// @fn	bool BasicPOCModule::getIsActive() const;
	///
	/// @brief	Destructor, removes this POC Module from the ModuleList
	///
	/// @author	Benjamin
	/// @date	16.01.2020
	///
	/// @returns	True if it succeeds, false if it fails.

	bool getIsActive() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual const uint16_t BasicPOCModule::getId() const = 0;
	///
	/// @brief	Gets the identifier
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The identifier.

	virtual const uint16_t getId() const = 0;

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual const string BasicPOCModule::getClassName() const = 0;
	///
	/// @brief	Gets class name
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The class name.

	virtual const string getClassName() const = 0;

	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual BasicPOCModule::~BasicPOCModule();
	///
	/// @brief	Destructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	virtual ~BasicPOCModule();
};


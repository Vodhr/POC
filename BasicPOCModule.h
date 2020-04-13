#pragma once
#include "Device.h"
#include "POCController.h"
#include <list>
#include <memory>

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
protected:

	/// @brief	The controller of this module
	POCController POCCONTROLLER;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BasicPOCModule::activate();
	///
	/// @brief	Activates this module.
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	void activate();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BasicPOCModule::deactivate();
	///
	/// @brief	Deactivates this module.
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	void deactivate();


public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	BasicPOCModule::BasicPOCModule(string name, short slaveID);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	09.01.2020
	///
	/// @param 	name   	The name of this module.
	/// @param 	slaveID	default I2C Slave-Id for the controller of this module

	BasicPOCModule(string name, short slaveID);

	///-------------------------------------------------------------------------------------------------
	/// @fn	static void BasicPOCModule::fixAddressConflicts();
	///
	/// @brief	Fix address conflicts between modules
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	static void fixAddressConflicts();

	///-------------------------------------------------------------------------------------------------
	/// @fn	static void BasicPOCModule::listAllModules();
	///
	/// @brief	prints the names of all modules
	///
	/// @author	Benjamin
	/// @date	09.01.2020

	static void listAllModules();

	///-------------------------------------------------------------------------------------------------
	/// @fn	BasicPOCModule::~BasicPOCModule();
	///
	/// @brief	Destructor, removes this POC Module from the ModuleList
	///
	/// @author	Benjamin
	/// @date	16.01.2020

	virtual const uint16_t getId() = 0;

	virtual const string getClassName() = 0;

	virtual ~BasicPOCModule();
};


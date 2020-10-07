///-------------------------------------------------------------------------------------------------
/// @file	POC\Component.h.
///
/// @brief	Declares the component class

#pragma once
#include "Device.h"

///-------------------------------------------------------------------------------------------------
/// @class	BasicPOCModule
///
/// @brief	forward declaration
///
/// @author	Benjamin
/// @date	28.09.2020

class BasicPOCModule;

///-------------------------------------------------------------------------------------------------
/// @class	Component
///
/// @brief	A component located on a module board
///
/// @author	Benjamin
/// @date	08.09.2020

class Component : public Device
{
protected:
	/// @brief	its poc module
	BasicPOCModule* itsPOCModule;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	Component::Component(string name, BasicPOCModule* itsPOCModule);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 		   	name			The name.
	/// @param [in,out]	itsPOCModule	If non-null, its poc module.

	Component(string name, BasicPOCModule* itsPOCModule);
};


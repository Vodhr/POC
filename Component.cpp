///-------------------------------------------------------------------------------------------------
/// @file	POC\Component.cpp.
///
/// @brief	Implements the component class

#include "Component.h"
#include "BasicPOCModule.h"

///-------------------------------------------------------------------------------------------------
/// @fn	Component::Component(string name, BasicPOCModule* itsPOCModule)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 		   	name			The name.
/// @param [in,out]	itsPOCModule	If non-null, its poc module.

Component::Component(string name, BasicPOCModule* itsPOCModule) : Device(name), itsPOCModule(itsPOCModule) {

}

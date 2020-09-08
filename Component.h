#pragma once
#include "Device.h"

//forward declaration
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
	BasicPOCModule* itsPOCModule;
public:
	Component(string name, BasicPOCModule* itsPOCModule);
};


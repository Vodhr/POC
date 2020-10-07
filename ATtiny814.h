///-------------------------------------------------------------------------------------------------
/// @file	POC\ATtiny814.h.
///
/// @brief	Declares the ttiny 814 class

#pragma once
#include "I2CComponent.h"
#include <list>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	ATtiny814
///
/// @brief	A ttiny 814.
///
/// @author	Benjamin
/// @date	28.09.2020

class ATtiny814 :
	public I2CComponent
{
public:
	ATtiny814(string name, short slaveID, BasicPOCModule* itsPOCModule, list<Component*>& componentList);
};


///-------------------------------------------------------------------------------------------------
/// @file	POC\BasicPOCModuleStatusEntry.h.
///
/// @brief	Declares the basic poc module status entry class

#pragma once
#include <string>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	BasicPOCModuleStatusEntry
///
/// @brief	A basic poc module status entry.
///
/// @author	Benjamin
/// @date	28.09.2020

class BasicPOCModuleStatusEntry
{
	///-------------------------------------------------------------------------------------------------
	/// @fn	virtual void BasicPOCModuleStatusEntry::serialize() = 0;
	///
	/// @brief	Serialize this object to the given stream
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	virtual void serialize() = 0;
};


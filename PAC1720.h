///-------------------------------------------------------------------------------------------------
/// @file	POC\PAC1720.h.
///
/// @brief	Declares the pac 1720 class

#pragma once
#include "I2CComponent.h"
#include <list>
#include "BasicPOCModule.h"

///-------------------------------------------------------------------------------------------------
/// @class	PAC1720
///
/// @brief	A pac 1720.
///
/// @author	Benjamin
/// @date	28.09.2020

class PAC1720 :
	public I2CComponent {
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	PAC1720::PAC1720(BasicPOCModule* itsPOCModule, list<Component*>& componentList);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
	/// @param [in,out]	componentList	[in,out] If non-null, list of components.

	PAC1720(BasicPOCModule* itsPOCModule, list<Component*>& componentList);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void PAC1720::init() final;
	///
	/// @brief	Initializes this object
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void init() final;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void PAC1720::selfTest() final;
	///
	/// @brief	Tests self
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void selfTest() final;

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned int PAC1720::getCurrentDrawHS();
	///
	/// @brief	Gets current draw hs
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The current draw hs.

	unsigned int getCurrentDrawHS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned int PAC1720::getVoltageHS();
	///
	/// @brief	Gets voltage hs
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The voltage hs.

	unsigned int getVoltageHS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned int PAC1720::getPowerHS();
	///
	/// @brief	Gets power hs
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The power hs.

	unsigned int getPowerHS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned int PAC1720::getCurrentDrawLS();
	///
	/// @brief	Gets current draw ls
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The current draw ls.

	unsigned int getCurrentDrawLS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned int PAC1720::getVoltageLS();
	///
	/// @brief	Gets voltage ls
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The voltage ls.

	unsigned int getVoltageLS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned int PAC1720::getPowerLS();
	///
	/// @brief	Gets power ls
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The power ls.

	unsigned int getPowerLS();
};


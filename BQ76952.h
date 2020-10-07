///-------------------------------------------------------------------------------------------------
/// @file	POC\BQ76952.h.
///
/// @brief	Declares the bq 76952 class

#pragma once
#include <memory>
#include <list>
#include "TimedState.h"
#include "I2CComponent.h"

///-------------------------------------------------------------------------------------------------
/// @struct	Status5
///
/// @brief	The status 5.
///
/// @author	Benjamin
/// @date	28.09.2020

struct Status5 {
	//TODO

};

///-------------------------------------------------------------------------------------------------
/// @class	BQ76952
///
/// @brief	A bq 76952.
///
/// @author	Benjamin
/// @date	28.09.2020

class BQ76952 :
	public I2CComponent {

	/// @brief	The fifth status
	TimedState<Status5> status5;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	BQ76952::BQ76952(BasicPOCModule* itsPOCModule, list<Component*>& componentlist);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
	/// @param [in,out]	componentlist	[in,out] If non-null, the componentlist.

	BQ76952(BasicPOCModule* itsPOCModule, list<Component*>& componentlist);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BQ76952::init() final;
	///
	/// @brief	Initializes this object
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void init() final;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BQ76952::selfTest() final;
	///
	/// @brief	Tests self
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void selfTest() final;

	///-------------------------------------------------------------------------------------------------
	/// @fn	TimedState<Status5> BQ76952::getStatus5();
	///
	/// @brief	Gets status 5
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The status 5.

	TimedState<Status5> getStatus5();
};


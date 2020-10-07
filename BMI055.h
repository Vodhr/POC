///-------------------------------------------------------------------------------------------------
/// @file	POC\BMI055.h.
///
/// @brief	Declares the bmi 055 class

#pragma once
#include "I2CComponent.h"
#include <queue>
#include "Vector3d.h"

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	BMI055IMU
///
/// @brief	A bmi 055 imu.
///
/// @author	Benjamin
/// @date	28.09.2020

class BMI055IMU :
	public I2CComponent
{
private:
	unsigned int bandwidth_hz;
	queue<unsigned char> avgBufferHealth;
public:
	BMI055IMU(BasicPOCModule* pocModule, list<Component*>& componentList, unsigned int bandwidth_hz = 400);
	void init();
	void selfTest();
	void getAccelerationData(queue<int>& accelerationX, queue<int>& accelerationY, queue<int>& accelerationZ);
	char getTemperature();
	float getAvgBufferHealth() const;
	unsigned int getBandwidth_hz() const;
};

///-------------------------------------------------------------------------------------------------
/// @class	BMI055Gyro
///
/// @brief	A bmi 055 gyro.
///
/// @author	Benjamin
/// @date	28.09.2020

class BMI055Gyro :
	public I2CComponent {
private:
	/// @brief	The bandwidth Hz
	unsigned int bandwidth_hz;
	/// @brief	The average buffer health
	queue<unsigned char> avgBufferHealth;
	/// @brief	The rotation rate offset s
	Vector3d<double> rotationRateOffset_s;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	BMI055Gyro::BMI055Gyro(BasicPOCModule* pocModule, list<Component*>& moduleList, unsigned int bandwidth_hz = 400);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param [in,out]	pocModule   	If non-null, the poc module.
	/// @param [in,out]	moduleList  	[in,out] If non-null, list of modules.
	/// @param 		   	bandwidth_hz	(Optional) The bandwidth Hz.

	BMI055Gyro(BasicPOCModule* pocModule, list<Component*>& moduleList, unsigned int bandwidth_hz = 400);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BMI055Gyro::init();
	///
	/// @brief	Initializes this object
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void init();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BMI055Gyro::selfTest();
	///
	/// @brief	Tests self
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void selfTest();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void BMI055Gyro::getRotationRateData(queue<Vector3d<double>>& q);
	///
	/// @brief	Gets rotation rate data
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param [in,out]	q	A queue&lt;Vector3d&lt;double&gt;&gt; to process.

	void getRotationRateData(queue<Vector3d<double>>& q);

	///-------------------------------------------------------------------------------------------------
	/// @fn	float BMI055Gyro::getAvgBufferHealth() const;
	///
	/// @brief	Gets average buffer health
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The average buffer health.

	float getAvgBufferHealth() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	Vector3d<double> BMI055Gyro::getRotationOffset() const;
	///
	/// @brief	Gets rotation offset
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The rotation offset.

	Vector3d<double> getRotationOffset() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	unsigned int BMI055Gyro::getBandwidth_hz() const;
	///
	/// @brief	Gets bandwidth Hz
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The bandwidth Hz.

	unsigned int getBandwidth_hz() const;
};


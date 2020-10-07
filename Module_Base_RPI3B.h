///-------------------------------------------------------------------------------------------------
/// @file	POC\Module_Base_RPI3B.h.
///
/// @brief	Declares the module base rpi 3 b class

#pragma once
#include "BasicPOCModule.h"
#include "PAC1720.h"
#include "BMI055.h"
#include <math.h>
#include <thread>
#include <queue>
#include <list>
#include "Vector3d.h"
#include "TimedState.h"
#include "CoordinateSystem3D.h"
#include "RepeatedTask.h"

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	BaseModuleController
///
/// @brief	Example of a module specific POCController class. This can be used to customize the
/// 		controller by adding additional functionality
///
/// @author	Benjamin
/// @date	08.09.2020

class BaseModuleController : public POCController {
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	BaseModuleController::BaseModuleController(short slaveId, BasicPOCModule* itsPOCModule, list<Component*>& componentList)
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 		   	slaveId		 	Identifier for the slave.
	/// @param [in,out]	itsPOCModule 	If non-null, its poc module.
	/// @param [in,out]	componentList	[in,out] If non-null, list of components.

	BaseModuleController(short slaveId, BasicPOCModule* itsPOCModule, list<Component*>& componentList) :
		POCController("Base Module Controller", slaveId, itsPOCModule, componentList) {

	}
};

///-------------------------------------------------------------------------------------------------
/// @class	Module_Base_RPI3B
///
/// @brief	Module class for the Raspberry Pi 3B base module
///
/// @author	Benjamin
/// @date	08.09.2020

class Module_Base_RPI3B : public BasicPOCModule
{
private:
	/// @brief	The controller of this module
	POCController pocController;

	/// @brief	The pac
	PAC1720 pac;

	/// @brief	The inertial measurement unit located on this board
	BMI055IMU imu;

	/// @brief	The gyroscope located on this board
	BMI055Gyro gyro;

	RepeatedTask gyroTask;

	bool shouldStop = false;

	/// @brief	The current coordinate system of this module, base point is the position of the imu
	CoordinateSystem3d<double> coordinateSystem;

	/// @brief	The imu temperature degrees c
	float imuTemperature_degC;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	Module_Base_RPI3B::Module_Base_RPI3B();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	Module_Base_RPI3B();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void Module_Base_RPI3B::init();
	///
	/// @brief	Initializes this object
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void init();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void Module_Base_RPI3B::selfTest();
	///
	/// @brief	Tests self
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void selfTest();

	///-------------------------------------------------------------------------------------------------
	/// @fn	const uint16_t Module_Base_RPI3B::getId() const;
	///
	/// @brief	Gets the identifier
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The identifier.

	const uint16_t getId() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	const string Module_Base_RPI3B::getClassName() const;
	///
	/// @brief	Gets class name
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The class name.

	const string getClassName() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	double Module_Base_RPI3B::getCurrentDrawHS();
	///
	/// @brief	Gets current draw hs
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The current draw hs.

	double getCurrentDrawHS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	double Module_Base_RPI3B::getVoltageHS();
	///
	/// @brief	Gets voltage hs
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The voltage hs.

	double getVoltageHS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	double Module_Base_RPI3B::getPowerHS();
	///
	/// @brief	Gets power hs
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The power hs.

	double getPowerHS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	double Module_Base_RPI3B::getCurrentDrawLS();
	///
	/// @brief	Gets current draw ls
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The current draw ls.

	double getCurrentDrawLS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	double Module_Base_RPI3B::getVoltageLS();
	///
	/// @brief	Gets voltage ls
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The voltage ls.

	double getVoltageLS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	double Module_Base_RPI3B::getPowerLS();
	///
	/// @brief	Gets power ls
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The power ls.

	double getPowerLS();

	///-------------------------------------------------------------------------------------------------
	/// @fn	float Module_Base_RPI3B::getIMUBufferHealth() const;
	///
	/// @brief	Gets imu buffer health
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The imu buffer health.

	float getIMUBufferHealth() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	float Module_Base_RPI3B::getGyroBufferHealth() const;
	///
	/// @brief	Gets gyro buffer health
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The gyro buffer health.

	float getGyroBufferHealth() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	Vector3d<double> Module_Base_RPI3B::getAcceleration_g() const;
	///
	/// @brief	Gets acceleration g
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The acceleration g.

	Vector3d<double> getAcceleration_g() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	Vector3d<double> Module_Base_RPI3B::getVelocity_ms() const;
	///
	/// @brief	Gets velocity milliseconds
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The velocity milliseconds.

	Vector3d<double> getVelocity_ms() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	Vector3d<double> Module_Base_RPI3B::getLocation_m() const;
	///
	/// @brief	Gets location m
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The location m.

	Vector3d<double> getLocation_m() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	Vector3d<double> Module_Base_RPI3B::getRotation() const;
	///
	/// @brief	Gets the rotation
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The rotation.

	Vector3d<double> getRotation() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	Vector3d<double> Module_Base_RPI3B::getRotationRate_s() const;
	///
	/// @brief	Gets rotation rate s
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The rotation rate s.

	Vector3d<double> getRotationRate_s() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	Vector3d<double> Module_Base_RPI3B::getRotationAcceleration_s2() const;
	///
	/// @brief	Gets rotation acceleration s 2
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The rotation acceleration s 2.

	Vector3d<double> getRotationAcceleration_s2() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	float Module_Base_RPI3B::getIMUTemperature_degC() const;
	///
	/// @brief	Gets imu temperature degrees c
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The imu temperature degrees c.
	
	void getUnitVectors(Vector3d<double>& eX, Vector3d<double>& eY, Vector3d<double>& eZ);
	 			
	Vector3d<double> getEulerAngles() const;


	float getIMUTemperature_degC() const;

	~Module_Base_RPI3B();

private:
	//void updateIMUData();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void Module_Base_RPI3B::updateIMUTemperature();
	///
	/// @brief	Updates the imu temperature
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void updateIMUTemperature();

	///-------------------------------------------------------------------------------------------------
	/// @fn	void Module_Base_RPI3B::updateGyroData();
	///
	/// @brief	Updates the gyro data
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	void updateGyroData();
};


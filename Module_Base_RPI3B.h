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

///-------------------------------------------------------------------------------------------------
/// @class	BaseModuleController
///
/// @brief	Example of a module specific POCController class. This can be used to customize the controller by adding additional functionality
///
/// @author	Benjamin
/// @date	08.09.2020

class BaseModuleController : public POCController {
public:
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
	BaseModuleController pocController;

	PAC1720 pac;

	/// @brief	The inertial measurement unit located on this board
	BMI055IMU imu;

	/// @brief	The gyroscope located on this board
	BMI055Gyro gyro;


	/// @brief	The current coordinate system of this module, base point is the position of the imu
	CoordinateSystem3d<double> coordinateSystem;

	Vector3d<double> acceleration_g;
	Vector3d<double> velocity_ms;
	Vector3d<double> location_m;

	Vector3d<double> rotation;
	Vector3d<double> rotationRate_s;
	Vector3d<double> rotationAcceleration_s2;

	list<Vector3d<double>> rotation_History;

	float imuTemperature_degC;
public:

	Module_Base_RPI3B();
	void init();
	void selfTest();
	const uint16_t getId() const;
	const string getClassName() const;

	double getCurrentDrawHS();
	double getVoltageHS();
	double getPowerHS();
	double getCurrentDrawLS();
	double getVoltageLS();
	double getPowerLS();

	float getIMUBufferHealth() const;
	float getGyroBufferHealth() const;

	Vector3d<double> getAcceleration_g() const;
	Vector3d<double> getVelocity_ms() const;
	Vector3d<double> getLocation_m() const;

	Vector3d<double> getRotation() const;
	Vector3d<double> getRotationRate_s() const;
	Vector3d<double> getRotationAcceleration_s2() const;

	float getIMUTemperature_degC() const;

private:
	//void updateIMUData();
	void updateIMUTemperature();
	void updateGyroData();
};


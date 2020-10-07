///-------------------------------------------------------------------------------------------------
/// @file	POC\Module_Base_RPI3B.cpp.
///
/// @brief	Implements the module base rpi 3 b class

#include "Module_Base_RPI3B.h"

///-------------------------------------------------------------------------------------------------
/// @fn	Module_Base_RPI3B::Module_Base_RPI3B()
///
/// @brief	Default constructor
///
/// @author	Benjamin
/// @date	28.09.2020

Module_Base_RPI3B::Module_Base_RPI3B() : pocController("controller", 0x42, this, componentList),
	BasicPOCModule(getClassName(), shared_ptr<POCController>(&pocController)), 
	pac(this, componentList), imu(this, componentList),
	imuTemperature_degC(23),
	gyro(this, componentList),
	gyroTask(bind(&Module_Base_RPI3B::updateGyroData, this))
{
	
	//imu.init();
	gyro.init();
	gyroTask.start();
}

///-------------------------------------------------------------------------------------------------
/// @fn	void Module_Base_RPI3B::init()
///
/// @brief	Initializes this object
///
/// @author	Benjamin
/// @date	28.09.2020

void Module_Base_RPI3B::init() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void Module_Base_RPI3B::selfTest()
///
/// @brief	Tests self
///
/// @author	Benjamin
/// @date	28.09.2020

void Module_Base_RPI3B::selfTest() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	const uint16_t Module_Base_RPI3B::getId() const
///
/// @brief	Gets the identifier
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The identifier.

const uint16_t Module_Base_RPI3B::getId() const {
	return 0xB01;
}

///-------------------------------------------------------------------------------------------------
/// @fn	const string Module_Base_RPI3B::getClassName() const
///
/// @brief	Gets class name
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The class name.

const string Module_Base_RPI3B::getClassName() const {
	return "Raspberry 3B Base Module";
}

///-------------------------------------------------------------------------------------------------
/// @fn	double Module_Base_RPI3B::getCurrentDrawHS()
///
/// @brief	Gets current draw hs
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The current draw hs.

double Module_Base_RPI3B::getCurrentDrawHS() {
	return static_cast<double>(pac.getCurrentDrawHS()) * 10 / 2047;
}

///-------------------------------------------------------------------------------------------------
/// @fn	double Module_Base_RPI3B::getVoltageHS()
///
/// @brief	Gets voltage hs
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The voltage hs.

double Module_Base_RPI3B::getVoltageHS() {
	return static_cast<double>(pac.getVoltageHS()) * 0.01952;
}

///-------------------------------------------------------------------------------------------------
/// @fn	double Module_Base_RPI3B::getPowerHS()
///
/// @brief	Gets power hs
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The power hs.

double Module_Base_RPI3B::getPowerHS() {
	return static_cast<double>(pac.getPowerHS()) * 0.0061;
}

///-------------------------------------------------------------------------------------------------
/// @fn	double Module_Base_RPI3B::getCurrentDrawLS()
///
/// @brief	Gets current draw ls
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The current draw ls.

double Module_Base_RPI3B::getCurrentDrawLS() {
	return static_cast<double>(pac.getCurrentDrawLS()) * 10 / 2047;
}

///-------------------------------------------------------------------------------------------------
/// @fn	double Module_Base_RPI3B::getVoltageLS()
///
/// @brief	Gets voltage ls
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The voltage ls.

double Module_Base_RPI3B::getVoltageLS() {
	return static_cast<double>(pac.getVoltageLS()) * 0.01952;
}

///-------------------------------------------------------------------------------------------------
/// @fn	double Module_Base_RPI3B::getPowerLS()
///
/// @brief	Gets power ls
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The power ls.

double Module_Base_RPI3B::getPowerLS() {
	return static_cast<double>(pac.getPowerLS()) * 0.0061;
}

///-------------------------------------------------------------------------------------------------
/// @fn	void Module_Base_RPI3B::updateIMUTemperature()
///
/// @brief	/*void Module_Base_RPI3B::updateIMUData() {
/// 			  TODO mutex
/// 			static const double deltaTs = 0.001;
/// 			static const double deltaTs2 = pow(deltaTs, 2);
/// 		
/// 			queue<int> accelerationX;
/// 			queue<int> accelerationY;
/// 			queue<int> accelerationZ;
/// 		
/// 			while (true) {
/// 				imu.getAccelerationData(accelerationX, accelerationY, accelerationY);
/// 		
/// 				if(!accelerationX.empty())
/// 					acceleration_g.x = (double)accelerationX.back();
/// 				if(!accelerationY.empty())
/// 					acceleration_g.y = (double)accelerationY.back();
/// 				if(!accelerationZ.empty())
/// 					acceleration_g.z = (double)accelerationZ.back();
/// 		
/// 		
/// 				while (!accelerationX.empty()) {
/// 					velocity_ms.x += (double)accelerationX.front() * deltaTs / 1024;
/// 					location_m.x += (double)accelerationX.front() / 2 * deltaTs2 / 1024;
/// 					accelerationX.pop();
/// 				}
/// 		
/// 				while (!accelerationY.empty()) {
/// 					velocity_ms.y += (double)accelerationY.front() * deltaTs / 1024;
/// 					location_m.y += (double)accelerationY.front() / 2 * deltaTs2 / 1024;
/// 					accelerationY.pop();
/// 				}
/// 		
/// 				while (!accelerationZ.empty()) {
/// 					velocity_ms.z += (double)accelerationZ.front() * deltaTs / 1024;
/// 					location_m.z += (double)accelerationZ.front() / 2 * deltaTs2 / 1024;
/// 					accelerationZ.pop();
/// 				}
/// 		
/// 				usleep(500000);
/// 			}
/// 		}*/
///
/// @author	Benjamin
/// @date	28.09.2020

void Module_Base_RPI3B::updateIMUTemperature() {
	while (true) {
		imuTemperature_degC = (float)imu.getTemperature() * 0.5f + 23.0f;

		sleep(1);
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	void Module_Base_RPI3B::updateGyroData()
///
/// @brief	Updates the gyro data
///
/// @author	Benjamin
/// @date	28.09.2020

void Module_Base_RPI3B::updateGyroData() {
	queue<Vector3d<double>> rotationRatetemp;
	Vector3d<double> localRotationRate_s;
	
	int n = 0;

	const double deltaT_s = 1.0 / gyro.getBandwidth_hz();

	while (!shouldStop) {
		n = 0;

		gyro.getRotationRateData(rotationRatetemp);

		//if(!rotationRatetemp.empty())
		//rotationRate_s = rotationRatetemp.back() / 100;

		//numerically integrate rate of rotation to get current rotation 
		while (!rotationRatetemp.empty()) {
			Vector3d<double> eX, eY, eZ;
			coordinateSystem.getUnitVectors(eX, eY, eZ);
			
			localRotationRate_s = rotationRatetemp.front() - gyro.getRotationOffset();
			coordinateSystem.setRotationRate_s(eX * localRotationRate_s.getX() + eY * localRotationRate_s.getY() + eZ * localRotationRate_s.getZ());
			//coordinateSystem.setRotationRate_s(localRotationRate_s);
			coordinateSystem.update(deltaT_s);

			//cout << localRotationRate_s << endl;

			rotationRatetemp.pop();
			n++;
		}


		//cout << "=====================================" << endl;
		//rotationRate_s = rotationRateAvg / n;

		usleep(100000);
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	float Module_Base_RPI3B::getGyroBufferHealth() const
///
/// @brief	Gets gyro buffer health
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The gyro buffer health.

float Module_Base_RPI3B::getGyroBufferHealth() const {
	return gyro.getAvgBufferHealth();
}

///-------------------------------------------------------------------------------------------------
/// @fn	float Module_Base_RPI3B::getIMUBufferHealth() const
///
/// @brief	Gets imu buffer health
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The imu buffer health.

float Module_Base_RPI3B::getIMUBufferHealth() const {
	return imu.getAvgBufferHealth();
}

///-------------------------------------------------------------------------------------------------
/// @fn	Vector3d<double> Module_Base_RPI3B::getAcceleration_g() const
///
/// @brief	Gets acceleration g
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The acceleration g.

Vector3d<double> Module_Base_RPI3B::getAcceleration_g() const {
	//TODO
}
///-------------------------------------------------------------------------------------------------
/// @fn	Vector3d<double> Module_Base_RPI3B::getVelocity_ms() const
///
/// @brief	Gets velocity milliseconds
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The velocity milliseconds.

Vector3d<double> Module_Base_RPI3B::getVelocity_ms() const {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	Vector3d<double> Module_Base_RPI3B::getLocation_m() const
///
/// @brief	Gets location m
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The location m.

Vector3d<double> Module_Base_RPI3B::getLocation_m() const {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	Vector3d<double> Module_Base_RPI3B::getRotation() const
///
/// @brief	Gets the rotation
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The rotation.

Vector3d<double> Module_Base_RPI3B::getRotation() const {
	Vector3d<double> temp(coordinateSystem.getRotationGlobal());
	return temp;
}

///-------------------------------------------------------------------------------------------------
/// @fn	Vector3d<double> Module_Base_RPI3B::getRotationRate_s() const
///
/// @brief	Gets rotation rate s
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The rotation rate s.

Vector3d<double> Module_Base_RPI3B::getRotationRate_s() const {
	Vector3d<double> temp(coordinateSystem.getRotationRateGlobal_s());
	return temp;
}

///-------------------------------------------------------------------------------------------------
/// @fn	Vector3d<double> Module_Base_RPI3B::getRotationAcceleration_s2() const
///
/// @brief	Gets rotation acceleration s 2
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The rotation acceleration s 2.

Vector3d<double> Module_Base_RPI3B::getRotationAcceleration_s2() const {
	//TODO
}

void Module_Base_RPI3B::getUnitVectors(Vector3d<double>& eX, Vector3d<double>& eY, Vector3d<double>& eZ) {
	coordinateSystem.getUnitVectors(eX, eY, eZ);
}

Vector3d<double> Module_Base_RPI3B::getEulerAngles() const {
	return coordinateSystem.getEulerAngles();
}

///-------------------------------------------------------------------------------------------------
/// @fn	float Module_Base_RPI3B::getIMUTemperature_degC() const
///
/// @brief	Gets imu temperature degrees c
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The imu temperature degrees c.

float Module_Base_RPI3B::getIMUTemperature_degC() const {
	return imuTemperature_degC;
}

Module_Base_RPI3B::~Module_Base_RPI3B() {
	shouldStop = true;
}


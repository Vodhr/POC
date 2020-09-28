#include "Module_Base_RPI3B.h"

Module_Base_RPI3B::Module_Base_RPI3B() : pocController(0x42, this, componentList),
	BasicPOCModule(getClassName(), make_shared<POCController>(pocController)), 
	pac(this, componentList), imu(this, componentList),
	imuTemperature_degC(23),
	gyro(this, componentList)
{
	//imu.init();
	gyro.init();
	//move to init?
	//class updateThread? frequency, stopcondition
	//thread(&Module_Base_RPI3B::updateIMUData, this).detach();
	thread(&Module_Base_RPI3B::updateIMUTemperature, this).detach();
	thread(&Module_Base_RPI3B::updateGyroData, this).detach();
}

void Module_Base_RPI3B::init() {
	//TODO
}

void Module_Base_RPI3B::selfTest() {
	//TODO
}

const uint16_t Module_Base_RPI3B::getId() const {
	return 0xB01;
}

const string Module_Base_RPI3B::getClassName() const {
	return "Raspberry 3B Base Module";
}

double Module_Base_RPI3B::getCurrentDrawHS() {
	return static_cast<double>(pac.getCurrentDrawHS()) * 10 / 2047;
}

double Module_Base_RPI3B::getVoltageHS() {
	return static_cast<double>(pac.getVoltageHS()) * 0.01952;
}

double Module_Base_RPI3B::getPowerHS() {
	return static_cast<double>(pac.getPowerHS()) * 0.0061;
}

double Module_Base_RPI3B::getCurrentDrawLS() {
	return static_cast<double>(pac.getCurrentDrawLS()) * 10 / 2047;
}

double Module_Base_RPI3B::getVoltageLS() {
	return static_cast<double>(pac.getVoltageLS()) * 0.01952;
}

double Module_Base_RPI3B::getPowerLS() {
	return static_cast<double>(pac.getPowerLS()) * 0.0061;
}

/*void Module_Base_RPI3B::updateIMUData() {
	//TODO mutex
	static const double deltaTs = 0.001;
	static const double deltaTs2 = pow(deltaTs, 2);

	queue<int> accelerationX;
	queue<int> accelerationY;
	queue<int> accelerationZ;

	while (true) {
		imu.getAccelerationData(accelerationX, accelerationY, accelerationY);

		if(!accelerationX.empty())
			acceleration_g.x = (double)accelerationX.back();
		if(!accelerationY.empty())
			acceleration_g.y = (double)accelerationY.back();
		if(!accelerationZ.empty())
			acceleration_g.z = (double)accelerationZ.back();
		

		while (!accelerationX.empty()) {
			velocity_ms.x += (double)accelerationX.front() * deltaTs / 1024;
			location_m.x += (double)accelerationX.front() / 2 * deltaTs2 / 1024;
			accelerationX.pop();
		}

		while (!accelerationY.empty()) {
			velocity_ms.y += (double)accelerationY.front() * deltaTs / 1024;
			location_m.y += (double)accelerationY.front() / 2 * deltaTs2 / 1024;
			accelerationY.pop();
		}

		while (!accelerationZ.empty()) {
			velocity_ms.z += (double)accelerationZ.front() * deltaTs / 1024;
			location_m.z += (double)accelerationZ.front() / 2 * deltaTs2 / 1024;
			accelerationZ.pop();
		}

		usleep(500000);
	}
}*/

void Module_Base_RPI3B::updateIMUTemperature() {
	while (true) {
		imuTemperature_degC = (float)imu.getTemperature() * 0.5f + 23.0f;

		sleep(1);
	}
}

void Module_Base_RPI3B::updateGyroData() {
	queue<Vector3d<double>> rotationRatetemp;
	Vector3d<double> localRotationRate_s;
	
	int n = 0;

	const double deltaT_s = 1.0 / gyro.getBandwidth_hz();

	while (true) {
		n = 0;

		gyro.getRotationRateData(rotationRatetemp);

		//if(!rotationRatetemp.empty())
		//rotationRate_s = rotationRatetemp.back() / 100;

		//numerically integrate rate of rotation to get current rotation 
		while (!rotationRatetemp.empty()) {
			Vector3d<double> eX, eY, eZ;
			coordinateSystem.getUnitVectors(eX, eY, eZ);
			
			localRotationRate_s = rotationRatetemp.front() - gyro.getRotationOffset();
			rotationRate_s = eX * localRotationRate_s.getX() + eY * localRotationRate_s.getY() + eZ * localRotationRate_s.getZ();
			rotation += rotationRate_s * deltaT_s;
			coordinateSystem.rotate(rotationRate_s * deltaT_s);

			rotationRatetemp.pop();
			n++;
		}

		//rotationRate_s = rotationRateAvg / n;

		usleep(100000);
	}
}

float Module_Base_RPI3B::getGyroBufferHealth() const {
	return gyro.getAvgBufferHealth();
}

float Module_Base_RPI3B::getIMUBufferHealth() const {
	return imu.getAvgBufferHealth();
}

Vector3d<double> Module_Base_RPI3B::getAcceleration_g() const {
	return acceleration_g;
}

Vector3d<double> Module_Base_RPI3B::getVelocity_ms() const {
	return velocity_ms;
}

Vector3d<double> Module_Base_RPI3B::getLocation_m() const {
	return location_m;
}

Vector3d<double> Module_Base_RPI3B::getRotation() const {
	return rotation;
}

Vector3d<double> Module_Base_RPI3B::getRotationRate_s() const {
	return rotationRate_s;
}
Vector3d<double> Module_Base_RPI3B::getRotationAcceleration_s2() const {
	return rotationAcceleration_s2;
}

float Module_Base_RPI3B::getIMUTemperature_degC() const {
	return imuTemperature_degC;
}




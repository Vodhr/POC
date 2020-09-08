#pragma once
#include "I2CComponent.h"
#include <queue>
#include "Vector3d.h"

using namespace std;

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

class BMI055Gyro :
	public I2CComponent {
private:
	unsigned int bandwidth_hz;
	queue<unsigned char> avgBufferHealth;
	Vector3d<double> rotationRateOffset_s;
public:
	BMI055Gyro(BasicPOCModule* pocModule, list<Component*>& moduleList, unsigned int bandwidth_hz = 400);
	void init();
	void selfTest();
	void getRotationRateData(queue<Vector3d<double>>& q);
	float getAvgBufferHealth() const;
	Vector3d<double> getRotationOffset() const;
	unsigned int getBandwidth_hz() const;
};


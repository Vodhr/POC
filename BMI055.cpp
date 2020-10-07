///-------------------------------------------------------------------------------------------------
/// @file	POC\BMI055.cpp.
///
/// @brief	Implements the bmi 055 class

#include "BMI055.h"

///-------------------------------------------------------------------------------------------------
/// @fn	BMI055IMU::BMI055IMU(BasicPOCModule* pocModule, list<Component*>& componentList, unsigned int bandwidth_hz)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	pocModule	 	If non-null, the poc module.
/// @param [in,out]	componentList	[in,out] If non-null, list of components.
/// @param 		   	bandwidth_hz 	The bandwidth Hz.

BMI055IMU::BMI055IMU(BasicPOCModule* pocModule, list<Component*>& componentList, unsigned int bandwidth_hz) : 
	I2CComponent("BMI055 Acceleration Sensor", 0x18, false, 100000, pocModule, componentList), bandwidth_hz(bandwidth_hz) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	void BMI055IMU::init()
///
/// @brief	Initializes this object
///
/// @author	Benjamin
/// @date	28.09.2020

void BMI055IMU::init() {
	//reset
	//writeRegister(0x14, 0xB6);
	//TODO
	//Set FIFO mode to stream
	writeRegister(0x3E, 0b10000000);

	//Disable Filter, enable shadowing
	writeRegister(0x13, 0b11000000);

	//measurement range initially set to 2g

	//set bandwith to 2000Hz
	writeRegister(0x10, 0b00000001);

	//set power mode to normal
	writeRegister(0x11, 0b00000000);
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BMI055IMU::selfTest()
///
/// @brief	Tests self
///
/// @author	Benjamin
/// @date	28.09.2020

void BMI055IMU::selfTest() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BMI055IMU::getAccelerationData(queue<int>& accelerationX, queue<int>& accelerationY, queue<int>& accelerationZ)
///
/// @brief	Gets acceleration data
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	accelerationX	The acceleration x coordinate.
/// @param [in,out]	accelerationY	The acceleration y coordinate.
/// @param [in,out]	accelerationZ	The acceleration z coordinate.

void BMI055IMU::getAccelerationData(queue<int>& accelerationX, queue<int>& accelerationY, queue<int>& accelerationZ) {
	while(!accelerationX.empty()) accelerationX.pop();
	while(!accelerationY.empty()) accelerationY.pop();
	while(!accelerationZ.empty()) accelerationZ.pop();


	unsigned char readBuffer[31 * 3 * 2];
	unsigned char n = 0;
	n = readRegister(0x0E) & 0b01111111;

	//cout << "Reading " << (int)n << " Frames" << endl;

	//cout << "IMU AccX: " << (int)readRegister(0x02) << endl;
	//cout << "IMU AccX: " << (int)readRegister(0x03) << endl;
	//cout << "IMU Temp: " << (int)readRegister(0x08) << endl;
	

	readRegister(0x3F, readBuffer, n * 4 * 2);

	/*for (unsigned int i = 0; i < n * 3 * 2; i++) {
		readBuffer[i] = readRegister(0x3F);
	}*/

	for (unsigned int i = 0; i < n; i++) {
		accelerationX.push(readBuffer[6 * i + 1] << 8 | readBuffer[6 * i]);
		accelerationY.push(readBuffer[6 * i + 3] << 8 | readBuffer[6 * i + 2]);
		accelerationZ.push(readBuffer[6 * i + 5] << 8 | readBuffer[6 * i + 4]);
		//cout << "Processed frame " << i << " of " << (int)n << endl;
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	char BMI055IMU::getTemperature()
///
/// @brief	Gets the temperature
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The temperature.

char BMI055IMU::getTemperature() {
	return readRegister(0x08);
}

///-------------------------------------------------------------------------------------------------
/// @fn	float BMI055IMU::getAvgBufferHealth() const
///
/// @brief	Gets average buffer health
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The average buffer health.

float BMI055IMU::getAvgBufferHealth() const {
	float result = 0;

	queue<unsigned char> tmp = avgBufferHealth;

	while (!tmp.empty()) {
		result += tmp.front();
		tmp.pop();
	}

	return result / 100;
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int BMI055IMU::getBandwidth_hz() const
///
/// @brief	Gets bandwidth Hz
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The bandwidth Hz.

unsigned int BMI055IMU::getBandwidth_hz() const {
	return bandwidth_hz;
}

///-------------------------------------------------------------------------------------------------
/// @fn	BMI055Gyro::BMI055Gyro(BasicPOCModule* pocModule, list<Component*>& componentList, unsigned int bandwidth_hz)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	pocModule	 	If non-null, the poc module.
/// @param [in,out]	componentList	[in,out] If non-null, list of components.
/// @param 		   	bandwidth_hz 	The bandwidth Hz.

BMI055Gyro::BMI055Gyro(BasicPOCModule* pocModule, list<Component*>& componentList, unsigned int bandwidth_hz) :
	I2CComponent("BMI055 Gyro", 0x68, false, 100000, pocModule, componentList), bandwidth_hz(bandwidth_hz) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	void BMI055Gyro::init()
///
/// @brief	Initializes this object
///
/// @author	Benjamin
/// @date	28.09.2020

void BMI055Gyro::init() {
	//Range
	writeRegister(0x0F, 0b00000100);

	//set Bandwidth
	switch (bandwidth_hz) {
	case 100:
		writeRegister(0x10, 0b00000111);
		break;
	case 200:
		writeRegister(0x10, 0b00000110);
		break;
	case 400:
		writeRegister(0x10, 0b00000011);
		break;
	case 1000:
		writeRegister(0x10, 0b00000010);
		break;
	case 2000:
		writeRegister(0x10, 0b00000001);
		break;
	default:
		cout << "Unsupported Bandwidth Setting " << bandwidth_hz << ", using 400Hz instead" << endl;
		bandwidth_hz = 400;
		writeRegister(0x10, 0b00000011);
	}
	

	//filter
	writeRegister(0x13, 0b00000000);

	//FIFO Config -> Stream
	writeRegister(0x3E, 0b10000000);

	//calibrate (offset compensation)
	queue<Vector3d<double>> offsetData;

	queue<Vector3d<double>> temp;

	Vector3d<double> max;

	//dump fifo
	getRotationRateData(temp); 

	

	for (int i = 0; i < 100; i++) {	
		usleep(100000);

		getRotationRateData(temp);
		while (!temp.empty()) {
			if(temp.front().length() < 10) 
				offsetData.push(temp.front());
			if (temp.front() > max) max = temp.front();
			temp.pop();
		}
		cout << "calibrating (" << i << " of " << " 100)" << endl;
	}

	cout << "Collected " << offsetData.size() << " frames for offset calibration" << endl;
	cout << "Max: (" << max.getX() << ", " << max.getY() << ", " << max.getZ() << ")" << endl;

	int n = 0;

	Vector3d<double> offsetSum;

	while (!offsetData.empty()) {
		offsetSum += offsetData.front();
		offsetData.pop();
		n++;
	}

	rotationRateOffset_s = offsetSum / n;

	cout << "Offset is { " << rotationRateOffset_s.getX() << ", " << rotationRateOffset_s.getY() << ", " << rotationRateOffset_s.getZ() << " }" << endl;
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BMI055Gyro::selfTest()
///
/// @brief	Tests self
///
/// @author	Benjamin
/// @date	28.09.2020

void BMI055Gyro::selfTest() {
	//TODO
}

///-------------------------------------------------------------------------------------------------
/// @fn	void BMI055Gyro::getRotationRateData(queue<Vector3d<double>>& q)
///
/// @brief	Gets rotation rate data
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param [in,out]	q	A queue&lt;Vector3d&lt;double&gt;&gt; to process.

void BMI055Gyro::getRotationRateData(queue<Vector3d<double>>& q) {
	//one frame contains 6 bytes, 2 bytes of data for each axis
	const int framesize = 6;

	//Clear all queues 
	while (!q.empty()) q.pop();

	//Gyro FIFO holds a maximum of 100 frames. 
	unsigned char readBuffer[100 * framesize];
	
	//will hold the amount of frames currently in the FIFO buffer
	unsigned char n = 0;

	//get the amount of frames in the FIFO buffer
	n = readRegister(0x0E) & 0b01111111;

	//get n frames from the FIFO buffer
	readRegister(0x3F, readBuffer, n * framesize);

	//cout << (int)readBuffer[0] << ", " << (int)readBuffer[1] << endl;

	//assemble vectors and push into queue, divide by 262.4 for degrees or by 15034.4125 for radians
	for (unsigned char i = 0; i < n; i++) {
		Vector3d<double> temp{ static_cast<double>(static_cast<int16_t>((readBuffer[framesize * i + 1] << 8) | (readBuffer[framesize * i]))) / 15034.4125,
			static_cast<double>(static_cast<int16_t>((readBuffer[framesize * i + 3] << 8) | (readBuffer[framesize * i + 2]))) / 15034.4125,
			static_cast<double>(static_cast<int16_t>((readBuffer[framesize * i + 5] << 8) | (readBuffer[framesize * i + 4]))) / 15034.4125 };

		q.push(temp);
	}

	//push the amount of frames read
	avgBufferHealth.push(n);

	//make sure only 1000 buffer health values are stored
	while (avgBufferHealth.size() > 100) {
		avgBufferHealth.pop();
	}
}

///-------------------------------------------------------------------------------------------------
/// @fn	float BMI055Gyro::getAvgBufferHealth() const
///
/// @brief	Gets average buffer health
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The average buffer health.

float BMI055Gyro::getAvgBufferHealth() const {
	float result = 0;

	queue<unsigned char> tmp = avgBufferHealth;
	
	while (!tmp.empty()) {
		result += tmp.front();
		tmp.pop();
	}

	return result / 100;
}

///-------------------------------------------------------------------------------------------------
/// @fn	Vector3d<double> BMI055Gyro::getRotationOffset() const
///
/// @brief	Gets rotation offset
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The rotation offset.

Vector3d<double> BMI055Gyro::getRotationOffset() const {
	return rotationRateOffset_s;
}

///-------------------------------------------------------------------------------------------------
/// @fn	unsigned int BMI055Gyro::getBandwidth_hz() const
///
/// @brief	Gets bandwidth Hz
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	The bandwidth Hz.

unsigned int BMI055Gyro::getBandwidth_hz() const {
	return bandwidth_hz;
}
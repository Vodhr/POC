#pragma once
#include "BasicPOCModuleI2CComponent.h"

class BMI055 :
	public BasicPOCModuleI2CComponent
{
public:
	BMI055(BasicPOCModule* pocModule, list<BasicPOCModuleI2CComponent*>& componentList);
	void init();
	void selfTest();
	unsigned char getAccelerationData(int accelerationX[32], int accelerationY[32], int accelerationZ[32]);
};


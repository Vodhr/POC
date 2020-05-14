#include "BQ76952.h"

BQ76952::BQ76952(BasicPOCModule* itsPOCModule) : I2CDevice("BQ76952", 0x42, false, 100000), POCModuleComponent(itsPOCModule) {
	//TODO
}

void BQ76952::init() {
	//TODO
}

void BQ76952::selfTest() {
	//TODO
}

TimedState<Status5> BQ76952::getStatus5() {
	//TODO
	return status5;
}
#include "BQ76952.h"

BQ76952::BQ76952(BasicPOCModule* itsPOCModule, list<BasicPOCModuleI2CComponent*>& componentList) : BasicPOCModuleI2CComponent("BQ76952", 0x42, false, 100000, itsPOCModule, componentList) {
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
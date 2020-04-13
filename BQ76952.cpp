#include "BQ76952.h"

BQ76952::BQ76952() : I2CDevice("BQ76952", 0x42, false, 100000) {
	//TODO
}

void BQ76952::init() {
	//TODO
}

void BQ76952::selfTest() {
	//TODO
}

BQ76952::Status5 BQ76952::getStatus5() {
	//TODO
}
#pragma once
#include "BasicPOCModule.h"
#include "PowerLogger.h"
#include "POCController.h"
#include <list>

using namespace std;

class POCPowerModule : public BasicPOCModule {
private:
	static list<POCPowerModule&> moduleList;
	PowerLogger POWERLOGGER{ "Power Logger", 0x00 };
public:
	POCPowerModule();
	void init() final;
	void selfTest() final;
	double getPowerDraw();
	double getBatteryState();
	~POCPowerModule();
};


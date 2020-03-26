#pragma once
#include "BasicPOCModule.h"
#include <string>
#include <list>
#include "BDLCMotorDriver.h"

class POCMotorModule : public BasicPOCModule {
private:
	static list<POCMotorModule*> moduleList;
public:
	POCMotorModule();
	void init() final;
	void selfTest() final;
	~POCMotorModule();
};


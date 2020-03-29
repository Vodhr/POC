#include "POCPowerModule.h"
#include "POCMotorModule.h"
#include "BasicPOCModule.h"

using namespace std;

int main() {
	new POCPowerModule();
	new POCPowerModule();
	new POCMotorModule();

	new POCPowerModule();
	new POCPowerModule();
	new POCMotorModule();
	new POCMotorModule();
	new POCMotorModule();

	POCMotorModule* MOTORMODULE1 = new POCMotorModule();
	POCPowerModule POWERMODULE;

	BasicPOCModule::listAllModules();

	delete MOTORMODULE1;

	BasicPOCModule::listAllModules();

	string a;

	cin >> a;

	return 0;
}
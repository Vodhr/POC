#include "Module_Battery_Management_System.h"
#include "BasicPOCModule.h"

using namespace std;

int main() {
	Module_Battery_Management_System* BMS = new Module_Battery_Management_System();
	Module_Battery_Management_System* BMS2 = new Module_Battery_Management_System();
	BasicPOCModule::listAllModules();

	delete BMS;

	cout << "-------------------\n";

	BasicPOCModule::listAllModules();

	delete BMS2;

	string a;

	cin >> a;

	return 0;
}
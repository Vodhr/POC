#include "Module_Battery_Management_System.h"
#include "Module_Base_RPI3B.h"
#include "BasicPOCModule.h"
#include <iomanip>

using namespace std;

int main() {
	Module_Battery_Management_System* BMS = new Module_Battery_Management_System();
	Module_Battery_Management_System* BMS2 = new Module_Battery_Management_System();
	Module_Base_RPI3B BM1{};

	BasicPOCModule::listAllModules();

	delete BMS;

	cout << "-------------------\n";

	BasicPOCModule::listAllModules();

	//while (true) {
	//	BM1.activate();
	//	sleep(1);
	//	BM1.deactivate();
	//	sleep(1);
	//}

	double PowerHSAverage = 0;
	double PowerLSAverage = 0;

	while (true) {
		cout << dec << fixed << setprecision(5) << BM1.getCurrentDrawHS() << ", "
			<< BM1.getVoltageHS() << ", "
			<< BM1.getPowerHS() << ", "
			<< BM1.getCurrentDrawLS() << ", "
			<< BM1.getVoltageLS() << ", "
			<< BM1.getPowerLS() << ", "
			<< PowerLSAverage / PowerHSAverage
			<< endl;

		PowerHSAverage += BM1.getPowerHS();
		PowerLSAverage += BM1.getPowerLS();

		PowerHSAverage *= 0.99;
		PowerLSAverage *= 0.99;

		usleep(500000);
	}
	

	delete BMS2;

	string a;

	cin >> a;

	return 0;
}
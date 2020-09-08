#include "Module_Base_RPI3B.h"
#include "BasicPOCModule.h"
#include "Vector3d.h"
#include <iomanip>

using namespace std;

int main() {
	Module_Base_RPI3B BM1{};

	BasicPOCModule::listAllModules();

	cout << "-------------------\n";

	BasicPOCModule::listAllModules();

	while (true) {
		Vector3d<double> temp = BM1.getRotation();
		cout << temp << ", " << BM1.getGyroBufferHealth() << ", " << BM1.getIMUTemperature_degC() << endl;
		usleep(100000);
	}

	string a;

	cin >> a;

	return 0;
}
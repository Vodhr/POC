///-------------------------------------------------------------------------------------------------
/// @file	POC\main.cpp.
///
/// @brief	Implements the main class

#include "Module_Base_RPI3B.h"
#include "Module_Temperature_Measurement.h"
#include "BasicPOCModule.h"
#include "Vector3d.h"
#include <iomanip>

using namespace std;

///-------------------------------------------------------------------------------------------------
/// @fn	int main()
///
/// @brief	Main entry-point for this application
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @returns	Exit-code for the process - 0 for success, else an error code.

int main() {
	Vector3d<double> eX, eY, eZ;

	//Module_Base_RPI3B BM1{};
	Module_Temperature_Measurement TM{};
	

	//BasicPOCModule::listAllModules();

	cout << "-------------------\n";

	//BasicPOCModule::listAllModules();

	while (true) {
		/*BM1.getUnitVectors(eX, eY, eZ);
		Vector3d<double> temp = BM1.getEulerAngles();
		cout << eX << ", " << eY << ", " << eZ << ", " << BM1.getGyroBufferHealth() << ", " << BM1.getIMUTemperature_degC() << endl;
		cout << temp << endl;*/
		//cout << "Main Thread is still here" << endl;

		usleep(100000);
	}

	string a;

	cin >> a;

	return 0;
}
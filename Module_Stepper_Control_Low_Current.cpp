#include "Module_Stepper_Control_Low_Current.h"

Module_Stepper_Control_Low_Current::Module_Stepper_Control_Low_Current() : BasicPOCModule(getClassName(), 0x12) {

}

const uint16_t Module_Stepper_Control_Low_Current::getId() const {
	//TODO
	return 6001;
}

const string Module_Stepper_Control_Low_Current::getClassName() const {
	return "Stepper Control Low Current";
}

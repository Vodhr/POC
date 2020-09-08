#include "SPIComponent.h"
#include "BasicPOCModule.h"

SPIComponent::SPIComponent(string name, unsigned char slotNumber, bool cpha, bool cpol, long fmax, BasicPOCModule* itsPOCModule,
	list<Component*>& componentList) : 
	slotNr(slotNumber),
	Component(name, itsPOCModule), 
	SPI(cpha, cpol, fmax) {

	componentList.push_back(this);
}

void SPIComponent::transfere(char* buffer, int n) {
	//TODO
	


	SPI::transfere(buffer, n);
}

unsigned char SPIComponent::readRegister(unsigned char reg) {
	//TODO
	return 0;
}

void SPIComponent::readRegister(unsigned char reg, unsigned char readBuffer[], unsigned int n) {
	//TODO
}

void SPIComponent::writeRegister(unsigned char reg, unsigned char data) {
	//TODO
}

void SPIComponent::writeRegister(unsigned char reg, unsigned char writeBuffer[], unsigned int n) {
	//TODO
}

SPIComponent::~SPIComponent() {

}
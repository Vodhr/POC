#pragma once
#include "BasicPOCModule.h"
#include <list>
#include <memory>

class Module_Battery_Management_System :
	public BasicPOCModule {
public:
	class Cell {
	public:
		Cell(unsigned int number);
		Cell(unsigned int number, double maxVoltage);
		unsigned int getNumber();
		double getVoltage();
		double getMaxVoltage();
	private:
		double maxVoltage;
		unsigned int number;
	};

	list<shared_ptr<Cell>> cells;

	Module_Battery_Management_System();
	void init() final;
	void selfTest() final;
	const uint16_t getId() final;
	const string getClassName() final;

	void addCell(unsigned int cellNUmber);
	void removeCell(unsigned int cellNumber);
	void useAllCells();

	double getBatteryState();
	double getCellVoltage(unsigned int cellNumber);
	double getCurrentDraw();
};


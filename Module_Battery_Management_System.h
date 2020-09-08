#pragma once
#include <vector>
#include <memory>
#include "BasicPOCModule.h"
#include "BQ76952.h"

class Module_Battery_Management_System :
	public BasicPOCModule {
private:
	BQ76952 bq;

public:
	class Cell {
	private:
		bool isActive = true;
		double maxVoltage = 3.3;	//V
		double minVoltage = 0;		//V
		double maxCapacity = 1.8;	//Ah
		unsigned int number;
	public:
		Cell(unsigned int number);

		unsigned int getNumber();

		double getVoltage();

		void setMaxVoltage(double maxVoltage);
		double getMaxVoltage();

		void setMaxCapacity(double maxCapacity);
		double getMaxCapacity();

		void setMinVoltage(double minCapacity);
		double getMinVoltage();
		

		bool getIsActive();
		void activate();
		void deactivate();
	};

	Cell cell1{ 1 };
	Cell cell2{ 2 };
	Cell cell3{ 3 };
	Cell cell4{ 4 };
	Cell cell5{ 5 };
	Cell cell6{ 6 };
	Cell cell7{ 7 };
	Cell cell8{ 8 };

	vector<shared_ptr<Cell>> cells{
		make_shared<Cell>(cell1),
		make_shared<Cell>(cell2),
		make_shared<Cell>(cell3),
		make_shared<Cell>(cell4),
		make_shared<Cell>(cell5),
		make_shared<Cell>(cell6),
		make_shared<Cell>(cell7),
		make_shared<Cell>(cell8)
	};

	Module_Battery_Management_System();
	void init() final;
	void selfTest() final;
	const uint16_t getId() const final;
	const string getClassName() const final;

	double getBatteryCapacityLeft();
	double getBatteryMaxCapacity();
	double getBatteryState();
	double getCurrentDraw();
};


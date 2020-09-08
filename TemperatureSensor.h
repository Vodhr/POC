#pragma once
#include <shared_mutex>
#include "TimedState.h"
#include <chrono>

using namespace std;

class TemperatureSensor {
private:
	TimedState<double> temperature;

public:
	TemperatureSensor();
	TemperatureSensor(double temperature);
	TemperatureSensor(const TimedState<double>& temperature);

	void setTemperature(const TemperatureSensor& t);
	TimedState<double> getTemperature() const;
};



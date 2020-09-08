#include "TemperatureSensor.h"

TemperatureSensor::TemperatureSensor() : temperature(0) {

}

TemperatureSensor::TemperatureSensor(double temperature) : temperature(temperature) {

}

TemperatureSensor::TemperatureSensor(const TimedState<double>& temperature) : temperature(temperature) {

}

void TemperatureSensor::setTemperature(const TemperatureSensor& t) {
	mutex.lock();

	temperature = t.getTemperature();
	
	mutex.unlock();
}

TimedState<double> TemperatureSensor::getTemperature() const {
	mutex.lock();

	auto temp = temperature;

	mutex.unlock();

	return temp;
}



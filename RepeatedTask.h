///-------------------------------------------------------------------------------------------------
/// @file	POC\RepeatedTask.h.
///
/// @brief	Declares the repeated task class. If an object of this class is instantiated, 

#pragma once
#include <thread>
#include <functional>
#include <chrono>
#include <iostream>

using namespace std;

class RepeatedTask
{
private:
	bool shouldStop = false;
	thread t;
	function<void()> f;
	chrono::steady_clock::duration waitTime = chrono::milliseconds(1000);


public:
	RepeatedTask(const function<void()>& f, const chrono::steady_clock::duration& waitTime = chrono::milliseconds(1000));

	void start();

	void setWaitTime(const chrono::steady_clock::duration& waitTime);

	chrono::steady_clock::duration getWaitTime() const;
	
	virtual void stop();

	bool getShouldStop() const;

	~RepeatedTask();
};



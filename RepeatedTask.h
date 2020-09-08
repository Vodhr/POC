#pragma once
#include <thread>
#include <functional>

using namespace std;

class RepeatedTask : thread
{
	bool shouldStop = false;

	template<class T>
	RepeatedTask(function<T>& f);
	
	virtual void stop();
};

template<class T>
RepeatedTask::RepeatedTask(function<T>& f) : thread([this](Task* t) { while (!t->shouldStop) { f(); }}) {

}

//Stops the repeating task at the next opportunity and joins it with the current thread
void RepeatedTask::stop() {
	shouldStop = true;
	join();
}

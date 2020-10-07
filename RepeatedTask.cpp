#include "RepeatedTask.h"

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> RepeatedTask::RepeatedTask(function<T>& f)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @tparam	T	Generic type parameter.
/// @param [in,out]	f	A function&lt;T&gt; to process.

RepeatedTask::RepeatedTask(const function<void()>& f, const chrono::steady_clock::duration& waitTime) : 
	waitTime(waitTime), f(f) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	void RepeatedTask::setWaitTime(chrono::steady_clock::duration waitTime)
///
/// @brief	Sets wait time
///
/// @author	Benjamin
/// @date	01.10.2020
///
/// @param 	waitTime	The wait time.

void RepeatedTask::start() {
	t = thread([](const function<void()>& f, RepeatedTask* rt) {
		while (!rt->getShouldStop()) {
			//cout << "Executing repeated task" << endl;
			f();
			this_thread::sleep_for(rt->getWaitTime());
		}
		}, f, this);
	
	t.detach();
}

void RepeatedTask::setWaitTime(const chrono::steady_clock::duration& waitTime) {
	this->waitTime = waitTime;
}

chrono::steady_clock::duration RepeatedTask::getWaitTime() const {
	return waitTime;
}

///-------------------------------------------------------------------------------------------------
/// @fn	void RepeatedTask::stop()
///
/// @brief	Stops the repeating task at the next opportunity and joins it with the current thread
///
/// @author	Benjamin
/// @date	28.09.2020

void RepeatedTask::stop() {
	shouldStop = true;
	t.join();
}

bool RepeatedTask::getShouldStop() const {
	return shouldStop;
}

RepeatedTask::~RepeatedTask() {
	stop();
}
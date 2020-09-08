#pragma once
#include <chrono>
#include <shared_mutex>

using namespace std::chrono;
using namespace std;

template<class T>
class TimedState
{
private:
	mutable shared_mutex mutex;
protected:
	system_clock::time_point time;
	T state;
public:
	TimedState();
	TimedState(T state, system_clock::time_point time = system_clock::now());
	TimedState(const TimedState<T>& timedState);
	TimedState<T> get() const;
	void get(T& state, system_clock::time_point& time) const;
	void set(const TimedState<T>& timedState);
	T getState() const;		
	system_clock::time_point getTime() const;
	void operator=(const TimedState<T>& timedState);
	void operator=(const T& state);
};

template<class T>
TimedState<T>::TimedState() : time(system_clock::now()) {

}

template<class T>
TimedState<T>::TimedState(T state, system_clock::time_point time) : state(state), time(time) {

}

template<class T>
TimedState<T>::TimedState(const TimedState<T>& timedState) : time(timedState.getTime()), state(timedState.get()) {
	temp.set(timedState.get());
}

template<class T>
void TimedState<T>::get(T& state, system_clock::time_point& time) const {
	mutex.lock_shared();

	state = this->state;
	time = this->time;

	mutex.unlock_shared();
}

template<class T>
TimedState<T> TimedState<T>::get() const {
	mutex.lock_shared();

	TimedState<T> temp{ time, state };

	mutex.unlock_shared();

	return temp;
}

template<class T>
void TimedState<T>::set(const TimedState<T>& timedState) {
	T state;
	system_clock::time_point time;

	timedState.get(state, time);

	mutex.lock();

	this->state = state;
	this->time = time;

	mutex.unlock();
}

template<class T>
T TimedState<T>::getState() const {
	return state;
}

template<class T> 
system_clock::time_point TimedState<T>::getTime() const {
	return time;
}

template<class T>
void TimedState<T>::operator=(const TimedState<T>& timedState) {
	set(timedState);
}

template<class T>
void TimedState<T>::operator=(const T& state) {
	this->state = state;
	time = chrono::system_clock::now();
}


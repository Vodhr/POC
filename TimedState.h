#pragma once
#include <chrono>

using namespace std::chrono;

template<class T>
class TimedState
{
protected:
	system_clock::time_point time;
	T state;
public:
	TimedState();
	TimedState(T state, system_clock::time_point time);
	TimedState(TimedState<T>& timedState);
	system_clock::time_point getTime();
	T getState();
};

template<class T>
TimedState<T>::TimedState() : time(system_clock::now()) {

}

template<class T>
TimedState<T>::TimedState(T state, system_clock::time_point time) : state(state), time(time) {

}

template<class T>
TimedState<T>::TimedState(TimedState<T>& timedState) : time(timedState.getTime()), state(timedState.getState()) {

}

template<class T>
system_clock::time_point TimedState<T>::getTime() {
	return system_clock::time_point(time);
}

template<class T>
T TimedState<T>::getState() {
	return T(state);
}


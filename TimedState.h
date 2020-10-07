///-------------------------------------------------------------------------------------------------
/// @file	POC\TimedState.h.
///
/// @brief	Declares the timed state class

#pragma once
#include <chrono>
#include <shared_mutex>

using namespace std::chrono;
using namespace std;

///-------------------------------------------------------------------------------------------------
/// @class	TimedState
///
/// @brief	A timed state.
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @tparam	T	Generic type parameter.

template<class T>
class TimedState
{
private:

	///-------------------------------------------------------------------------------------------------
	/// @property	mutable shared_mutex mutex
	///
	/// @brief	Gets or sets the mutex
	///
	/// @returns	The mutex.

	mutable shared_mutex mutex;
protected:
	/// @brief	The time
	system_clock::time_point time;
	/// @brief	The state
	T state;
public:

	///-------------------------------------------------------------------------------------------------
	/// @fn	TimedState::TimedState();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	TimedState();

	///-------------------------------------------------------------------------------------------------
	/// @fn	TimedState::TimedState(T state, system_clock::time_point time = system_clock::now());
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	state	The state.
	/// @param 	time 	(Optional) The time.

	TimedState(T state, system_clock::time_point time = system_clock::now());

	///-------------------------------------------------------------------------------------------------
	/// @fn	TimedState::TimedState(const TimedState<T>& timedState);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	timedState	State of the timed.

	TimedState(const TimedState<T>& timedState);

	///-------------------------------------------------------------------------------------------------
	/// @fn	TimedState<T> TimedState::get() const;
	///
	/// @brief	Gets the get
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	A TimedState&lt;T&gt;

	TimedState<T> get() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void TimedState::get(T& state, system_clock::time_point& time) const;
	///
	/// @brief	Gets
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param [in,out]	state	The state.
	/// @param [in,out]	time 	The time.

	void get(T& state, system_clock::time_point& time) const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void TimedState::set(const TimedState<T>& timedState);
	///
	/// @brief	Sets the given timed state
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	timedState	The timed state to set.

	void set(const TimedState<T>& timedState);

	///-------------------------------------------------------------------------------------------------
	/// @fn	T TimedState::getState() const;
	///
	/// @brief	Gets the state
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The state.

	T getState() const;		

	///-------------------------------------------------------------------------------------------------
	/// @fn	system_clock::time_point TimedState::getTime() const;
	///
	/// @brief	Gets the time
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @returns	The time.

	system_clock::time_point getTime() const;

	///-------------------------------------------------------------------------------------------------
	/// @fn	void TimedState::operator=(const TimedState<T>& timedState);
	///
	/// @brief	Assignment operator
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	timedState	State of the timed.

	void operator=(const TimedState<T>& timedState);

	///-------------------------------------------------------------------------------------------------
	/// @fn	void TimedState::operator=(const T& state);
	///
	/// @brief	Assignment operator
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	state	The state.

	void operator=(const T& state);
};

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> TimedState<T>::TimedState() : time(system_clock::now())
///
/// @brief	Default constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @tparam	T	Generic type parameter.

template<class T>
TimedState<T>::TimedState() : time(system_clock::now()) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> TimedState<T>::TimedState(T state, system_clock::time_point time)
///
/// @brief	Constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @tparam	T	Generic type parameter.
/// @param 	state	The state.
/// @param 	time 	The time.

template<class T>
TimedState<T>::TimedState(T state, system_clock::time_point time) : state(state), time(time) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> TimedState<T>::TimedState(const TimedState<T>& timedState)
///
/// @brief	Copy constructor
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @tparam	T	Generic type parameter.
/// @param 	timedState	State of the timed.

template<class T>
TimedState<T>::TimedState(const TimedState<T>& timedState) : time(timedState.getTime()), state(timedState.getState()) {

}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> void TimedState<T>::get(T& state, system_clock::time_point& time) const
///
/// @brief	Gets
///
/// @tparam	T	Generic type parameter.
/// @param [in,out]	state	The state.
/// @param [in,out]	time 	The time.

template<class T>
void TimedState<T>::get(T& state, system_clock::time_point& time) const {

	///-------------------------------------------------------------------------------------------------
	/// @fn	mutex.lock_shared();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	mutex.lock_shared();

	///< An enum constant representing the state option
	state = this->state;
	///< An enum constant representing the time option
	time = this->time;

	///-------------------------------------------------------------------------------------------------
	/// @fn	mutex.unlock_shared();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	mutex.unlock_shared();
}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> TimedState<T> TimedState<T>::get() const
///
/// @brief	Gets the get
///
/// @tparam	T	Generic type parameter.
///
/// @returns	A TimedState&lt;T&gt;

template<class T>
TimedState<T> TimedState<T>::get() const {

	///-------------------------------------------------------------------------------------------------
	/// @fn	mutex.lock_shared();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	mutex.lock_shared();

	/// @brief	The temporary
	TimedState<T> temp{ time, state };

	///-------------------------------------------------------------------------------------------------
	/// @fn	mutex.unlock_shared();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	mutex.unlock_shared();

	return temp;
}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> void TimedState<T>::set(const TimedState<T>& timedState)
///
/// @brief	Sets the given timed state
///
/// @tparam	T	Generic type parameter.
/// @param 	timedState	State of the timed.

template<class T>
void TimedState<T>::set(const TimedState<T>& timedState) {
	/// @brief	The state
	T state;
	/// @brief	The time
	system_clock::time_point time;

	///-------------------------------------------------------------------------------------------------
	/// @fn	timedState.get(state parameter1, time parameter2);
	///
	/// @brief	Constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	parameter1	The first parameter.
	/// @param 	parameter2	The second parameter.

	timedState.get(state, time);

	///-------------------------------------------------------------------------------------------------
	/// @fn	mutex.lock();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	mutex.lock();

	/// @brief	.
	this->state = state;
	/// @brief	.
	this->time = time;

	///-------------------------------------------------------------------------------------------------
	/// @fn	mutex.unlock();
	///
	/// @brief	Default constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020

	mutex.unlock();
}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> T TimedState<T>::getState() const
///
/// @brief	Gets the state
///
/// @tparam	T	Generic type parameter.
///
/// @returns	The state.

template<class T>
T TimedState<T>::getState() const {
	return state;
}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> system_clock::time_point TimedState<T>::getTime() const
///
/// @brief	Gets the time
///
/// @tparam	T	Generic type parameter.
///
/// @returns	The time.

template<class T> 
system_clock::time_point TimedState<T>::getTime() const {
	return time;
}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> void TimedState<T>::operator=(const TimedState<T>& timedState)
///
/// @brief	Assignment operator
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	timedState	State of the timed.

template<class T>
void TimedState<T>::operator=(const TimedState<T>& timedState) {

	///-------------------------------------------------------------------------------------------------
	/// @fn	set(timedState parameter1);
	///
	/// @brief	Copy constructor
	///
	/// @author	Benjamin
	/// @date	28.09.2020
	///
	/// @param 	parameter1	The parameter 1 to set.

	set(timedState);
}

///-------------------------------------------------------------------------------------------------
/// @fn	template<class T> void TimedState<T>::operator=(const T& state)
///
/// @brief	Assignment operator
///
/// @author	Benjamin
/// @date	28.09.2020
///
/// @param 	state	The state.

template<class T>
void TimedState<T>::operator=(const T& state) {
	/// @brief	.
	this->state = state;
	///< An enum constant representing the time option
	time = chrono::system_clock::now();
}


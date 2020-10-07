///-------------------------------------------------------------------------------------------------
/// @file	POC\Vector3d.h.
///
/// @brief	Declares the vector 3D class

#pragma once
#include <shared_mutex>
#include <iostream>
#include <math.h>

using namespace std;

template<class T>
class Vector3d
{
private:

	T x, y, z;

	mutable shared_mutex mtx;

public:

	Vector3d() : x(0), y(0), z(0) {

	}

	Vector3d(T x, T y, T z) : x(x), y(y), z(z) {

	}

	Vector3d(const Vector3d<T>& vector) {
		set(vector);
	}

	Vector3d<T> get() const;

	void get(T& x, T& y, T& z) const;

	void set(const Vector3d<T>& vector);

	T getX() const;

	T getY() const;

	T getZ() const;

	double length() const;

	void operator=(const Vector3d<T>& vector);

	Vector3d<T> operator+(const Vector3d<T>& vector) const;

	Vector3d<T> operator-(const Vector3d<T>& vector) const;

	Vector3d<T> operator/(double d) const;

	Vector3d<T> operator*(double m) const;

	double operator*(const Vector3d<T>& vector) const;

	void operator+=(const Vector3d<T>& vector);

	void operator-=(const Vector3d<T>& vector);

	bool operator<(const Vector3d<T>& vector) const;

	bool operator>(const Vector3d<T>& vector) const;

	Vector3d<T> cross(const Vector3d<T>& vector) const;

	Vector3d<T> rotate(const Vector3d<T>& vector) const;

	Vector3d<T> normal() const;

	template<class R>
	friend ostream& operator<<(ostream& os, const Vector3d<R> vector);
};

template<class T> 
Vector3d<T> Vector3d<T>::get() const {

	mtx.lock_shared();		//several processes can read at once while no prosess is writing


	Vector3d<T> temp{ x, y, z };

	mtx.unlock_shared();

	return temp;
}

template<class T>
void Vector3d<T>::get(T& x, T& y, T& z) const { 

	mtx.lock_shared();		//only one process can write at a time


	x = this->x;

	y = this->y;

	z = this->z;

	mtx.unlock_shared();
}

template<class T>
void Vector3d<T>::set(const Vector3d<T>& vector) {

	T x, y, z;

	vector.get(x, y, z);

	mtx.lock();


	this->x = x;

	this->y = y;

	this->z = z;

	mtx.unlock();
}

template<class T> 
double Vector3d<T>::length() const{

	Vector3d<T> temp(get());

	return sqrt(pow(temp.getX(), 2) + pow(temp.getY(), 2) + pow(temp.getZ(), 2));
}

template<class T>
void Vector3d<T>::operator=(const Vector3d<T>& vector) {

	set(vector);
}
template<class T>
T Vector3d<T>::getX() const {
	return x;
}

template<class T>
T Vector3d<T>::getY() const {
	return y;
}

template<class T>
T Vector3d<T>::getZ() const {
	return z;
}

template<class T>
Vector3d<T> Vector3d<T>::operator+(const Vector3d<T>& vector) const {

	T x, y, z;

	vector.get(x, y, z);

	mtx.lock_shared();


	Vector3d<T> result{ this->x + x, this->y + y, this->z + z };

	mtx.unlock_shared();

	return result;
}

template<class T>
Vector3d<T> Vector3d<T>::operator-(const Vector3d<T>& vector) const {

	T x, y, z;

	vector.get(x, y, z);

	mtx.lock_shared();


	Vector3d<T> result{ this->x - x, this->y - y, this->z - z };

	mtx.unlock_shared();

	return result;
}

template<class T>
Vector3d<T> Vector3d<T>::operator/(double d) const {

	mtx.lock_shared();


	Vector3d<T> result{ x / d, y / d, z / d };

	mtx.unlock_shared();

	return result;
}

template<class T>
Vector3d<T> Vector3d<T>::operator*(double m) const {

	mtx.lock_shared();


	Vector3d<T> result{ x * m, y * m, z * m };

	mtx.unlock_shared();

	return result;
}

template<class T>
double Vector3d<T>::operator*(const Vector3d<T>& vector) const {

	T x, y, z;

	vector.get(x, y, z);

	mtx.lock_shared();


	double result = this->x * x + this->y * y + this->z * z;

	mtx.unlock_shared();

	return result;
}

template<class T>
void Vector3d<T>::operator+=(const Vector3d<T>& vector) {

	T x, y, z;

	vector.get(x, y, z);

	mtx.lock();


	this->x += x;

	this->y += y;

	this->z += z;

	mtx.unlock();
}

template<class T>
void Vector3d<T>::operator-=(const Vector3d<T>& vector) {

	T x, y, z;

	vector.get(x, y, z);

	mtx.lock();


	this->x -= x;

	this->y -= y;

	this->z -= z;

	mtx.unlock();
}

template<class T>
bool Vector3d<T>::operator<(const Vector3d<T>& vector) const {
	return length() < vector.length();
}

template<class T>
bool Vector3d<T>::operator>(const Vector3d<T>& vector) const {
	return length() > vector.length();
}

template<class T>
Vector3d<T> Vector3d<T>::cross(const Vector3d<T>& vector) const {

	T x, y, z;

	vector.get(x, y, z);

	mtx.lock_shared();


	Vector3d<T> result{ this->y * z - this->z * y, this->z * x - this->x * z, this->x * y - this->y * x };

	mtx.unlock_shared();

	return result;
}

template<class T>
Vector3d<T> Vector3d<T>::rotate(const Vector3d<T>& v) const {

	Vector3d<T> a(*this);

	if (a * v == 0) {
		//cout << "vectors are aligned" << endl;
		return a;
	}

	Vector3d<T> c = v.normal() * (a * v) / v.length();
	Vector3d<T> d = a - c;

	Vector3d<T> result = c + d * cos(v.length()) + v.cross(d) / v.length() * sin(v.length());

	return result;
}

template<class T>
Vector3d<T> Vector3d<T>::normal() const {
	auto temp(*this);
	return temp / temp.length();
}

template<class R>
ostream& operator<<(ostream& os, Vector3d<R> vector) {

	Vector3d<R> temp = vector.get();

	os << "(" << temp.getX() << ", " << temp.getY() << ", " << temp.getZ() << ")";
	return os;
}


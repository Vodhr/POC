#pragma once
#include "Vector3d.h"
#include <vector>
#include <shared_mutex>

using namespace std;

template<class T>
class CoordinateSystem3d
{
private:
    mutable shared_mutex mutex;

    const Vector3d<T> eX = { 1, 0, 0 }, eY = { 0, 1, 0 }, eZ = { 0, 0, 1 };
    CoordinateSystem3d<T>* base;
    Vector3d<T> rotationToBase;
    Vector3d<T> translationToBase;

public:
    CoordinateSystem3d(CoordinateSystem3d<T>* base = nullptr, Vector3d<T> rotationToBase = { 0, 0, 0 }, Vector3d<T> translationToBase = { 0, 0, 0 });
    void getUnitVectors(Vector3d<T>& eX, Vector3d<T>& eY, Vector3d<T>& eZ) const;

    void setRotation(const Vector3d<T>& axis);

    void rotate(const Vector3d<T>& axis);

    Vector3d<T> getInBase(const Vector3d<T>& vector) const;
};

template<class T>
CoordinateSystem3d<T>::CoordinateSystem3d(CoordinateSystem3d<T>* base, Vector3d<T> rotationToBase, Vector3d<T> translationToBase) : base(base), rotationToBase(rotationToBase), translationToBase(translationToBase) {

}

template<class T>
void CoordinateSystem3d<T>::getUnitVectors(Vector3d<T>& eX, Vector3d<T>& eY, Vector3d<T>& eZ) const{
    mutex.lock_shared();

    eX = this->eX.rotate(rotationToBase);
    eY = this->eY.rotate(rotationToBase);
    eZ = this->eZ.rotate(rotationToBase);

    mutex.unlock_shared();
}

template<class T> 
void CoordinateSystem3d<T>::setRotation(const Vector3d<T>& axis) {
    mutex.lock();

    this->rotationToBase = axis;

    mutex.unlock();
}

template<class T>
void CoordinateSystem3d<T>::rotate(const Vector3d<T>& axis) {
    mutex.lock();

    this->rotationToBase += axis;

    mutex.unlock();
}

template<class T>
Vector3d<T> CoordinateSystem3d<T>::getInBase(const Vector3d<T>& vector) const {
    mutex.lock_shared();

    Vector3d<T> temp = vector.rotate(rotationToBase) + translationToBase;

    mutex.unlock_shared();

    return temp;
}


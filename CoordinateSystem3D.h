///-------------------------------------------------------------------------------------------------
/// @file	POC\CoordinateSystem3D.h.
///
/// @brief	Declares the coordinate system 3D class

#pragma once
#include "Vector3d.h"
#include <vector>
#include <shared_mutex>
#include <memory>
#include <cmath>

using namespace std;

template<class T>
class CoordinateSystem3d
{
private:
    mutable shared_mutex mutex;

    Vector3d<T> eX = { 1, 0, 0 }, eY = { 0, 1, 0 }, eZ = { 0, 0, 1 };
    shared_ptr<CoordinateSystem3d<T>> base;

    Vector3d<T> rotationGlobal;
    Vector3d<T> rotationRateGlobal_s;
    Vector3d<T> rotationAccellerationGlobal_s2;
    Vector3d<T> translationGlobal_m;
    Vector3d<T> velocityGlobal_ms;
    Vector3d<T> accellerationGlobal_ms2;

public:

    CoordinateSystem3d(shared_ptr<CoordinateSystem3d<T>> base = nullptr, Vector3d<T> rotationGlobal = { 0, 0, 0 }, Vector3d<T> translationGlobal = { 0, 0, 0 });

    CoordinateSystem3d(shared_ptr<CoordinateSystem3d<T>> base,
        const Vector3d<T>& rotationGlobal,
        const Vector3d<T>& rotationRateGlobal_s,
        const Vector3d<T>& rotationAccellerationGlobal_s2,
        const Vector3d<T>& translationGlobal_m,
        const Vector3d<T>& velocityGlobal_ms,
        const Vector3d<T>& accellerationGlobal_ms2);

    CoordinateSystem3d(const CoordinateSystem3d<T>& coordinateSystem);

    void getUnitVectors(Vector3d<T>& eX, Vector3d<T>& eY, Vector3d<T>& eZ) const;

    CoordinateSystem3d<T> get() const;

    Vector3d<T> getRotationGlobal() const;

    Vector3d<T> getRotationRateGlobal_s() const;

    Vector3d<T> getRotationAccellerationGlobal_s2() const;

    Vector3d<T> getTranslationGlobal_m() const;

    Vector3d<T> getVelocityGlobal_ms() const;

    Vector3d<T> getAccellerationGlobal_ms2() const;

    void update(const double& deltaT_s);

    void setRotation(const Vector3d<T>& axis);

    void setRotationRate_s(const Vector3d<T>& axis);

    Vector3d<double> getEulerAngles() const;

    void rotate(const Vector3d<T>& axis);

    void reset();
};

template<class T>
CoordinateSystem3d<T>::CoordinateSystem3d(shared_ptr<CoordinateSystem3d<T>> base, Vector3d<T> rotationGlobal, Vector3d<T> translationGlobal_m) : base(base), rotationGlobal(rotationGlobal), translationGlobal_m(translationGlobal_m) {

}

template<class T>
CoordinateSystem3d<T>::CoordinateSystem3d(shared_ptr<CoordinateSystem3d<T>> base,
    const Vector3d<T>& rotationGlobal,
    const Vector3d<T>& rotationRateGlobal_s,
    const Vector3d<T>& rotationAccellerationGlobal_s2,
    const Vector3d<T>& translationGlobal_m,
    const Vector3d<T>& velocityGlobal_ms,
    const Vector3d<T>& accellerationGlobal_ms2) 
{
    mutex.lock();

    this->base = base;
    this->rotationGlobal = rotationGlobal;
    this->rotationRateGlobal_s = rotationRateGlobal_s;
    this->rotationAccellerationGlobal_s2 = rotationAccellerationGlobal_s2;
    this->translationGlobal_m = translationGlobal_m;
    this->velocityGlobal_ms = velocityGlobal_ms;
    this->accellerationGlobal_ms2 = accellerationGlobal_ms2;

    mutex.unlock();
}

template<class T>
CoordinateSystem3d<T>::CoordinateSystem3d(const CoordinateSystem3d<T>& coordinateSystem) {
    //TODO
}

template<class T>
Vector3d<T> CoordinateSystem3d<T>::getRotationGlobal() const { return rotationGlobal; }

template<class T>
Vector3d<T> CoordinateSystem3d<T>::getRotationRateGlobal_s() const { return rotationRateGlobal_s; }

template<class T>
Vector3d<T> CoordinateSystem3d<T>::getRotationAccellerationGlobal_s2() const { return rotationAccellerationGlobal_s2; }

template<class T>
Vector3d<T> CoordinateSystem3d<T>::getTranslationGlobal_m() const { return translationGlobal_m; }

template<class T>
Vector3d<T> CoordinateSystem3d<T>::getVelocityGlobal_ms() const { return velocityGlobal_ms; }

template<class T>
Vector3d<T> CoordinateSystem3d<T>::getAccellerationGlobal_ms2() const { return accellerationGlobal_ms2; }

template<class T>
void CoordinateSystem3d<T>::getUnitVectors(Vector3d<T>& eX, Vector3d<T>& eY, Vector3d<T>& eZ) const {

    mutex.lock_shared();

    eX = this->eX;
    eY = this->eY;
    eZ = this->eZ;

    mutex.unlock_shared();
}

template<class T>
CoordinateSystem3d<T> CoordinateSystem3d<T>::get() const {

}

template<class T>
void CoordinateSystem3d<T>::update(const double& deltaT_s) {
    rotate(rotationRateGlobal_s * deltaT_s);
}

template<class T> 
void CoordinateSystem3d<T>::setRotation(const Vector3d<T>& axis) {
    reset();
    rotate(axis);
}

template<class T>
void CoordinateSystem3d<T>::setRotationRate_s(const Vector3d<T>& axis) {
    mutex.lock();

    this->rotationRateGlobal_s = axis;

    mutex.unlock();
}

template<class T>
void CoordinateSystem3d<T>::rotate(const Vector3d<T>& axis) {

    mutex.lock();

    eX = eX.rotate(axis);
    eY = eY.rotate(axis);
    eZ = eZ.rotate(axis);

    mutex.unlock();
}

template<class T>
Vector3d<double> CoordinateSystem3d<T>::getEulerAngles() const {

    Vector3d<T> eXtemp;
    Vector3d<T> eYtemp;
    Vector3d<T> eZtemp;

    getUnitVectors(eXtemp, eYtemp, eZtemp);

    Vector3d<double> temp(atan2(eXtemp.getZ(), eXtemp.getX()), atan2(eXtemp.getY(), eXtemp.getX()), atan2(eYtemp.getZ(), eYtemp.getY()));
    
    return temp * 180 / M_PI;
}

template<class T>
void CoordinateSystem3d<T>::reset() {
    mutex.lock();

    eX = { 1, 0, 0 };
    eY = { 0, 1, 0 };
    eZ = { 0, 0, 1 };

    mutex.unlock();
}


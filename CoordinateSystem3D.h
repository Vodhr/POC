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

    const Vector3d<T> eX = { 1, 0, 0 }, eY = { 0, 1, 0 }, eZ = { 0, 0, 1 };
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

    Vector3d<T> getRotationGlobal() { return rotationGlobal; }
    Vector3d<T> getRotationRateGlobal_s() { return rotationRateGlobal_s; }
    Vector3d<T> getRotationAccellerationGlobal_s2() { return rotationAccellerationGlobal_s2; }
    Vector3d<T> getTranslationGlobal_m() { return translationGlobal_m; }
    Vector3d<T> getVelocityGlobal_ms() { return velocityGlobal_ms; }
    Vector3d<T> getAccellerationGlobal_ms2() { return accellerationGlobal_ms2; }

    void setRotation(const Vector3d<T>& axis);

    Vector3d<double> getEulerAngles() const;

    void rotate(const Vector3d<T>& axis);
};

template<class T>
CoordinateSystem3d<T>::CoordinateSystem3d(shared_ptr<CoordinateSystem3d<T>> base, Vector3d<T> rotationGlobal, Vector3d<T> translationGlobal_m) : base(base), rotationGlobal(rotationToBase), translationGlobal_m(translationToBase) {

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
void CoordinateSystem3d<T>::getUnitVectors(Vector3d<T>& eX, Vector3d<T>& eY, Vector3d<T>& eZ) const{
    mutex.lock_shared();

    eX = this->eX.rotate(rotationGlobal);
    eY = this->eY.rotate(rotationGlobal);
    eZ = this->eZ.rotate(rotationGlobal);

    mutex.unlock_shared();
}

template<class T>
CoordinateSystem3d<T> CoordinateSystem3d<T>::get() const {

}

template<class T> 
void CoordinateSystem3d<T>::setRotation(const Vector3d<T>& axis) {
    mutex.lock();

    this->rotationGlobal = axis;

    mutex.unlock();
}

template<class T>
void CoordinateSystem3d<T>::rotate(const Vector3d<T>& axis) {
    mutex.lock();

    this->rotationGlobal += axis;

    mutex.unlock();
}

template<class T>
Vector3d<double> CoordinateSystem3d<T>::getEulerAngles() const {
    mutex.lock_shared();

    Vector<T> eXtemp = eX;
    Vector<T> eYtemp = eY;

    Vector3d<double> temp(atan2(eXtemp.getZ(), eXtemp.getX()), atan2(eXtemp.getY(), eXtemp.getX()), atan2(eYtemp.getZ(), eYtemp.getY());

    mutex.unlock_shared();
    

    return temp;
}




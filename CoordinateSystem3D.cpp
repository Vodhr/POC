#include "CoordinateSystem3D.h"

CoordinateSystem3d::CoordinateSystem3d(CoordinateSystem3d* base, Vector3d<double> rotationToBase, Vector3d<double> translationToBase) : base(base), rotationToBase(rotationToBase), translationToBase(translationToBase) {

}

Vector3d<double> CoordinateSystem3d::getEX() const {
	return eX.rotate(rotationToBase);
}

Vector3d<double> CoordinateSystem3d::getEY() const {
	return eY.rotate(rotationToBase); 
}

Vector3d<double> CoordinateSystem3d::getEZ() const {
	return eZ.rotate(rotationToBase);
}

void CoordinateSystem3d::setRotation(const Vector3d<double> axis) {
	rotationToBase = axis;
}

void CoordinateSystem3d::rotate(const Vector3d<double> axis) {
	rotationToBase += axis;
}
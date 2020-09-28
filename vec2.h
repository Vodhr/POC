#pragma once
#include <atomic>

using namespace std;

template<class T>
class vec2
{
private:
    T x, y, z;
public:
    T getX() {
        return x;
    }
    T getY() {
        return y;
    }
    T getZ() {
        return z;
    }

    vec2<T> operator+(const vec2<T>& vector) {
        vec2<T> temp(*this);
        vec2<T> temp2(vector);
        return vec2<T> {temp.getX() + temp2.getX(), temp.getY() + temp2.getY(), temp.getZ() + temp2.getZ()};
    }

    vec2<T> operator-(const vec2<T>& vector) {
        vec2<T> temp(*this);
        vec2<T> temp2(vector);
        return vec2<T> {temp.getX() - temp2.getX(), temp.getY() - temp2.getY(), temp.getZ() - temp2.getZ()};
    }

    vec2<T> operator*(const double& d) {
        vec2<T> temp(*this);
        return vec2<T> {temp.getX() * d, temp.getY() * d, temp.getZ() * d};
    }

    vec2<T> operator/(const double& d) {
        vec2<T> temp(*this);
        return vec2<T> {temp.getX() / d, temp.getY() / d, temp.getZ() / d};
    }

    void operator+=(const vec2& vector) {
        vec2<T> temp(*this);
        vec2<T> temp2(vector);
        *this = {temp.getX() + temp2.getX(), temp.getY() + temp2.getY(), temp.getZ() + temp2.getZ()};
    }

    void operator-=(const vec2& vector) {
        vec2<T> temp(*this);
        vec2<T> temp2(vector);
        *this = { temp.getX() - temp2.getX(), temp.getY() + temp2.getY(), temp.getZ() + temp2.getZ() };
    }


};




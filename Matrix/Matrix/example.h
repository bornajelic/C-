#pragma once
#ifndef _POINT3D_H_IS_INCLUDED
#define _POINT3D_H_IS_INCLUDED
#include <iostream>
template <typename T>
class Point3D {

private:
	T data[3];
public:
	Point3D(T x = 0.0, T y = 0.0, T z = 0.0);
	T operator[](int i) const { return data[i]; }
	T& operator[](int i) { return data[i]; }
};


template <typename T>
Point3D<T>::Point3D(T x, T y, T z) {
	data[0] = x;
	data[1] = y;
	data[2] = z;
}

template <typename T>
std::ostream& operator<< (std::ostream &out, Point3D<T> const& p) {
	out << "[" << p[0] << ", " << p[1] << "," << p[2] << "]";
	return out;
}
#endif // !_POINT3D_H_IS_INCLUDED
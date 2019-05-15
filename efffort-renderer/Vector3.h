#pragma once

class Vector3 {
public:

	double x, y, z;

	Vector3() :x(0), y(0), z(0) {};
	Vector3(double x_) : x(x_), y(x_), z(x_) {};
	Vector3(double x_, double y_) :x(x_), y(y_), z(0) {};
	Vector3(double x_, double y_, double z_) :x(x_), y(y_), z(z_) {};
};

bool operator ==(const Vector3 v1, const Vector3 v2) {
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return true;
	else
		return false;
}

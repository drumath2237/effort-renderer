#pragma once

class Vector3 {
	double x, y, z;

	Vector3() :x(0), y(0), z(0) {};
	Vector3(double x_) : x(x_), y(x_), z(x_) {};
	Vector3(double x_, double y_) :x(x_), y(y_), z(0) {};
	Vector3(double x_, double y_, double z_) :x(x_), y(y_), z(z_) {};
};

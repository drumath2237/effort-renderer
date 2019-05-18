#pragma once

class Vector3 {
public:

	double x, y, z;

	Vector3() :x(0), y(0), z(0) {};
	Vector3(double x_) : x(x_), y(x_), z(x_) {};
	Vector3(double x_, double y_) :x(x_), y(y_), z(0) {};
	Vector3(double x_, double y_, double z_) :x(x_), y(y_), z(z_) {};

	double length() {
		return sqrt(x * x + y * y + z * z);
	}

	double length2() {
		x* x + y * y + z * z;
	}
};

bool operator ==(const Vector3 v1, const Vector3 v2) {
	if (v1.x == v2.x && v1.y == v2.y && v1.z == v2.z)
		return true;
	else
		return false;
}

Vector3 operator +(const Vector3 v1, const Vector3 v2) {
	return Vector3(
		v1.x + v2.x,
		v1.y + v2.y,
		v1.z + v2.z
		);
}

Vector3 operator -(const Vector3 v1, const Vector3 v2) {
	return Vector3(
		v1.x - v2.x,
		v1.y - v2.y,
		v1.z - v2.z
	);
}

Vector3 operator *(const Vector3 v1, const Vector3 v2) {
	return Vector3(
		v1.x * v2.x,
		v1.y * v2.y,
		v1.z * v2.z
	);
}

Vector3 operator *(const Vector3 v1, double d) {
	return Vector3(
		v1.x * d,
		v1.y * d,
		v1.z * d
	);
}

Vector3 operator *(double d, const Vector3 v1) {
	return v1 * d;
}

Vector3 operator /(const Vector3 v, double d) {
	return Vector3(v.x / d, v.y / d, v.z / d);
}

Vector3 operator /(double d, const Vector3 v) {
	return Vector3(d / v.x, d / v.y, d / v.z);
}

double dot(const Vector3 v1, const Vector3 v2) {
	return v1.x* v2.x + v1.y * v2.y + v1.z * v2.z;
}

Vector3 cross(const Vector3 v1, const Vector3 v2) {
	return Vector3(
		v1.y * v2.z - v1.z * v2.y,
		v1.z * v2.x - v1.x * v2.z,
		v1.x * v2.y - v1.y * v2.x
	);
}

Vector3 normalize(Vector3 v) {
	return v / v.length();
}
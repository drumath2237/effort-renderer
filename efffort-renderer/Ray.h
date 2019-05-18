#pragma once

#include "Vector3.h"

class Ray {
public:
	Vector3 origin;
	Vector3 direction;

	Ray() :origin(Vector3()), direction(Vector3(1,0,0)) {};
	Ray(Vector3 o, Vector3 d) :origin(o), direction(normalize(d)) {};

	Vector3 operator()(double t) const {
		return origin + direction * t;
	}
};
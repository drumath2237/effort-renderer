#pragma once

#include "Vector3.h"
#include "Ray.h"

class Camera {
public:
	Vector3 position;
	Vector3 rotation;
	double aspect;
	double near;
	double far;
	double size;

	virtual Ray getRay(double u, double v) const = 0;
};
#pragma once

#include "Camera.h"
#include "util.h"

#include <iostream>

class PerspectiveCamera : public Camera {
public:
	double fov;

	Ray getRay(double u, double v)const;
};

Ray PerspectiveCamera::getRay(double u, double v) const {
	const double len = 1. / (2.*std::tan(DEG2RAD * fov/2.));
	const Vector3 uv = len * normalize(forward)
		+ u * normalize(right)*aspect + v * normalize(up);

	return Ray(position, normalize(uv));
}
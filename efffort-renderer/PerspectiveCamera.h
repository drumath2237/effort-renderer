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
	const double len = 1. / std::tan(DEG2RAD * fov);
	const Vector3 uv = position + len * normalize(forward)
		+ u * normalize(right) + v * normalize(up);

	return Ray(position, normalize(uv));
}
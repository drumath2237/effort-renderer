#pragma once

#include "Camera.h"

#include <iostream>

class PerspectiveCamera : public Camera {
public:
	double fov;

	Ray getRay(double u, double v)const;
};

Ray PerspectiveCamera::getRay(double u, double v) const {
	// todo
}
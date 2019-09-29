#pragma once

#include "Light.h"

class PointLight : public Light {
public:
	PointLight(Vector3 pos, double flux) :Light(pos, flux) {}
};

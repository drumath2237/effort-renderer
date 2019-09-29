#pragma once

#include "Vector3.h"

class Light {
public:
	Vector3 pos;
	double flux;

	Light(const Vector3& p, double f) :pos(p), flux(f) {};
};

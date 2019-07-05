#pragma once

#include "Vector3.h"
#include "Ray.h"
#include "EfffortObject.h"

class Hit {
	// distance from ray-origin to object
	double t;

	// hit object
	EfffortObject obj;

	// hit position
	Vector3 pos;

	// normal vector of hit position
	Vector3 normal;
};

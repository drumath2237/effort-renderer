#pragma once

#include "Vector3.h"
#include "Ray.h"
//#include "EfffortObject.h"

class EfffortObject;

class Hit {
	// distance from ray-origin to object
	double t;

	// hit object (circle reference)
	EfffortObject* obj;

	// hit position
	Vector3 pos;

	// normal vector of hit position
	Vector3 normal;
};

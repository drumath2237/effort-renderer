#pragma once

#include "Vector3.h"
#include "Ray.h"
#include "EfffortObject.h"
#include "Hit.h"
#include "util.h"

class Sphere : EfffortObject {
	Vector3 o;
	double r;

	Sphere() :o(Vector3(0)), r(1.) {}
	Sphere(Vector3 origin, double radius) :o(origin), r(radius) {}

	bool intersect(const Ray&, Hit&);
};

bool Sphere::intersect(const Ray& ray, Hit& hit) {
	return true; // fix me
}

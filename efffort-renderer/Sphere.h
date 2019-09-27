#pragma once

#include "Vector3.h"
#include "Ray.h"
#include "EfffortObject.h"
#include "Hit.h"
#include "util.h"

class Sphere : public EfffortObject {
public:
	Vector3 o;
	double r;

	Sphere() :o(Vector3(0)), r(1.) {}
	Sphere(Vector3 origin, double radius) :o(origin), r(radius) {}

	bool intersect(const Ray&, Hit&)const ;
};

bool Sphere::intersect(const Ray& ray, Hit& hit) const {
	const double A = ray.direction.length2();
	const double B = dot(ray.direction, ray.origin * 2 - o);
	const double C = (o + ray.origin).length2() - r * r;

	const auto D = B * B - 4 * A * C;
	if (D < 0)
		return false;

	const double sign_b = signbit(B) ? -1 : 1;
	const double alpha = (-B - sign_b * std::sqrt(D)) / 2 * A;
	const double beta = C / (A * alpha);

	hit.t = (alpha < beta) ? alpha : beta;
	hit.obj = (Sphere*)this;
	hit.pos = ray(hit.t);
	hit.normal = normalize(hit.pos - o);

	return true;
}

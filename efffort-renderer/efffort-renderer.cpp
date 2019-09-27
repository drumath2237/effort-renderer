
#include <iostream>

#include "Vector3.h"
#include "Image.h"
#include "Sphere.h"

using namespace std;

int main()
{

	const Sphere sphere = Sphere();

	Image img = Image(400, 400);
	const double z = -10.;
	for (int j = 0; j < 400; j++) for (int i = 0; i < 400; i++) {
		const double x = ((double)i - 400 / 2) / (400 / 2);
		const double y = -((double)j - 400 / 2) / (400 / 2);
		Ray _ray = Ray(Vector3(x, y, z), Vector3(0, 0, 1));

		Hit hit;
		const bool isHit = sphere.intersect(_ray, hit);

		auto color = isHit ? hit.normal : Vector3(-1.);
		img.setPixel(i, j, color);

	}
	img.ppm_out("test_sphere_out.ppm");
}
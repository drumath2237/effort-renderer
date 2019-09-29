
#include <iostream>

#include "Vector3.h"
#include "Image.h"
#include "Sphere.h"
#include "PointLight.h"

//#define DEBUG_INTERSECTION

using namespace std;

int main()
{

	const Sphere sphere = Sphere();
	const PointLight light = PointLight(Vector3(1,1,-2)*10, 12.0);

	Image img = Image(400, 400);
	const double z = -10.;
	for (int j = 0; j < 400; j++) for (int i = 0; i < 400; i++) {
		const double x = ((double)i - 400 / 2) / (400 / 2);
		const double y = -((double)j - 400 / 2) / (400 / 2);
		Ray _ray = Ray(Vector3(x, y, z), Vector3(0, 0, 1));

		Hit hit;
		Vector3 color = Vector3(0);

#ifdef DEBUG_INTERSECTION
		color = Vector3(0, 1, 0);
#endif // DEBUG_INTERSECTION

		if (sphere.intersect(_ray, hit)) {

#ifdef DEBUG_INTERSECTION
			color = Vector3(1, 0, 1);
#endif // DEBUG_INTERSECTION


			// solve V
			const auto shadow_ray = Ray(hit.pos + (hit.normal*0.01+sphere.o), light.pos - hit.pos);
			Hit _h;
			if (!sphere.intersect(shadow_ray, _h)) {

				const auto omega = normalize(light.pos - hit.pos);

				const double L = dot(omega, hit.normal) / (light.pos - hit.pos).length2();

				color = Vector3(1.) * L*500;
			}

		}

		img.setPixel(i, j, color);

	}
	img.ppm_out("test_sphere_light_out.ppm");
}
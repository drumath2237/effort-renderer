
#include <iostream>

#include "Vector3.h"
#include "Image.h"

int main()
{
	Image img = Image();
	for (int i = 0; i < 640; i++) for (int j = 0; j < 400; j++) {
		img.setPixel(i, j, Vector3(1, 0, 1));
	}
	img.ppm_out("test_out.ppm");
    //std::cout << "Hello World!\n"; 
}
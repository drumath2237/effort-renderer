#pragma once

#include <iostream>

using namespace std;

class Image {
public:

	int width, height;

	Image() :width(640), height(400) {};
	Image(int w, int h) : width(w), height(h) {};

	double getPixel(int x, int y);
	void setPixel(int x, int y);
	void ppm_out(string filename);
	Image gammma_correction();

};

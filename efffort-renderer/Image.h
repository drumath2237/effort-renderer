#pragma once

#include <iostream>
#include <vector>

using namespace std;

class Image {
public:

	int width, height;
	vector<double> data;

	Image() :width(640), height(400) {
		data = vector<double>(width*height, 0);
	};

	Image(int w, int h) : width(w), height(h) {
		data = vector<double>(w * h, 0);
	};

	double getPixel(int x, int y)const;
	void setPixel(int x, int y, double value);
	void ppm_out(string filename);
	Image gammma_correction()const;

};

double Image::getPixel(int x, int y) const {
	return data[x * width + y];
}

void Image::setPixel(int x, int y, double value) {
	data[x * width + y] = value;
}

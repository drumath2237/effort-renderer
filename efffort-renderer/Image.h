#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "Vector3.h"

using namespace std;

class Image {
public:

	int width, height;
	vector<Vector3> data;

	Image() :width(640), height(400) {
		data = vector<Vector3>(width*height, Vector3());
	};

	Image(int w, int h) : width(w), height(h) {
		data = vector<Vector3>(w * h, Vector3());
	};

	Vector3 getPixel(int x, int y)const;
	void setPixel(int x, int y, Vector3 value);
	void ppm_out(string filename)const;
	Image gammma_correction()const;

};

Vector3 Image::getPixel(int x, int y) const {
	return data[x * width + y];
}

void Image::setPixel(int x, int y, Vector3 value) {
	data[x * width + y] = value;
}

void Image::ppm_out(string filename) const {
	ofstream ofs(filename);
}

#pragma once

#include <iostream>
#include <vector>
#include <fstream>

#include "Vector3.h"
#include "util.h"

using namespace std;

class Image {
public:

	int width, height;
	vector<Vector3> data;

	Image() :width(640), height(400) {
		auto n = width * height;
		data = vector<Vector3>(n, Vector3());
	};

	Image(int w, int h) : width(w), height(h) {
		auto n = width * height;
		data = vector<Vector3>(n, Vector3());
	};

	Vector3 getPixel(int x, int y)const;
	void setPixel(int x, int y, const Vector3& value);
	void AddPixel(int x, int y, const Vector3& value);
	void devide(int N);
	void ppm_out(string filename)const;
	void gammma_correction();

};

Vector3 Image::getPixel(int x, int y) const {
	auto index = y * width + x;
	return data[index];
}

void Image::setPixel(int x, int y, const Vector3& value) {
	auto index = y * width + x;
	data[index] = value;
}

void Image::AddPixel(int x, int y, const Vector3& value) {
	setPixel(x, y, getPixel(x, y) + value);
}

void Image::devide(int N) {
	for (int i = 0; i < width; i++) for (int j = 0; j < height; j++) {
		setPixel(i, j, getPixel(i, j) / N);
	}
}

void Image::gammma_correction() {
	for (int i = 0; i < width; i++) for (int j = 0; j < height; j++) {
		auto c = getPixel(i, j);
		setPixel(i, j, Vector3(
			std::pow(c.x, 1.0 / 2.2),
			std::pow(c.y, 1.0 / 2.2),
			std::pow(c.z, 1.0 / 2.2)
		));
	}
}

void Image::ppm_out(string filename) const {
	ofstream ofs(filename);

	ofs << "P3" << endl;
	ofs << width << " " << height << endl;
	ofs << 255 << endl;

	for (int i = 0; i < width; i++) for (int j = 0; j < height; j++) {
		Vector3 color = getPixel(i, j);
		int r = clamp(0, (int)(color.x*255), 255);
		int g = clamp(0, (int)(color.y*255), 255);
		int b = clamp(0, (int)(color.z*255), 255);

		ofs << r << " " << g << " " << b << endl;
	}

	ofs.close();

}

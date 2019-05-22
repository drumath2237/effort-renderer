#pragma once

double clamp(double min, double value, double max) {
	if (value > max)
		return max;
	else if (value < min)
		return min;

	return value;
}

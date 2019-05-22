#pragma once

double clamp(double value, double max, double min) {
	if (value > max)
		return max;
	else if (value < min)
		return min;

	return value;
}

#pragma once

#define PI 3.14159265358979

#define DEG2RAD PI/180.
#define RAD2DEG 180./PI

/// <summary>
/// 値を最小値と最大値で切り取る関数。主にppm出力のときなどに使われる。
/// </summary>
/// <param name="min">最小値</param>
/// <param name="value">値</param>
/// <param name="max">最大値</param>
/// <returns>切り取られた値</returns>
double clamp(double min, double value, double max) {
	if (value > max)
		return max;
	else if (value < min)
		return min;

	return value;
}

/// <summary>
/// 法線マップをきれいに表示するための関数
/// </summary>
/// <param name="value">[-1,1]->[0,255]にマッピングする関数</param>
/// <returns>マッピングされた数値</returns>
int map_normal(double value) {
	if (value < -1 || 1 < value) {
		return 0;
	}
	return (int)(value * 127.5 + 127.5);
}

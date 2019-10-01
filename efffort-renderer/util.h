#pragma once

#define PI 3.14159265358979

#define DEG2RAD PI/180.
#define RAD2DEG 180./PI

/// <summary>
/// �l���ŏ��l�ƍő�l�Ő؂���֐��B���ppm�o�͂̂Ƃ��ȂǂɎg����B
/// </summary>
/// <param name="min">�ŏ��l</param>
/// <param name="value">�l</param>
/// <param name="max">�ő�l</param>
/// <returns>�؂���ꂽ�l</returns>
double clamp(double min, double value, double max) {
	if (value > max)
		return max;
	else if (value < min)
		return min;

	return value;
}

/// <summary>
/// �@���}�b�v�����ꂢ�ɕ\�����邽�߂̊֐�
/// </summary>
/// <param name="value">[-1,1]->[0,255]�Ƀ}�b�s���O����֐�</param>
/// <returns>�}�b�s���O���ꂽ���l</returns>
int map_normal(double value) {
	if (value < -1 || 1 < value) {
		return 0;
	}
	return (int)(value * 127.5 + 127.5);
}

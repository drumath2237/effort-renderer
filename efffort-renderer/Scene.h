#pragma once

#include <vector>

#include "EfffortObject.h"
#include "Light.h"
#include "Sphere.h"
#include "Hit.h"

class Scene {
public:
	/// <summary>
	/// EffortObject�̃��X�g
	/// </summary>
	vector<EfffortObject*> obj_list;

	/// <summary>
	/// light�̃��X�g
	/// </summary>
	vector<Light*> light_list;

	/// <summary>
	/// scene����Object��Ray�̌�������
	/// </summary>
	/// <param name="ray">���������郌�C</param>
	/// <param name="hit">�����������̏Փˏ��</param>
	/// <returns>���������true�A�����łȂ����false</returns>
	bool intersect(const Ray& ray, Hit& hit)const;

	/// <summary>
	/// scene��Object��ǉ�����
	/// </summary>
	/// <param name="obj">�ǉ�����Object</param>
	/// <returns>�ǉ�����Object�̎Q��</returns>
	EfffortObject* add(const EfffortObject& obj);

	/// <summary>
	/// Scene��Light��ǉ�����
	/// </summary>
	/// <param name="light"></param>
	/// <returns>�ǉ�����Light�̎Q��</returns>
	Light* add(const Light& light);
};
#pragma once

#include <vector>
#include <limits>

#include "EfffortObject.h"
#include "Light.h"
#include "Sphere.h"
#include "Hit.h"

class Scene {
private:
	/// <summary>
	/// EffortObject�̃��X�g
	/// </summary>
	vector<EfffortObject> obj_list;

	/// <summary>
	/// light�̃��X�g
	/// </summary>
	vector<Light> light_list;

public:

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
	EfffortObject& add(const EfffortObject& obj);

	/// <summary>
	/// Scene��Light��ǉ�����
	/// </summary>
	/// <param name="light"></param>
	/// <returns>�ǉ�����Light�̎Q��</returns>
	Light& add(const Light& light);
};

EfffortObject& Scene::add(const EfffortObject& obj) {
	obj_list.push_back(obj);
	return (EfffortObject & )obj;
}

Light& Scene::add(const Light& light) {
	light_list.push_back(light);
	return (Light&)light;
}

bool Scene::intersect(const Ray& ray, Hit& hit) const {
	if (obj_list.size == 0) return false;

	hit.t = INT32_MAX;

	for (auto obj : obj_list) {
		Hit _h;
		if (obj.intersect(ray, _h)) {
			if (_h.t < hit.t) {
				hit.t = _h.t;
				hit.normal = _h.normal;
				hit.obj = _h.obj;
				hit.pos = _h.pos;
			}
		}
	}

	return hit.t != INT32_MAX;
}
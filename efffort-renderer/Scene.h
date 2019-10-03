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
	/// EffortObjectのリスト
	/// </summary>
	vector<EfffortObject> obj_list;

	/// <summary>
	/// lightのリスト
	/// </summary>
	vector<Light> light_list;

public:

	/// <summary>
	/// scene中のObjectとRayの交差判定
	/// </summary>
	/// <param name="ray">交差させるレイ</param>
	/// <param name="hit">交差した時の衝突情報</param>
	/// <returns>交差すればtrue、そうでなければfalse</returns>
	bool intersect(const Ray& ray, Hit& hit)const;

	/// <summary>
	/// sceneにObjectを追加する
	/// </summary>
	/// <param name="obj">追加するObject</param>
	/// <returns>追加したObjectの参照</returns>
	EfffortObject& add(const EfffortObject& obj);

	/// <summary>
	/// SceneにLightを追加する
	/// </summary>
	/// <param name="light"></param>
	/// <returns>追加したLightの参照</returns>
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
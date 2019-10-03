#pragma once

#include <vector>

#include "EfffortObject.h"
#include "Light.h"
#include "Sphere.h"
#include "Hit.h"

class Scene {
public:
	/// <summary>
	/// EffortObjectのリスト
	/// </summary>
	vector<EfffortObject*> obj_list;

	/// <summary>
	/// lightのリスト
	/// </summary>
	vector<Light*> light_list;

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
	EfffortObject* add(const EfffortObject& obj);

	/// <summary>
	/// SceneにLightを追加する
	/// </summary>
	/// <param name="light"></param>
	/// <returns>追加したLightの参照</returns>
	Light* add(const Light& light);
};
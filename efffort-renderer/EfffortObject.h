#pragma once

#include "Vector3.h"
#include "Hit.h"

// EfffortObject abstract class
class EfffortObject {
private:
	Vector3 position;

public:
	void setPosition(const Vector3&);
	virtual bool intersect(const Ray&, Hit&)const = 0;
};

void EfffortObject::setPosition(const Vector3& p) {
	position = p;
}

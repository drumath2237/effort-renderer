#pragma once

#include "Vector3.h"

// EfffortObject abstract class
class EfffortObject {
private:
	Vector3 position;

public:
	virtual void setPosition(const Vector3&);
};

void EfffortObject::setPosition(const Vector3& p) {
	position = p;
}

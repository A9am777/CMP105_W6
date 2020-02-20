#include "RailedObj.h"

void RailedObj::update(float dt)
{
	speed += accel * dt;

	if (Vector::magnitude(pointB - pointA) < 3.0f) { speed = 0; }

	setPosition(getPosition() + Vector::normalise(pointB - pointA) * speed * dt);
}

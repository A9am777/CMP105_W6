#pragma once

#include "Framework/GameObject.h"
#include "Framework/Vector.h"

class RailedObj :
public GameObject
{
	public:


		void update(float) override;

		sf::Vector2f pointA;
		sf::Vector2f pointB;
		float speed;
		float accel;
	private:

};


#pragma once

#include "Framework/GameObject.h"

class AngryBird :
public GameObject
{
	public:
		AngryBird();

		void update(float) override;

		void handleInput(float) override;

	private:
		bool drag;
		bool firOnce;
};


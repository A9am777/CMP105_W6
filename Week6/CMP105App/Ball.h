#pragma once

#include "Framework\GameObject.h"

class Ball :
public GameObject
{
	public:

	Ball();
	~Ball();

	void setScreenSize(sf::Vector2u);

	void update(float) override;
	void handleInput(float) override;

	private:
		sf::Vector2u screenSiz;
};


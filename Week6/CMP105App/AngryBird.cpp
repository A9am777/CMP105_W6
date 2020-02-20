#include "AngryBird.h"

AngryBird::AngryBird()
{
	firOnce = true;
}

void AngryBird::update(float dt)
{
	if (!firOnce) 
	{
		velocity += sf::Vector2f(0, 98 * dt);


		setPosition(getPosition() + velocity * dt);
	}
}

void AngryBird::handleInput(float dt)
{
	if (firOnce)
	{
		if (drag)
		{
			if (!input->isMouseRDown())
			{
				firOnce = false;
				velocity = getPosition() - sf::Vector2f(input->getMouseX(), input->getMouseY());
			}
		}
		else
		{
			if (input->isMouseRDown())
			{
				drag = true;
			}
		}
	}
}

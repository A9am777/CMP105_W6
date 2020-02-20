#include "Ball.h"



Ball::Ball()
{
}


Ball::~Ball()
{
}

void Ball::setScreenSize(sf::Vector2u screenSize)
{
	screenSiz = screenSize;
}

void Ball::update(float dt)
{
	velocity += dt*sf::Vector2f(0, 98);

	setPosition(getPosition() + velocity * dt);

	if (getPosition().y + getSize().y >= screenSiz.y) 
	{ 
		setPosition(sf::Vector2f(getPosition().x, screenSiz.y - getSize().y)); 
		velocity = velocity * -0.67f;
	}

}

void Ball::handleInput(float dt)
{
	if (input->isMouseLDown())
	{
		setPosition(sf::Vector2f(input->getMouseX() - 25, input->getMouseY() - 25));
	}

}

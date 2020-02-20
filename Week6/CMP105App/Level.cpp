#include "Level.h"

Level::Level(sf::RenderWindow* hwnd, Input* in)
{
	window = hwnd;
	input = in;

	// initialise game objects
	ballTex.loadFromFile("gfx/Goomba.png");

	ball.setScreenSize(window->getSize());
	ball.setPosition(sf::Vector2f(window->getSize().x/2+25,50));
	ball.setSize(sf::Vector2f(50, 50));
	ball.setTexture(&ballTex);
	ball.setInput(input);

	onRail.speed = 80;
	onRail.accel = 12;
	onRail.pointA = sf::Vector2f(0, 0);
	onRail.pointB = sf::Vector2f(window->getSize().x, window->getSize().y);
	onRail.setPosition(sf::Vector2f(0,0));
	onRail.setSize(sf::Vector2f(50, 50));
	onRail.setTexture(&ballTex);

	bird.setPosition(sf::Vector2f(50, 100));
	bird.setSize(sf::Vector2f(50, 50));
	bird.setTexture(&ballTex);
	bird.setInput(input);


}

Level::~Level()
{

}

// handle user input
void Level::handleInput(float dt)
{
	ball.handleInput(dt);

	onRail.pointA = onRail.getPosition();
	onRail.pointB = sf::Vector2f(input->getMouseX(), input->getMouseY());

	bird.handleInput(dt);
}

// Update game objects
void Level::update(float dt)
{
	ball.update(dt);
	onRail.update(dt);
	bird.update(dt);
}

// Render level
void Level::render()
{
	beginDraw();
	window->draw(ball);
	window->draw(onRail);
	window->draw(bird);
	endDraw();
}

// Begins rendering to the back buffer. Background colour set to light blue.
void Level::beginDraw()
{
	window->clear(sf::Color(100, 149, 237));
}

// Ends rendering to the back buffer, and swaps buffer to the screen.
void Level::endDraw()
{
	window->display();
}
#include "Enemy.h"
#include <iostream>

Enemy::Enemy(Dir dir, float speed, sf::RenderWindow & window)
{
	bodyCircle.setFillColor(sf::Color::Blue);
	bodyCircle.setOutlineColor(sf::Color::Black);
	bodyCircle.setRadius(10);
	bodyCircle.setOutlineThickness(2);
	bodyCircle.setOrigin(5, 5);
	Diff = speed;
	direction = dir;
}

void Enemy::setPos(float posx, float posy)
{
	bodyCircle.setPosition(posx, posy);
}

sf::FloatRect Enemy::getBorder() const
{
	return bodyCircle.getGlobalBounds();
}

void Enemy::moveAxisX(sf::RenderWindow & window, float min, float max)
{	
	window.draw(bodyCircle);

	switch (direction)
	{
	case LEFT:
	{
		bodyCircle.move(sf::Vector2f(-Diff, 0));
		if (bodyCircle.getPosition().x <= min)
			direction = RIGHT;

		break;
	}
	case RIGHT:
	{
		bodyCircle.move(sf::Vector2f(Diff, 0));
		if (bodyCircle.getPosition().x >= max)
			direction = LEFT;

		break;
	}
	}
}

void Enemy::moveAxisY(sf::RenderWindow & window, float min, float max)
{
	window.draw(bodyCircle);

	switch (direction)
	{
	case UP:
	{
		bodyCircle.move(sf::Vector2f(0, -Diff));
		if (bodyCircle.getPosition().y <= min)
			direction = DOWN;

		break;
	}
	case DOWN:
	{
		bodyCircle.move(sf::Vector2f(0, Diff));
		if (bodyCircle.getPosition().y >= max)
			direction = UP;

		break;
	}
	}
}

void Enemy::SlantFall(sf::RenderWindow & window, float min, float max)
{
	window.draw(bodyCircle);

	switch (direction)
	{
	case SLANTTOP:
	{
		bodyCircle.move(sf::Vector2f(-Diff, -Diff));
		if (bodyCircle.getPosition().y <= min)
			direction = SLANTBOTTOM;
		
		break;
	}
	case SLANTBOTTOM:
	{
		bodyCircle.move(sf::Vector2f(Diff, Diff));
		if (bodyCircle.getPosition().y >= max)
			direction = SLANTTOP;
		break;
	}
	}
}

void Enemy::SlantRise(sf::RenderWindow & window, float min, float max)
{
	window.draw(bodyCircle);

	switch (direction)
	{
	case SLANTTOP:
	{
		bodyCircle.move(sf::Vector2f(Diff, -Diff));
		if (bodyCircle.getPosition().y <= min)
			direction = SLANTBOTTOM;

		break;
	}
	case SLANTBOTTOM:
	{
		bodyCircle.move(sf::Vector2f(-Diff, Diff));
		if (bodyCircle.getPosition().y >= max)
			direction = SLANTTOP;
		break;
	}
	}
}
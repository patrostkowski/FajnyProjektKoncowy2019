#include "Enemy.h"
#include <iostream>

Enemy::Enemy(float x, float y, Dir dir, sf::RenderWindow & window)
{
	enemy.setFillColor(sf::Color::Blue);
	enemy.setOutlineColor(sf::Color::Black);
	enemy.setRadius(10);
	enemy.setOutlineThickness(2);
	enemy.setOrigin(5, 5);
	enemy.setPosition(x, y);
	direction = dir;
}

void Enemy::drawEnemy(sf::RenderWindow & window)
{
	window.draw(enemy);
}

sf::FloatRect Enemy::getEnemyBorder() const
{
	return enemy.getGlobalBounds();
}

void Enemy::moveAxisX(sf::RenderWindow & window, float min, float max)
{	
	window.draw(enemy);

	switch (direction)
	{
	case LEFT:
	{
		enemy.move(sf::Vector2f(-0.02f, 0));
		if (enemy.getPosition().x <= min)
			direction = RIGHT;

		break;
	}
	case RIGHT:
	{
		enemy.move(sf::Vector2f(0.02f, 0));
		if (enemy.getPosition().x >= max)
			direction = LEFT;

		break;
	}
	}
}

void Enemy::moveAxisY(sf::RenderWindow & window, float min, float max)
{
	window.draw(enemy);

	switch (direction)
	{
	case UP:
	{
		enemy.move(sf::Vector2f(0, -0.02f));
		if (enemy.getPosition().y <= min)
			direction = DOWN;

		break;
	}
	case DOWN:
	{
		enemy.move(sf::Vector2f(0, 0.02f));
		if (enemy.getPosition().y >= max)
			direction = UP;

		break;
	}
	}
}

void Enemy::SlantFall(sf::RenderWindow & window, float min, float max)
{
	window.draw(enemy);

	switch (direction)
	{
	case TOP:
	{
		enemy.move(sf::Vector2f(-0.02f, -0.02f));
		if (enemy.getPosition().y <= min)
			direction = BOTTOM;
		
		break;
	}
	case BOTTOM:
	{
		enemy.move(sf::Vector2f(0.02f, 0.02f));
		if (enemy.getPosition().y >= max)
			direction = TOP;
		break;
	}
	}
}

void Enemy::SlantRise(sf::RenderWindow & window, float min, float max)
{
	window.draw(enemy);

	switch (direction)
	{
	case TOP:
	{
		enemy.move(sf::Vector2f(0.02f, -0.02f));
		if (enemy.getPosition().y <= min)
			direction = BOTTOM;

		break;
	}
	case BOTTOM:
	{
		enemy.move(sf::Vector2f(-0.02f, 0.02f));
		if (enemy.getPosition().y >= max)
			direction = TOP;
		break;
	}
	}
}
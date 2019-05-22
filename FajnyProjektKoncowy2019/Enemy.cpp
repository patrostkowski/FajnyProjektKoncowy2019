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

sf::FloatRect Enemy::getEnemyPos() const
{
	return enemy.getGlobalBounds();
}

void Enemy::moveAxisX(sf::RenderWindow & window, float x1, float x2)
{	
	window.draw(enemy);

	/*
	std::cout << "vec x1 " << x1 << std::endl;
	std::cout << "enemy x " << enemy.getPosition().x << std::endl;
	std::cout << "intiial x " << initialX << std::endl;

	system("cls");
	*/

	switch (direction)
	{
	case LEFT:
	{
		enemy.move(sf::Vector2f(-0.02f, 0));
		if (enemy.getPosition().x <= x1)
			direction = RIGHT;

		break;
	}
	case RIGHT:
	{
		enemy.move(sf::Vector2f(0.02f, 0));
		if (enemy.getPosition().x >= x2)
			direction = LEFT;

		break;
	}
	}
}

void Enemy::moveAxisY(sf::RenderWindow & window, float y1, float y2)
{
	window.draw(enemy);

	switch (direction)
	{
	case UP:
	{
		enemy.move(sf::Vector2f(0, -0.02f));
		if (enemy.getPosition().y <= y1)
			direction = DOWN;

		break;
	}
	case DOWN:
	{
		enemy.move(sf::Vector2f(0, 0.02f));
		if (enemy.getPosition().y >= y2)
			direction = UP;

		break;
	}
	}
}

void Enemy::moveSlant(sf::RenderWindow & window, float x, float y, bool dir)
{
	window.draw(enemy);

	switch (direction)
	{
	case TOP:
	{
		if (dir == 0)
		{
			enemy.move(sf::Vector2f(-0.02f, -0.02f));
			if (enemy.getPosition().y <= x)
				direction = BOTTOM;
		}
		if (dir == 1)
		{
			enemy.move(sf::Vector2f(0.02f, 0.02f));
			if (enemy.getPosition().x <= y)
				direction = BOTTOM;
		}
		break;
	}
	case BOTTOM:
	{
		if (dir == 0)
		{
			enemy.move(sf::Vector2f(0.02f, 0.02f));
			if (enemy.getPosition().y >= y)
				direction = TOP;
		}
		if (dir == 1)
		{
			enemy.move(sf::Vector2f(-0.02f, -0.02f));
			if (enemy.getPosition().y >= x)
				direction = TOP;
		}

		break;
	}
	}
}

void Enemy::moveSquare(sf::RenderWindow & window, float x, float y)
{
	window.draw(enemy);

	switch (direction)
	{
	case TOP:
	{
		enemy.move(sf::Vector2f(-0.02f, -0.02f));
		if (enemy.getPosition().y <= x)
			direction = BOTTOM;

		break;
	}
	case BOTTOM:
	{
		enemy.move(sf::Vector2f(0.02f, 0.02f));
		if (enemy.getPosition().y >= y)
			direction = TOP;

		break;
	}
	}
}

void Enemy::rotate(sf::RenderWindow & window)
{

}


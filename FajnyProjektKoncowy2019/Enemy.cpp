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

void Enemy::moveAxisXLeft(sf::RenderWindow & window, float x1, float velo)
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
		enemy.move(-0.02f, 0);
		if (enemy.getPosition().x == 700.0f)
			direction = RIGHT;
		break;
	}
	case RIGHT:
	{
		enemy.move(0.02f, 0);
		if (enemy.getPosition().x == 850.0f)
			direction = LEFT;
		break;
	}
	}
}

void Enemy::moveAxisXRight(sf::RenderWindow & window, float x, float velo)
{
	enemy.move(sf::Vector2f(velo, 0));
	window.draw(enemy);
	if (enemy.getPosition().x == initialX)
		direction = LEFT;
}

void Enemy::switchAxis(sf::RenderWindow & window)
{
	window.draw(enemy);
	switch (direction)
	{
	case LEFT:
	{
		enemy.move(sf::Vector2f(-0.02f, 0));
		if (enemy.getPosition().x == 700.0f)
			direction = RIGHT;
		break;
	}
	case RIGHT:
	{
		enemy.move(sf::Vector2f(0.02f, 0));
		if (enemy.getPosition().x == 850.0f)
			direction = LEFT;
		break;
	}
	}
}

void Enemy::moveSlant(sf::RenderWindow & window)
{

}

void Enemy::rotate(sf::RenderWindow & window)
{

}


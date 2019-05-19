#include "Enemy.h"
#include <iostream>

Enemy::Enemy(float x, float y, sf::RenderWindow & window)
{
	enemy.setFillColor(sf::Color::Blue);
	enemy.setOutlineColor(sf::Color::Black);
	enemy.setRadius(10);
	enemy.setOutlineThickness(2);
	enemy.setOrigin(5, 5);
	enemy.setPosition(x, y);
}

void Enemy::drawEnemy(sf::RenderWindow & window)
{
	window.draw(enemy);
}

void Enemy::moveAxisXLeft(sf::RenderWindow & window, float x1, float velo)
{	
	/*
	std::cout << "vec x1 " << x1 << std::endl;
	std::cout << "enemy x " << enemy.getPosition().x << std::endl;
	system("cls");
	*/	
	if (enemy.getPosition().x != x1)
	{
		enemy.move(sf::Vector2f(-velo, 0));
		window.draw(enemy);
	}
	else if (enemy.getPosition().x == x1)
	{
		enemy.move(sf::Vector2f(velo, 0));
		window.draw(enemy);
	}
	else
	{
		window.draw(enemy);
	}

}

void Enemy::moveAxisXRight(sf::RenderWindow & window, float x, float velo)
{
	if (enemy.getPosition().x < initialX)
	{
		enemy.move(sf::Vector2f(velo, 0));
		window.draw(enemy);
	}
}

void Enemy::moveSlant(sf::RenderWindow & window)
{

}

void Enemy::rotate(sf::RenderWindow & window)
{

}


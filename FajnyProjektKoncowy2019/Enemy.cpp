#include "Enemy.h"

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

void Enemy::enemyMove(sf::RenderWindow & window)
{
	for (int i = 0; i < 10; ++i)
	{
		enemy.move(enemy.getPosition().x-i*10, enemy.getPosition().y);
		window.draw(enemy);
	}
}

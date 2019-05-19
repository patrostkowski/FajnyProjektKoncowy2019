#pragma once
#include "SFML/Graphics.hpp"
class Enemy
{
	sf::CircleShape enemy;
public:
	Enemy(float x, float y, sf::RenderWindow& window);
	void drawEnemy(sf::RenderWindow & window);
	void enemyMove(sf::RenderWindow & window);
};

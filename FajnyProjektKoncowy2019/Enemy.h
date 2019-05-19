#pragma once
#include "SFML/Graphics.hpp"
class Enemy
{
	sf::CircleShape enemy;
	float velocity=0.03;
	int initialX = enemy.getPosition().x;
public:
	Enemy(float x, float y, sf::RenderWindow& window);
	void drawEnemy(sf::RenderWindow & window);
	void moveAxisXLeft(sf::RenderWindow & window, float x, float velo);
	void moveAxisXRight(sf::RenderWindow & window, float x, float velo);
	void moveSlant(sf::RenderWindow & window);
	void rotate(sf::RenderWindow & window);
};

#pragma once
#include "SFML/Graphics.hpp"

enum Dir { LEFT, RIGHT, UP, DOWN, TOP, BOTTOM};

class Enemy
{
	Dir direction;
	sf::CircleShape enemy;
public:
	Enemy(float x, float y, Dir dir, sf::RenderWindow& window);
	void drawEnemy(sf::RenderWindow & window);
	sf::FloatRect getEnemyPos() const;
	void moveAxisX(sf::RenderWindow & window, float x1, float x2);
	void moveAxisY(sf::RenderWindow & window, float y1, float y2);
	void moveSlant(sf::RenderWindow & window, float x, float y, bool dir);
	void moveSquare(sf::RenderWindow & window, float x, float y);
	void rotate(sf::RenderWindow & window);
};

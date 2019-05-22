#pragma once
#include "SFML/Graphics.hpp"

enum Dir { LEFT, RIGHT };

class Enemy
{
	Dir direction;
	sf::CircleShape enemy;
//	float velocity=0.03;
	int initialX = 800;
public:
	Enemy(float x, float y, Dir dir, sf::RenderWindow& window);
	void drawEnemy(sf::RenderWindow & window);
	sf::FloatRect getEnemyPos() const;
	void moveAxisXLeft(sf::RenderWindow & window, float x, float velo);
	void moveAxisXRight(sf::RenderWindow & window, float x, float velo);
	void switchAxis(sf::RenderWindow & window);
	void moveSlant(sf::RenderWindow & window);
	void rotate(sf::RenderWindow & window);
};

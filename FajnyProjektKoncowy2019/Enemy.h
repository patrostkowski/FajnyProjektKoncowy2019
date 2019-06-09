#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include "Player.h"
#include "Sound.h"

enum Dir { LEFT, RIGHT, UP, DOWN, SLANTTOP, SLANTBOTTOM};

class Enemy
{
	sf::CircleShape bodyEnemy[10];
	Dir direction;
	float drift;
public:
	Enemy(int count, Dir dir, float speed, sf::RenderWindow& window);
	void setPos(int indx, float posx, float posy);
	bool collision(Player &player);
	void moveAxisX(sf::RenderWindow & window, float x1, float x2);
	void moveAxisY(sf::RenderWindow & window, float y1, float y2);
	void SlantFall(sf::RenderWindow & window, float x, float y);
	void SlantRise(sf::RenderWindow & window, float x, float y);
};

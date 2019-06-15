#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include "Player.h"
#include "Sound.h"

enum Dir { LEFT, RIGHT, UP, DOWN, SLANTTOP, SLANTBOTTOM};

class Enemy
{
	sf::CircleShape bodyEnemy;
	Dir direction;
	float speed;
	int body_size;
public:
	Enemy(float speed, sf::RenderWindow& window);
	void setDir(Dir dir);
	void setPos(float posx, float posy);
	bool collision(Player &player);
	void moveAxisX(sf::RenderWindow & window, float x1, float x2);
	void moveAxisY(sf::RenderWindow & window, float y1, float y2);
	void SlantFall(sf::RenderWindow & window, float x, float y);
	void SlantRise(sf::RenderWindow & window, float x, float y);
};

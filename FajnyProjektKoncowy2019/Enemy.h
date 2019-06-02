#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"

enum Dir { LEFT, RIGHT, UP, DOWN, SLANTTOP, SLANTBOTTOM};

class Enemy: public Particle
{
	Dir direction;
	float Diff;
public:
	Enemy(Dir dir, float speed, sf::RenderWindow& window);
	void setPos(float posx, float posy);
	sf::FloatRect getBorder() const;
	void moveAxisX(sf::RenderWindow & window, float x1, float x2);
	void moveAxisY(sf::RenderWindow & window, float y1, float y2);
	void SlantFall(sf::RenderWindow & window, float x, float y);
	void SlantRise(sf::RenderWindow & window, float x, float y);
};

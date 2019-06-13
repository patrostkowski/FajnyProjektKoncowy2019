#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include "Player.h"

class Point
{
	sf::CircleShape bodyPoint[4];
	bool pointCheck[4];
public:
	Point(sf::RenderWindow & window);
	void setPos(int indx, float posx, float posy);
	void drawPoint(sf::RenderWindow & window);
	void collision(Player &player);
	bool isPointChecked(int a) const;
};


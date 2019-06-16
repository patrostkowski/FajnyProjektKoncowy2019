#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include "Player.h"

class Point
{
	sf::CircleShape bodyPoint;
	bool pointCheck;
public:
	Point(sf::RenderWindow & window);
	void setPos(float posx, float posy);
	void drawPoint(sf::RenderWindow & window);
	bool collision(Player &player);
	bool isPointChecked() const;
};


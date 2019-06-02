#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"

class Point: public Particle
{
	bool taken;
public:
	Point(sf::RenderWindow & window);
	void setPos(float posx, float posy);
	void drawPoint(sf::RenderWindow & window);
	sf::FloatRect getBorder() const;
	void pointTaken();
	bool isTaken(); 
};


#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include "Point.h"

class Player: public Particle
{
public:
	Player(sf::RenderWindow& window);
	void setPos(float posx, float posy);
	void playerMovement(sf::RenderWindow& window);
	void playerCollision(sf::RenderWindow& window, Point &point);
	sf::FloatRect getBorder() const;
	void resetPos();
};


#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include <iostream>

class Player: public Particle
{
public:
	Player(sf::RenderWindow& window);
	void setPos(float posx, float posy);
	void playerMovement(sf::RenderWindow& window);
	sf::FloatRect getBorder() const;
	void resetPos();
};


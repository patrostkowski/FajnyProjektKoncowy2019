#pragma once
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include <iostream>

class Player: public Particle
{
	const float speed = 0.05f;
public:
	Player(sf::RenderWindow& window);
	void setPos(float posx, float posy);
	void playerMovement(sf::RenderWindow& window);
	sf::FloatRect getBorder() const;
	float getBorderLeft() const;
	float getBorderTop() const;
	float getBorderWidth() const;
	float getBorderHeight() const;
	void resetPos();
	float getPlayerX() const;
	float getPlayerY() const;
};


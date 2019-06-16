#pragma once
#include "Particle.h"
#include "Player.h"
class Obstacles: public Particle
{
public:
	Obstacles(sf::RenderWindow &window);
	sf::FloatRect getBorder() const;
	void setSize(float posx, float posy);
	void setPos(float posx, float posy);
	void draw(sf::RenderWindow &window);
	void collision(Player &player);
};


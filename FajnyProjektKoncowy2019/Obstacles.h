#pragma once
#include "Particle.h"
#include "Player.h"
class Obstacles: public Particle
{
public:
	Obstacles(int width, int heigth, sf::RenderWindow &window);
	sf::FloatRect getBorder(int indx) const;
	void setSize(int indx, float posx, float posy);
	void setPos(int indx, float posx, float posy);
	void draw(sf::RenderWindow &window);
	void collision(Player &player);
};


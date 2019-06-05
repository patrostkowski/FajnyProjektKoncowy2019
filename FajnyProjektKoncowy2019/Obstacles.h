#pragma once
#include "Particle.h"
class Obstacles: public Particle 
{
public:
	Obstacles(int width, int heigth, sf::RenderWindow &window);
	sf::FloatRect getborder() const;
};


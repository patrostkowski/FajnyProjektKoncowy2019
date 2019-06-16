#pragma once
#include "SFML/Graphics.hpp"

//klasa czysto wirtualna - na niej bazuja pozostale czyli gracz, wrog i punkt. 

class Particle
{
protected: 
	sf::RectangleShape bodyRect;
	sf::CircleShape bodyCircle;
public:
	virtual void setPos(float posX, float posY) = 0;
	virtual sf::FloatRect getBorder() const = 0;
};



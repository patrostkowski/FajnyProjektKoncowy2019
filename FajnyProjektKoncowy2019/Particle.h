#pragma once
#include "SFML/Graphics.hpp"

//klasa czysto wirtualna - na niej bazuja pozostale czyli gracz, wrog i punkt. 

class Particle
{
protected: 
	sf::CircleShape bodyEnemy[5];
	sf::RectangleShape bodyRect[10];
	sf::CircleShape bodyCircle;
public:
	virtual void setPos(int indx, float posX, float posY) = 0;
	virtual sf::FloatRect getBorder(int indx) const = 0;
};



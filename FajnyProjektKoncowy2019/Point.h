#pragma once
#include "SFML/Graphics.hpp"
class Point
{
	sf::CircleShape point;
public:
	Point(float x, float y, sf::RenderWindow & window);
	void setPoint(sf::RenderWindow & window);
	sf::FloatRect getPointPos() const;
	void pointTaken();
};


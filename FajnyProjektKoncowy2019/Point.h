#pragma once
#include "SFML/Graphics.hpp"
class Point
{
	sf::CircleShape point;
	bool taken;
public:
	Point(float x, float y, sf::RenderWindow & window);
	void drawPoint(sf::RenderWindow & window);
	sf::FloatRect getPointPos() const;
	void pointTaken();
	bool isTaken();
};


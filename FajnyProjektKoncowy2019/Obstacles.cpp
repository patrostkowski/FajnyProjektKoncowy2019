#include "Obstacles.h"


Obstacles::Obstacles(int width, int heigth, sf::RenderWindow &window)
{
	bodyRect.setSize(sf::Vector2f(width, heigth));
	bodyRect.setFillColor(sf::Color(40,30,20));
	bodyRect.setOutlineColor(sf::Color::Black);
	bodyRect.setOutlineThickness(2);
	bodyRect.setOrigin(width/2, heigth/2);
	window.draw(bodyRect);
	window.display();
}

sf::FloatRect Obstacles::getborder() const
{
	return bodyRect.getGlobalBounds();
}


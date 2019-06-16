#include "Point.h"
#include <iostream>

Point::Point(sf::RenderWindow& window)
{
		bodyPoint.setFillColor(sf::Color::Yellow);
		bodyPoint.setOutlineColor(sf::Color::Black);
		bodyPoint.setRadius(10);
		bodyPoint.setOutlineThickness(2);
		bodyPoint.setOrigin(10, 10);
		pointCheck = false;
	/*
	konstruktor ustawia wszystkie parametry punktu
	*/
}

void Point::setPos(float posx, float posy)
{
	bodyPoint.setPosition(posx, posy);
}

void Point::drawPoint(sf::RenderWindow & window)
{
		window.draw(bodyPoint);
	/*
	punkt jest przekazywany do okna do petli while
	*/
}

void Point::collision(Player &player)
{
	for (auto i = 0; i < 4; ++i)
	{
		if (player.getBorder().intersects(bodyPoint.getGlobalBounds())) //przekazac do gameplay oraz zrobic dla kazdego punktu zeby resetowalo
		{
			bodyPoint.setPosition(-100, -100);
			std::cout << "point checked" << std::endl;
			pointCheck = true;
		}
	}
}

bool Point::isPointChecked() const
{
	if(pointCheck==true)
		return true;
	else return false;
}





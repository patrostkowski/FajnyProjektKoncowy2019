#include "Point.h"
#include <iostream>

Point::Point(sf::RenderWindow& window)
{
	for (auto i = 0; i < 4; i++)
	{
		bodyPoint[i].setFillColor(sf::Color::Yellow);
		bodyPoint[i].setOutlineColor(sf::Color::Black);
		bodyPoint[i].setRadius(10);
		bodyPoint[i].setOutlineThickness(2);
		bodyPoint[i].setOrigin(10, 10);
		pointCheck[i] = false;
	}
	/*
	konstruktor ustawia wszystkie parametry punktu
	*/
}

void Point::setPos(int indx,float posx, float posy)
{
	bodyPoint[indx].setPosition(posx, posy);
}

void Point::drawPoint(sf::RenderWindow & window)
{
	for(auto i=0;i<4;++i)
		window.draw(bodyPoint[i]);
	/*
	punkt jest przekazywany do okna do petli while
	*/
}

void Point::collision(Player &player)
{
	for (auto i = 0; i < 4; ++i)
	{
		if (player.getBorder().intersects(bodyPoint[i].getGlobalBounds())) //przekazac do gameplay oraz zrobic dla kazdego punktu zeby resetowalo
		{
			bodyPoint[i].setPosition(-100, -100);
			std::cout << "point checked" << std::endl;
			pointCheck[i] = true;
		}
	}
}

bool Point::isPointChecked(int a) const
{
	if(pointCheck[a]==true)
		return true;
	else return false;
}





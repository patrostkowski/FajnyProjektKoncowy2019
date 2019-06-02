#include "Point.h"
#include <iostream>

Point::Point(sf::RenderWindow& window)
{
	bodyCircle.setFillColor(sf::Color::Yellow);
	bodyCircle.setOutlineColor(sf::Color::Black);
	bodyCircle.setRadius(10);
	bodyCircle.setOutlineThickness(2);
	bodyCircle.setOrigin(5, 5);
	taken = false;

	/*
	konstruktor ustawia wszystkie parametry punktu
	*/
}

void Point::setPos(float posx, float posy)
{
	bodyCircle.setPosition(posx, posy);
}

void Point::drawPoint(sf::RenderWindow & window)
{
	window.draw(bodyCircle);

	/*
	punkt jest przekazywany do okna do petli while
	*/
}

sf::FloatRect Point::getBorder() const
{
	return bodyCircle.getGlobalBounds();
}

void Point::pointTaken()
{
	taken = true;
	bodyCircle.setPosition(9999, 9999);
	/*
	funkcja pomocnicza - gdy punkt zostaje zdobyty zostaje przeniosiony poza ekran gry
	*/
}

bool Point::isTaken()
{
	return taken;
}





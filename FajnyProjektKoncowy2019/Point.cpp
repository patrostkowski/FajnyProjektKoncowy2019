#include "Point.h"
#include <iostream>

Point::Point(float x, float y, sf::RenderWindow& window)
{
	point.setFillColor(sf::Color::Yellow);
	point.setOutlineColor(sf::Color::Black);
	point.setRadius(10);
	point.setOutlineThickness(2);
	point.setOrigin(5, 5);
	point.setPosition(x, y);
	taken = false;

	/*
	konstruktor ustawia wszystkie parametry punktu
	*/
}

void Point::drawPoint(sf::RenderWindow & window)
{
	window.draw(point);

	/*
	punkt jest przekazywany do okna do petli while
	*/
}

sf::FloatRect Point::getPointPos() const
{
	return point.getGlobalBounds();
}

void Point::pointTaken()
{
	taken = true;
	point.setPosition(9999, 9999);

	/*
	funkcja pomocnicza - gdy punkt zostaje zdobyty zostaje przeniosiony poza ekran gry
	*/
}




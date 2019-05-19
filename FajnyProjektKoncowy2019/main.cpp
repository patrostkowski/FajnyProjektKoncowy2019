#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Point.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);

	Point point1(152, 100, window);
	Point point2(521, 424, window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (player.getPlayerPos().intersects(point1.getPointPos()))
			{
				std::cout << "XD\n";
				point1.pointTaken();
			}
		}
		window.clear(sf::Color::White);

		point1.setPoint(window);
		point2.setPoint(window);

		player.playerMovement(window); //przekazac do gameplay

	}
	window.clear();
	window.display();

	return 0;
}
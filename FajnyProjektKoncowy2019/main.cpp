#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);
	Enemy enemy(800,300,window);
	Point point1(300,200,window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		enemy.enemyMove(window);

		point1.drawPoint(window);

	//	enemy.drawEnemy(window);

		if (player.getPlayerPos().intersects(point1.getPointPos()))
		{
			point1.pointTaken();
			std::cout << "XD\n";
		}

		player.playerMovement(window); //przekazac do gameplay

	}
	window.clear();
	window.display();

	return 0;
}
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);
	Enemy enemy(800,300,LEFT,window); //przekazac do gameplay
	Point point1(300,200,window); //przekazac do gameplay

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		enemy.moveAxisXLeft(window, 100.0f, 0.01f); //przekazac do gameplay
//		enemy.moveAxisXRight(window, 850.0f, 0.01f); //przekazac do gameplay
//		enemy.switchAxis(window);

		point1.drawPoint(window); //przekazac do gameplay

		if (player.getPlayerPos().intersects(point1.getPointPos())) //przekazac do gameplay
		{
			point1.pointTaken();
			std::cout << "XD\n";
		}

		if (player.getPlayerPos().intersects(enemy.getEnemyPos())) //przekazac do gameplay
		{
			player.resetPos();
			std::cout << "AHA\n";
		}

		player.playerMovement(window); //przekazac do gameplay

	}

	window.clear();
	window.display();

	return 0;
}
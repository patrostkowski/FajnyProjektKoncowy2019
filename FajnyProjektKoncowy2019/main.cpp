#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);
	Enemy enemy1(200,300,RIGHT,window); //przekazac do gameplay
	Enemy enemy2(700,300,UP,window); //przekazac do gameplay
	Enemy enemy3(500,500,TOP,window); //przekazac do gameplay
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

		enemy1.moveAxisX(window, 600, 810); //przekazac do gameplay
		enemy2.moveAxisY(window, 200, 400);
		enemy3.SlantRise(window, 300, 600);

		point1.drawPoint(window); //przekazac do gameplay

		if (player.getPlayerBorder().intersects(point1.getPointBorder())) //przekazac do gameplay oraz zrobic dla kazdego punktu zeby resetowalo
		{
			point1.pointTaken();
			std::cout << "Point taken\n";
		}

		if (player.getPlayerBorder().intersects(enemy1.getEnemyBorder())) //przekazac do gameplay oraz reset dla kazdego enemy
		{
			player.resetPos();
			std::cout << "Player reset\n";
		}

		player.playerMovement(window); //przekazac do gameplay
	}

	window.clear();
	window.display();

	return 0;
}
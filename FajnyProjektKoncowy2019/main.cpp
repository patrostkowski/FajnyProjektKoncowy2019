#include <iostream>
#include "SFML/Graphics.hpp"
#include "Particle.h"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);
	Enemy enemy1(SLANTBOTTOM,0.01f,window); //przekazac do gameplay
	Point point1(window); //przekazac do gameplay

	player.setPos(800, 500);
	enemy1.setPos(400, 400);
	point1.setPos(300, 400);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		enemy1.SlantFall(window, 300, 600); //przekazac do gameplay

		point1.drawPoint(window); //przekazac do gameplay

		if (player.getBorder().intersects(point1.getBorder())) //przekazac do gameplay oraz zrobic dla kazdego punktu zeby resetowalo
		{
			point1.pointTaken();
			std::cout << "Point taken\n";
		}

		if (player.getBorder().intersects(enemy1.getBorder())) //przekazac do gameplay oraz reset dla kazdego enemy
		{
			player.resetPos();
			std::cout << "Player reset\n";
		}

		player.playerMovement(window); //przekazac do gameplay
		window.display();
	}

	window.clear();
	window.display();

	return 0;
}
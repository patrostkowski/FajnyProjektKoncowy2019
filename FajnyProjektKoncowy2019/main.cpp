#include <iostream>
#include "SFML/Graphics.hpp"
#include <vector>
#include "Particle.h"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);

	Enemy Enemy1(3,SLANTBOTTOM,0.03f,window); //przekazac do gameplay
	Enemy Enemy2(6,LEFT,0.03f,window); //przekazac do gameplay

	Point points(window); //przekazac do gameplay

	player.setPos(800, 500);
	points.setPos(0,300, 400);
	points.setPos(1,600, 400);
	points.setPos(2,300, 700);
	points.setPos(3,600, 700);

	Enemy1.setPos(0, 100, 100);
	Enemy1.setPos(1, 200, 100);
	Enemy1.setPos(2, 300, 100);

	for (auto i = 0; i < 6; ++i)
	{
		Enemy2.setPos(i, 300, 100+i * 100);
	}


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear(sf::Color::White);

		Enemy1.SlantFall(window, 300, 600); //przekazac do gameplay
		Enemy2.moveAxisX(window, 200, 600); //przekazac do gameplay

		points.drawPoint(window); //przekazac do gameplay
/*
		if (player.getBorder().intersects(point1.getBorder())) //przekazac do gameplay oraz zrobic dla kazdego punktu zeby resetowalo
		{
			point1.pointTaken();
		}
*/
		points.collision(player);
		Enemy1.collision(player);
		Enemy2.collision(player);
/*
		if (player.getBorder().intersects(enemies.getBorder())) //przekazac do gameplay oraz reset dla kazdego enemy
		{
			player.resetPos();
		}
*/

		player.playerMovement(window); //przekazac do gameplay
		window.display();
	}

	window.clear();
	window.display();

	return 0;
}
#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);
	Enemy enemyX(800,300,RIGHT,window); //przekazac do gameplay
	Enemy enemyY(700,300,UP,window); //przekazac do gameplay
	Enemy enemySlant(500,500,TOP,window); //przekazac do gameplay
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

		enemyX.moveAxisX(window, 790, 810); //przekazac do gameplay
		enemyY.moveAxisY(window, 290, 310);
		enemySlant.moveSlant(window, 490, 510, 1);

		point1.drawPoint(window); //przekazac do gameplay

		if (player.getPlayerPos().intersects(point1.getPointPos())) //przekazac do gameplay oraz zrobic dla kazdego punktu zeby resetowalo
		{
			point1.pointTaken();
			std::cout << "XD\n";
		}

		if (player.getPlayerPos().intersects(enemyX.getEnemyPos())) //przekazac do gameplay oraz reset dla kazdego enemy
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
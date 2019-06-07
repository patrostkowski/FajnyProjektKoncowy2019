#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Particle.h"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"
#include "Obstacles.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");
	sf::Music music;
	sf::Clock timer;

	Player player(window);

	Enemy Enemy1(3,SLANTBOTTOM,0.03f,window); //przekazac do gameplay
	Enemy Enemy2(6,LEFT,0.03f,window); //przekazac do gameplay

	Obstacles obstacle(100, 300, window);
	obstacle.setPos(500, 500);

	Point points(window); //przekazac do gameplay

	music.openFromFile("song.wav");
	if (!music.openFromFile("song.wav"))
	{
		std::cout << "could not load music!";
	}
	music.setVolume(1);
	music.play();
	music.setLoop(true);

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

		if (timer.getElapsedTime().asMicroseconds() > 0.0166)
		{
			window.clear(sf::Color::White);

			obstacle.draw(window);
			obstacle.collision(player);

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
			window.clear();
			timer.restart();
		}
	}
	return 0;
}
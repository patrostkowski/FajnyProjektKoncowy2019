#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Particle.h"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"
#include "Obstacles.h"
#include "Sound.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");
	sf::Clock timer;

	Sound music("theme");
	Sound sounds;

	Player player(window);

	Enemy Enemy1(4,RIGHT,0.03f,window); //przekazac do gameplay
	Enemy Enemy2(4,LEFT,0.03f,window); //przekazac do gameplay

	Obstacles obstacle(300, 600, window);
	Obstacles obstacle2(300, 600, window);
	obstacle.setPos(300, 400);
	obstacle2.setPos(750, 400);

	Point points(window); //przekazac do gameplay

	player.setPos(50, 50);

	points.setPos(0,500, 350);
	points.setPos(1,50, 700);
	points.setPos(2,1000, 700);
	points.setPos(3,1000, 50);

	Enemy1.setPos(0, 455, 110);
	Enemy1.setPos(1, 455, 110+142);
	Enemy1.setPos(2, 455, 110+142*2);
	Enemy1.setPos(3, 455, 110+142*3);

	for (auto i = 0; i < 6; ++i)
	{
		Enemy2.setPos(i, 580, 160+i * 142);
	}


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			system("cls");
			sf::Vector2i mousepos = sf::Mouse::getPosition(window);
			std::cout<< "X:" << mousepos.x << std::endl;
			std::cout << "Y:" << mousepos.y << std::endl;
		}

		if (timer.getElapsedTime().asMicroseconds() > 0.0166)
		{
			window.clear(sf::Color::White);

			obstacle.draw(window);
			obstacle2.draw(window);
			obstacle.collision(player);
			obstacle2.collision(player);

			Enemy1.moveAxisX(window, 460, 580); //przekazac do gameplay
			Enemy2.moveAxisX(window, 460, 580); //przekazac do gameplay

			points.drawPoint(window); //przekazac do gameplay

			points.collision(player);

			Enemy2.collision(player);

			player.playerMovement(window); //przekazac do gameplay

			if (Enemy1.collision(player) == true)
				sounds.playSound(1);

			window.display();
			window.clear();
			timer.restart();
		}
	}
	return 0;
}
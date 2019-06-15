#include <iostream>
#include "SFML/Graphics.hpp"
#include "SFML/Audio.hpp"
#include "Particle.h"
#include "Player.h"
#include "Point.h"
#include "Enemy.h"
#include "Obstacles.h"
#include "Sound.h"
#include "Level.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");
	sf::Clock timer;

	Sound music("theme");
	Sound sounds;

	Player player(window);
	Level Level1(LEVEL1);

	Point points(window); //przekazac do gameplay
	Obstacles obstacle(300, 600, window);

	player.setPos(50, 50);

	obstacle.setSize(0, 400.f, 125.f);
	obstacle.setPos(0, 200.f, 140.f);
	obstacle.setSize(1, 400.f, 125.f);
	obstacle.setPos(1, 200.f, 140.f + 200.f);
	obstacle.setSize(2, 400.f, 125.f);
	obstacle.setPos(2, 200.f, 140.f + 400.f);
	obstacle.setSize(3, 250.f, 380.f);
	obstacle.setPos(3, 600.f, 420.f);
	obstacle.setSize(4, 350.f, 90.f);
	obstacle.setPos(4, 650.f, 125.f);

	points.setPos(0,15, 240);
	points.setPos(1,15, 440);
	points.setPos(2,770, 40);
	points.setPos(3,765, 580);

	std::vector<Enemy> vec_lvl1;

	for (auto i = 0; i < 10; ++i)
	{
		vec_lvl1.emplace_back(0.1f, window);
	}

	vec_lvl1[0].setPos(50, 225);
	vec_lvl1[0].setDir(RIGHT);

	vec_lvl1[1].setPos(375, 425);
	vec_lvl1[1].setDir(LEFT);

	vec_lvl1[2].setPos(50, 455);
	vec_lvl1[2].setDir(RIGHT);

	vec_lvl1[3].setPos(375, 255);
	vec_lvl1[3].setDir(LEFT);


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

		if (timer.getElapsedTime().asMicroseconds() > 0.001)
		{
			window.clear(sf::Color::White);

			player.playerMovement(window); //przekazac do gameplay

			obstacle.draw(window);
			points.drawPoint(window); //przekazac do gameplay

			obstacle.collision(player);
			points.collision(player);

			vec_lvl1[0].moveAxisX(window, 50, 375);
			vec_lvl1[1].moveAxisX(window, 50, 375);
			vec_lvl1[2].moveAxisX(window, 50, 375);
			vec_lvl1[3].moveAxisX(window, 50, 375);


			window.display();
			window.clear();
			timer.restart();
		}
	}
	return EXIT_SUCCESS;
}
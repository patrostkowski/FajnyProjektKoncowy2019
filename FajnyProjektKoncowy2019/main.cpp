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
	Enemy enemy1_grp1(2,RIGHT,0.05f,window); //przekazac do gameplay
	Enemy enemy1_grp2(2,LEFT,0.05f,window); //przekazac do gameplay
	Enemy enemy1_grp3(2, DOWN, 0.05f, window); //przekazac do gameplay

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

	enemy1_grp1.setPos(0, 50, 225);
	enemy1_grp1.setPos(1, 50, 425);

	enemy1_grp2.setPos(0, 375, 255);
	enemy1_grp2.setPos(1, 375, 455);

	enemy1_grp3.setPos(0, 425, 95);
	enemy1_grp3.setPos(1, 455, 95);



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

			enemy1_grp1.moveAxisX(window, 50, 375); //przekazac do gameplay
			enemy1_grp2.moveAxisX(window, 50, 375); //przekazac do gameplay
			enemy1_grp3.moveAxisY(window, 95, 575); //przekazac do gameplay

			enemy1_grp1.collision(player);
			enemy1_grp2.collision(player);
			enemy1_grp3.collision(player);


			window.display();
			window.clear();
			timer.restart();
		}
	}
	return EXIT_SUCCESS;
}
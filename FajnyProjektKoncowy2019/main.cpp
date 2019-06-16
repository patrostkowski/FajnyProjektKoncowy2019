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

enum GameLayer
{
	MAINMENU, LEVEL1
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "The Game");
	sf::Clock timer;
	Level lvl;

	GameLayer gamelayer=MAINMENU;

	Sound music("theme");
	Sound sounds;

	Player player(window);

	lvl.setup_lvl1(window, player);

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

			switch (gamelayer)
			{
			case MAINMENU:
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter))
					gamelayer = LEVEL1;
				break;
			}
			case LEVEL1:
			{
				lvl.draw_lvl1(window, player);
			
				if(lvl.end_lvl1()==true)
					gamelayer = MAINMENU;
					
				break;
			}
			}
/*
			player.playerMovement(window); //przekazac do gameplay

			obstacle.draw(window);
			points.drawPoint(window); //przekazac do gameplay

			obstacle.collision(player);
			points.collision(player);

			vec_lvl1[0].moveAxisX(window, 50, 375);
			vec_lvl1[1].moveAxisX(window, 50, 375);
			vec_lvl1[2].moveAxisX(window, 50, 375);
			vec_lvl1[3].moveAxisX(window, 50, 375);
			vec_lvl1[4].moveAxisX(window, 500, 730);
			vec_lvl1[5].moveAxisX(window, 500, 730);
			vec_lvl1[6].moveAxisY(window, 100, 575);
			vec_lvl1[7].moveAxisY(window, 100, 575);
			vec_lvl1[8].moveAxisY(window, 225, 525);
			vec_lvl1[9].moveAxisY(window, 225, 525);

			vec_lvl1[0].collision(player);
			vec_lvl1[1].collision(player);
			vec_lvl1[2].collision(player);
			vec_lvl1[3].collision(player);
			vec_lvl1[4].collision(player);
			vec_lvl1[5].collision(player);
			vec_lvl1[6].collision(player);
			vec_lvl1[7].collision(player);
			vec_lvl1[8].collision(player);
			vec_lvl1[9].collision(player);
*/
			window.display();
			window.clear();
			timer.restart();
		}
	}
	return EXIT_SUCCESS;
}
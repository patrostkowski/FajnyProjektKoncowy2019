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
#include "MainMenu.h"

enum GameLayer
{
	GAMESETUP, MAINMENU, LEVEL1
};

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Super Fajen Giera");
	sf::Clock timer;
	Level lvl;
	MainMenu menu(window);

	GameLayer gamelayer=GAMESETUP;

	Sound music("theme");

	Player player(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::KeyReleased:
			{
				switch (event.key.code)
				{
				case sf::Keyboard::Up:
					{
					menu.MoveUp();
						break;
					}
				case sf::Keyboard::Down:
				{
					menu.MoveDown();
					break;
				}
				case sf::Keyboard::Return:
				{
					switch(menu.getPressedItem())
					{
					case 0:
					{
						gamelayer = LEVEL1;
						break;
					}
					case 1:
					{
						if (music.isMusicMuted() == false)
							music.muteSound();
						else
							music.unmuteSound();
						break;
					}
					case 2:
					{
						exit(EXIT_SUCCESS);
						break;
					}
					}
					break;
				}
				}
				break;
			}
			case sf::Event::Closed:
			{
				window.close();
				break;
			}
			}
		}
/*
		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			system("cls");
			sf::Vector2i mousepos = sf::Mouse::getPosition(window);
			std::cout<< "X:" << mousepos.x << std::endl;
			std::cout << "Y:" << mousepos.y << std::endl;
		}
*/
		if (timer.getElapsedTime().asMicroseconds() > 0.001)
		{
			window.clear(sf::Color::White);

			switch (gamelayer)
			{
			case GAMESETUP:
			{
				lvl.setup_lvl1(window, player);
				gamelayer = MAINMENU;
				break;
			}
			case MAINMENU:
			{
				menu.draw(window);
				break;
			}
			case LEVEL1:
			{
				lvl.draw_lvl1(window, player);
			
				if(lvl.end_lvl1()==true)
					gamelayer = GAMESETUP;
					
				break;
			}
			}
			window.display();
			window.clear();
			timer.restart();
		}
	}
	return EXIT_SUCCESS;
}
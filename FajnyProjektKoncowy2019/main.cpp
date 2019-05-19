#include <iostream>
#include "SFML/Graphics.hpp"
#include "Player.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(1024, 768), "The Game");

	Player player(window);

	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}
		window.clear(sf::Color::White);
		player.playerMovement(window);
	}
	window.display();

	return 0;
}
#pragma once
#include "SFML/Graphics.hpp"

class Player
{
	sf::RectangleShape player;
public:
	Player(sf::RenderWindow& window);
	void playerMovement(sf::RenderWindow& window);
	sf::FloatRect getPlayerPos() const;
};


#pragma once
#include "SFML/Graphics.hpp"
class MainMenu
{
	int selectedItem;
	sf::Font font;
	sf::Text menu[3];
	sf::Texture banner;
	sf::Sprite top;
public:
	MainMenu(sf::RenderWindow &window);
	void draw(sf::RenderWindow &window);
	void MoveUp();
	void MoveDown();
	int getPressedItem() const;
};


#include "MainMenu.h"

MainMenu::MainMenu(sf::RenderWindow &window)
{
	if (!font.loadFromFile("comicsans.ttf"))
	{

	}

	if (!banner.loadFromFile("baner.png"))
	{

	}

	top.setTexture(banner);
	top.setPosition(285, 25);

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(100, 200));
	menu[0].setCharacterSize(100);

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::Blue);
	menu[1].setString("Mute Sounds");
	menu[1].setPosition(sf::Vector2f(100, 300));
	menu[1].setCharacterSize(100);

	menu[2].setFont(font);
	menu[2].setFillColor(sf::Color::Blue);
	menu[2].setString("Exit");
	menu[2].setPosition(sf::Vector2f(100, 400));
	menu[2].setCharacterSize(100);

	selectedItem = 0;
}

void MainMenu::draw(sf::RenderWindow & window)
{
	for (auto i = 0; i < 3; ++i)
	{
		window.draw(menu[i]);
	}
	window.draw(top);
}

void MainMenu::MoveUp()
{
	if (selectedItem - 1 >= 0)
	{
		menu[selectedItem].setFillColor(sf::Color::Blue);
		selectedItem--;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

void MainMenu::MoveDown()
{
	if (selectedItem + 1 < 3)
	{
		menu[selectedItem].setFillColor(sf::Color::Blue);
		selectedItem++;
		menu[selectedItem].setFillColor(sf::Color::Red);
	}
}

int MainMenu::getPressedItem() const
{
	return selectedItem;
}

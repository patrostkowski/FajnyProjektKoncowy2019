#include "Player.h"

Player::Player(sf::RenderWindow& window)
{
	player.setFillColor(sf::Color::Red);
	player.setOutlineColor(sf::Color::Black);
	player.setSize(sf::Vector2f(20, 20));
	player.setOutlineThickness(2);
	player.setOrigin(5, 5);
	player.setPosition(512, 384);
	window.draw(player);
	window.display();

	/*
	konstruktor ustawia wszystkie opcje gracza: kolor rozmiar pozycje itd.
	*/
}

void Player::playerMovement(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		player.move(-0.05f, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		player.move(0.05f, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		player.move(0, -0.05f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		player.move(0, 0.05f);

	window.draw(player);
	window.display();

	/*
	proste menu sterowania
	*/
}

sf::FloatRect Player::getPlayerBorder() const
{
	return player.getGlobalBounds();
}

void Player::resetPos()
{
	player.setPosition(512, 384);
}



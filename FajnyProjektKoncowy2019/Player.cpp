#include "Player.h"

Player::Player(sf::RenderWindow& window)
{	
	bodyRect.setFillColor(sf::Color::Red);
	bodyRect.setOutlineColor(sf::Color::Black);
	bodyRect.setSize(sf::Vector2f(20, 20));
	bodyRect.setOutlineThickness(2);
	bodyRect.setOrigin(10, 10);
	window.draw(bodyRect);
	window.display();

	/*
	konstruktor ustawia wszystkie opcje gracza: kolor rozmiar pozycje itd.
	*/
}

void Player::setPos(float posx, float posy)
{
	bodyRect.setPosition(posx, posy);
}

void Player::playerMovement(sf::RenderWindow& window)
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		bodyRect.move(-0.05f, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		bodyRect.move(0.05f, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		bodyRect.move(0, -0.05f);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		bodyRect.move(0, 0.05f);

	if (bodyRect.getPosition().x < 12.f)
		bodyRect.setPosition(12.f, bodyRect.getPosition().y);
	if (bodyRect.getPosition().y < 12.f)
		bodyRect.setPosition(bodyRect.getPosition().x, 12.f);
	if (bodyRect.getPosition().x + bodyRect.getGlobalBounds().width > 1037.f)
		bodyRect.setPosition(1037.f - bodyRect.getGlobalBounds().width, bodyRect.getPosition().y);
	if (bodyRect.getPosition().y + bodyRect.getGlobalBounds().height > 780.f)
		bodyRect.setPosition(bodyRect.getPosition().x, 780.f - bodyRect.getGlobalBounds().height);

	window.draw(bodyRect);

	/*
	proste menu sterowania
	*/
}

sf::FloatRect Player::getBorder() const
{
	return bodyRect.getGlobalBounds();
}

void Player::resetPos()
{
	std::cout << "Player reset\n";
	bodyRect.setPosition(20, 20);
}



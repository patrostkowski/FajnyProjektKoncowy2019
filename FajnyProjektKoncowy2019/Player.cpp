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
		bodyRect.move(-speed, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		bodyRect.move(speed, 0);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		bodyRect.move(0, -speed);
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		bodyRect.move(0, speed);

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

float Player::getBorderLeft() const
{
	return bodyRect.getGlobalBounds().left;
}

float Player::getBorderTop() const
{
	return bodyRect.getGlobalBounds().top;
}

float Player::getBorderWidth() const
{
	return bodyRect.getGlobalBounds().width;
}

float Player::getBorderHeight() const
{
	return bodyRect.getGlobalBounds().height;
}

void Player::resetPos()
{
	std::cout << "Player reset\n";
	bodyRect.setPosition(20, 20);
}

float Player::getPlayerX() const
{
	return bodyRect.getPosition().x;
}

float Player::getPlayerY() const
{
	return bodyRect.getPosition().y;
}



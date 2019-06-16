#include "Obstacles.h"


Obstacles::Obstacles(sf::RenderWindow &window)
{
	bodyRect.setFillColor(sf::Color(105, 105, 105));
	bodyRect.setOutlineColor(sf::Color::Black);
	bodyRect.setOutlineThickness(2);
	window.draw(bodyRect);
	window.display();
}

sf::FloatRect Obstacles::getBorder() const
{
	return bodyRect.getGlobalBounds();
}

void Obstacles::setSize(float posx, float posy)
{
	bodyRect.setOrigin(posx / 2, posy / 2);
	bodyRect.setSize(sf::Vector2f(posx, posy));
}

void Obstacles::setPos(float posx, float posy)
{
	bodyRect.setPosition(posx, posy);
}

void Obstacles::draw(sf::RenderWindow & window)
{
	window.draw(bodyRect);
}

void Obstacles::collision(Player & player)
{
	float left, right, top, bottom;

	left = bodyRect.getGlobalBounds().left - 12.f;
	right = bodyRect.getGlobalBounds().left + bodyRect.getSize().x + 14.f;
	top = bodyRect.getGlobalBounds().top - bodyRect.getSize().y / 2 - 13.f;
	bottom = bodyRect.getGlobalBounds().top + bodyRect.getSize().y / 2 + 13.f;

	if (bodyRect.getGlobalBounds().intersects(player.getBorder()))
	{
		//X

		if (player.getBorderLeft() < bodyRect.getGlobalBounds().left &&
			player.getBorderLeft() + player.getBorderWidth() < bodyRect.getGlobalBounds().left + bodyRect.getGlobalBounds().width &&
			player.getBorderTop() < bodyRect.getGlobalBounds().top + bodyRect.getGlobalBounds().height &&
			player.getBorderTop() + player.getBorderHeight() > bodyRect.getGlobalBounds().top)
		{
			player.setPos(bodyRect.getGlobalBounds().left - 12.f, player.getPlayerY());
		}
		else if (player.getBorderLeft() > bodyRect.getGlobalBounds().left &&
			player.getBorderLeft() + player.getBorderWidth() > bodyRect.getGlobalBounds().left + bodyRect.getGlobalBounds().width &&
			player.getBorderTop() < bodyRect.getGlobalBounds().top + bodyRect.getGlobalBounds().height &&
			player.getBorderTop() + player.getBorderHeight() > bodyRect.getGlobalBounds().top)
		{
			player.setPos(bodyRect.getGlobalBounds().left + 16.f + bodyRect.getSize().x, player.getPlayerY());
		}

		// Y

		if (player.getBorderTop() < bodyRect.getGlobalBounds().top &&
			player.getBorderTop() + player.getBorderHeight() < bodyRect.getGlobalBounds().top + bodyRect.getGlobalBounds().height &&
			player.getBorderLeft() < bodyRect.getGlobalBounds().left + bodyRect.getGlobalBounds().width &&
			player.getBorderLeft() + player.getBorderWidth() > bodyRect.getGlobalBounds().left)
		{
			player.setPos(player.getPlayerX(), bodyRect.getGlobalBounds().top - 12.f);
		}
		else if (player.getBorderTop() > bodyRect.getGlobalBounds().top &&
			player.getBorderTop() + player.getBorderHeight() > bodyRect.getGlobalBounds().top + bodyRect.getGlobalBounds().height &&
			player.getBorderLeft() < bodyRect.getGlobalBounds().left + bodyRect.getGlobalBounds().width &&
			player.getBorderLeft() + player.getBorderWidth() > bodyRect.getGlobalBounds().left)
		{
			player.setPos(player.getPlayerX(), bodyRect.getGlobalBounds().top + 16.f + bodyRect.getSize().y);
		}
	}
}


#include "Obstacles.h"


Obstacles::Obstacles(int width, int heigth, sf::RenderWindow &window)
{
	for (auto i = 0; i < 10; i++)
	{
		bodyRect[i].setFillColor(sf::Color(105, 105, 105));
		bodyRect[i].setOutlineColor(sf::Color::Black);
		bodyRect[i].setOutlineThickness(2);
		window.draw(bodyRect[i]);
	}
	window.display();
}

sf::FloatRect Obstacles::getBorder(int indx) const
{
	return bodyRect[indx].getGlobalBounds();
}

void Obstacles::setSize(int indx, float posx, float posy)
{
	bodyRect[indx].setOrigin(posx / 2, posy / 2);
	bodyRect[indx].setSize(sf::Vector2f(posx, posy));
}

void Obstacles::setPos(int indx,float posx, float posy)
{
	bodyRect[indx].setPosition(posx, posy);
}

void Obstacles::draw(sf::RenderWindow & window)
{
	for (auto i = 0; i < 10; i++)
		window.draw(bodyRect[i]);
}

void Obstacles::collision(Player & player)
{
	float left, right, top, bottom;
	for (auto i = 0; i < 10; i++)
	{
	left = bodyRect[i].getGlobalBounds().left - 12.f;
	right = bodyRect[i].getGlobalBounds().left + bodyRect[i].getSize().x + 14.f;
	top = bodyRect[i].getGlobalBounds().top - bodyRect[i].getSize().y / 2 - 13.f;
	bottom = bodyRect[i].getGlobalBounds().top + bodyRect[i].getSize().y / 2 + 13.f;

	if (bodyRect[i].getGlobalBounds().intersects(player.getBorder()))
	{
		//X

		if (player.getBorderLeft() < bodyRect[i].getGlobalBounds().left &&
			player.getBorderLeft() + player.getBorderWidth() < bodyRect[i].getGlobalBounds().left + bodyRect[i].getGlobalBounds().width &&
			player.getBorderTop() < bodyRect[i].getGlobalBounds().top + bodyRect[i].getGlobalBounds().height &&
			player.getBorderTop() + player.getBorderHeight() > bodyRect[i].getGlobalBounds().top)
		{
			player.setPos(bodyRect[i].getGlobalBounds().left - 12.f, player.getPlayerY());
		}
		else if (player.getBorderLeft() > bodyRect[i].getGlobalBounds().left &&
			player.getBorderLeft() + player.getBorderWidth() > bodyRect[i].getGlobalBounds().left + bodyRect[i].getGlobalBounds().width &&
			player.getBorderTop() < bodyRect[i].getGlobalBounds().top + bodyRect[i].getGlobalBounds().height &&
			player.getBorderTop() + player.getBorderHeight() > bodyRect[i].getGlobalBounds().top)
		{
			player.setPos(bodyRect[i].getGlobalBounds().left + 16.f + bodyRect[i].getSize().x, player.getPlayerY());
		}

		// Y

		if (player.getBorderTop() < bodyRect[i].getGlobalBounds().top &&
			player.getBorderTop() + player.getBorderHeight() < bodyRect[i].getGlobalBounds().top + bodyRect[i].getGlobalBounds().height &&
			player.getBorderLeft() < bodyRect[i].getGlobalBounds().left + bodyRect[i].getGlobalBounds().width &&
			player.getBorderLeft() + player.getBorderWidth() > bodyRect[i].getGlobalBounds().left)
		{
			player.setPos(player.getPlayerX(), bodyRect[i].getGlobalBounds().top - 12.f);
		}
		else if (player.getBorderTop() > bodyRect[i].getGlobalBounds().top &&
			player.getBorderTop() + player.getBorderHeight() > bodyRect[i].getGlobalBounds().top + bodyRect[i].getGlobalBounds().height &&
			player.getBorderLeft() < bodyRect[i].getGlobalBounds().left + bodyRect[i].getGlobalBounds().width &&
			player.getBorderLeft() + player.getBorderWidth() > bodyRect[i].getGlobalBounds().left)
		{
			player.setPos(player.getPlayerX(), bodyRect[i].getGlobalBounds().top + 16.f + bodyRect[i].getSize().y);
		}
	}
	}
}


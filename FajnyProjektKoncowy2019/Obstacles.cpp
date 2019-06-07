#include "Obstacles.h"


Obstacles::Obstacles(int width, int heigth, sf::RenderWindow &window)
{
	bodyRect.setSize(sf::Vector2f(width, heigth));
	bodyRect.setFillColor(sf::Color(105, 105, 105));
	bodyRect.setOutlineColor(sf::Color::Black);
	bodyRect.setOutlineThickness(2);
	bodyRect.setOrigin(width/2, heigth/2);
	bodyRect.setPosition(500, 500);
	window.draw(bodyRect);
	window.display();
}

sf::FloatRect Obstacles::getBorder() const
{
	return bodyRect.getGlobalBounds();
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
	if (bodyRect.getGlobalBounds().intersects(player.getBorder()))
	{
		std::cout << "XDD" << std::endl;
	}
}


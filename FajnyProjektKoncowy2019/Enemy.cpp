#include "Enemy.h"
#include <iostream>

Enemy::Enemy(int count, Dir dir, float speed, sf::RenderWindow & window)
{
	for (auto i = 0; i < count; i++)
	{
		bodyEnemy[i].setFillColor(sf::Color::Blue);
		bodyEnemy[i].setOutlineColor(sf::Color::Black);
		bodyEnemy[i].setRadius(10);
		bodyEnemy[i].setOutlineThickness(2);
		bodyEnemy[i].setOrigin(10, 10);
		this->speed = speed;
		direction = dir;
	}
}

void Enemy::setPos(int indx, float posx, float posy)
{
	bodyEnemy[indx].setPosition(posx, posy);
}

bool Enemy::collision(Player & player)
{
	for (auto i = 0; i < 4; i++)
	{
		if (player.getBorder().intersects(bodyEnemy[i].getGlobalBounds())) //przekazac do gameplay oraz reset dla kazdego enemy
		{
			player.resetPos();
			return true;
		}
	}
	return false;
}

void Enemy::moveAxisX(sf::RenderWindow & window, float min, float max)
{	
	for (auto i = 0; i < 2; i++)
	{
//		std::cout << i << " x: " << bodyEnemy[i].getPosition().x << std::endl;
//		std::cout << i << " y: " << bodyEnemy[i].getPosition().y << std::endl;
		window.draw(bodyEnemy[i]);

		switch (direction)
		{
		case LEFT:
		{
			bodyEnemy[i].move(sf::Vector2f(-speed, 0));
			if (bodyEnemy[i].getPosition().x <= min)
				direction = RIGHT;

			break;
		}
		case RIGHT:
		{
			bodyEnemy[i].move(sf::Vector2f(speed, 0));
			if (bodyEnemy[i].getPosition().x >= max)
				direction = LEFT;

			break;
		}
		}


	}
}

void Enemy::moveAxisY(sf::RenderWindow & window, float min, float max)
{
	for (auto i = 0; i < 2; i++)
	{
		window.draw(bodyEnemy[i]);

		switch (direction)
		{
		case UP:
		{
			bodyEnemy[i].move(sf::Vector2f(0, -speed));
			if (bodyEnemy[i].getPosition().y <= min)
				direction = DOWN;

			break;
		}
		case DOWN:
		{
			bodyEnemy[i].move(sf::Vector2f(0, speed));
			if (bodyEnemy[i].getPosition().y >= max)
				direction = UP;

			break;
		}
		}
	}
}

void Enemy::SlantFall(sf::RenderWindow & window, float min, float max)
{
	for (auto i = 0; i < 2; i++)
	{
		window.draw(bodyEnemy[i]);

		switch (direction)
		{
		case SLANTTOP:
		{
			bodyEnemy[i].move(sf::Vector2f(-speed, -speed));
			if (bodyEnemy[i].getPosition().y <= min)
				direction = SLANTBOTTOM;

			break;
		}
		case SLANTBOTTOM:
		{
			bodyEnemy[i].move(sf::Vector2f(speed, speed));
			if (bodyEnemy[i].getPosition().y >= max)
				direction = SLANTTOP;
			break;
		}
		}
	}
}

void Enemy::SlantRise(sf::RenderWindow & window, float min, float max)
{
	for (auto i = 0; i < 2; i++)
	{
		window.draw(bodyEnemy[i]);

		switch (direction)
		{
		case SLANTTOP:
		{
			bodyEnemy[i].move(sf::Vector2f(speed, -speed));
			if (bodyEnemy[i].getPosition().y <= min)
				direction = SLANTBOTTOM;

			break;
		}
		case SLANTBOTTOM:
		{
			bodyEnemy[i].move(sf::Vector2f(-speed, speed));
			if (bodyEnemy[i].getPosition().y >= max)
				direction = SLANTTOP;
			break;
		}
		}
	}
}

sf::FloatRect Enemy::getBorder(int indx) const
{
	return bodyEnemy[indx].getGlobalBounds();
}

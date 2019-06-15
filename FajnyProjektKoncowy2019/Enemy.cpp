#include "Enemy.h"
#include <iostream>

Enemy::Enemy(float speed, sf::RenderWindow & window)
{
	bodyEnemy.setFillColor(sf::Color::Blue);
	bodyEnemy.setOutlineColor(sf::Color::Black);
	bodyEnemy.setRadius(10);
	bodyEnemy.setOutlineThickness(2);
	bodyEnemy.setOrigin(10, 10);
	this->speed = speed;
}

void Enemy::setDir(Dir dir)
{
	direction = dir;
}

void Enemy::setPos(float posx, float posy)
{
	bodyEnemy.setPosition(posx, posy);
}

bool Enemy::collision(Player & player)
{
	if (player.getBorder().intersects(bodyEnemy.getGlobalBounds())) //przekazac do gameplay oraz reset dla kazdego enemy
	{
		player.resetPos();			
		return true;
	}
	else return false;
}

void Enemy::moveAxisX(sf::RenderWindow & window, float min, float max)
{	
		window.draw(bodyEnemy);

		switch (direction)
		{
		case LEFT:
		{
			bodyEnemy.move(sf::Vector2f(-speed, 0));
			if (bodyEnemy.getPosition().x <= min)
				direction = RIGHT;

			break;
		}
		case RIGHT:
		{
			bodyEnemy.move(sf::Vector2f(speed, 0));
			if (bodyEnemy.getPosition().x >= max)
				direction = LEFT;

			break;
		}
		}
}

void Enemy::moveAxisY(sf::RenderWindow & window, float min, float max)
{
		window.draw(bodyEnemy);

		switch (direction)
		{
		case UP:
		{
			bodyEnemy.move(sf::Vector2f(0, -speed));
			if (bodyEnemy.getPosition().y <= min)
				direction = DOWN;
			break;
		}
		case DOWN:
		{
			bodyEnemy.move(sf::Vector2f(0, speed));
			if (bodyEnemy.getPosition().y >= max)
				direction = UP;

			break;
		}
		}
}

void Enemy::SlantFall(sf::RenderWindow & window, float min, float max)
{
		window.draw(bodyEnemy);

		switch (direction)
		{
		case SLANTTOP:
		{
			bodyEnemy.move(sf::Vector2f(-speed, -speed));
			if (bodyEnemy.getPosition().y <= min)
				direction = SLANTBOTTOM;

			break;
		}
		case SLANTBOTTOM:
		{
			bodyEnemy.move(sf::Vector2f(speed, speed));
			if (bodyEnemy.getPosition().y >= max)
				direction = SLANTTOP;
			break;
		}
		}
}

void Enemy::SlantRise(sf::RenderWindow & window, float min, float max)
{
		window.draw(bodyEnemy);

		switch (direction)
		{
		case SLANTTOP:
		{
			bodyEnemy.move(sf::Vector2f(speed, -speed));
			if (bodyEnemy.getPosition().y <= min)
				direction = SLANTBOTTOM;

			break;
		}
		case SLANTBOTTOM:
		{
			bodyEnemy.move(sf::Vector2f(-speed, speed));
			if (bodyEnemy.getPosition().y >= max)
				direction = SLANTTOP;
			break;
		}
		}
}

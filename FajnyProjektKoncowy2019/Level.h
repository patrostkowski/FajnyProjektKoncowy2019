#pragma once
#include "Player.h"
#include "Point.h"
#include "Enemy.h"
#include "Obstacles.h"

class Level
{
	float enemy_speed = 0.05f;
	std::vector<Enemy> vec_lvl1;
public:
	Level();
	virtual void setup_lvl1(sf::RenderWindow &window, 
		Player &player, 
		Obstacles &obstacle,
		Point &points);
	virtual void draw_lvl1(sf::RenderWindow &window,
		Player &player,
		Obstacles &obstacle,
		Point &points);
};


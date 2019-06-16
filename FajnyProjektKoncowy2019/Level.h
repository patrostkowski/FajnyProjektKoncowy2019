#pragma once
#include "Player.h"
#include "Point.h"
#include "Enemy.h"
#include "Obstacles.h"



class Level
{

	float enemy_speed = 0.01f;
	std::vector<Enemy> vec_enemy_lvl1;
	std::vector<Obstacles> vec_obst_lvl1;
	std::vector<Point> vec_point_lvl1;
public:
	Level();
	virtual void setup_lvl1(sf::RenderWindow &window, 
		Player &player);
	virtual void draw_lvl1(sf::RenderWindow &window,
		Player &player);
	virtual bool end_lvl1();
};


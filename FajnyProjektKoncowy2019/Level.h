#pragma once
#include "Player.h"
#include "Point.h"
#include "Enemy.h"
#include "Obstacles.h"



class Level
{

	float enemy_speed = 0.01f;
	std::vector<Enemy> vec_enemy_lvl;
	std::vector<Obstacles> vec_obst_lvl;
	std::vector<Point> vec_point_lvl;
public:
	Level();

	virtual void setup_lvl1(sf::RenderWindow &window, 
		Player &player);
	virtual void draw_lvl1(sf::RenderWindow &window,
		Player &player);
	virtual bool end_lvl1();

	virtual void setup_lvl2(sf::RenderWindow &window,
		Player &player);
	virtual void draw_lvl2(sf::RenderWindow &window,
		Player &player);
	virtual bool end_lvl2();
};


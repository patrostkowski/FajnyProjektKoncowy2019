#pragma once
#include "Enemy.h"
#include "Obstacles.h"
#include "Point.h"

enum GameLevel
{
	MAINMENU, LEVEL1, LEVEL2
};

class Level
{
	GameLevel level;
public:
	Level(GameLevel level);
	void LevelOneSetup(sf::RenderWindow &window);
	void LevelOneDraw(sf::RenderWindow &window);
};


#include "Level.h"



Level::Level()
{
}

void Level::setup_lvl1(sf::RenderWindow & window, Player & player, Obstacles & obstacle, Point & points)
{
	player.setPos(50, 50);

	obstacle.setSize(0, 400.f, 125.f);
	obstacle.setPos(0, 200.f, 140.f);
	obstacle.setSize(1, 400.f, 125.f);
	obstacle.setPos(1, 200.f, 140.f + 200.f);
	obstacle.setSize(2, 400.f, 125.f);
	obstacle.setPos(2, 200.f, 140.f + 400.f);
	obstacle.setSize(3, 250.f, 380.f);
	obstacle.setPos(3, 600.f, 420.f);
	obstacle.setSize(4, 350.f, 90.f);
	obstacle.setPos(4, 650.f, 125.f);

	points.setPos(0, 15, 240);
	points.setPos(1, 15, 440);
	points.setPos(2, 770, 40);
	points.setPos(3, 765, 580);

	for (auto i = 0; i < 10; ++i)
	{
		vec_lvl1.emplace_back(enemy_speed, window);
	}

	vec_lvl1[0].setPos(50, 225);
	vec_lvl1[0].setDir(RIGHT);

	vec_lvl1[1].setPos(375, 425);
	vec_lvl1[1].setDir(LEFT);

	vec_lvl1[2].setPos(50, 455);
	vec_lvl1[2].setDir(RIGHT);

	vec_lvl1[3].setPos(375, 255);
	vec_lvl1[3].setDir(LEFT);

	vec_lvl1[4].setPos(730, 20);
	vec_lvl1[4].setDir(LEFT);

	vec_lvl1[5].setPos(500, 55);
	vec_lvl1[5].setDir(RIGHT);

	vec_lvl1[6].setPos(420, 100);
	vec_lvl1[6].setDir(DOWN);

	vec_lvl1[7].setPos(450, 575);
	vec_lvl1[7].setDir(UP);

	vec_lvl1[8].setPos(780, 525);
	vec_lvl1[8].setDir(UP);

	vec_lvl1[9].setPos(750, 225);
	vec_lvl1[9].setDir(DOWN);
}

void Level::draw_lvl1(sf::RenderWindow & window, Player & player, Obstacles & obstacle, Point & points)
{
	player.playerMovement(window); //przekazac do gameplay

	obstacle.draw(window);
	points.drawPoint(window); //przekazac do gameplay

	obstacle.collision(player);
	points.collision(player);

	vec_lvl1[0].moveAxisX(window, 50, 375);
	vec_lvl1[1].moveAxisX(window, 50, 375);
	vec_lvl1[2].moveAxisX(window, 50, 375);
	vec_lvl1[3].moveAxisX(window, 50, 375);
	vec_lvl1[4].moveAxisX(window, 500, 730);
	vec_lvl1[5].moveAxisX(window, 500, 730);
	vec_lvl1[6].moveAxisY(window, 100, 575);
	vec_lvl1[7].moveAxisY(window, 100, 575);
	vec_lvl1[8].moveAxisY(window, 225, 525);
	vec_lvl1[9].moveAxisY(window, 225, 525);

	vec_lvl1[0].collision(player);
	vec_lvl1[1].collision(player);
	vec_lvl1[2].collision(player);
	vec_lvl1[3].collision(player);
	vec_lvl1[4].collision(player);
	vec_lvl1[5].collision(player);
	vec_lvl1[6].collision(player);
	vec_lvl1[7].collision(player);
	vec_lvl1[8].collision(player);
	vec_lvl1[9].collision(player);



}

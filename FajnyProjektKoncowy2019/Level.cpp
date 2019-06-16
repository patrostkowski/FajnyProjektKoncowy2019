#include "Level.h"



Level::Level()
{

}

void Level::setup_lvl1(sf::RenderWindow & window, Player & player)
{
	player.setPos(35, 35);

	for (auto i = 0; i < 5; ++i)
	{
		vec_obst_lvl1.emplace_back(window);
	}

	for (auto i = 0; i < 10; ++i)
	{
		vec_enemy_lvl1.emplace_back(enemy_speed, window);
	}

	for (auto i = 0; i < 4; ++i)
	{
		vec_point_lvl1.emplace_back(window);
	}

	vec_obst_lvl1[0].setSize(400.f, 125.f);
	vec_obst_lvl1[0].setPos(200.f, 140.f);
	vec_obst_lvl1[1].setSize(400.f, 125.f);
	vec_obst_lvl1[1].setPos(200.f, 140.f + 200.f);
	vec_obst_lvl1[2].setSize(400.f, 125.f);
	vec_obst_lvl1[2].setPos(200.f, 140.f + 400.f);
	vec_obst_lvl1[3].setSize(250.f, 380.f);
	vec_obst_lvl1[3].setPos(600.f, 420.f);
	vec_obst_lvl1[4].setSize(350.f, 90.f);
	vec_obst_lvl1[4].setPos(650.f, 125.f);

	vec_point_lvl1[0].setPos(15, 240);
	vec_point_lvl1[1].setPos(15, 440);
	vec_point_lvl1[2].setPos(770, 40);
	vec_point_lvl1[3].setPos(765, 580);

	vec_enemy_lvl1[0].setPos(50, 225);
	vec_enemy_lvl1[0].setDir(RIGHT);

	vec_enemy_lvl1[1].setPos(375, 425);
	vec_enemy_lvl1[1].setDir(LEFT);

	vec_enemy_lvl1[2].setPos(50, 455);
	vec_enemy_lvl1[2].setDir(RIGHT);

	vec_enemy_lvl1[3].setPos(375, 255);
	vec_enemy_lvl1[3].setDir(LEFT);

	vec_enemy_lvl1[4].setPos(730, 20);
	vec_enemy_lvl1[4].setDir(LEFT);

	vec_enemy_lvl1[5].setPos(500, 55);
	vec_enemy_lvl1[5].setDir(RIGHT);

	vec_enemy_lvl1[6].setPos(420, 100);
	vec_enemy_lvl1[6].setDir(DOWN);

	vec_enemy_lvl1[7].setPos(450, 575);
	vec_enemy_lvl1[7].setDir(UP);

	vec_enemy_lvl1[8].setPos(780, 525);
	vec_enemy_lvl1[8].setDir(UP);

	vec_enemy_lvl1[9].setPos(750, 225);
	vec_enemy_lvl1[9].setDir(DOWN);
}

void Level::draw_lvl1(sf::RenderWindow & window, Player & player)
{
	player.playerMovement(window); //przekazac do gameplay

	vec_obst_lvl1[0].draw(window);
	vec_obst_lvl1[0].collision(player);
	vec_obst_lvl1[1].draw(window);
	vec_obst_lvl1[1].collision(player);
	vec_obst_lvl1[2].draw(window);
	vec_obst_lvl1[2].collision(player);
	vec_obst_lvl1[3].draw(window);
	vec_obst_lvl1[3].collision(player);
	vec_obst_lvl1[4].draw(window);
	vec_obst_lvl1[4].collision(player);

	vec_point_lvl1[0].drawPoint(window); //przekazac do gameplay
	vec_point_lvl1[0].collision(player);
	vec_point_lvl1[1].drawPoint(window); //przekazac do gameplay
	vec_point_lvl1[1].collision(player);
	vec_point_lvl1[2].drawPoint(window); //przekazac do gameplay
	vec_point_lvl1[2].collision(player);
	vec_point_lvl1[3].drawPoint(window); //przekazac do gameplay
	vec_point_lvl1[3].collision(player);

	vec_enemy_lvl1[0].moveAxisX(window, 50, 375);
	vec_enemy_lvl1[1].moveAxisX(window, 50, 375);
	vec_enemy_lvl1[2].moveAxisX(window, 50, 375);
	vec_enemy_lvl1[3].moveAxisX(window, 50, 375);
	vec_enemy_lvl1[4].moveAxisX(window, 500, 730);
	vec_enemy_lvl1[5].moveAxisX(window, 500, 730);
	vec_enemy_lvl1[6].moveAxisY(window, 100, 575);
	vec_enemy_lvl1[7].moveAxisY(window, 100, 575);
	vec_enemy_lvl1[8].moveAxisY(window, 225, 525);
	vec_enemy_lvl1[9].moveAxisY(window, 225, 525);

	vec_enemy_lvl1[0].collision(player);
	vec_enemy_lvl1[1].collision(player);
	vec_enemy_lvl1[2].collision(player);
	vec_enemy_lvl1[3].collision(player);
	vec_enemy_lvl1[4].collision(player);
	vec_enemy_lvl1[5].collision(player);
	vec_enemy_lvl1[6].collision(player);
	vec_enemy_lvl1[7].collision(player);
	vec_enemy_lvl1[8].collision(player);
	vec_enemy_lvl1[9].collision(player);
}

bool Level::end_lvl1()
{
	if (vec_point_lvl1[0].isPointChecked() == true &&
		vec_point_lvl1[1].isPointChecked() == true &&
		vec_point_lvl1[2].isPointChecked() == true &&
		vec_point_lvl1[3].isPointChecked() == true)
		return true;

	return false;
}

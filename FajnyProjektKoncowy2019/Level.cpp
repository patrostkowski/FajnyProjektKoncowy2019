#include "Level.h"



Level::Level()
{

}

void Level::setup_lvl1(sf::RenderWindow & window, Player & player)
{
	for (auto i = 0; i < 5; ++i)
	{
		vec_obst_lvl.emplace_back(window);
	}

	for (auto i = 0; i < 10; ++i)
	{
		vec_enemy_lvl.emplace_back(enemy_speed, window);
	}

	for (auto i = 0; i < 4; ++i)
	{
		vec_point_lvl.emplace_back(window);
	}

	vec_obst_lvl[0].setSize(400.f, 125.f);
	vec_obst_lvl[0].setPos(200.f, 140.f);
	vec_obst_lvl[1].setSize(400.f, 125.f);
	vec_obst_lvl[1].setPos(200.f, 140.f + 200.f);
	vec_obst_lvl[2].setSize(400.f, 125.f);
	vec_obst_lvl[2].setPos(200.f, 140.f + 400.f);
	vec_obst_lvl[3].setSize(250.f, 380.f);
	vec_obst_lvl[3].setPos(600.f, 420.f);
	vec_obst_lvl[4].setSize(350.f, 90.f);
	vec_obst_lvl[4].setPos(650.f, 125.f);

	vec_point_lvl[0].setPos(15, 240);
	vec_point_lvl[1].setPos(15, 440);
	vec_point_lvl[2].setPos(770, 40);
	vec_point_lvl[3].setPos(765, 580);

	vec_enemy_lvl[0].setPos(50, 225);
	vec_enemy_lvl[0].setDir(RIGHT);

	vec_enemy_lvl[1].setPos(375, 425);
	vec_enemy_lvl[1].setDir(LEFT);

	vec_enemy_lvl[2].setPos(50, 455);
	vec_enemy_lvl[2].setDir(RIGHT);

	vec_enemy_lvl[3].setPos(375, 255);
	vec_enemy_lvl[3].setDir(LEFT);

	vec_enemy_lvl[4].setPos(730, 20);
	vec_enemy_lvl[4].setDir(LEFT);

	vec_enemy_lvl[5].setPos(500, 55);
	vec_enemy_lvl[5].setDir(RIGHT);

	vec_enemy_lvl[6].setPos(420, 100);
	vec_enemy_lvl[6].setDir(DOWN);

	vec_enemy_lvl[7].setPos(450, 575);
	vec_enemy_lvl[7].setDir(UP);

	vec_enemy_lvl[8].setPos(780, 525);
	vec_enemy_lvl[8].setDir(UP);

	vec_enemy_lvl[9].setPos(750, 225);
	vec_enemy_lvl[9].setDir(DOWN);
}

void Level::draw_lvl1(sf::RenderWindow & window, Player & player)
{
	player.playerMovement(window); //przekazac do gameplay

	vec_obst_lvl[0].draw(window);
	vec_obst_lvl[0].collision(player);
	vec_obst_lvl[1].draw(window);
	vec_obst_lvl[1].collision(player);
	vec_obst_lvl[2].draw(window);
	vec_obst_lvl[2].collision(player);
	vec_obst_lvl[3].draw(window);
	vec_obst_lvl[3].collision(player);
	vec_obst_lvl[4].draw(window);
	vec_obst_lvl[4].collision(player);

	vec_point_lvl[0].drawPoint(window); //przekazac do gameplay
	vec_point_lvl[0].collision(player);
	vec_point_lvl[1].drawPoint(window); //przekazac do gameplay
	vec_point_lvl[1].collision(player);
	vec_point_lvl[2].drawPoint(window); //przekazac do gameplay
	vec_point_lvl[2].collision(player);
	vec_point_lvl[3].drawPoint(window); //przekazac do gameplay
	vec_point_lvl[3].collision(player);

	vec_enemy_lvl[0].moveAxisX(window, 50, 375);
	vec_enemy_lvl[1].moveAxisX(window, 50, 375);
	vec_enemy_lvl[2].moveAxisX(window, 50, 375);
	vec_enemy_lvl[3].moveAxisX(window, 50, 375);
	vec_enemy_lvl[4].moveAxisX(window, 500, 730);
	vec_enemy_lvl[5].moveAxisX(window, 500, 730);
	vec_enemy_lvl[6].moveAxisY(window, 100, 575);
	vec_enemy_lvl[7].moveAxisY(window, 100, 575);
	vec_enemy_lvl[8].moveAxisY(window, 225, 525);
	vec_enemy_lvl[9].moveAxisY(window, 225, 525);

	vec_enemy_lvl[0].collision(player);
	vec_enemy_lvl[1].collision(player);
	vec_enemy_lvl[2].collision(player);
	vec_enemy_lvl[3].collision(player);
	vec_enemy_lvl[4].collision(player);
	vec_enemy_lvl[5].collision(player);
	vec_enemy_lvl[6].collision(player);
	vec_enemy_lvl[7].collision(player);
	vec_enemy_lvl[8].collision(player);
	vec_enemy_lvl[9].collision(player);
}

bool Level::end_lvl1()
{
	if (vec_point_lvl[0].isPointChecked() == true &&
		vec_point_lvl[1].isPointChecked() == true &&
		vec_point_lvl[2].isPointChecked() == true &&
		vec_point_lvl[3].isPointChecked() == true)
	{
		return true;
	}

	return false;
}

void Level::setup_lvl2(sf::RenderWindow & window, Player & player)
{
	for (auto i = 5; i < 8; ++i)
	{
		vec_obst_lvl.emplace_back(window);
	}

	for (auto i = 10; i < 32; ++i)
	{
		vec_enemy_lvl.emplace_back(enemy_speed, window);
	}

	for (auto i = 4; i < 7; ++i)
	{
		vec_point_lvl.emplace_back(window);
	}

	vec_obst_lvl[5].setSize(100.f, 600.f);
	vec_obst_lvl[5].setPos(180.f, 250.f);
	vec_obst_lvl[6].setSize(170.f, 600.f);
	vec_obst_lvl[6].setPos(400.f, 350.f);
	vec_obst_lvl[7].setSize(100.f, 600.f);
	vec_obst_lvl[7].setPos(620.f, 250.f);

	vec_point_lvl[4].setPos(180, 580);
	vec_point_lvl[5].setPos(400, 20);
	vec_point_lvl[6].setPos(740, 20);

	vec_enemy_lvl[10].setPos(15, 110);
	vec_enemy_lvl[10].setDir(RIGHT);

	vec_enemy_lvl[11].setPos(15, 140);
	vec_enemy_lvl[11].setDir(RIGHT);

	vec_enemy_lvl[12].setPos(110, 170);
	vec_enemy_lvl[12].setDir(LEFT);

	vec_enemy_lvl[13].setPos(110, 200);
	vec_enemy_lvl[13].setDir(LEFT);

	vec_enemy_lvl[14].setPos(15, 280);
	vec_enemy_lvl[14].setDir(RIGHT);

	vec_enemy_lvl[15].setPos(110, 360);
	vec_enemy_lvl[15].setDir(LEFT);

	vec_enemy_lvl[16].setPos(15, 420);
	vec_enemy_lvl[16].setDir(LEFT);

	vec_enemy_lvl[17].setPos(110, 500);
	vec_enemy_lvl[17].setDir(RIGHT);

	vec_enemy_lvl[18].setPos(260, 525);
	vec_enemy_lvl[18].setDir(UP);

	vec_enemy_lvl[19].setPos(290, 330);
	vec_enemy_lvl[19].setDir(DOWN);

	vec_enemy_lvl[20].setPos(260, 280);
	vec_enemy_lvl[20].setDir(UP);

	vec_enemy_lvl[21].setPos(290, 30);
	vec_enemy_lvl[21].setDir(DOWN);

	vec_enemy_lvl[22].setPos(510, 525);
	vec_enemy_lvl[22].setDir(UP);

	vec_enemy_lvl[23].setPos(550, 330);
	vec_enemy_lvl[23].setDir(DOWN);

	vec_enemy_lvl[24].setPos(510, 280);
	vec_enemy_lvl[24].setDir(UP);

	vec_enemy_lvl[25].setPos(550, 30);
	vec_enemy_lvl[25].setDir(DOWN);

	vec_enemy_lvl[26].setPos(690, 60);
	vec_enemy_lvl[26].setDir(SLANTBOTTOM);

	vec_enemy_lvl[27].setPos(780, 140);
	vec_enemy_lvl[27].setDir(SLANTBOTTOM);

	vec_enemy_lvl[28].setPos(690, 230);
	vec_enemy_lvl[28].setDir(SLANTBOTTOM);

	vec_enemy_lvl[29].setPos(780, 310);
	vec_enemy_lvl[29].setDir(SLANTBOTTOM);

	vec_enemy_lvl[30].setPos(690, 400);
	vec_enemy_lvl[30].setDir(SLANTBOTTOM);

	vec_enemy_lvl[31].setPos(780, 490);
	vec_enemy_lvl[31].setDir(SLANTBOTTOM);

}

void Level::draw_lvl2(sf::RenderWindow & window, Player & player)
{
	player.playerMovement(window); //przekazac do gameplay

	vec_obst_lvl[5].draw(window);
	vec_obst_lvl[5].collision(player);
	vec_obst_lvl[6].draw(window);
	vec_obst_lvl[6].collision(player);
	vec_obst_lvl[7].draw(window);
	vec_obst_lvl[7].collision(player);

	vec_point_lvl[4].drawPoint(window); //przekazac do gameplay
	vec_point_lvl[4].collision(player);
	vec_point_lvl[5].drawPoint(window); //przekazac do gameplay
	vec_point_lvl[5].collision(player);
	vec_point_lvl[6].drawPoint(window); //przekazac do gameplay
	vec_point_lvl[6].collision(player);

	vec_enemy_lvl[10].moveAxisX(window, 15, 110);
	vec_enemy_lvl[11].moveAxisX(window, 15, 110);
	vec_enemy_lvl[12].moveAxisX(window, 15, 110);
	vec_enemy_lvl[13].moveAxisX(window, 15, 110);

	vec_enemy_lvl[14].moveAxisX(window, 15, 110);
	vec_enemy_lvl[15].moveAxisX(window, 15, 110);
	vec_enemy_lvl[16].moveAxisX(window, 15, 110);
	vec_enemy_lvl[17].moveAxisX(window, 15, 110);

	vec_enemy_lvl[18].moveAxisY(window, 330, 525);
	vec_enemy_lvl[19].moveAxisY(window, 330, 525);
	vec_enemy_lvl[20].moveAxisY(window, 330-300, 525-300);
	vec_enemy_lvl[21].moveAxisY(window, 330-300, 525-300);

	vec_enemy_lvl[22].moveAxisY(window, 330, 525);
	vec_enemy_lvl[23].moveAxisY(window, 330, 525);
	vec_enemy_lvl[24].moveAxisY(window, 330 - 300, 525 - 300);
	vec_enemy_lvl[25].moveAxisY(window, 330 - 300, 525 - 300);

	vec_enemy_lvl[26].SlantFall(window, 60, 140);
	vec_enemy_lvl[27].SlantRise(window, 140, 230);

	vec_enemy_lvl[28].SlantFall(window, 230, 310);
	vec_enemy_lvl[29].SlantRise(window, 310, 400);

	vec_enemy_lvl[30].SlantFall(window, 400, 480);
	vec_enemy_lvl[31].SlantRise(window, 480, 560);

	vec_enemy_lvl[10].collision(player);
	vec_enemy_lvl[11].collision(player);
	vec_enemy_lvl[12].collision(player);
	vec_enemy_lvl[13].collision(player);
	vec_enemy_lvl[14].collision(player);
	vec_enemy_lvl[15].collision(player);
	vec_enemy_lvl[16].collision(player);
	vec_enemy_lvl[17].collision(player);
	vec_enemy_lvl[18].collision(player);
	vec_enemy_lvl[19].collision(player);
	vec_enemy_lvl[20].collision(player);
	vec_enemy_lvl[21].collision(player);
	vec_enemy_lvl[22].collision(player);
	vec_enemy_lvl[23].collision(player);
	vec_enemy_lvl[24].collision(player);
	vec_enemy_lvl[25].collision(player);
	vec_enemy_lvl[26].collision(player);
	vec_enemy_lvl[27].collision(player);
	vec_enemy_lvl[28].collision(player);
	vec_enemy_lvl[29].collision(player);
	vec_enemy_lvl[30].collision(player);
	vec_enemy_lvl[31].collision(player);
}

bool Level::end_lvl2()
{
	if (vec_point_lvl[4].isPointChecked() == true &&
		vec_point_lvl[5].isPointChecked() == true &&
		vec_point_lvl[6].isPointChecked() == true)
	{
				vec_obst_lvl.clear();
				vec_point_lvl.clear();
				vec_enemy_lvl.clear();
		return true;
	}

	return false;
}

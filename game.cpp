#include "game.h"
#include "graphics.h"
#include "config.h"
#include "Utils.h"
#include "Score.h"

Contact  Game::checkCollisionPlayer1()
{
		float posX = ball->getPosX();
		float posY = ball->getPosY();

		float ballLeft = ball->getPosX() -5;
		float ballRight = ball->getPosX() + 5;
		float ballTop = ball->getPosY() -5;
		float ballBottom = ball->getPosY() + 5;

		float playerLeft = player->getPosX() - 3 ;
		float playerRight = player->getPosX() + 3;
		float playerTop = player->getPosY() - 40 ;
		float playerBottom = player->getPosY() + 40; 

		Contact contact{};
		
		if (ballLeft >= playerRight)
		{
			return contact;
		}
		if (ballRight <= playerLeft)
		{
			return contact;
		}
		if (ballTop >= playerBottom)
		{
			return contact;
		}
		if (ballBottom <= playerTop)
		{
			return contact;
		}

		float playerUpper = playerBottom - (2.0f * PLAYER_SIZE / 3.0f);
		float playerMiddle = playerBottom - (PLAYER_SIZE / 3.0f);

		//
		contact.penetration = playerRight - ballLeft;
		

		if ((ballBottom > playerTop)
			&& (ballBottom < playerUpper))
		{
			contact.type = CollisionType::Top;
		}
		else if ((ballBottom > playerUpper)
			&& (ballBottom < playerMiddle))
		{
			contact.type = CollisionType::Middle;
		}
		else
		{
			contact.type = CollisionType::Bottom;
		}

	return contact;
			


	
	
}
Contact Game::checkCollisionPlayer2()
{
	
	float posX = ball->getPosX();
	float posY = ball->getPosY();

	float ballLeft = ball->getPosX() - 5 ;
	float ballRight = ball->getPosX() + 5 ;
	float ballTop = ball->getPosY() - 5 ;
	float ballBottom = ball->getPosY() + 5;

	float player2Left = player2->getPosX() - 3 ;
	float player2Right = player2->getPosX() + 3;
	float player2Top = player2->getPosY() - 40;
	float player2Bottom = player2->getPosY() + 40;

	Contact contact{};



	if (ballLeft >= player2Right)
	{
		return contact;
	}

	if (ballRight <= player2Left)
	{
		return contact;
	}

	if (ballTop >= player2Bottom)
	{
		return contact;
	}

	if (ballBottom <= player2Top)
	{
		return contact;
	}

	float playerUpper = player2Bottom - (2.0f * PLAYER_SIZE / 3.0f);
	float playerMiddle = player2Bottom - (PLAYER_SIZE / 3.0f);

	
		contact.penetration = player2Left - ballRight;
	

	if ((ballBottom > player2Top)
		&& (ballBottom < playerUpper))
	{
		contact.type = CollisionType::Top;
	}
	else if ((ballBottom > playerUpper)
		&& (ballBottom < playerMiddle))
	{
		contact.type = CollisionType::Middle;
	}
	else
	{
		contact.type = CollisionType::Bottom;
	}

	return contact;



	

}
Contact Game::checkCollisionWall()
{
	
	float ballLeft = ball->getPosX() -5 ;
	float ballRight = ball->getPosX() +5;
	float ballTop = ball->getPosY() - 5 ;
	float ballBottom = ball->getPosY() + 5;

	Contact contact{};
	

	if (ballLeft < 0.0f)
	{
		contact.type = CollisionType::Left;
	}

	if (ballRight > CANVAS_WIDTH)
	{
		contact.type = CollisionType::Right;
	}

	if (ballTop < 0.0f)
	{
		contact.type = CollisionType::Top;
		contact.penetration = -ballTop;
	}

	if (ballBottom > CANVAS_HEIGHT)
	{
		contact.type = CollisionType::Bottom;
		contact.penetration = CANVAS_HEIGHT - ballBottom;
	}


	return contact;



	

}

void Game::update()
{
	//initialize start menu
	if (!initMenu) {
		startmenu = new StartMenu();
		graphics::playMusic(std::string(ASSET_PATH) + "menuMusic.ogg",0.5f, true);
		initMenu = true;
	}
	
	//initialized
	if (!initialized && startMenu)
	{
		
		player = new Player();
		ball = new Ball();
		player2 = new Player2();
		score = new Score();
		initialized = true; 
	}
	
	//afotou patisoun Space
	if (startMenu) {
		//Check All Collisions
		Contact contact1 = checkCollisionPlayer1();
		Contact contact2 = checkCollisionPlayer2();
		Contact wallContact = checkCollisionWall();

		//ixos contact me paixti
		if (contact1.type != CollisionType::None)
		{
			ball->CollideWithPlayer(contact1);
			graphics::playSound(std::string(ASSET_PATH) + "pongPlayer.ogg", 1.0f, false);

		}
		if (contact2.type != CollisionType::None)
		{
			ball->CollideWithPlayer(contact2);
			graphics::playSound(std::string(ASSET_PATH) + "pongPlayer.ogg", 1.0f, false);

		}
		//ixos contact me toixo
		if (wallContact.type != CollisionType::None)
		{
			ball->CollideWithWall(wallContact);
			graphics::playSound(std::string(ASSET_PATH) + "pongWall.ogg", 1.0f, false);

		}
		//ixos goal kai update tou score
		if (wallContact.type == CollisionType::Left)
		{
			graphics::playSound(std::string(ASSET_PATH) + "pongGoal.ogg", 1.0f, false);
			int s1 = score->getScore1();
			int s2 = score->getScore2() + 1;
			delete score;
			score = nullptr;
			score = new Score();
			score->setScore1(s1);
			score->setScore2(s2);
			score->draw();
		}
		if (wallContact.type == CollisionType::Right)
		{
			graphics::playSound(std::string(ASSET_PATH) + "pongGoal.ogg", 1.0f, false);
			int s1 = score->getScore1() + 1;
			int s2 = score->getScore2();
			delete score;
			score = nullptr;
			score = new Score();
			score->setScore1(s1);
			score->setScore2(s2);
			score->draw();
		}

		//GameObject Updates
		if (player) {
			player->update();
		}
		if (player2) {
			player2->update();
		}

		if (ball) {
			ball->update();
		}
		if (score) {
			score->update();
		}
		if (startmenu) {
			startmenu->update();
		}
	}
	
}

void Game::draw()
{
	//Draw Start Menu
	if (startmenu ) {
		startmenu->draw();
	}

	if (graphics::getKeyState(graphics::SCANCODE_SPACE)) {
		graphics::stopMusic(3500);
		startMenu = true;
		delete startmenu;
		startmenu = nullptr;
	}
	//Afotou patisoun Space
	if(startMenu){

		graphics::Brush br;
		br.fill_opacity = 1.0f;
		br.outline_color[0] = 0.0f;
		br.outline_color[1] = 1.0f;
		br.outline_color[2] = 0.0f;
		br.outline_opacity = 1.0f;

		//diakekomeni mesi grammi
		for (int y = 1; y < CANVAS_HEIGHT; ++y) {
			if (!(y % 5)) {
				graphics::drawLine(CANVAS_WIDTH / 2, y, CANVAS_WIDTH / 2, y + 5, br);
			}
			y = y + 1;
		}
		//epano grammi
		graphics::drawLine(1, 1, CANVAS_WIDTH, 1, br);

		//kato grammi
		graphics::drawLine(1, CANVAS_HEIGHT - 1, CANVAS_WIDTH, CANVAS_HEIGHT - 1, br);

		//draw player
		if (player) {
			player->draw();

		}
		//draw player2 
		if (player2) {
			player2->draw();

		}
		//draw ball 
		if (ball) {
			ball->draw();
		}
		//draw score
		if (score) {
			score->draw();

		}
	}
}

void Game::init()
{
	graphics::setFont(std::string(ASSET_PATH) + "arcadeclassic.ttf");
}

Game::Game()
{
}

Game::~Game()
{
	if (player) {
		delete player;
	}
	if (player2) {
		delete player2;
	}
	if (ball) {
		delete ball;
	}
	if (score) {
		delete score;
	}
	if (startmenu) {
		delete startmenu;
	}

}

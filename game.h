#pragma once

#include "Player.h"
#include "ball.h"
#include "Player2.h"
#include "Score.h"
#include "Utils.h"
#include "startMenu.h"

class Game
{
	Player * player = nullptr;

	Ball* ball = nullptr; 

	Player2* player2 = nullptr; 

	Score* score = nullptr; 

	StartMenu* startmenu = nullptr;

	bool initMenu = false;
	bool initialized = false; 
	bool startMenu = false;
	bool something = false;



public:
	void update();
	void draw();
	void init();
	Contact checkCollisionPlayer1();
	Contact checkCollisionPlayer2();
	Contact checkCollisionWall();
	Game();
	~Game();




};

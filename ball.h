#pragma once
#include "GameObject.h"
#include "config.h"
#include "Utils.h"


class Ball : public GameObject
{
	float speedX = BALL_SPEED;
	float speedY = BALL_SPEED;
	float BallSpeed = BALL_SPEED;
	float pos_x = CANVAS_WIDTH / 2, pos_y = CANVAS_HEIGHT / 2;
	bool started = false;
public:
	void update() override;
	void draw() override;
	void init() override;
	void CollideWithWall(Contact const& contact);
	void CollideWithPlayer(Contact const& contact);
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
	
	
};


#pragma once
#include "GameObject.h"
#include "config.h"


class Player2 : public GameObject
{
	float pos_x = CANVAS_WIDTH - 50, pos_y = CANVAS_HEIGHT / 2;
	
public:
	void update() override;
	void draw() override;
	void init() override;
	float getPosY() { return pos_y; }
	float getPosX() { return pos_x; }
};
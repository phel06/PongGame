#pragma once

#include "GameObject.h"
#include "config.h"


class Score : public GameObject
{
	
public:
	
	int getScore1() { return Score1; }
	int getScore2() { return Score2; }
	void setScore1(int s) { Score1 = s; }
	void setScore2(int s) { Score2 = s; }

	int Score1 = 0;
	int Score2 = 0;
	void update() override;
	void draw() override;
	void init() override;
};

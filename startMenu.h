#pragma once
#include "GameObject.h"
#include "config.h"

class StartMenu : public GameObject{
public:
	void update() override;
	void draw() override;
	void init() override;



};
#include "Player.h"
#include "graphics.h"
#include "config.h" 

void Player::update()
{
	if (graphics::getKeyState(graphics::SCANCODE_W)) 
	{
		pos_y -= PLAYER_SPEED * graphics::getDeltaTime() / 20.0f;
	}
	if (graphics::getKeyState(graphics::SCANCODE_S))
	{
		pos_y += PLAYER_SPEED * graphics::getDeltaTime() / 20.0f;
	}
	
	if (pos_y < PLAYER_SIZE/2) pos_y = PLAYER_SIZE / 2;
	if (pos_y > CANVAS_HEIGHT- PLAYER_SIZE / 2) pos_y = CANVAS_HEIGHT - PLAYER_SIZE / 2;
}


void Player::draw()
{
	graphics::Brush br;

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.0f;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 1.0f;
	br.outline_color[2] = 0.0f;
	br.outline_opacity = 0.0f;

	graphics::drawRect(pos_x , pos_y, 5, PLAYER_SIZE, br);
}


void Player::init()
{
}

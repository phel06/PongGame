#include "ball.h"
#include "graphics.h"
#include "config.h"
#include "Utils.h"

void Ball::CollideWithWall(Contact const& contact)
{
	
	if ((contact.type == CollisionType::Top)
		|| (contact.type == CollisionType::Bottom))
	{
		pos_y += contact.penetration;
		//velocity.y = -velocity.y;
		speedY = -speedY;
	}
	else if (contact.type == CollisionType::Left)
	{
		pos_x = CANVAS_WIDTH / 2.0f;
		pos_y = CANVAS_HEIGHT * rand0to1();
		//speedX = speedX;
		speedY = BALL_SPEED;
		BallSpeed = BALL_SPEED;
		//velocity.x = BALL_SPEED;
		//velocity.y = 0.75f * BALL_SPEED;
		
	}
	else if (contact.type == CollisionType::Right)
	{
		pos_x = CANVAS_WIDTH / 2.0f;
		pos_y = CANVAS_HEIGHT * rand0to1();
		//speedX = -1.0f * speedX;
		speedY = BALL_SPEED;
		BallSpeed = BALL_SPEED;
		
	}
}

void Ball::CollideWithPlayer (Contact const& contact)
{
	pos_x += contact.penetration;
	speedX = -1.0f * speedX;
	if (contact.type == CollisionType::Top)
	{
		BallSpeed = 1.05f * BallSpeed;
		speedY = -BallSpeed;
	}
	else if (contact.type == CollisionType::Bottom)
	{
		BallSpeed = 1.05f * BallSpeed;
		speedY =  BallSpeed;
	}
}

void Ball::update()
{
	pos_x += speedX;
	pos_y += speedY;
}

void Ball::draw()
{
	graphics::Brush br;

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.0f;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 1.0f;
	br.outline_color[2] = 0.0f;
	br.outline_opacity = 1.0f;

	graphics::drawRect(pos_x, pos_y, 10, 10, br);
}



void Ball::init()
{
	
}



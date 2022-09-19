#include "startMenu.h"
#include "graphics.h"
#include "config.h"

void StartMenu::update()
{
}

void StartMenu::draw()
{
	graphics::Brush br;
	float offset = sinf(graphics::getGlobalTime() / 500.0f);
	br.fill_color[0] = 0.0f ;
	br.fill_color[1] = 1.0f ;
	br.fill_color[2] = 0.0f ;
	br.fill_secondary_color[0] = 0.9f;
	br.fill_secondary_color[1] = 0.1f;
	br.fill_secondary_color[2] = 0.3f;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 1.0f;
	br.outline_color[2] = 0.0f;
	br.outline_opacity = 1.0f;
	std::string text1 = "PONG GAME";
	std::string text2 = "PRESS SPACE TO PLAY";
	
	graphics::drawText(CANVAS_WIDTH / 4 -30, 190 +40 *offset/2, 150, text1, br);

	br.fill_opacity = 1.0f +  1.0f * offset; 
	graphics::drawText(CANVAS_WIDTH / 5, CANVAS_HEIGHT - 160 , 80, text2, br);

	//perigramma
	br.fill_opacity = 0.0f;
	br.outline_width = 200.0f;
	graphics::drawRect(CANVAS_WIDTH / 2, CANVAS_HEIGHT / 2, CANVAS_WIDTH-5, CANVAS_HEIGHT -5, br);
	
	//2 paixtes
	br.fill_opacity = 1.0f;
	br.outline_opacity = 0.0f;
	graphics::drawRect(50, CANVAS_HEIGHT / 2 + 220*offset, 3, PLAYER_SIZE, br);
	graphics::drawRect(CANVAS_WIDTH - 50, CANVAS_HEIGHT / 2 -220*offset, 3, PLAYER_SIZE, br);



}




void StartMenu::init()
{
	
}

#include "Score.h"
#include "graphics.h"
#include "config.h"

void Score::update()
{
}

void Score::draw()
{
	graphics::Brush br;

	br.fill_color[0] = 0.0f;
	br.fill_color[1] = 1.0f;
	br.fill_color[2] = 0.0f;
	br.outline_color[0] = 0.0f;
	br.outline_color[1] = 1.0f;
	br.outline_color[2] = 0.0f;
	br.outline_opacity = 1.0f;
	
	
	std::string pl1Score = std::to_string(Score1);
	std::string pl2Score = std::to_string(Score2);
	//char scoreText[20] = "11111" ;
	//printf("%d", scoreText);	
	//printf("%c", scoreText);
	graphics::drawText(CANVAS_WIDTH/4 , 60, 80, pl1Score,br);
	graphics::drawText(3 * CANVAS_WIDTH / 4, 60, 80, pl2Score, br);

	
}

void Score::init()
{
	
}

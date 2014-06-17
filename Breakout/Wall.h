#ifndef WALL_H_
#define WALL_H_

#include "SDL.h"
class GraphicsManager;

class Wall {
public:
	Wall() : Wall(0, 0, 0, 0, 0) {};
	Wall(float x, float y, float w, float h, int color);
	~Wall();

	void drawWall(const GraphicsManager& gm);

private:
	static SDL_Color colors[5];

	float m_x, m_y, m_w, m_h;
	SDL_Color m_color;
};

#endif
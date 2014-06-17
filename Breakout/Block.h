#ifndef BLOCK_H_
#define BLOCK_H_

#include "SDL.h"
class GraphicsManager;

class Block {
public:
	Block();
	Block(float x, float y, int color);
	~Block();

	void drawBlock(const GraphicsManager& gm);

private:
	static SDL_Color colors[5];

	float m_x, m_y;
	SDL_Color m_color;
};

#endif
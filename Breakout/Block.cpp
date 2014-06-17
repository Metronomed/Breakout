#include "Block.h"
#include "SDL.h"
#include "GraphicsManager.h"

SDL_Color Block::colors[5] = { { 0xFF, 0x00, 0x00, 0xFF }, { 0x00, 0xFF, 0x00, 0xFF }, { 0x00, 0x00, 0xFF, 0xFF }, { 0xFF, 0xFF, 0x00, 0xFF }, { 0x00, 0xFF, 0xFF, 0xFF }};

const int blockHeight = 16;
const int blockWidth = 32;

Block::Block() {
	m_x = 0;
	m_y = 0;
	m_color = colors[0];
}

Block::Block(float x, float y, int color) {
	m_x = x;
	m_y = y;
	m_color = colors[color];
}

Block::~Block() {

}

void Block::drawBlock(const GraphicsManager& gm) {
	SDL_Rect blockRect = { (int) m_x, (int) m_y, blockWidth, blockHeight };
	gm.renderRect(&blockRect, &m_color);
}
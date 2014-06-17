#include "Wall.h"
#include "SDL.h"
#include "GraphicsManager.h"

SDL_Color Wall::colors[5] = { { 0xFF, 0x00, 0x00, 0xFF }, { 0x00, 0xFF, 0x00, 0xFF }, { 0x00, 0x00, 0xFF, 0xFF }, { 0xFF, 0xFF, 0x00, 0xFF }, { 0x00, 0xFF, 0xFF, 0xFF } };

Wall::Wall(float x, float y, float w, float h, int color) {
	m_x = x;
	m_y = y;
	m_w = w;
	m_h = h;
	m_color = colors[color];
}

void Wall::drawWall(const GraphicsManager& gm) {
	SDL_Rect wallRect = { m_x, m_y, m_w, m_h };
	gm.renderRect(&wallRect, &m_color);
}
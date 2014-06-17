#include "SpriteSheet.h"
#include "SDL.h"
#include "GraphicsManager.h"
#include <stdio.h>

SpriteSheet::SpriteSheet(GraphicsManager& gm, const std::string filename, const SDL_Color* transparency) {
	m_sheet = NULL;
	m_sheet = gm.loadImage(filename, transparency);
	if (m_sheet == NULL) {
		printf("Could not load image");
	}
}

SpriteSheet::~SpriteSheet() {
	SDL_DestroyTexture(m_sheet);
}

void SpriteSheet::drawSprite(GraphicsManager& gm, const std::string spriteName, const int x, const int y) {
	SDL_Rect sourceRect = m_spriteAreas[spriteName];
	SDL_Rect destRect = { x, y, sourceRect.w, sourceRect.h };
	gm.renderTexture(m_sheet, &sourceRect, &destRect);
}

void SpriteSheet::setSpriteArea(const std::string spriteName, const SDL_Rect area) {
	//m_spriteAreas.insert({ spriteName, area }); //no effect if key already exist in map
	m_spriteAreas[spriteName] = area; //to find and replace
}
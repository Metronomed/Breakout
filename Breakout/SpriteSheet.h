#ifndef SPRITE_SHEET_H_
#define SPRITE_SHEET_H_

#include <string>
#include <map>

class GraphicsManager;
struct SDL_Texture;
struct SDL_Rect;
struct SDL_Color;

class SpriteSheet {
public:
	SpriteSheet(GraphicsManager& gm, const std::string filename, const SDL_Color* transparency = NULL);
	~SpriteSheet();
	
	void drawSprite(GraphicsManager& gm, const std::string spriteName, const int x, const int y);
	void setSpriteArea(const std::string spriteName, const SDL_Rect area);
private:
	SDL_Texture* m_sheet;
	std::map<std::string, SDL_Rect> m_spriteAreas;
};

#endif
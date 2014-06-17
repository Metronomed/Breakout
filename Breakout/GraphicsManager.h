#ifndef GRAPHICS_MANAGER_H_
#define GRAPHICS_MANAGER_H_

//#include <SDL.h>
#include <string>

struct SDL_Window;
struct SDL_Texture;
struct SDL_Renderer;
struct SDL_Rect;
struct SDL_Color;

class GraphicsManager {
public:
	void startUp(int gameWidth, int gameHeight);
	void shutDown();

	SDL_Texture* loadImage(const std::string& file_path, const SDL_Color* transparency = NULL);

	void renderTexture(SDL_Texture* source, SDL_Rect* sourceRect=NULL, SDL_Rect* destRect=NULL) const;
	void renderRect(const SDL_Rect* area, const SDL_Color* color) const;

	void clear();
	void flip();
private:
	static bool isInstantiated;
	SDL_Window* m_window;
	SDL_Texture* m_screenTexture;
	SDL_Renderer* m_renderer;
};

#endif // !GRAPHICS_MANAGER_H_

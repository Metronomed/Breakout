#include "GraphicsManager.h"
#include "SDL.h"
#include <stdio.h>

bool GraphicsManager::isInstantiated = false;

void GraphicsManager::startUp(int gameWidth, int gameHeight) {
	if (isInstantiated == true) {
		printf("GraphicsManager already instantiated, should not happen again.");
	}
	else {
		isInstantiated = true;
		SDL_Color defaultFill = { 0xFF, 0xFF, 0xFF, 0xFF };
		if (SDL_InitSubSystem(SDL_INIT_VIDEO) < 0) {
			printf("Could not initialize SDL video subsystem. SDL Error: %s/n", SDL_GetError());
		}
		else {
			m_window = NULL;
			m_window = SDL_CreateWindow("TITLE", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, gameWidth, gameHeight, SDL_WINDOW_SHOWN);
			if (m_window == NULL) {
				printf("Could not create window. SDL Error: %s/n", SDL_GetError());
			}

			m_renderer = SDL_CreateRenderer(m_window, -1, SDL_RENDERER_ACCELERATED);
			if (m_window == NULL) {
				printf("Could not create renderer. SDL Error: %s/n", SDL_GetError());
			}
			else {
				SDL_SetRenderDrawColor(m_renderer, defaultFill.r, defaultFill.b, defaultFill.g, defaultFill.a);
			}
		}
	}
}

void GraphicsManager::shutDown() {
	SDL_DestroyRenderer(m_renderer);
	SDL_DestroyWindow(m_window);
	isInstantiated = false;
}

//creates a surface with the loaded image
SDL_Texture* GraphicsManager::loadImage(const std::string& file_path, const SDL_Color* transparency) {
	SDL_Texture* loadedTexture = NULL;
	SDL_Surface* loadedSurface = SDL_LoadBMP(file_path.c_str());

	if (loadedSurface == NULL) {
		printf("Unable to load image to surface. SDL Error: %s\n", SDL_GetError());
	}
	else {
		if (transparency != NULL) {
			SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, transparency->r, transparency->b, transparency->g));
		}
		loadedTexture = SDL_CreateTextureFromSurface(m_renderer, loadedSurface);
		if (loadedTexture == NULL) {
			printf("Unable to make texture from surface. SDL Error: %s\n", SDL_GetError());
		}
		SDL_FreeSurface(loadedSurface);
	}

	return loadedTexture;
}

//blits the surface to the screen
void GraphicsManager::renderTexture(SDL_Texture* source, SDL_Rect* sourceRect, SDL_Rect* destRect) const {
	SDL_RenderCopy(m_renderer, source, sourceRect, destRect);
}

void GraphicsManager::renderRect(const SDL_Rect* area, const SDL_Color* color) const {
	SDL_Color prevRenderColor;
	SDL_GetRenderDrawColor(m_renderer, &prevRenderColor.r, &prevRenderColor.b, &prevRenderColor.g, &prevRenderColor.a);
	SDL_SetRenderDrawColor(m_renderer, color->r, color->b, color->g, color->a);
	SDL_RenderFillRect(m_renderer, area);
	SDL_SetRenderDrawColor(m_renderer, prevRenderColor.r, prevRenderColor.b, prevRenderColor.g, prevRenderColor.a);
}

//clears screen to current render color
void GraphicsManager::clear() {
	SDL_RenderClear(m_renderer);
}

//flips the screen on the window
void GraphicsManager::flip() {
	SDL_RenderPresent(m_renderer);
}
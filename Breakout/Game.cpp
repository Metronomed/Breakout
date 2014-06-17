#include "Game.h"
#include "SDL.h"
#include "GraphicsManager.h"
#include "InputManager.h"
#include "SpriteSheet.h"
#include "Block.h"
#include "Wall.h"
#include <algorithm>

const Uint32 maxFrameTime = 5 * 1000 / 60;
int Game::gameScreenWidth = 480;
int Game::gameScreenHeight = 640;

GraphicsManager gGraphicsManager;
InputManager gInputManager;
const int blockR = 10; const int blockC = 12;
Block* blocks[blockR][blockC];
Wall* walls[3];

Game::Game() {
	m_gameClock = Clock(0.0f);
	SDL_Init(0);
	gGraphicsManager.startUp(gameScreenWidth, gameScreenHeight);
	gInputManager.startUp();
	//SDL_InitSubSystem(SDL_INIT_EVENTS);
	FPS = 60;
	
	m_player = Player();
	for (int r = 0; r < blockR; ++r) {
		for (int c = 0; c < blockC; ++c) {
			blocks[r][c] = new Block(36 * c + 24, 25 * r + 25, r/2);
		}
	}
	blocks[2][2] = NULL;
	walls[0] = new Wall(0, 0, 16, 640, 0);
	walls[1] = new Wall(0, 0, 480, 16, 1);
	walls[2] = new Wall(480 - 16, 0, 16, 640, 2);
	runGame();
}

Game::~Game() {
	gInputManager.shutDown();
	gGraphicsManager.shutDown();
	SDL_Quit();
}

void Game::runGame() {
	SDL_Event event;
	bool running = true;
	Uint32 deltaTime = 1000./FPS;

	while (running) {
		Uint32 startTime = SDL_GetTicks();
		//process events
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}
		}

		gInputManager.updateStates();

		if (gInputManager.wasKeyPressed(SDL_SCANCODE_ESCAPE)) {
			running = false;
		}

		if (gInputManager.isKeyHeld(Player::PLAYER_KEY_LEFT)) {
			m_player.movePaddleLeft();
		}
		else if (gInputManager.isKeyHeld(Player::PLAYER_KEY_RIGHT)) {
			m_player.movePaddleRight();
		}
		else {
			m_player.stopPaddle();
		}

		updateGame(std::min(deltaTime, maxFrameTime));
		drawGame();

		deltaTime = SDL_GetTicks() - startTime;
		if ((deltaTime) < 1000. / FPS) {
			SDL_Delay(1000. / FPS - deltaTime);
		}
	}
}

void Game::drawGame() {
	gGraphicsManager.clear();
	m_player.drawPaddle(gGraphicsManager);
	for (int r = 0; r < blockR; ++r) {
		for (int c = 0; c < blockC; ++c) {
			if (blocks[r][c] != NULL) {
				blocks[r][c]->drawBlock(gGraphicsManager);
			}
			
		}
	}

	for (int w = 0; w < 3; ++w) {
		walls[w]->drawWall(gGraphicsManager);
	}
	gGraphicsManager.flip();
}

void Game::updateGame(unsigned int milliseconds) {
	m_player.update(milliseconds);
}
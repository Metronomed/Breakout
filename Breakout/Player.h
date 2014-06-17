#ifndef PLAYER_H_
#define PLAYER_H_

#include "Paddle.h"
#include "SDL_scancode.h"

class GraphicsManager;
struct SDL_Rect;

class Player {
public:
	Player();
	~Player();

	void movePaddleLeft();
	void movePaddleRight();
	void stopPaddle();
	void drawPaddle(const GraphicsManager& gm);

	void resetPaddle();

	void addScore(int add);
	int getScore();
	void update(int milliseconds);

	static SDL_Scancode PLAYER_KEY_LEFT;
	static SDL_Scancode PLAYER_KEY_RIGHT;
private:
	int m_score;
	Paddle m_paddle;
};

#endif
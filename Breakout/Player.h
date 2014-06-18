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
	void drawPaddle(const GraphicsManager& gm, float alpha);

	void resetPaddle();

	void addScore(int add);
	int getScore();
	void update();

	static SDL_Scancode PLAYER_KEY_LEFT;
	static SDL_Scancode PLAYER_KEY_RIGHT;
private:
	int m_score;
	Paddle m_paddle;
};

#endif
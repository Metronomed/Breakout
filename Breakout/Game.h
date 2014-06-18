#ifndef GAME_H_
#define GAME_H_

#include "Clock.h"
#include "Player.h"

class Game {
public: 
	Game();
	~Game();

	static int gameScreenWidth;
	static int gameScreenHeight;
private:
	void runGame();
	void drawGame(float alpha);
	void updateGame();

	Clock m_gameClock;
	int FPS;
	int updateRate;
	Player m_player;

};

#endif GAME_H_
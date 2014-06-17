#ifndef BALL_H_
#define BALL_H_

class GraphicsManager;
class Wall;
class Block;
class Paddle;

class Ball {
public:
	Ball(float x, float y);
	~Ball();

	void drawBall(const GraphicsManager& gm);

	void collideWall(Wall& wall);
	void collideBlock(Block& block);
	void collidePaddle(Paddle& paddle);

private:
	float m_centerX, m_centerY;

};

#endif
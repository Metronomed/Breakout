#ifndef PADDLE_H_
#define PADDLE_H_

class GraphicsManager;
struct SDL_Rect;

class Paddle {
public:
	Paddle();
	~Paddle();

	void draw(const GraphicsManager& gm);
	void update(int milliseconds);
	void reset();

	void moveLeft();
	void moveRight();
	void stopMoving();
	
private:
	enum Direction {
		LEFT,
		RIGHT,
		NONE
	};
	float m_x, m_y;
	float m_velocity;
	Direction m_direction;
};

#endif
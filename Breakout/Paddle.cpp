#include "Paddle.h"
#include "SDL.h"
#include "GraphicsManager.h"
#include "Game.h"

const int paddleHeight = 16;
const int paddleWidth = 48;
const SDL_Color paddleColor = { 0xFF, 0x00, 0x00, 0xFF };
const float maxPaddleVelocity = 3.15;
const float paddleAcceleration = 0.0888f;
const float paddleDeceleration = 0.83f;

Paddle::Paddle() {
	reset();
}

Paddle::~Paddle() {

}

void Paddle::draw(const GraphicsManager& gm) {
	SDL_Rect paddleRect = { m_x, m_y, paddleWidth, paddleHeight };
	gm.renderRect(&paddleRect, &paddleColor);
}

void Paddle::moveLeft() {
	m_direction = LEFT;
}

void Paddle::moveRight() {
	m_direction = RIGHT;
}

void Paddle::stopMoving() {
	m_direction = NONE;
}

void Paddle::update(int milliseconds) {
	switch (m_direction) {
	case LEFT:
		m_velocity = -maxPaddleVelocity;
		break;
	case RIGHT:
		m_velocity = maxPaddleVelocity;
		break;
	case NONE:
		m_velocity = 0.0f;
		break;
	default: break;
	}

	m_x += m_velocity;
	if (m_x < 0) {
		m_x = 0.0f;
		m_direction = NONE;
	}
	else if (m_x > Game::gameScreenWidth - paddleWidth) {
		m_x = Game::gameScreenWidth - paddleWidth;
		m_direction = NONE;
	}
}

void Paddle::reset() {
	m_x = (Game::gameScreenWidth - paddleWidth) / 2;
	m_y = Game::gameScreenHeight - 3 * paddleHeight;
	m_velocity = 0.0f;
	m_direction = NONE;
}
#include "Player.h"
#include "SDL.h"
#include "GraphicsManager.h"

SDL_Scancode Player::PLAYER_KEY_LEFT = SDL_SCANCODE_LEFT;
SDL_Scancode Player::PLAYER_KEY_RIGHT = SDL_SCANCODE_RIGHT;

Player::Player() {
	m_score = 0;
	m_paddle = Paddle();
}

Player::~Player() {

}

void Player::movePaddleLeft() {
	m_paddle.moveLeft();
}

void Player::movePaddleRight() {
	m_paddle.moveRight();
}

void Player::stopPaddle() {
	m_paddle.stopMoving();
}

void Player::drawPaddle(const GraphicsManager& gm, float alpha) {
	m_paddle.draw(gm, alpha);
}

void Player::resetPaddle() {
	m_paddle.reset();
}

void Player::addScore(int add) {
	m_score += add;
}

int Player::getScore() {
	return m_score;
}

void Player::update() {
	m_paddle.update();
}
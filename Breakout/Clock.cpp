#include "Clock.h"

Clock::Clock(float startTimeMillis) {
	m_timeElapsed = millisToNano(startTimeMillis);
	m_timeScale = 1.0f;
	m_isPaused = false;
}

//Clock::Clock(nanoseconds startTimeNano) {
//	m_timeElapsed = startTimeNano;
//	m_timeScale = 1.0f;
//	m_isPaused = false;
//}

Clock::~Clock() {}

void Clock::update(float milliseconds) {
	if (!m_isPaused) {
		nanoseconds scaledTime = millisToNano(milliseconds * m_timeScale);
		m_timeElapsed += scaledTime;
	}
}

void Clock::update(nanoseconds nanos) {
	if (!m_isPaused) {
		nanoseconds scaledTime = duration_cast<nanoseconds>(nanos * m_timeScale);
		m_timeElapsed += scaledTime;
	}
}

void Clock::setPaused(bool isPaused) {
	m_isPaused = isPaused;
}

bool Clock::isPaused() const {
	return m_isPaused;
}

void Clock::setTimeScale(float scale) {
	m_timeScale = scale;
}

float Clock::getTimeScale() const {
	return m_timeScale;
}

void Clock::reset() {
	m_timeElapsed = (nanoseconds) 0;
}

float Clock::getTimeElapsed() {
	return nanoToMillis(m_timeElapsed);
}

nanoseconds Clock::getTimeElapsedNano() {
	return m_timeElapsed;
}
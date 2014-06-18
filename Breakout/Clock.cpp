#include "Clock.h"
#include <Windows.h>

int64_t Clock::s_cyclesPerSecond;

Clock::Clock(float startTimeSeconds) : m_isPaused(false), m_timeScale(1.0f), m_timeCycles(secondsToCycles(startTimeSeconds)) 
{ }

Clock::~Clock() {}

//Call when game starts
void Clock::init() {
	LARGE_INTEGER freq;
	QueryPerformanceFrequency(&freq);
	s_cyclesPerSecond = freq.QuadPart;
}

int64_t Clock::getFrequency() const {
	return s_cyclesPerSecond;
}

int64_t Clock::getTimeCycles() const {
	return m_timeCycles;
}

float Clock::calcDeltaSeconds(const Clock& other) {
	int64_t dt = m_timeCycles - other.m_timeCycles;
	return cyclesToSeconds(dt);
}

void Clock::update(float dtRealSeconds) {
	if (!m_isPaused) {
		int64_t dtScaledCycles = secondsToCycles(dtRealSeconds * m_timeScale);
		m_timeCycles += dtScaledCycles;
	}
}

void Clock::update(int64_t dtCycles) {
	if (!m_isPaused) {
		int64_t dtScaledCycles = dtCycles * m_timeScale;
		m_timeCycles += dtScaledCycles;
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
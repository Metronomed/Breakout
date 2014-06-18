#ifndef CLOCK_H_
#define CLOCK_H_
#include <stdint.h>

class Clock{
public: 
	explicit Clock(float startTimeSeconds = 0.0f);
	~Clock();

	static void init();

	int64_t getFrequency() const;
	int64_t getTimeCycles() const;
	float calcDeltaSeconds(const Clock& other);

	void update(float dtRealSeconds);
	void update(int64_t cycles);

	void setPaused(bool isPaused);
	bool isPaused() const;
	void setTimeScale(float scale);
	float getTimeScale() const;

private:
	static int64_t s_cyclesPerSecond;
	bool m_isPaused;
	float m_timeScale;
	int64_t m_timeCycles;

	static inline int64_t secondsToCycles(float timeSeconds) {
		return (int64_t)(timeSeconds * s_cyclesPerSecond);
	}

	//only use with small time durations
	static inline float cyclesToSeconds(int64_t timeCycles) {
		return (float)timeCycles / s_cyclesPerSecond;
	}
};

#endif
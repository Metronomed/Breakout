#ifndef CLOCK_H_
#define CLOCK_H_

#include <chrono>
using namespace std::chrono;

class Clock{
public: 
	Clock(float startTimeMillis = 0.0f);
	//Clock(nanoseconds startTimeNano = (nanoseconds)(0));
	~Clock();

	void update(float millis);
	void update(nanoseconds nanos);

	void setPaused(bool isPaused);
	bool isPaused() const;
	void setTimeScale(float scale);
	float getTimeScale() const;
	void reset();

	float getTimeElapsed();
	nanoseconds getTimeElapsedNano();

private:
	nanoseconds m_timeElapsed;
	float m_timeScale;
	bool m_isPaused;

	static inline nanoseconds millisToNano(float millis) {
		return duration_cast<nanoseconds>((duration<float>)(millis * 1000.f));
	}

	static inline float nanoToMillis(nanoseconds nanos) {
		return (float) duration<float>((nanos / 1000)).count();
	}
};

#endif
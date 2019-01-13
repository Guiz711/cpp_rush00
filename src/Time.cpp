#include "../includes/Time.hpp"
#include "../includes/Log.hpp"
#include <sys/time.h>

double	Time::_timeSinceStartup = 0;
double	Time::_deltaTime = 0;

Time::Time( void )
{
	double curTime = Time::getCurrentTime();

	_startupTime = curTime;
	_lastFrameTime = curTime;

}

Time::Time( Time const & src ):
	_lastFrameTime(src.getLastFrameTime()),
	_startupTime(src.getStartupTime())
{}

Time::~Time( void ) {};

Time &Time::operator=( Time const & src)
{
	if (this == &src)
		return *this;

	_timeSinceStartup = src.getTimeSinceStartup();
	_deltaTime = src.getDeltaTime();
	_startupTime =src.getStartupTime();
	_lastFrameTime = src.getLastFrameTime();
	return *this;
}

double	Time::getCurrentTime(void)
{
	struct timespec curTime;

	clock_gettime(CLOCK_MONOTONIC, &curTime);
	return curTime.tv_sec + curTime.tv_nsec * 1e-9;
}

void Time::updateTime( void )
{
	double now = Time::getCurrentTime();

	_timeSinceStartup = now - _startupTime;
	_deltaTime = now - _lastFrameTime;
	_lastFrameTime = now;
}

double Time::getDeltaTime(void) { return _deltaTime; }
double Time::getTimeSinceStartup(void) { return _timeSinceStartup; }
double Time::getStartupTime(void) const { return _startupTime; }
double Time::getLastFrameTime(void) const { return _lastFrameTime; }
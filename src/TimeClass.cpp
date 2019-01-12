#include "../includes/TimeClass.hpp"
#include "../includes/Log.hpp"
#include <sys/time.h>

TimeClass::TimeClass( void ):
	_timeSinceStartup(0),
	_deltaTime(0)
{
	double curTime = TimeClass::getCurrentTime();

	_startupTime = curTime;
	_lastFrameTime = curTime;

	Log::instance().log("Default TimeClass Constructor");
}

TimeClass::TimeClass( TimeClass const & src ):
	_timeSinceStartup(src.getTimeSinceStartup()),
	_deltaTime(src.getDeltaTime()),
	_startupTime(src.getStartupTime()),
	_lastFrameTime(src.getLastFrameTime())
{}

TimeClass::~TimeClass( void ) {};

TimeClass &TimeClass::operator=( TimeClass const & src)
{
	if (this == &src)
		return *this;

	_timeSinceStartup = src.getTimeSinceStartup();
	_deltaTime = src.getDeltaTime();
	_startupTime =src.getStartupTime();
	_lastFrameTime = src.getLastFrameTime();
	return *this;
}

double	TimeClass::getCurrentTime(void)
{
	struct timespec curTime;

	clock_gettime(CLOCK_MONOTONIC, &curTime);
	return curTime.tv_sec + curTime.tv_nsec * 1e-9;
}

void TimeClass::updateTime( void )
{
	double now = TimeClass::getCurrentTime();

	_timeSinceStartup = now - _startupTime;
	_deltaTime = now - _lastFrameTime;
	_lastFrameTime = now;
}

double TimeClass::getDeltaTime(void) const { return _deltaTime; }
double TimeClass::getTimeSinceStartup(void) const { return _timeSinceStartup; }
double TimeClass::getStartupTime(void) const { return _startupTime; }
double TimeClass::getLastFrameTime(void) const { return _lastFrameTime; }
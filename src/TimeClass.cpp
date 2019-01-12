#include "../includes/TimeClass.hpp"
#include "../includes/Log.hpp"
#include <sys/time.h>

TimeClass::TimeClass( void ){
  Log::instance().log("Default TimeClass Constructor");
  return;
}

TimeClass::TimeClass( TimeClass const & src ){
  Log::instance().log("CopyTimeClass Constructor");
  _deltaTime = src.getDelta();
  _frameTime = src.getFrame();
  return;
}

TimeClass::~TimeClass( void ){
  Log::instance().log("TimeClass Destructor");
  return;
}

TimeClass &TimeClass::operator=( TimeClass const & rhs){
  Log::instance().log("TimeClass Operator =");
  _deltaTime = rhs.getDelta();
  _frameTime = rhs.getFrame();
  return *this;
}

void TimeClass::setDeltaTime( void ){
  timeval     time;
  float       sec;

  gettimeofday(&time, NULL);
  sec = (time.tv_sec) + (time.tv_usec / 100000);
  _deltaTime = _frameTime - sec;
  return;
}

void TimeClass::setFrameTime( void ){
  timeval     time;
  float       sec;

  gettimeofday(&time, NULL);
  sec = (time.tv_sec) + (time.tv_usec / 1000);
  _frameTime = sec;
  return;
}

int TimeClass::getDelta( void ) const {
  return _deltaTime;
}

int TimeClass::getFrame( void ) const {
  return _frameTime;
}

#include "../includes/TimeClass.hpp"
#include "../includes/Log.hpp"


TimeClass::TimeClass( void ){
  Log::instance().log("Default TimeClass Constructor");
  _t = time(NULL);
  return;
}

TimeClass::TimeClass( TimeClass const & src ){
  Log::instance().log("CopyTimeClass Constructor");
  *this = src;
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
//  int     actualTime;

  std::cout << localtime(&_t);
  //actualTime = localtime(&_t);
//  Log::instance().log("delta TimeClass is" << localtime(&_t));
//  _deltaTime = actualTime - _frameTime;
  return;
}

void TimeClass::setFrameTime( void ){
  //_frameTime = localtime(&_t);
  std::cout << localtime(&_t);
//  Log::instance().log("new TimeClass is" << localtime(&_t));
  return;
}

int TimeClass::getDelta( void ) const {
  return _deltaTime;
}

int TimeClass::getFrame( void ) const {
  return _frameTime;
}

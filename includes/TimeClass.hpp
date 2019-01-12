#ifndef TIMECLASS_HPP
# define TIMECLASS_HPP

#include <string>

class TimeClass{
  private:
    int              _deltaTime;
    int              _frameTime;

  public:
    TimeClass( void );
    TimeClass( TimeClass const & src );
    ~TimeClass( void );

    TimeClass &operator=( TimeClass const & rhs);

    void setDeltaTime( void );
    void setFrameTime( void );

    int getDelta( void ) const ;
    int getFrame( void ) const ;
};

#endif

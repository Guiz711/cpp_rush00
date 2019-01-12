#ifndef TIMECLASS_HPP
# define TIMECLASS_HPP

#include <string>

class TimeClass{
  private:
    double              	_deltaTime;
	double				_timeSinceStartup;
    double              	_lastFrameTime;
	double				_startupTime;

	static double		getCurrentTime(void);

  public:
    TimeClass( void );
    TimeClass( TimeClass const & src );
    ~TimeClass( void );

    TimeClass &operator=( TimeClass const & rhs);

	void				updateTime(void);

    double 				getDeltaTime(void) const;
    double 				getTimeSinceStartup(void) const;
	double 				getStartupTime(void) const;
	double 				getLastFrameTime(void) const;
};

#endif

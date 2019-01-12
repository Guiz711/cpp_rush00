#ifndef TIME_HPP
# define TIME_HPP

#include <string>

class Time{
  private:
    static double       _deltaTime;
	static double		_timeSinceStartup;
    double              _lastFrameTime;
	double				_startupTime;

	static double		getCurrentTime(void);

  public:
    Time( void );
    Time( Time const & src );
    ~Time( void );

    Time &operator=( Time const & rhs);

	void				updateTime(void);

    static double 		getDeltaTime(void);
    static double 		getTimeSinceStartup(void);
	double 				getStartupTime(void) const;
	double 				getLastFrameTime(void) const;
};

#endif

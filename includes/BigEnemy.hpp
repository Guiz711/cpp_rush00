#ifndef BIGENEMY_HPP
# define BIGENEMY_HPP

#include "AEnemy.hpp"

class BigEnemy: public AEnemy{
  public:
    BigEnemy( void );
    BigEnemy( float posX, float posY );
    BigEnemy( BigEnemy const &src );
    ~BigEnemy( void );

    BigEnemy &operator=( BigEnemy const &rhs);
    virtual void update( void );

  private:
    double    _lastSpawn;
};

#endif

#ifndef SIMPLEENEMY_HPP
# define SIMPLEENEMY_HPP

#include "AEnemy.hpp"

class SimpleEnemy: public AEnemy{
  public:
    SimpleEnemy( void );
    SimpleEnemy( float posX, float posY );
    SimpleEnemy( SimpleEnemy const &src );
    ~SimpleEnemy( void );

    SimpleEnemy &operator=( SimpleEnemy const &rhs);
    virtual void update( void );
};

#endif

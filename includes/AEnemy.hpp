#ifndef AENEMY_HPP
# define AENEMY_HPP

#include "AEntity.hpp"

class AEnemy: public AEntity{
  public:
    AEnemy( void );
    AEnemy( float posX, float posY );
    AEnemy( AEnemy const &src );
    ~AEnemy( void );

    AEnemy &operator=( AEnemy const &rhs);

    int   getLife( void ) const ;
    float getVelocity0( void ) const ;
    float	getVelocity1( void ) const ;
    virtual void update( void ) = 0;
    virtual void onCollision( AEntity *entity );

  private:
    int       _life;
    int       _velocity[2];
}

#endif

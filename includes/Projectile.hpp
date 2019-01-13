#ifndef PROJECTILE_HPP
# define PROJECTILE_HPP

#include "AEntity.hpp"

class Projectile: public AEntity{
  public:
    Projectile( float xPos, float yPos, Collision collisionMask, float speed );
    Projectile( Projectile const & src);
    ~Projectile();

    Projectile &operator=(Projectile const &rhs);

    virtual void update( void );
    virtual void onCollision(AEntity *collider);
    float			   getVelocity0( void ) const ;
    float			   getVelocity1( void ) const ;

  private:
    float   _velocity[2];

    Projectile( void );
};

#endif

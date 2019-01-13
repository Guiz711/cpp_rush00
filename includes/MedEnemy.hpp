#ifndef MEDENEMY_HPP
# define MEDENEMY_HPP

#include "AEnemy.hpp"

class MedEnemy: public AEnemy{
  public:
    MedEnemy( void );
    MedEnemy( float posX, float posY );
    MedEnemy( MedEnemy const &src );
    ~MedEnemy( void );

    MedEnemy &operator=( MedEnemy const &rhs);
    virtual void update( void );
};

#endif

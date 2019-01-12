#ifndef PHYSICS_HPP
# define PHYSICS_HPP

#include <string>
#include "EntitiesList.hpp"

class Physics{
  private:
    EntitiesList  *_list;

    Physics( void );

  public:
    Physics( EntitiesList *list);
    Physics( Physics const & src );
    ~Physics( void );

    Physics &operator=(Physics const & rhs);

    void checkMaskCollisions( void );

    EntitiesList *getList( void )
}

#endif

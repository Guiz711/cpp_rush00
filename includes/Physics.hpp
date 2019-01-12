#ifndef PHYSICS_HPP
# define PHYSICS_HPP

#include <string>
#include "EntitiesList.hpp"

class Physics{
  private:
    EntitiesList  *_list;

  public:
    Physics( void );
    Physics( EntitiesList *list);
    Physics( Physics const & src );
    ~Physics( void );

    Physics &operator=(Physics const & rhs);

    void checkCollisions( void );
    void setList( EntitiesList *list );
    EntitiesList *getList( void ) const ;
};

#endif

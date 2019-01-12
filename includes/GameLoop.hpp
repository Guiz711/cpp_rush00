#ifndef GAMELOOP_HPP
# define GAMELOOP_HPP

#include "Renderer.hpp"
#include "AEntity.hpp"
#include "EntitiesList.hpp"
#include "Inputs.hpp"
#include "Physics.hpp"
#include "TimeClass.hpp"

class GameLoop{
  private:
    EntitiesList        *_list;
    Renderer            _renderer;
    Inputs              _inputs;
    Physics             _physics;
    TimeClass           _time;

    void _update( void );


  public:
    GameLoop( void );
    GameLoop( GameLoop const & src );
    ~GameLoop( void );

    GameLoop &operator=(const GameLoop &rhs);

    EntitiesList *getList( void ) const ;

    void checkAlive( void );
    void startLoop( void );

};

#endif

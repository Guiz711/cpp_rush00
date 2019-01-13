#ifndef GAMELOOP_HPP
# define GAMELOOP_HPP

#include "Renderer.hpp"
#include "AEntity.hpp"
#include "EntitiesList.hpp"
#include "Inputs.hpp"
#include "Physics.hpp"
#include "Time.hpp"

class GameLoop{
  private:
    static EntitiesList *_list;
    Renderer            _renderer;
    Inputs              _inputs;
    Physics             _physics;
    Time           		_time;

    void _update( void );


  public:
    GameLoop( void );
    GameLoop( GameLoop const & src );
    ~GameLoop( void );

    GameLoop &operator=(const GameLoop &rhs);

	EntitiesList *getList( void ) const ;

    void checkAlive( void );
    void startLoop( void );
	static void addEntity(AEntity *entity);

};

#endif

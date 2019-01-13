#ifndef GAMELOOP_HPP
# define GAMELOOP_HPP

#include "AEntity.hpp"
#include "Renderer.hpp"
#include "EntitiesList.hpp"
#include "Inputs.hpp"
#include "Physics.hpp"
#include "Time.hpp"
#include "Game.hpp"
#include "MedEnemy.hpp"
#include "SimpleEnemy.hpp"
#include "BigEnemy.hpp"
#include "Projectile.hpp"

class GameLoop{
  private:
    static EntitiesList *_list;
    Renderer            _renderer;
    Inputs              _inputs;
    Physics             _physics;
    Time           		  _time;
	  static bool			    _running;

    void _update( void );


  public:
    GameLoop( void );
    GameLoop( GameLoop const & src );
    ~GameLoop( void );

    GameLoop &operator=(const GameLoop &rhs);

	   EntitiesList 	*getList( void ) const ;
	   static void		quitGame(void);

     void checkAlive( void );
     void startLoop( void );
	   static void addEntity(AEntity *entity);

};

#endif

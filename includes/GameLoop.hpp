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

class GameLoop{
  private:
    static EntitiesList *_list;
    Renderer            _renderer;
    Inputs              _inputs;
    Physics             _physics;
    Time           		_time;
	static bool			_running;
	static int			_boardWidth;
	static int			_boardHeight;

    void 	_update( void );
	bool	isOutsideMap(int x, int y);

  public:
    GameLoop( void );
    GameLoop( GameLoop const & src );
    ~GameLoop( void );

    GameLoop &operator=(const GameLoop &rhs);

	   EntitiesList 	*getList( void ) const ;
	   static void		quitGame(void);

	static int		getBoardWidth(void);
	static int		getBoardHeight(void);

    void checkAlive( void );
    void startLoop( void );
	static void addEntity(AEntity *entity);

};

#endif

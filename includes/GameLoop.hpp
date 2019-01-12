#ifndef GAMELOOP_HPP
# define GAMELOOP_HPP


class GameLoop{
  private:
    EntitiesList  *_list;
    Renderer      renderer;
    Inputs        inputs;

    void _update( void );
    void _manageEntities( void );


  public:
    GameLoop( void );
    GameLoop( GameLoop const & src );
    ~GameLoop( void );

    GameLoop &operator=(const GameLoop &rhs);

    EntitiesList *getList( void );

    void startLoop( void );

};

#endif

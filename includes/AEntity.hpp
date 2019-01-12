#ifndef AENTITY_HPP
# define AENTITY_HPP

#include <string>

class AEntity{
  protected:
    char            **_sprite = NULL;
    bool            _isAlive = true;
    std::string     _color;
    int             _xPos;
    int             _yPos;
    enum            _collisionMask{ Player, Enemies, Decor, Ui };

  public:
    AEntity( void );
    AEntity( int xPos, int yPos );
    AEntity( AEntity & src );
    ~AEntity( void );

    AEntity &operator=( AEntity const & rhs );

    virtual void update( void ) = 0;
    virtual void onCollision( void ) = 0;
    int         *getPos( void ) const ;
    char       **getSprite( void ) const ;
    std::string  getColor( void ) const ;
    bool         isAlive( void ) const ;
    std::string  getColor( void ) const ;
    enum        *getCollisionMask( void ) const ;
};


#endif

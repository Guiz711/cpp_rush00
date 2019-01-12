#ifndef AENTITY_HPP
# define AENTITY_HPP

#include <string>

enum Collision
{
	PLAYER = 1 << 0,
	ENEMIES = 1 << 1,
	LAND = 1 << 2,
	UI = 1 << 3
};

class AEntity{
  protected:
    std::string    	*_sprite;
    bool            _isAlive;
    std::string     _color;
    int             _xPos;
    int             _yPos;
    Collision       _collisionMask;

  public:
    AEntity( void );
    AEntity( int xPos, int yPos );
    AEntity( AEntity & src );
    ~AEntity( void );

    AEntity &operator=( AEntity const & rhs );

    // virtual void update( void ) = 0;
    // virtual void onCollision( void ) = 0;
    int          getXPos( void ) const ;
    int          getYPos( void ) const ;
    std::string  *getSprite( void ) const ;
    std::string  getColor( void ) const ;
    bool         isAlive( void ) const ;
    Collision    getCollisionMask( void ) const ;
};


#endif

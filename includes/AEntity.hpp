#ifndef AENTITY_HPP
# define AENTITY_HPP

# include <string>
# include <ncurses.h>
# include "Inputs.hpp"
# include "Time.hpp"
# include "Log.hpp"

enum Collision 
{
	NO_COLLISION = 0,
	PLAYER = 1 << 0,
	ENEMIES = 1 << 1,
	LAND = 1 << 2,
	UI = 1 << 3,
	PLAYER_PROJECTILE = 1 << 4 
};

class AEntity {
  protected:
    std::string    	*_sprite;
    bool            _isAlive;
	int     		_color;
    float           _xPos;
	float       	_yPos;
    Collision       _collisionMask;

  public:
    AEntity( void );
    AEntity( float xPos, float yPos );
    AEntity( AEntity & src );
    virtual ~AEntity( void );

    AEntity &operator=( AEntity const & rhs );

    virtual void update(void) = 0;
    virtual void onCollision(AEntity *collider);
    int          getXPos( void ) const ;
    int          getYPos( void ) const ;
    std::string  *getSprite( void ) const ;
    int  		 getColor( void ) const ;
    bool         isAlive( void ) const ;
    Collision    getCollisionMask( void ) const ;
    void         setNotAlive( void );
};


#endif

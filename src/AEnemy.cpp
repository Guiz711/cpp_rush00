#include "AEnemy.hpp"
#include "AEntity.hpp"

AEnemy::AEnemy( void ) : AEntity(){
  _collisionMask = ENEMIES;
  _color = COLOR_RED;
  return;
}

AEnemy::AEnemy( AEnemy const &src) : AEntity(){
  _sprite= src.getSprite();
  _isAlive= src.isAlive();
  _color= src.getColor();
  _xPos= src.getXPos();
  _yPos= src.getYPos();
  _collisionMask= src.getCollisionMask();
  _life = src.getLife();
  _velocity[0] = src.getVelocity0();
  _velocity[1] = src.getVelocity1();
  _collisionMask = src.getCollisionMask();
}

AEnemy::AEnemy( float posX, float posY ): AEntity(posX, posY){
  _xPos = posX;
  _yPos = posY;
  _collisionMask = ENEMIES;
  _color = COLOR_RED;
}

AEnemy::~AEnemy( void ){
  return;
}

AEnemy &AEnemy::operator=( AEnemy const &rhs){
  _sprite= rhs.getSprite();
  _isAlive= rhs.isAlive();
  _color= rhs.getColor();
  _xPos= rhs.getXPos();
  _yPos= rhs.getYPos();
  _collisionMask= rhs.getCollisionMask();
  _life = rhs.getLife();
  _velocity[0] = rhs.getVelocity0();
  _velocity[1] = rhs.getVelocity1();
  _collisionMask = rhs.getCollisionMask();
  return *this;
}

int   AEnemy::getLife( void ) const {
  return _life;
}

float AEnemy::getVelocity0( void ) const {
  return _velocity[0];
}

float	AEnemy::getVelocity1( void ) const {
  return _velocity[1];
}


void AEnemy::onCollision( AEntity *collider ){
	if (collider->getCollisionMask() & (PLAYER_PROJECTILE))
	{
		_life -= 1;
	}
	if (_life <= 0 || collider->getCollisionMask() & (PLAYER))
		setNotAlive();
	return;
}

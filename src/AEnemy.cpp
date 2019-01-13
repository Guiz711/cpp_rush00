#include "AEnemy.hpp"

AEnemy::AEnemy( void ) : AEntity(){
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
}

AEnemy::AEnemy( float posX, float posY ): AEntity(posX, posY){
  _xPos = posX;
  _yPos = posY;
}

AEnemy::~AEnemy( void ){
  return;
}

AEnemy::AEnemy &operator=( AEnemy const &rhs){
  _sprite= rhs.getSprite();
  _isAlive= rhs.isAlive();
  _color= rhs.getColor();
  _xPos= rhs.getXPos();
  _yPos= rhs.getYPos();
  _collisionMask= rhs.getCollisionMask();
  _life = rhs.getLife();
  _velocity[0] = rhs.getVelocity0();
  _velocity[1] = rhs.getVelocity1();
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


void onCollision( AEntity *entity ){
  
}

#include "Projectile.hpp"
#include "Time.hpp"

Projectile::Projectile( void ): AEntity(){
  _sprite = new std::string[2];
  _sprite[0] = "-";
  _sprite[1] = "";
  _velocity[0] = 0;
  _velocity[1] = 0;
  return;
}

Projectile::Projectile( float xPos, float yPos, Collision collisionMask, float speed ): AEntity(xPos, yPos){
  _sprite = new std::string[2];
  _sprite[0] = "-";
  _sprite[1] = "";
  _velocity[1] = 0;
  _collisionMask = collisionMask;
  if (_collisionMask & PLAYER){
      _velocity[0] = speed;
      _color = COLOR_GREEN;
  }
  if (_collisionMask & ENEMIES){
      _velocity[0] = -speed;
      _sprite[0] = "+";
      _sprite[1] = "";
      _color = COLOR_RED;
  }
  return;
}

Projectile::Projectile( Projectile const & src): AEntity() {
  _sprite = src.getSprite();
  _isAlive = src.isAlive();
  _color = src.getColor();
  _xPos = src.getXPos();
  _yPos = src.getYPos();
  _collisionMask = src.getCollisionMask();
  _velocity[0] = src.getVelocity0();
  _velocity[1] = src.getVelocity1();
  return;
}

Projectile::~Projectile(){
  return ;
}

Projectile &Projectile::operator=(Projectile const &rhs){
  _sprite = rhs.getSprite();
  _isAlive = rhs.isAlive();
  _color = rhs.getColor();
  _xPos = rhs.getXPos();
  _yPos = rhs.getYPos();
  _collisionMask = rhs.getCollisionMask();
  _velocity[0] = rhs.getVelocity0();
  _velocity[1] = rhs.getVelocity1();
  return *this;
}

void Projectile::update( void ){
  _xPos += _velocity[0] * (float)Time::getDeltaTime();
  return;
}

void Projectile::onCollision( void ){
  setNotAlive();
  return;
}

float	Projectile::getVelocity0( void ) const {
  return _velocity[0];
}

float Projectile::getVelocity1( void ) const {
  return _velocity[1];
}

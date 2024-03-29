#include "AEntity.hpp"

AEntity::AEntity( void ):
	_sprite(NULL),
	_isAlive(true),
	_color(COLOR_WHITE),
	_xPos(0),
	_yPos(0),
	_collisionMask(NO_COLLISION)
{
  return;
}

AEntity::AEntity( float xPos, float yPos ):
	_sprite(NULL),
	_isAlive(true),
	_color(COLOR_WHITE),
	_xPos(xPos),
	_yPos(yPos),
	_collisionMask(NO_COLLISION)
{
  return;
}

AEntity::AEntity( AEntity & src ){
  _sprite= src.getSprite();
  _isAlive= src.isAlive();
  _color= src.getColor();
  _xPos= src.getXPos();
  _yPos= src.getYPos();
  _collisionMask= src.getCollisionMask();
  return;
}

AEntity::~AEntity( void ){
  delete [] _sprite;
  return;
}

AEntity &AEntity::operator=( AEntity const & rhs ){
  _sprite= rhs.getSprite();
  _isAlive= rhs.isAlive();
  _color= rhs.getColor();
  _xPos= rhs.getXPos();
  _yPos= rhs.getYPos();
  _collisionMask= rhs.getCollisionMask();
  return *this;
}

void	AEntity::onCollision(AEntity *collider) {
	collider = NULL;
}

int     AEntity::getXPos( void ) const {
  return _xPos;
}

int     AEntity::getYPos( void ) const {
  return _yPos;
}

std::string *AEntity::getSprite( void ) const {
  return _sprite;
}

int AEntity::getColor( void ) const {
  return _color;
}

bool AEntity::isAlive( void ) const {
  return _isAlive;
}

Collision AEntity::getCollisionMask( void ) const {
  return _collisionMask;
}

void AEntity::setNotAlive( void ){
  this->_isAlive = false;
  return;
}

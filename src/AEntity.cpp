#include "../includes/AEntity.hpp"
#include <iostream>

AEntity::AEntity( void ){
  Log::instance().log("Default Entity Constructor");
  return;
}

AEntity::AEntity( int xPos, int yPos ){
  _xPos = xPos;
  _yPos = yPos;
  Log::instance().log("Entity Parametric Constructor");
  return;
}

AEntity::AEntity( AEntity & src ){
  Log::instance().log("Copy Entity Constructor");
  *this = src;
  return this;
}

AEntity::~AEntity( void ){
  Log::instance().log("Entity Destructor");
  return;
}

AEntity &AEntity::operator=( AEntity const & rhs ){
  Log::instance().log("Entity Operator =");
  _sprite= rhs.getSprite();
  _isAlive= rhs.isAlive();
  _color= rhs.getColor();
  _xPos= rhs.getPos()[0];
  _yPos= rhs.getPos()[1];
  _collisionMask= rhs.getCollisionMask();
  return *this;
}

int     *AEntity::getPos( void ) const {
  int   res[2];

  res[0] = _xPos;
  res[1] = _yPos;
  return res;
}

char **AEntity::getSprite( void ) const {
  return _sprite;
}

std::string AEntity::getColor( void ) const {
  return _color;
}

bool AEntity::isAlive( void ) const {
  return _isAlive;
}

std::string  getColor( void ) const {
  return _color;
}

enum *AEntity::getCollisionMask( void ) const {
  return _collisionMask;
}

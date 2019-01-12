#include "../includes/AEntity.hpp"
#include <iostream>
#include "Log.hpp"

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
  return;
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
  int   *res = new int[2];

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

Collision AEntity::getCollisionMask( void ) const {
  return _collisionMask;
}

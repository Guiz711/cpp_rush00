#include "../includes/AEntity.hpp"
#include "../includes/Log.hpp"
#include <iostream>
#include "Log.hpp"

AEntity::AEntity( void ){
  Log::instance().log("Default Entity Constructor");
  return;
}

AEntity::AEntity( int xPos, int yPos ){
  _xPos = xPos;
  _yPos = yPos;
  _sprite = new std::string[4];
  _sprite[0] = "|\\";
  _sprite[1] = "}=O>";
  _sprite[2] = "|/";
  _sprite[3] = "";
  Log::instance().log("Entity Parametric Constructor");
  return;
}

AEntity::AEntity( AEntity & src ){
  Log::instance().log("Copy Entity Constructor");
  _sprite= src.getSprite();
  _isAlive= src.isAlive();
  _color= src.getColor();
  _xPos= src.getXPos();
  _yPos= src.getYPos();
  _collisionMask= src.getCollisionMask();
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
  _xPos= rhs.getXPos();
  _yPos= rhs.getYPos();
  _collisionMask= rhs.getCollisionMask();
  return *this;
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

std::string AEntity::getColor( void ) const {
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

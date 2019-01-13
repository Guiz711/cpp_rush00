#include "SimpleEnemy.hpp"

SimpleEnemy::SimpleEnemy( void ): AEnemy(){
  _sprite = new std::string[2];
  _sprite[0] = "<X=";
  _sprite[1] = "";
  _velocity[0] = -30;
  _velocity[1] = 0;
  _life = 1;
}

SimpleEnemy::SimpleEnemy( float posX, float posY ): AEnemy(posX, posY){
  _sprite = new std::string[2];
  _sprite[0] = "<X=";
  _sprite[1] = "";
  _velocity[0] = -30;
  _velocity[1] = 0;
  _life = 1;
}

SimpleEnemy::SimpleEnemy( SimpleEnemy const &src ): AEnemy(){
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

SimpleEnemy::~SimpleEnemy( void ){
  return;
}

SimpleEnemy &SimpleEnemy::operator=( SimpleEnemy const &rhs){
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

void SimpleEnemy::update(void){
	_xPos += _velocity[0] * (float)Time::getDeltaTime();
}

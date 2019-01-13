#include "MedEnemy.hpp"
#include "GameLoop.hpp"
#include <cmath>

MedEnemy::MedEnemy( void ): AEnemy(){
  _sprite = new std::string[4];
  _sprite[0] = "  / ";
  _sprite[1] = "-X#{";
  _sprite[2] = "  \\ ";
  _sprite[3] = "";
  _velocity[0] = 0;
  _velocity[1] = 0;
  _life = 1;
}

MedEnemy::MedEnemy( float posX, float posY ): AEnemy(posX, posY){
  _sprite = new std::string[4];
  _sprite[0] = "  / ";
  _sprite[1] = "-X#{";
  _sprite[2] = "  \\ ";
  _sprite[3] = "";
  _velocity[0] = 0;
  _velocity[1] = 0;
  _life = 1;
}

MedEnemy::MedEnemy( MedEnemy const &src ): AEnemy(){
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

MedEnemy::~MedEnemy( void ){
  return;
}

MedEnemy &MedEnemy::operator=( MedEnemy const &rhs){
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

void MedEnemy::update(void){
  double  time;
  
  _velocity[0] = 0;
	_velocity[1] = 0;

	_velocity[0] = -13;

  time = Time::getTimeSinceStartup();

  if ( 0 < std::fmod(time,5) && std::fmod(time,5) < 0.05)
		GameLoop::addEntity(new Projectile(_xPos - 1, _yPos + 1, _collisionMask, 20));

	_xPos += _velocity[0] * (float)Time::getDeltaTime();
}

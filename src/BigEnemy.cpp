#include "BigEnemy.hpp"
#include "GameLoop.hpp"
#include <cmath>

BigEnemy::BigEnemy( void ): AEnemy(){
  _sprite = new std::string[6];
  _sprite[0] = "  / ";
  _sprite[1] = "=|o{";
  _sprite[2] = "<X##";
  _sprite[3] = "=|o{";
  _sprite[4] = "  \\ ";
  _sprite[5] = "";
  _velocity[0] = 0;
  _velocity[1] = 0;
  _life = 3;
  _lastSpawn = Time::getTimeSinceStartup();
}

BigEnemy::BigEnemy( float posX, float posY ): AEnemy(posX, posY){
  _sprite = new std::string[6];
  _sprite[0] = "  / ";
  _sprite[1] = "=|o{";
  _sprite[2] = "<X##";
  _sprite[3] = "=|o{";
  _sprite[4] = "  \\ ";
  _sprite[5] = "";
  _velocity[0] = 0;
  _velocity[1] = 0;
  _life = 3;
  _lastSpawn = Time::getTimeSinceStartup();
}

BigEnemy::BigEnemy( BigEnemy const &src ): AEnemy(){
  _sprite= src.getSprite();
  _isAlive= src.isAlive();
  _color= src.getColor();
  _xPos= src.getXPos();
  _yPos= src.getYPos();
  _collisionMask= src.getCollisionMask();
  _life = src.getLife();
  _velocity[0] = src.getVelocity0();
  _velocity[1] = src.getVelocity1();
  _lastSpawn = Time::getTimeSinceStartup();
}

BigEnemy::~BigEnemy( void ){
  return;
}

BigEnemy &BigEnemy::operator=( BigEnemy const &rhs){
  _sprite= rhs.getSprite();
  _isAlive= rhs.isAlive();
  _color= rhs.getColor();
  _xPos= rhs.getXPos();
  _yPos= rhs.getYPos();
  _collisionMask= rhs.getCollisionMask();
  _life = rhs.getLife();
  _velocity[0] = rhs.getVelocity0();
  _velocity[1] = rhs.getVelocity1();
  _lastSpawn = Time::getTimeSinceStartup();
  return *this;
}

void BigEnemy::update(void){
  double    time;

  _velocity[0] = 0;
	_velocity[1] = 0;

	_velocity[0] = -15;

  time = Time::getTimeSinceStartup();

    if ( time - _lastSpawn > 5 ){
    _lastSpawn = time;
		GameLoop::addEntity(new Projectile(_xPos - 1, _yPos + 1, _collisionMask, 20));
    GameLoop::addEntity(new Projectile(_xPos - 1, _yPos + 3, _collisionMask, 20));
  }
	_xPos += _velocity[0] * (float)Time::getDeltaTime();
}

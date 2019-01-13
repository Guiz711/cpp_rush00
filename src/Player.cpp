/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:50:52 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 12:40:34 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"
#include "GameLoop.hpp"
#include "Projectile.hpp"

Player::Player(void):
	AEntity()
{
	_velocity[0] = 0;
	_velocity[1] = 0;

	_sprite = new std::string[4];
	_sprite[0] = "|\\";
	_sprite[1] = "}=O>";
	_sprite[2] = "|/ ";
	_sprite[3] = "";

	_collisionMask = PLAYER;

	_color = COLOR_GREEN;
}

Player::Player(Player const &src): AEntity(){
	_velocity[0] = src.getVelocity0();
	_velocity[1] = src.getVelocity1();
	_life = src.getLife();
	_sprite= src.getSprite();
	_isAlive= src.isAlive();
	_color= src.getColor();
	_xPos= src.getXPos();
	_yPos= src.getYPos();
	_collisionMask= src.getCollisionMask();
	return;

}

Player::Player( float posX, float posY ):
	AEntity(posX, posY)
	{
	_velocity[0] = 0;
	_velocity[1] = 0;

	_sprite = new std::string[4];
	_sprite[0] = "|\\";
	_sprite[1] = "}=O>";
	_sprite[2] = "|/ ";
	_sprite[3] = "";

	_collisionMask = PLAYER;

	_color = COLOR_GREEN;
}

Player::~Player(void) {}

Player&	Player::operator=(const Player& rhs){
	_velocity[0] = rhs.getVelocity0();
	_velocity[1] = rhs.getVelocity1();
	_life = rhs.getLife();
	_sprite= rhs.getSprite();
	_isAlive= rhs.isAlive();
	_color= rhs.getColor();
	_xPos= rhs.getXPos();
	_yPos= rhs.getYPos();
	_collisionMask= rhs.getCollisionMask();
	return *this;
}

void	Player::update(void)
{
	_velocity[0] = 0;
	_velocity[1] = 0;

	if (Inputs::getKeyDown(INP_UP))
		_velocity[1] = -5000;
	if (Inputs::getKeyDown(INP_DOWN))
		_velocity[1] = 5000;
	if (Inputs::getKeyDown(INP_LEFT))
		_velocity[0] = -5000;
	if (Inputs::getKeyDown(INP_RIGHT))
		_velocity[0] = 5000;
	if (Inputs::getKeyDown(INP_SPACE))
		GameLoop::addEntity(new Projectile(_xPos + 4, _yPos + 1, _collisionMask, 20));

	// Log::instance().logWarning(std::to_string(_velocity[1]));
	_xPos += _velocity[0] * (float)Time::getDeltaTime();
	_yPos += _velocity[1] * (float)Time::getDeltaTime();
}

void Player::onCollision(AEntity *collider)
{
	if (collider->getCollisionMask() & (ENEMIES | LAND))
	{
		_life -= 1;
		if (_life <= 0){
			setNotAlive();
		}
	}
	return;
}

int Player::getLife( void ) const {
	return _life;
}

float Player::getVelocity0( void ) const {
	return _velocity[0];
}

float Player::getVelocity1( void ) const {
	return _velocity[1];
}

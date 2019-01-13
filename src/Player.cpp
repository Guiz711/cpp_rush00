/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:50:52 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 10:34:56 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Player.hpp"

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

Player::~Player(void) {}

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
	
	// Log::instance().logWarning(std::to_string(_velocity[1]));
	_xPos += _velocity[0] * (float)Time::getDeltaTime();
	_yPos += _velocity[1] * (float)Time::getDeltaTime();
}

void Player::onCollision(void)
{
	return;
}


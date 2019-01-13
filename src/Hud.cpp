/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hud.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:29:58 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 19:45:04 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Hud.hpp"
//9 5
//2 5
Hud::Hud(void):
	AEntity(),
	_startTime(Time::getTimeSinceStartup())
{
	Log::instance().log("init hud");
	_sprite = new std::string[2];
	_sprite[0] = " + + +  99999 ";
	_sprite[1] = "";

	_collisionMask = UI;

	_color = COLOR_GREEN;
}

Hud::Hud(Hud const &src):
	AEntity(),
	_startTime(Time::getTimeSinceStartup())
{
	_sprite= src.getSprite();
	_isAlive= src.isAlive();
	_color= src.getColor();
	_xPos= src.getXPos();
	_yPos= src.getYPos();
	_collisionMask= src.getCollisionMask();
	return;

}

Hud::Hud( float posX, float posY ):
	AEntity(posX, posY)
{
	_sprite = new std::string[2];
	_sprite[0] = " + + +  99999 ";
	_sprite[1] = "";

	_collisionMask = UI;

	_color = COLOR_GREEN;
}

Hud::~Hud(void) {}

Hud&	Hud::operator=(const Hud& rhs){
	_sprite= rhs.getSprite();
	_isAlive= rhs.isAlive();
	_color= rhs.getColor();
	_xPos= rhs.getXPos();
	_yPos= rhs.getYPos();
	_collisionMask= rhs.getCollisionMask();
	return *this;
}

void	Hud::update(void)
{
	std::stringstream	timeStr;
	std::string			dest;

	timeStr << (int)(Time::getTimeSinceStartup() - _startTime);
	dest = timeStr.str();
	for (int i = 0; i < 5 - dest.length(); i++)
		dest = " " + dest;
	_sprite[0].replace(8, 5, dest);	
}

void	Hud::updateLife(int hp)
{
	std::string	shp;
	int			len = 6;

  	Log::instance().log(std::to_string(hp));
	while(hp--)
	{
		shp += "+ ";
		len -= 2;
	}
	while (len-- > 0)
		shp += " ";
  	Log::instance().log(shp);
	_sprite[0].replace(1, 6, shp);
}

void	Hud::updateScore(int score)
{

}
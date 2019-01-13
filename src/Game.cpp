/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:38:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 12:00:14 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Decors.hpp"

Game::Game(void):
	AEntity()
{
	init();
	_collisionMask = NO_COLLISION;
}

Game::~Game(void) {}

void	Game::update(void)
{
	if (Inputs::getKeyDown(INP_Q))
	{
		GameLoop::quitGame();
	}
}

void Game::onCollision(void)
{
	return;
}

void Game::init()
{
	int			width;
	int			width_screen;
	
	width = 20;
	width_screen = GameLoop::getBoardWidth();
	while( width < width_screen){
		GameLoop::addEntity(new Decors(true, width, 0));
		GameLoop::addEntity(new Decors(false, width, 0));
		width += 16;
	}
	GameLoop::addEntity(new Player(0, int(GameLoop::getBoardHeight()/2)));
	GameLoop::addEntity(new MedEnemy(120,10));
	GameLoop::addEntity(new BigEnemy(150, 30));
}

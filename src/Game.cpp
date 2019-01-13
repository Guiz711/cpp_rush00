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
	GameLoop::addEntity(new Player);
	GameLoop::addEntity(new SimpleEnemy(100,10));
}

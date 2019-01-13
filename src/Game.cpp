/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:38:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 19:38:13 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Decors.hpp"

Game::Game(void):
	AEntity()
{
	_spawnYMax = GameLoop::getBoardHeight() - 13;
	_spawnYMin = 8;
	init();
	_collisionMask = NO_COLLISION;
}

Game::Game(const Game& src){
	_spawnYMax = src.getSpawnMax();
	_spawnYMin = src.getSpawnMin();
	init();
	_collisionMask = src.getCollisionMask();
}

Game &Game::operator=(const Game &rhs){
	_spawnYMax = rhs.getSpawnMax();
	_spawnYMin = rhs.getSpawnMin();
	init();
	_collisionMask = rhs.getCollisionMask();
	return *this;
}

Game::~Game(void) {}

void	Game::update(void)
{
	if (Inputs::getKeyDown(INP_Q))
	{
		GameLoop::quitGame();
	}

	if (rand() % 500 == 1)
	{
		int enemy = rand() % 24;
		int y = rand() % (_spawnYMax - _spawnYMin) + _spawnYMin;

		if (enemy < 15)
			GameLoop::addEntity(new SimpleEnemy(GameLoop::getBoardWidth() - 1, y));
		if (enemy >= 15 && enemy < 21)
			GameLoop::addEntity(new MedEnemy(GameLoop::getBoardWidth() - 1, y));
		if (enemy >= 21 && enemy < 24)
			GameLoop::addEntity(new BigEnemy(GameLoop::getBoardWidth() - 1, y));
	}


}

int	Game::getSpawnMax( void ){
	return _spawnYMax;
}

int	Game::getSpawnMin( void ){
	return _spawnYMin;
}

void Game::onCollision(void)
{
	return;
}

void Game::init()
{
	int			width;
	int			width_screen;
	
	width = 0;
	width_screen = GameLoop::getBoardWidth();
	while( width < width_screen){
		GameLoop::addEntity(new Decors(true, width, 0));
		GameLoop::addEntity(new Decors(false, width, 0));
		width += 16;
	}
	GameLoop::addEntity(new Player(0, int(GameLoop::getBoardHeight()/2)));
}

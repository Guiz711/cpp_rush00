/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:38:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 21:33:30 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Decors.hpp"

std::string	Game::_endScreen[7] = {
	"/*****************************\\",
	"|                             |",
	"|        ~ GAME OVER ~        |",
	"|                             |",
	"|  (press SPACE to continue)  |",
	"|                             |",
	"\\*****************************/",
};

bool Game::_gameOver = true;

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

Game::~Game(void) {
	_sprite = NULL;
}

void	Game::update(void)
{
	if (Inputs::getKeyDown(INP_Q))
	{
		GameLoop::quitGame();
	}

	if (!_gameOver)
	{
		if (!_player->getLife())
			_gameOver = true;

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
	else
	{
		if (_sprite == NULL)
		{
			_yPos = GameLoop::getBoardHeight() / 2 - 3;
			_xPos = GameLoop::getBoardWidth() / 2 - 16;
			_sprite = _endScreen;
		}

		if (Inputs::getKeyDown(INP_SPACE))
			init();
	}



}

int	Game::getSpawnMax( void ) const{
	return _spawnYMax;
}

int	Game::getSpawnMin( void ) const{
	return _spawnYMin;
}

void Game::init()
{
	int			width;
	int			width_screen;
	
	_sprite = NULL;

	_gameOver = false;
	width = 0;
	width_screen = GameLoop::getBoardWidth();
	while( width < width_screen){
		GameLoop::addEntity(new Decors(true, width, 0));
		GameLoop::addEntity(new Decors(false, width, 0));
		width += 16;
	}
	_player = new Player(0, int(GameLoop::getBoardHeight()/2));
	GameLoop::addEntity(_player);
}

void	Game::die(void)
{
	_sprite = _endScreen;
}

bool	Game::isGameOver(void)
{
	return (_gameOver);
}
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:38:55 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 20:00:59 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Game.hpp"
#include "Decors.hpp"

const std::string	Game::_endScreen[7] = {
	"/*****************************\\",
	"|                             |",
	"|        ~ GAME OVER ~        |",
	"|                             |",
	"|  (press SPACE to continue)  |",
	"|                             |",
	"\\*****************************/",
};

Game::Game(void):
	AEntity()
{
	_spawnYMax = GameLoop::getBoardHeight() - 13;
	_spawnYMin = 8;
	_gameOver = false;
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

void	Game::die(void)
{
	_sprite = _endScreen;

}
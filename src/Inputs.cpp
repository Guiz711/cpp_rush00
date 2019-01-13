/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inputs.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:49:04 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 21:02:47 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inputs.hpp"
#include "Log.hpp"

int	Inputs::_keyBuffer = 0;

Inputs::Inputs(void)
{
	if (!stdscr)
		initscr();
	// cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
}

Inputs::Inputs(const Inputs& src) { (void)src; }
Inputs&	Inputs::operator=(const Inputs& rhs) { (void)rhs; return *this; }

Inputs::~Inputs(void)
{
	endwin();
}

void	Inputs::updateInputs(void)
{
	int	key = getch();

	if (_keyBuffer != INP_UP && key == KEY_UP)
		_keyBuffer = INP_UP;
	else if (_keyBuffer != INP_DOWN && key == KEY_DOWN)
		_keyBuffer = INP_DOWN;
	else if (_keyBuffer != INP_RIGHT && key == KEY_RIGHT)
		_keyBuffer = INP_RIGHT;
	else if (_keyBuffer != INP_LEFT && key == KEY_LEFT)
		_keyBuffer = INP_LEFT;
	else if (_keyBuffer != INP_SPACE && key == ' ')
		_keyBuffer = INP_SPACE;
	else if (_keyBuffer != INP_Q && key == 'q')
		_keyBuffer = INP_Q;
	else
		_keyBuffer = 0;

	// Log::instance().logError(std::to_string(key));	
}

bool	Inputs::getKeyDown(Keys keycode)
{
	return _keyBuffer & keycode ? true : false;
}

bool Inputs::inputReceived() { return _keyBuffer != 0; }

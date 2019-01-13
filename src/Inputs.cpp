/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inputs.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:49:04 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 09:57:04 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inputs.hpp"

int	Inputs::_keyBuffer = 0;

Inputs::Inputs(void):
	_bufferSize(sizeof(_keyBuffer) / sizeof(int))
{
	if (!stdscr)
		initscr();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	nodelay(stdscr, TRUE);
}

Inputs::Inputs(const Inputs& src) {}
Inputs&	Inputs::operator=(const Inputs& rhs) { return *this; }

Inputs::~Inputs(void)
{
	endwin();
}

void	Inputs::updateInputs(void)
{
	int	key = getch();

	if (key == ERR)
		_keyBuffer = 0;
	else if (key == KEY_UP)
		_keyBuffer = INP_UP;
	else if (key == KEY_DOWN)
		_keyBuffer = INP_DOWN;
	else if (key == KEY_RIGHT)
		_keyBuffer = INP_RIGHT;
	else if (key == KEY_LEFT)
		_keyBuffer = INP_LEFT;
	else if (key == ' ')
		_keyBuffer = INP_SPACE;
	else if (key == 'q')
		_keyBuffer = INP_Q;
}

bool	Inputs::getKeyDown(Keys keycode)
{
	return _keyBuffer & keycode ? true : false;
}

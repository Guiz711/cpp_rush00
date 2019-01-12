/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inputs.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 17:49:02 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/12 18:37:35 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUTS_H
# define INPUTS_H

# include <ncurses.h>

enum Keys
{
	INP_UP = 1 << 0,
	INP_DOWN = 1 << 1,
	INP_RIGHT = 1 << 2,
	INP_LEFT = 1 << 3,
	INP_SPACE = 1 << 4,
	INP_Q = 1 << 5
};

class Inputs
{
	public:
		Inputs(void);
		~Inputs(void);

		static bool	getKeyDown(Keys keycode);

		void	updateInputs(void);

	private:
		static int		_keyBuffer;
		int				_bufferSize;

		Inputs(const Inputs& src);
		Inputs&	operator=(const Inputs& rhs);
};

#endif

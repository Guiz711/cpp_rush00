/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:15:01 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 10:26:04 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDERER_HPP
# define RENDERER_HPP

# include <ncurses.h>
# include <string>
# include "EntitiesList.hpp"

class Renderer
{
	public:
		Renderer(void);
		~Renderer(void);

		void		renderScreen(EntityLink *entities);

		int			getBoardX(void) const;
		int			getBoardY(void) const;

	private:
		int			_width;
		int			_height;

		void		placeSprite(int x, int y, std::string *sprite, chtype color);

		Renderer(const Renderer& src);
		Renderer&	operator=(const Renderer& rhs);
};

#endif
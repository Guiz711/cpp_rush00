/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:16:10 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 10:34:35 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Renderer.hpp"

Renderer::Renderer(void)
{
	if (!stdscr)
		initscr();
	curs_set(0);
	getmaxyx(stdscr, _width, _height);
	start_color();
}

Renderer::Renderer(const Renderer& src)
{
	return;
}

Renderer::~Renderer(void)
{
	endwin();
}

Renderer&	Renderer::operator=(const Renderer& rhs)
{
	return *this;
}

void		Renderer::renderScreen(EntityLink *entities)
{
	AEntity	*entity;
	werase(stdscr);
	while (entities)
	{
		entity = entities->entity;
		placeSprite(entity->getXPos(), entity->getYPos(), entity->getSprite(), entity->getColor());
		entities = entities->next;
	}
	wrefresh(stdscr);
}

void		Renderer::placeSprite(int x, int y, std::string *sprite, chtype color)
{
	init_pair(1, color, COLOR_BLACK);
	for (int v = 0; sprite[v][0]; ++v)
		for (int u = 0; sprite[v][u]; ++u)
			mvwaddch(stdscr, y + v, x + u, sprite[v][u] | COLOR_PAIR(1));
}

int			Renderer::getBoardX(void) const { return _width; }
int			Renderer::getBoardY(void) const { return _height; }

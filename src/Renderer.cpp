/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:16:10 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/12 18:13:34 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Renderer.hpp"

Renderer::Renderer(void)
{
	if (!stdscr)
		initscr();
	curs_set(0);
	getmaxyx(stdscr, _width, _height);
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
		placeSprite(entity->getXPos(), entity->getYPos(), entity->getSprite());
		entities = entities->next;
	}
	wrefresh(stdscr);
}

void		Renderer::placeSprite(int x, int y, std::string *sprite)
{
	for (int v = 0; sprite[v][0]; ++v)
		for (int u = 0; sprite[v][u]; ++u)
			mvwaddch(stdscr, y + v, x + u, sprite[v][u]);
}

int			Renderer::getBoardX(void) const { return _width; }
int			Renderer::getBoardY(void) const { return _height; }

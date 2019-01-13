/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Renderer.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 15:16:10 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 19:50:07 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Renderer.hpp"

Renderer::Renderer(void)
{
	if (!stdscr)
		initscr();
	curs_set(0);
	getmaxyx(stdscr, _height, _width);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_RED, COLOR_BLACK);
	init_pair(4, COLOR_YELLOW, COLOR_BLACK);
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
	AEntity		*entity;
	std::string *sprite;

	werase(stdscr);
	while (entities)
	{
		entity = entities->entity;
		sprite = entity->getSprite();
		if(sprite)
			placeSprite(entity->getXPos(), entity->getYPos(), sprite, entity->getColor());
		entities = entities->next;
	}
	wrefresh(stdscr);
}

void		Renderer::placeSprite(int x, int y, std::string *sprite, chtype color)
{
	int attr = 1;

	if(color == COLOR_GREEN)
		attr = COLOR_PAIR(2);
	else if (color == COLOR_RED)
		attr = COLOR_PAIR(3);
	else if (color == COLOR_MAGENTA)
		attr = COLOR_PAIR(1) | A_DIM;
	for (int v = 0; sprite[v][0]; ++v)
		for (int u = 0; sprite[v][u]; ++u)
			if (sprite[v][u] != ' ')
				mvwaddch(stdscr, y + v, x + u, sprite[v][u] | attr);
}

int			Renderer::getScreenWidth(void) const { return _width; }
int			Renderer::getScreenHeight(void) const { return _height; }

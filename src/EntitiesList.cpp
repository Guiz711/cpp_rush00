/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntitiesList.cpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 12:33:22 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/12 15:08:31 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntitiesList.hpp"

EntitiesList::EntitiesList(void):
	_list(NULL)
{}

EntitiesList::EntitiesList(const EntitiesList& src)
{
	copyList(src.getList());
}

EntitiesList::~EntitiesList(void)
{
	destroyList();
}

EntitiesList&	EntitiesList::operator=(const EntitiesList& rhs)
{
	if (this == &rhs)
		return *this;
	if (_list)
		clearList();
	copyList(rhs.getList());
	return *this;
}

void			EntitiesList::addEntity(AEntity *entity)
{
	EntityLink *link = new EntityLink;

	link->entity = entity;
	if (_list)
		_list->prev = link;
	link->next = _list;
	link->prev = NULL;
	_list = link;
}

void			EntitiesList::removeEntity(EntityLink *link)
{
	if (link->prev)
		link->prev->next = link->next;
	if (link->next)
		link->next->prev = link->prev;
	delete link->entity;
	delete link;
}

void			EntitiesList::clearList(void)
{
	EntityLink *tmp;

	while (_list)
	{
		tmp = _list;
		Log::instance().log(std::to_string(tmp->entity->getXPos()));
		_list = _list->next;
		delete tmp;
	}
}

EntityLink		*EntitiesList::getList(void) const { return _list; }

void			EntitiesList::copyList(EntityLink *src)
{
	while (src)
	{
		addEntity(src->entity);
		src = src->next;
	}
}

void			EntitiesList::destroyList(void)
{
	EntityLink *tmp;

	while (_list)
	{
		tmp = _list;
		_list = _list->next;
		delete tmp->entity;
		delete tmp;
	}
}

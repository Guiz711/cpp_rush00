/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:47:24 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/12 17:29:19 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntitiesList.hpp"
#include "Renderer.hpp"
#include <iostream>

int main(void)
{
	Renderer		renderer;
	EntitiesList 	*lst = new EntitiesList;
	AEntity			*test = new AEntity(10, 15);
	AEntity			*test2 = new AEntity(30, 50);
	AEntity			*test3 = new AEntity(100, 10);

	lst->addEntity(test);
	lst->addEntity(test2);
	lst->addEntity(test3);
	while(1)
	{
		renderer.renderScreen(lst->getList());
	}
	delete lst;
	return 0;
}

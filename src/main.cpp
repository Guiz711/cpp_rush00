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
#include "Physics.hpp"
#include <iostream>
#include <sys/time.h>
#include <unistd.h>


#include <ctime>


int main(void)
{
//	Renderer		renderer;
	EntitiesList 	*lst = new EntitiesList;
	AEntity			*test = new AEntity(0, 0);
	AEntity			*test2 = new AEntity(3, 1);
	AEntity			*test3 = new AEntity(100, 10);

	lst->addEntity(test);
	lst->addEntity(test2);
	lst->addEntity(test3);

	Physics			phys(lst);
	phys.checkCollisions();

	// while(1)
	// {
	// 	renderer.renderScreen(lst->getList());
	// }
	 delete lst;


  return 0;
}

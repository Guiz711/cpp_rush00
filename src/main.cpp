/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:47:24 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/12 14:52:58 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "EntitiesList.hpp"
#include <iostream>
#include <sys/time.h>
#include <unistd.h>


#include <ctime>


int main(void)
{
	EntitiesList 	*lst = new EntitiesList;
	AEntity			*test = new AEntity(1, 1);
	AEntity			*test2 = new AEntity(2, 2);
	AEntity			*test3 = new AEntity(3, 3);

	lst->addEntity(test);
	lst->addEntity(test2);
	lst->addEntity(test3);
	delete lst;


  return 0;
}

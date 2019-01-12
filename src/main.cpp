/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:47:24 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/12 12:07:44 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Log.hpp"
//#include "TimeClass.hpp"
#include <time.h>

int main(void)
{
//	TimeClass test;

//	test.setFrameTime();


  time_t t = time(NULL);
	printf("UTC:       %s", asctime(gmtime(&t)));
	printf("local:     %s", asctime(localtime(&t)));

	Log::instance().logWarning("Hi");
	Log::instance().log("How are you?");
	Log::instance().logError("Ouch");

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hud.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 16:27:13 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 20:40:03 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUD_HPP
# define HUD_HPP

# include <sstream>
# include "AEntity.hpp"

class Hud: public AEntity
{
	public:
		Hud(void);
		Hud(float posX, float posY);
		Hud(const Hud& src);
		~Hud(void);

		Hud&	operator=(const Hud& rhs);

		virtual void 		update( void );
		void 				updateLife(int hp);
		void				kill(void);

	private:
		double	_startTime;
};

#endif
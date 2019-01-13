/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Player.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 09:49:52 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 10:36:33 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAYER_HPP
# define PLAYER_HPP

# include "AEntity.hpp"
# include "Inputs.hpp"
# include "Time.hpp"
# include "Log.hpp"

class Player: public AEntity
{
	public:
		Player(void);
		Player(float posX, float posY);
		Player(const Player& src);
		~Player(void);

		Player&	operator=(const Player& rhs);

		virtual void update( void );
    	virtual void onCollision( void );

	private:
		float		_velocity[2];
};

#endif
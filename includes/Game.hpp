/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:38:29 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 11:47:22 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_HPP
# define GAME_HPP

# include "AEntity.hpp"
# include "Player.hpp"
# include "GameLoop.hpp"

class Game: public AEntity
{
	public:
		Game(void);
		Game(const Game& src);
		~Game(void);

		Game&	operator=(const Game& rhs);

		virtual void	update( void );
    virtual void	onCollision( void );

	private:

		void			init();
};

#endif

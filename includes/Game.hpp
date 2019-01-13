/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:38:29 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 20:00:48 by gmichaud         ###   ########.fr       */
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

		void			die(void);

	private:
		int					_spawnYMin;
		int					_spawnYMax;
		bool				_gameOver;
		static std::string	_endScreen[7];

		void			init();
};

#endif

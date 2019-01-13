/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Game.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/13 10:38:29 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/13 20:59:30 by gmichaud         ###   ########.fr       */
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
		~Game(void);

		Game&	operator=(const Game& rhs);

		virtual void	update( void );

		void			die(void);
		int				getSpawnMax( void ) const;
		int				getSpawnMin( void ) const;
		static bool		isGameOver(void);

	private:
		int					_spawnYMin;
		int					_spawnYMax;
		Player				*_player;
		static std::string	_endScreen[7];
		static bool			_gameOver;

		void			init();

		Game(const Game& src);
};

#endif

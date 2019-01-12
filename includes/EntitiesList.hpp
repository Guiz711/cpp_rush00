/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   EntitiesList.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gmichaud <gmichaud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/12 11:35:51 by gmichaud          #+#    #+#             */
/*   Updated: 2019/01/12 15:19:18 by gmichaud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ENTITIESLIST_HPP
# define ENTITIESLIST_HPP

# include "AEntity.hpp"
# include "Log.hpp"
# include <string>
# include <stdlib.h>

struct EntityLink
{
	AEntity				*entity;
	EntityLink			*prev;
	EntityLink			*next;
};

class EntitiesList
{
	public:
		EntitiesList(void);
		~EntitiesList(void);

<<<<<<< HEAD
		EntitiesList&	operator=(const EntitiesList& rhs);

=======
>>>>>>> 4ae516badcbd46a469470c4c0927ae97be1e789e
		void			addEntity(AEntity *entity);
		void			removeEntity(EntityLink *link);
		void			clearList(void);

		EntityLink		*getList(void) const;

	private:
		EntityLink		*_list;

		void			copyList(EntityLink *src);
		void			destroyList(void);

		EntitiesList(const EntitiesList& src);
		EntitiesList&	operator=(const EntitiesList& rhs);		
};

#endif

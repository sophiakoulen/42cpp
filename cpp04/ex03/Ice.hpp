/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:20:12 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:06:47 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ICE_H
# define ICE_H

# include "AMateria.hpp"

class Ice: public AMateria
{
	public:
		Ice();
		~Ice();
		Ice(const Ice& i);
		Ice&	operator=(const Ice& rhs);
	
		/* override virtual functions */

		Ice*	clone(void) const;
		void	use(ICharacter& target);
} ;

#endif

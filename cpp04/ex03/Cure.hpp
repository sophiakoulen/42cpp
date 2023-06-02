/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:20:12 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:08:16 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CURE_H
# define CURE_H

# include "AMateria.hpp"

class Cure: public AMateria
{
	public:
		Cure();
		~Cure();
		Cure(const Cure& c);
		Cure&	operator=(const Cure& rhs);
	
		/* override virtual functions */

		Cure*	clone(void) const;
		void	use(ICharacter& target);
} ;

#endif

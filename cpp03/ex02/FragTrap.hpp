/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:28:48 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 16:32:49 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRAG_TRAP_H
# define FRAG_TRAP_H

# include "ClapTrap.hpp"

class FragTrap: public ClapTrap
{
	public:
		FragTrap(const FragTrap& f);
		FragTrap(std::string name);
		~FragTrap(void);
		FragTrap& operator=(const FragTrap& f);

		void	highFivesGuys(void) const;

	private:
		FragTrap(void);
} ;

#endif

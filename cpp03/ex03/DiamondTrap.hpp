/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:47:19 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 11:54:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DIAMOND_TRAP_H
# define DIAMOND_TRAP_H

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

#include <string>

class DiamondTrap: public ScavTrap, public FragTrap
{
	public:
		DiamondTrap(std::string name);
		DiamondTrap(const DiamondTrap& d);
		~DiamondTrap(void);
		DiamondTrap& operator=(const DiamondTrap& d);

		using	ScavTrap::attack;
		void	whoAmI(void) const;

	private:
		DiamondTrap(void);
		std::string	_name;
} ;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:19:51 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 11:07:03 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAV_TRAP_H
# define SCAV_TRAP_H

# include "ClapTrap.hpp"
# include <string>

class ScavTrap: public ClapTrap
{
	public:
		ScavTrap(std::string name);
		ScavTrap(const ScavTrap& s);
		~ScavTrap(void);
		ScavTrap& operator=(const ScavTrap& s);
	
		/* ScavTrap's attack overwrites ClapTrap's attack */
		void	attack(const std::string& target);

		/* ScavTrap's special ability */
		void	guardGate(void) const;

	private:
		ScavTrap(void); //default constructor shouldn't be used
		
};

#endif

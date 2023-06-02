/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:26:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 12:28:18 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

# include <string>

class ClapTrap
{
	public:
		
		ClapTrap(const ClapTrap& c);
		ClapTrap& operator=(const ClapTrap& c);
		~ClapTrap(void);

		ClapTrap(std::string name);

		void	attack(const std::string& target);
		void	takeDamage(unsigned int amount);
		void	beRepaired(unsigned int amount);
			
	private:
		
		ClapTrap(void);
		
		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
} ;

#endif

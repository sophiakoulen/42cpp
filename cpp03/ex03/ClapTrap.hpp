/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:26:06 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 11:30:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAP_TRAP_H
# define CLAP_TRAP_H

# include <string>
# include <ostream>

class ClapTrap
{
	public:
		
		/* stuff that is mandatory for orthodox canonical form */
		ClapTrap(const ClapTrap& c);
		ClapTrap& operator=(const ClapTrap& c);

		/* THE destructor */
		~ClapTrap(void);

		/* THE constructor we're supposed to use */
		ClapTrap(std::string name);

		virtual	void	attack(const std::string& target);
		void			takeDamage(unsigned int amount);
		void			beRepaired(unsigned int amount);
	
		/* getters, used for ostream << overload */

		std::string	getName(void) const;
		int			getHitPoints(void) const;
		int			getEnergyPoints(void) const;
		int			getAttackDamage(void) const;

	private:
		
		/* default constructor, we don't want this to be used anywhere */
		ClapTrap(void);

	protected:

		/* constructor for use in derived classes only */
		ClapTrap(std::string n, int h, int e, int a);

		std::string	_name;
		int			_hit_points;
		int			_energy_points;
		int			_attack_damage;
} ;

std::ostream& operator<<(std::ostream& o, const ClapTrap& c);

#endif

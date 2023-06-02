/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:18:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 17:06:06 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_H
# define HUMAN_B_H

# include "Weapon.hpp"
# include <string>

using std::string;

class HumanB
{
	private:
		string	_name;
		Weapon	*_weapon;
	public:
		HumanB(string name);
		void	attack(void) const;
		void	setWeapon(Weapon &w);
		void	removeWeapon(void);
} ;

#endif

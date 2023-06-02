/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:17:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 16:31:29 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_H
# define HUMAN_A_H

# include "Weapon.hpp"
# include <string>

using std::string;

class HumanA
{
	private:
		string	_name;
		Weapon	&_weapon;
	public:
		HumanA(string name, Weapon &w);
		void	attack(void) const;
} ;

#endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:03:55 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 16:40:17 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_H
# define WEAPON_H

# include <iostream>
# include <string>

using std::string;

class Weapon
{
	private:
		string	_type;

	public:
		Weapon(void);
		Weapon(string const type);
		string const &getType(void) const;
		void	setType(std::string);
} ;

#endif

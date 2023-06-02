/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:06:33 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 16:56:21 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"
#include <string>

using std::string;

Weapon::Weapon(void):
	_type("unknown mysterious weapon")
{
	return ;
}

Weapon::Weapon(string type):
	_type(type)
{
	return ;
}

string const	&Weapon::getType(void) const
{
	return (this->_type);
}

void	Weapon::setType(string type)
{
	this->_type = type;
}

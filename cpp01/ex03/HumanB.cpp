/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:28:55 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 17:06:42 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"
#include "Weapon.hpp"
#include <iostream>
#include <string>

#define BLUE "\033[38:5:117m"
#define YELLOW "\033[33m"
#define RESET "\033[0m"

HumanB::HumanB(std::string name):
	_name(name), _weapon(0)
{
	return ;
}

void	HumanB::attack(void) const
{
	std::cout
		<<YELLOW<<this->_name<<RESET
		<<" attacks with their ";

	if (this->_weapon != 0)
		std::cout
			<<BLUE<<this->_weapon->getType()<<RESET
			<<std::endl;
	else
		std::cout<<"bare hands"<<std::endl;
}

void	HumanB::setWeapon(Weapon &w)
{
	this->_weapon = &w;
}

void	HumanB::removeWeapon(void)
{
	this->_weapon = 0;
}

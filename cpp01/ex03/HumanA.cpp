/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:25:08 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 17:00:27 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"
#include <string>
#include <iostream>

#define BLUE "\033[38:5:117m"
#define MAGENTA "\033[35m"
#define RESET "\033[0m"

HumanA::HumanA(std::string name, Weapon  &w):
	_name(name), _weapon(w)
{
	return ;
}

void	HumanA::attack(void) const
{
	std::cout
		<<MAGENTA<<this->_name<<RESET
		<<" attacks with their "
		<<BLUE<<this->_weapon.getType()<<RESET
		<<std::endl;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:32:08 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 15:25:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <iostream>

Zombie::Zombie(void):
	_name("A.N O'Nyme")
{
	return ;
}

Zombie::Zombie(std::string name):
	_name(name)
{
	return ;
}

Zombie::~Zombie(void)
{
	std::cout<<"Zombie "<<this->_name<<" has been destroyed"<<std::endl;
}

void	Zombie::announce(void) const
{
	std::cout<<this->_name<<": BraiiiiiiinnnzzzZ..."<<std::endl;
}

void	Zombie::setName(std::string name)
{
	this->_name = name;
}

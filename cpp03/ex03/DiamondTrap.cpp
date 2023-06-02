/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:59:50 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 11:55:08 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"
#include <iostream>

using std::cout;
using std::endl;

DiamondTrap::DiamondTrap(std::string name):
	ClapTrap(name + "_clap_name", 100, 50, 30),
	ScavTrap(name),	
   	FragTrap(name),
	_name(name)
{
	cout<<"DiamondTrap constructor called"<<endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap& d):
	ClapTrap(d),
	ScavTrap(d),
	FragTrap(d),
	_name(d._name)
{
	cout<<"DiamondTrap copy constructor called"<<endl;
}

DiamondTrap::~DiamondTrap(void)
{
	cout<<"DiamondTrap destructor called"<<endl;
}

DiamondTrap& DiamondTrap::operator=(const DiamondTrap& d)
{
	cout<<"DiamondTrap assignment operator called"<<endl;
	ScavTrap::operator=(d);
	_name = d._name;
	return (*this);
}

void	DiamondTrap::whoAmI(void) const
{
	cout<<"who am i? my name is "<<_name<<" and ClapTrap name is "
		<<this->ClapTrap::_name<<endl;
}

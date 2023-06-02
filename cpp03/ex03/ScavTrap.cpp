/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 14:26:29 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 11:10:03 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

ScavTrap::ScavTrap(std::string name):
	ClapTrap(name, 100, 50, 20) 
{
	cout<<"ScavTrap constructor called"<<endl;
}

ScavTrap::ScavTrap(const ScavTrap& s):
	ClapTrap(s)
{
	cout<<"ScavTrap copy constructor called"<<endl;
}

ScavTrap::~ScavTrap(void)
{
	cout<<"ScavTrap destructor called"<<endl;
}

ScavTrap& ScavTrap::operator=(const ScavTrap& s)
{
	cout<<"ScavTrap assignment operator called"<<endl;
	ClapTrap::operator=(s);
	return (*this);
}

/* ScavTrap's attack overwrites ClapTrap's attack */
void	ScavTrap::attack(const std::string& target)
{
	if (_energy_points <= 0)
	{
		cout<<"ScavTrap "<<_name<<" cannot attack: no energy left!"<<endl;
	}
	else if (_hit_points <= 0)
	{
		cout<<"ScavTrap "<<_name<< " cannot attack: they are dead!"<<endl;
	}
	else
	{
		cout<<"ScavTrap "<<_name<<" attacks "<<target<<", causing "
		<<_attack_damage<<" points of damage!"<<endl;
		_energy_points--;
	}
}

void	ScavTrap::guardGate(void) const
{
	cout<<"ScavTrap "<<_name<<" is now in mode Gate keeper"<<endl;
}

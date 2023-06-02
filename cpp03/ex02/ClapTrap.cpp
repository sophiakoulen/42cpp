/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 10:42:26 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/04 11:35:12 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::endl;

ClapTrap::ClapTrap(const ClapTrap& c):
	_name(c._name),
	_hit_points(c._hit_points),
	_energy_points(c._energy_points),
	_attack_damage(c._attack_damage)
{
	cout<<"ClapTrap copy constructor called"<<endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap& c)
{
	cout<<"ClapTrap assignment operator called"<<endl;
	_name = c._name;
	_hit_points = c._hit_points;
	_energy_points = c._energy_points;
	_attack_damage = c._attack_damage;
	return (*this);
}

ClapTrap::~ClapTrap(void)
{
	cout<<"ClapTrap destructor called"<<endl;
}

ClapTrap::ClapTrap(std::string name):
	_name(name),
	_hit_points(10),
	_energy_points(10),
	_attack_damage(0)
{
	cout<<"ClapTrap constructor called"<<endl;
}

void	ClapTrap::attack(const std::string& target)
{
	if (_energy_points <= 0)
	{
		cout<<"ClapTrap "<<_name<<" cannot attack: no energy left!"<<endl;
	}
	else if (_hit_points <= 0)
	{
		cout<<"ClapTrap "<<_name<< " cannot attack: they are dead!"<<endl;
	}
	else
	{
		cout<<"ClapTrap "<<_name<<" attacks "<<target<<", causing "
		<<_attack_damage<<" points of damage!"<<endl;
		_energy_points--;
	}
}

void	ClapTrap::takeDamage(unsigned int amount)
{
	cout<<"ClapTrap "<<_name<<" gets "<<amount<<" points of damage.";
	_hit_points -= amount;
	cout<<" Hit points left: "<<_hit_points<<endl;
}

void	ClapTrap::beRepaired(unsigned int amount)
{
	if (_energy_points <= 0)
	{
		cout<<"ClapTrap "<<_name<<" cannot repair itself: no energy left!"
			<<endl;
	}
	else if (_hit_points <= 0)
	{
		cout<<"ClapTrap "<<_name<<" cannot repair itself: they are dead!"
			<<endl;
	}
	else
	{
		cout<<"ClapTrap "<<_name<<" repairs itself with "<<amount<<" hit points"
			<<endl;
		_hit_points += amount;
		_energy_points--;
	}
}

std::string	ClapTrap::getName(void) const
{
	return (_name);
}

int	ClapTrap::getHitPoints(void) const
{
	return (_hit_points);
}

int	ClapTrap::getEnergyPoints(void) const
{
	return (_energy_points);
}

int	ClapTrap::getAttackDamage(void) const
{
	return (_attack_damage);
}

ClapTrap::ClapTrap(void)
{
	cout<<"ClapTrap default constructor called"<<endl;
}

ClapTrap::ClapTrap(std::string n, int h, int e, int a):
	_name(n), _hit_points(h), _energy_points(e),_attack_damage(a)
{
	cout<<"ClapTrap protected constructor called"<<endl;
}

std::ostream& operator<<(std::ostream& o, const ClapTrap& c)
{
	o<<"ClapTrap <"<<c.getName()<<">"<<endl;
	o<<"\thit points: "<<c.getHitPoints()<<endl;
	o<<"\tenergy points: "<<c.getEnergyPoints()<<endl;
	o<<"\tattack damage: "<<c.getAttackDamage()<<endl;
	return (o);
}

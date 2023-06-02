/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/19 13:35:02 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 12:36:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

Character::Character(const std::string& name):
	_name(name)
{
	cout<<"Character constructor called"<<endl;
}

Character::~Character(void)
{
	cout<<"Character destructor called"<<endl;
}

Character::Character(const Character& c):
	_name(c._name),
	_inventory(c._inventory) // is this going to call the copy constructor?
{
	cout<<"Character copy constructor called"<<endl;
}

Character&	Character::operator=(const Character& rhs)
{
	cout<<"Character assigment operator called"<<endl;	
	_name = rhs._name;
	_inventory = rhs._inventory;
	return (*this);
}

const std::string& Character::getName(void) const
{
	return (_name);
}

void	Character::equip(AMateria *m)
{
	AMateria**	slot = _inventory.get();
	if (slot)
		*slot = m;
}

void	Character::unequip(int idx)
{
	AMateria**	slot = _inventory.get(idx);
	if (slot)
		*slot = NULL;
}

void	Character::use(int idx, ICharacter& target)
{
	AMateria**	slot = _inventory.get(idx);
	if (slot)
		(*slot)->use(target);
}

std::string	Character::serialize() const
{
	std::stringstream	ss;

	ss<<"<Character>{"<<endl
		<<"_name: "<<_name<<","<<endl
		<<"_inventory: "<<_inventory.serialize()<<endl
		<<"}"<<endl;

	return (ss.str());
}

std::ostream&	operator<<(std::ostream& o, const Character& rhs)
{
	o<<rhs.serialize();
	return (o);
}

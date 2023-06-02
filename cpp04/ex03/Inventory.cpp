/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Inventory.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:24:34 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 12:35:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Inventory.hpp"
#include <sstream>
#include <iostream>

using std::cout;
using std::endl;

Inventory::Inventory()
{
	cout<<"Inventory constructor called"<<endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Inventory::Inventory(const Inventory& cpy)
{
	cout<<"Inventory copy constructor called"<<endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = cpy._inventory[i] ? cpy._inventory[i]->clone() : NULL;
}

Inventory::~Inventory()
{
	cout<<"Inventory destructor called"<<endl;
	for (int i = 0; i < 4; i++)
		delete _inventory[i];
}

Inventory&	Inventory::operator=(const Inventory& rhs)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
		_inventory[i] = rhs._inventory[i] ? rhs._inventory[i]->clone() : NULL;
	}
	return (*this);
}

AMateria**	Inventory::get()
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] == NULL)
			return (&_inventory[i]);
	}
	return (NULL);
}

AMateria**	Inventory::get(int idx)
{
	if (idx >= 0 && idx < 4 && _inventory[idx])
		return (&_inventory[idx]);
	return (NULL);
}

AMateria**	Inventory::get(const std::string& type)
{
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i] && _inventory[i]->getType() == type)
			return (&_inventory[i]);
	}
	return (NULL);
}

std::string	Inventory::serialize() const
{
	std::stringstream	ss;
	ss<<"<Inventory>[ ";
	for (int i = 0; i < 4; i++)
	{
		ss<<(_inventory[i] ? _inventory[i]->getType() : "NULL");
		ss<<(i < 3 ? ", " : " ");
	}
	ss<<"]";
	return (ss.str());
}

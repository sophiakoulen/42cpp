/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 11:01:50 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:26:15 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"
#include <iostream>
#include <sstream>

using std::cout;
using std::endl;

MateriaSource::MateriaSource(void)
{
	cout<<"MateriaSource constructor called"<<endl;
}

MateriaSource::MateriaSource(const MateriaSource& m):
	_inventory(m._inventory)
{
	cout<<"MateriaSource copy constructor called"<<endl;
}

MateriaSource::~MateriaSource(void)
{
	cout<<"MateriaSource destructor called"<<endl;
}

MateriaSource&	MateriaSource::operator=(const MateriaSource& rhs)
{
	cout<<"MateriaSource assignment operator called"<<endl;
	_inventory = rhs._inventory;
	return (*this);
}

void	MateriaSource::learnMateria(AMateria* m)
{
	AMateria**	slot = _inventory.get();
	if (slot)
		*slot = m->clone();
}

AMateria*	MateriaSource::createMateria(std::string const & type)
{
	AMateria**	slot = _inventory.get(type);
	if (slot)
		return ((*slot)->clone());
	return (NULL);
}

std::string	MateriaSource::serialize(void) const
{
	std::stringstream	ss;

	ss<<"<MateriaSource>{"<<endl;
	ss<<"_inventory: "<<_inventory.serialize()<<endl;
	ss<<"}"<<endl;

	return (ss.str());
}

std::ostream&	operator<<(std::ostream& o, const MateriaSource& rhs)
{
	o<<rhs.serialize();
	return (o);
}

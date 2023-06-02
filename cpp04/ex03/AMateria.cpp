/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:40:29 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:07:21 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include <iostream>

using std::cout;
using std::endl;

AMateria::AMateria(const std::string& type):
	_type(type)
{
	cout<<"AMateria constructor called"<<endl;
}

AMateria::AMateria(const AMateria& m):
	_type(m._type)
{
	cout<<"AMateria copy constructor called"<<endl;
}

AMateria::~AMateria(void)
{
	cout<<"AMateria destructor called"<<endl;
}

AMateria&	AMateria::operator=(const AMateria& rhs)
{
	cout<<"AMateria assignment operator called"<<endl;
	_type = rhs._type;
	return (*this);	
}

const std::string&	AMateria::getType(void) const
{
	return (_type);
}

void	AMateria::use(ICharacter& target)
{
	cout<<"* AMateria of type "<<_type<<" used against "<<target.getName()
		<<" *"<<endl;
}

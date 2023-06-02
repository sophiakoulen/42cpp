/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:19:36 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:08:49 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include <iostream>

using std::cout;
using std::endl;

Cure::Cure():
	AMateria("cure")
{
	cout<<"Cure constructor called"<<endl;
}

Cure::~Cure()
{
	cout<<"Cure destructor called"<<endl;
}

Cure::Cure(const Cure& c):
	AMateria(c)
{
	cout<<"Cure copy constructor called"<<endl;
}

Cure&	Cure::operator=(const Cure& rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}

/* override virtual functions */

Cure*	Cure::clone(void) const
{
	return (new Cure(*this));
}

void	Cure::use(ICharacter& target)
{
	cout<<"* heals "<<target.getName()<<"'s wounds *"<<endl;
}


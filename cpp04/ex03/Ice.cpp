/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/18 13:19:36 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 14:08:34 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include <iostream>

using std::cout;
using std::endl;

Ice::Ice():
	AMateria("ice")
{
	cout<<"Ice constructor called"<<endl;
}

Ice::~Ice()
{
	cout<<"Ice destructor called"<<endl;
}

Ice::Ice(const Ice& i):
	AMateria(i)
{
	cout<<"Ice copy constructor called"<<endl;
}

Ice&	Ice::operator=(const Ice& rhs)
{
	AMateria::operator=(rhs);
	return (*this);
}

/* override virtual functions */

Ice*	Ice::clone(void) const
{
	return (new Ice(*this));
}

void	Ice::use(ICharacter& target)
{
	cout<<"* shoots an ice bolt at "<<target.getName()<<" *"<<endl;
}


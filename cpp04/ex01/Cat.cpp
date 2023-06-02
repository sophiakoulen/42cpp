/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:21:17 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 09:29:56 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

using std::cout;
using std::endl;

Cat::Cat(void):
	_brain(new Brain())
{
	cout<<"Cat default constructor called"<<endl;
	_type = "Cat";
}

Cat::Cat(const Cat& d):
	Animal(d)
{
	cout<<"Cat copy constructor called"<<endl;
	_brain = d._brain;
}

Cat::~Cat(void)
{
	cout<<"Cat destructor called"<<endl;
	delete _brain;
}

Cat& Cat::operator=(const Cat& d)
{
	cout<<"Cat assignment operator called"<<endl;
	Animal::operator=(d);
	*_brain = *d._brain;
	return (*this);
}

void	Cat::makeSound(void) const
{
	cout<<"Cat sound: miaou miaou..."<<endl;
}

Brain& Cat::getBrain(void) const
{
	return (*_brain);
}

std::ostream&	operator<<(std::ostream& o, const Cat& rhs)
{
	o<<rhs.getType()<<endl;
	o<<rhs.getBrain();
	return (o);
}

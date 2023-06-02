/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:21:27 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 10:52:43 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

using std::cout;
using std::endl;

Dog::Dog(void):
	_brain(new Brain())
{
	cout<<"Dog default constructor called"<<endl;
	_type = "Dog";
}

Dog::Dog(const Dog& d):
	AAnimal(d)
{
	cout<<"Dog copy constructor called"<<endl;
	_brain = d._brain;
}

Dog::~Dog(void)
{
	cout<<"Dog destructor called"<<endl;
	delete _brain;
}

Dog& Dog::operator=(const Dog& d)
{
	cout<<"Dog assignment operator called"<<endl;
	AAnimal::operator=(d);
	*_brain = *d._brain;
	return (*this);
}

void	Dog::makeSound(void) const
{
	cout<<"Dog sound: wouaf wouaf..."<<endl;
}

Brain& Dog::getBrain(void) const
{
	return (*_brain);
}

std::ostream&	operator<<(std::ostream& o , const Dog& rhs)
{
	o<<rhs.getType()<<endl;
	o<<rhs.getBrain();
	return (o);
}


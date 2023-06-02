/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:55:03 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 12:32:19 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include <iostream>

using std::cout;
using std::endl;

Animal::Animal(void)
	: _type("DefaultAnimalType")
{
	cout<<"Animal default constructor called"<<endl;
}

Animal::Animal(const Animal& a):
	_type(a._type)
{
	cout<<"Animal copy constructor called"<<endl;
}

Animal::~Animal(void)
{
	cout<<"Animal destructor called"<<endl;
}

Animal& Animal::operator=(const Animal& a)
{
	cout<<"Animal assignment operator called"<<endl;
	_type = a._type;
	return (*this);
}

void	Animal::makeSound(void) const
{
	cout<<"Animal sound: weird sound..."<<endl;
}

std::string	Animal::getType(void) const
{
	return (_type);
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 15:32:18 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 15:33:40 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "WrongAnimal.hpp"
#include <iostream>

using std::cout;
using std::endl;

WrongAnimal::WrongAnimal(void)
	: _type("DefaultWrongAnimalType")
{
	cout<<"WrongAnimal default constructor called"<<endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& a):
	_type(a._type)
{
	cout<<"WrongAnimal copy constructor called"<<endl;
}

WrongAnimal::~WrongAnimal(void)
{
	cout<<"WrongAnimal destructor called"<<endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& a)
{
	cout<<"WrongAnimal assignment operator called"<<endl;
	_type = a._type;
	return (*this);
}

void	WrongAnimal::makeSound(void) const
{
	cout<<"WrongAnimal sound: weird sound..."<<endl;
}

std::string	WrongAnimal::getType(void) const
{
	return (_type);
}

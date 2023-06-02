/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 14:55:03 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/17 11:05:53 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"
#include <iostream>

using std::cout;
using std::endl;

AAnimal::AAnimal(void)
	: _type("DefaultAAnimalType")
{
	cout<<"AAnimal default constructor called"<<endl;
}

AAnimal::AAnimal(const AAnimal& a):
	_type(a._type)
{
	cout<<"AAnimal copy constructor called"<<endl;
}

AAnimal::~AAnimal(void)
{
	cout<<"AAnimal destructor called"<<endl;
}

AAnimal& AAnimal::operator=(const AAnimal& a)
{
	cout<<"AAnimal assignment operator called"<<endl;
	_type = a._type;
	return (*this);
}

std::string	AAnimal::getType(void) const
{
	return (_type);
}

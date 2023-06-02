/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/04 15:21:27 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 12:32:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include <iostream>

using std::cout;
using std::endl;

Dog::Dog(void)
{
	cout<<"Dog default constructor called"<<endl;
	_type = "Dog";
}

Dog::Dog(const Dog& d):
	Animal(d)
{
	cout<<"Dog copy constructor called"<<endl;
}

Dog::~Dog(void)
{
	cout<<"Dog destructor called"<<endl;
}

Dog& Dog::operator=(const Dog& d)
{
	cout<<"Dog assignment operator called"<<endl;
	Animal::operator=(d);
	return (*this);
}

void	Dog::makeSound(void) const
{
	cout<<"Dog sound: wouaf wouaf..."<<endl;
}


/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:21:17 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 12:33:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"
#include <iostream>

using std::cout;
using std::endl;

Cat::Cat(void)
{
	cout<<"Cat default constructor called"<<endl;
	_type = "Cat";
}

Cat::Cat(const Cat& d):
	Animal(d)
{
	cout<<"Cat copy constructor called"<<endl;
}

Cat::~Cat(void)
{
	cout<<"Cat destructor called"<<endl;
}

Cat& Cat::operator=(const Cat& d)
{
	cout<<"Cat assignment operator called"<<endl;
	Animal::operator=(d);
	return (*this);
}

void	Cat::makeSound(void) const
{
	cout<<"Cat sound: miaou miaou..."<<endl;
}

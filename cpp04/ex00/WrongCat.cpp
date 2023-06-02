/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/05 12:21:17 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 15:44:03 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"
#include <iostream>

using std::cout;
using std::endl;

WrongCat::WrongCat(void)
{
	cout<<"WrongCat default constructor called"<<endl;
	_type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat& d):
	WrongAnimal(d)
{
	cout<<"WrongCat copy constructor called"<<endl;
}

WrongCat::~WrongCat(void)
{
	cout<<"WrongCat destructor called"<<endl;
}

WrongCat& WrongCat::operator=(const WrongCat& d)
{
	cout<<"WrongCat assignment operator called"<<endl;
	WrongAnimal::operator=(d);
	return (*this);
}

void	WrongCat::makeSound(void) const
{
	cout<<"WrongCat sound: miaou miaou..."<<endl;
}

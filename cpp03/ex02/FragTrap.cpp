/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 16:32:58 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/04 11:36:08 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"
#include <string>
#include <iostream>

using std::cout;
using std::endl;

FragTrap::FragTrap(const FragTrap& f) :
	ClapTrap(f)
{
	cout<<"FragTrap copy constructor called"<<endl;
}

FragTrap::FragTrap(std::string name) :
	ClapTrap(name, 100, 100, 30)
{
	cout<<"FragTrap constructor called"<<endl;	
}

FragTrap::~FragTrap(void)
{
	cout<<"FragTrap destructor called"<<endl;
}

FragTrap& FragTrap::operator=(const FragTrap& f)
{
	cout<<"FragTrap assignment operator called"<<endl;
	ClapTrap::operator=(f);
	return (*this);
}

void	FragTrap::highFivesGuys(void) const
{
	cout<<"Please give high fives"<<endl;
}


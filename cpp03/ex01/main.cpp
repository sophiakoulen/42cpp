/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:21:03 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 12:04:33 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int	main(void)
{
	
	ScavTrap b(string("Bob"));
	
	cout<<"b is initially:"<<endl<<b<<endl;

	b.takeDamage(15);
	
	cout<<endl<<"testing attack()"<<endl;
	b.attack("Alice");
	
	cout<<endl<<"testing ClapTrap::attack()"<<endl;
	b.ClapTrap::attack("Alice");
	cout<<endl;

	b.beRepaired(3);
	
	b.ClapTrap::attack("truc");

	b.guardGate();

	cout<<"b is now"<<endl<<b<<endl;

	cout<<endl<<"Testing assignment operator:"<<endl<<endl;
	
	ScavTrap b1("another stupid name");
	b1 = b;
	cout<<"b1 is:"<<endl<<b1<<endl;

	cout<<endl<<"Testing copy constructor:"<<endl<<endl;
	
	ScavTrap b2(b1);
	cout<<"b2 is:"<<endl<<b2<<endl;

	cout<<endl;

	return (0);
}

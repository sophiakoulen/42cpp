/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:21:03 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 17:11:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int	main(void)
{
	cout<<"Testing ClapTrap Alice:"<<endl<<endl;

	ClapTrap a(string("Alice"));
	
	cout<<"a is initially:"<<endl<<a<<endl;

	a.attack("some random creature");
	a.takeDamage(3);
	a.beRepaired(2);
	for (int i = 0; i < 15; i++)
		a.attack("a target");

	a.attack("a thing");
	a.attack("the keybard");

	cout<<"a is now:"<<endl<<a<<endl;

	cout<<endl<<"Testing ScavTrap Bob:"<<endl<<endl;
	
	ScavTrap b(string("Bob"));
	
	cout<<"b is initially:"<<endl<<b<<endl;

	b.takeDamage(15);
	b.attack("Alice");
	b.beRepaired(3);
	
	b.guardGate();

	cout<<"b is now"<<endl<<b<<endl;

	cout<<"Testing FragTrap Charles:"<<endl<<endl;

	FragTrap c("Charles");
	cout<<"c is initially:"<<endl<<c<<endl;
	c.attack("truc");
	c.takeDamage(13);
	c.beRepaired(5);
	c.highFivesGuys();
	cout<<"c is now:"<<endl<<c<<endl;

	cout<<endl<<"Testing assignment operator:"<<endl<<endl;
	
	ClapTrap a1("stupid name");
	a1 = a;
	cout<<"a1 is:"<<endl<<a1<<endl;

	ScavTrap b1("another stupid name");
	b1 = b;
	cout<<"b1 is:"<<endl<<b1<<endl;

	cout<<endl<<"Testing copy constructor:"<<endl<<endl;
	
	ClapTrap a2(a1);
	cout<<"a2 is:"<<endl<<a2<<endl;

	ScavTrap b2(b1);
	cout<<"b2 is:"<<endl<<b2<<endl;

	cout<<endl;

	return (0);
}

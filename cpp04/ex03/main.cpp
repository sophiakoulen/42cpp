/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:07:27 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/20 12:42:44 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "Cure.hpp"
#include "Character.hpp"

#include <iostream>

using std::cout;
using std::endl;

int	main(void)
{
	Character alice("Alice");
	Character bob("Bob");

	AMateria* m1 = new Ice();
	AMateria* m2 = new Cure();
	AMateria* m3 = m1->clone();
	AMateria* m4 = m2->clone();
	AMateria* m5 = m3->clone();
	cout<<endl;

	/* test if equip(), unequip() and use() methods work */

	alice.equip(m1);
	cout<<alice;
	alice.use(0, bob);
	alice.equip(m2);
	cout<<alice;
	alice.use(1, bob);
	alice.use(2, bob);
	alice.use(-1, bob);
	alice.equip(m3);
	cout<<alice;
	alice.equip(m4);
	cout<<alice;
	alice.equip(m5);
	cout<<alice;
	alice.use(3, bob);
	alice.unequip(0);
	cout<<alice;
	alice.use(0, bob);

	cout<<endl;

	/* test copy and assigning */
	
	bob = alice;
	cout<<bob;

	Character	charles(alice); 
	cout<<charles;

	charles.use(1, charles);

	delete m1;
	delete m5;

	return 0;
}

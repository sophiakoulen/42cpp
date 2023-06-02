/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:21:03 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/03 13:49:20 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include <string>

using std::string;

int	main(void)
{
	ClapTrap a(string("Alice"));
	ClapTrap b(string("Bob"));

	a.attack("some random creature");
	a.takeDamage(3);
	a.beRepaired(2);
	for (int i = 0; i < 15; i++)
		a.attack("a target");

	a.attack("a thing");
	a.attack("the keybard");

	b.takeDamage(15);
	b.attack("Alice");
	b.beRepaired(3);

	return (0);
}

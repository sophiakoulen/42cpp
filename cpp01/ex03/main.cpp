/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 16:03:31 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 17:07:18 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Weapon.hpp"
#include "HumanA.hpp"
#include "HumanB.hpp"

int	main()
{
	Weapon	w1;
	Weapon	w2("scary algorithms");
	Weapon	w3("minishell nightmares spell");
	Weapon	w4("diabolicaly fast typing skills");

	HumanA alice("alice", w1);
	alice.attack();
	w1.setType("ponzi scheme");
	alice.attack();

	HumanA bob("bob", w2);
	bob.attack();
	w2.setType("even scarier mathematics");
	bob.attack();

	HumanB charles("charles");
	charles.attack();
	charles.setWeapon(w1);
	charles.attack();
	charles.removeWeapon();
	charles.attack();

	HumanB daniel("daniel");
	daniel.attack();

	daniel.setWeapon(w4);
	daniel.attack();

	charles.setWeapon(w3);
	charles.attack();

	return (0);
}

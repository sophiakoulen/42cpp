/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:21:03 by skoulen           #+#    #+#             */
/*   Updated: 2023/04/05 11:58:48 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"
#include "ScavTrap.hpp"
#include "FragTrap.hpp"
#include "DiamondTrap.hpp"
#include <string>
#include <iostream>

using std::string;
using std::cout;
using std::endl;

int	main(void)
{
	DiamondTrap d("David");

	cout<<endl<<d<<endl;

	cout<<"testing attack() method:"<<endl;
	d.attack("thing");
	cout<<endl;

	cout<<"testing whoAmI() method:"<<endl;
	d.whoAmI();
	cout<<endl;

	cout<<"testing guardGate() method:"<<endl;
	d.guardGate();
	cout<<endl;

	cout<<"testing highFivesGuys() method:"<<endl;
	d.highFivesGuys();
	cout<<endl;

	cout<<"testing beRepaired() method:"<<endl;
	d.beRepaired(15);
	cout<<endl;

	cout<<d<<endl;

	return (0);
}

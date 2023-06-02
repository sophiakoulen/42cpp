/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 14:32:51 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 15:37:00 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie	*zombieHorde(int N, std::string name);

int	main()
{
	Zombie	*truc = new Zombie();
	truc->announce();

	Zombie	*jean_michel = new Zombie("Jean-Michel");
	jean_michel->announce();

	delete	truc;
	delete jean_michel;

	Zombie *horde = zombieHorde(5, "un membre de la horde");
	for (int i = 0; i < 5; i++)
	{
		horde[i].announce();
	}
	delete [] horde;

	Zombie	surLaStack_1;
	surLaStack_1.announce();

	Zombie	surLaStack_2("Patrick");
	surLaStack_2.announce();

	return (0);
}

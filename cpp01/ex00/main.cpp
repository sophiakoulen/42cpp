/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:55:43 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/08 14:29:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Zombie.hpp"

Zombie	*newZombie(std::string name);
void	randomChump(std::string name);

int	main()
{
	Zombie *paul = newZombie("Paul");
	Zombie *pierre = newZombie("Pierre");

	paul->announce();
	pierre->announce();

	delete paul;
	delete pierre;

	randomChump("Antoinette");
	randomChump("Josiane");

	return (0);
}

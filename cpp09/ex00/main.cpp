/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 11:24:10 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/11 17:34:19 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "BitcoinExchange.hpp"

int main(int argc, char **argv)
{
	(void) argv;

	if (argc != 2)
	{
		std::cout << "Usage: ./btc [inputfile]" << std::endl;
		return (1);
	}

	BitcoinExchange btc("data.csv");
	btc.doInput(argv[1]);
	return (0);
}

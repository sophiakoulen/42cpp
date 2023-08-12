/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausann>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/11 17:45:58 by skoulen           #+#    #+#             */
/*   Updated: 2023/08/12 11:30:23 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"
#include <iostream>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "usage: ./RPN [computation]" << std::endl;
		return (1);
	}

	RPN calculator;
	calculator.compute(argv[1]);
	return 0;
}

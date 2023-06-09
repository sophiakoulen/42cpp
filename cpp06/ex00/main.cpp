/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/09 11:31:50 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/09 16:04:25 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "ScalarConverter.hpp"

using std::cout;
using std::endl;

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		cout<<"Usage: ./convert <value>"<<endl;
		return (1);
	}	
	std::string arg = argv[1];
	ScalarConverter::convert(arg);
	return (0);
}
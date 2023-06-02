/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 18:15:59 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/13 09:47:28 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>
#include <string>

using std::cout;
using std::cerr;
using std::endl;

int main(int argc, char **argv)
{
	std::string	str;
	int			level;

	if (argc != 2)
	{
		cerr<<"Usage: ./HarlFilter level"<<endl
			<<"Level can be DEBUG, INFO, WARNING or ERROR"<<endl;
		return (2);
	}

	str = argv[1];
	if (str == "DEBUG")
		level = 0;
	else if (str == "INFO")
		level = 1;
	else if (str == "WARNING")
		level = 2;
	else if (str == "ERROR")
		level = 3;
	else
		level = -1;

	Harl	harl;

	switch (level)
	{
		case 0:
			cout<<"[ DEBUG ]"<<endl;
			harl.complain("debug");
			cout<<endl;

		case 1:
			cout<<"[ INFO ]"<<endl;
			harl.complain("info");
			cout<<endl;

		case 2:
			cout<<"[ WARNING ]"<<endl;
			harl.complain("warning");
			cout<<endl;

		case 3:
			cout<<"[ ERROR ]"<<endl;
			harl.complain("error");
			cout<<endl;
			break ;

		default:
			cout<<"[ Probably complaining about insignificant  problems ]"<<endl;
	}
	return (0);
}
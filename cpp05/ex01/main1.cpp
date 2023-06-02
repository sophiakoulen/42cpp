/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:46:15 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 17:47:15 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	try
	{
		Form f1("trucBidule", -1, 45);
	}
	catch (std::exception& e)
	{
		cout<<"something went wrong: "<<e.what()<<endl;
	}
	
	try
	{
		Form f2("machinTruc", 3, 1500000);
	}
	catch (std::exception& e)
	{
		cout<<"something went wrong: "<<e.what()<<endl;
	}
}

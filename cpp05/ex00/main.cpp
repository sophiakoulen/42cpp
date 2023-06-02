/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:46:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 16:23:06 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Bureaucrat john("John", 3);
	john.decreaseGrade();
	try
	{
		for (int i = 0; i < 4; i++)
		{
			cout<<john;
			john.increaseGrade();
		}
	} catch (std::exception& e)
	{
		cout<<"Exception caught: "<<e.what()<<endl;
	}

	return 0;
}

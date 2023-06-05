/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:46:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/05 13:11:18 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{	
	Bureaucrat b1("Alice", 1);
	Bureaucrat b2("Bob", 130);

	cout<<endl;

	ShrubberyCreationForm s1("garden");
	b1.signForm(s1);
	b1.executeForm(s1);

	cout<<endl;

	RobotomyRequestForm r1("Bob");
	b1.signForm(r1);
	b1.executeForm(r1);

	cout<<endl;

	b2.executeForm(r1);

	cout<<endl;


	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:06:42 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:24:37 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Bureaucrat	alice("Alice", 17);

	AForm*	form = new RobotomyRequestForm("Bob");
	AForm*	form1 = new RobotomyRequestForm("Charles");
	AForm*	form2 = new RobotomyRequestForm("David");
	AForm*	form3 = new RobotomyRequestForm("Eric");
	cout<<endl;

	alice.executeForm(*form);

	cout<<endl;

	alice.signForm(*form);
	alice.executeForm(*form);

	cout<<endl;
	alice.signForm(*form1);
	alice.signForm(*form2);
	alice.signForm(*form3);

	cout<<endl;

	alice.executeForm(*form1);
	alice.executeForm(*form2);
	alice.executeForm(*form3);

	cout<<endl;

	delete form;
	delete form1;
	delete form2;
	delete form3;

	return (0);
}
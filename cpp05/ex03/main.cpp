/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:46:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:44:38 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Bureaucrat b("Charles", 2);
	Intern fred;

	cout<<endl;

	AForm *form;

	form = fred.makeForm("robotomy request", "bob");
	cout<<*form;
	b.signForm(*form);
	b.executeForm(*form);
	delete form;
	cout<<endl;

	form = fred.makeForm("shrubbery creation", "truc");
	cout<<*form;
	b.signForm(*form);
	b.executeForm(*form);
	delete form;
	cout<<endl;

	form = fred.makeForm("presidential pardon", "alice");
	cout<<*form;
	b.signForm(*form);
	b.executeForm(*form);
	delete form;
	cout<<endl;

	form = fred.makeForm("stupidity certification", "donald");
	cout<<endl;

	return 0;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:46:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/05 18:00:59 by skoulen          ###   ########.fr       */
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
	Intern fred;
	AForm *form;

	form = fred.makeForm("robotomy request", "bob");
	cout<<*form;
	delete form;
	cout<<endl;
	
	form = fred.makeForm("shrubbery creation", "truc");
	cout<<*form;
	delete form;
	cout<<endl;

	form = fred.makeForm("presidential pardon", "alice");
	cout<<*form;
	delete form;
	cout<<endl;

	form = fred.makeForm("stupidity certification", "donald");
	cout<<endl;

	return 0;
}

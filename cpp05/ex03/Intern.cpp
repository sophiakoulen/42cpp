/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 17:39:30 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:41:24 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

using std::cout;
using std::endl;

Intern::Intern()
{
	cout<<"Intern ctor"<<endl;
}

Intern::Intern(const Intern& cpy)
{
	cout<<"Intern cpy ctor"<<endl;
	(void)cpy;
}

Intern::~Intern()
{
	cout<<"Intern dtor"<<endl;
}

Intern&	Intern::operator=(const Intern& rhs)
{
	cout<<"Intern cpy assignment"<<endl;
	(void)rhs;
	return (*this);
}

AForm*	Intern::RRFFactory(std::string target) const
{
	return new RobotomyRequestForm(target);
}

AForm*	Intern::SCFFactory(std::string target) const
{
	return new ShrubberyCreationForm(target);
}

AForm*	Intern::PPFFactory(std::string target) const
{
	return new PresidentialPardonForm(target);
}

#define N_OBJS	3

AForm*	Intern::makeForm(std::string name, std::string target)
{
	AForm*	(Intern::*func[N_OBJS])(std::string) const = {
		&Intern::RRFFactory,
		&Intern::SCFFactory,
		&Intern::PPFFactory
	};

	std::string names[N_OBJS] = {
		"robotomy request",
		"shrubbery creation",
		"presidential pardon"
	};

	for (int i = 0; i < N_OBJS; i++)
	{
		if (name == names[i])
			return (((*this).*func[i])(target));
	}
	cout<<"Error: there's no form with name \""<<name<<"\""<<endl;
	return (NULL);
}

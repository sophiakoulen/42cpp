/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 09:49:48 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:05:55 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Bureaucrat	alice("Alice", 78);
	Bureaucrat	bob("Bob", 145);

	ShrubberyCreationForm	form("garden");
	cout<<endl<<form<<endl;

	alice.signForm(form);
	alice.executeForm(form);

	cout<<endl<<form<<endl;

	cout<<endl;

	bob.signForm(form);
	bob.executeForm(form);

	cout<<endl;

	alice.executeForm(form); /* Can a form be executed twice ? */
	cout<<endl;

	return (0);
}
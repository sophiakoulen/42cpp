/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main3.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 10:17:49 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:21:33 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "PresidentialPardonForm.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Bureaucrat	alice("Alice", 26);
	Bureaucrat	bob("Bob", 3);

	PresidentialPardonForm	form(bob.getName());

	cout<<endl;

	alice.signForm(form);
	alice.increaseGrade();
	alice.signForm(form);

	cout<<endl;

	alice.executeForm(form);
	bob.executeForm(form);

	cout<<endl;

	return (0);
}
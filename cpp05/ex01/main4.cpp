/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main4.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:46:15 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 16:30:14 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Bureaucrat alice("Alice", 17);
	Bureaucrat bob("Bob", 2);

	Form f1("Form1", 15, 2);
	Form f2("Form2", 145, 146);

	alice.signForm(f1);
	bob.signForm(f2);
}

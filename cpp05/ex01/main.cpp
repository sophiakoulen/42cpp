/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 17:46:09 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/13 10:32:32 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Form f1("Stupid form", 56, 2);
	Bureaucrat alice("Alice", 57);

	cout<<endl<<f1<<endl;

	alice.signForm(f1);
	alice.increaseGrade();
	alice.signForm(f1);

	cout<<endl<<f1<<endl;

	alice.signForm(f1);

	cout<<endl;

	return 0;
}

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

	bob = alice;
	cout<<bob;

	Bureaucrat alice2(alice);
	cout<<alice2;
	alice2.decreaseGrade();
	cout<<alice2;
}

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:46:15 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 17:54:13 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	Bureaucrat dave("Dave", 3);
	Form f1("interestingForm", 2, 2);
	
	try
	{
		f1.beSigned(dave);
	}
	catch(Form::GradeTooLowException &e)
	{
		cout<<"something went wrong: "<<e.what()<<endl;
	}

	cout<<f1;
}

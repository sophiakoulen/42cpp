/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main1.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/02 12:46:15 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/02 14:54:49 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include <iostream>

using std::cout;
using std::endl;

int main()
{
	cout<<"Trying grade 200..."<<endl;
	try
	{
		Bureaucrat Didier("Didier", 200);
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		cout<<e.what()<<endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		cout<<e.what()<<endl;
	}
	cout<<endl;

	cout<<"Trying grade 3..."<<endl;
	try
	{
		Bureaucrat Helen("Helen", 3);
	}
	catch (Bureaucrat::GradeTooHighException e)
	{
		cout<<e.what()<<endl;
	}
	catch (Bureaucrat::GradeTooLowException e)
	{
		cout<<e.what()<<endl;
	}
	cout<<endl;

	cout<<"Trying grade 14..."<<endl;
	try
	{
		Bureaucrat *myriam = new Bureaucrat("Myriam", 14);
		delete myriam;
	}
	catch (std::exception e)
	{
		cout<<e.what()<<endl;
	}
	cout<<endl;

	cout<<"Trying grade -2..."<<endl;
	try
	{
		Bureaucrat *robert = new Bureaucrat("myriam", -2);
		delete robert;
	}
	catch (std::exception e)
	{
		cout<<e.what()<<endl;
	}
	cout<<endl;

	cout<<"Trying grade -151..."<<endl;
	try
	{
		Bureaucrat *john = new Bureaucrat("John", 151);
		delete john;
	}
	catch (std::exception& e)
	{
		cout<<e.what()<<endl;
	}
	cout<<endl;
}

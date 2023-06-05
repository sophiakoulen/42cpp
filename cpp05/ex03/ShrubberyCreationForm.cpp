/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:18:41 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/05 17:13:42 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
#include <fstream>
#include <cstring>
#define SCF ShrubberyCreationForm

using std::cout;
using std::endl;

SCF::SCF(const std::string& target):
	AForm("ShrubberyCreationForm", 145, 137),
	_target(target)
{
	cout<<"ShrubberyCreationForm ctor"<<endl;
}

SCF::SCF(const SCF& cpy):
	AForm(cpy),
	_target(cpy._target)
{
	cout<<"ShrubberyCreationForm cpy ctor"<<endl;
}

SCF::~SCF()
{
	cout<<"ShrubberyCreationForm dtor"<<endl;
}

SCF&	SCF::operator=(const SCF& rhs)
{
	cout<<"SCF assignment operator"<<endl;
	AForm::operator=(rhs);
	return (*this);
}

void	SCF::action() const
{
	cout<<"* gardening is fun! *"<<endl;
	
	std::string filename("");
	filename += _target;
	filename += "_shrubbery";
	std::ofstream output(filename.c_str());

	if (output.fail())
	{
		cout<<"* failed to write to output file "<<filename<<" *"<<endl;
		cout<<"* "<<std::strerror(errno)<<" *"<<endl;	
	}
	else
	{
		output<<"           ,@@@@@@@,"<<endl;
		output<<"   ,,,.   ,@@@@@@/@@,  .oo8888o."<<endl;
		output<<",&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o"<<endl;
		output<<",%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'"<<endl;
		output<<"%&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'"<<endl;
		output<<"%&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'"<<endl;
		output<<"`&%\\ ` /%&'    |.|        \\ '|8'"<<endl;
		output<<"    |o|        | |         | |"<<endl;
		output<<"    |.|        | |         | |"<<endl;
		output<<" \\\\/ ._\\//_/__/  ,\\_//__\\\\/.  \\_//__/_"<<endl;
		
		cout<<"* Shrubbery has been created in "<<filename<<" *"<<endl;
	}	
}

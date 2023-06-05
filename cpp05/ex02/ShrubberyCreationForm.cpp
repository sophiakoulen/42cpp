/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:18:41 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/05 12:00:51 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <iostream>
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
	cout<<"ShrubberyCreationForm ACTION"<<endl;
}

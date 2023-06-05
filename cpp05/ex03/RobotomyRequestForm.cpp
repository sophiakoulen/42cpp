/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:18:41 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/05 17:15:45 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#define RRF RobotomyRequestForm

using std::cout;
using std::endl;

RRF::RRF(const std::string& target):
	AForm("RobotomyRequestForm", 72, 45),
	_target(target)
{
	cout<<"RobotomyRequestForm ctor"<<endl;
	srand(time(NULL));
}

RRF::RRF(const RRF& cpy):
	AForm(cpy),
	_target(cpy._target)
{
	cout<<"RobotomyRequestForm cpy ctor"<<endl;
}

RRF::~RRF()
{
	cout<<"RobotomyRequestForm dtor"<<endl;
}

RRF&	RRF::operator=(const RRF& rhs)
{
	cout<<"RobotomyRequestForm assignment operator"<<endl;
	AForm::operator=(rhs);
	return (*this);
}

void	RRF::action() const
{
	cout<<"* scary drilling sounds *"<<endl;
	if (rand() % 2)
		cout<<"* "<<_target<<" has succesfully been robotomized! *"<<endl;
	else
		cout<<"* "<<_target<<"'s robotomy has failed. *"<<endl;
}

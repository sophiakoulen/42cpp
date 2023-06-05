/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/05 11:18:41 by skoulen           #+#    #+#             */
/*   Updated: 2023/06/05 17:14:47 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"
#include <iostream>
#include <cstdlib>
#include <ctime>
#define PPF PresidentialPardonForm

using std::cout;
using std::endl;

PPF::PPF(const std::string& target):
	AForm("PresidentialPardonForm", 25, 5),
	_target(target)
{
	cout<<"PresidentialPardonForm ctor"<<endl;
	srand(time(NULL));
}

PPF::PPF(const PPF& cpy):
	AForm(cpy),
	_target(cpy._target)
{
	cout<<"PresidentialPardonForm cpy ctor"<<endl;
}

PPF::~PPF()
{
	cout<<"PresidentialPardonForm dtor"<<endl;
}

PPF&	PPF::operator=(const PPF& rhs)
{
	cout<<"PresidentialPardonForm assignment operator"<<endl;
	AForm::operator=(rhs);
	return (*this);
}

void	PPF::action() const
{
	cout<<"* "<<_target<<" has been pardonned by president Zaphod Beeblebrox"
		<<" *"<<endl;
}

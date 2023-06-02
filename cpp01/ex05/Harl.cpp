/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skoulen <skoulen@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:23:17 by skoulen           #+#    #+#             */
/*   Updated: 2023/03/10 18:08:23 by skoulen          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"
#include <iostream>

using std::cout;
using std::endl;

void	Harl::_debug(void) const
{
	cout<<"I love having extra bacon for my 7XL-double-cheese-triple-pickle-special- ketchup burger. I really do !"<<endl;
}

void	Harl::_info(void) const
{
	cout<<"I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger ! If you did, I wouldn't be asking for more !"<<endl;
}

void	Harl::_warning(void) const
{
	cout<<"I think I deserve to have some extra bacon for free. I’ve been coming for years whereas you started working here since last month."<<endl;
}

void	Harl::_error(void) const
{
	cout<<"This is unacceptable ! I want to speak to the manager now."<<endl;
}

void	Harl::complain(std::string filter) const
{
	typedef void	(Harl::*f)(void) const;

	f methods[4] = {&Harl::_debug, &Harl::_info, &Harl::_warning, &Harl::_error};
	std::string levels[4] = {"debug", "info", "warning", "error"};

	int i;
	for (i = 0; i < 4; i++)
	{
		if (filter == levels[i])
			break ;
	}
	if (i == 4)
		return ;

	(this->*(methods[i]))();
}
